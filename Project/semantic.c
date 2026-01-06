#include "semantic.h"
#include <stdarg.h>

/* ==================== Global State ==================== */

FuncSymbol *func_table = NULL;
Scope *current_scope = NULL;
int semantic_errors = 0;
DataType current_func_return_type = TYPE_VOID;

/* Forward declaration of node struct (defined in proj.y) */
typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
    int lineno;
} node;

/* ==================== Error Reporting ==================== */

void semantic_error(const char *msg, int lineno) {
    fprintf(stderr, "SemanticError at line %d: %s\n", lineno, msg);
    semantic_errors++;
}

void semantic_error_fmt(int lineno, const char *fmt, ...) {
    va_list args;
    fprintf(stderr, "SemanticError at line %d: ", lineno);
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    semantic_errors++;
}

/* ==================== Type Utilities ==================== */

const char *type_to_string(DataType type) {
    switch (type) {
        case TYPE_INT:    return "int";
        case TYPE_FLOAT:  return "float";
        case TYPE_STRING: return "string";
        case TYPE_BOOL:   return "bool";
        case TYPE_VOID:   return "void";
        case TYPE_ERROR:  return "error";
        default:          return "unknown";
    }
}

DataType string_to_type(const char *s) {
    if (strcmp(s, "INT") == 0 || strcmp(s, "int") == 0) return TYPE_INT;
    if (strcmp(s, "FLOAT") == 0 || strcmp(s, "float") == 0) return TYPE_FLOAT;
    if (strcmp(s, "STRING") == 0 || strcmp(s, "string") == 0) return TYPE_STRING;
    if (strcmp(s, "BOOL") == 0 || strcmp(s, "bool") == 0) return TYPE_BOOL;
    if (strcmp(s, "VOID") == 0 || strcmp(s, "void") == 0) return TYPE_VOID;
    return TYPE_ERROR;
}

/* ==================== Scope Management ==================== */

