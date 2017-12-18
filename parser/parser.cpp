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

#define LOC CLoc(parseFile->fullFileName, parseFile->shortFileName, yyloc.first_line, yyloc.first_column)
#define LLOC CLoc(parseFile->fullFileName, parseFile->shortFileName, yylloc.first_line, yylloc.first_column)

int yyerror(YYLTYPE *locp, void *scanner, Compiler* compiler, CParseFile* parseFile, const char *msg) {
  if (locp) {
  	compiler->addWarning(CLoc(parseFile->fullFileName, parseFile->shortFileName, locp->first_line, locp->first_column), CErrorCode::Parser, msg);
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
    THEAPTHIS = 343,
    TIFVALUE = 344,
    TELSEEMPTY = 345,
    TTOREVERSE = 346,
    TENUM = 347,
    TSWITCH = 348,
    TCASE = 349,
    TDEFAULT = 350,
    TPACKAGE = 351,
    TIMPORT = 352,
    TUNDERSCORE = 353,
    TNULLPTR = 354
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


	NBase* node;
	NBlock* block;
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
	EnumArg* enumArg;
	EnumArgs* enumArgs;
	std::vector<std::string>* strings;
	std::vector<std::pair<std::string, std::vector<std::string>>>* import_namespaces;
	std::pair<std::string, std::vector<std::string>>* import_namespace;
	NCCode* ccode;
	CTypeNameParts* typeNameParts;
	vector<shared_ptr<NSwitchClause>>* switchClauses;
	NSwitchClause* switchClause;


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
#define YYFINAL  122
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  428

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   354

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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   120,   121,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   142,   143,   146,   147,   150,   151,   154,   155,   158,
     159,   162,   163,   166,   167,   170,   171,   172,   175,   176,
     179,   180,   183,   186,   187,   188,   189,   190,   191,   192,
     193,   196,   199,   200,   201,   204,   205,   208,   214,   219,
     224,   231,   232,   235,   236,   239,   240,   243,   244,   247,
     248,   251,   252,   253,   254,   257,   258,   259,   260,   261,
     264,   267,   268,   271,   274,   277,   280,   281,   282,   285,
     286,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   305,   306,   307,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   321,   322,   323,
     324,   325,   326,   327,   330,   331,   332,   333,   334,   337,
     338,   341,   344,   345,   348,   349,   352,   353,   356,   357,
     358,   359,   360,   363,   364,   367,   368,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   396,   397,
     398,   399,   400,   401,   402,   405,   406,   409,   410,   413,
     414,   415,   416,   417,   418,   421,   422,   423,   426,   429,
     430,   433,   436,   437,   440,   441,   444,   445,   446,   447,
     450,   453,   456,   457,   458,   461,   462,   463,   464,   467,
     468,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     482,   485,   486,   489,   490,   491,   494,   495,   498,   499,
     502,   503,   506,   509,   510,   513,   514,   515,   516,   519,
     520,   523,   524
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
  "THEAPTHIS", "TIFVALUE", "TELSEEMPTY", "TTOREVERSE", "TENUM", "TSWITCH",
  "TCASE", "TDEFAULT", "TPACKAGE", "TIMPORT", "TUNDERSCORE", "TNULLPTR",
  "$accept", "program", "stmts", "stmt", "cblock", "cdefine", "cstruct",
  "cfunction", "cinclude", "ctypedef", "cvar", "import_namespaces",
  "import_namespace", "namespace", "block", "var_decl", "enum_decl",
  "enum_args", "enum_arg", "func_decl", "func_type_name", "copy", "catch",
  "destroy", "func_block", "func_args", "func_arg", "implement",
  "implement_args", "implement_arg", "interface_decl", "interface_block",
  "interface_args", "interface_arg", "expr", "expr_and", "expr_comp",
  "expr_math", "expr_var", "for_expr", "while_expr", "switch_expr",
  "switch_clauses", "switch_clause", "if_expr", "ifValue_vars",
  "ifValue_var", "var_right", "const", "assign", "assign_tuple",
  "assign_tuple_arg", "assign_tuple_type", "assign_type", "tuple",
  "tuple_args", "array", "end_optional", "end_star", "array_args",
  "return_type_quote", "arg_type_quote", "arg_type", "arg_mode",
  "return_type", "value_type", "func_type", "func_arg_type",
  "func_arg_type_list", "temp_block_optional", "namespace_hash",
  "namespace_dot", "namespace_ident", "namespace_last",
  "temp_option_optional", "temp_block", "temp_args", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354
};
# endif

#define YYPACT_NINF -338

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-338)))

