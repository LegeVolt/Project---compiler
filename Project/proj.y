%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
extern int lineno;
extern char *yytext;

typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
} node;

node *mknode(char *token, node *left, node *right);
node *mk_leaf(char *token);
node *int_node(int val);
node *float_node(float val);
void printtree(node *tree, int indent);
%}

%union {
    char *sval;
    int ival;
    float fval;
    struct node *n;
}

%type <n> program func_list func args arg_decl_list param_decl type id_list
%type <n> opt_ret_type return_type body stmt_list stmt if_stmt assign_stmt return_stmt
%type <n> expr pass_stmt while_stmt block suite
%type <n> elif_tail

%token <sval> STRING ID
%token <ival> INT
%token <fval> FLOAT

%token IF ELSE ELIF WHILE RETURN AND OR NOT PASS DEF BOOL KW_INT KW_STRING KW_FLOAT
%token EQ ASSIGN GEQ LEQ LESS GREATER NEQ PLUS MINUS POW MUL DIV
%token DOT SEMI COMMA LPAREN RPAREN LBRACK RBRACK ARROW COLON
%token TRUE FALSE

%left PLUS MINUS
%left MUL DIV
%right POW

%nonassoc LOWER_THAN_ELSE   /* lowest, for dangling-else reduce */
%nonassoc ELIF             /* prefer shift on ELIF over reduce */
%nonassoc ELSE             /* highest among the three */

%%

program
    : func_list
      { $$ = mknode("CODE", $1, NULL); printtree($$, 0); }
    ;

func_list
    : func { $$ = $1; }
    | func_list func
      {
          node *t = $1;
          while(t->right != NULL) t = t->right;
          t->right = $2;
          $$ = $1;
      }
    ;

func
    : DEF ID LPAREN args RPAREN opt_ret_type COLON body
      {
          node *func_name = mk_leaf($2);
          node *a = $4;      /* ARGS node */
          node *r = $6;      /* RETURN node */
          node *b = $8;      /* BODY node */

          /* (FUNC foo (ARGS ...) (RETURN ...) (BODY ...)) */
          func_name->right = a;
          a->right = r;
          r->right = b;

          $$ = mknode("FUNC", func_name, NULL);
      }
    ;

args
    : /* empty */
      { $$ = mknode("ARGS", mknode("NONE", NULL, NULL), NULL); }
    | arg_decl_list
      { $$ = mknode("ARGS", $1, NULL); }
    ;

arg_decl_list
    : param_decl { $$ = $1; }
    | param_decl SEMI arg_decl_list
      {
          $1->right = $3;
          $$ = $1;
      }
    ;

param_decl
    : type id_list
      {
          /* (INT x y z) or (BOOL f) */
          $1->left = $2;
          $$ = $1;
      }
    ;

type
    : KW_INT    { $$ = mknode("INT", NULL, NULL); }
    | KW_STRING { $$ = mknode("STRING", NULL, NULL); }
    | KW_FLOAT  { $$ = mknode("FLOAT", NULL, NULL); }
    | BOOL      { $$ = mknode("BOOL", NULL, NULL); }
    ;

id_list
    : ID { $$ = mk_leaf($1); }
    | ID COMMA id_list
      {
          node *n = mk_leaf($1);
          n->right = $3;
          $$ = n;
      }
    ;

/* ===== RETURN TYPE (כמו במצגות) ===== */
opt_ret_type
    : /* empty */
      { $$ = mknode("RETURN", mknode("VOID", NULL, NULL), NULL); }
    | return_type
      { $$ = $1; }
    ;

return_type
    : ARROW type
      { $$ = mknode("RETURN", $2, NULL); }
    ;

body
    : LESS stmt_list GREATER
      { $$ = mknode("BODY", $2, NULL); }
    ;

block
    : LESS stmt_list GREATER
      { $$ = mknode("BLOCK", $2, NULL); }
    ;

/* SUITE: block או statement יחיד -> עטוף כ-BLOCK כדי להתאים למבנה במצגות */
suite
    : block { $$ = $1; }
    | stmt  { $$ = mknode("BLOCK", $1, NULL); }
    ;

