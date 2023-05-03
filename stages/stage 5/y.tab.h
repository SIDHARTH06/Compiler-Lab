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
     LDECH = 265,
     ELDECH = 266,
     PLUS = 267,
     MINUS = 268,
     MUL = 269,
     DIV = 270,
     ID = 271,
     MOD = 272,
     REPEAT = 273,
     BREAK = 274,
     CONTINUE = 275,
     UNTIL = 276,
     STARTC = 277,
     ENDC = 278,
     INT = 279,
     STR = 280,
     BEGN = 281,
     ENDT = 282,
     MAIN = 283,
     RETURN = 284,
     DECL = 285,
     IF = 286,
     THEN = 287,
     ELSE = 288,
     WHILE = 289,
     DO = 290,
     LT = 291,
     GT = 292,
     LE = 293,
     GE = 294,
     EQ = 295,
     NE = 296,
     AND = 297,
     OR = 298,
     NOT = 299
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
#define LDECH 265
#define ELDECH 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define ID 271
#define MOD 272
#define REPEAT 273
#define BREAK 274
#define CONTINUE 275
#define UNTIL 276
#define STARTC 277
#define ENDC 278
#define INT 279
#define STR 280
#define BEGN 281
#define ENDT 282
#define MAIN 283
#define RETURN 284
#define DECL 285
#define IF 286
#define THEN 287
#define ELSE 288
#define WHILE 289
#define DO 290
#define LT 291
#define GT 292
#define LE 293
#define GE 294
#define EQ 295
#define NE 296
#define AND 297
#define OR 298
#define NOT 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "parser.y"
{
	struct tnode *no;
	char *name;
	int number;
	struct Gsymbol *Symbol;
	struct Lsymbol *Lsymbol;
	struct paramstruct* paramlist;
	struct arglist* arglist;
}
/* Line 1529 of yacc.c.  */
#line 147 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

