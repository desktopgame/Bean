
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"

#include <stdio.h>
#include <stdlib.h>
#include "assign_type.h"
#include "ast.h"
#include "constructor_chain_type.h"
#include "modifier_type.h"
#include "yyinterface.h"
#define YYDEBUG 1
#define YYERROR_VERBOSE 1


/* Line 189 of yacc.c  */
#line 86 "bean.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SHORT = 258,
     INT = 259,
     LONG = 260,
     FLOAT = 261,
     DOUBLE = 262,
     CHAR_LITERAL = 263,
     STRING_LITERAL = 264,
     IDENT = 265,
     ADD = 266,
     SUB = 267,
     MUL = 268,
     DIV = 269,
     MOD = 270,
     AND = 271,
     ANDAND = 272,
     EQUAL = 273,
     NOTEQUAL = 274,
     BIGGEST = 275,
     EBIGGEST = 276,
     SMALLEST = 277,
     ESMALLEST = 278,
     NOT = 279,
     DOT = 280,
     COMMA = 281,
     N_ASSIGN_T = 282,
     ADD_ASSIGN_T = 283,
     SUB_ASSIGN_T = 284,
     MUL_ASSIGN_T = 285,
     DIV_ASSIGN_T = 286,
     MOD_ASSIGN_T = 287,
     VAR = 288,
     INC = 289,
     DEC = 290,
     DEF = 291,
     TRUE = 292,
     FALSE = 293,
     NULL_VALUE = 294,
     SEMI = 295,
     OR = 296,
     OROR = 297,
     CR = 298,
     LCB = 299,
     RCB = 300,
     LRB = 301,
     RRB = 302,
     LSB = 303,
     RSB = 304,
     FOR = 305,
     WHILE = 306,
     IF = 307,
     ELSE = 308,
     ELSEIF = 309,
     BREAK = 310,
     CONTINUE = 311,
     RETURN = 312,
     TRY = 313,
     CATCH = 314,
     FINALLY = 315,
     PUBLIC = 316,
     PRIVATE = 317,
     PROTECTED = 318,
     STATIC = 319,
     USE = 320,
     FINAL = 321,
     CLASS = 322,
     AT = 323,
     THROW = 324,
     SET = 325,
     GET = 326,
     NATIVE = 327,
     COLON = 328,
     ARROW = 329,
     THIS = 330,
     SUPER = 331,
     ENUM = 332,
     LAMBDA = 333,
     NEW = 334,
     ALIAS = 335,
     COLO_COLO = 336
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 12 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"

	char char_value;
	const char* ident_value;
	ast* ast_value;
	assign_type assign_type_value;
	modifier_type modifier_type_value;
	constructor_chain_type constructor_chain_type_value;



