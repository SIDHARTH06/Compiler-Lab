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
     READ = 258,
     WRITE = 259,
     NUM = 260,
     ENDOFLINE = 261,
     ASSIGN = 262,
     PLUS = 263,
     MINUS = 264,
     MUL = 265,
     DIV = 266,
     ID = 267,
     REPEAT = 268,
     BREAK = 269,
     CONTINUE = 270,
     UNTIL = 271,
     STARTC = 272,
     ENDC = 273,
     DECL = 274,
     INT = 275,
     STR = 276,
     BEGN = 277,
     ENDT = 278,
     IF = 279,
     THEN = 280,
     ELSE = 281,
     WHILE = 282,
     DO = 283,
     LT = 284,
     GT = 285,
     LE = 286,
     GE = 287,
     EQ = 288,
     NE = 289,
     AND = 290,
     OR = 291,
     NOT = 292
   };
#endif
/* Tokens.  */
#define READ 258
#define WRITE 259
#define NUM 260
#define ENDOFLINE 261
#define ASSIGN 262
#define PLUS 263
#define MINUS 264
#define MUL 265
#define DIV 266
#define ID 267
#define REPEAT 268
#define BREAK 269
#define CONTINUE 270
#define UNTIL 271
#define STARTC 272
#define ENDC 273
#define DECL 274
#define INT 275
#define STR 276
#define BEGN 277
#define ENDT 278
#define IF 279
#define THEN 280
#define ELSE 281
#define WHILE 282
#define DO 283
#define LT 284
#define GT 285
#define LE 286
#define GE 287
#define EQ 288
#define NE 289
#define AND 290
#define OR 291
#define NOT 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "exprtree.y"
{
	struct tnode *no;
	char *name;
	int number;
	struct Gsymbol *Symbol;
}
/* Line 1529 of yacc.c.  */
#line 130 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

