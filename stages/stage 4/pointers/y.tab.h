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
     STRNG = 258,
     ADDRESS = 259,
     READ = 260,
     WRITE = 261,
     NUM = 262,
     ENDOFLINE = 263,
     ASSIGN = 264,
     PLUS = 265,
     MINUS = 266,
     MUL = 267,
     DIV = 268,
     ID = 269,
     MOD = 270,
     REPEAT = 271,
     BREAK = 272,
     CONTINUE = 273,
     UNTIL = 274,
     STARTC = 275,
     ENDC = 276,
     DECL = 277,
     INT = 278,
     STR = 279,
     BEGN = 280,
     ENDT = 281,
     IF = 282,
     THEN = 283,
     ELSE = 284,
     WHILE = 285,
     DO = 286,
     LT = 287,
     GT = 288,
     LE = 289,
     GE = 290,
     EQ = 291,
     NE = 292,
     AND = 293,
     OR = 294,
     NOT = 295
   };
#endif
/* Tokens.  */
#define STRNG 258
#define ADDRESS 259
#define READ 260
#define WRITE 261
#define NUM 262
#define ENDOFLINE 263
#define ASSIGN 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define ID 269
#define MOD 270
#define REPEAT 271
#define BREAK 272
#define CONTINUE 273
#define UNTIL 274
#define STARTC 275
#define ENDC 276
#define DECL 277
#define INT 278
#define STR 279
#define BEGN 280
#define ENDT 281
#define IF 282
#define THEN 283
#define ELSE 284
#define WHILE 285
#define DO 286
#define LT 287
#define GT 288
#define LE 289
#define GE 290
#define EQ 291
#define NE 292
#define AND 293
#define OR 294
#define NOT 295




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
#line 136 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