stmt_list
    : /* empty */ { $$ = NULL; }
    | stmt_list stmt
      {
          if ($1 == NULL) $$ = $2;
          else {
              node *p = $1;
              while (p->right) p = p->right;
              p->right = $2;
              $$ = $1;
          }
      }
    ;

stmt
    : if_stmt
    | assign_stmt
    | return_stmt
    | pass_stmt
    | while_stmt
    ;

/* ===== IF / ELIF / ELSE (כמו במצגות) ===== */
if_stmt
    : IF expr COLON suite %prec LOWER_THAN_ELSE
      {
          /* מבנה ילדים: cond -> then (ללא tail) */
          node *cond = $2;
          node *then_b = $4;
          cond->right = then_b;
          $$ = mknode("IF", cond, NULL);
      }
    | IF expr COLON suite elif_tail
      {
          /* מבנה ילדים: cond -> then -> tail (ELIF/ELSE) */
          node *cond = $2;
          node *then_b = $4;
          node *tail = $5;
          cond->right = then_b;
          then_b->right = tail;
          $$ = mknode("IF", cond, NULL);
      }
    ;

/* שרשרת ELIF/ELSE ללא ε – המקרה הריק מטופל בכלל הראשון של if_stmt */
elif_tail
    : ELIF expr COLON suite %prec LOWER_THAN_ELSE
      {
          node *cond = $2;
          cond->right = $4;
          $$ = mknode("ELIF", cond, NULL);
      }
    | ELIF expr COLON suite elif_tail
      {
          node *cond = $2;
          cond->right = $4;
          node *elif_node = mknode("ELIF", cond, NULL);
          elif_node->right = $5;
          $$ = elif_node;
      }
    | ELSE COLON suite
      { $$ = mknode("ELSE", $3, NULL); }
    ;

assign_stmt
    : ID ASSIGN expr DOT
      {
          node *id = mk_leaf($1);
          id->right = $3;
          $$ = mknode("ASS", id, NULL);
      }
    ;

return_stmt
    : RETURN expr DOT
      { $$ = mknode("RET", $2, NULL); }
    | RETURN DOT
      { $$ = mknode("RET", mknode("VOID", NULL, NULL), NULL); }
    ;

pass_stmt
    : PASS DOT { $$ = mknode("PASS", NULL, NULL); }
    ;

while_stmt
    : WHILE expr COLON suite
      {
          node *cond = $2;
          cond->right = $4;
          $$ = mknode("WHILE", cond, NULL);
      }
    ;

expr
    : expr PLUS expr  { node *n = mknode("+", $1, NULL); $1->right = $3; $$ = n; }
    | expr MINUS expr { node *n = mknode("-", $1, NULL); $1->right = $3; $$ = n; }
    | expr MUL expr   { node *n = mknode("*", $1, NULL); $1->right = $3; $$ = n; }
    | expr DIV expr   { node *n = mknode("/", $1, NULL); $1->right = $3; $$ = n; }
    | INT             { $$ = int_node($1); }
    | FLOAT           { $$ = float_node($1); }
    | ID              { $$ = mk_leaf($1); }
    | STRING          { $$ = mk_leaf($1); }
    | TRUE            { $$ = mknode("True", NULL, NULL); }
    | FALSE           { $$ = mknode("False", NULL, NULL); }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

%%

int main() {
    return yyparse();
}

int yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", lineno, s, yytext);
    return 0;
}

node *mknode(char *token, node *left, node *right) {
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}

node *mk_leaf(char *token) {
    return mknode(token, NULL, NULL);
}

node *int_node(int val) {
    char buff[20];
    sprintf(buff, "%d", val);
    return mknode(buff, NULL, NULL);
}

node *float_node(float val) {
    char buff[30];
    sprintf(buff, "%.2f", val);
    return mknode(buff, NULL, NULL);
}

void printtree(node *tree, int indent) {
    if (!tree) return;
    for (int i = 0; i < indent; ++i) printf("  ");
    if (tree->left == NULL) {
        printf("%s\n", tree->token);
    } else {
        printf("(%s\n", tree->token);
        node *child = tree->left;
        while (child) {
            printtree(child, indent + 1);
            child = child->right;
        }
        for (int i = 0; i < indent; ++i) printf("  ");
        printf(")\n");
    }
}
