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
    TSTRING = 261,
    TCHAR = 262,
    TCBLOCK = 263,
    TCFUNCTION = 264,
    TCDEFINE = 265,
    TCSTRUCT = 266,
    TCINCLUDE = 267,
    TCVAR = 268,
    TCTYPEDEF = 269,
    TCEQ = 270,
    TCNE = 271,
    TCLT = 272,
    TCLE = 273,
    TCGT = 274,
    TCGE = 275,
    TEQUAL = 276,
    TEND = 277,
    TLPAREN = 278,
    TRPAREN = 279,
    TLBRACE = 280,
    TRBRACE = 281,
    TCOMMA = 282,
    TCOLON = 283,
    TQUOTE = 284,
    TPLUS = 285,
    TMINUS = 286,
    TMUL = 287,
    TDIV = 288,
    TTRUE = 289,
    TFALSE = 290,
    TAS = 291,
    TVOID = 292,
    TIF = 293,
    TELSE = 294,
    TTHROW = 295,
    TCATCH = 296,
    TFOR = 297,
    TTO = 298,
    TWHILE = 299,
    TPLUSPLUS = 300,
    TMINUSMINUS = 301,
    TPLUSEQUAL = 302,
    TMINUSEQUAL = 303,
    TLBRACKET = 304,
    TRBRACKET = 305,
    TEXCLAIM = 306,
    TDOT = 307,
    TTHIS = 308,
    TINCLUDE = 309,
    TAND = 310,
    TOR = 311,
    TCOPY = 312,
    TDESTROY = 313,
    TMOD = 314,
    THASH = 315,
    TCPEQ = 316,
    TCPNE = 317,
    TMULEQUAL = 318,
    TDIVEQUAL = 319,
    TISEMPTY = 320,
    TGETVALUE = 321,
    TQUESTION = 322,
    TEMPTY = 323,
    TVALUE = 324,
    TQUESTIONCOLON = 325,
    TQUESTIONDOT = 326,
    TPARENT = 327,
    TSTACK = 328,
    THEAP = 329,
    TLOCAL = 330,
    TTYPEI32 = 331,
    TTYPEU32 = 332,
    TTYPEF32 = 333,
    TTYPEI64 = 334,
    TTYPEU64 = 335,
    TTYPEF64 = 336,
    TTYPECHAR = 337,
    TTYPEBOOL = 338,
    TTYPEPTR = 339,
    TINVALID = 340,
    TCOLONEQUAL = 341,
    THEAPPARENT = 342,
    THEAPTHIS = 343
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
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   104,   105,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   123,   124,
     125,   126,   129,   130,   131,   132,   133,   134,   135,   136,
     139,   145,   150,   155,   162,   163,   166,   167,   170,   171,
     174,   175,   178,   179,   182,   183,   184,   185,   188,   189,
     190,   191,   192,   195,   198,   199,   202,   205,   208,   211,
     212,   213,   216,   217,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   233,   234,   235,   238,   239,
     240,   241,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     266,   267,   268,   271,   274,   277,   278,   279,   282,   283,
     284,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   309,
     310,   311,   312,   313,   314,   315,   318,   319,   322,   323,
     324,   327,   328,   329,   332,   333,   336,   339,   340,   343,
     346,   347,   350,   351,   354,   355,   356,   357,   360,   363,
     366,   367,   368,   369,   372,   373,   374,   375,   378,   379,
     382,   383,   384,   385,   386,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   400,   403,   404,   407,   408,   409,
     412,   413,   416,   417,   418,   419,   422,   423,   426,   427
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TINTEGER", "TDOUBLE",
  "TSTRING", "TCHAR", "TCBLOCK", "TCFUNCTION", "TCDEFINE", "TCSTRUCT",
  "TCINCLUDE", "TCVAR", "TCTYPEDEF", "TCEQ", "TCNE", "TCLT", "TCLE",
  "TCGT", "TCGE", "TEQUAL", "TEND", "TLPAREN", "TRPAREN", "TLBRACE",
  "TRBRACE", "TCOMMA", "TCOLON", "TQUOTE", "TPLUS", "TMINUS", "TMUL",
  "TDIV", "TTRUE", "TFALSE", "TAS", "TVOID", "TIF", "TELSE", "TTHROW",
  "TCATCH", "TFOR", "TTO", "TWHILE", "TPLUSPLUS", "TMINUSMINUS",
  "TPLUSEQUAL", "TMINUSEQUAL", "TLBRACKET", "TRBRACKET", "TEXCLAIM",
  "TDOT", "TTHIS", "TINCLUDE", "TAND", "TOR", "TCOPY", "TDESTROY", "TMOD",
  "THASH", "TCPEQ", "TCPNE", "TMULEQUAL", "TDIVEQUAL", "TISEMPTY",
  "TGETVALUE", "TQUESTION", "TEMPTY", "TVALUE", "TQUESTIONCOLON",
  "TQUESTIONDOT", "TPARENT", "TSTACK", "THEAP", "TLOCAL", "TTYPEI32",
  "TTYPEU32", "TTYPEF32", "TTYPEI64", "TTYPEU64", "TTYPEF64", "TTYPECHAR",
  "TTYPEBOOL", "TTYPEPTR", "TINVALID", "TCOLONEQUAL", "THEAPPARENT",
  "THEAPTHIS", "$accept", "program", "stmts", "stmt", "block", "var_decl",
  "func_decl", "func_type_name", "copy", "catch", "destroy", "func_block",
  "func_args", "func_arg", "implement", "implement_args", "implement_arg",
  "interface_decl", "interface_block", "interface_args", "interface_arg",
  "expr", "expr_and", "expr_and_inner", "expr_comp", "expr_math",
  "expr_var", "for_expr", "while_expr", "if_expr", "var", "var_right",
  "const", "assign", "assign_tuple", "assign_tuple_arg", "assign_type",
  "assign_copy", "tuple", "tuple_args", "array", "end_optional",
  "end_star", "array_args", "return_type_quote", "arg_type_quote",
  "arg_type", "arg_mode", "arg_type_interface", "return_type",
  "value_type", "func_type", "func_arg_type", "func_arg_type_list",
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
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

