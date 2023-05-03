/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include "astfunctions.h"
	#include "astfunctions.c"
	#include <string.h>
	#include "symboltable.c"

	int yylex();
    int yyerror();
	regs[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	extern FILE *yyin;
	nooffreereg=16;
	int label=0;
	struct gSymbolTable *gst;
	struct lSymbolTable *lst;
	int gm=4096;
	int flabel=0;
	int cb=0;
	FILE* target_file;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   653

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    17,    20,    22,    26,
      30,    32,    34,    39,    47,    50,    52,    57,    61,    66,
      69,    72,    74,    86,    97,   107,   110,   112,   116,   120,
     122,   124,   129,   137,   140,   142,   144,   147,   149,   151,
     153,   155,   157,   159,   161,   163,   165,   167,   169,   172,
     174,   180,   186,   191,   197,   205,   217,   225,   235,   238,
     241,   251,   255,   259,   263,   267,   271,   275,   279,   283,
     287,   291,   295,   299,   303,   307,   310,   314,   316,   318,
     320,   322,   326,   328,   333,   335,   340,   348
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    59,    61,    -1,    52,    61,    -1,
      61,    -1,    30,    22,    53,    23,    -1,    53,    54,    -1,
      54,    -1,    66,    55,     8,    -1,    55,    45,    56,    -1,
      56,    -1,    16,    -1,    16,    46,     7,    47,    -1,    16,
      46,     7,    47,    46,     7,    47,    -1,    14,    16,    -1,
      57,    -1,    16,    48,    58,    49,    -1,    16,    48,    49,
      -1,    58,    45,    66,    16,    -1,    66,    16,    -1,    59,
      60,    -1,    60,    -1,    66,    16,    48,    58,    49,    22,
      10,    62,    11,    67,    23,    -1,    66,    16,    48,    49,
      22,    10,    62,    11,    67,    23,    -1,    28,    48,    49,
      22,    10,    62,    11,    67,    23,    -1,    62,    63,    -1,
      63,    -1,    66,    64,     8,    -1,    64,    45,    65,    -1,
      65,    -1,    16,    -1,    16,    46,     7,    47,    -1,    16,
      46,     7,    47,    46,     7,    47,    -1,    14,    16,    -1,
      24,    -1,    25,    -1,    67,    68,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    82,
       8,    -1,    79,    -1,     5,    48,    83,    49,     8,    -1,
       6,    48,    80,    49,     8,    -1,    83,     9,    80,     8,
      -1,    83,     9,     4,    83,     8,    -1,    31,    48,    80,
      49,    22,    67,    23,    -1,    31,    48,    80,    49,    22,
      67,    23,    33,    22,    67,    23,    -1,    34,    48,    80,
      49,    22,    67,    23,    -1,    35,    22,    67,    23,    34,
      48,    80,    49,     8,    -1,    19,     8,    -1,    20,     8,
      -1,    18,    22,    67,    23,    21,    48,    80,    49,     8,
      -1,    29,    80,     8,    -1,    80,    12,    80,    -1,    80,
      13,    80,    -1,    80,    14,    80,    -1,    80,    15,    80,
      -1,    80,    17,    80,    -1,    80,    36,    80,    -1,    80,
      37,    80,    -1,    80,    38,    80,    -1,    80,    39,    80,
      -1,    80,    40,    80,    -1,    80,    41,    80,    -1,    80,
      42,    80,    -1,    80,    43,    80,    -1,    44,    80,    -1,
      48,    80,    49,    -1,    83,    -1,     7,    -1,     3,    -1,
      82,    -1,    81,    45,    80,    -1,    80,    -1,    16,    48,
      81,    49,    -1,    16,    -1,    16,    46,    80,    47,    -1,
      16,    46,    80,    47,    46,    80,    47,    -1,    14,    16,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    92,    97,   104,   139,   143,   148,   159,
     163,   169,   173,   177,   181,   185,   191,   195,   202,   206,
     212,   216,   221,   336,   399,   476,   481,   487,   499,   504,
     510,   515,   519,   523,   529,   533,   541,   545,   554,   558,
     562,   566,   570,   574,   578,   582,   586,   590,   594,   598,
     604,   610,   616,   620,   627,   633,   638,   643,   648,   653,
     658,   663,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   692,   697,   703,   717,   723,   735,   745
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRNG", "ADDRESS", "READ", "WRITE",
  "NUM", "ENDOFLINE", "ASSIGN", "LDECH", "ELDECH", "PLUS", "MINUS", "MUL",
  "DIV", "ID", "MOD", "REPEAT", "BREAK", "CONTINUE", "UNTIL", "STARTC",
  "ENDC", "INT", "STR", "BEGN", "ENDT", "MAIN", "RETURN", "DECL", "IF",
  "THEN", "ELSE", "WHILE", "DO", "LT", "GT", "LE", "GE", "EQ", "NE", "AND",
  "OR", "NOT", "','", "'['", "']'", "'('", "')'", "$accept", "program",
  "GDECLBLOCK", "GDEC", "DEC", "VARLIST", "IDDECL", "FDECNAME",
  "PARAMLIST", "FDEFBLOCK", "FDEF", "MAINBLOCK", "LDECLARATIONS",
  "LDECLSTMNT", "LVARLIST", "LIDDECL", "TYPE", "SLIST", "STMNT",
  "INPUTSTMNT", "OUTPUTSTMNT", "ASSIGNSTMNT", "IFSTMNT", "IFELSESTMNT",
  "WHILESTMNT", "DOWHILESTMNT", "BREAKSTMNT", "CONTINUESTMNT",
  "REPEATUNTILSTMNT", "RETURNSTMNT", "expr", "ARGMNTLIST", "FNCALLSTMNT",
  "IDENTIFIER", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    44,    91,    93,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    53,    53,    54,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    62,    62,    63,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    70,    71,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    83,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     4,     2,     1,     3,     3,
       1,     1,     4,     7,     2,     1,     4,     3,     4,     2,
       2,     1,    11,    10,     9,     2,     1,     3,     3,     1,
       1,     4,     7,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       5,     5,     4,     5,     7,    11,     7,     9,     2,     2,
       9,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       1,     3,     1,     4,     1,     4,     7,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,     1,    34,
      35,     0,    21,     3,     0,     0,     0,     7,     0,    20,
       2,     0,     0,     5,     6,     0,    11,     0,    10,    15,
       0,     0,    14,     0,     0,     8,     0,     0,     0,     0,
       0,    26,     0,     0,    17,     0,     9,     0,     0,     0,
      19,     0,    25,     0,    30,     0,    29,    12,    16,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    49,     0,     0,    33,     0,
      27,     0,     0,     0,    18,     0,     0,     0,    87,     0,
       0,     0,    58,    59,    79,    78,     0,     0,     0,    80,
      77,     0,     0,     0,    24,    36,    48,     0,     0,    28,
       0,     0,     0,    84,     0,     0,     0,    82,     0,     0,
      75,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    13,     0,     0,     0,     0,    85,     0,    83,
       0,    76,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,    52,
       0,    23,     0,    50,    51,     0,    81,     0,     0,     0,
       0,    53,     0,    22,     0,     0,     0,     0,     0,    32,
      86,     0,    54,    56,     0,     0,     0,     0,    60,     0,
      57,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    16,    17,    27,    28,    29,    38,    11,
      12,     5,    40,    41,    55,    56,    42,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     108,   128,   109,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
      36,   -17,    16,    49,     8,  -101,    19,   132,  -101,  -101,
    -101,     8,  -101,  -101,    40,    30,    87,  -101,    85,  -101,
    -101,    27,    70,  -101,  -101,    69,    76,    -6,  -101,  -101,
      10,   132,  -101,    89,    18,  -101,    85,    82,   -21,   110,
      52,  -101,   109,    92,  -101,   -19,  -101,   126,   132,   107,
    -101,   618,  -101,   127,    98,     1,  -101,   101,  -101,   132,
     143,   144,   118,   120,   151,    84,   147,   162,   165,    13,
     130,   131,   152,   442,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,   167,   171,  -101,   174,
    -101,   109,   176,    58,  -101,   132,   119,    13,  -101,    13,
      13,   618,  -101,  -101,  -101,  -101,    13,    13,    78,  -101,
    -101,    13,    13,   618,  -101,  -101,  -101,     3,   137,  -101,
     139,   618,    83,   145,   136,   175,   323,   403,    -5,   464,
     413,   215,  -101,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   229,   262,   486,   119,
     359,   148,  -101,   508,   618,   185,   187,   150,    13,  -101,
     198,  -101,    57,    57,   180,   180,  -101,   138,   138,   138,
     138,   138,   138,   413,   413,   199,   200,   186,   217,  -101,
     219,  -101,   530,  -101,  -101,    13,   403,   183,   618,   618,
     188,  -101,   190,  -101,   367,    13,   552,   574,    13,  -101,
    -101,   276,   201,  -101,   309,   225,   213,   230,  -101,   618,
    -101,   596,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,   223,  -101,   204,  -101,   211,  -101,
     236,     4,   -47,   -35,  -101,   157,     7,  -100,   -69,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
      65,  -101,   -48,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      87,   129,    35,    86,   115,    52,   104,   149,    13,    90,
     105,    14,    93,   148,    18,    20,   104,    64,    14,    65,
     105,   153,    87,    18,    48,    86,    48,    64,    49,    65,
      58,     6,     9,    10,     9,    10,     1,    39,     7,    36,
     158,    39,     9,    10,   159,   124,    91,   106,   122,     8,
      87,   107,    22,    86,   182,    60,    21,   106,    52,    37,
     115,   107,    87,    51,     1,    86,     2,    44,    15,   121,
      87,   135,   136,    86,   137,    30,     9,    10,    87,   115,
      31,    86,     9,    10,   115,    32,   132,    52,   196,   197,
     133,   134,   135,   136,   154,   137,    43,    87,   178,    25,
      86,    26,    87,    87,    47,    86,    86,     9,    10,   211,
      23,     9,    10,   115,   138,   139,   140,   141,   142,   143,
     144,   145,    33,    53,    34,    54,    50,   115,   115,    61,
      99,    87,   100,    64,    86,   123,    59,    87,    87,    57,
      86,    86,   115,    88,    89,    87,    87,    92,    86,    86,
     133,   134,   135,   136,    95,   137,     9,    10,    87,    94,
      87,    86,   125,    86,   126,   127,    96,    98,    97,   101,
     102,   130,   131,   103,   113,   116,   146,   147,   111,   112,
     117,   118,   150,   120,   151,   155,   152,   133,   134,   135,
     136,    99,   137,   183,   180,   184,   185,   137,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   138,   139,   140,   141,   142,   143,   144,   145,   187,
     190,   188,   189,   186,   156,   191,   192,   133,   134,   135,
     136,   195,   137,   208,   206,   209,   198,   199,   210,    24,
      46,   133,   134,   135,   136,    45,   137,    19,   119,     0,
     194,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     201,     0,     0,   204,   161,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   133,   134,   135,   136,   175,   137,
       0,     0,     0,     0,     0,     0,     0,     0,   133,   134,
     135,   136,     0,   137,     0,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,     0,
       0,   176,   138,   139,   140,   141,   142,   143,   144,   145,
       0,   133,   134,   135,   136,   205,   137,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,   135,   136,     0,
     137,     0,     0,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,     0,     0,     0,   207,   138,
     139,   140,   141,   142,   143,   144,   145,   179,     0,     0,
     157,   133,   134,   135,   136,     0,   137,     0,     0,   133,
     134,   135,   136,     0,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   200,   133,   134,   135,   136,     0,
     137,     0,     0,     0,     0,   133,   134,   135,   136,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   140,   141,   142,   143,   144,   145,    62,    63,   138,
     139,   140,   141,   142,   143,     0,    64,     0,    65,     0,
      66,    67,    68,     0,     0,   114,     0,     0,     0,    62,
      63,    69,     0,    70,     0,     0,    71,    72,    64,     0,
      65,     0,    66,    67,    68,     0,     0,   160,     0,     0,
       0,    62,    63,    69,     0,    70,     0,     0,    71,    72,
      64,     0,    65,     0,    66,    67,    68,     0,     0,   177,
       0,     0,     0,    62,    63,    69,     0,    70,     0,     0,
      71,    72,    64,     0,    65,     0,    66,    67,    68,     0,
       0,   181,     0,     0,     0,    62,    63,    69,     0,    70,
       0,     0,    71,    72,    64,     0,    65,     0,    66,    67,
      68,     0,     0,   193,     0,     0,     0,    62,    63,    69,
       0,    70,     0,     0,    71,    72,    64,     0,    65,     0,
      66,    67,    68,     0,     0,   202,     0,     0,     0,    62,
      63,    69,     0,    70,     0,     0,    71,    72,    64,     0,
      65,     0,    66,    67,    68,     0,     0,   203,     0,     0,
       0,    62,    63,    69,     0,    70,     0,     0,    71,    72,
      64,     0,    65,     0,    66,    67,    68,     0,     0,   212,
       0,     0,     0,    62,    63,    69,     0,    70,     0,     0,
      71,    72,    64,     0,    65,     0,    66,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,    70,
       0,     0,    71,    72
};

