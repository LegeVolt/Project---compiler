#include "codegen.h"
#include "semantic.h"

/* ==================== Global State ==================== */

int temp_counter = 0;
int label_counter = 0;
TACInstr *code_head = NULL;
TACInstr *code_tail = NULL;

/* Forward declaration of node struct */
typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
    int lineno;
} node;

/* ==================== Helper Functions ==================== */

static char *strdup_safe(const char *s) {
    if (s == NULL) return NULL;
    return strdup(s);
}

static int is_integer_literal(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    const char *p = s;
    if (*p == '-') p++;
    if (*p == '\0') return 0;
    while (*p) {
        if (*p < '0' || *p > '9') return 0;
        p++;
    }
    return 1;
}

static int is_float_literal(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    const char *p = s;
    if (*p == '-') p++;
    int has_dot = 0;
    while (*p) {
        if (*p == '.') {
            if (has_dot) return 0;
            has_dot = 1;
        } else if (*p < '0' || *p > '9') {
            return 0;
        }
        p++;
    }
    return has_dot;
}

static int is_string_literal(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    return (s[0] == '"' || s[0] == '\'');
}

static int is_variable(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    /* Check if it's not a literal, not True/False, not a keyword */
    if (is_integer_literal(s) || is_float_literal(s) || is_string_literal(s)) return 0;
    if (strcmp(s, "True") == 0 || strcmp(s, "False") == 0) return 0;
    if (strcmp(s, "NONE") == 0 || strcmp(s, "VOID") == 0) return 0;
    /* Should start with a letter */
    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
        return 1;
    }
    return 0;
}

/* ==================== Temp and Label Generation ==================== */