void enter_scope(void) {
    Scope *new_scope = (Scope*)malloc(sizeof(Scope));
    new_scope->symbols = NULL;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void exit_scope(void) {
    if (current_scope == NULL) return;
    
    /* Free symbols in current scope */
    Symbol *sym = current_scope->symbols;
    while (sym) {
        Symbol *next = sym->next;
        free(sym->name);
        free(sym);
        sym = next;
    }
    
    Scope *parent = current_scope->parent;
    free(current_scope);
    current_scope = parent;
}

/* ==================== Variable Symbol Table Operations ==================== */

Symbol *lookup_var(const char *name) {
    /* Search from current scope upward */
    Scope *scope = current_scope;
    while (scope) {
        Symbol *sym = scope->symbols;
        while (sym) {
            if (strcmp(sym->name, name) == 0) {
                return sym;
            }
            sym = sym->next;
        }
        scope = scope->parent;
    }
    return NULL;
}

Symbol *lookup_var_current_scope(const char *name) {
    /* Search only in current scope */
    if (current_scope == NULL) return NULL;
    
    Symbol *sym = current_scope->symbols;
    while (sym) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

int add_var(const char *name, DataType type, int lineno) {
    /* Check for duplicate in current scope */
    if (lookup_var_current_scope(name) != NULL) {
        semantic_error_fmt(lineno, "duplicate variable '%s'", name);
        return 0;
    }
    
    Symbol *sym = (Symbol*)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->lineno = lineno;
    sym->next = current_scope->symbols;
    current_scope->symbols = sym;
    return 1;
}

/* ==================== Function Symbol Table Operations ==================== */

FuncSymbol *lookup_func(const char *name) {
    FuncSymbol *func = func_table;
    while (func) {
        if (strcmp(func->name, name) == 0) {
            return func;
        }
        func = func->next;
    }
    return NULL;
}

int add_func(const char *name, DataType return_type, Param *params, int param_count, int lineno) {
    /* Check for duplicate function */
    if (lookup_func(name) != NULL) {
        semantic_error_fmt(lineno, "duplicate function '%s'", name);
        return 0;
    }
    
    FuncSymbol *func = (FuncSymbol*)malloc(sizeof(FuncSymbol));
    func->name = strdup(name);
    func->return_type = return_type;
    func->params = params;
    func->param_count = param_count;
    func->lineno = lineno;
    func->next = func_table;
    func_table = func;
    return 1;
}

/* ==================== Helper Functions ==================== */

/* Check if a string looks like an integer */
static int is_integer_literal(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    if (*s == '-') s++;
    while (*s) {
        if (*s < '0' || *s > '9') return 0;
        s++;
    }
    return 1;
}

/* Check if a string looks like a float */
static int is_float_literal(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    if (*s == '-') s++;
    int has_dot = 0;
    while (*s) {
        if (*s == '.') {
            if (has_dot) return 0;
            has_dot = 1;
        } else if (*s < '0' || *s > '9') {
            return 0;
        }
        s++;
    }
    return has_dot;
}

/* Check if a string is a string literal (starts with " or ') */
static int is_string_literal(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    return (s[0] == '"' || s[0] == '\'');
}

/* ==================== Semantic Analysis Functions ==================== */

/* Forward declarations */
void analyze_function(node *func);
void analyze_body(node *body);
void analyze_stmt(node *stmt);
void analyze_stmt_list(node *stmt_list);
DataType analyze_expr(node *expr);
void analyze_if(node *if_stmt);
void analyze_while(node *while_stmt);
void analyze_assign(node *assign);
void analyze_decl(node *decl);
void analyze_return(node *ret);
DataType analyze_call(node *call);

/* ==================== First Pass: Collect Function Signatures ==================== */

/* Extract parameters from ARGS node and build parameter list */
static Param *extract_params(node *args_node, int *count) {
    *count = 0;
    Param *params = NULL;
    Param *last = NULL;
    
    if (args_node == NULL) return NULL;
    
    /* args_node is ARGS, its left child is the parameter list or NONE */
    node *param_list = args_node->left;
    
    if (param_list == NULL || strcmp(param_list->token, "NONE") == 0) {
        return NULL;
    }
    
    /* param_list is a linked list of type nodes (INT, FLOAT, etc.) via ->right */
    node *type_node = param_list;
    while (type_node) {
        DataType dtype = string_to_type(type_node->token);
        
        /* Each type node has id_list in its left child */
        node *id = type_node->left;
        while (id) {
            Param *p = (Param*)malloc(sizeof(Param));
            p->name = strdup(id->token);
            p->type = dtype;
            p->next = NULL;
            
            if (last == NULL) {
                params = p;
            } else {
                last->next = p;
            }
            last = p;
            (*count)++;
            
            id = id->right;
        }
        
        type_node = type_node->right;
    }
    
    return params;
}

/* Get return type from RETURN node */
static DataType get_return_type(node *ret_node) {
    if (ret_node == NULL) return TYPE_VOID;
    
    /* ret_node is "RETURN", its left child is the type (VOID, INT, etc.) */
    node *type_node = ret_node->left;
    if (type_node == NULL) return TYPE_VOID;
    
    return string_to_type(type_node->token);
}

/* Collect all function signatures in first pass */
void collect_functions(node *func_list) {
    node *func = func_list;
    
    while (func) {
        if (strcmp(func->token, "FUNC") == 0) {
            /* FUNC structure: left = func_name node
               func_name->right = ARGS
               ARGS->right = RETURN
               RETURN->right = BODY */
            node *name_node = func->left;
            char *func_name = name_node->token;
            
            node *args_node = name_node->right;
            node *ret_node = args_node->right;
            
            int param_count = 0;
            Param *params = extract_params(args_node, &param_count);
            DataType return_type = get_return_type(ret_node);
            
            add_func(func_name, return_type, params, param_count, func->lineno);
        }
        func = func->right;
    }
}

/* ==================== Expression Type Checking ==================== */

DataType analyze_expr(node *expr) {
    if (expr == NULL) return TYPE_ERROR;
    
    char *tok = expr->token;
    
    /* Literals */
    if (is_integer_literal(tok)) {
        return TYPE_INT;
    }
    if (is_float_literal(tok)) {
        return TYPE_FLOAT;
    }
    if (is_string_literal(tok)) {
        return TYPE_STRING;
    }
    if (strcmp(tok, "True") == 0 || strcmp(tok, "False") == 0) {
        return TYPE_BOOL;
    }
    
    /* Function call */
    if (strcmp(tok, "CALL") == 0) {
        return analyze_call(expr);
    }
    
    /* Index operation: string[int] -> string */
    if (strcmp(tok, "INDEX") == 0) {
        node *base = expr->left;
        node *index = base->right;
        
        DataType base_type = analyze_expr(base);
        DataType index_type = analyze_expr(index);
        
        if (base_type != TYPE_STRING) {
            semantic_error_fmt(expr->lineno, "index operator [] can only be applied to string, got %s", type_to_string(base_type));
            return TYPE_ERROR;
        }
        if (index_type != TYPE_INT) {
            semantic_error_fmt(expr->lineno, "index must be int, got %s", type_to_string(index_type));
            return TYPE_ERROR;
        }
        return TYPE_STRING;
    }
    
    /* Arithmetic operators: +, -, *, / */
    if (strcmp(tok, "+") == 0 || strcmp(tok, "-") == 0 ||
        strcmp(tok, "*") == 0 || strcmp(tok, "/") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        DataType left_type = analyze_expr(left_node);
        DataType right_type = analyze_expr(right_node);
        
        /* Both must be int or float */
        if ((left_type != TYPE_INT && left_type != TYPE_FLOAT) ||
            (right_type != TYPE_INT && right_type != TYPE_FLOAT)) {
            semantic_error_fmt(expr->lineno, "arithmetic operator '%s' requires int or float operands, got %s and %s",
                             tok, type_to_string(left_type), type_to_string(right_type));
            return TYPE_ERROR;
        }
        
        /* Result is int if both are int, otherwise float */
        if (left_type == TYPE_INT && right_type == TYPE_INT) {
            return TYPE_INT;
        }
        return TYPE_FLOAT;
    }
    
    /* Power operator: ** (same rules as arithmetic) */
    if (strcmp(tok, "**") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        DataType left_type = analyze_expr(left_node);
        DataType right_type = analyze_expr(right_node);
        
        if ((left_type != TYPE_INT && left_type != TYPE_FLOAT) ||
            (right_type != TYPE_INT && right_type != TYPE_FLOAT)) {
            semantic_error_fmt(expr->lineno, "power operator '**' requires int or float operands, got %s and %s",
                             type_to_string(left_type), type_to_string(right_type));
            return TYPE_ERROR;
        }
        
        if (left_type == TYPE_INT && right_type == TYPE_INT) {
            return TYPE_INT;
        }
        return TYPE_FLOAT;
    }
    
    /* Comparison operators: >, <, >=, <= (int/float -> bool) */
    if (strcmp(tok, ">") == 0 || strcmp(tok, "<") == 0 ||
        strcmp(tok, ">=") == 0 || strcmp(tok, "<=") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        DataType left_type = analyze_expr(left_node);
        DataType right_type = analyze_expr(right_node);
        
        if ((left_type != TYPE_INT && left_type != TYPE_FLOAT) ||
            (right_type != TYPE_INT && right_type != TYPE_FLOAT)) {
            semantic_error_fmt(expr->lineno, "comparison operator '%s' requires int or float operands, got %s and %s",
                             tok, type_to_string(left_type), type_to_string(right_type));
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }
    
    /* Equality operators: ==, != (same type required -> bool) */
    if (strcmp(tok, "==") == 0 || strcmp(tok, "!=") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        DataType left_type = analyze_expr(left_node);
        DataType right_type = analyze_expr(right_node);
        
        if (left_type != right_type) {
            semantic_error_fmt(expr->lineno, "equality operator '%s' requires same types, got %s and %s",
                             tok, type_to_string(left_type), type_to_string(right_type));
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }
    
    /* Logical operators: AND, OR (bool, bool -> bool) */
    if (strcmp(tok, "AND") == 0 || strcmp(tok, "OR") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        DataType left_type = analyze_expr(left_node);
        DataType right_type = analyze_expr(right_node);
        
        if (left_type != TYPE_BOOL || right_type != TYPE_BOOL) {
            semantic_error_fmt(expr->lineno, "logical operator '%s' requires bool operands, got %s and %s",
                             tok, type_to_string(left_type), type_to_string(right_type));
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }
    
    /* NOT operator (bool -> bool) */
    if (strcmp(tok, "NOT") == 0) {
        node *operand = expr->left;
        DataType op_type = analyze_expr(operand);
        
        if (op_type != TYPE_BOOL) {
            semantic_error_fmt(expr->lineno, "logical operator 'not' requires bool operand, got %s",
                             type_to_string(op_type));
            return TYPE_ERROR;
        }
        return TYPE_BOOL;
    }
    
    /* Variable reference */
    Symbol *var = lookup_var(tok);
    if (var != NULL) {
        return var->type;
    }
    
    /* Unknown identifier - could be undefined variable */
    /* Check if it's not a keyword or known token */
    if (strcmp(tok, "NONE") != 0 && strcmp(tok, "VOID") != 0 &&
        strcmp(tok, "ARGS") != 0 && strcmp(tok, "BLOCK") != 0) {
        semantic_error_fmt(expr->lineno, "undefined variable '%s'", tok);
    }
    
    return TYPE_ERROR;
}

/* ==================== Function Call Validation ==================== */

DataType analyze_call(node *call) {
    /* CALL structure: left = func_name_node
       func_name_node->right = ARGS node
       ARGS->left = argument expression list or NONE */
    
    node *name_node = call->left;
    char *func_name = name_node->token;
    node *args_node = name_node->right;
    
    /* Look up function */
    FuncSymbol *func = lookup_func(func_name);
    if (func == NULL) {
        semantic_error_fmt(call->lineno, "undefined function '%s'", func_name);
        return TYPE_ERROR;
    }
    
    /* Count and check arguments */
    int arg_count = 0;
    node *arg_list = args_node->left;
    
    /* Build list of argument types */
    DataType arg_types[100];  /* Max 100 arguments */
    
    if (arg_list != NULL && strcmp(arg_list->token, "NONE") != 0) {
        node *arg = arg_list;
        while (arg && arg_count < 100) {
            arg_types[arg_count] = analyze_expr(arg);
            arg_count++;
            arg = arg->right;
        }
    }
    
    /* Check argument count */
    if (arg_count != func->param_count) {
        semantic_error_fmt(call->lineno, "function '%s' expects %d arguments, got %d",
                         func_name, func->param_count, arg_count);
        return func->return_type;  /* Still return the declared type */
    }
    
    /* Check argument types */
    Param *param = func->params;
    for (int i = 0; i < arg_count && param; i++) {
        if (arg_types[i] != param->type && arg_types[i] != TYPE_ERROR) {
            semantic_error_fmt(call->lineno, "function '%s' argument %d: expected %s, got %s",
                             func_name, i + 1, type_to_string(param->type), type_to_string(arg_types[i]));
        }
        param = param->next;
    }
    
    return func->return_type;
}

/* ==================== Statement Analysis ==================== */

void analyze_if(node *if_stmt) {
    /* IF structure: left = condition
       condition->right = then_block
       then_block->right = elif_tail or else_block (optional) */
    
    node *cond = if_stmt->left;
    DataType cond_type = analyze_expr(cond);
    
    if (cond_type != TYPE_BOOL && cond_type != TYPE_ERROR) {
        semantic_error_fmt(if_stmt->lineno, "if condition must be bool, got %s", type_to_string(cond_type));
    }
    
    /* Analyze then block */
    node *then_block = cond->right;
    if (then_block) {
        enter_scope();
        if (strcmp(then_block->token, "BLOCK") == 0) {
            analyze_stmt_list(then_block->left);
        } else {
            analyze_stmt(then_block);
        }
        exit_scope();
        
        /* Check for elif/else tail */
        node *tail = then_block->right;
        while (tail) {
            if (strcmp(tail->token, "ELIF") == 0) {
                node *elif_cond = tail->left;
                DataType elif_cond_type = analyze_expr(elif_cond);
                
                if (elif_cond_type != TYPE_BOOL && elif_cond_type != TYPE_ERROR) {
                    semantic_error_fmt(tail->lineno, "elif condition must be bool, got %s", type_to_string(elif_cond_type));
                }
                
                node *elif_block = elif_cond->right;
                if (elif_block) {
                    enter_scope();
                    if (strcmp(elif_block->token, "BLOCK") == 0) {
                        analyze_stmt_list(elif_block->left);
                    } else {
                        analyze_stmt(elif_block);
                    }
                    exit_scope();
                }
                tail = tail->right;
            } else if (strcmp(tail->token, "ELSE") == 0) {
                node *else_block = tail->left;
                if (else_block) {
                    enter_scope();
                    if (strcmp(else_block->token, "BLOCK") == 0) {
                        analyze_stmt_list(else_block->left);
                    } else {
                        analyze_stmt(else_block);
                    }
                    exit_scope();
                }
                break;
            } else {
                break;
            }
        }
    }
}

void analyze_while(node *while_stmt) {
    /* WHILE structure: left = condition
       condition->right = body block */
    
    node *cond = while_stmt->left;
    DataType cond_type = analyze_expr(cond);
    
    if (cond_type != TYPE_BOOL && cond_type != TYPE_ERROR) {
        semantic_error_fmt(while_stmt->lineno, "while condition must be bool, got %s", type_to_string(cond_type));
    }
    
    /* Analyze body */
    node *body = cond->right;
    if (body) {
        enter_scope();
        if (strcmp(body->token, "BLOCK") == 0) {
            analyze_stmt_list(body->left);
        } else {
            analyze_stmt(body);
        }
        exit_scope();
    }
}

void analyze_assign(node *assign) {
    /* ASS structure: left = id_node
       id_node->right = expr */
    
    node *id_node = assign->left;
    char *var_name = id_node->token;
    node *expr = id_node->right;
    
    /* Check variable exists */
    Symbol *var = lookup_var(var_name);
    if (var == NULL) {
        semantic_error_fmt(assign->lineno, "undefined variable '%s'", var_name);
        return;
    }
    
    /* Check type matches */
    DataType expr_type = analyze_expr(expr);
    if (expr_type != var->type && expr_type != TYPE_ERROR) {
        semantic_error_fmt(assign->lineno, "type mismatch in assignment: variable '%s' is %s, got %s",
                         var_name, type_to_string(var->type), type_to_string(expr_type));
    }
}

void analyze_decl(node *decl) {
    /* DECL structure: left = type_node
       type_node->left = id or id_list (linked via right)
       For initialized decl: id_node->right = INIT node wrapping the initializer expr
       For multi-var decl: id_node->right = next id in list */
    
    node *type_node = decl->left;
    DataType var_type = string_to_type(type_node->token);
    
    /* Iterate through id list */
    node *id = type_node->left;
    
    /* Check if this is an initialized declaration (type ID = expr)
       The parser wraps the initializer in an INIT node */
    if (id && id->right && strcmp(id->right->token, "INIT") == 0) {
        /* Single variable with initializer */
        add_var(id->token, var_type, decl->lineno);
        
        /* INIT node's left child is the actual initializer expression */
        node *init_node = id->right;
        node *init_expr = init_node->left;
        
        DataType init_type = analyze_expr(init_expr);
        if (init_type != var_type && init_type != TYPE_ERROR) {
            semantic_error_fmt(decl->lineno, "type mismatch in declaration: variable '%s' is %s, initialized with %s",
                             id->token, type_to_string(var_type), type_to_string(init_type));
        }
        return;
    }
    
    /* Multiple variables without initializer (type id1, id2, ...) */
    while (id) {
        add_var(id->token, var_type, decl->lineno);
        id = id->right;
    }
}

void analyze_return(node *ret) {
    /* RET structure: left = return expression or VOID */
    
    node *expr = ret->left;
    DataType ret_type;
    
    if (expr == NULL || strcmp(expr->token, "VOID") == 0) {
        ret_type = TYPE_VOID;
    } else {
        ret_type = analyze_expr(expr);
    }
    
    if (ret_type != current_func_return_type && ret_type != TYPE_ERROR) {
        semantic_error_fmt(ret->lineno, "return type mismatch: expected %s, got %s",
                         type_to_string(current_func_return_type), type_to_string(ret_type));
    }
}

void analyze_stmt(node *stmt) {
    if (stmt == NULL) return;
    
    char *tok = stmt->token;
    
    if (strcmp(tok, "IF") == 0) {
        analyze_if(stmt);
    } else if (strcmp(tok, "WHILE") == 0) {
        analyze_while(stmt);
    } else if (strcmp(tok, "ASS") == 0) {
        analyze_assign(stmt);
    } else if (strcmp(tok, "DECL") == 0) {
        analyze_decl(stmt);
    } else if (strcmp(tok, "RET") == 0) {
        analyze_return(stmt);
    } else if (strcmp(tok, "PASS") == 0) {
        /* pass is always valid */
    } else if (strcmp(tok, "CALL") == 0) {
        analyze_call(stmt);
    }
}

void analyze_stmt_list(node *stmt_list) {
    node *stmt = stmt_list;
    while (stmt) {
        analyze_stmt(stmt);
        stmt = stmt->right;
    }
}

void analyze_body(node *body) {
    if (body == NULL) return;
    
    /* BODY structure: left = statement list */
    analyze_stmt_list(body->left);
}

/* ==================== Function Analysis (Second Pass) ==================== */

void analyze_function(node *func) {
    /* FUNC structure: left = func_name node
       func_name->right = ARGS
       ARGS->right = RETURN
       RETURN->right = BODY */
    
    node *name_node = func->left;
    char *func_name = name_node->token;
    
    node *args_node = name_node->right;
    node *ret_node = args_node->right;
    node *body_node = ret_node->right;
    
    /* Set current function's return type for checking return statements */
    current_func_return_type = get_return_type(ret_node);
    
    /* Enter function scope */
    enter_scope();
    
    /* Add parameters to scope */
    node *param_list = args_node->left;
    if (param_list && strcmp(param_list->token, "NONE") != 0) {
        node *type_node = param_list;
        while (type_node) {
            DataType dtype = string_to_type(type_node->token);
            node *id = type_node->left;
            while (id) {
                add_var(id->token, dtype, func->lineno);
                id = id->right;
            }
            type_node = type_node->right;
        }
    }
    
    /* Analyze function body */
    analyze_body(body_node);
    
    /* Exit function scope */
    exit_scope();
}

/* ==================== Main Entry Point ==================== */

void analyze_program(node *root) {
    if (root == NULL) return;
    
    /* root is "CODE" node, left child is func_list */
    node *func_list = root->left;
    
    /* First pass: collect all function signatures */
    collect_functions(func_list);
    
    /* Check for main function */
    FuncSymbol *main_func = lookup_func("main");
    if (main_func == NULL) {
        semantic_error("main function not found", 1);
    } else {
        /* Check main has no parameters */
        if (main_func->param_count != 0) {
            semantic_error_fmt(main_func->lineno, "main function must not have parameters");
        }
        /* Check main has no return type (void) */
        if (main_func->return_type != TYPE_VOID) {
            semantic_error_fmt(main_func->lineno, "main function must not have a return type");
        }
    }
    
    /* Second pass: analyze each function body */
    node *func = func_list;
    while (func) {
        if (strcmp(func->token, "FUNC") == 0) {
            analyze_function(func);
        }
        func = func->right;
    }
}

int semantic_analysis(node *root) {
    /* Reset state */
    func_table = NULL;
    current_scope = NULL;
    semantic_errors = 0;
    
    /* Run analysis */
    analyze_program(root);
    
    return semantic_errors;
}