static const yytype_int16 yycheck[] =
{
      51,   101,     8,    51,    73,    40,     3,     4,     4,     8,
       7,     4,    59,   113,     7,    11,     3,    14,    11,    16,
       7,   121,    73,    16,    45,    73,    45,    14,    49,    16,
      49,    48,    24,    25,    24,    25,    28,    30,    22,    45,
      45,    34,    24,    25,    49,    96,    45,    44,    95,     0,
     101,    48,    22,   101,   154,    48,    16,    44,    93,    49,
     129,    48,   113,    11,    28,   113,    30,    49,    49,    11,
     121,    14,    15,   121,    17,    48,    24,    25,   129,   148,
      10,   129,    24,    25,   153,    16,     8,   122,   188,   189,
      12,    13,    14,    15,    11,    17,     7,   148,   149,    14,
     148,    16,   153,   154,    22,   153,   154,    24,    25,   209,
      23,    24,    25,   182,    36,    37,    38,    39,    40,    41,
      42,    43,    46,    14,    48,    16,    16,   196,   197,    22,
      46,   182,    48,    14,   182,    16,    10,   188,   189,    47,
     188,   189,   211,    16,    46,   196,   197,    46,   196,   197,
      12,    13,    14,    15,    10,    17,    24,    25,   209,    16,
     211,   209,    97,   211,    99,   100,    48,    16,    48,    22,
       8,   106,   107,     8,    22,     8,   111,   112,    48,    48,
       9,     7,   117,     7,    47,    49,    47,    12,    13,    14,
      15,    46,    17,     8,    46,     8,    46,    17,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    36,    37,    38,    39,    40,    41,    42,    43,    21,
      34,    22,    22,   158,    49,     8,     7,    12,    13,    14,
      15,    48,    17,     8,    33,    22,    48,    47,     8,    16,
      36,    12,    13,    14,    15,    34,    17,    11,    91,    -1,
     185,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
     195,    -1,    -1,   198,    49,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    12,    13,    14,    15,    49,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    49,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    12,    13,    14,    15,    49,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    36,
      37,    38,    39,    40,    41,    42,    43,     8,    -1,    -1,
      47,    12,    13,    14,    15,    -1,    17,    -1,    -1,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,     5,     6,    36,
      37,    38,    39,    40,    41,    -1,    14,    -1,    16,    -1,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,     5,
       6,    29,    -1,    31,    -1,    -1,    34,    35,    14,    -1,
      16,    -1,    18,    19,    20,    -1,    -1,    23,    -1,    -1,
      -1,     5,     6,    29,    -1,    31,    -1,    -1,    34,    35,
      14,    -1,    16,    -1,    18,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,     5,     6,    29,    -1,    31,    -1,    -1,
      34,    35,    14,    -1,    16,    -1,    18,    19,    20,    -1,
      -1,    23,    -1,    -1,    -1,     5,     6,    29,    -1,    31,
      -1,    -1,    34,    35,    14,    -1,    16,    -1,    18,    19,
      20,    -1,    -1,    23,    -1,    -1,    -1,     5,     6,    29,
      -1,    31,    -1,    -1,    34,    35,    14,    -1,    16,    -1,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,     5,
       6,    29,    -1,    31,    -1,    -1,    34,    35,    14,    -1,
      16,    -1,    18,    19,    20,    -1,    -1,    23,    -1,    -1,
      -1,     5,     6,    29,    -1,    31,    -1,    -1,    34,    35,
      14,    -1,    16,    -1,    18,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,     5,     6,    29,    -1,    31,    -1,    -1,
      34,    35,    14,    -1,    16,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      -1,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    30,    51,    52,    61,    48,    22,     0,    24,
      25,    59,    60,    61,    66,    49,    53,    54,    66,    60,
      61,    16,    22,    23,    54,    14,    16,    55,    56,    57,
      48,    10,    16,    46,    48,     8,    45,    49,    58,    66,
      62,    63,    66,     7,    49,    58,    56,    22,    45,    49,
      16,    11,    63,    14,    16,    64,    65,    47,    49,    10,
      66,    22,     5,     6,    14,    16,    18,    19,    20,    29,
      31,    34,    35,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    82,    83,    16,    46,
       8,    45,    46,    62,    16,    10,    48,    48,    16,    46,
      48,    22,     8,     8,     3,     7,    44,    48,    80,    82,
      83,    48,    48,    22,    23,    68,     8,     9,     7,    65,
       7,    11,    62,    16,    83,    80,    80,    80,    81,    67,
      80,    80,     8,    12,    13,    14,    15,    17,    36,    37,
      38,    39,    40,    41,    42,    43,    80,    80,    67,     4,
      80,    47,    47,    67,    11,    49,    49,    47,    45,    49,
      23,    49,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    49,    49,    23,    83,     8,
      46,    23,    67,     8,     8,    46,    80,    21,    22,    22,
      34,     8,     7,    23,    80,    48,    67,    67,    48,    47,
      47,    80,    23,    23,    80,    49,    33,    49,     8,    22,
       8,    67,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 87 "parser.y"
    {
		printf("Parsing Complete\n");
		fclose(target_file);
	}
    break;

  case 3:
#line 93 "parser.y"
    {
		printf("Parsing Complete\n");
		fclose(target_file);
	}
    break;

  case 4:
#line 98 "parser.y"
    {
		printf("test");
		printf("Parsing Complete\n");		
		fclose(target_file);
	}
    break;

  case 5:
#line 105 "parser.y"
    {
	printf("test");
	(yyval.Symbol)=(yyvsp[(3) - (4)].Symbol);
	gst = ( struct gSymbolTable* ) malloc(sizeof(struct gSymbolTable));
    gst->head = (yyvsp[(3) - (4)].Symbol);
    assignbinding(gst,gm);
	printglobalsymboltable(gst);
	if (findduplicate(gst))
	{
		yyerror("Duplicate Declaration\n");
		exit(1);
	}
    target_file = fopen("ASSEMBLYCODE.xsm", "w");
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", 4095);
    fprintf(target_file, "MOV BP, %d\n", 4096);
    fprintf(target_file, "PUSH R0\n");
     while( gm-- > 4096){
        fprintf(target_file, "PUSH R0\n");
    }


    fprintf(target_file, "CALL MAIN\n");


    fprintf(target_file, "MOV R0,\"Exit\"\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL 0\n");
}
    break;

  case 6:
#line 140 "parser.y"
    {
		(yyval.Symbol) = joinnode((yyvsp[(1) - (2)].Symbol),(yyvsp[(2) - (2)].Symbol));
	}
    break;

  case 7:
#line 144 "parser.y"
    {
		(yyval.Symbol) = (yyvsp[(1) - (1)].Symbol);
	}
    break;

  case 8:
#line 149 "parser.y"
    {
	struct Gsymbol* temp=(yyvsp[(2) - (3)].Symbol);
	while(temp!=NULL)
	{
		temp->type=(yyvsp[(1) - (3)].number);
		temp=temp->next;
	}
	(yyval.Symbol)=(yyvsp[(2) - (3)].Symbol);
}
    break;

  case 9:
#line 160 "parser.y"
    {
		(yyval.Symbol)=joinnode((yyvsp[(1) - (3)].Symbol),(yyvsp[(3) - (3)].Symbol));
	}
    break;

  case 10:
#line 164 "parser.y"
    {
		(yyval.Symbol) = (yyvsp[(1) - (1)].Symbol);
	}
    break;

  case 11:
#line 170 "parser.y"
    {
		(yyval.Symbol)=createsymbolnode(gst,(yyvsp[(1) - (1)].name),INVALIDTYPE,1,1,-1,NULL,NULL,-1);
	}
    break;

  case 12:
#line 174 "parser.y"
    {
		(yyval.Symbol)=createsymbolnode(gst,(yyvsp[(1) - (4)].name),INVALIDTYPE,(yyvsp[(3) - (4)].number),(yyvsp[(3) - (4)].number),-1,NULL,NULL,-1);
	}
    break;

  case 13:
#line 178 "parser.y"
    {
		(yyval.Symbol) = createsymbolnode(gst,(yyvsp[(1) - (7)].name),INVALIDTYPE,((yyvsp[(3) - (7)].number)*(yyvsp[(6) - (7)].number)),(yyvsp[(3) - (7)].number),-1,NULL,NULL,-1);
	}
    break;

  case 14:
#line 182 "parser.y"
    {
		(yyval.Symbol)=createsymbolnode(gst,(yyvsp[(2) - (2)].name),INVALIDTYPE,1,0,-1,NULL,NULL,-1);
	}
    break;

  case 15:
#line 186 "parser.y"
    {
		(yyval.Symbol)=(yyvsp[(1) - (1)].Symbol);
	}
    break;

  case 16:
#line 192 "parser.y"
    {
	(yyval.Symbol)=createsymbolnode(gst,(yyvsp[(1) - (4)].name),INVALIDTYPE,0,0,-1,(yyvsp[(3) - (4)].paramlist),NULL,flabel++);
}
    break;

  case 17:
#line 196 "parser.y"
    {
	(yyval.Symbol)=createsymbolnode(gst,(yyvsp[(1) - (3)].name),INVALIDTYPE,0,0,-1,NULL,NULL,flabel++);
}
    break;

  case 18:
#line 203 "parser.y"
    {
	(yyval.paramlist)=joinparamnode((yyvsp[(1) - (4)].paramlist),createparamnode((yyvsp[(4) - (4)].name),(yyvsp[(3) - (4)].number),1,1));
}
    break;

  case 19:
#line 207 "parser.y"
    {
	(yyval.paramlist)=createparamnode((yyvsp[(2) - (2)].name),(yyvsp[(1) - (2)].number),1,1);
}
    break;

  case 20:
#line 213 "parser.y"
    {
		(yyval.Symbol)=(yyvsp[(1) - (2)].Symbol);
	}
    break;

  case 21:
#line 217 "parser.y"
    {
		(yyval.Symbol)=(yyvsp[(1) - (1)].Symbol);
	}
    break;

  case 22:
#line 222 "parser.y"
    {
	printf("test");
	struct Gsymbol *temp = lookup(gst,(yyvsp[(2) - (11)].name));
	temp->paramlist=(yyvsp[(4) - (11)].paramlist);
	struct lSymbolTable *lst = (struct lSymbolTable*)malloc(sizeof(struct lSymbolTable));
	lst->head=(yyvsp[(8) - (11)].Lsymbol);
	printlocalsymboltable(lst);
	temp->lsth=lst->head;
	temp->flabel=flabel;
	fprintf(target_file, "F%d:\n ",flabel);
	flabel++;
	(yyval.Symbol)=NULL;
	if(temp==NULL)
	{
		printf("Function %s not declared\n",(yyvsp[(2) - (11)].name));
		exit(1);
	}
	else
	{

		if(temp->type!=(yyvsp[(1) - (11)].number))
			{
				printf("Function %s return type mismatch\n",(yyvsp[(2) - (11)].name));
				exit(1);
			}
			else
			{
				if(temp->paramlist==NULL && (yyvsp[(4) - (11)].paramlist)==NULL)
				{
					addargtolst(temp->lsth,temp->paramlist);
					//create activation record
                    fprintf(target_file , "PUSH BP\n");
                    fprintf(target_file , "MOV BP, SP\n");
                    //push reg on stack for lst
					temp = (yyvsp[(8) - (11)].Lsymbol);
					while(temp!=NULL)
					{
						fprintf(target_file, "PUSH R0\n");
						temp=temp->next;
					}
					codeGen((yyvsp[(10) - (11)].no),target_file,lst);
                    //pop reg for lst
					temp = (yyvsp[(8) - (11)].Lsymbol);
					while(temp!=NULL)
					{
						fprintf(target_file, "POP R0\n");
						temp=temp->next;
					}
					fprintf(target_file, "MOV BP, [SP]\n");
                    fprintf(target_file, "POP R0\n");
                    fprintf(target_file, "RET\n");
                    free((yyvsp[(8) - (11)].Lsymbol));
				}
				else if(temp->paramlist==NULL && (yyvsp[(4) - (11)].paramlist)!=NULL)
				{
					printf("Function %s parameter mismatch\n",(yyvsp[(2) - (11)].name));
					exit(1);
				}
				else if(temp->paramlist!=NULL && (yyvsp[(4) - (11)].paramlist)==NULL)
				{
					printf("Function %s parameter mismatch\n",(yyvsp[(2) - (11)].name));
					exit(1);
				}
				else
				{
					struct paramstruct *temp1 = temp->paramlist;
					struct Lsymbol *temp2 = (yyvsp[(4) - (11)].paramlist);
					while(temp1!=NULL && temp2!=NULL)
					{
						if(temp1->type!=temp2->type)
						{
							printf("Function %s parameter mismatch\n",(yyvsp[(2) - (11)].name));
							exit(1);
						}
						temp1=temp1->next;
						temp2=temp2->next;
					}
					if(temp1!=NULL || temp2!=NULL)
					{
						printf("Function %s parameter mismatch\n",(yyvsp[(2) - (11)].name));
						exit(1);
					}
					else
					{
						addargtolst(lst,temp->paramlist);
						//create activation record
                    	fprintf(target_file , "PUSH BP\n");
                    	fprintf(target_file , "MOV BP, SP\n");
                    	//push reg on stack for lst
						temp = (yyvsp[(8) - (11)].Lsymbol);
						while(temp!=NULL)
						{
							fprintf(target_file, "PUSH R0\n");
							temp=temp->next;
						}
						assignbindinglocal(lst);
						codeGen((yyvsp[(10) - (11)].no),target_file,lst);
                    	//pop reg for lst
						temp = (yyvsp[(8) - (11)].Lsymbol);
						while(temp!=NULL)
						{
							fprintf(target_file, "POP R0\n");
							temp=temp->next;
						}
						fprintf(target_file, "MOV BP, [SP]\n");
                    	fprintf(target_file, "POP R0\n");
                    	fprintf(target_file, "RET\n");
                    	freelst((yyvsp[(8) - (11)].Lsymbol));
					}
				}
			}
		}
	}
    break;

  case 23:
#line 337 "parser.y"
    {
	struct Gsymbol *temp = lookup(gst,(yyvsp[(2) - (10)].name));
	temp->paramlist=NULL;
	struct lSymbolTable *lst = (struct lSymbolTable*)malloc(sizeof(struct lSymbolTable));
	lst->head=(yyvsp[(7) - (10)].Lsymbol);
	printlocalsymboltable(lst);
	temp->lsth=lst->head;
	temp->flabel=flabel;
	fprintf(target_file, "F%d:\n ",flabel);
	flabel++;
	(yyval.Symbol)=NULL;
	if(temp==NULL)
	{
		printf("Function %s not declared\n",(yyvsp[(2) - (10)].name));
		exit(1);
	}
	else
	{

		if(temp->type!=(yyvsp[(1) - (10)].number))
			{
				printf("Function %s return type mismatch\n",(yyvsp[(2) - (10)].name));
				exit(1);
			}
			else
			{
				if(temp->paramlist==NULL)
				{
					addargtolst(temp->lsth,temp->paramlist);
					//create activation record
                    fprintf(target_file , "PUSH BP\n");
                    fprintf(target_file , "MOV BP, SP\n");
                    //push reg on stack for lst
					temp = (yyvsp[(7) - (10)].Lsymbol);
					while(temp!=NULL)
					{
						fprintf(target_file, "PUSH R0\n");
						temp=temp->next;
					}
					codeGen((yyvsp[(9) - (10)].no),target_file,lst);
                    //pop reg for lst
					temp = (yyvsp[(7) - (10)].Lsymbol);
					while(temp!=NULL)
					{
						fprintf(target_file, "POP R0\n");
						temp=temp->next;
					}
					fprintf(target_file, "MOV BP, [SP]\n");
                    fprintf(target_file, "POP R0\n");
                    fprintf(target_file, "RET\n");
                    free((yyvsp[(7) - (10)].Lsymbol));
				}
				else
				{
					printf("Function %s parameter mismatch\n",(yyvsp[(2) - (10)].name));
					exit(1);
				}
			}
	}
				
}
    break;

  case 24:
#line 400 "parser.y"
    {
	check();
	if(gst==NULL)
	{
		target_file = fopen("ASSEMBLYCODE.xsm", "w");
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", 4095);
    fprintf(target_file, "MOV BP, %d\n", 4096);
    fprintf(target_file, "PUSH R0\n");
     while( gm-- > 4096){
        fprintf(target_file, "PUSH R0\n");
    }


    fprintf(target_file, "CALL MAIN\n");


    fprintf(target_file, "MOV R0,\"Exit\"\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL 0\n");
	}
	
	if(target_file==NULL)	
	{
		target_file = fopen("ASSEMBLYCODE.xsm", "a");
	}
    int cb = 1;
	struct lSymbolTable *lst = (struct lSymbolTable*)malloc(sizeof(struct lSymbolTable));
	lst->head=(yyvsp[(6) - (9)].Lsymbol);
	printlocalsymboltable(lst);
    struct Lsymbol* temp1 = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	temp1 = (yyvsp[(6) - (9)].Lsymbol);
	if (temp1 == NULL){
		cb = 1;
	}
	else{
    while (temp1!=NULL){
		if(temp1->binding==0)
			break;
        temp1 = temp1->next;
    }
    while (temp1 != NULL){
        temp1->binding = cb;
        cb += 1;
        temp1 = temp1->next;
    }
	}
	fprintf(target_file,  "MAIN:\n");
    fprintf(target_file , "PUSH BP\n");
    fprintf(target_file , "MOV BP, SP\n");
	temp1=(yyvsp[(8) - (9)].no);
    while (temp1 != NULL)
    {
        fprintf(target_file, "PUSH R0\n");
        temp1 = temp1->next;
    }
    codeGen((yyvsp[(8) - (9)].no),target_file,lst);
    temp1 = lst->head;
    while (temp1 != NULL)
    {
        fprintf(target_file, "POP R0\n");
        temp1 = temp1->next;
    }

    fprintf(target_file, "MOV BP, [SP]\n");
    fprintf(target_file, "POP R0\n");
	fprintf(target_file, "RET\n");
    freelst(lst);
}
    break;

  case 25:
#line 477 "parser.y"
    {
		struct Lsymbol *temp = (yyvsp[(1) - (2)].Lsymbol);
		(yyval.Lsymbol) = joinnodel((yyvsp[(1) - (2)].Lsymbol),(yyvsp[(2) - (2)].Lsymbol));
	}
    break;

  case 26:
#line 482 "parser.y"
    {
		(yyval.Lsymbol) = (yyvsp[(1) - (1)].Lsymbol);
	}
    break;

  case 27:
#line 488 "parser.y"
    {
		printf("test");
		struct Lsymbol* temp = (yyvsp[(2) - (3)].Lsymbol);
        while(temp!=NULL)
		{
            temp->type = (yyvsp[(1) - (3)].number);
            temp = temp->next;
        }
		(yyval.Lsymbol) = (yyvsp[(2) - (3)].Lsymbol);
	}
    break;

  case 28:
#line 500 "parser.y"
    {
		printf("test");
		(yyval.Lsymbol)=joinnodel((yyvsp[(1) - (3)].Lsymbol),(yyvsp[(3) - (3)].Lsymbol));
	}
    break;

  case 29:
#line 505 "parser.y"
    {
		printf("test");
		(yyval.Lsymbol)=(yyvsp[(1) - (1)].Lsymbol);
	}
    break;

  case 30:
#line 511 "parser.y"
    {
		printf("test");
		(yyval.Lsymbol)=createlocalsymbolnode((yyvsp[(1) - (1)].name),INVALIDTYPE,1,1,0);
	}
    break;

  case 31:
#line 516 "parser.y"
    {
		(yyval.Lsymbol)=createlocalsymbolnode((yyvsp[(1) - (4)].name),INVALIDTYPE,(yyvsp[(3) - (4)].number),(yyvsp[(3) - (4)].number),0);
	}
    break;

  case 32:
#line 520 "parser.y"
    {
		(yyval.Lsymbol) = createlocalsymbolnode((yyvsp[(1) - (7)].name),INVALIDTYPE,((yyvsp[(3) - (7)].number)*(yyvsp[(6) - (7)].number)),(yyvsp[(3) - (7)].number),0);
	}
    break;

  case 33:
#line 524 "parser.y"
    {
		(yyval.Lsymbol)=createlocalsymbolnode((yyvsp[(2) - (2)].name),INVALIDTYPE,1,0,0);
	}
    break;

  case 34:
#line 530 "parser.y"
    {
	(yyval.number) = INTTYPE;
}
    break;

  case 35:
#line 534 "parser.y"
    {
	(yyval.number) = STRTYPE;
}
    break;

  case 36:
#line 542 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,(yyvsp[(1) - (2)].no),(yyvsp[(2) - (2)].no));
	}
    break;

  case 37:
