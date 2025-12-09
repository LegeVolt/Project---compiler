%{
#include <stdio.h>
int yylex();
int yyerror();
%}

%token AUGUST SEPTEMBER OCTOBER NOVEMBER DECEMBER YEAR

%%
s: month '#' YEAR   { printf("Date is OK\n"); }
 | error            { printf("Error in date\n"); }
 ;

month: AUGUST
     | SEPTEMBER
     | OCTOBER
     | NOVEMBER
     | DECEMBER
     ;
%%

int main() {
    return yyparse();
}

int yyerror() {
    printf("Error in date\n");
    return 0;
}