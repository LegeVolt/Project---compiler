/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     ID = 259,
     INT = 260,
     FLOAT = 261,
     IF = 262,
     ELSE = 263,
     ELIF = 264,
     WHILE = 265,
     RETURN = 266,
     AND = 267,
     OR = 268,
     NOT = 269,
     PASS = 270,
     DEF = 271,
     BOOL = 272,
     KW_INT = 273,
     KW_STRING = 274,
     KW_FLOAT = 275,
     EQ = 276,
     ASSIGN = 277,
     GEQ = 278,
     LEQ = 279,
     LESS = 280,
     GREATER = 281,
     NEQ = 282,
     PLUS = 283,
     MINUS = 284,
     POW = 285,
     MUL = 286,
     DIV = 287,
     DOT = 288,
     SEMI = 289,
     COMMA = 290,
     LPAREN = 291,
     RPAREN = 292,
     LBRACK = 293,
     RBRACK = 294,
     ARROW = 295,
     COLON = 296,
     TRUE = 297,
     FALSE = 298,
     LOWER_THAN_ELSE = 299
   };
#endif
/* Tokens.  */
#define STRING 258
#define ID 259
#define INT 260
#define FLOAT 261
#define IF 262
#define ELSE 263
#define ELIF 264
#define WHILE 265
#define RETURN 266
#define AND 267
#define OR 268
#define NOT 269
#define PASS 270
#define DEF 271
#define BOOL 272
#define KW_INT 273
#define KW_STRING 274
#define KW_FLOAT 275
#define EQ 276
#define ASSIGN 277
#define GEQ 278
#define LEQ 279
#define LESS 280
#define GREATER 281
#define NEQ 282
#define PLUS 283
#define MINUS 284
#define POW 285
#define MUL 286
#define DIV 287
#define DOT 288
#define SEMI 289
#define COMMA 290
#define LPAREN 291
#define RPAREN 292
#define LBRACK 293
#define RBRACK 294
#define ARROW 295
#define COLON 296
#define TRUE 297
#define FALSE 298
#define LOWER_THAN_ELSE 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "proj.y"
{
    char *sval;
    int ival;
    float fval;
    struct node *n;
}
/* Line 1529 of yacc.c.  */
#line 144 "proj.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