/* Line 214 of yacc.c  */
#line 214 "bean.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 226 "bean.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNRULES -- Number of states.  */
#define YYNSTATES  323

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   336

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      82,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    13,    15,    17,    19,
      21,    23,    27,    33,    35,    39,    46,    47,    50,    56,
      58,    62,    66,    68,    69,    71,    74,    76,    78,    80,
      89,    97,   103,   108,   110,   112,   113,   115,   123,   130,
     138,   143,   151,   159,   163,   167,   171,   173,   174,   178,
     180,   184,   185,   187,   189,   191,   193,   195,   197,   199,
     203,   205,   209,   211,   214,   216,   218,   222,   224,   226,
     228,   230,   232,   234,   236,   240,   244,   246,   250,   254,
     256,   260,   264,   266,   270,   274,   278,   282,   284,   288,
     292,   294,   298,   302,   306,   308,   311,   314,   316,   319,
     322,   324,   328,   334,   341,   347,   354,   357,   360,   362,
     364,   367,   371,   375,   377,   381,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     419,   425,   428,   430,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   456,   464,   471,   480,   482,   485,
     491,   501,   503,   512,   518,   528,   533,   541,   544,   547,
     550,   554,   558,   564,   571,   580,   581,   583,   587,   590,
     592
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      84,     0,    -1,    85,    -1,    84,    85,    -1,     1,    82,
      -1,    86,    -1,    87,    -1,    89,    -1,   100,    -1,    91,
      -1,   126,    -1,    65,    88,    40,    -1,    80,    10,    27,
      88,    40,    -1,    10,    -1,    88,    25,    10,    -1,    67,
      10,    90,    44,    94,    45,    -1,    -1,    73,    10,    -1,
      77,    10,    44,    92,    45,    -1,    93,    -1,    92,    26,
      93,    -1,    10,    27,   110,    -1,    10,    -1,    -1,    95,
      -1,    94,    95,    -1,    96,    -1,   100,    -1,   101,    -1,
     104,    36,    79,    46,   108,    47,    99,   143,    -1,   104,
      36,    79,    46,    47,    99,   143,    -1,    73,    98,    46,
     107,    47,    -1,    73,    98,    46,    47,    -1,    76,    -1,
      75,    -1,    -1,    97,    -1,   104,    36,    10,    46,   108,
      47,   143,    -1,   104,    36,    10,    46,    47,   143,    -1,
     104,    68,    10,    46,   102,    47,   103,    -1,   104,    68,
      10,   103,    -1,    71,    27,    10,    26,    70,    27,    10,
      -1,    70,    27,    10,    26,    71,    27,    10,    -1,    70,
      27,    10,    -1,    71,    27,    10,    -1,    27,   110,    40,
      -1,    40,    -1,    -1,    48,   105,    49,    -1,   106,    -1,
     105,    41,   106,    -1,    -1,    61,    -1,    62,    -1,    63,
      -1,    64,    -1,    66,    -1,    72,    -1,   110,    -1,   110,
      26,   107,    -1,    10,    -1,    10,    26,   108,    -1,   126,
      -1,   109,   126,    -1,   111,    -1,   113,    -1,   113,   112,
     111,    -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,
      31,    -1,    32,    -1,   114,    -1,   113,    41,   114,    -1,
     113,    42,   114,    -1,   115,    -1,   114,    16,   115,    -1,
     114,    17,   115,    -1,   116,    -1,   115,    18,   116,    -1,
     115,    19,   116,    -1,   117,    -1,   116,    20,   117,    -1,
     116,    21,   117,    -1,   116,    22,   117,    -1,   116,    23,
     117,    -1,   118,    -1,   117,    11,   118,    -1,   117,    12,
     118,    -1,   119,    -1,   118,    13,   119,    -1,   118,    14,
     119,    -1,   118,    15,   119,    -1,   120,    -1,    24,   119,
      -1,    12,   119,    -1,   121,    -1,    34,   121,    -1,    35,
     121,    -1,   122,    -1,   121,    25,    10,    -1,   121,    25,
      79,    46,    47,    -1,   121,    25,    79,    46,   107,    47,
      -1,   121,    25,    10,    46,    47,    -1,   121,    25,    10,
      46,   107,    47,    -1,   121,    34,    -1,   121,    35,    -1,
     124,    -1,   123,    -1,    44,    45,    -1,    44,   107,    45,
      -1,    46,   110,    47,    -1,    10,    -1,    10,    46,    47,
      -1,    10,    46,   107,    47,    -1,    37,    -1,    38,    -1,
      39,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
       7,    -1,     8,    -1,     9,    -1,    75,    -1,    76,    -1,
     125,    -1,    78,    46,   108,    47,    74,   142,    -1,    78,
      46,    47,    74,   142,    -1,   110,    40,    -1,   127,    -1,
     130,    -1,   132,    -1,   133,    -1,   134,    -1,   135,    -1,
     136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,
      52,    46,   110,    47,   142,    -1,    52,    46,   110,    47,
     142,    53,   142,    -1,    52,    46,   110,    47,   142,   128,
      -1,    52,    46,   110,    47,   142,   128,    53,   142,    -1,
     129,    -1,   128,   129,    -1,    54,    46,   110,    47,   142,
      -1,    50,    46,   141,    40,   141,    40,   141,    47,   142,
      -1,   131,    -1,    50,    46,   138,   141,    40,   141,    47,
     142,    -1,    51,    46,   110,    47,   142,    -1,    58,   142,
      59,    46,    10,    47,   142,    60,   142,    -1,    58,   142,
      60,   142,    -1,    58,   142,    59,    46,    10,    47,   142,
      -1,    55,    40,    -1,    56,    40,    -1,    57,    40,    -1,
      57,   110,    40,    -1,    69,   110,    40,    -1,    33,    10,
      27,   110,    40,    -1,   110,    81,    10,    27,   110,    40,
      -1,   110,    81,    10,    46,    47,    27,   125,    40,    -1,
      -1,   110,    -1,    44,   109,    45,    -1,    44,    45,    -1,
      40,    -1,   142,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    87,    88,    94,    98,   102,   106,   110,
     114,   120,   126,   132,   136,   142,   149,   152,   158,   164,
     168,   174,   178,   185,   188,   192,   198,   199,   200,   203,
     207,   213,   217,   223,   227,   234,   237,   240,   244,   250,
     254,   260,   264,   268,   272,   278,   282,   289,   292,   298,
     302,   309,   312,   316,   320,   324,   328,   332,   338,   342,
     348,   352,   358,   362,   368,   371,   372,   378,   382,   386,
     390,   394,   398,   404,   405,   409,   415,   416,   420,   426,
     427,   431,   437,   438,   442,   446,   450,   456,   457,   461,
     467,   468,   472,   476,   482,   483,   487,   493,   494,   498,
     504,   505,   509,   513,   517,   521,   525,   529,   535,   536,
     539,   543,   549,   553,   557,   561,   565,   569,   573,   577,
     578,   579,   580,   581,   582,   583,   584,   588,   592,   595,
     599,   605,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   622,   626,   630,   634,   640,   641,   647,
     653,   657,   660,   666,   672,   676,   680,   686,   692,   698,
     702,   708,   714,   720,   726,   733,   736,   739,   743,   749,
     753
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SHORT", "INT", "LONG", "FLOAT",
  "DOUBLE", "CHAR_LITERAL", "STRING_LITERAL", "IDENT", "ADD", "SUB", "MUL",
  "DIV", "MOD", "AND", "ANDAND", "EQUAL", "NOTEQUAL", "BIGGEST",
  "EBIGGEST", "SMALLEST", "ESMALLEST", "NOT", "DOT", "COMMA", "N_ASSIGN_T",
  "ADD_ASSIGN_T", "SUB_ASSIGN_T", "MUL_ASSIGN_T", "DIV_ASSIGN_T",
  "MOD_ASSIGN_T", "VAR", "INC", "DEC", "DEF", "TRUE", "FALSE",
  "NULL_VALUE", "SEMI", "OR", "OROR", "CR", "LCB", "RCB", "LRB", "RRB",
  "LSB", "RSB", "FOR", "WHILE", "IF", "ELSE", "ELSEIF", "BREAK",
  "CONTINUE", "RETURN", "TRY", "CATCH", "FINALLY", "PUBLIC", "PRIVATE",
  "PROTECTED", "STATIC", "USE", "FINAL", "CLASS", "AT", "THROW", "SET",
  "GET", "NATIVE", "COLON", "ARROW", "THIS", "SUPER", "ENUM", "LAMBDA",
  "NEW", "ALIAS", "COLO_COLO", "'\\n'", "$accept", "root", "top_level",
  "include", "alias_T", "namespace", "class_define", "class_super",
  "enum_define", "enum_item_list", "enum_item_define",
  "member_define_list", "member_define", "constructor_define",
  "constructor_chain", "constructor_chain_type_T",
  "constructor_chain_optional", "func_define", "field_define",
  "field_set_get", "field_default_value", "modifier_define",
  "modifier_list", "modifier_type_T", "argument_list", "parameter_list",
  "stmt_list", "expression", "assignExpr", "assign_type", "or", "and",
  "equal", "compare", "addsub", "muldiv", "unary", "prefix", "postfix",
  "primary_expression", "new_array", "primary_no_new_array", "lambda",
  "stmt", "if_stmt", "elsif_list", "elsif", "for_stmt", "for_stmt_fixed",
  "while_stmt", "try_stmt", "break_stmt", "continue_stmt", "return_stmt",
  "throw_stmt", "variable_define", "dyn_field_define", "dyn_method_define",
  "expression_optional", "block", "block_optional", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    84,    84,    85,    85,    85,    85,    85,
      85,    86,    87,    88,    88,    89,    90,    90,    91,    92,
      92,    93,    93,    94,    94,    94,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   115,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     118,   118,   118,   118,   119,   119,   119,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   127,   128,   128,   129,
     130,   130,   131,   132,   133,   133,   133,   134,   135,   136,
     136,   137,   138,   139,   140,   141,   141,   142,   142,   143,
     143
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     3,     6,     0,     2,     5,     1,
       3,     3,     1,     0,     1,     2,     1,     1,     1,     8,
       7,     5,     4,     1,     1,     0,     1,     7,     6,     7,
       4,     7,     7,     3,     3,     3,     1,     0,     3,     1,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     1,     2,     2,
       1,     3,     5,     6,     5,     6,     2,     2,     1,     1,
       2,     3,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     7,     6,     8,     1,     2,     5,
       9,     1,     8,     5,     9,     4,     7,     2,     2,     2,
       3,     3,     5,     6,     8,     0,     1,     3,     2,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   119,   120,   121,   122,   123,   124,   125,   113,
       0,     0,     0,     0,     0,   116,   117,   118,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,    47,     2,     5,     6,
       7,     9,     8,     0,     0,    64,    65,    73,    76,    79,
      82,    87,    90,    94,    97,   100,   109,   108,   128,    10,
     132,   133,   151,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     4,     0,    96,    95,     0,    98,    99,   110,
       0,    58,     0,    52,    53,    54,    55,    56,    57,     0,
      49,   165,     0,     0,   157,   158,   159,     0,     0,     0,
      13,     0,    16,     0,     0,     0,     0,     1,     3,     0,
     131,     0,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   114,     0,     0,
     111,     0,   112,    51,    48,   166,   165,     0,     0,     0,
     160,   168,     0,    62,     0,     0,     0,    11,     0,     0,
     161,     0,    60,     0,     0,     0,     0,     0,    74,    75,
      66,    77,    78,    80,    81,    83,    84,    85,    86,    88,
      89,    91,    92,    93,   101,     0,   115,     0,    59,    50,
       0,   165,     0,     0,   167,    63,     0,   155,    14,    17,
      23,    22,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   165,     0,   153,   143,     0,    47,
      24,    26,    27,    28,     0,     0,     0,    18,    61,   130,
       0,    12,     0,     0,     0,     0,   104,     0,   102,     0,
       0,   165,     0,     0,   145,   147,     0,    15,    25,     0,
       0,    21,    20,   129,   169,   170,    38,     0,   163,     0,
     105,   103,     0,     0,   144,     0,     0,   148,   156,     0,
       0,    37,     0,   152,     0,     0,   146,     0,     0,     0,
      46,     0,    40,   164,   150,     0,   154,    35,     0,     0,
       0,     0,     0,   149,     0,    36,     0,    35,    45,     0,
       0,     0,    34,    33,     0,    30,     0,    43,    44,    39,
       0,    29,     0,     0,    32,     0,     0,     0,    31,     0,
       0,    42,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    36,    37,    38,    39,   101,    40,   159,    41,   202,
     203,   219,   220,   221,   295,   304,   296,    42,   223,   292,
     282,    43,    89,    90,    80,   164,   152,    81,    45,   120,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   244,   245,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   147,   255,
     256
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -236
static const yytype_int16 yypact[] =
{
     341,   -54,  -236,  -236,  -236,  -236,  -236,  -236,  -236,    21,
     735,   735,    23,   155,   155,  -236,  -236,  -236,   419,   735,
     123,    39,    43,    49,     9,    17,   464,    -5,    89,   125,
     735,  -236,  -236,   132,   107,   163,   263,  -236,  -236,  -236,
    -236,  -236,  -236,   142,   -13,  -236,    86,   103,   112,   149,
     136,   183,  -236,  -236,    87,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,   509,  -236,  -236,   161,    87,    87,  -236,
     131,   164,   153,  -236,  -236,  -236,  -236,  -236,  -236,   -18,
    -236,   555,   735,   735,  -236,  -236,  -236,   175,     8,   143,
    -236,    54,   144,   181,   180,    25,   199,  -236,  -236,   219,
    -236,   222,  -236,  -236,  -236,  -236,  -236,  -236,   735,   735,
     735,   735,   735,   735,   735,   735,   735,   735,   735,   735,
     735,   735,   735,   735,    -3,  -236,  -236,  -236,   195,   735,
    -236,   735,  -236,   123,  -236,  -236,   735,   203,   197,   198,
    -236,  -236,    99,  -236,   200,    -5,   237,  -236,   239,   206,
    -236,   242,   227,   182,   207,    89,   209,    -2,   103,   103,
    -236,   112,   112,   149,   149,   136,   136,   136,   136,   183,
     183,  -236,  -236,  -236,   211,   212,  -236,   220,  -236,  -236,
     221,   735,    -5,    -5,  -236,  -236,   252,  -236,  -236,  -236,
     216,   247,     3,  -236,   266,    -5,   204,    56,    27,   735,
     230,   600,   645,  -236,   735,   240,  -236,   152,   234,    42,
    -236,  -236,  -236,  -236,   -12,   735,   242,  -236,  -236,  -236,
      -5,  -236,    11,   235,   243,   257,  -236,   238,  -236,   241,
     244,   735,    -5,   246,   154,  -236,    -5,  -236,  -236,    -1,
     276,  -236,  -236,  -236,  -236,  -236,  -236,    11,  -236,   215,
    -236,  -236,    -5,   248,  -236,   735,    -5,  -236,   229,   253,
      -6,  -236,   250,  -236,    -5,   256,  -236,    -5,    28,   735,
    -236,   140,  -236,  -236,  -236,    -5,  -236,   231,   258,   254,
     279,   281,   265,  -236,   137,  -236,    11,   231,  -236,   300,
     306,    70,  -236,  -236,   271,  -236,    11,   296,   297,  -236,
     690,  -236,   255,   259,  -236,   277,   298,   304,  -236,   317,
     323,  -236,  -236
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,   299,  -236,  -236,   169,  -236,  -236,  -236,  -236,
     110,  -236,   118,  -236,  -236,  -236,    57,  -131,  -236,  -236,
      51,  -118,  -236,   213,   -71,  -198,  -236,     0,   249,  -236,
    -236,   100,   101,   104,    55,   105,    -7,  -236,   224,  -236,
    -236,  -236,    96,   -90,  -236,  -236,   113,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,   267,  -236,  -236,  -141,   -26,
    -235
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      44,    99,   138,    74,    75,   190,   228,   184,   153,   166,
     233,     2,     3,     4,     5,     6,     7,     8,     9,    82,
      10,   279,   271,   143,   249,   209,    97,   110,    72,   226,
     103,   144,    11,    76,   280,   162,    44,   162,   162,    98,
     281,    12,    13,    14,   210,    15,    16,    17,   227,    94,
     215,   254,    18,   151,    19,    98,   250,    95,    21,    22,
      23,   305,   195,    24,    25,    26,    27,    73,   111,   222,
     188,   311,   163,   240,   232,   287,   185,    30,   269,   156,
     288,   156,   224,    31,    32,    91,    34,   247,   222,    92,
      20,   145,   148,   149,   157,    93,   231,   279,    44,   100,
     263,   224,     2,     3,     4,     5,     6,     7,     8,     9,
     280,    10,   134,   112,   113,   114,   115,   116,   117,   121,
     122,   135,   136,    11,   181,   182,   183,   118,   119,   197,
     123,   124,    12,    13,    14,   102,    15,    16,    17,   187,
     237,   239,   104,    18,   194,    19,   145,   129,   130,    21,
      22,    23,    44,   105,    24,    25,    26,    27,     2,     3,
       4,     5,     6,     7,     8,     9,   216,   217,    30,   125,
     126,   127,   128,   106,    31,    32,   140,    34,   109,   229,
     175,   176,   177,   178,    83,    84,    85,    86,   139,    87,
     141,   145,    15,    16,    17,    88,   131,   132,   133,    18,
     142,    19,   154,   155,   253,   242,   243,   266,   243,   234,
     290,   291,   302,   303,   145,   150,   264,   158,   168,   169,
     268,   160,   171,   172,   161,   251,   165,   173,   174,   166,
      31,    32,   167,    34,   179,   180,   273,    77,    78,   315,
     276,   145,   186,   191,   192,   193,   196,   198,   284,   199,
     200,   286,   201,   204,   206,   208,   205,   211,   212,   293,
     213,   214,   218,   107,    20,   275,     2,     3,     4,     5,
       6,     7,     8,     9,   225,    10,   162,   235,   230,   289,
     241,   246,   257,   258,   259,   260,   270,    11,   261,   277,
     283,   262,   265,    34,   298,   274,    12,    13,    14,   278,
      15,    16,    17,   285,   294,   297,   299,    18,   300,    19,
     307,    20,   301,    21,    22,    23,   308,   310,    24,    25,
      26,    27,   312,   313,   318,   319,   316,   321,    28,   317,
      29,   320,    30,   322,   207,   108,   252,   248,    31,    32,
      33,    34,     1,    35,     2,     3,     4,     5,     6,     7,
       8,     9,   309,    10,   306,   272,   189,   267,   146,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,   170,
       0,     0,     0,     0,    12,    13,    14,   -47,    15,    16,
      17,     0,     0,     0,     0,    18,     0,    19,     0,    20,
       0,    21,    22,    23,     0,     0,    24,    25,    26,    27,
       0,     0,     0,     0,     0,     0,    28,     0,    29,     0,
      30,     0,     0,     0,     0,     0,    31,    32,    33,    34,
       0,    35,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,    15,    16,    17,     0,
       0,     0,     0,    18,    79,    19,     0,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,    31,    32,     0,    34,    13,    14,
       0,    15,    16,    17,    96,     0,     0,     0,    18,     0,
      19,     0,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,    31,
      32,     0,    34,    13,    14,     0,    15,    16,    17,     0,
       0,     0,     0,    18,     0,    19,   137,     0,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    31,    32,     0,    34,    12,    13,
      14,     0,    15,    16,    17,     0,     0,     0,     0,    18,
       0,    19,     0,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      31,    32,     0,    34,    13,    14,     0,    15,    16,    17,
       0,     0,     0,     0,    18,     0,    19,   236,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    31,    32,     0,    34,    13,
      14,     0,    15,    16,    17,     0,     0,     0,     0,    18,
       0,    19,   238,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      31,    32,     0,    34,    13,    14,     0,    15,    16,    17,
       0,     0,     0,     0,    18,     0,    19,   314,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    31,    32,     0,    34,    13,
      14,     0,    15,    16,    17,     0,     0,     0,     0,    18,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,    34
};

