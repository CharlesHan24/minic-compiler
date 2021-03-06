/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    CONTINUE = 261,                /* CONTINUE  */
    BREAK = 262,                   /* BREAK  */
    RETURN = 263,                  /* RETURN  */
    INT = 264,                     /* INT  */
    VOID = 265,                    /* VOID  */
    CONST = 266,                   /* CONST  */
    L_PAR = 267,                   /* L_PAR  */
    R_PAR = 268,                   /* R_PAR  */
    L_SBRAC = 269,                 /* L_SBRAC  */
    R_SBRAC = 270,                 /* R_SBRAC  */
    L_CBRAC = 271,                 /* L_CBRAC  */
    R_CBRAC = 272,                 /* R_CBRAC  */
    COMMA = 273,                   /* COMMA  */
    COLON = 274,                   /* COLON  */
    DECIMAL_TOK = 275,             /* DECIMAL_TOK  */
    IDENT = 276,                   /* IDENT  */
    IDENT_FUNC = 277,              /* IDENT_FUNC  */
    NOT_OP1 = 278,                 /* NOT_OP1  */
    MULDIV_OP2 = 279,              /* MULDIV_OP2  */
    ADDMIN_OP3 = 280,              /* ADDMIN_OP3  */
    COMP_OP4 = 281,                /* COMP_OP4  */
    EQUAL_OP5 = 282,               /* EQUAL_OP5  */
    AND_OP6 = 283,                 /* AND_OP6  */
    OR_OP7 = 284,                  /* OR_OP7  */
    ASSIGN_OP8 = 285               /* ASSIGN_OP8  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define CONTINUE 261
#define BREAK 262
#define RETURN 263
#define INT 264
#define VOID 265
#define CONST 266
#define L_PAR 267
#define R_PAR 268
#define L_SBRAC 269
#define R_SBRAC 270
#define L_CBRAC 271
#define R_CBRAC 272
#define COMMA 273
#define COLON 274
#define DECIMAL_TOK 275
#define IDENT 276
#define IDENT_FUNC 277
#define NOT_OP1 278
#define MULDIV_OP2 279
#define ADDMIN_OP3 280
#define COMP_OP4 281
#define EQUAL_OP5 282
#define AND_OP6 283
#define OR_OP7 284
#define ASSIGN_OP8 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "parser.y"

	unsigned val;
	char* name;
	struct Syntax_Tree* node;

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#include <stdio.h>
void minic2eeyore(FILE* inp_file, FILE* oup_file);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
