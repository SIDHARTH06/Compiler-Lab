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
     ADDRESS = 258,
     READ = 259,
     WRITE = 260,
     NUM = 261,
     ENDOFLINE = 262,
     ASSIGN = 263,
     PLUS = 264,
     MINUS = 265,
     MUL = 266,
     DIV = 267,
     ID = 268,
     REPEAT = 269,
     BREAK = 270,
     CONTINUE = 271,
     UNTIL = 272,
     STARTC = 273,
     ENDC = 274,
     DECL = 275,
     INT = 276,
     STR = 277,
     BEGN = 278,
     ENDT = 279,
     IF = 280,
     THEN = 281,
     ELSE = 282,
     WHILE = 283,
     DO = 284,
     LT = 285,
     GT = 286,
     LE = 287,
     GE = 288,
     EQ = 289,
     NE = 290,
     AND = 291,
     OR = 292,
     NOT = 293
   };
#endif
/* Tokens.  */
#define ADDRESS 258
#define READ 259
#define WRITE 260
#define NUM 261
#define ENDOFLINE 262
#define ASSIGN 263
#define PLUS 264
#define MINUS 265
#define MUL 266
#define DIV 267
#define ID 268
#define REPEAT 269
#define BREAK 270
#define CONTINUE 271
#define UNTIL 272
#define STARTC 273
#define ENDC 274
#define DECL 275
#define INT 276
#define STR 277
#define BEGN 278
#define ENDT 279
#define IF 280
#define THEN 281
#define ELSE 282
#define WHILE 283
#define DO 284
#define LT 285
#define GT 286
#define LE 287
#define GE 288
#define EQ 289
#define NE 290
#define AND 291
#define OR 292
#define NOT 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "parser.y"
{
	struct tnode *no;
	char *name;
	int number;
	struct Gsymbol *Symbol;
}
/* Line 1529 of yacc.c.  */
#line 132 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
