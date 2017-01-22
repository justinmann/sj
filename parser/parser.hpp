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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
    TCEQ = 263,
    TCNE = 264,
    TCLT = 265,
    TCLE = 266,
    TCGT = 267,
    TCGE = 268,
    TEQUAL = 269,
    TEND = 270,
    TLPAREN = 271,
    TRPAREN = 272,
    TLBRACE = 273,
    TRBRACE = 274,
    TCOMMA = 275,
    TCOLON = 276,
    TQUOTE = 277,
    TPLUS = 278,
    TMINUS = 279,
    TMUL = 280,
    TDIV = 281,
    TTRUE = 282,
    TFALSE = 283,
    TCAST = 284,
    TVOID = 285,
    TIF = 286,
    TELSE = 287,
    TTHROW = 288,
    TCATCH = 289,
    TEXTERN = 290,
    TFOR = 291,
    TTO = 292,
    TWHILE = 293,
    TPLUSPLUS = 294,
    TMINUSMINUS = 295,
    TPLUSEQUAL = 296,
    TMINUSEQUAL = 297,
    TLBRACKET = 298,
    TRBRACKET = 299,
    TEXCLAIM = 300,
    TDOT = 301,
    TTHIS = 302,
    TINCLUDE = 303
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
	TemplateTypeNames* templateTypeNames;
	int token;
	bool isMutable;


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



int yyparse (void *scanner, CResult* result);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
