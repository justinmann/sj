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

#define LOC CLoc(result->fileName, yyloc.first_line, yyloc.first_column)
#define LLOC CLoc(result->fileName, yylloc.first_line, yylloc.first_column)

int yyerror(YYLTYPE *locp, void *scanner, CResult* result, const char *msg) {
  if (locp) {
  	result->addWarning(CLoc(result->fileName, locp->first_line, locp->first_column), CErrorCode::Parser, msg);
  } else {
  	result->addWarning(CLoc::undefined, CErrorCode::Parser, msg);
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
    TDESTROY = 309,
    TMOD = 310,
    THASH = 311,
    TAT = 312,
    TCPEQ = 313,
    TCPNE = 314,
    TMULEQUAL = 315,
    TDIVEQUAL = 316,
    TISEMPTY = 317,
    TGETVALUE = 318,
    TASOPTION = 319,
    TQUESTION = 320,
    TEMPTY = 321,
    TVALUE = 322,
    TQUESTIONCOLON = 323,
    TQUESTIONDOT = 324,
    TPARENT = 325
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
	bool isMutable;
	OPTIONANDTYPELIST optionAndTypeList;
	NTupleAssignmentArgList* tupleAssignmentArgList;
	NTupleAssignmentArg* tupleAssignmentArg;


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
#define YYLAST   885

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   102,   103,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   118,   119,   120,   121,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   135,   141,
     146,   151,   158,   159,   162,   163,   166,   167,   170,   173,
     174,   175,   178,   179,   180,   181,   182,   185,   188,   189,
     192,   195,   198,   201,   202,   203,   206,   207,   210,   211,
     212,   213,   214,   215,   216,   219,   220,   221,   224,   225,
     226,   227,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     252,   253,   254,   257,   260,   263,   264,   265,   268,   269,
     270,   273,   274,   275,   276,   277,   278,   279,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   293,   294,   295,
     296,   297,   298,   299,   302,   303,   306,   307,   308,   311,
     312,   315,   318,   319,   322,   325,   326,   329,   332,   335,
     336,   337,   340,   341,   344,   345,   348,   351,   352,   355,
     356,   357,   360,   361,   364,   365,   366,   367,   370,   371,
     374,   375
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
  "TEXCLAIM", "TDOT", "TTHIS", "TINCLUDE", "TAND", "TOR", "TDESTROY",
  "TMOD", "THASH", "TAT", "TCPEQ", "TCPNE", "TMULEQUAL", "TDIVEQUAL",
  "TISEMPTY", "TGETVALUE", "TASOPTION", "TQUESTION", "TEMPTY", "TVALUE",
  "TQUESTIONCOLON", "TQUESTIONDOT", "TPARENT", "$accept", "program",
  "stmts", "stmt", "block", "var_decl", "func_decl", "func_type_name",
  "catch", "destroy", "func_block", "func_args", "func_arg", "implement",
  "implement_args", "implement_arg", "interface_decl", "interface_block",
  "interface_args", "interface_arg", "expr", "expr_and", "expr_and_inner",
  "expr_comp", "expr_math", "expr_var", "for_expr", "while_expr",
  "if_expr", "var", "var_right", "const", "assign", "assign_tuple",
  "assign_tuple_arg", "assign_type", "tuple", "tuple_args", "array",
  "array_args", "return_type_quote", "arg_type_quote", "arg_type",
  "arg_type_interface", "return_type", "func_type", "func_arg_type",
  "func_arg_type_list", "temp_block_optional", "temp_option_optional",
  "temp_block", "temp_args", YY_NULLPTR
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
     325
};
# endif

#define YYPACT_NINF -202

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-202)))

