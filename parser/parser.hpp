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
    TCSTRUCT = 267,
    TCEQ = 268,
    TCNE = 269,
    TCLT = 270,
    TCLE = 271,
    TCGT = 272,
    TCGE = 273,
    TEQUAL = 274,
    TEND = 275,
    TLPAREN = 276,
    TRPAREN = 277,
    TLBRACE = 278,
    TRBRACE = 279,
    TCOMMA = 280,
    TCOLON = 281,
    TQUOTE = 282,
    TPLUS = 283,
    TMINUS = 284,
    TMUL = 285,
    TDIV = 286,
    TTRUE = 287,
    TFALSE = 288,
    TAS = 289,
    TVOID = 290,
    TIF = 291,
    TELSE = 292,
    TTHROW = 293,
    TCATCH = 294,
    TFOR = 295,
    TTO = 296,
    TWHILE = 297,
    TPLUSPLUS = 298,
    TMINUSMINUS = 299,
    TPLUSEQUAL = 300,
    TMINUSEQUAL = 301,
    TLBRACKET = 302,
    TRBRACKET = 303,
    TEXCLAIM = 304,
    TDOT = 305,
    TTHIS = 306,
    TINCLUDE = 307,
    TAND = 308,
    TOR = 309,
    TCOPY = 310,
    TDESTROY = 311,
    TMOD = 312,
    THASH = 313,
    TAT = 314,
    TCPEQ = 315,
    TCPNE = 316,
    TMULEQUAL = 317,
    TDIVEQUAL = 318,
    TISEMPTY = 319,
    TGETVALUE = 320,
    TASOPTION = 321,
    TQUESTION = 322,
    TEMPTY = 323,
    TVALUE = 324,
    TQUESTIONCOLON = 325,
    TQUESTIONDOT = 326,
    TPARENT = 327,
    TSTACK = 328,
    THEAP = 329,
    TLOCAL = 330,
    TAUTO = 331,
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