#define YYPACT_NINF -243

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-243)))

#define YYTABLE_NINF -149

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     590,  -243,    19,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,   491,   162,  -243,  -243,  -243,   952,     3,
      64,   952,    70,  1007,  -243,    16,    97,    90,   104,   110,
     122,  -243,   952,   952,   952,  -243,  -243,   161,   159,  -243,
    -243,  -243,    21,  -243,  -243,  -243,   171,  1031,   157,  -243,
    -243,  -243,  1082,  -243,  -243,  -243,  -243,   142,   142,  1095,
    1042,   142,   323,    33,  -243,    25,   580,   181,   197,   127,
      50,   117,  -243,  -243,   201,  -243,  -243,   178,   331,   100,
     952,   212,   331,    70,   952,  -243,  -243,   124,  -243,   178,
     952,   952,  -243,   952,  -243,  -243,  -243,  -243,   501,   167,
     230,   280,   181,   176,  -243,   580,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   580,   580,
     580,  1095,  -243,  -243,   580,   580,   952,   177,   580,   580,
     208,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,    49,  -243,  -243,
    1095,  -243,  -243,  -243,  -243,   412,   110,  -243,  -243,   580,
     580,   210,   580,   313,   580,  -243,  -243,  -243,   678,   199,
     952,   208,   216,   952,  -243,  -243,  -243,    51,   225,  -243,
     226,   228,   229,  -243,  -243,   824,   205,   178,  1029,   217,
     331,   280,  -243,  -243,  -243,    -2,    -2,    -2,    -2,    -2,
      -2,    92,    92,     7,     7,   189,    -2,    -2,  -243,  -243,
    -243,  -243,   218,    19,  -243,  -243,  -243,  -243,    28,    -1,
     230,  -243,    37,  -243,  -243,  -243,  -243,    25,  -243,    50,
    -243,   235,   114,   261,   222,  -243,   238,   897,   234,   952,
     275,  -243,  -243,  -243,  -243,  -243,  -243,   101,  -243,  -243,
    -243,   123,  -243,   230,  -243,  -243,    52,  -243,  -243,  -243,
     331,   244,   217,   217,   331,   266,   323,    33,   178,  -243,
    -243,  1095,  1095,  -243,   179,    28,  1095,  -243,  -243,  -243,
    -243,  -243,  -243,   952,  -243,   952,  -243,  -243,   181,    47,
    -243,   751,   287,   824,  -243,    28,   230,  -243,   331,   254,
     244,   244,   217,   412,  -243,  -243,   412,  -243,  -243,  -243,
    1029,    -1,  -243,  -243,   289,  -243,   285,   275,  -243,   275,
    -243,   824,  -243,  -243,  -243,    28,  -243,   331,  -243,   254,
     254,   244,  -243,  -243,  -243,  -243,   331,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,   254,  -243,  -243
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    34,   121,   123,   126,   127,    10,    13,    11,
      12,    14,    15,     0,     0,   124,   125,    74,     0,     0,
       0,     0,   150,     0,   117,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,   118,   119,     0,     2,     3,
       6,     7,   115,     8,     9,    67,    77,    90,    99,    65,
      66,    64,   101,   110,   102,    22,    68,   144,   144,   164,
     164,   144,     0,     0,    35,    34,     0,   115,     0,    81,
     101,     0,   136,    80,     0,   120,   122,    34,     0,   101,
       0,     0,     0,   152,     0,   151,    97,   101,    16,   190,
       0,     0,   128,     0,    70,    72,    71,     1,     0,   150,
       0,   111,     0,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,    23,    24,     0,     0,     0,     0,     0,     0,
       0,   145,   141,   143,   166,   167,   165,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   159,     0,   160,   163,
     164,   196,   142,   129,   130,     0,   138,   111,   100,     0,
       0,     0,     0,     0,     0,    19,    21,    20,     0,   105,
       0,     0,     0,     0,   104,   153,   154,   150,     0,   191,
       0,     0,     0,     4,    43,     0,   168,   190,   164,    38,
       0,     0,    55,    75,    76,    82,    83,    86,    87,    88,
      89,    91,    92,    93,    94,    95,    84,    85,    96,    98,
      25,    26,     0,    34,   108,    27,    28,   109,   192,   187,
       0,   198,     0,   131,   139,    78,    79,    34,   135,     0,
     137,   146,     0,     0,     0,    69,     0,     0,     0,   151,
      62,    57,   112,   113,   114,    51,    50,   150,    44,    48,
      52,   101,    49,     0,    56,   174,     0,   158,   170,   173,
       0,    36,    38,    38,     0,    73,     0,     0,   193,   161,
     194,   164,   164,   188,     0,   192,   164,   197,   140,    18,
     106,   107,    73,     0,   157,     0,   149,   155,     0,     0,
      59,     0,     0,   151,   169,   192,     0,    39,     0,    40,
      36,    36,    38,     0,   132,   133,     0,   195,   186,   185,
     164,     0,   162,   199,     0,   156,     0,    62,    58,    62,
      47,     0,    42,    45,   171,   192,    37,     0,    30,    40,
      40,    36,    29,   134,   184,   189,     0,    63,    60,    61,
      46,   172,    41,    32,    31,    40,   103,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,   147,   -59,   -76,  -243,  -171,     1,  -242,  -220,
    -121,   -65,  -243,  -175,  -243,  -243,   214,  -162,  -243,  -243,
    -107,    17,    72,  -243,    -6,  1047,   296,  -243,  -243,   103,
       0,   -24,  -243,  -161,  -243,   180,   -48,   156,  -243,  -243,
    -243,   -94,   -73,  -243,  -182,   -21,   -56,  -177,  -208,    15,
    -172,  -168,    31,  -243,   164,  -239,   -70,  -243
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    37,    38,    39,   169,    40,    41,    67,   299,   261,
     328,   101,   247,   248,   102,   103,   104,    43,   241,   289,
     290,    44,    45,    68,    46,    47,    48,    49,    50,    51,
      87,    53,    54,    55,    71,    72,    62,   132,    73,    74,
      56,    84,    85,   177,   190,    63,   146,   147,   187,   257,
     148,   149,   273,   274,   178,   269,    64,   222
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    42,   157,   153,   151,   185,   174,    69,    92,   264,
     175,   256,   275,    70,   246,   155,   258,   156,    79,   179,
     259,    79,    88,   249,   252,   189,    80,   271,   113,   114,
     115,   116,    79,    79,    79,    78,   312,   191,    82,   183,
      57,   154,   300,   301,    99,   294,    57,    58,    59,    94,
      95,    96,   218,    58,    57,   295,   324,   117,   329,   330,
      69,    58,    52,    42,   276,   209,   117,    81,   120,   317,
      60,   318,   219,    83,   319,   219,    60,   120,   237,    60,
      79,   100,   331,   238,    79,   272,   341,   277,   325,   345,
      79,    79,    83,    79,   221,   268,   223,   172,    52,    42,
      89,   176,   161,   214,   239,    61,   217,   180,   181,   220,
     182,    61,   296,    90,   262,   263,   320,   179,   323,    61,
     246,   130,   246,    83,   115,   116,    79,    91,   291,   249,
     252,   249,   252,   256,   337,   224,    98,   214,   258,    59,
     279,   162,   259,   212,   163,    93,   340,   214,   270,   170,
     246,   117,   171,   292,  -147,    52,    42,   280,   231,   249,
     252,    97,   120,   229,   285,   266,    75,    76,    52,    42,
      79,   130,   170,    79,   293,   127,   171,   193,   194,   278,
     213,    98,   159,   160,   297,   251,    42,   234,   302,    83,
     236,   184,   267,   121,   130,   130,   210,   211,   307,   131,
     215,   216,   250,   310,    99,   270,   311,   304,   343,   344,
     338,    77,   339,   227,   133,   308,   309,   152,   321,   306,
     313,   158,   326,   316,   347,   270,   105,   106,   164,    60,
      24,   225,   226,   186,   228,   173,   100,    79,   233,    79,
     235,   288,    27,    28,   332,   305,    30,   333,   240,    31,
     242,   342,   243,   244,   284,   270,   287,   253,   260,   120,
     346,    24,  -148,    24,    35,    36,    52,    42,   265,   165,
     166,   167,   282,    27,    28,    27,    28,    30,    77,    30,
      31,   283,    31,    79,   286,    79,   168,   303,   165,   166,
     167,   251,    42,   251,    42,    35,    36,    35,    36,    18,
     314,   298,   315,    52,    42,   168,    52,    42,   250,   188,
     250,   322,   327,   336,   188,   232,    65,   192,   288,    86,
     288,   251,    42,    -5,     1,   334,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   281,    12,   250,   165,
     166,   167,   335,   230,     0,    -5,    13,    -5,     0,    -5,
      -5,   254,    59,     0,    14,     0,   168,    15,    16,     0,
      17,    18,     0,    19,     0,    20,    24,    21,     0,     0,
       0,     0,    22,     0,    23,     0,    24,    25,    27,    28,
       0,     0,    30,    26,     0,    31,     0,     0,    27,    28,
       0,    29,    30,     0,     0,    31,    32,    33,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    -5,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
       0,     0,     0,     0,    -5,    13,    -5,     0,    -5,    -5,
       0,     0,     0,    14,     0,     0,    15,    16,     0,    17,
      18,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,    22,     0,    23,     0,    24,    25,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,    27,    28,     0,
      29,    30,     0,     0,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,    65,     3,     4,     5,     6,    35,
      36,    -5,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    66,    12,     0,     0,     0,     0,
       0,     0,    14,    -5,    13,    15,    16,    -5,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,    17,    18,
       0,    19,    23,    20,    24,    21,     0,     0,     0,     0,
      22,     0,    23,     0,    24,    25,    27,    28,     0,    29,
      30,    26,     0,    31,     0,     0,    27,    28,     0,    29,
      30,     0,     0,    31,    32,    33,    34,     0,    35,    36,
       0,     0,     0,    77,     3,     4,     5,     6,    35,    36,
      -5,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    66,    12,     0,     0,     0,     0,     0,
       0,    14,    -5,    13,    15,    16,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     0,    17,    18,     0,
      19,    23,    20,    24,    21,     0,     0,     0,     0,    22,
       0,    23,     0,    24,    25,    27,    28,     0,    29,    30,
      26,     0,    31,     0,     0,    27,    28,     0,    29,    30,
       0,     0,    31,    32,    33,    34,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    36,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      -5,    13,     0,     0,    -5,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,    25,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,    27,    28,     0,    29,    30,     0,     0,
      31,    32,    33,    34,     2,     3,     4,     5,     6,     0,
       0,     0,     0,     0,   245,    35,    36,     0,     0,     0,
       0,     0,     0,    83,    13,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,    17,    18,
       0,    19,     0,    20,     0,    21,     0,     0,     0,     0,
      22,     0,    23,     0,    24,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,    27,    28,     0,    29,
      30,     0,     0,    31,    32,    33,    34,     2,     3,     4,
       5,     6,     0,     0,     0,     0,     0,   245,    35,    36,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
       0,    17,    18,     0,    19,     0,    20,     0,    21,     0,
       0,     0,     0,    22,     0,    23,     0,    24,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,    27,
      28,     0,    29,    30,     0,     0,    31,    32,    33,    34,
      77,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,    83,
      66,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,    17,    18,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,    22,     0,    23,     0,
      24,     0,     0,     0,     0,    77,     3,     4,     5,     6,
       0,     0,    27,    28,     0,    29,    30,     0,     0,    31,
      32,    33,    34,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,    14,    35,    36,    15,    16,     0,    17,
      18,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,    22,     0,    23,     0,    24,     0,     0,     0,     0,
      77,     3,     4,     5,     6,     0,     0,    27,    28,     0,
      29,    30,     0,     0,    31,    32,    33,    34,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,    14,    35,
      36,    15,    16,     0,     0,     0,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
      24,   113,   114,   115,   116,     0,   255,     0,     0,     0,
       0,     0,    27,    28,     0,    29,    30,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   150,   118,   119,    35,    36,     0,     0,     0,     0,
       0,   120,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   122,   123,   124,
     125,   126,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,     0,     0,   130,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145
};

