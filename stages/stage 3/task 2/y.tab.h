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
     ID = 261,
     ENDOFLINE = 262,
     ASSIGN = 263,
     PLUS = 264,
     MINUS = 265,
     MUL = 266,
     DIV = 267,
     BEG = 268,
     ENOFLINE = 269,
     END = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     ENDIF = 274,
     WHILE = 275,
     DO = 276,
     ENDWHILE = 277,
     LT = 278,
     GT = 279,
     LE = 280,
     GE = 281,
     EQ = 282,
     NE = 283,
     AND = 284,
     OR = 285,
     NOT = 286
   };
#endif
/* Tokens.  */
#define READ 258
#define WRITE 259
#define NUM 260
#define ID 261
#define ENDOFLINE 262
#define ASSIGN 263
#define PLUS 264
#define MINUS 265
#define MUL 266
#define DIV 267
#define BEG 268
#define ENOFLINE 269
#define END 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define LT 278
#define GT 279
#define LE 280
#define GE 281
#define EQ 282
#define NE 283
#define AND 284
#define OR 285
#define NOT 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "exprtree.y"
{
	struct tnode *no;
}
/* Line 1529 of yacc.c.  */
#line 115 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

