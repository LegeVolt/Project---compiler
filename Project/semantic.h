#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==================== Type Definitions ==================== */

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_VOID,
    TYPE_ERROR
} DataType;

/* ==================== Symbol Table Structures ==================== */

/* Variable symbol */
typedef struct Symbol {
    char *name;
    DataType type;
    int lineno;
    struct Symbol *next;
} Symbol;

/* Scope for variable symbols (stack-based) */
typedef struct Scope {
    Symbol *symbols;
    struct Scope *parent;
} Scope;

/* Function parameter */
typedef struct Param {
    char *name;
    DataType type;
    struct Param *next;
} Param;

/* Function symbol */
typedef struct FuncSymbol {
    char *name;
    DataType return_type;
    Param *params;
    int param_count;
    int lineno;
    struct FuncSymbol *next;
} FuncSymbol;

/* ==================== Global State ==================== */

extern FuncSymbol *func_table;      /* Global function table */
extern Scope *current_scope;        /* Current variable scope */
extern int semantic_errors;         /* Error counter */
extern DataType current_func_return_type;  /* For checking return statements */

/* ==================== Forward declaration of node ==================== */
struct node;

/* ==================== Function Prototypes ==================== */

/* Error reporting */
void semantic_error(const char *msg, int lineno);
void semantic_error_fmt(int lineno, const char *fmt, ...);

/* Type utilities */
const char *type_to_string(DataType type);
DataType string_to_type(const char *s);

/* Scope management */
void enter_scope(void);
void exit_scope(void);

/* Variable symbol table operations */
Symbol *lookup_var(const char *name);
Symbol *lookup_var_current_scope(const char *name);
int add_var(const char *name, DataType type, int lineno);

/* Function symbol table operations */
FuncSymbol *lookup_func(const char *name);
int add_func(const char *name, DataType return_type, Param *params, int param_count, int lineno);

/* Semantic analysis entry point */
int semantic_analysis(struct node *root);

/* Analysis functions */
void analyze_program(struct node *root);
void collect_functions(struct node *func_list);
void analyze_function(struct node *func);
void analyze_body(struct node *body);
void analyze_stmt(struct node *stmt);
void analyze_stmt_list(struct node *stmt_list);
DataType analyze_expr(struct node *expr);
void analyze_if(struct node *if_stmt);
void analyze_while(struct node *while_stmt);
void analyze_assign(struct node *assign);
void analyze_decl(struct node *decl);
void analyze_return(struct node *ret);
DataType analyze_call(struct node *call);

#endif /* SEMANTIC_H */