#define YYTABLE_NINF -190

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     738,  -338,    12,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  1285,  1436,  -338,  -338,  -338,  1358,     3,
      15,  1358,    21,  1436,  -338,    45,  1358,    68,    74,    91,
      76,    98,  -338,  1358,  1358,  1358,  -338,  -338,   168,   213,
    1065,   223,    21,  -338,  -338,   180,   214,  -338,   234,   236,
     237,   250,   251,   254,  -338,  -338,  -338,    24,  -338,  -338,
    -338,   106,   291,   324,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  1581,  1545,  -338,   438,    -9,
    -338,    -6,  1358,   242,   245,    19,    82,   108,  -338,   246,
     221,  1358,  -338,   253,   181,  1358,   257,   253,    21,  1358,
    -338,    49,  -338,  -338,   221,  1358,  1358,  -338,  1358,  -338,
    -338,  -338,    10,  -338,   163,  -338,   263,    21,   264,  -338,
      63,   285,  -338,   638,  -338,  -338,  -338,  -338,  -338,  -338,
     177,   223,   104,   242,   230,  -338,  1431,  1431,  1431,  1431,
    1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,
    1431,  1581,  -338,  -338,  1431,  1431,  1358,  1508,  1431,  1431,
    1436,  1436,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,    29,  -338,  -338,  1581,  -338,
    -338,  -338,   538,   235,   238,   239,  -338,  -338,  -338,  1358,
    1544,  1358,  1580,  1431,   837,   258,  1436,   269,  1358,  -338,
    -338,  -338,    89,   278,  -338,   280,   281,   288,  1358,   168,
     212,    21,  1138,    21,   310,  -338,   289,    95,  -338,   266,
    -338,  -338,   988,   187,   342,   275,   253,   104,  -338,  -338,
      49,  -338,    35,    35,    35,    35,    35,    35,    67,    67,
     267,   267,  -338,    35,    35,  -338,  -338,  -338,   277,    12,
    -338,  -338,  -338,  -338,  -338,   273,   -14,   325,     9,    13,
     326,  -338,  -338,    -2,  -338,  -338,  -338,  -338,   282,    -6,
    -338,   179,  -338,   306,    32,    -8,  -338,   -22,  1212,   301,
    1358,   328,  -338,  -338,  -338,  -338,  -338,  -338,   253,   352,
     253,   253,    21,  -338,  1138,  -338,   223,   285,   253,   285,
    -338,   343,  -338,   157,  -338,  -338,  -338,   204,  -338,  -338,
    -338,  -338,  -338,   253,   300,   275,   275,   253,   337,   438,
      -9,  -338,  1581,  1581,  -338,   145,  -338,   221,  -338,  -338,
    -338,  -338,   273,  -338,  1581,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  1358,  1358,  -338,  1358,  -338,  -338,   242,   154,
    -338,  -338,   331,   164,  -338,  -338,  -338,   335,  1138,    21,
     266,  -338,  -338,  -338,  -338,   915,   338,   988,  -338,   253,
     322,   300,   300,   275,   538,  -338,  -338,   538,  -338,  -338,
     342,   -14,  -338,  -338,   253,   253,  -338,   353,   328,  -338,
     328,   360,   352,   357,   352,  -338,  -338,   358,  -338,   988,
    -338,  -338,  -338,   253,  -338,   322,   322,   300,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,   322,  -338
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    61,   159,   160,   163,   164,    22,    28,    24,
      26,    30,    32,     0,     0,   161,   162,   104,     0,     0,
       0,     0,   192,     0,   154,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,     0,   155,   156,     0,     0,
       0,     0,   192,   166,   165,     0,     2,     3,    11,    12,
      13,    14,    15,    16,     6,     9,     7,   152,     8,    10,
      95,   107,   116,   123,    92,    94,    93,    91,   128,   158,
      43,    96,    97,   185,   187,   205,   205,   186,     0,     0,
      62,    61,     0,   152,     0,   107,   123,     0,   175,     0,
      61,     0,   157,     0,   123,     0,     0,     0,   194,     0,
     193,   122,    17,   102,   226,     0,     0,   167,     0,    99,
     101,   100,    61,   146,     0,   144,     0,   192,     0,    41,
       0,     0,     1,     0,    21,    23,    25,    27,    29,    31,
     192,     0,   148,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,   207,   208,   206,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   201,     0,   202,   204,   205,   239,
     168,   169,     0,   179,   181,   180,   177,   148,   147,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   131,
     195,   196,   192,     0,   227,     0,     0,     0,     0,     0,
     141,   192,     0,   192,     0,    18,    41,   192,    37,    39,
       4,    70,     0,   226,   205,    65,     0,     0,    82,   105,
     123,   106,   108,   109,   112,   113,   114,   115,   117,   118,
     119,   120,   121,   110,   111,   124,    46,    47,     0,    61,
     125,    48,    49,   126,   127,   234,   223,     0,   235,     0,
     230,   229,   241,     0,   170,   182,   184,   183,     0,    61,
     174,     0,   176,   190,     0,     0,    98,     0,     0,     0,
     193,    89,    84,   149,   150,   151,   145,   143,     0,     0,
       0,     0,   192,   134,     0,    40,     0,     0,     0,   193,
      34,    78,    77,   192,    71,    75,    79,   123,    76,    83,
     210,   209,   200,     0,    63,    65,    65,     0,   103,     0,
       0,   232,   205,   205,   224,     0,   233,   236,   203,   237,
     234,   228,     0,   231,   205,   240,   103,   178,   188,    42,
     139,   140,     0,     0,   199,     0,   191,   197,     0,     0,
      86,   142,    55,   192,    54,   137,   136,     0,   193,   192,
      38,    36,    19,    35,    33,     0,     0,   193,    66,     0,
      67,    63,    63,    65,     0,   171,   172,     0,   222,   221,
     205,     0,   238,   242,     0,     0,   198,     0,    89,    85,
      89,     0,     0,     0,   193,   133,   135,     0,    74,     0,
      69,    72,    64,     0,    57,    67,    67,    63,    50,   173,
     220,   225,   129,   130,    90,    87,    88,    56,    53,    51,
      52,   132,    73,    68,    59,    58,    67,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -338,  -338,   189,   -74,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,   -86,   -39,   -70,  -338,  -338,  -338,  -165,  -180,
       1,  -337,  -287,  -299,   -77,  -338,  -308,  -338,  -338,   252,
    -167,  -338,  -338,  -153,    69,   125,    11,   196,     0,  -338,
    -338,  -338,    96,    27,   117,  -338,   184,     6,  -338,  -158,
    -338,   205,   127,   -76,  -338,  -338,  -338,    -5,   -89,  -338,
    -217,   -25,   -68,  -338,    18,  -338,  -338,    20,  -338,   182,
    -338,   142,  -338,   144,  -338,   -93,  -338
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
     301,   217,   218,   219,   195,    54,    55,   353,   354,    56,
      83,   370,   314,   404,   132,   303,   304,   133,   134,   135,
      58,   282,   349,   350,    59,    60,    61,    62,    94,    64,
      65,    66,   292,   293,    67,   114,   115,    68,    69,    70,
      87,    88,   186,    78,    71,    89,    72,    99,   100,   202,
     226,    79,   311,   175,   312,   176,   177,   324,   325,   203,
     258,   259,   260,   261,   328,    80,   263
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    57,   120,   182,   180,   107,   187,   174,   179,   200,
     317,   204,    73,    86,   322,   183,   330,   194,    96,    74,
      92,   342,   184,   101,    85,   334,    95,   199,   371,   372,
      18,    73,   255,    73,   405,   406,   208,   121,    74,   113,
      74,    75,   302,    98,   210,    76,  -189,   130,   335,   220,
     215,   102,   256,   181,   123,   305,   227,   398,   339,   401,
      76,    76,   225,    76,   308,   144,   145,   146,   147,   343,
     426,   104,   323,   257,   136,   137,   327,    77,    63,    57,
     185,    38,    84,   245,   131,   151,   407,    93,   194,   257,
      97,   422,   223,    85,   148,   103,    77,   105,    77,   146,
     147,   196,   109,   110,   111,    75,   424,   425,   264,   118,
     262,    98,   212,   280,   106,   214,   278,    98,   151,   160,
     161,   108,   297,    63,    57,   222,   148,   427,   299,   194,
     204,   189,   191,   224,   190,   192,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,    84,   160,   161,   230,   230,   315,   316,   230,   230,
      84,   136,   137,   250,   197,   329,   253,   254,   201,   380,
     414,   112,   381,   319,   205,   206,   388,   207,   389,    98,
     122,   390,    63,    57,   365,   302,    98,   302,   194,   345,
     209,   392,   271,   230,    63,    57,   250,   279,   305,    98,
     305,   221,   250,   358,   273,   340,   289,   308,   294,   308,
     113,   361,   298,   363,   367,   151,   116,   151,   351,   302,
     355,   356,   307,    57,   320,   248,   119,   418,   362,   420,
     189,   190,   305,   196,   382,   415,   123,   416,    76,   214,
     151,   308,   124,   368,   377,   375,   125,   373,   126,   160,
     161,   160,   161,   189,   378,   379,   157,   360,   268,   127,
     270,   229,   231,   128,   394,   130,   383,   277,   129,   188,
     358,   387,    76,   193,   160,   161,   399,   286,   194,   246,
     247,   291,   348,   251,   252,   198,   211,   357,   216,   213,
     131,   306,   265,   276,   376,   266,   267,   275,   366,   402,
     408,   281,   288,   409,   283,   284,   138,   139,   140,   141,
     142,   143,   285,   295,   412,   413,   313,   296,   214,    63,
      57,   144,   145,   146,   147,   321,   148,   318,   326,   332,
     338,    90,   336,   423,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   344,   393,   347,
     148,   346,   149,   150,   397,   352,   364,   369,   374,   391,
     151,   395,   400,   291,   417,   307,    57,   307,    57,   152,
     153,   154,   155,   156,    63,    57,   157,    63,    57,   310,
     403,   419,   224,   274,   421,   396,   228,   158,   159,   348,
     359,   348,   341,   287,   160,   161,   337,   272,   410,   307,
      57,   411,   333,   331,     0,   309,     0,     0,     0,     0,
       0,   384,   385,     0,   386,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   291,     0,     0,
       0,     0,     0,     0,   306,     0,   306,     0,    -5,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      -5,    13,    -5,     0,    -5,    -5,     0,    75,   306,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,    25,     0,     0,    26,     0,     0,    27,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,     0,    41,    42,    43,    44,    -5,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      -5,    13,    -5,     0,    -5,    -5,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,    25,     0,     0,    26,     0,     0,    27,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,     0,    41,    42,    43,    44,    -5,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      -5,    13,     0,     0,    -5,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,    25,     0,     0,    26,     0,     0,    27,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,     0,    41,    42,    43,    44,    -5,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      -5,    13,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,    25,     0,     0,    26,     0,     0,    27,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,     0,    41,    42,    43,    44,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    -5,
      13,     0,     0,    -5,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,    17,    18,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,    22,     0,    23,     0,
      24,    25,     0,     0,    26,     0,     0,    27,     0,     0,
       0,     0,    28,    29,     0,    30,    31,     0,     0,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,    36,    37,    38,     0,   300,    39,
      40,     0,     0,    41,    42,    43,    44,    98,    13,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,    17,    18,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,    22,     0,    23,     0,    24,     0,
       0,     0,    26,     0,     0,    27,     0,     0,     0,     0,
      28,    29,     0,    30,    31,     0,     0,    32,    33,    34,
      35,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       0,   300,    36,    37,    38,     0,     0,     0,    40,     0,
       0,    13,     0,    43,    44,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,     0,     0,     0,    26,     0,     0,    27,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,    90,     3,
       4,     5,     6,     0,     0,    36,    37,    38,     0,     0,
       0,    40,     0,     0,     0,     0,    43,    44,    82,     0,
     117,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,    17,    18,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,    22,     0,    23,     0,    24,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
      28,    29,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    90,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,     0,    40,     0,
       0,    82,     0,    43,    44,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,    90,     3,     4,     5,     6,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
       0,    40,     0,   290,    98,    82,    43,    44,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,    17,
      18,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,    22,     0,    23,     0,    24,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
      30,    31,     0,     0,    32,    33,    34,    35,    81,     3,
       4,     5,     6,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,     0,    40,     0,     0,    82,     0,
      43,    44,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,    17,    18,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,    22,     0,    23,     0,    24,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
      28,    29,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    90,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,     0,    40,     0,
       0,    82,     0,    43,    44,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,    90,     3,     4,     5,     6,    90,
       3,     4,     5,     6,     0,    36,    37,    38,     0,     0,
       0,    40,     0,     0,    91,     0,    43,    44,     0,    91,
       0,     0,    14,     0,     0,    15,    16,    14,     0,     0,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,    28,    29,     0,    30,
      31,    28,    29,    32,    30,    31,     0,     0,    32,     0,
       0,   249,     3,     4,     5,     6,     0,     0,    36,    37,
       0,     0,     0,    36,    37,     0,     0,     0,     0,    43,
      44,    91,     0,     0,    43,    44,     0,     0,     0,    14,
       0,     0,    15,    16,     0,     0,     0,   269,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,    28,    29,    14,    30,    31,    15,    16,
      32,     0,     0,    81,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,   178,    36,    37,    24,     0,     0,
       0,     0,     0,    91,     0,     0,    43,    44,     0,    28,
      29,    14,    30,    31,    15,    16,    32,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,    36,    37,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,    28,    29,     0,    30,    31,
       0,     0,    32,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44
};

