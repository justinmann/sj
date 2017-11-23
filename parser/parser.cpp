/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */



#include <stdio.h>
#include "../node/Node.h"
#include "parser.hpp"

#define LOC CLoc(parseFile->fileName, yyloc.first_line, yyloc.first_column)
#define LLOC CLoc(parseFile->fileName, yylloc.first_line, yylloc.first_column)

int yyerror(YYLTYPE *locp, void *scanner, Compiler* compiler, CParseFile* parseFile, const char *msg) {
  if (locp) {
  	compiler->addWarning(CLoc(parseFile->fileName, locp->first_line, locp->first_column), CErrorCode::Parser, msg);
  } else {
  	compiler->addWarning(CLoc::undefined, CErrorCode::Parser, msg);
  }
  return (0);
}

extern int yylex(YYSTYPE * yylval_param,YYLTYPE * yylloc_param , void *scanner);

#define YYPRINT yyprint

void yyprint(FILE* file, unsigned short int v1, const YYSTYPE type) {
	switch (v1) {
		case TIDENTIFIER:
        case TINTEGER:
        case TDOUBLE:
			fprintf(file, "%s", type.string->c_str());
	}				
}




# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
    TAUTO = 330,
    TTYPEI32 = 331,
    TTYPEU32 = 332,
    TTYPEF32 = 333,
    TTYPEI64 = 334,
    TTYPEU64 = 335,
    TTYPEF64 = 336,
    TTYPECHAR = 337,
    TTYPEBOOL = 338,
    TTYPEPTR = 339
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

/* Copy the second part of user declarations.  */



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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  326

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   104,   105,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   120,   121,   122,   123,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   137,   143,
     148,   153,   160,   161,   164,   165,   168,   169,   172,   173,
     176,   179,   180,   181,   184,   185,   186,   187,   188,   191,
     194,   195,   198,   201,   204,   207,   208,   209,   212,   213,
     216,   217,   218,   219,   220,   221,   222,   225,   226,   227,
     230,   231,   232,   233,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   258,   259,   260,   263,   266,   269,   270,   271,
     274,   275,   276,   279,   280,   281,   282,   283,   284,   285,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   299,
     300,   301,   302,   303,   304,   305,   308,   309,   312,   313,
     314,   317,   318,   321,   322,   323,   324,   325,   328,   329,
     332,   335,   336,   339,   342,   343,   346,   349,   352,   353,
     354,   355,   358,   359,   360,   361,   364,   365,   368,   369,
     370,   371,   372,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   386,   389,   390,   393,   394,   395,   398,   399,
     402,   403,   404,   405,   408,   409,   412,   413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TINTEGER", "TDOUBLE",
  "TINVALID", "TSTRING", "TCHAR", "TCBLOCK", "TCFUNCTION", "TCDEFINE",
  "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TEND",
  "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE", "TCOMMA", "TCOLON", "TQUOTE",
  "TPLUS", "TMINUS", "TMUL", "TDIV", "TTRUE", "TFALSE", "TAS", "TVOID",
  "TIF", "TELSE", "TTHROW", "TCATCH", "TFOR", "TTO", "TWHILE", "TPLUSPLUS",
  "TMINUSMINUS", "TPLUSEQUAL", "TMINUSEQUAL", "TLBRACKET", "TRBRACKET",
  "TEXCLAIM", "TDOT", "TTHIS", "TINCLUDE", "TAND", "TOR", "TCOPY",
  "TDESTROY", "TMOD", "THASH", "TAT", "TCPEQ", "TCPNE", "TMULEQUAL",
  "TDIVEQUAL", "TISEMPTY", "TGETVALUE", "TASOPTION", "TQUESTION", "TEMPTY",
  "TVALUE", "TQUESTIONCOLON", "TQUESTIONDOT", "TPARENT", "TSTACK", "THEAP",
  "TLOCAL", "TAUTO", "TTYPEI32", "TTYPEU32", "TTYPEF32", "TTYPEI64",
  "TTYPEU64", "TTYPEF64", "TTYPECHAR", "TTYPEBOOL", "TTYPEPTR", "$accept",
  "program", "stmts", "stmt", "block", "var_decl", "func_decl",
  "func_type_name", "copy", "catch", "destroy", "func_block", "func_args",
  "func_arg", "implement", "implement_args", "implement_arg",
  "interface_decl", "interface_block", "interface_args", "interface_arg",
  "expr", "expr_and", "expr_and_inner", "expr_comp", "expr_math",
  "expr_var", "for_expr", "while_expr", "if_expr", "var", "var_right",
  "const", "assign", "assign_tuple", "assign_tuple_arg", "assign_type",
  "assign_mode", "assign_copy", "tuple", "tuple_args", "array",
  "array_args", "return_type_quote", "arg_type_quote", "arg_type",
  "arg_mode", "arg_type_interface", "return_type", "value_type",
  "func_type", "func_arg_type", "func_arg_type_list",
  "temp_block_optional", "temp_option_optional", "temp_block", "temp_args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     335,   336,   337,   338,   339
};
# endif