static const yytype_int16 yycheck[] =
{
       0,    27,    73,    10,    11,   146,   204,    10,    98,    10,
     208,     3,     4,     5,     6,     7,     8,     9,    10,    19,
      12,    27,   257,    41,    36,    27,    26,    40,    82,    26,
      30,    49,    24,    10,    40,    10,    36,    10,    10,    44,
      46,    33,    34,    35,    46,    37,    38,    39,    45,    40,
     191,    40,    44,    45,    46,    44,    68,    40,    50,    51,
      52,   296,   152,    55,    56,    57,    58,    46,    81,   200,
     141,   306,    47,   214,    47,    47,    79,    69,    79,    25,
     278,    25,   200,    75,    76,    46,    78,    45,   219,    46,
      48,    91,    92,    93,    40,    46,    40,    27,    98,    10,
     241,   219,     3,     4,     5,     6,     7,     8,     9,    10,
      40,    12,    25,    27,    28,    29,    30,    31,    32,    16,
      17,    34,    35,    24,   131,   132,   133,    41,    42,   155,
      18,    19,    33,    34,    35,    10,    37,    38,    39,   139,
     211,   212,    10,    44,    45,    46,   146,    11,    12,    50,
      51,    52,   152,    46,    55,    56,    57,    58,     3,     4,
       5,     6,     7,     8,     9,    10,   192,   193,    69,    20,
      21,    22,    23,    10,    75,    76,    45,    78,    36,   205,
     125,   126,   127,   128,    61,    62,    63,    64,    27,    66,
      26,   191,    37,    38,    39,    72,    13,    14,    15,    44,
      47,    46,    59,    60,   230,    53,    54,    53,    54,   209,
      70,    71,    75,    76,   214,    40,   242,    73,   118,   119,
     246,    40,   121,   122,    44,   225,    27,   123,   124,    10,
      75,    76,    10,    78,   129,   130,   262,    13,    14,   310,
     266,   241,    47,    40,    47,    47,    46,    10,   274,    10,
      44,   277,    10,    26,    47,    46,    74,    46,    46,   285,
      40,    40,    10,     0,    48,   265,     3,     4,     5,     6,
       7,     8,     9,    10,    27,    12,    10,    47,    74,   279,
      40,    47,    47,    40,    27,    47,    10,    24,    47,    60,
      40,    47,    46,    78,    40,    47,    33,    34,    35,    46,
      37,    38,    39,    47,    73,    47,    27,    44,    27,    46,
      10,    48,    47,    50,    51,    52,    10,    46,    55,    56,
      57,    58,    26,    26,    47,    27,    71,    10,    65,    70,
      67,    27,    69,    10,   165,    36,   226,   219,    75,    76,
      77,    78,     1,    80,     3,     4,     5,     6,     7,     8,
       9,    10,   301,    12,   297,   259,   143,   244,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    46,    -1,    48,
      -1,    50,    51,    52,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      -1,    80,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    78,    34,    35,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    44,    -1,
      46,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    78,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,    47,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    75,    76,    -1,    78,    33,    34,
      35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    78,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    46,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    78,    34,
      35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    47,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    78,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    46,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    78,    34,
      35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    24,    33,    34,    35,    37,    38,    39,    44,    46,
      48,    50,    51,    52,    55,    56,    57,    58,    65,    67,
      69,    75,    76,    77,    78,    80,    84,    85,    86,    87,
      89,    91,   100,   104,   110,   111,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    82,    46,   119,   119,    10,   121,   121,    45,
     107,   110,   110,    61,    62,    63,    64,    66,    72,   105,
     106,    46,    46,    46,    40,    40,    40,   110,    44,   142,
      10,    88,    10,   110,    10,    46,    10,     0,    85,    36,
      40,    81,    27,    28,    29,    30,    31,    32,    41,    42,
     112,    16,    17,    18,    19,    20,    21,    22,    23,    11,
      12,    13,    14,    15,    25,    34,    35,    47,   107,    27,
      45,    26,    47,    41,    49,   110,   138,   141,   110,   110,
      40,    45,   109,   126,    59,    60,    25,    40,    73,    90,
      40,    44,    10,    47,   108,    27,    10,    10,   114,   114,
     111,   115,   115,   116,   116,   117,   117,   117,   117,   118,
     118,   119,   119,   119,    10,    79,    47,   110,   107,   106,
     141,    40,    47,    47,    45,   126,    46,   142,    10,    10,
      44,    10,    92,    93,    26,    74,    47,    88,    46,    27,
      46,    46,    46,    40,    40,   141,   142,   142,    10,    94,
      95,    96,   100,   101,   104,    27,    26,    45,   108,   142,
      74,    40,    47,   108,   110,    47,    47,   107,    47,   107,
     141,    40,    53,    54,   128,   129,    47,    45,    95,    36,
      68,   110,    93,   142,    40,   142,   143,    47,    40,    27,
      47,    47,    47,   141,   142,    46,    53,   129,   142,    79,
      10,   143,   125,   142,    47,   110,   142,    60,    46,    27,
      40,    46,   103,    40,   142,    47,   142,    47,   108,   110,
      70,    71,   102,   142,    73,    97,    99,    47,    40,    27,
      27,    47,    75,    76,    98,   143,    99,    10,    10,   103,
      46,   143,    26,    26,    47,   107,    71,    70,    47,    27,
      27,    10,    10
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 4:

/* Line 1455 of yacc.c  */
#line 89 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 95 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		ast_compile_entry((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 99 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		ast_compile_entry((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 103 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		ast_compile_entry((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 107 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		ast_compile_entry((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 111 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		ast_compile_entry((yyvsp[(1) - (1)].ast_value))
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 115 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		ast_compile_entry((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 121 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_include((yyvsp[(2) - (3)].ast_value));
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 127 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_alias((yyvsp[(2) - (5)].ident_value), (yyvsp[(4) - (5)].ast_value));
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 133 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_namespace((yyvsp[(1) - (1)].ident_value));
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 137 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_namespace_list((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ident_value));
	;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 143 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_class((yyvsp[(2) - (6)].ident_value), (yyvsp[(3) - (6)].ast_value), (yyvsp[(5) - (6)].ast_value));
	;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 149 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 153 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_superclass((yyvsp[(2) - (2)].ident_value));
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 159 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_enum((yyvsp[(2) - (5)].ident_value), (yyvsp[(4) - (5)].ast_value));
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 165 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = (yyvsp[(1) - (1)].ast_value);
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 169 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_enum_item_list((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 175 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_enum_item((yyvsp[(1) - (3)].ident_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 179 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_enum_item((yyvsp[(1) - (1)].ident_value), ast_new_null());
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 185 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 189 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_member((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 193 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_member_list((yyvsp[(1) - (2)].ast_value), (yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 204 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_constructor((yyvsp[(1) - (8)].ast_value), (yyvsp[(5) - (8)].ast_value), (yyvsp[(7) - (8)].ast_value), (yyvsp[(8) - (8)].ast_value));
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 208 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_constructor((yyvsp[(1) - (7)].ast_value), ast_new_blank(), (yyvsp[(6) - (7)].ast_value), (yyvsp[(7) - (7)].ast_value));
	;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 214 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_constructor_chain((yyvsp[(2) - (5)].constructor_chain_type_value), (yyvsp[(4) - (5)].ast_value));
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 218 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_constructor_chain((yyvsp[(2) - (4)].constructor_chain_type_value), ast_new_blank());
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 224 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.constructor_chain_type_value) = cct_super;
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 228 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.constructor_chain_type_value) = cct_this;
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 234 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 241 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_function((yyvsp[(1) - (7)].ast_value), (yyvsp[(3) - (7)].ident_value), (yyvsp[(5) - (7)].ast_value), (yyvsp[(7) - (7)].ast_value));
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 245 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_function_empty_args((yyvsp[(1) - (6)].ast_value), (yyvsp[(3) - (6)].ident_value), (yyvsp[(6) - (6)].ast_value));
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 251 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field((yyvsp[(1) - (7)].ast_value), (yyvsp[(3) - (7)].ident_value), (yyvsp[(5) - (7)].ast_value), (yyvsp[(7) - (7)].ast_value));
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 255 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field((yyvsp[(1) - (4)].ast_value), (yyvsp[(3) - (4)].ident_value), ast_new_blank(), (yyvsp[(4) - (4)].ast_value));
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 261 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field_accessor(ast_new_field_setter((yyvsp[(7) - (7)].ident_value)), ast_new_field_getter((yyvsp[(3) - (7)].ident_value)));
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 265 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field_accessor(ast_new_field_setter((yyvsp[(3) - (7)].ident_value)), ast_new_field_getter((yyvsp[(7) - (7)].ident_value)));
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 269 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field_accessor(ast_new_field_setter((yyvsp[(3) - (3)].ident_value)), ast_new_blank());
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 273 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field_accessor(ast_new_blank(), ast_new_field_getter((yyvsp[(3) - (3)].ident_value)));
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 279 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = (yyvsp[(2) - (3)].ast_value);
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 283 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 289 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_modifier(mt_default);
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 293 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = (yyvsp[(2) - (3)].ast_value);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 299 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_modifier((yyvsp[(1) - (1)].modifier_type_value));
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 303 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_modifier_list((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].modifier_type_value));
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 309 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_default;
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 313 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_public;
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 317 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_private;
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 321 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_protected;
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 325 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_static;
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 329 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_final;
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 333 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.modifier_type_value) = mt_native;
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 339 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_argument_once((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 343 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_argument_list((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 349 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_parameter((yyvsp[(1) - (1)].ident_value));
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 353 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_parameter_list((yyvsp[(1) - (3)].ident_value), (yyvsp[(3) - (3)].ast_value))
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 359 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_stmt((yyvsp[(1) - (1)].ast_value));
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 363 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_stmt_list((yyvsp[(1) - (2)].ast_value), (yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 373 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_assign_match((yyvsp[(1) - (3)].ast_value), (yyvsp[(2) - (3)].assign_type_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 379 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.assign_type_value) = ao_Assign;
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 383 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.assign_type_value) = ao_Add;
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 387 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.assign_type_value) = ao_Sub;
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 391 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.assign_type_value) = ao_Mul;
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 395 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.assign_type_value) = ao_Div;
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 399 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.assign_type_value) = ao_Mod;
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 406 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_or((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 410 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_oror((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 417 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_and((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 421 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_andand((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 428 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_equal((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 432 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_notequal((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 439 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_biggest((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 443 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_e_biggest((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 447 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_smallest((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 451 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_e_smallest((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 458 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_add((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 462 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_sub((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 469 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_mul((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 473 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_div((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 477 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_mod((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ast_value));
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 484 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_not((yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 488 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_minus((yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 495 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_pre_increment((yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 499 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_pre_decrement((yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 506 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_field_access((yyvsp[(1) - (3)].ast_value), (yyvsp[(3) - (3)].ident_value));
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 510 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_invoke_bymessage_empty_args((yyvsp[(1) - (5)].ast_value), ast_new_newident());
	;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 514 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_invoke_bymessage((yyvsp[(1) - (6)].ast_value), ast_new_newident(), (yyvsp[(5) - (6)].ast_value))
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 518 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_invoke_bymessage_empty_args((yyvsp[(1) - (5)].ast_value), (yyvsp[(3) - (5)].ident_value));
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 522 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_invoke_bymessage((yyvsp[(1) - (6)].ast_value), (yyvsp[(3) - (6)].ident_value), (yyvsp[(5) - (6)].ast_value))
	;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 526 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_post_increment((yyvsp[(1) - (2)].ast_value));
	;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 530 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_post_decrement((yyvsp[(1) - (2)].ast_value));
	;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 540 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_array_empty_args();
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 544 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_array((yyvsp[(2) - (3)].ast_value));
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 550 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = (yyvsp[(2) - (3)].ast_value);
	;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 554 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_variable((yyvsp[(1) - (1)].ident_value));
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 558 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_invoke_byself_empty_args((yyvsp[(1) - (3)].ident_value));
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 562 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_invoke_byself((yyvsp[(1) - (4)].ident_value), (yyvsp[(3) - (4)].ast_value));
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 566 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_true();
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 570 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_false();
	;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 574 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_null();
	;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 585 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_this();
	;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 589 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_super();
	;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 596 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_lambda((yyvsp[(3) - (6)].ast_value), (yyvsp[(6) - (6)].ast_value));
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 600 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_lambda_empty_args((yyvsp[(5) - (5)].ast_value));
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 606 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_stmt((yyvsp[(1) - (2)].ast_value));
	;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 623 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_if((yyvsp[(3) - (5)].ast_value), (yyvsp[(5) - (5)].ast_value));
	;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 627 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_if_else((yyvsp[(3) - (7)].ast_value), (yyvsp[(5) - (7)].ast_value), (yyvsp[(7) - (7)].ast_value));
	;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 631 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_if_elseif_list((yyvsp[(3) - (6)].ast_value), (yyvsp[(5) - (6)].ast_value), (yyvsp[(6) - (6)].ast_value));
	;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 635 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_if_elseif_list_else((yyvsp[(3) - (8)].ast_value), (yyvsp[(5) - (8)].ast_value), (yyvsp[(6) - (8)].ast_value), (yyvsp[(8) - (8)].ast_value));
	;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 642 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_elseif_list((yyvsp[(1) - (2)].ast_value), (yyvsp[(2) - (2)].ast_value));
	;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 648 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_elseif((yyvsp[(3) - (5)].ast_value), (yyvsp[(5) - (5)].ast_value));
	;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 654 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_for_stmt((yyvsp[(3) - (9)].ast_value), (yyvsp[(5) - (9)].ast_value), (yyvsp[(7) - (9)].ast_value), (yyvsp[(9) - (9)].ast_value));
	;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 661 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_for_stmt((yyvsp[(3) - (8)].ast_value), (yyvsp[(4) - (8)].ast_value), (yyvsp[(6) - (8)].ast_value), (yyvsp[(8) - (8)].ast_value));
	;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 667 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_while_stmt((yyvsp[(3) - (5)].ast_value), (yyvsp[(5) - (5)].ast_value));
	;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 673 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_try_catch_finally_stmt((yyvsp[(2) - (9)].ast_value), (yyvsp[(5) - (9)].ident_value), (yyvsp[(7) - (9)].ast_value), (yyvsp[(9) - (9)].ast_value));
	;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 677 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_try_finally_stmt((yyvsp[(2) - (4)].ast_value), (yyvsp[(4) - (4)].ast_value));
	;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 681 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_try_catch_stmt((yyvsp[(2) - (7)].ast_value), (yyvsp[(5) - (7)].ident_value), (yyvsp[(7) - (7)].ast_value));
	;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 687 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_break();
	;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 693 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_continue();
	;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 699 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_return_empty();
	;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 703 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_return((yyvsp[(2) - (3)].ast_value));
	;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 709 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_throw_stmt((yyvsp[(2) - (3)].ast_value));
	;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 715 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_variable_decl((yyvsp[(2) - (5)].ident_value), (yyvsp[(4) - (5)].ast_value));
	;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 721 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_dyn_field((yyvsp[(1) - (6)].ast_value), (yyvsp[(3) - (6)].ident_value), (yyvsp[(5) - (6)].ast_value));
	;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 727 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_dyn_method((yyvsp[(1) - (8)].ast_value), (yyvsp[(3) - (8)].ident_value), (yyvsp[(7) - (8)].ast_value));
	;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 733 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 740 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_codeblock((yyvsp[(2) - (3)].ast_value));
	;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 744 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_codeblock_empty();
	;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 750 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"
    {
		(yyval.ast_value) = ast_new_blank();
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2983 "bean.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 755 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"

