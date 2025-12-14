%{
#include "proj.tab.h"
#include <string.h>
#include <stdlib.h>

int lineno = 1;
%}

%%

"if"      return IF;
"elif"    return ELIF;
"else"    return ELSE;
"while"   return WHILE;
"return"  return RETURN;
"and"     return AND;
"or"      return OR;
"not"     return NOT;
"pass"    return PASS;
"def"     return DEF;

"bool"    return BOOL;
"int"     return KW_INT;
"string"  return KW_STRING;
"float"   return KW_FLOAT;

"=="      return EQ;
"="       return ASSIGN;
">="      return GEQ;
"<="      return LEQ;
"<"       return LESS;
">"       return GREATER;
"!="      return NEQ;
"+"       return PLUS;
"-"       return MINUS;
"**"      return POW;
"*"       return MUL;
"/"       return DIV;

"."       return DOT;
";"       return SEMI;
","       return COMMA;
"("       return LPAREN;
")"       return RPAREN;
"["       return LBRACK;
"]"       return RBRACK;
"->"      return ARROW;
":"       return COLON;

"True"    return TRUE;
"False"   return FALSE;

0[xX][0-9a-fA-F]+     { yylval.ival = (int)strtol(yytext, NULL, 16); return INT; }
(0|[1-9][0-9]*)       { yylval.ival = atoi(yytext); return INT; }
[0-9]+\.[0-9]+        { yylval.fval = atof(yytext); return FLOAT; }

\"[^\n"]*\"           { yylval.sval = strdup(yytext); return STRING; }
\'[^\n']*\'           { yylval.sval = strdup(yytext); return STRING; }

[a-zA-Z][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return ID; }

[ \t\r]+  ;
\n        { lineno++; }
\#.*      ;
.         { return yytext[0]; }

%%

int yywrap() { return 1; }