#define YYTABLE_NINF -134

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     479,  -202,   148,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
     731,    78,  -202,  -202,  -202,   683,    15,    98,   683,   683,
     801,  -202,   110,   126,   140,   144,   120,   152,  -202,   179,
     162,  -202,  -202,  -202,     2,  -202,  -202,  -202,   125,   232,
     165,  -202,  -202,  -202,   208,  -202,  -202,  -202,  -202,  -202,
    -202,    21,    23,   275,    19,  -202,    14,   764,   188,   193,
     100,   -24,    90,  -202,  -202,   175,  -202,  -202,    30,   178,
     -13,   683,   197,   178,  -202,    25,  -202,  -202,   172,   683,
     683,  -202,   683,  -202,   411,   615,   228,   196,   188,   180,
    -202,   764,   764,   764,   764,   764,   764,   764,   764,   764,
     764,   764,   764,   764,   764,   764,   764,    21,  -202,  -202,
     764,   764,   683,    24,   764,   764,    43,    44,   107,   228,
    -202,  -202,    21,  -202,  -202,  -202,   343,   120,  -202,  -202,
     764,   764,    45,   764,   113,   764,  -202,  -202,  -202,   547,
     198,    43,   217,   683,  -202,   683,  -202,   220,  -202,   221,
     222,   234,  -202,  -202,   205,  -202,  -202,  -202,    50,  -202,
     192,   172,    20,   218,   178,   196,  -202,  -202,  -202,   164,
     164,   164,   164,   164,   164,    35,    35,   -26,   -26,   190,
     164,   164,  -202,  -202,  -202,  -202,   224,   102,  -202,  -202,
    -202,  -202,   172,  -202,  -202,    21,    21,  -202,   116,    44,
    -202,    74,  -202,  -202,  -202,  -202,    14,  -202,   -24,  -202,
     240,    28,   160,  -202,   225,  -202,   270,  -202,  -202,  -202,
    -202,   615,  -202,   615,   228,  -202,  -202,  -202,  -202,   178,
     227,   218,   218,   178,   271,   275,    19,  -202,  -202,  -202,
      20,   107,  -202,    21,  -202,  -202,  -202,  -202,  -202,   683,
     172,   188,   209,  -202,  -202,  -202,  -202,  -202,   178,  -202,
     227,   227,   218,   343,  -202,  -202,   343,  -202,  -202,  -202,
     267,   266,   270,  -202,   270,  -202,  -202,  -202,   227,  -202,
    -202,   178,  -202,  -202,  -202,  -202,  -202
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,   105,   109,   111,   114,   115,    10,    12,    11,
       0,     0,   112,   113,    64,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,   106,     0,
       2,     3,     6,     7,     0,     8,     9,    61,    67,    80,
      89,    59,    60,    58,    91,   100,    92,    19,    62,   129,
     130,     0,     0,     0,     0,    33,   105,     0,     0,     0,
      71,    91,     0,   124,    70,     0,   108,   110,   105,     0,
      91,     0,     0,     0,   135,     0,    87,    13,   152,     0,
       0,   116,     0,     1,     0,    42,     0,   101,     0,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,   154,   149,     0,
     138,   141,     0,   158,   117,   118,     0,   126,   101,    90,
       0,     0,     0,     0,     0,     0,    16,    18,    17,     0,
      95,     0,     0,     0,    94,     0,   134,     0,   153,     0,
       0,     0,     4,    45,     0,    39,    43,    46,    91,    44,
     142,   152,     0,    34,     0,     0,    49,    65,    66,    72,
      73,    76,    77,    78,    79,    81,    82,    83,    84,    85,
      74,    75,    86,    88,    22,    23,     0,   105,    98,    24,
      25,    99,   155,   139,   156,     0,     0,   150,     0,   154,
     160,     0,   119,   127,    68,    69,   105,   123,     0,   125,
     131,     0,     0,    63,     0,   136,    56,    51,   102,   103,
     104,    42,    38,    42,     0,    50,   145,   144,   137,     0,
      36,    34,    34,     0,    26,     0,     0,   157,   147,   148,
       0,     0,   140,     0,   159,   128,    15,    96,    97,     0,
      32,     0,     0,    53,    40,    41,   143,    35,     0,    28,
      36,    36,    34,     0,   120,   121,     0,   146,   151,   161,
       0,     0,    56,    52,    56,    37,    30,    29,    36,    27,
     122,     0,    57,    54,    55,    31,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,   154,   -51,   -68,  -202,   -76,     0,  -201,   -75,
     -50,  -202,   -87,  -202,  -202,   213,   -72,  -202,  -202,  -115,
     -12,   708,  -202,     6,   779,   277,  -202,  -202,    92,     4,
     -61,  -202,   -65,  -202,   171,   -39,  -202,  -202,  -202,  -202,
    -153,   -25,   -41,  -101,    68,  -202,    70,  -202,   156,   114,
     -57,  -202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,   140,    32,    33,    58,   230,   259,
      87,   154,   155,    88,    89,    90,    35,   217,   252,   253,
      36,    37,    59,    38,    39,    40,    41,    42,    43,    70,
      45,    46,    47,    62,    63,    53,    64,    65,    48,    75,
     164,    54,   227,   161,   228,   121,   197,   198,   147,   193,
      55,   201
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    81,   124,    69,    44,   144,    73,    74,   128,   153,
     120,   123,   233,   156,    61,   126,    60,   127,   199,   163,
     159,   148,    85,   117,   117,   132,   117,   187,   125,   103,
     260,   261,    49,   152,   -32,    71,   141,    49,   165,    50,
     118,   118,   106,   118,    50,   116,    68,    84,   206,   145,
     -32,   246,   188,    34,   226,   191,   116,    44,    86,   142,
     194,   278,    52,    60,   101,   102,   183,   149,   150,   122,
     151,   188,   146,   157,    21,   202,   119,   119,    52,   119,
     188,   200,    66,    67,    34,    34,    24,    25,    44,   158,
     103,    27,    52,    21,    28,    21,   231,   232,   243,   113,
     186,    72,   203,   106,   148,    24,    25,    24,    25,   192,
      27,   133,    27,    28,   134,    28,    56,    77,   282,   116,
      49,   244,   -32,   256,  -132,   195,    34,    50,    51,    78,
      44,   214,   196,   215,   254,   237,   255,   240,   208,    34,
     241,   210,   194,    44,   247,   153,    51,   153,   235,   156,
      52,   156,   130,   131,   238,   239,   159,   283,   159,   284,
      79,   257,   236,    21,    80,   262,    49,   245,   -32,   136,
     137,   138,    82,    50,    51,    24,    25,    91,    92,    83,
      27,    84,   139,    28,   264,   276,   277,   136,   137,   138,
     275,    99,   100,   101,   102,    15,    52,   266,   107,   135,
     139,   271,   269,   285,   -32,   136,   137,   138,    85,   157,
     265,   157,   279,   286,   129,   280,   251,   143,   139,   103,
      52,    34,   162,    34,   221,   158,   222,   158,   272,   223,
     273,   160,   106,   274,   212,    34,    86,   270,   213,    44,
     216,   224,   218,   219,    93,    94,    95,    96,    97,    98,
     108,   109,   110,   111,   112,   220,   229,   113,   106,    99,
     100,   101,   102,    34,  -133,   249,    34,    44,   114,   115,
      44,   234,   251,   250,   251,    -5,     1,   116,     2,     3,
       4,   258,     5,     6,     7,     8,     9,   103,   281,   263,
     104,   105,   162,   211,    -5,    10,    -5,    76,    -5,    -5,
     106,    51,   166,    11,   248,   209,    12,    13,   267,    14,
      15,   268,    16,   242,    17,     0,    18,   225,     0,     0,
       0,    19,     0,    20,     0,    21,    22,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,    24,    25,     0,
       0,    26,    27,    -5,     1,    28,     2,     3,     4,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    -5,    10,    -5,     0,    -5,    -5,     0,     0,
       0,    11,     0,     0,    12,    13,     0,    14,    15,     0,
      16,     0,    17,     0,    18,     0,     0,     0,     0,    19,
       0,    20,     0,    21,    22,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,    24,    25,     0,     0,    26,
      27,    -5,     1,    28,     2,     3,     4,     0,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,     0,     0,
      -5,    10,     0,     0,    -5,     0,     0,     0,     0,    11,
       0,     0,    12,    13,     0,    14,    15,     0,    16,     0,
      17,     0,    18,     0,     0,     0,     0,    19,     0,    20,
       0,    21,    22,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    24,    25,     0,     0,    26,    27,    -5,
       1,    28,     2,     3,     4,     0,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,    -5,    10,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      12,    13,     0,    14,    15,     0,    16,     0,    17,     0,
      18,     0,     0,     0,     0,    19,     0,    20,     0,    21,
      22,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    24,    25,     0,     0,    26,    27,     0,     1,    28,
       2,     3,     4,     0,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    -5,    10,     0,     0,
      -5,     0,     0,     0,     0,    11,     0,     0,    12,    13,
       0,    14,    15,     0,    16,     0,    17,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,    21,    22,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,    24,
      25,     0,     0,    26,    27,     0,     0,    28,     2,     3,
       4,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    12,    13,     0,    14,
      15,     0,    16,     0,    17,     0,    18,     0,     0,     0,
       0,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,    24,    25,     0,
       0,    26,    27,     0,     0,    28,    68,     3,     4,     0,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,    12,    13,     0,    14,    15,     0,
      16,     0,    17,     0,    18,     0,     0,     0,     0,    19,
       0,    20,     0,    21,    56,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     0,    24,    25,     0,     0,    26,
      27,    57,     0,    28,     0,     0,     0,     0,     0,    11,
       0,     0,    12,    13,     0,     0,     0,    68,     3,     4,
       0,     5,     6,     0,     0,     0,     0,     0,     0,    20,
       0,    21,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,    11,    24,    25,    12,    13,    26,    27,   167,
     168,    28,     0,     0,    68,     3,     4,     0,     5,     6,
       0,     0,    20,     0,    21,     0,     0,     0,   184,   185,
       0,    57,   189,   190,     0,     0,    24,    25,     0,    11,
      26,    27,    12,    13,    28,     0,     0,     0,   204,   205,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,    26,    27,     0,
       0,    28,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182
};