static const yytype_int16 yycheck[] =
{
       0,     0,    67,    62,    60,    99,    82,    13,    29,   191,
      83,   188,   220,    13,   185,    63,   188,    65,    18,    89,
     188,    21,     6,   185,   185,   101,    23,    28,    30,    31,
      32,    33,    32,    33,    34,    18,   275,   102,    21,    98,
      21,    62,   262,   263,    23,   253,    21,    28,    29,    32,
      33,    34,     3,    28,    21,     3,   295,    59,   300,   301,
      66,    28,    62,    62,    27,   121,    59,     3,    70,    22,
      51,    24,    23,    22,    27,    23,    51,    70,    27,    51,
      80,    60,   302,   177,    84,    86,   325,    50,   296,   331,
      90,    91,    22,    93,   150,    67,   155,    80,    98,    98,
       3,    84,    52,   127,   177,    86,   130,    90,    91,    60,
      93,    86,    60,    23,   190,   191,   291,   187,   293,    86,
     291,    71,   293,    22,    32,    33,   126,    23,    27,   291,
     291,   293,   293,   310,   316,   156,    22,   161,   310,    29,
      26,    24,   310,   126,    27,    23,   321,   171,   218,    49,
     321,    59,    52,   247,    27,   155,   155,   233,   164,   321,
     321,     0,    70,   163,   237,   213,     4,     5,   168,   168,
     170,    71,    49,   173,   247,    52,    52,   105,   106,   227,
       3,    22,    55,    56,   260,   185,   185,   170,   264,    22,
     173,    24,   213,    36,    71,    71,   124,   125,   268,    57,
     128,   129,   185,    24,    23,   275,    27,   266,   329,   330,
     317,     3,   319,     3,    58,   271,   272,    61,   291,   267,
     276,    24,   298,   288,   345,   295,    55,    56,    27,    51,
      53,   159,   160,     3,   162,    23,    60,   237,    39,   239,
      24,   240,    65,    66,   303,   266,    69,   306,    23,    72,
      24,   327,    24,    24,   237,   325,   239,    52,    41,    70,
     336,    53,    27,    53,    87,    88,   266,   266,    50,     8,
       9,    10,    50,    65,    66,    65,    66,    69,     3,    69,
      72,    43,    72,   283,    50,   285,    25,    21,     8,     9,
      10,   291,   291,   293,   293,    87,    88,    87,    88,    38,
     283,    57,   285,   303,   303,    25,   306,   306,   291,    29,
     293,    24,    58,    24,    29,   168,     3,   103,   317,    23,
     319,   321,   321,     0,     1,   310,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   233,    14,   321,     8,
       9,    10,   311,   163,    -1,    22,    23,    24,    -1,    26,
      27,   187,    29,    -1,    31,    -1,    25,    34,    35,    -1,
      37,    38,    -1,    40,    -1,    42,    53,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    -1,    53,    54,    65,    66,
      -1,    -1,    69,    60,    -1,    72,    -1,    -1,    65,    66,
      -1,    68,    69,    -1,    -1,    72,    73,    74,    75,    -1,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    87,
      88,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    23,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    22,    23,    34,    35,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    37,    38,
      -1,    40,    51,    42,    53,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    -1,    53,    54,    65,    66,    -1,    68,
      69,    60,    -1,    72,    -1,    -1,    65,    66,    -1,    68,
      69,    -1,    -1,    72,    73,    74,    75,    -1,    87,    88,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    87,    88,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    23,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    22,    23,    34,    35,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    51,    42,    53,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    54,    65,    66,    -1,    68,    69,
      60,    -1,    72,    -1,    -1,    65,    66,    -1,    68,    69,
      -1,    -1,    72,    73,    74,    75,    -1,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    37,    38,
      -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    -1,    -1,    72,    73,    74,    75,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,    37,    38,    -1,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    65,
      66,    -1,    68,    69,    -1,    -1,    72,    73,    74,    75,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      53,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,
      73,    74,    75,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    87,    88,    34,    35,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    65,    66,    -1,
      68,    69,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    87,
      88,    34,    35,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    30,    31,    32,    33,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    49,    61,    62,    87,    88,    -1,    -1,    -1,    -1,
      -1,    70,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    45,    46,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    23,    31,    34,    35,    37,    38,    40,
      42,    44,    49,    51,    53,    54,    60,    65,    66,    68,
      69,    72,    73,    74,    75,    87,    88,    90,    91,    92,
      94,    95,    96,   106,   110,   111,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   129,    21,    28,    29,
      51,    86,   125,   134,   145,     3,    23,    96,   112,   113,
     119,   123,   124,   127,   128,     4,     5,     3,   110,   119,
      23,     3,   110,    22,   130,   131,   115,   119,     6,     3,
      23,    23,   134,    23,   110,   110,   110,     0,    22,    23,
      60,   100,   103,   104,   105,    55,    56,    15,    16,    17,
      18,    19,    20,    30,    31,    32,    33,    59,    61,    62,
      70,    36,    45,    46,    47,    48,    49,    52,    63,    64,
      71,    57,   126,   126,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   135,   136,   139,   140,
      49,   135,   126,    92,   134,   125,   125,   100,    24,    55,
      56,    52,    24,    27,    27,     8,     9,    10,    25,    93,
      49,    52,   110,    23,    93,   131,   110,   132,   143,   145,
     110,   110,   110,    92,    24,   130,     3,   137,    29,    93,
     133,   100,   105,   111,   111,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   135,
     111,   111,   110,     3,   120,   111,   111,   120,     3,    23,
      60,   135,   146,    92,   134,   111,   111,     3,   111,   119,
     124,   113,    91,    39,   110,    24,   110,    27,   130,   131,
      23,   107,    24,    24,    24,    13,    95,   101,   102,   106,
     110,   119,   122,    52,   143,    37,   136,   138,   139,   140,
      41,    98,    93,    93,   133,    50,   125,   134,    67,   144,
     145,    28,    86,   141,   142,   137,    27,    50,   125,    26,
      93,   118,    50,    43,   110,   131,    50,   110,    96,   108,
     109,    27,   130,   131,   137,     3,    60,    93,    57,    97,
      98,    98,    93,    21,    92,   134,   125,   145,   135,   135,
      24,    27,   144,   135,   110,   110,   100,    22,    24,    27,
     102,   131,    24,   102,   144,   137,    93,    58,    99,    97,
      97,    98,    92,    92,   138,   141,    24,   133,   109,   109,
     102,   144,    93,    99,    99,    97,    93,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   103,   104,   104,   105,   106,   107,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   112,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   116,   117,   118,   118,   118,   119,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   125,   126,   126,   127,   128,   128,   129,
     130,   130,   131,   131,   132,   132,   132,   132,   133,   134,
     135,   135,   135,   135,   136,   136,   136,   136,   137,   137,
     138,   138,   138,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   141,   141,   142,   142,   142,
     143,   143,   144,   144,   144,   144,   145,   145,   146,   146
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     6,
       6,     7,     7,     8,     1,     2,     0,     2,     0,     2,
       0,     2,     5,     2,     1,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     1,
       3,     3,     0,     3,     1,     1,     1,     1,     1,     4,
       2,     2,     2,     4,     1,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       3,     1,     1,     8,     3,     3,     5,     5,     3,     3,
       1,     2,     4,     4,     4,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     2,     3,
       3,     4,     5,     5,     6,     4,     1,     3,     2,     3,
       4,     2,     2,     2,     0,     1,     3,     1,     3,     5,
       0,     1,     1,     2,     1,     3,     4,     3,     2,     2,
       1,     3,     4,     1,     0,     1,     1,     1,     1,     3,
       1,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     2,     2,     0,     1,     3,
       0,     1,     0,     1,     1,     2,     2,     4,     1,     3
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

    { (yyval.node) = new NCCode(LOC, NCC_STRUCT, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 13:

    { (yyval.node) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 14:

    { (yyval.node) = new NCCode(LOC, NCC_INCLUDE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 15:

    { (yyval.node) = new NCCode(LOC, NCC_TYPEDEF, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 16:

    { (yyval.node) = new NInclude(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 17:

    { (yyval.node) = nullptr; /* yyclearin; */ compiler->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }

    break;

  case 18:

    { (yyval.node) = (yyvsp[-1].block); }

    break;

  case 19:

    { (yyval.node) = new NCCode(LOC, NCC_BLOCK, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 20:

    { (yyval.node) = new NCCode(LOC, NCC_DEFINE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 21:

    { (yyval.node) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 23:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Inc, nullptr); }

    break;

  case 24:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Dec, nullptr); }

    break;

  case 25:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 26:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 27:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 28:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 29:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), make_shared<NCall>(LOC, "setAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[0].node))))); }

    break;

  case 30:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].typeName)->valueName.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-5].typeName); 
					}

    break;

  case 31:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 32:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 33:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-7].typeName)->valueName.c_str(), (yyvsp[-7].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-6].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 34:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, (yyvsp[0].string)->c_str(), false); delete (yyvsp[0].string); }

    break;

  case 35:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

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

    { (yyval.node) = nullptr; }

    break;

  case 41:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 42:

    { (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 43:

    { (yyval.exprvec) = new NodeList(); }

    break;

  case 44:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 45:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 46:

    { if ((yyvsp[-1].node)) { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 47:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 51:

    { (yyval.node) = new NCCode(LOC, NCC_VAR, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 52:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 53:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 54:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 55:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 56:

    { (yyval.typeName) = new CTypeName(CTC_Interface, CTM_Stack, *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 57:

    { (yyval.node) = new NInterface(LOC, *(yyvsp[-2].string), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 58:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 59:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 60:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 61:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 62:

    { (yyval.node) = nullptr; }

    break;

  case 63:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].typeName)->valueName.c_str(), (yyvsp[-2].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 64:

    { (yyval.node) = (yyvsp[0].nif); }

    break;

  case 67:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 69:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 70:

    { (yyval.node) = new NChangeMode(LOC, CTM_Stack, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 71:

    { (yyval.node) = new NChangeMode(LOC, CTM_Local, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 72:

    { (yyval.node) = new NChangeMode(LOC, CTM_Heap, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 73:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 74:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 75:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 76:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 78:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 79:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 80:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 82:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::EQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 83:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::NE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 84:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PEQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 85:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PNE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 86:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 87:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 88:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 89:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 90:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 91:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 92:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 93:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 94:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 95:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mod, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 96:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 97:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 98:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 99:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 100:

    { (yyval.var) = (yyvsp[-1].var); }

    break;

  case 101:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 102:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 103:

    { (yyval.node) = new NFor(LOC, (yyvsp[-6].string)->c_str(), shared_ptr<NBase>((yyvsp[-4].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); delete (yyvsp[-6].string); }

    break;

  case 104:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 105:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 106:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 107:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].nif))); }

    break;

  case 108:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 109:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 111:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].typeName)->valueName.c_str(), (yyvsp[-1].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].typeName); }

    break;

  case 112:

    { (yyval.var) = new NIsEmpty(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 113:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 114:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 115:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].typeName)->valueName.c_str(), (yyvsp[0].typeName)->templateTypeNames); delete (yyvsp[0].typeName); }

    break;

  case 116:

    { (yyval.var) = new NParent(LOC, false); }

    break;

  case 117:

    { (yyval.var) = new NThis(LOC, false); }

    break;

  case 118:

    { (yyval.var) = new NParent(LOC, true); }

    break;

  case 119:

    { (yyval.var) = new NThis(LOC, true); }

    break;

  case 120:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 121:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 122:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 123:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 124:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 125:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 126:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 127:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 128:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 129:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 130:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 131:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 132:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 133:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 134:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 135:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 136:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 137:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 138:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 139:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), (yyvsp[-1].assignOp)); }

    break;

  case 140:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 141:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).isMutable = true; (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 142:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).isMutable = true; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 143:

    { (yyval.assignOp) = (yyvsp[0].assignOp); (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 144:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; }

    break;

  case 145:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined;  }

    break;

  case 146:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 147:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 148:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 149:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 150:

    { (yyval.node) = nullptr; }

    break;

  case 151:

    { (yyval.node) = nullptr; }

    break;

  case 152:

    { (yyval.node) = nullptr; }

    break;

  case 153:

    { (yyval.node) = nullptr; }

    break;

  case 154:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 155:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 156:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 157:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 158:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 159:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 160:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 161:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-2].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 162:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-3].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 163:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 164:

    { (yyval.typeMode) = CTM_Undefined; }

    break;

  case 165:

    { (yyval.typeMode) = CTM_Local; }

    break;

  case 166:

    { (yyval.typeMode) = CTM_Stack; }

    break;

  case 167:

    { (yyval.typeMode) = CTM_Heap; }

    break;

  case 168:

    { (yyval.string) = (yyvsp[0].string); }

    break;

  case 169:

    { (yyval.string) = new string(*(yyvsp[-2].string) + "." + *(yyvsp[0].string)); }

    break;

  case 170:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 171:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-2].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 172:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-3].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 173:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 174:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, "void", false); }

    break;

  case 175:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "i32", false); }

    break;

  case 176:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "u32", false); }

    break;

  case 177:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "f32", false); }

    break;

  case 178:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "i64", false); }

    break;

  case 179:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "u64", false); }

    break;

  case 180:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "f64", false); }

    break;

  case 181:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "char", false); }

    break;

  case 182:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "bool", false); }

    break;

  case 183:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "ptr", false); }

    break;

  case 184:

    { (yyval.typeName) = new CTypeName((yyvsp[-4].typeMode), shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 185:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Mutable; }

    break;

  case 186:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Immutable; }

    break;

  case 187:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 188:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 189:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 190:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 191:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 192:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 193:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 194:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 195:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 196:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 197:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 198:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 199:

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

