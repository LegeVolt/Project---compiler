#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==================== Forward declaration of node ==================== */
struct node;

/* ==================== 3AC Instruction Types ==================== */

typedef enum {
    TAC_ASSIGN,         /* t0 = value or var = t0 */
    TAC_BINOP,          /* t0 = a + b */
    TAC_UNOP,           /* t0 = not a */
    TAC_COPY,           /* a = b */
    TAC_LABEL,          /* L1: */
    TAC_GOTO,           /* Goto L1 */
    TAC_IF_GOTO,        /* if cond Goto L1 */
    TAC_IF_FALSE_GOTO,  /* if not cond Goto L1 */
    TAC_RETURN,         /* Return t0 */
    TAC_PARAM,          /* PushParam t0 */
    TAC_CALL,           /* t0 = LCall func */
    TAC_POP_PARAMS,     /* PopParams N */
    TAC_BEGIN_FUNC,     /* BeginFunc N */
    TAC_END_FUNC,       /* EndFunc */
    TAC_FUNC_LABEL      /* foo: */
} TACType;

/* ==================== 3AC Instruction ==================== */

typedef struct TACInstr {
    TACType type;
    char *result;       /* Result/destination */
    char *arg1;         /* First operand */
    char *arg2;         /* Second operand (for binop) */
    char *op;           /* Operator string */
    int value;          /* For numeric values (BeginFunc size, PopParams size) */
    struct TACInstr *next;
} TACInstr;

/* ==================== Code Generation State ==================== */

extern int temp_counter;    /* For generating t0, t1, t2, ... */
extern int label_counter;   /* For generating L0, L1, L2, ... */
extern TACInstr *code_head; /* Head of instruction list */
extern TACInstr *code_tail; /* Tail for efficient appending */

/* ==================== Function Prototypes ==================== */

/* Temp and label generation */
char *new_temp(void);
char *new_label(void);

/* Emit 3AC instructions */
void emit(TACType type, const char *result, const char *arg1, const char *arg2, const char *op, int value);
void emit_label(const char *label);
void emit_goto(const char *label);
void emit_if_goto(const char *cond, const char *label);
void emit_func_label(const char *name);
void emit_begin_func(int size);
void emit_end_func(void);
void emit_return(const char *value);
void emit_param(const char *param);
void emit_call(const char *result, const char *func_name);
void emit_pop_params(int size);
void emit_assign(const char *dest, const char *src);
void emit_binop(const char *result, const char *arg1, const char *op, const char *arg2);
void emit_unop(const char *result, const char *op, const char *arg);

/* Code generation from AST */
void generate_code(struct node *root);
void gen_func(struct node *func);
void gen_stmt(struct node *stmt);
void gen_stmt_list(struct node *stmt_list);
char *gen_expr(struct node *expr);
void gen_if(struct node *if_stmt);
void gen_while(struct node *while_stmt);
void gen_assign(struct node *assign);
void gen_decl(struct node *decl);
void gen_return(struct node *ret);
char *gen_call(struct node *call);

/* Short-circuit evaluation */
void gen_bool_expr(struct node *expr, const char *true_label, const char *false_label);

/* Output */
void print_code(void);
void reset_codegen(void);

/* Utility */
int count_local_vars(struct node *body);
int is_boolean_expr(struct node *expr);

#endif /* CODEGEN_H */
