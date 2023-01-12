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
     NUM = 258,
     PLUS = 259,
     MINUS = 260,
     MUL = 261,
     DIV = 262,
     ID = 263,
     begin = 264,
     END = 265,
     READ = 266,
     WRITE = 267,
     EOL = 268,
     IF = 269,
     then = 270,
     ELSE = 271,
     endif = 272,
     WHILE = 273,
     DO = 274,
     endwhile = 275,
     GT = 276,
     LT = 277,
     LE = 278,
     GE = 279,
     NE = 280,
     EQ = 281,
     ASSIGN = 282,
     BREAK = 283,
     CONTINUE = 284
   };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define ID 263
#define begin 264
#define END 265
#define READ 266
#define WRITE 267
#define EOL 268
#define IF 269
#define then 270
#define ELSE 271
#define endif 272
#define WHILE 273
#define DO 274
#define endwhile 275
#define GT 276
#define LT 277
#define LE 278
#define GE 279
#define NE 280
#define EQ 281
#define ASSIGN 282
#define BREAK 283
#define CONTINUE 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 12 "parser.y"
{
  struct tnode* p;
}
/* Line 1529 of yacc.c.  */
#line 111 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