#define YYPACT_NINF -229

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-229)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     510,  -229,   321,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
     697,   221,  -229,  -229,  -229,   648,    18,    78,   648,   648,
     769,  -229,   133,   141,   136,   147,   127,   150,  -229,   161,
     160,  -229,  -229,  -229,    62,  -229,  -229,  -229,   226,   793,
     151,  -229,  -229,  -229,   616,  -229,  -229,  -229,  -229,   211,
     211,   819,   792,   303,   162,  -229,     7,   731,   180,   191,
      79,   -28,    28,  -229,  -229,   193,  -229,  -229,    11,   188,
     -14,   648,   200,   188,  -229,    24,  -229,  -229,   194,   648,
     648,  -229,   648,  -229,   441,    59,   233,   310,   180,   181,
    -229,   731,   731,   731,   731,   731,   731,   731,   731,   731,
     731,   731,   731,   731,   731,   731,   731,   819,  -229,  -229,
     731,   731,   648,    47,   731,   731,   125,  -229,   195,   195,
     195,   195,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,    21,  -229,
    -229,   819,  -229,  -229,  -229,   372,   127,  -229,  -229,   731,
     731,   145,   731,   183,   731,  -229,  -229,  -229,   579,   216,
     125,   235,   648,  -229,   648,  -229,   240,  -229,   254,   261,
     267,  -229,  -229,   229,  -229,  -229,  -229,    80,  -229,   243,
     194,   190,   251,   188,   310,  -229,  -229,  -229,    17,    17,
      17,    17,    17,    17,    95,    95,    45,    45,   227,    17,
      17,  -229,  -229,  -229,  -229,   250,   121,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,    94,   203,   233,  -229,    36,
    -229,  -229,  -229,  -229,     7,  -229,   -28,  -229,   275,   171,
     192,  -229,   265,  -229,   298,  -229,  -229,  -229,  -229,    59,
    -229,    59,   233,  -229,  -229,    23,  -229,  -229,  -229,   188,
     255,   251,   251,   188,   299,   303,   162,   194,  -229,  -229,
     819,   819,  -229,    96,    94,   819,  -229,  -229,  -229,  -229,
    -229,   648,   194,   180,   274,  -229,  -229,  -229,  -229,    94,
     233,  -229,   188,   270,   255,   255,   251,   372,  -229,  -229,
     372,  -229,  -229,  -229,   190,   203,  -229,  -229,   307,   304,
     298,  -229,   298,  -229,    94,  -229,   188,  -229,   270,   270,
     255,  -229,  -229,  -229,  -229,   188,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,   270,  -229,  -229
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,   107,   111,   113,   116,   117,    10,    12,    11,
       0,     0,   114,   115,    66,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,   108,     0,
       2,     3,     6,     7,     0,     8,     9,    63,    69,    82,
      91,    61,    62,    60,    93,   102,    94,    19,    64,   138,
     138,   152,   152,     0,     0,    33,   107,     0,     0,     0,
      73,    93,     0,   126,    72,     0,   110,   112,   107,     0,
      93,     0,     0,     0,   144,     0,    89,    13,   178,     0,
       0,   118,     0,     1,     0,    44,     0,   103,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,    20,    21,
       0,     0,     0,     0,     0,     0,     0,   139,   138,   138,
     138,   138,   131,   133,   132,   154,   155,   153,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   147,     0,   148,
     151,   152,   184,   119,   120,     0,   128,   103,    92,     0,
       0,     0,     0,     0,     0,    16,    18,    17,     0,    97,
       0,     0,     0,    96,     0,   143,     0,   179,     0,     0,
       0,     4,    47,     0,    41,    45,    48,    93,    46,   156,
     178,   152,    36,     0,     0,    51,    67,    68,    74,    75,
      78,    79,    80,    81,    83,    84,    85,    86,    87,    76,
      77,    88,    90,    22,    23,     0,   107,   100,    24,    25,
     101,   136,   137,   135,   134,   180,   175,     0,   186,     0,
     121,   129,    70,    71,   107,   125,     0,   127,   140,     0,
       0,    65,     0,   145,    58,    53,   104,   105,   106,    44,
      40,    44,     0,    52,   162,     0,   146,   158,   161,     0,
      34,    36,    36,     0,    26,     0,     0,   181,   149,   182,
     152,   152,   176,     0,   180,   152,   185,   130,    15,    98,
      99,     0,    32,     0,     0,    55,    42,    43,   157,   180,
       0,    37,     0,    38,    34,    34,    36,     0,   122,   123,
       0,   183,   173,   174,   152,     0,   150,   187,     0,     0,
      58,    54,    58,   159,   180,    35,     0,    28,    38,    38,
      34,    27,   124,   172,   177,     0,    59,    56,    57,   160,
      39,    30,    29,    38,    95,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,   175,   -50,   -71,  -229,   -73,     0,  -147,  -212,
    -132,   -51,  -229,  -135,  -229,  -229,   256,   -68,  -229,  -229,
     -96,   -10,   166,  -229,     1,   784,   323,  -229,  -229,   118,
       4,   -83,  -229,   -67,  -229,   197,   -41,   302,   237,  -229,
    -229,  -229,  -229,  -165,   -25,   -42,  -161,  -188,    65,  -159,
    -158,    66,  -229,   182,  -228,   -72,  -229
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,   159,    32,    33,    58,   283,   250,
     307,    87,   173,   174,    88,    89,    90,    35,   235,   274,
     275,    36,    37,    59,    38,    39,    40,    41,    42,    43,
      70,    45,    46,    47,    62,    63,    53,   122,   123,    64,
      65,    48,    75,   183,    54,   137,   138,   180,   246,   139,
     140,   262,   263,   166,   258,    55,   219
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    81,   163,   143,    44,    69,   167,   147,    73,    74,
     142,    60,   172,   145,    61,   146,   182,   175,   178,   253,
     245,   151,   247,   248,   215,    49,   279,   -32,   144,   264,
     207,   -32,    50,   210,   171,   160,   296,   184,    71,   284,
     285,   216,   116,   216,    99,   100,   101,   102,   164,   152,
     206,   303,   153,    34,   278,    52,   116,    44,    60,    52,
     265,   161,     2,     3,     4,   202,     5,     6,   207,   168,
     169,   165,   170,   103,   310,   176,   319,   207,   217,    10,
     280,    72,    85,   266,    34,    34,   106,    11,    44,   177,
      12,    13,   304,    14,    15,   220,    16,    21,    17,   218,
      18,   103,   205,  -141,   276,    19,   277,    20,   167,    21,
      24,    25,   251,   252,   106,    27,    23,   294,    28,    86,
     295,   221,    24,    25,   101,   102,    26,    27,    68,   113,
      28,   149,   150,   245,   316,   247,   248,   308,   309,    49,
      77,   -32,    52,   259,    78,    34,    50,    51,   224,    44,
     116,   103,   232,    51,   233,   228,    79,   226,    34,   269,
     257,    83,    44,   323,   106,   255,   172,    80,   172,    52,
      82,   175,   178,   175,   178,    21,   321,   322,   281,    84,
      49,   256,   286,   267,   107,   291,    56,    50,    24,    25,
      84,   325,   259,    27,   268,    21,    28,   155,   156,   157,
      85,   155,   156,   157,   317,   288,   318,   259,    24,    25,
     158,   305,   148,    27,   158,   290,    28,   154,   292,   293,
     162,   260,   299,   297,   244,    66,    67,    15,   261,   176,
     289,   176,   259,    21,   273,   320,   179,   311,    86,    34,
     312,    34,    52,   177,   324,   177,    24,    25,   239,   117,
     240,    27,   230,   241,    28,    34,   231,   186,   187,    44,
     234,   298,   125,   126,   127,   117,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   236,   203,   204,    91,    92,
     208,   209,   237,   118,   119,   120,   121,    34,   238,   249,
      34,    44,   242,   300,    44,   301,   106,   254,   302,  -142,
     273,   272,   273,    -5,     1,   271,     2,     3,     4,   282,
       5,     6,     7,     8,     9,   222,   223,   287,   225,   155,
     156,   157,    -5,    10,    -5,   306,    -5,    -5,   315,    51,
     181,    11,   158,   229,    12,    13,   181,    14,    15,    49,
      16,   -32,    17,    76,    18,   185,    50,    51,   270,    19,
     227,    20,   124,    21,    22,   211,   212,   213,   214,   313,
      23,   314,   243,     0,     0,     0,    24,    25,     0,    52,
      26,    27,    -5,     1,    28,     2,     3,     4,   -32,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,     0,
       0,    -5,    10,    -5,     0,    -5,    -5,     0,     0,     0,
      11,     0,     0,    12,    13,     0,    14,    15,     0,    16,
       0,    17,     0,    18,     0,     0,     0,     0,    19,     0,
      20,     0,    21,    22,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,    24,    25,     0,     0,    26,
      27,    -5,     1,    28,     2,     3,     4,     0,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,     0,     0,
      -5,    10,     0,     0,    -5,     0,     0,     0,     0,    11,
       0,     0,    12,    13,     0,    14,    15,     0,    16,     0,
      17,     0,    18,     0,     0,     0,     0,    19,     0,    20,
       0,    21,    22,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,    24,    25,     0,     0,    26,    27,
      -5,     1,    28,     2,     3,     4,     0,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,    -5,
      10,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,    12,    13,     0,    14,    15,     0,    16,     0,    17,
       0,    18,     0,     0,     0,     0,    19,     0,    20,     0,
      21,    22,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    24,    25,     0,     0,    26,    27,     0,
       1,    28,     2,     3,     4,     0,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,    -5,    10,
       0,     0,    -5,     0,     0,     0,     0,    11,     0,     0,
      12,    13,     0,    14,    15,     0,    16,     0,    17,     0,
      18,     0,     0,     0,     0,    19,     0,    20,     0,    21,
      22,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,    24,    25,     0,     0,    26,    27,     0,     0,
      28,    68,     3,     4,     0,     5,     6,     0,   108,   109,
     110,   111,   112,     0,     0,   113,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,    11,   114,   115,    12,
      13,     0,    14,    15,     0,    16,   116,    17,     0,    18,
       0,     0,     0,     0,    19,     0,    20,     0,    21,     0,
      56,     3,     4,     0,     5,     6,     0,     0,     0,     0,
       0,    24,    25,     0,     0,    26,    27,    57,     0,    28,
       0,     0,     0,     0,     0,    11,     0,     0,    12,    13,
       0,     0,     0,     0,    68,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     0,    20,     0,    21,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,    11,
      24,    25,    12,    13,    26,    27,     0,     0,    28,     0,
       0,     0,    68,     3,     4,     0,     5,     6,     0,    20,
       0,    21,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,    24,    25,     0,    11,    26,    27,
      12,    13,    28,     0,     0,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,    26,    27,   141,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,   125,   126,   127,     0,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   125,   126,   127,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
       0,    26,    73,    53,     0,    15,    78,    58,    18,    19,
      52,    10,    85,    54,    10,    56,    87,    85,    85,   184,
     181,    49,   181,   181,     3,    18,     3,    20,    53,   217,
     113,    20,    25,   116,    84,    49,   264,    88,    20,   251,
     252,    20,    70,    20,    27,    28,    29,    30,    24,    21,
       3,   279,    24,    53,   242,    48,    70,    53,    57,    48,
      24,    71,     3,     4,     5,   107,     7,     8,   151,    79,
      80,    47,    82,    56,   286,    85,   304,   160,    57,    20,
      57,     3,    20,    47,    84,    85,    69,    28,    84,    85,
      31,    32,   280,    34,    35,   145,    37,    50,    39,   141,
      41,    56,   112,    24,   239,    46,   241,    48,   180,    50,
      63,    64,   183,   184,    69,    68,    57,    21,    71,    57,
      24,   146,    63,    64,    29,    30,    67,    68,     3,    49,
      71,    52,    53,   294,   299,   294,   294,   284,   285,    18,
       7,    20,    48,   215,     3,   145,    25,    26,     3,   145,
      70,    56,   162,    26,   164,   154,    20,   153,   158,   230,
      66,     0,   158,   310,    69,   206,   239,    20,   241,    48,
      20,   239,   239,   241,   241,    50,   308,   309,   249,    19,
      18,   206,   253,   224,    33,   257,     3,    25,    63,    64,
      19,   323,   264,    68,    23,    50,    71,     9,    10,    11,
      20,     9,    10,    11,   300,   255,   302,   279,    63,    64,
      22,   282,    21,    68,    22,   256,    71,    24,   260,   261,
      20,    18,   273,   265,    34,     4,     5,    35,    25,   239,
     255,   241,   304,    50,   234,   306,     3,   287,    57,   239,
     290,   241,    48,   239,   315,   241,    63,    64,    19,    54,
      21,    68,    36,    24,    71,   255,    21,    91,    92,   255,
      20,   271,    72,    73,    74,    54,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    21,   110,   111,    52,    53,
     114,   115,    21,    72,    73,    74,    75,   287,    21,    38,
     290,   287,    49,    19,   290,    21,    69,    47,    24,    24,
     300,     3,   302,     0,     1,    40,     3,     4,     5,    54,
       7,     8,     9,    10,    11,   149,   150,    18,   152,     9,
      10,    11,    19,    20,    21,    55,    23,    24,    21,    26,
      26,    28,    22,   158,    31,    32,    26,    34,    35,    18,
      37,    20,    39,    20,    41,    89,    25,    26,   230,    46,
     153,    48,    50,    50,    51,   118,   119,   120,   121,   294,
      57,   295,   180,    -1,    -1,    -1,    63,    64,    -1,    48,
      67,    68,     0,     1,    71,     3,     4,     5,    57,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,    -1,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    67,
      68,     0,     1,    71,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,
      -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    67,    68,
       0,     1,    71,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    67,    68,    -1,
       1,    71,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      31,    32,    -1,    34,    35,    -1,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    67,    68,    -1,    -1,
      71,     3,     4,     5,    -1,     7,     8,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    49,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    61,    62,    31,
      32,    -1,    34,    35,    -1,    37,    70,    39,    -1,    41,
      -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,    -1,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    67,    68,    20,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      63,    64,    31,    32,    67,    68,    -1,    -1,    71,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    63,    64,    -1,    28,    67,    68,
      31,    32,    71,    -1,    -1,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    67,    68,    46,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     7,     8,     9,    10,    11,
      20,    28,    31,    32,    34,    35,    37,    39,    41,    46,
      48,    50,    51,    57,    63,    64,    67,    68,    71,    86,
      87,    88,    90,    91,    92,   102,   106,   107,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   126,    18,
      25,    26,    48,   121,   129,   140,     3,    20,    92,   108,
     109,   115,   119,   120,   124,   125,     4,     5,     3,   106,
     115,    20,     3,   106,   106,   127,   111,     7,     3,    20,
      20,   129,    20,     0,    19,    20,    57,    96,    99,   100,
     101,    52,    53,    12,    13,    14,    15,    16,    17,    27,
      28,    29,    30,    56,    59,    60,    69,    33,    42,    43,
      44,    45,    46,    49,    61,    62,    70,    54,    72,    73,
      74,    75,   122,   123,   122,    72,    73,    74,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   130,   131,   134,
     135,    46,   130,    88,   129,   121,   121,    96,    21,    52,
      53,    49,    21,    24,    24,     9,    10,    11,    22,    89,
      49,   106,    20,    89,    24,    47,   138,   140,   106,   106,
     106,    88,    91,    97,    98,   102,   106,   115,   118,     3,
     132,    26,    89,   128,    96,   101,   107,   107,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   130,   107,   107,   106,     3,   116,   107,   107,
     116,   123,   123,   123,   123,     3,    20,    57,   130,   141,
      88,   129,   107,   107,     3,   107,   115,   120,   109,    87,
      36,    21,   106,   106,    20,   103,    21,    21,    21,    19,
      21,    24,    49,   138,    34,   131,   133,   134,   135,    38,
      94,    89,    89,   128,    47,   121,   129,    66,   139,   140,
      18,    25,   136,   137,   132,    24,    47,   121,    23,    89,
     114,    40,     3,    92,   104,   105,    98,    98,   132,     3,
      57,    89,    54,    93,    94,    94,    89,    18,    88,   129,
     121,   140,   130,   130,    21,    24,   139,   130,   106,    96,
      19,    21,    24,   139,   132,    89,    55,    95,    93,    93,
      94,    88,    88,   133,   136,    21,   128,   105,   105,   139,
      89,    95,    95,    93,    89,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    97,    97,    97,    98,    98,    98,    98,    98,    99,
     100,   100,   101,   102,   103,   104,   104,   104,   105,   105,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     108,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   112,   113,   114,   114,   114,
     115,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   119,   119,   120,   120,
     120,   121,   121,   122,   122,   122,   122,   122,   123,   123,
     124,   125,   125,   126,   127,   127,   128,   129,   130,   130,
     130,   130,   131,   131,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   136,   136,   137,   137,   137,   138,   138,
     139,   139,   139,   139,   140,   140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       2,     2,     3,     3,     3,     3,     4,     6,     6,     7,
       7,     8,     1,     2,     0,     2,     0,     2,     0,     2,
       3,     1,     3,     3,     0,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     3,     1,     3,     3,     0,     3,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     3,     1,     1,     8,     3,     3,     5,     5,
       3,     3,     1,     2,     4,     4,     4,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     2,     3,
       3,     4,     5,     5,     6,     4,     1,     3,     2,     3,
       4,     2,     2,     1,     2,     2,     2,     2,     0,     1,
       3,     1,     3,     3,     1,     3,     2,     2,     1,     3,
       4,     1,     0,     1,     1,     1,     1,     3,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     2,     0,     1,     3,     0,     1,
       0,     1,     1,     2,     2,     4,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, scanner, compiler, parseFile, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner, compiler, parseFile); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, Compiler* compiler, CParseFile* parseFile)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (compiler);
  YYUSE (parseFile);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, Compiler* compiler, CParseFile* parseFile)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, compiler, parseFile);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void *scanner, Compiler* compiler, CParseFile* parseFile)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, compiler, parseFile);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, compiler, parseFile); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *scanner, Compiler* compiler, CParseFile* parseFile)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (compiler);
  YYUSE (parseFile);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner, Compiler* compiler, CParseFile* parseFile)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { parseFile->block = std::shared_ptr<NBlock>((yyvsp[0].block)); }

    break;

  case 3:

    { (yyval.block) = new NBlock(LOC); if ((yyvsp[0].node)) (yyval.block)->statements.push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 4:

    { if ((yyvsp[0].node)) (yyvsp[-2].block)->statements.push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 5:

    { (yyval.node) = nullptr; }

    break;

  case 9:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 10:

    { (yyval.node) = new NCCode(LOC, NCC_BLOCK, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 11:

    { (yyval.node) = new NCCode(LOC, NCC_DEFINE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 12:

    { (yyval.node) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 13:

    { (yyval.node) = new NInclude(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 14:

    { (yyval.node) = nullptr; /* yyclearin; */ compiler->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }

    break;

  case 15:

    { (yyval.node) = (yyvsp[-1].block); }

    break;

  case 16:

    { (yyval.node) = new NCCode(LOC, NCC_BLOCK, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 17:

    { (yyval.node) = new NCCode(LOC, NCC_DEFINE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 18:

    { (yyval.node) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 20:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Inc, nullptr); }

    break;

  case 21:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Dec, nullptr); }

    break;

  case 22:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 23:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 24:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 25:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 26:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 27:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), make_shared<NCall>(LOC, "setAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[0].node))))); }

    break;

  case 28:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].typeName)->valueName.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-5].typeName); 
					}

    break;

  case 29:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 30:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 31:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-7].typeName)->valueName.c_str(), (yyvsp[-7].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-6].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 32:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, (yyvsp[0].string)->c_str(), false); delete (yyvsp[0].string); }

    break;

  case 33:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 34:

    { (yyval.node) = nullptr; }

    break;

  case 35:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 36:

    { (yyval.node) = nullptr; }

    break;

  case 37:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 38:

    { (yyval.node) = nullptr; }

    break;

  case 39:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 40:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 41:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 42:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 43:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 44:

    { (yyval.node) = nullptr; }

    break;

  case 48:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 49:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 50:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 51:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 52:

    { (yyval.typeName) = new CTypeName(CTC_Interface, CTM_Stack, *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 53:

    { (yyval.node) = new NInterface(LOC, *(yyvsp[-2].string), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 54:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 55:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 56:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 57:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 58:

    { (yyval.node) = nullptr; }

    break;

  case 59:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].typeName)->valueName.c_str(), (yyvsp[-2].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 60:

    { (yyval.node) = (yyvsp[0].nif); }

    break;

  case 63:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 65:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 66:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 67:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 68:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 70:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 71:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 72:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 74:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::EQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 75:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::NE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 76:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PEQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 77:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PNE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 78:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 79:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 80:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 81:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 82:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 83:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 84:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 85:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 86:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 87:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mod, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 88:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 89:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 90:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 91:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 92:

    { (yyval.var) = (yyvsp[-1].var); }

    break;

  case 93:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 94:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 95:

    { (yyval.node) = new NFor(LOC, (yyvsp[-6].string)->c_str(), shared_ptr<NBase>((yyvsp[-4].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); delete (yyvsp[-6].string); }

    break;

  case 96:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 97:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 98:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 99:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].nif))); }

    break;

  case 100:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 101:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 103:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].typeName)->valueName.c_str(), (yyvsp[-1].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].typeName); }

    break;

  case 104:

    { (yyval.var) = new NIsEmpty(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 105:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 106:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 107:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 108:

    { (yyval.var) = new NParent(LOC); }

    break;

  case 109:

    { (yyval.var) = new NThis(LOC); }

    break;

  case 110:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 111:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 112:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 113:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 114:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 115:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 116:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 117:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 118:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 119:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 120:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 121:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 122:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 123:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 124:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 125:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 126:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 127:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 128:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 129:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), (yyvsp[-1].assignOp)); }

    break;

  case 130:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 131:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).isMutable = true; }

    break;

  case 132:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).isMutable = false; }

    break;

  case 133:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).typeMode = CTM_Undefined; }

    break;

  case 134:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).typeMode = CTM_Undefined; }

    break;

  case 135:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).typeMode = CTM_Local; }

    break;

  case 136:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).typeMode = CTM_Stack; }

    break;

  case 137:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).typeMode = CTM_Heap; }

    break;

  case 138:

    { (yyval.assignOp).isCopy = false; }

    break;

  case 139:

    { (yyval.assignOp).isCopy = true; }

    break;

  case 140:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 141:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 142:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 143:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec))); }

    break;

  case 144:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 145:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 146:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 147:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 148:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 149:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-2].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 150:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-3].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 151:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 152:

    { (yyval.typeMode) = CTM_Undefined; }

    break;

  case 153:

    { (yyval.typeMode) = CTM_Local; }

    break;

  case 154:

    { (yyval.typeMode) = CTM_Stack; }

    break;

  case 155:

    { (yyval.typeMode) = CTM_Heap; }

    break;

  case 156:

    { (yyval.string) = (yyvsp[0].string); }

    break;

  case 157:

    { (yyval.string) = new string(*(yyvsp[-2].string) + "." + *(yyvsp[0].string)); }

    break;

  case 158:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 159:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-2].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 160:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-3].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 161:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 162:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, "void", false); }

    break;

  case 163:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "i32", false); }

    break;

  case 164:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "u32", false); }

    break;

  case 165:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "f32", false); }

    break;

  case 166:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "i64", false); }

    break;

  case 167:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "u64", false); }

    break;

  case 168:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "f64", false); }

    break;

  case 169:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "char", false); }

    break;

  case 170:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "bool", false); }

    break;

  case 171:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "ptr", false); }

    break;

  case 172:

    { (yyval.typeName) = new CTypeName((yyvsp[-4].typeMode), shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 173:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Mutable; }

    break;

  case 174:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Immutable; }

    break;

  case 175:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 176:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 177:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 178:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 179:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 180:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 181:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 182:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 183:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 184:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 185:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 186:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 187:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, compiler, parseFile, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, compiler, parseFile, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, scanner, compiler, parseFile);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner, compiler, parseFile);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, compiler, parseFile, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, compiler, parseFile);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, scanner, compiler, parseFile);
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
  return yyresult;
}