static const yytype_int16 yycheck[] =
{
       0,    26,    53,    15,     0,    73,    18,    19,    58,    85,
      51,    52,   165,    85,    10,    54,    10,    56,   119,    87,
      85,    78,    20,     3,     3,    49,     3,     3,    53,    55,
     231,   232,    18,    84,    20,    20,    49,    18,    88,    25,
      20,    20,    68,    20,    25,    69,     3,    19,     3,    24,
      20,    23,   113,    53,    34,   116,    69,    53,    56,    71,
     117,   262,    48,    57,    29,    30,   107,    79,    80,    46,
      82,   132,    47,    85,    50,   126,    56,    56,    48,    56,
     141,   122,     4,     5,    84,    85,    62,    63,    84,    85,
      55,    67,    48,    50,    70,    50,   164,   165,    24,    49,
     112,     3,   127,    68,   161,    62,    63,    62,    63,    65,
      67,    21,    67,    70,    24,    70,     3,     7,   271,    69,
      18,    47,    20,   224,    24,    18,   126,    25,    26,     3,
     126,   143,    25,   145,   221,   192,   223,    21,   134,   139,
      24,   135,   199,   139,   212,   221,    26,   223,   187,   221,
      48,   223,    52,    53,   195,   196,   221,   272,   223,   274,
      20,   229,   187,    50,    20,   233,    18,   206,    20,     9,
      10,    11,    20,    25,    26,    62,    63,    52,    53,     0,
      67,    19,    22,    70,   235,   260,   261,     9,    10,    11,
     258,    27,    28,    29,    30,    35,    48,   236,    33,    24,
      22,   251,   243,   278,    56,     9,    10,    11,    20,   221,
     235,   223,   263,   281,    21,   266,   216,    20,    22,    55,
      48,   221,    26,   223,    19,   221,    21,   223,    19,    24,
      21,     3,    68,    24,    36,   235,    56,   249,    21,   235,
      20,    49,    21,    21,    12,    13,    14,    15,    16,    17,
      42,    43,    44,    45,    46,    21,    38,    49,    68,    27,
      28,    29,    30,   263,    24,    40,   266,   263,    60,    61,
     266,    47,   272,     3,   274,     0,     1,    69,     3,     4,
       5,    54,     7,     8,     9,    10,    11,    55,    21,    18,
      58,    59,    26,   139,    19,    20,    21,    20,    23,    24,
      68,    26,    89,    28,   212,   134,    31,    32,   240,    34,
      35,   241,    37,   199,    39,    -1,    41,   161,    -1,    -1,
      -1,    46,    -1,    48,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,     0,     1,    70,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,    -1,
      -1,    28,    -1,    -1,    31,    32,    -1,    34,    35,    -1,
      37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,
      -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
      67,     0,     1,    70,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    31,    32,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,     0,
       1,    70,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      31,    32,    -1,    34,    35,    -1,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    -1,     1,    70,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    32,
      -1,    34,    35,    -1,    37,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    46,    -1,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    66,    67,    -1,    -1,    70,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    34,
      35,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    46,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    -1,    -1,    70,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    31,    32,    -1,    34,    35,    -1,
      37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,
      -1,    48,    -1,    50,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
      67,    20,    -1,    70,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    31,    32,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    62,    63,    31,    32,    66,    67,    91,
      92,    70,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,   110,   111,
      -1,    20,   114,   115,    -1,    -1,    62,    63,    -1,    28,
      66,    67,    31,    32,    70,    -1,    -1,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,    -1,
      -1,    70,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     7,     8,     9,    10,    11,
      20,    28,    31,    32,    34,    35,    37,    39,    41,    46,
      48,    50,    51,    56,    62,    63,    66,    67,    70,    72,
      73,    74,    76,    77,    78,    87,    91,    92,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   109,    18,
      25,    26,    48,   106,   112,   121,     3,    20,    78,    93,
      94,   100,   104,   105,   107,   108,     4,     5,     3,    91,
     100,    20,     3,    91,    91,   110,    96,     7,     3,    20,
      20,   112,    20,     0,    19,    20,    56,    81,    84,    85,
      86,    52,    53,    12,    13,    14,    15,    16,    17,    27,
      28,    29,    30,    55,    58,    59,    68,    33,    42,    43,
      44,    45,    46,    49,    60,    61,    69,     3,    20,    56,
     113,   116,    46,   113,    74,   112,   106,   106,    81,    21,
      52,    53,    49,    21,    24,    24,     9,    10,    11,    22,
      75,    49,    91,    20,    75,    24,    47,   119,   121,    91,
      91,    91,    74,    77,    82,    83,    87,    91,   100,   103,
       3,   114,    26,    75,   111,    81,    86,    92,    92,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,   113,    92,    92,    91,     3,   101,    92,
      92,   101,    65,   120,   121,    18,    25,   117,   118,   114,
     113,   122,    74,   112,    92,    92,     3,    92,   100,   105,
      94,    73,    36,    21,    91,    91,    20,    88,    21,    21,
      21,    19,    21,    24,    49,   119,    34,   113,   115,    38,
      79,    75,    75,   111,    47,   106,   112,   121,   113,   113,
      21,    24,   120,    24,    47,   106,    23,    75,    99,    40,
       3,    78,    89,    90,    83,    83,   114,    75,    54,    80,
      79,    79,    75,    18,    74,   112,   106,   115,   117,   113,
      91,    81,    19,    21,    24,    75,    80,    80,    79,    74,
      74,    21,   111,    90,    90,    80,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    82,    83,    83,    83,    83,    83,    84,    85,    85,
      86,    87,    88,    89,    89,    89,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    97,    98,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   106,
     106,   107,   108,   108,   109,   110,   110,   111,   112,   113,
     113,   113,   114,   114,   115,   115,   116,   117,   117,   118,
     118,   118,   119,   119,   120,   120,   120,   120,   121,   121,
     122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       2,     2,     3,     3,     3,     3,     4,     6,     5,     6,
       6,     7,     1,     2,     0,     2,     0,     2,     3,     1,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     3,     1,     3,     3,     0,     3,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       3,     1,     1,     8,     3,     3,     5,     5,     3,     3,
       1,     2,     4,     4,     4,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       5,     5,     6,     4,     1,     3,     2,     3,     4,     1,
       1,     3,     1,     3,     3,     1,     3,     2,     2,     2,
       3,     1,     1,     3,     1,     1,     4,     2,     2,     0,
       1,     3,     0,     1,     0,     1,     1,     2,     2,     4,
       1,     3
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
      yyerror (&yylloc, scanner, result, YY_("syntax error: cannot back up")); \
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
                  Type, Value, Location, scanner, result); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, CResult* result)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (result);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, CResult* result)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, result);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void *scanner, CResult* result)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, result);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, result); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *scanner, CResult* result)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (result);
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
yyparse (void *scanner, CResult* result)
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

    { result->block = std::shared_ptr<NBlock>((yyvsp[0].block)); }

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

    { (yyval.node) = nullptr; /* yyclearin; */ result->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }

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
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-4].typeName)->name.c_str(), (yyvsp[-4].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-3].exprvec)), 
							shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-4].typeName); 
					}

    break;

  case 29:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].typeName)->name.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-4].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-3].exprvec)), 
							shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 30:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-3].typeName)), (yyvsp[-5].typeName)->name.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 31:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-3].typeName)), (yyvsp[-6].typeName)->name.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 32:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[0].string)->c_str(), false); delete (yyvsp[0].string); }

    break;

  case 33:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

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

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 39:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 40:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 41:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 42:

    { (yyval.node) = nullptr; }

    break;

  case 46:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 47:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 48:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 49:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 50:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (string("#") + *(yyvsp[-1].string)).c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 51:

    { (yyval.node) = new NInterface(LOC, (string("#") + *(yyvsp[-2].string)).c_str(), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 52:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 53:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 54:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 55:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 56:

    { (yyval.node) = nullptr; }

    break;

  case 57:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].typeName)->name.c_str(), (yyvsp[-2].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 58:

    { (yyval.node) = (yyvsp[0].nif); }

    break;

  case 61:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 63:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 64:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 65:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 66:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 68:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 69:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 70:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 72:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::EQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 73:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::NE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 74:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PEQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 75:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PNE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 76:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 77:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 78:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 79:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 80:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 81:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 82:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 83:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 84:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 85:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mod, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 86:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 87:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 88:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 89:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 90:

    { (yyval.var) = (yyvsp[-1].var); }

    break;

  case 91:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 92:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 93:

    { (yyval.node) = new NFor(LOC, (yyvsp[-6].string)->c_str(), shared_ptr<NBase>((yyvsp[-4].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); delete (yyvsp[-6].string); }

    break;

  case 94:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 95:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 96:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 97:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].nif))); }

    break;

  case 98:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 99:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 101:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].typeName)->name.c_str(), (yyvsp[-1].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].typeName); }

    break;

  case 102:

    { (yyval.var) = new NIsEmpty(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 103:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 104:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 105:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 106:

    { (yyval.var) = new NParent(LOC); }

    break;

  case 107:

    { (yyval.var) = new NThis(LOC); }

    break;

  case 108:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 109:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 110:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 111:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 112:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 113:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 114:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 115:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 116:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 117:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 118:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].isMutable)); }

    break;

  case 119:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 120:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 121:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].isMutable)); }

    break;

  case 122:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 123:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 124:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 125:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 126:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].isMutable)); }

    break;

  case 127:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), (yyvsp[-1].isMutable)); }

    break;

  case 128:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].isMutable)); }

    break;

  case 129:

    { (yyval.isMutable) = true; }

    break;

  case 130:

    { (yyval.isMutable) = false; }

    break;

  case 131:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 132:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 133:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 134:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec))); }

    break;

  case 135:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 136:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 137:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 138:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 139:

    { (yyval.typeName) = new CTypeName(CTC_Value, *(yyvsp[-1].string) + ((yyvsp[0].optionAndTypeList).isOption ? "?" : ""), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 140:

    { (yyval.typeName) = new CTypeName(CTC_Interface, string("#") + *(yyvsp[-1].string) + ((yyvsp[0].optionAndTypeList).isOption ? "?" : ""), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 141:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 142:

    { (yyval.string) = (yyvsp[0].string); }

    break;

  case 143:

    { (yyval.string) = new string(*(yyvsp[-2].string) + "." + *(yyvsp[0].string)); }

    break;

  case 144:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 145:

    { (yyval.typeName) = new CTypeName(CTC_Value, "void", false); }

    break;

  case 146:

    { (yyval.typeName) = new CTypeName(shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 147:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTM_Mutable; }

    break;

  case 148:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTM_Immutable; }

    break;

  case 149:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 150:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 151:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 152:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 153:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 154:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 155:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 156:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 157:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 158:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 159:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 160:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 161:

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
      yyerror (&yylloc, scanner, result, YY_("syntax error"));
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
        yyerror (&yylloc, scanner, result, yymsgp);
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
                      yytoken, &yylval, &yylloc, scanner, result);
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
                  yystos[yystate], yyvsp, yylsp, scanner, result);
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
  yyerror (&yylloc, scanner, result, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, result);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, scanner, result);
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