char *new_temp(void) {
    char *temp = (char *)malloc(16);
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

char *new_label(void) {
    char *label = (char *)malloc(16);
    sprintf(label, "L%d", label_counter++);
    return label;
}

/* ==================== Emit Functions ==================== */

static TACInstr *new_instr(TACType type) {
    TACInstr *instr = (TACInstr *)malloc(sizeof(TACInstr));
    instr->type = type;
    instr->result = NULL;
    instr->arg1 = NULL;
    instr->arg2 = NULL;
    instr->op = NULL;
    instr->value = 0;
    instr->next = NULL;
    return instr;
}

static void append_instr(TACInstr *instr) {
    if (code_head == NULL) {
        code_head = instr;
        code_tail = instr;
    } else {
        code_tail->next = instr;
        code_tail = instr;
    }
}

void emit_func_label(const char *name) {
    TACInstr *instr = new_instr(TAC_FUNC_LABEL);
    instr->result = strdup_safe(name);
    append_instr(instr);
}

void emit_begin_func(int size) {
    TACInstr *instr = new_instr(TAC_BEGIN_FUNC);
    instr->value = size;
    append_instr(instr);
}

void emit_end_func(void) {
    TACInstr *instr = new_instr(TAC_END_FUNC);
    append_instr(instr);
}

void emit_label(const char *label) {
    TACInstr *instr = new_instr(TAC_LABEL);
    instr->result = strdup_safe(label);
    append_instr(instr);
}

void emit_goto(const char *label) {
    TACInstr *instr = new_instr(TAC_GOTO);
    instr->result = strdup_safe(label);
    append_instr(instr);
}

void emit_if_goto(const char *cond, const char *label) {
    TACInstr *instr = new_instr(TAC_IF_GOTO);
    instr->arg1 = strdup_safe(cond);
    instr->result = strdup_safe(label);
    append_instr(instr);
}

void emit_return(const char *value) {
    TACInstr *instr = new_instr(TAC_RETURN);
    instr->arg1 = strdup_safe(value);
    append_instr(instr);
}

void emit_param(const char *param) {
    TACInstr *instr = new_instr(TAC_PARAM);
    instr->arg1 = strdup_safe(param);
    append_instr(instr);
}

void emit_call(const char *result, const char *func_name) {
    TACInstr *instr = new_instr(TAC_CALL);
    instr->result = strdup_safe(result);
    instr->arg1 = strdup_safe(func_name);
    append_instr(instr);
}

void emit_pop_params(int size) {
    TACInstr *instr = new_instr(TAC_POP_PARAMS);
    instr->value = size;
    append_instr(instr);
}

void emit_assign(const char *dest, const char *src) {
    TACInstr *instr = new_instr(TAC_ASSIGN);
    instr->result = strdup_safe(dest);
    instr->arg1 = strdup_safe(src);
    append_instr(instr);
}

void emit_binop(const char *result, const char *arg1, const char *op, const char *arg2) {
    TACInstr *instr = new_instr(TAC_BINOP);
    instr->result = strdup_safe(result);
    instr->arg1 = strdup_safe(arg1);
    instr->op = strdup_safe(op);
    instr->arg2 = strdup_safe(arg2);
    append_instr(instr);
}

void emit_unop(const char *result, const char *op, const char *arg) {
    TACInstr *instr = new_instr(TAC_UNOP);
    instr->result = strdup_safe(result);
    instr->op = strdup_safe(op);
    instr->arg1 = strdup_safe(arg);
    append_instr(instr);
}

/* ==================== Output ==================== */

void print_code(void) {
    TACInstr *instr = code_head;
    int need_newline_before_func = 0;
    
    while (instr) {
        switch (instr->type) {
            case TAC_FUNC_LABEL:
                if (need_newline_before_func) {
                    printf("\n");
                }
                printf("%s:\n", instr->result);
                need_newline_before_func = 1;
                break;
                
            case TAC_BEGIN_FUNC:
                printf("\tBeginFunc %d\n", instr->value);
                break;
                
            case TAC_END_FUNC:
                printf("\tEndFunc\n");
                break;
                
            case TAC_LABEL:
                printf("%s:\t", instr->result);
                /* Look ahead - if next is not a regular instruction, print newline */
                if (instr->next == NULL || 
                    instr->next->type == TAC_LABEL ||
                    instr->next->type == TAC_FUNC_LABEL ||
                    instr->next->type == TAC_END_FUNC) {
                    printf("\n");
                }
                break;
                
            case TAC_GOTO:
                printf("Goto %s\n", instr->result);
                break;
                
            case TAC_IF_GOTO:
                printf("if %s Goto %s\n", instr->arg1, instr->result);
                break;
                
            case TAC_RETURN:
                printf("Return %s\n", instr->arg1);
                break;
                
            case TAC_PARAM:
                printf("PushParam %s\n", instr->arg1);
                break;
                
            case TAC_CALL:
                printf("%s = LCall %s\n", instr->result, instr->arg1);
                break;
                
            case TAC_POP_PARAMS:
                printf("PopParams %d\n", instr->value);
                break;
                
            case TAC_ASSIGN:
                printf("%s = %s\n", instr->result, instr->arg1);
                break;
                
            case TAC_BINOP:
                printf("%s = %s %s %s\n", instr->result, instr->arg1, instr->op, instr->arg2);
                break;
                
            case TAC_UNOP:
                printf("%s = %s %s\n", instr->result, instr->op, instr->arg1);
                break;
                
            default:
                break;
        }
        
        /* Add tab for instructions that aren't after a label */
        TACInstr *prev = NULL;
        for (TACInstr *p = code_head; p != instr; p = p->next) {
            prev = p;
        }
        
        instr = instr->next;
    }
}

/* Better print function with proper formatting */
void print_code_formatted(void) {
    TACInstr *instr = code_head;
    int first_func = 1;
    int after_label = 0;
    
    while (instr) {
        switch (instr->type) {
            case TAC_FUNC_LABEL:
                if (!first_func) {
                    printf("\n");
                }
                first_func = 0;
                printf("%s:\n", instr->result);
                after_label = 0;
                break;
                
            case TAC_BEGIN_FUNC:
                printf("\tBeginFunc %d\n", instr->value);
                after_label = 0;
                break;
                
            case TAC_END_FUNC:
                if (!after_label) printf("\t");
                printf("EndFunc\n");
                after_label = 0;
                break;
                
            case TAC_LABEL:
                printf("%s:", instr->result);
                after_label = 1;
                /* Always print tab after label for alignment */
                printf("\t");
                /* If next is another label, func label, or nothing relevant, print newline */
                if (instr->next == NULL ||
                    instr->next->type == TAC_LABEL ||
                    instr->next->type == TAC_FUNC_LABEL) {
                    printf("\n");
                    after_label = 0;
                }
                break;
                
            case TAC_GOTO:
                if (!after_label) printf("\t");
                printf("Goto %s\n", instr->result);
                after_label = 0;
                break;
                
            case TAC_IF_GOTO:
                if (!after_label) printf("\t");
                printf("if %s Goto %s\n", instr->arg1, instr->result);
                after_label = 0;
                break;
                
            case TAC_RETURN:
                if (!after_label) printf("\t");
                printf("Return %s\n", instr->arg1);
                after_label = 0;
                break;
                
            case TAC_PARAM:
                if (!after_label) printf("\t");
                printf("PushParam %s\n", instr->arg1);
                after_label = 0;
                break;
                
            case TAC_CALL:
                if (!after_label) printf("\t");
                printf("%s = LCall %s\n", instr->result, instr->arg1);
                after_label = 0;
                break;
                
            case TAC_POP_PARAMS:
                if (!after_label) printf("\t");
                printf("PopParams %d\n", instr->value);
                after_label = 0;
                break;
                
            case TAC_ASSIGN:
                if (!after_label) printf("\t");
                printf("%s = %s\n", instr->result, instr->arg1);
                after_label = 0;
                break;
                
            case TAC_BINOP:
                if (!after_label) printf("\t");
                printf("%s = %s %s %s\n", instr->result, instr->arg1, instr->op, instr->arg2);
                after_label = 0;
                break;
                
            case TAC_UNOP:
                if (!after_label) printf("\t");
                printf("%s = %s %s\n", instr->result, instr->op, instr->arg1);
                after_label = 0;
                break;
                
            default:
                after_label = 0;
                break;
        }
        
        instr = instr->next;
    }
}

void reset_codegen(void) {
    /* Free all instructions */
    TACInstr *instr = code_head;
    while (instr) {
        TACInstr *next = instr->next;
        free(instr->result);
        free(instr->arg1);
        free(instr->arg2);
        free(instr->op);
        free(instr);
        instr = next;
    }
    
    code_head = NULL;
    code_tail = NULL;
    temp_counter = 0;
    label_counter = 0;
}

/* ==================== Count Local Variables ==================== */

static int count_vars_in_stmt_list(node *stmt_list);

static int count_vars_in_decl(node *decl) {
    int count = 0;
    if (decl == NULL) return 0;
    
    /* DECL -> type_node -> id_list */
    node *type_node = decl->left;
    if (type_node == NULL) return 0;
    
    node *id = type_node->left;
    while (id) {
        count++;
        /* Check if right is INIT (initialized) or another ID */
        if (id->right && strcmp(id->right->token, "INIT") == 0) {
            break;  /* Only one var in initialized decl */
        }
        id = id->right;
    }
    
    return count;
}

static int count_vars_in_block(node *block) {
    if (block == NULL) return 0;
    if (strcmp(block->token, "BLOCK") == 0) {
        return count_vars_in_stmt_list(block->left);
    }
    return 0;
}

static int count_vars_in_stmt(node *stmt) {
    if (stmt == NULL) return 0;
    
    char *tok = stmt->token;
    
    if (strcmp(tok, "DECL") == 0) {
        return count_vars_in_decl(stmt);
    } else if (strcmp(tok, "IF") == 0) {
        int count = 0;
        node *cond = stmt->left;
        node *then_block = cond->right;
        count += count_vars_in_block(then_block);
        
        /* Check elif/else chain */
        node *tail = then_block->right;
        while (tail) {
            if (strcmp(tail->token, "ELIF") == 0) {
                node *elif_cond = tail->left;
                node *elif_block = elif_cond->right;
                count += count_vars_in_block(elif_block);
                tail = tail->right;
            } else if (strcmp(tail->token, "ELSE") == 0) {
                count += count_vars_in_block(tail->left);
                break;
            } else {
                break;
            }
        }
        return count;
    } else if (strcmp(tok, "WHILE") == 0) {
        node *cond = stmt->left;
        node *body = cond->right;
        return count_vars_in_block(body);
    }
    
    return 0;
}

static int count_vars_in_stmt_list(node *stmt_list) {
    int count = 0;
    node *stmt = stmt_list;
    while (stmt) {
        count += count_vars_in_stmt(stmt);
        stmt = stmt->right;
    }
    return count;
}

int count_local_vars(node *body) {
    if (body == NULL) return 0;
    /* BODY -> stmt_list */
    return count_vars_in_stmt_list(body->left);
}

/* ==================== Check if Expression is Boolean ==================== */

int is_boolean_expr(node *expr) {
    if (expr == NULL) return 0;
    
    char *tok = expr->token;
    
    if (strcmp(tok, "AND") == 0 || strcmp(tok, "OR") == 0 || strcmp(tok, "NOT") == 0) {
        return 1;
    }
    if (strcmp(tok, ">") == 0 || strcmp(tok, "<") == 0 ||
        strcmp(tok, ">=") == 0 || strcmp(tok, "<=") == 0 ||
        strcmp(tok, "==") == 0 || strcmp(tok, "!=") == 0) {
        return 1;
    }
    if (strcmp(tok, "True") == 0 || strcmp(tok, "False") == 0) {
        return 1;
    }
    
    return 0;
}

/* ==================== Expression Code Generation ==================== */

/* Check if expression is a simple value (literal or variable) */
static int is_simple_value(node *expr) {
    if (expr == NULL) return 0;
    char *tok = expr->token;
    if (is_integer_literal(tok) || is_float_literal(tok) || is_string_literal(tok)) return 1;
    if (strcmp(tok, "True") == 0 || strcmp(tok, "False") == 0) return 1;
    if (is_variable(tok) && expr->left == NULL) return 1;
    return 0;
}

/* Get simple value as string (no temp needed) */
static char *get_simple_value(node *expr) {
    if (expr == NULL) return strdup("0");
    char *tok = expr->token;
    if (strcmp(tok, "True") == 0) return strdup("1");
    if (strcmp(tok, "False") == 0) return strdup("0");
    return strdup(tok);
}

char *gen_expr(node *expr) {
    if (expr == NULL) return strdup("0");
    
    char *tok = expr->token;
    
    /* Literals - assign to temp */
    if (is_integer_literal(tok) || is_float_literal(tok) || is_string_literal(tok)) {
        char *temp = new_temp();
        emit_assign(temp, tok);
        return temp;
    }
    
    /* Boolean literals */
    if (strcmp(tok, "True") == 0) {
        char *temp = new_temp();
        emit_assign(temp, "1");
        return temp;
    }
    if (strcmp(tok, "False") == 0) {
        char *temp = new_temp();
        emit_assign(temp, "0");
        return temp;
    }
    
    /* Variable reference */
    if (is_variable(tok) && expr->left == NULL) {
        return strdup(tok);
    }
    
    /* Function call */
    if (strcmp(tok, "CALL") == 0) {
        return gen_call(expr);
    }
    
    /* Index operation */
    if (strcmp(tok, "INDEX") == 0) {
        node *base = expr->left;
        node *index = base->right;
        
        char *base_temp = gen_expr(base);
        char *idx_temp = gen_expr(index);
        char *result = new_temp();
        
        /* t = base[idx] */
        char op_str[64];
        sprintf(op_str, "%s[%s]", base_temp, idx_temp);
        emit_assign(result, op_str);
        
        free(base_temp);
        free(idx_temp);
        return result;
    }
    
    /* Binary operators */
    if (strcmp(tok, "+") == 0 || strcmp(tok, "-") == 0 ||
        strcmp(tok, "*") == 0 || strcmp(tok, "/") == 0 ||
        strcmp(tok, "**") == 0) {
        
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        char *left_temp = gen_expr(left_node);
        char *right_temp = gen_expr(right_node);
        char *result = new_temp();
        
        emit_binop(result, left_temp, tok, right_temp);
        
        free(left_temp);
        free(right_temp);
        return result;
    }
    
    /* Comparison operators */
    if (strcmp(tok, ">") == 0 || strcmp(tok, "<") == 0 ||
        strcmp(tok, ">=") == 0 || strcmp(tok, "<=") == 0 ||
        strcmp(tok, "==") == 0 || strcmp(tok, "!=") == 0) {
        
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        /* Use simple values directly, only gen_expr for complex expressions */
        char *left_val, *right_val;
        
        if (is_simple_value(left_node)) {
            left_val = get_simple_value(left_node);
        } else {
            left_val = gen_expr(left_node);
        }
        
        if (is_simple_value(right_node)) {
            right_val = get_simple_value(right_node);
        } else {
            right_val = gen_expr(right_node);
        }
        
        /* For comparisons in conditions, return the comparison string */
        char *result = (char *)malloc(128);
        sprintf(result, "%s %s %s", left_val, tok, right_val);
        
        free(left_val);
        free(right_val);
        return result;
    }
    
    /* AND/OR - short circuit evaluation */
    if (strcmp(tok, "AND") == 0 || strcmp(tok, "OR") == 0) {
        char *true_label = new_label();
        char *false_label = new_label();
        char *end_label = new_label();
        char *result = new_temp();
        
        gen_bool_expr(expr, true_label, false_label);
        
        emit_label(true_label);
        emit_assign(result, "1");
        emit_goto(end_label);
        
        emit_label(false_label);
        emit_assign(result, "0");
        
        emit_label(end_label);
        
        return result;
    }
    
    /* NOT operator */
    if (strcmp(tok, "NOT") == 0) {
        node *operand = expr->left;
        char *op_temp = gen_expr(operand);
        char *result = new_temp();
        emit_unop(result, "!", op_temp);
        free(op_temp);
        return result;
    }
    
    /* Fallback - return token as-is */
    return strdup(tok);
}

/* ==================== Short-Circuit Boolean Expression Generation ==================== */

void gen_bool_expr(node *expr, const char *true_label, const char *false_label) {
    if (expr == NULL) return;
    
    char *tok = expr->token;
    
    /* AND - short circuit: if left is false, skip right */
    if (strcmp(tok, "AND") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        char *mid_label = new_label();
        
        /* If left is true, check right; if false, go to false_label */
        gen_bool_expr(left_node, mid_label, false_label);
        
        emit_label(mid_label);
        
        /* If right is true, go to true_label; if false, go to false_label */
        gen_bool_expr(right_node, true_label, false_label);
        return;
    }
    
    /* OR - short circuit: if left is true, skip right */
    if (strcmp(tok, "OR") == 0) {
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        char *mid_label = new_label();
        
        /* If left is true, go to true_label; if false, check right */
        gen_bool_expr(left_node, true_label, mid_label);
        
        emit_label(mid_label);
        
        /* If right is true, go to true_label; if false, go to false_label */
        gen_bool_expr(right_node, true_label, false_label);
        return;
    }
    
    /* NOT */
    if (strcmp(tok, "NOT") == 0) {
        node *operand = expr->left;
        /* Swap true and false labels */
        gen_bool_expr(operand, false_label, true_label);
        return;
    }
    
    /* Comparison operators or simple boolean */
    if (strcmp(tok, ">") == 0 || strcmp(tok, "<") == 0 ||
        strcmp(tok, ">=") == 0 || strcmp(tok, "<=") == 0 ||
        strcmp(tok, "==") == 0 || strcmp(tok, "!=") == 0) {
        
        node *left_node = expr->left;
        node *right_node = left_node->right;
        
        /* Use simple values directly */
        char *left_val, *right_val;
        
        if (is_simple_value(left_node)) {
            left_val = get_simple_value(left_node);
        } else {
            left_val = gen_expr(left_node);
        }
        
        if (is_simple_value(right_node)) {
            right_val = get_simple_value(right_node);
        } else {
            right_val = gen_expr(right_node);
        }
        
        char cond[128];
        sprintf(cond, "%s %s %s", left_val, tok, right_val);
        
        emit_if_goto(cond, true_label);
        emit_goto(false_label);
        
        free(left_val);
        free(right_val);
        return;
    }
    
    /* True/False literals */
    if (strcmp(tok, "True") == 0) {
        emit_goto(true_label);
        return;
    }
    if (strcmp(tok, "False") == 0) {
        emit_goto(false_label);
        return;
    }
    
    /* Variable (boolean variable) */
    if (is_variable(tok)) {
        char cond[128];
        sprintf(cond, "%s == 1", tok);
        emit_if_goto(cond, true_label);
        emit_goto(false_label);
        return;
    }
    
    /* Function call that returns bool */
    if (strcmp(tok, "CALL") == 0) {
        char *call_result = gen_call(expr);
        char cond[128];
        sprintf(cond, "%s == 1", call_result);
        emit_if_goto(cond, true_label);
        emit_goto(false_label);
        free(call_result);
        return;
    }
}

/* ==================== Function Call Generation ==================== */

char *gen_call(node *call) {
    /* CALL -> name_node -> ARGS -> arg_list */
    node *name_node = call->left;
    char *func_name = name_node->token;
    node *args_node = name_node->right;
    node *arg_list = args_node->left;
    
    /* Count arguments and generate them */
    int arg_count = 0;
    char *arg_temps[100];
    
    if (arg_list && strcmp(arg_list->token, "NONE") != 0) {
        node *arg = arg_list;
        while (arg && arg_count < 100) {
            arg_temps[arg_count] = gen_expr(arg);
            arg_count++;
            arg = arg->right;
        }
    }
    
    /* Push params in order */
    for (int i = 0; i < arg_count; i++) {
        emit_param(arg_temps[i]);
    }
    
    /* Call function */
    char *result = new_temp();
    emit_call(result, func_name);
    
    /* Pop params (assume 8 bytes per param for simplicity) */
    if (arg_count > 0) {
        emit_pop_params(arg_count * 8);
    }
    
    /* Free arg temps */
    for (int i = 0; i < arg_count; i++) {
        free(arg_temps[i]);
    }
    
    return result;
}

/* ==================== Statement Generation ==================== */

void gen_assign(node *assign) {
    /* ASS -> id_node -> expr */
    node *id_node = assign->left;
    char *var_name = id_node->token;
    node *expr = id_node->right;
    
    char *expr_temp = gen_expr(expr);
    emit_assign(var_name, expr_temp);
    free(expr_temp);
}

void gen_decl(node *decl) {
    /* DECL -> type_node -> id / id_list */
    node *type_node = decl->left;
    node *id = type_node->left;
    
    /* Check if initialized */
    if (id && id->right && strcmp(id->right->token, "INIT") == 0) {
        /* Initialized declaration */
        node *init_node = id->right;
        node *init_expr = init_node->left;
        
        char *expr_temp = gen_expr(init_expr);
        emit_assign(id->token, expr_temp);
        free(expr_temp);
    }
    /* For non-initialized declarations, no code is generated */
}

void gen_return(node *ret) {
    /* RET -> expr or VOID */
    node *expr = ret->left;
    
    if (expr == NULL || strcmp(expr->token, "VOID") == 0) {
        emit_return("0");
    } else {
        char *expr_temp = gen_expr(expr);
        emit_return(expr_temp);
        free(expr_temp);
    }
}

void gen_if(node *if_stmt) {
    /* IF -> cond -> then_block -> tail (ELIF/ELSE) */
    node *cond = if_stmt->left;
    node *then_block = cond->right;
    node *tail = then_block->right;
    
    char *true_label = new_label();
    char *false_label = new_label();
    char *end_label = new_label();
    
    /* Generate condition with short-circuit */
    gen_bool_expr(cond, true_label, false_label);
    
    /* Then block */
    emit_label(true_label);
    if (strcmp(then_block->token, "BLOCK") == 0) {
        gen_stmt_list(then_block->left);
    } else {
        gen_stmt(then_block);
    }
    emit_goto(end_label);
    
    /* Else/Elif handling */
    emit_label(false_label);
    
    if (tail) {
        if (strcmp(tail->token, "ELSE") == 0) {
            node *else_block = tail->left;
            if (strcmp(else_block->token, "BLOCK") == 0) {
                gen_stmt_list(else_block->left);
            } else {
                gen_stmt(else_block);
            }
        } else if (strcmp(tail->token, "ELIF") == 0) {
            /* Generate elif chain */
            while (tail && strcmp(tail->token, "ELIF") == 0) {
                node *elif_cond = tail->left;
                node *elif_block = elif_cond->right;
                
                char *elif_true = new_label();
                char *elif_false = new_label();
                
                gen_bool_expr(elif_cond, elif_true, elif_false);
                
                emit_label(elif_true);
                if (strcmp(elif_block->token, "BLOCK") == 0) {
                    gen_stmt_list(elif_block->left);
                } else {
                    gen_stmt(elif_block);
                }
                emit_goto(end_label);
                
                emit_label(elif_false);
                
                tail = tail->right;
            }
            
            /* Check for trailing else */
            if (tail && strcmp(tail->token, "ELSE") == 0) {
                node *else_block = tail->left;
                if (strcmp(else_block->token, "BLOCK") == 0) {
                    gen_stmt_list(else_block->left);
                } else {
                    gen_stmt(else_block);
                }
            }
        }
    }
    
    emit_label(end_label);
}

void gen_while(node *while_stmt) {
    /* WHILE -> cond -> body */
    node *cond = while_stmt->left;
    node *body = cond->right;
    
    char *loop_label = new_label();
    char *body_label = new_label();
    char *end_label = new_label();
    
    /* Loop start */
    emit_label(loop_label);
    
    /* Condition with short-circuit */
    gen_bool_expr(cond, body_label, end_label);
    
    /* Body */
    emit_label(body_label);
    if (strcmp(body->token, "BLOCK") == 0) {
        gen_stmt_list(body->left);
    } else {
        gen_stmt(body);
    }
    
    /* Jump back to condition */
    emit_goto(loop_label);
    
    /* End of loop */
    emit_label(end_label);
}

void gen_stmt(node *stmt) {
    if (stmt == NULL) return;
    
    char *tok = stmt->token;
    
    if (strcmp(tok, "IF") == 0) {
        gen_if(stmt);
    } else if (strcmp(tok, "WHILE") == 0) {
        gen_while(stmt);
    } else if (strcmp(tok, "ASS") == 0) {
        gen_assign(stmt);
    } else if (strcmp(tok, "DECL") == 0) {
        gen_decl(stmt);
    } else if (strcmp(tok, "RET") == 0) {
        gen_return(stmt);
    } else if (strcmp(tok, "CALL") == 0) {
        /* Expression statement - function call */
        char *temp = gen_call(stmt);
        free(temp);
    } else if (strcmp(tok, "PASS") == 0) {
        /* No code generated for pass */
    }
}

void gen_stmt_list(node *stmt_list) {
    node *stmt = stmt_list;
    while (stmt) {
        gen_stmt(stmt);
        stmt = stmt->right;
    }
}

/* ==================== Function Generation ==================== */

void gen_func(node *func) {
    /* FUNC -> name_node -> ARGS -> RETURN -> BODY */
    node *name_node = func->left;
    char *func_name = name_node->token;
    node *args_node = name_node->right;
    node *ret_node = args_node->right;
    node *body_node = ret_node->right;
    
    /* Count parameters */
    int param_count = 0;
    node *param_list = args_node->left;
    if (param_list && strcmp(param_list->token, "NONE") != 0) {
        node *type_node = param_list;
        while (type_node) {
            node *id = type_node->left;
            while (id) {
                param_count++;
                id = id->right;
            }
            type_node = type_node->right;
        }
    }
    
    /* Count local variables */
    int local_vars = count_local_vars(body_node);
    
    /* Calculate frame size: (params + locals + some temps) * 4 */
    int frame_size = (param_count + local_vars + 3) * 4;
    
    /* Emit function label */
    emit_func_label(func_name);
    
    /* Emit BeginFunc */
    emit_begin_func(frame_size);
    
    /* Generate body */
    if (body_node) {
        gen_stmt_list(body_node->left);
    }
    
    /* Emit EndFunc */
    emit_end_func();
}

/* ==================== Main Code Generation Entry Point ==================== */

void generate_code(node *root) {
    if (root == NULL) return;
    
    /* Reset state */
    reset_codegen();
    
    /* root is CODE node, left child is func_list */
    node *func = root->left;
    
    while (func) {
        if (strcmp(func->token, "FUNC") == 0) {
            gen_func(func);
        }
        func = func->right;
    }
    
    /* Print the generated code */
    print_code_formatted();
}