static const yytype_int16 yycheck[] =
{
       0,     0,    41,    79,    78,    30,    83,    75,    76,    98,
     227,   104,    21,    13,    28,    21,     3,    25,     3,    28,
      14,    43,    28,    23,    13,    27,    23,    97,   315,   316,
      38,    21,     3,    21,   371,   372,   112,    42,    28,    38,
      28,    29,   222,    22,   114,    51,    27,    23,    50,   123,
     120,     6,    23,    78,    22,   222,   133,   365,    26,   367,
      51,    51,   132,    51,   222,    30,    31,    32,    33,    91,
     407,     3,    86,    60,    55,    56,    67,    86,    78,    78,
      86,    89,    13,   151,    60,    36,   373,    18,    25,    60,
      21,   399,   131,    82,    59,    26,    86,    23,    86,    32,
      33,    52,    33,    34,    35,    29,   405,   406,   182,    40,
     178,    22,   117,   202,    23,    52,    27,    22,    36,    70,
      71,    23,    27,   123,   123,   130,    59,   426,   217,    25,
     223,    49,    24,    29,    52,    27,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    82,    70,    71,   154,   155,   226,   227,   158,   159,
      91,    55,    56,   157,    95,   258,   160,   161,    99,    24,
     387,     3,    27,   249,   105,   106,    22,   108,    24,    22,
       0,    27,   182,   182,    27,   365,    22,   367,    25,   278,
      27,    27,   192,   193,   194,   194,   190,   202,   365,    22,
     367,    24,   196,   292,   193,   275,   211,   365,   213,   367,
     209,   297,   217,   299,   303,    36,     3,    36,   288,   399,
     290,   291,   222,   222,   249,   156,     3,   392,   298,   394,
      49,    52,   399,    52,   327,   388,    22,   390,    51,    52,
      36,   399,     8,   313,   320,   319,    10,   317,    11,    70,
      71,    70,    71,    49,   322,   323,    52,   296,   189,     9,
     191,   136,   137,    12,   353,    23,   334,   198,    14,    24,
     359,   348,    51,    27,    70,    71,   365,   208,    25,   154,
     155,   212,   281,   158,   159,    28,    23,   292,     3,    25,
      60,   222,    57,    24,   319,    57,    57,    39,   303,   369,
     374,    23,    90,   377,    24,    24,    15,    16,    17,    18,
      19,    20,    24,     3,   384,   385,    41,    28,    52,   319,
     319,    30,    31,    32,    33,    52,    59,    50,     3,     3,
      24,     3,    50,   403,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   278,   353,   280,
      59,    50,    61,    62,   359,     3,    13,    57,    21,    28,
      36,    26,    24,   294,     4,   365,   365,   367,   367,    45,
      46,    47,    48,    49,   374,   374,    52,   377,   377,    37,
      58,    24,    29,   194,    26,   358,   134,    63,    64,   388,
     294,   390,   275,   209,    70,    71,   269,   192,   380,   399,
     399,   381,   260,   259,    -1,   223,    -1,    -1,    -1,    -1,
      -1,   342,   343,    -1,   345,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   358,    -1,    -1,
      -1,    -1,    -1,    -1,   365,    -1,   367,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    29,   399,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      53,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    87,    88,    89,    -1,    13,    92,
      93,    -1,    -1,    96,    97,    98,    99,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    -1,    -1,    72,    73,    74,
      75,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    23,    -1,    98,    99,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    98,    99,    23,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    -1,    -1,    72,    73,    74,
      75,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    23,    -1,    98,    99,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    95,    22,    23,    98,    99,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    -1,    -1,    72,    73,    74,    75,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    -1,    -1,    -1,    93,    -1,    -1,    23,    -1,
      98,    99,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    -1,    -1,    72,    73,    74,
      75,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    23,    -1,    98,    99,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,    -1,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    23,    -1,    98,    99,    -1,    23,
      -1,    -1,    31,    -1,    -1,    34,    35,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    65,    66,    72,    68,    69,    -1,    -1,    72,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    87,    88,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    98,
      99,    23,    -1,    -1,    98,    99,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    65,    66,    31,    68,    69,    34,    35,
      72,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    87,    88,    53,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    98,    99,    -1,    65,
      66,    31,    68,    69,    34,    35,    72,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    87,    88,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    65,    66,    -1,    68,    69,
      -1,    -1,    72,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    23,    31,    34,    35,    37,    38,    40,
      42,    44,    49,    51,    53,    54,    57,    60,    65,    66,
      68,    69,    72,    73,    74,    75,    87,    88,    89,    92,
      93,    96,    97,    98,    99,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   115,   116,   119,   120,   130,   134,
     135,   136,   137,   138,   139,   140,   141,   144,   147,   148,
     149,   154,   156,    21,    28,    29,    51,    86,   153,   161,
     175,     3,    23,   120,   134,   136,   138,   150,   151,   155,
       3,    23,   147,   134,   138,    23,     3,   134,    22,   157,
     158,   138,     6,   134,     3,    23,    23,   161,    23,   134,
     134,   134,     3,   120,   145,   146,     3,    25,   134,     3,
     113,   157,     0,    22,     8,    10,    11,     9,    12,    14,
      23,    60,   124,   127,   128,   129,    55,    56,    15,    16,
      17,    18,    19,    20,    30,    31,    32,    33,    59,    61,
      62,    36,    45,    46,    47,    48,    49,    52,    63,    64,
      70,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   162,   163,   165,   166,    49,   162,
     103,   161,   153,    21,    28,    86,   152,   124,    24,    49,
      52,    24,    27,    27,    25,   114,    52,   134,    28,   114,
     158,   134,   159,   169,   175,   134,   134,   134,   153,    27,
     114,    23,   157,    25,    52,   114,     3,   111,   112,   113,
     103,    24,   157,   113,    29,   114,   160,   124,   129,   135,
     138,   135,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   162,   135,   135,   134,     3,
     147,   135,   135,   147,   147,     3,    23,    60,   170,   171,
     172,   173,   162,   176,   103,    57,    57,    57,   134,     3,
     134,   138,   151,   136,   102,    39,    24,   134,    27,   157,
     158,    23,   131,    24,    24,    24,   134,   146,    90,   157,
      95,   134,   142,   143,   157,     3,    28,    27,   157,   158,
      13,   110,   119,   125,   126,   130,   134,   138,   149,   169,
      37,   162,   164,    41,   122,   114,   114,   160,    50,   153,
     161,    52,    28,    86,   167,   168,     3,    67,   174,   175,
       3,   173,     3,   171,    27,    50,    50,   152,    24,    26,
     114,   144,    43,    91,   134,   158,    50,   134,   120,   132,
     133,   114,     3,   117,   118,   114,   114,   157,   158,   142,
     113,   112,   114,   112,    13,    27,   157,   158,   114,    57,
     121,   122,   122,   114,    21,   103,   161,   153,   162,   162,
      24,    27,   175,   162,   134,   134,   134,   124,    22,    24,
      27,    28,    27,   157,   158,    26,   143,   157,   126,   158,
      24,   126,   114,    58,   123,   121,   121,   122,   103,   103,
     164,   167,   114,   114,   160,   133,   133,     4,   118,    24,
     118,    26,   126,   114,   123,   123,   121,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   117,   117,   117,   118,   118,   119,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     127,   128,   128,   129,   130,   131,   132,   132,   132,   133,
     133,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   138,   138,   138,   138,   138,   139,
     139,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     144,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   150,   150,   151,   151,   152,
     152,   152,   152,   152,   152,   153,   153,   153,   154,   155,
     155,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     160,   161,   162,   162,   162,   163,   163,   163,   163,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   167,   167,   168,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   173,   173,   174,   174,   174,   174,   175,
     175,   176,   176
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     5,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     2,     3,     3,     3,     3,
       6,     7,     3,     3,     1,     1,     3,     6,     7,     7,
       8,     1,     2,     0,     2,     0,     2,     0,     2,     5,
       2,     1,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     3,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       2,     2,     2,     4,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     2,     1,     3,     3,     3,     3,     1,     7,
       7,     3,     7,     6,     1,     3,     2,     2,     3,     5,
       5,     3,     5,     3,     1,     3,     1,     3,     2,     4,
       4,     4,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       4,     5,     5,     6,     4,     1,     3,     2,     4,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     5,     1,
       3,     5,     0,     1,     1,     2,     1,     3,     4,     3,
       2,     2,     1,     3,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     2,     0,     1,     3,     0,     1,     2,     1,
       1,     2,     2,     2,     1,     0,     1,     1,     2,     2,
       4,     1,     3
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

  case 10:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 11:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 12:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 13:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 14:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 15:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 16:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 17:

    { (yyval.node) = new NInclude(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 18:

    { (yyval.node) = new NPackage(LOC, *(yyvsp[-1].strings), shared_ptr<NBase>((yyvsp[0].node))); delete (yyvsp[-1].strings); }

    break;

  case 19:

    { (yyval.node) = new NImport(LOC, *(yyvsp[-2].import_namespaces), shared_ptr<NBase>((yyvsp[0].node))); delete (yyvsp[-2].import_namespaces); }

    break;

  case 20:

    { (yyval.node) = nullptr; /* yyclearin; */ compiler->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }

    break;

  case 21:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 22:

    { (yyval.ccode) = new NCCode(LOC, NCC_BLOCK, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 23:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 24:

    { (yyval.ccode) = new NCCode(LOC, NCC_DEFINE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 25:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 26:

    { (yyval.ccode) = new NCCode(LOC, NCC_STRUCT, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 27:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 28:

    { (yyval.ccode) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 29:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 30:

    { (yyval.ccode) = new NCCode(LOC, NCC_INCLUDE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 31:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 32:

    { (yyval.ccode) = new NCCode(LOC, NCC_TYPEDEF, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 33:

    { (yyval.ccode)->lines.push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 34:

    { (yyval.ccode) = new NCCode(LOC, NCC_VAR, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 35:

    { (yyvsp[-2].import_namespaces)->push_back(*(yyvsp[0].import_namespace)); delete (yyvsp[0].import_namespace); }

    break;

  case 36:

    { (yyvsp[-2].import_namespaces)->push_back(*(yyvsp[0].import_namespace)); delete (yyvsp[0].import_namespace); }

    break;

  case 37:

    { (yyval.import_namespaces) = new vector<pair<string, vector<string>>>(); (yyval.import_namespaces)->push_back(*(yyvsp[0].import_namespace)); delete (yyvsp[0].import_namespace); }

    break;

  case 38:

    { (yyval.import_namespace) = new pair<string, vector<string>>(*(yyvsp[-2].string), *(yyvsp[0].strings)); delete (yyvsp[-2].string); delete (yyvsp[0].strings); }

    break;

  case 39:

    { (yyval.import_namespace) = new pair<string, vector<string>>("", *(yyvsp[0].strings)); delete (yyvsp[0].strings); }

    break;

  case 40:

    { (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 41:

    { (yyval.strings) = new vector<string>(); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 42:

    { (yyval.node) = (yyvsp[-1].block); }

    break;

  case 44:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Inc, nullptr); }

    break;

  case 45:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Dec, nullptr); }

    break;

  case 46:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 47:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 48:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 49:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 50:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), make_shared<NCall>(LOC, "setAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[0].node))))); }

    break;

  case 51:

    { (yyval.node) = new NEnum(LOC, *(yyvsp[-5].string), shared_ptr<EnumArgs>((yyvsp[-2].enumArgs))); delete (yyvsp[-5].string); }

    break;

  case 52:

    { (yyvsp[-2].enumArgs)->push_back(shared_ptr<EnumArg>((yyvsp[0].enumArg))); }

    break;

  case 53:

    { (yyvsp[-2].enumArgs)->push_back(shared_ptr<EnumArg>((yyvsp[0].enumArg))); }

    break;

  case 54:

    { (yyval.enumArgs) = new EnumArgs(shared_ptr<EnumArg>((yyvsp[0].enumArg))); }

    break;

  case 55:

    { (yyval.enumArg) = new EnumArg(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 56:

    { (yyval.enumArg) = new EnumArg(*(yyvsp[-2].string), *(yyvsp[0].string)); delete (yyvsp[-2].string); delete (yyvsp[0].string); }

    break;

  case 57:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].typeName)->valueName.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-5].typeName); 
					}

    break;

  case 58:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 59:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 60:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-7].typeName)->valueName.c_str(), (yyvsp[-7].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-6].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 61:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, (yyvsp[0].string)->c_str(), false); delete (yyvsp[0].string); }

    break;

  case 62:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 63:

    { (yyval.node) = nullptr; }

    break;

  case 64:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 65:

    { (yyval.node) = nullptr; }

    break;

  case 66:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 67:

    { (yyval.node) = nullptr; }

    break;

  case 68:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 69:

    { (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 70:

    { (yyval.exprvec) = new NodeList(); }

    break;

  case 71:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 72:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 73:

    { if ((yyvsp[0].node)) { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 74:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 78:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 79:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 80:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 81:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 82:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 83:

    { string t = (yyvsp[-1].strings)->back(); (yyvsp[-1].strings)->pop_back(); (yyval.typeName) = new CTypeName(CTC_Interface, CTM_Stack, *(yyvsp[-1].strings), t, shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].strings); }

    break;

  case 84:

    { (yyval.node) = new NInterface(LOC, *(yyvsp[-2].string), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 85:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 86:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 87:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 88:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 89:

    { (yyval.node) = nullptr; }

    break;

  case 90:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].typeName)->valueName.c_str(), (yyvsp[-2].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 91:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 93:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 95:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 96:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 98:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 99:

    { (yyval.node) = new NChangeMode(LOC, CTM_Stack, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 100:

    { (yyval.node) = new NChangeMode(LOC, CTM_Local, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 101:

    { (yyval.node) = new NChangeMode(LOC, CTM_Heap, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 102:

    { (yyval.node) = new NCopy(LOC, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 103:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 104:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 105:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 106:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 108:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::EQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 109:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::NE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 110:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PEQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 111:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PNE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 112:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 113:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 114:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 115:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 116:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 117:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 118:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 119:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 120:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 121:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mod, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 122:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 123:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 124:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 125:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 126:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 127:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 128:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 129:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), true); delete (yyvsp[-5].string); }

    break;

  case 130:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), false); delete (yyvsp[-5].string); }

    break;

  case 131:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 132:

    { (yyval.node) = new NSwitch(LOC, shared_ptr<NBase>((yyvsp[-5].node)), *(yyvsp[-2].switchClauses)); delete (yyvsp[-2].switchClauses); }

    break;

  case 133:

    { (yyval.node) = new NSwitch(LOC, nullptr, *(yyvsp[-2].switchClauses)); delete (yyvsp[-2].switchClauses); }

    break;

  case 134:

    { (yyval.switchClauses) = new vector<shared_ptr<NSwitchClause>>(); (yyval.switchClauses)->push_back(shared_ptr<NSwitchClause>((yyvsp[0].switchClause))); }

    break;

  case 135:

    { (yyval.switchClauses) = (yyvsp[-2].switchClauses); (yyval.switchClauses)->push_back(shared_ptr<NSwitchClause>((yyvsp[0].switchClause))); }

    break;

  case 136:

    { (yyval.switchClause) = new NSwitchClause(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 137:

    { (yyval.switchClause) = new NSwitchClause(LOC, nullptr, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 138:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 139:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 140:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 141:

    { (yyval.node) = new NIfValue(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 142:

    { (yyval.node) = new NIfValue(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 143:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 144:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 145:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 146:

    { (yyval.node) = new NVariable(LOC, (yyvsp[0].typeName)->valueName.c_str(), (yyvsp[0].typeName)->templateTypeNames); delete (yyvsp[0].typeName); }

    break;

  case 147:

    { (yyval.var) = new NVariableStub(shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 148:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].typeName)->valueName.c_str(), (yyvsp[-1].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].typeName); }

    break;

  case 149:

    { (yyval.var) = new NIsEmpty(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 150:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 151:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 152:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].typeName)->valueName.c_str(), (yyvsp[0].typeName)->templateTypeNames); delete (yyvsp[0].typeName); }

    break;

  case 153:

    { (yyval.var) = new NParent(LOC, false); }

    break;

  case 154:

    { (yyval.var) = new NThis(LOC, false); }

    break;

  case 155:

    { (yyval.var) = new NParent(LOC, true); }

    break;

  case 156:

    { (yyval.var) = new NThis(LOC, true); }

    break;

  case 157:

    { (yyval.var) = new NNegate(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 158:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 159:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 160:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 161:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 162:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 163:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 164:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 165:

    { (yyval.var) = new NNullPtr(LOC); }

    break;

  case 166:

    { (yyval.var) = new NUnderscore(LOC); }

    break;

  case 167:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 168:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 169:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 170:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 171:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 172:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 173:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 174:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 175:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 176:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 177:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 178:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 179:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 180:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 181:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 182:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 183:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 184:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 185:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 186:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 187:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 188:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[-1].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec))); }

    break;

  case 189:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 190:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 191:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 192:

    { (yyval.node) = nullptr; }

    break;

  case 193:

    { (yyval.node) = nullptr; }

    break;

  case 194:

    { (yyval.node) = nullptr; }

    break;

  case 195:

    { (yyval.node) = nullptr; }

    break;

  case 196:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 197:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 198:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 199:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 200:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 201:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 202:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 203:

    { (yyval.typeName) = new CTypeName((yyvsp[-1].typeNameParts)->isHash ? CTC_Interface : CTC_Value, (yyvsp[-2].typeMode), (yyvsp[-1].typeNameParts)->packageNamespace, (yyvsp[-1].typeNameParts)->name, shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].typeNameParts); }

    break;

  case 204:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 205:

    { (yyval.typeMode) = CTM_Undefined; }

    break;

  case 206:

    { (yyval.typeMode) = CTM_Local; }

    break;

  case 207:

    { (yyval.typeMode) = CTM_Stack; }

    break;

  case 208:

    { (yyval.typeMode) = CTM_Heap; }

    break;

  case 209:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 210:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, "void", false); }

    break;

  case 211:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i32", false); }

    break;

  case 212:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u32", false); }

    break;

  case 213:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f32", false); }

    break;

  case 214:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i64", false); }

    break;

  case 215:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u64", false); }

    break;

  case 216:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f64", false); }

    break;

  case 217:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "char", false); }

    break;

  case 218:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "bool", false); }

    break;

  case 219:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "ptr", false); }

    break;

  case 220:

    { (yyval.typeName) = new CTypeName((yyvsp[-4].typeMode), shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 221:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Mutable; }

    break;

  case 222:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Immutable; }

    break;

  case 223:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 224:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 225:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 226:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 227:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 228:

    { (yyval.typeNameParts) = (yyvsp[0].typeNameParts); (yyval.typeNameParts)->packageNamespace = *(yyvsp[-1].strings); delete (yyvsp[-1].strings); }

    break;

  case 229:

    { (yyval.typeNameParts) = (yyvsp[0].typeNameParts); }

    break;

  case 230:

    { (yyval.strings) = new vector<string>(); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 231:

    { (yyval.strings) = (yyvsp[0].strings); (yyval.strings)->push_back(*(yyvsp[-1].string)); delete (yyvsp[-1].string); }

    break;

  case 232:

    { (yyval.string) = (yyvsp[-1].string); }

    break;

  case 233:

    { (yyval.typeNameParts) = new CTypeNameParts(); (yyval.typeNameParts)->isHash = true;  (yyval.typeNameParts)->name = *(yyvsp[0].string); delete (yyvsp[0].string); }

    break;

  case 234:

    { (yyval.typeNameParts) = new CTypeNameParts(); (yyval.typeNameParts)->isHash = false; (yyval.typeNameParts)->name = *(yyvsp[0].string); delete (yyvsp[0].string); }

    break;

  case 235:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 236:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 237:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 238:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 239:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 240:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 241:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 242:

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

