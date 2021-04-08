/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    CONTINUE = 261,
    BREAK = 262,
    RETURN = 263,
    INT = 264,
    VOID = 265,
    CONST = 266,
    L_PAR = 267,
    R_PAR = 268,
    L_SBRAC = 269,
    R_SBRAC = 270,
    L_CBRAC = 271,
    R_CBRAC = 272,
    COMMA = 273,
    COLON = 274,
    DECIMAL_TOK = 275,
    IDENT = 276,
    NOT_OP1 = 277,
    MULDIV_OP2 = 278,
    ADDMIN_OP3 = 279,
    COMP_OP4 = 280,
    EQUAL_OP5 = 281,
    AND_OP6 = 282,
    OR_OP7 = 283,
    ASSIGN_OP8 = 284
  };
#endif
/* Tokens.  */
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
#define NOT_OP1 277
#define MULDIV_OP2 278
#define ADDMIN_OP3 279
#define COMP_OP4 280
#define EQUAL_OP5 281
#define AND_OP6 282
#define OR_OP7 283
#define ASSIGN_OP8 284

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