#line 546 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 38:
#line 555 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 39:
#line 559 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 40:
#line 563 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 41:
#line 567 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 42:
#line 571 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 43:
#line 575 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 44:
#line 579 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 45:
#line 583 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 46:
#line 587 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 47:
#line 591 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 48:
#line 595 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (2)].no);
	}
    break;

  case 49:
#line 599 "parser.y"
    {
		(yyval.no) = (yyvsp[(1) - (1)].no);
	}
    break;

  case 50:
#line 605 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,READNODE,(yyvsp[(3) - (5)].no),NULL);
	}
    break;

  case 51:
#line 611 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,WRITENODE,(yyvsp[(3) - (5)].no),NULL);
	}
    break;

  case 52:
#line 617 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,ASSIGNNODE,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no));
	}
    break;

  case 53:
#line 621 "parser.y"
    {
		struct tnode *temp = createTree(-1, INVALIDTYPE, NULL, ADDRNODE, (yyvsp[(4) - (5)].no),NULL);
            (yyval.no) = createTree(-1, INVALIDTYPE, NULL, ASSIGNNODE, (yyvsp[(1) - (5)].no),temp);
	}
    break;

  case 54:
#line 628 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,IFNODE,(yyvsp[(3) - (7)].no),(yyvsp[(6) - (7)].no));
	}
    break;

  case 55:
#line 634 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,IFELSENODE,(yyvsp[(3) - (11)].no),createTree(-1,INVALIDTYPE,NULL,CONNECTORNODE,(yyvsp[(6) - (11)].no),(yyvsp[(10) - (11)].no)));
	}
    break;

  case 56:
#line 639 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,WHILENODE,(yyvsp[(3) - (7)].no),(yyvsp[(6) - (7)].no));
	}
    break;

  case 57:
#line 644 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,DOWHILENODE,(yyvsp[(7) - (9)].no),(yyvsp[(3) - (9)].no));
	}
    break;

  case 58:
#line 649 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,BREAKNODE,NULL,NULL);
	}
    break;

  case 59:
#line 654 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,CONTINUENODE,NULL,NULL);
	}
    break;

  case 60:
#line 659 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,REPEATUNTILNODE,(yyvsp[(7) - (9)].no),(yyvsp[(3) - (9)].no));
	}
    break;

  case 61:
#line 664 "parser.y"
    {
		(yyval.no) = createTree(-1,INVALIDTYPE,NULL,RETNODE,(yyvsp[(2) - (3)].no),NULL);
	}
    break;

  case 62:
#line 670 "parser.y"
    {(yyval.no) = createTree(-1,INTTYPE,"+",MATHOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 63:
#line 671 "parser.y"
    {(yyval.no) = createTree(-1,INTTYPE,"-",MATHOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 64:
#line 672 "parser.y"
    {(yyval.no) = createTree(-1,INTTYPE,"*",MATHOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 65:
#line 673 "parser.y"
    {(yyval.no) = createTree(-1,INTTYPE,"/",MATHOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 66:
#line 674 "parser.y"
    {(yyval.no) = createTree(-1,INTTYPE,"M",MATHOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 67:
#line 675 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"<",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 68:
#line 676 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,">",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 69:
#line 677 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"<=",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 70:
#line 678 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,">=",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 71:
#line 679 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"==",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 72:
#line 680 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"!=",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 73:
#line 681 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"&&",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 74:
#line 682 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"||",LOGICOPNODE,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no));}
    break;

  case 75:
#line 683 "parser.y"
    {(yyval.no) = createTree(-1,BOOLTYPE,"!",LOGICOPNODE,(yyvsp[(2) - (2)].no),NULL);}
    break;

  case 76:
#line 684 "parser.y"
    {(yyval.no) = (yyvsp[(2) - (3)].no);}
    break;

  case 77:
#line 685 "parser.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 78:
#line 686 "parser.y"
    {(yyval.no) = createTree((yyvsp[(1) - (1)].number), INTTYPE, NULL, NUMNODE,NULL,NULL);}
    break;

  case 79:
#line 687 "parser.y"
    {(yyval.no) = createTree(-1, STRTYPE, (yyvsp[(1) - (1)].name),STRNODE,NULL,NULL);}
    break;

  case 80:
#line 688 "parser.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 81:
#line 693 "parser.y"
    {
		check();
		(yyval.arglist)=joinargnode((yyvsp[(1) - (3)].arglist),(yyvsp[(3) - (3)].no));
	}
    break;

  case 82:
#line 698 "parser.y"
    {
		(yyval.arglist) = createargnode((yyvsp[(1) - (1)].no));
	}
    break;

  case 83:
#line 704 "parser.y"
    {
	struct tnode *temp = createTree(-1,INVALIDTYPE,(yyvsp[(1) - (4)].name),FNNODE,(yyvsp[(3) - (4)].arglist),NULL);
	temp->paramlist=lookup(gst,temp->varname)->paramlist;
	temp->arglist=(yyvsp[(3) - (4)].arglist);
	check();
	if(checkargissameasparam(temp)==0)
	{
		yyerror("Arguments do not match with parameters");
		exit(1);
	}
	(yyval.no)=temp;
}
    break;

  case 84:
#line 718 "parser.y"
    {
		struct tnode* temp =createTree(-1,INVALIDTYPE,(yyvsp[(1) - (1)].name),VARNODE,NULL,NULL);
		//temp->type=findtype(gst,temp->varname);
		(yyval.no)=temp;
	}
    break;

  case 85:
#line 724 "parser.y"
    {
		struct tnode* temp =createTree(-1,INVALIDTYPE,(yyvsp[(1) - (4)].name),VARNODE,(yyvsp[(3) - (4)].no),NULL);
		temp->type=findtype(gst,temp->varname);
		if((yyvsp[(3) - (4)].no)->nodetype==NUMNODE && temp->Gentry->size<=evaluate((yyvsp[(3) - (4)].no)))
		{
			yyerror("Array index out of bounds");
			exit(1);
		}
		(yyval.no)=temp;
	}
    break;

  case 86:
#line 736 "parser.y"
    { 
		struct tnode* temp = createTree(-1, INVALIDTYPE, (yyvsp[(1) - (7)].name),VARNODE,(yyvsp[(3) - (7)].no),(yyvsp[(6) - (7)].no));
        findtype(gst,temp);
        if(temp->Gentry->size <= (evaluate((yyvsp[(3) - (7)].no))*evaluate((yyvsp[(6) - (7)].no)))) 
			yyerror("Array index out of bounds"); // need to check for out of bounds
		printf("temp :%s",temp->varname);
    	(yyval.no) = temp;
	}
    break;

  case 87:
#line 746 "parser.y"
    {
		struct tnode* temp =createTree(-1,INVALIDTYPE,(yyvsp[(2) - (2)].name),VARNODE,NULL,NULL);
		temp->type=findtype(gst,temp->varname);
		struct tnode* temp1 =createTree(-1,temp->type,NULL,PTRNODE,temp,NULL);
		(yyval.no)=temp1;
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2574 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 753 "parser.y"


yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc, char* argv[]) 
{
	if(argc > 1)
 	{
  		FILE *target_file = fopen(argv[1], "r");
  		if(target_file)
   			yyin = target_file;
 	}
	yyparse();
	return 0;
}
