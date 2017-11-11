//insert by Automatic.exe---
#include "assign_type.h"
#include "ast.h"
#include "modifier_type.h"
//---insert by Automatic.exe

/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 12 "C:\\Users\\Koya\\Desktop\\SVN\\Local\\Bean\\v1\\trunk\\Bean\\Bean\\bean\\parser\\bison\\bean.y"

	char char_value;
	const char* ident_value;
	ast* ast_value;
	assign_type assign_type_value;
	modifier_type modifier_type_value;
	constructor_chain_type constructor_chain_type_value;



/* Line 1676 of yacc.c  */
#line 144 "bean.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


