/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PROJ_TAB_H_INCLUDED
# define YY_YY_PROJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    ID = 259,                      /* ID  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    ELIF = 264,                    /* ELIF  */
    WHILE = 265,                   /* WHILE  */
    RETURN = 266,                  /* RETURN  */
    AND = 267,                     /* AND  */
    OR = 268,                      /* OR  */
    NOT = 269,                     /* NOT  */
    PASS = 270,                    /* PASS  */
    DEF = 271,                     /* DEF  */
    BOOL = 272,                    /* BOOL  */
    KW_INT = 273,                  /* KW_INT  */
    KW_STRING = 274,               /* KW_STRING  */
    KW_FLOAT = 275,                /* KW_FLOAT  */
    EQ = 276,                      /* EQ  */
    ASSIGN = 277,                  /* ASSIGN  */
    GEQ = 278,                     /* GEQ  */
    LEQ = 279,                     /* LEQ  */
    LESS = 280,                    /* LESS  */
    GREATER = 281,                 /* GREATER  */
    NEQ = 282,                     /* NEQ  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    POW = 285,                     /* POW  */
    MUL = 286,                     /* MUL  */
    DIV = 287,                     /* DIV  */
    DOT = 288,                     /* DOT  */
    SEMI = 289,                    /* SEMI  */
    COMMA = 290,                   /* COMMA  */
    LPAREN = 291,                  /* LPAREN  */
    RPAREN = 292,                  /* RPAREN  */
    LBRACK = 293,                  /* LBRACK  */
    RBRACK = 294,                  /* RBRACK  */
    ARROW = 295,                   /* ARROW  */
    COLON = 296,                   /* COLON  */
    TRUE = 297,                    /* TRUE  */
    FALSE = 298,                   /* FALSE  */
    LOWER_THAN_ELSE = 299          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "proj.y"

    char *sval;
    int ival;
    float fval;
    struct node *n;

#line 115 "proj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PROJ_TAB_H_INCLUDED  */
