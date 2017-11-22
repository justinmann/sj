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

#ifndef YY_YY_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */


struct OPTIONANDTYPELIST {
	bool isOption;
	CTypeNameList* templateTypeNames;	
};



/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENTIFIER = 258,
    TINTEGER = 259,
    TDOUBLE = 260,
    TINVALID = 261,
    TSTRING = 262,
    TCHAR = 263,
    TCBLOCK = 264,
    TCFUNCTION = 265,
    TCDEFINE = 266,
    TCEQ = 267,
    TCNE = 268,
    TCLT = 269,
    TCLE = 270,
    TCGT = 271,
    TCGE = 272,
    TEQUAL = 273,
    TEND = 274,
    TLPAREN = 275,
    TRPAREN = 276,
    TLBRACE = 277,
    TRBRACE = 278,
    TCOMMA = 279,
    TCOLON = 280,
    TQUOTE = 281,
    TPLUS = 282,
    TMINUS = 283,
    TMUL = 284,
    TDIV = 285,
    TTRUE = 286,
    TFALSE = 287,
    TAS = 288,
    TVOID = 289,
    TIF = 290,
    TELSE = 291,
    TTHROW = 292,
    TCATCH = 293,
    TFOR = 294,
    TTO = 295,
    TWHILE = 296,
    TPLUSPLUS = 297,
    TMINUSMINUS = 298,
    TPLUSEQUAL = 299,
    TMINUSEQUAL = 300,
    TLBRACKET = 301,
    TRBRACKET = 302,
    TEXCLAIM = 303,
    TDOT = 304,
    TTHIS = 305,
    TINCLUDE = 306,
    TAND = 307,
    TOR = 308,
    TCOPY = 309,
    TDESTROY = 310,
    TMOD = 311,
    THASH = 312,
    TAT = 313,
    TCPEQ = 314,
    TCPNE = 315,
    TMULEQUAL = 316,
    TDIVEQUAL = 317,
    TISEMPTY = 318,
    TGETVALUE = 319,
    TASOPTION = 320,
    TQUESTION = 321,
    TEMPTY = 322,
    TVALUE = 323,
    TQUESTIONCOLON = 324,
    TQUESTIONDOT = 325,
    TPARENT = 326,
    TSTACK = 327,
    THEAP = 328,
    TLOCAL = 329,
    TCOLONCOPY = 330,
    TEQUALCOPY = 331,
    TTYPEI32 = 332,
    TTYPEU32 = 333,
    TTYPEF32 = 334,
    TTYPEI64 = 335,
    TTYPEU64 = 336,
    TTYPEF64 = 337,
    TTYPECHAR = 338,
    TTYPEBOOL = 339,
    TTYPEPTR = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


	NBase* node;
	NBlock* block;
	NIf* nif;
	NVariableBase* var;
	NodeList* exprvec;
	std::string* string;
	CTypeName* typeName;
	CTypeNameList* templateTypeNames;
	int token;
	AssignOp assignOp;
	OPTIONANDTYPELIST optionAndTypeList;
	NTupleAssignmentArgList* tupleAssignmentArgList;
	NTupleAssignmentArg* tupleAssignmentArg;
	CTypeMode typeMode;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (void *scanner, Compiler* compiler, CParseFile* parseFile);

#endif /* !YY_YY_PARSER_PARSER_HPP_INCLUDED  */
