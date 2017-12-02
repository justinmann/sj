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
    TCINCLUDE = 268,
    TCEQ = 269,
    TCNE = 270,
    TCLT = 271,
    TCLE = 272,
    TCGT = 273,
    TCGE = 274,
    TEQUAL = 275,
    TEND = 276,
    TLPAREN = 277,
    TRPAREN = 278,
    TLBRACE = 279,
    TRBRACE = 280,
    TCOMMA = 281,
    TCOLON = 282,
    TQUOTE = 283,
    TPLUS = 284,
    TMINUS = 285,
    TMUL = 286,
    TDIV = 287,
    TTRUE = 288,
    TFALSE = 289,
    TAS = 290,
    TVOID = 291,
    TIF = 292,
    TELSE = 293,
    TTHROW = 294,
    TCATCH = 295,
    TFOR = 296,
    TTO = 297,
    TWHILE = 298,
    TPLUSPLUS = 299,
    TMINUSMINUS = 300,
    TPLUSEQUAL = 301,
    TMINUSEQUAL = 302,
    TLBRACKET = 303,
    TRBRACKET = 304,
    TEXCLAIM = 305,
    TDOT = 306,
    TTHIS = 307,
    TINCLUDE = 308,
    TAND = 309,
    TOR = 310,
    TCOPY = 311,
    TDESTROY = 312,
    TMOD = 313,
    THASH = 314,
    TAT = 315,
    TCPEQ = 316,
    TCPNE = 317,
    TMULEQUAL = 318,
    TDIVEQUAL = 319,
    TISEMPTY = 320,
    TGETVALUE = 321,
    TASOPTION = 322,
    TQUESTION = 323,
    TEMPTY = 324,
    TVALUE = 325,
    TQUESTIONCOLON = 326,
    TQUESTIONDOT = 327,
    TPARENT = 328,
    TSTACK = 329,
    THEAP = 330,
    TLOCAL = 331,
    TAUTO = 332,
    TTYPEI32 = 333,
    TTYPEU32 = 334,
    TTYPEF32 = 335,
    TTYPEI64 = 336,
    TTYPEU64 = 337,
    TTYPEF64 = 338,
    TTYPECHAR = 339,
    TTYPEBOOL = 340,
    TTYPEPTR = 341
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
