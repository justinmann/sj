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
    TQUOTEDIDENTIFIER = 270,
    TCEQ = 271,
    TCNE = 272,
    TCLT = 273,
    TCLE = 274,
    TCGT = 275,
    TCGE = 276,
    TEQUAL = 277,
    TEND = 278,
    TLPAREN = 279,
    TRPAREN = 280,
    TLBRACE = 281,
    TRBRACE = 282,
    TCOMMA = 283,
    TCOLON = 284,
    TQUOTE = 285,
    TPLUS = 286,
    TMINUS = 287,
    TMUL = 288,
    TDIV = 289,
    TTRUE = 290,
    TFALSE = 291,
    TAS = 292,
    TVOID = 293,
    TIF = 294,
    TELSE = 295,
    TTHROW = 296,
    TCATCH = 297,
    TFOR = 298,
    TTO = 299,
    TWHILE = 300,
    TPLUSPLUS = 301,
    TMINUSMINUS = 302,
    TPLUSEQUAL = 303,
    TMINUSEQUAL = 304,
    TLBRACKET = 305,
    TRBRACKET = 306,
    TEXCLAIM = 307,
    TDOT = 308,
    TTHIS = 309,
    TINCLUDE = 310,
    TAND = 311,
    TOR = 312,
    TCOPY = 313,
    TDESTROY = 314,
    TMOD = 315,
    THASH = 316,
    TCPEQ = 317,
    TCPNE = 318,
    TMULEQUAL = 319,
    TDIVEQUAL = 320,
    TISEMPTY = 321,
    TISVALID = 322,
    TGETVALUE = 323,
    TQUESTION = 324,
    TEMPTY = 325,
    TVALID = 326,
    TQUESTIONCOLON = 327,
    TQUESTIONDOT = 328,
    TPARENT = 329,
    TSTACK = 330,
    THEAP = 331,
    TWEAK = 332,
    TLOCAL = 333,
    TTYPEI32 = 334,
    TTYPEU32 = 335,
    TTYPEF32 = 336,
    TTYPEI64 = 337,
    TTYPEU64 = 338,
    TTYPEF64 = 339,
    TTYPECHAR = 340,
    TTYPEBOOL = 341,
    TTYPEPTR = 342,
    TINVALID = 343,
    TCOLONEQUAL = 344,
    TIFVALID = 345,
    TELSEEMPTY = 346,
    TTOREVERSE = 347,
    TENUM = 348,
    TSWITCH = 349,
    TDEFAULT = 350,
    TPACKAGE = 351,
    TIMPORT = 352,
    TUNDERSCORE = 353,
    TNULLPTR = 354,
    TBOOLXOR = 355,
    TBOOLOR = 356,
    TBOOLAND = 357,
    TBOOLSHL = 358,
    TBOOLSHR = 359,
    TBOOLNOT = 360,
    TAT = 361
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
	vector<pair<shared_ptr<NBase>, shared_ptr<NBase>>>* hashArgs;
	pair<shared_ptr<NBase>, shared_ptr<NBase>>* hashArg;
	CFunctionName* functionName;


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
#define YYFINAL  134
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1825

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  265
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  472

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   127,   128,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   149,   150,   153,   154,   157,   158,   161,   162,   165,
     166,   169,   170,   173,   174,   177,   178,   179,   182,   183,
     186,   187,   190,   193,   194,   195,   196,   197,   198,   199,
     200,   203,   206,   207,   208,   211,   212,   215,   221,   226,
     231,   238,   239,   240,   241,   242,   243,   244,   245,   248,
     249,   252,   253,   256,   257,   260,   261,   264,   265,   268,
     269,   272,   273,   274,   275,   278,   279,   280,   281,   282,
     285,   288,   289,   292,   295,   298,   301,   302,   303,   306,
     307,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   322,   323,   324,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     357,   358,   359,   360,   361,   362,   365,   366,   369,   372,
     373,   376,   377,   380,   381,   384,   385,   386,   387,   388,
     391,   392,   395,   396,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   423,   424,   425,   426,   427,   428,
     429,   432,   433,   436,   437,   440,   441,   442,   443,   444,
     445,   448,   449,   450,   453,   456,   457,   460,   463,   466,
     467,   468,   469,   472,   475,   476,   479,   480,   483,   484,
     485,   486,   489,   492,   495,   496,   497,   500,   501,   502,
     503,   504,   507,   508,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   522,   525,   526,   529,   530,   531,   534,
     535,   538,   539,   542,   543,   546,   549,   550,   553,   554,
     555,   556,   559,   560,   563,   564
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TINTEGER", "TDOUBLE",
  "TSTRING", "TCHAR", "TCBLOCK", "TCFUNCTION", "TCDEFINE", "TCSTRUCT",
  "TCINCLUDE", "TCVAR", "TCTYPEDEF", "TQUOTEDIDENTIFIER", "TCEQ", "TCNE",
  "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TEND", "TLPAREN", "TRPAREN",
  "TLBRACE", "TRBRACE", "TCOMMA", "TCOLON", "TQUOTE", "TPLUS", "TMINUS",
  "TMUL", "TDIV", "TTRUE", "TFALSE", "TAS", "TVOID", "TIF", "TELSE",
  "TTHROW", "TCATCH", "TFOR", "TTO", "TWHILE", "TPLUSPLUS", "TMINUSMINUS",
  "TPLUSEQUAL", "TMINUSEQUAL", "TLBRACKET", "TRBRACKET", "TEXCLAIM",
  "TDOT", "TTHIS", "TINCLUDE", "TAND", "TOR", "TCOPY", "TDESTROY", "TMOD",
  "THASH", "TCPEQ", "TCPNE", "TMULEQUAL", "TDIVEQUAL", "TISEMPTY",
  "TISVALID", "TGETVALUE", "TQUESTION", "TEMPTY", "TVALID",
  "TQUESTIONCOLON", "TQUESTIONDOT", "TPARENT", "TSTACK", "THEAP", "TWEAK",
  "TLOCAL", "TTYPEI32", "TTYPEU32", "TTYPEF32", "TTYPEI64", "TTYPEU64",
  "TTYPEF64", "TTYPECHAR", "TTYPEBOOL", "TTYPEPTR", "TINVALID",
  "TCOLONEQUAL", "TIFVALID", "TELSEEMPTY", "TTOREVERSE", "TENUM",
  "TSWITCH", "TDEFAULT", "TPACKAGE", "TIMPORT", "TUNDERSCORE", "TNULLPTR",
  "TBOOLXOR", "TBOOLOR", "TBOOLAND", "TBOOLSHL", "TBOOLSHR", "TBOOLNOT",
  "TAT", "$accept", "program", "stmts", "stmt", "cblock", "cdefine",
  "cstruct", "cfunction", "cinclude", "ctypedef", "cvar",
  "import_namespaces", "import_namespace", "namespace", "block",
  "var_decl", "enum_decl", "enum_args", "enum_arg", "func_decl",
  "func_type_name", "func_attribs", "func_attrib", "copy", "catch",
  "destroy", "func_block", "func_args", "func_arg", "implement",
  "implement_args", "implement_arg", "interface_decl", "interface_block",
  "interface_args", "interface_arg", "expr", "expr_and", "expr_comp",
  "expr_math", "expr_var", "for_expr", "while_expr", "switch_expr",
  "switch_clauses", "switch_clause", "if_expr", "ifValue_vars",
  "ifValue_var", "var_right", "const", "assign", "assign_tuple",
  "assign_tuple_arg", "assign_tuple_type", "assign_type", "tuple",
  "tuple_args", "array", "hash", "hash_args", "hash_arg", "end_optional",
  "end_star", "array_args", "return_type_quote", "arg_type_quote",
  "arg_type", "arg_mode", "return_type", "value_type", "func_type",
  "func_arg_type", "func_arg_type_list", "temp_block_optional",
  "namespace_hash", "namespace_dot", "namespace_ident", "namespace_last",
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361
};
# endif

#define YYPACT_NINF -346

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-346)))

#define YYTABLE_NINF -206

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     757,  -346,    44,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,    -4,  1263,    34,  1529,  -346,  -346,  -346,
    1339,    43,    92,  1339,    34,  1529,  -346,    95,  1529,   131,
     141,   153,   160,   170,   197,  -346,  1529,  1529,  1529,  1529,
      15,   211,  1415,   222,    34,  -346,  -346,    23,   242,   226,
    -346,   251,   259,   250,   261,   260,   257,  -346,  -346,  -346,
      25,    34,  -346,  -346,  -346,  -346,    70,  1690,   276,  -346,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  1738,  1699,  -346,   445,    29,  -346,  -346,    60,  1339,
     258,   256,   201,   190,    47,  -346,   247,    34,  1339,  -346,
      -4,  1339,  -346,   264,   215,  1339,   255,   264,  1339,   215,
    -346,   215,    -4,  1339,  1339,  1339,  -346,  1339,   215,   215,
     215,   215,    86,  -346,   143,  -346,   267,    34,   266,  -346,
      17,   292,  -346,  -346,  -346,   653,  -346,  -346,  -346,  -346,
    -346,  -346,   165,   222,   116,   258,   237,  -346,    37,  1472,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1738,
    -346,  -346,  1472,  1472,  1339,  1552,  1472,  1472,  1529,  1529,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,    56,  -346,  -346,  1738,  -346,  -346,
    -346,   549,   239,   244,   248,  -346,  -346,  -346,  1339,  1606,
    1339,  1660,  1472,  -346,   278,    48,  -346,   861,   270,  1529,
     287,  1339,  -346,  -346,   150,   290,  -346,   294,   295,   305,
     308,  1339,    15,   245,    34,  1110,    34,   314,  -346,   310,
     157,  -346,   284,  -346,  -346,  1034,   214,  1661,   302,   264,
     116,  -346,    -4,    -4,  -346,  -346,  -346,    91,    91,    91,
      91,    91,    91,    28,    28,    54,    54,   176,    91,    91,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,   300,    44,
    -346,  -346,  -346,  -346,  -346,   293,   -10,   342,    31,    32,
     349,  -346,  -346,    40,  -346,  -346,  -346,  -346,   303,    60,
    -346,   190,  -346,   328,  1339,  1187,   333,  1339,   121,    30,
    -346,   -15,  1187,   304,  1339,    39,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,   264,   358,   264,    84,    34,  -346,  1110,
    -346,   222,   292,   264,   292,  -346,   350,  -346,   158,  -346,
    -346,  -346,   236,  -346,  -346,  -346,  -346,  -346,   264,   306,
     302,   302,   264,  -346,  -346,   340,   445,    29,  -346,  1738,
    1738,  -346,   191,  -346,    -4,  -346,  -346,  -346,  -346,   293,
    -346,  1738,  -346,  -346,  -346,  -346,  -346,  -346,  1339,  -346,
    -346,  -346,  -346,  -346,  1339,  1339,  -346,  1339,  -346,  -346,
     258,   136,  -346,  -346,   339,   175,  -346,  -346,  -346,   344,
    1110,   264,    34,   284,  -346,  -346,  -346,  -346,   958,   347,
    1034,  -346,   264,   316,   306,   306,   302,   549,  -346,  -346,
     549,  -346,  -346,  1661,   -10,  -346,  -346,  -346,   264,   264,
    -346,   348,    39,  -346,    39,   373,   358,   354,   358,  -346,
    -346,   353,  -346,  1034,  -346,  -346,  -346,   264,  -346,   316,
     316,   306,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
     316,  -346
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    20,    61,   175,   176,   179,   180,    22,    28,    24,
      26,    30,    32,    63,     0,   214,     0,   177,   178,   110,
       0,     0,     0,     0,   214,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   182,   181,     0,     0,     2,
       3,    11,    12,    13,    14,    15,    16,     6,     9,     7,
     170,   214,    69,     8,    10,   105,   113,   122,   139,   102,
     104,   103,   101,   145,   174,    43,   106,   107,   108,   201,
     203,   227,   227,   202,     0,     0,    62,    64,    61,     0,
     170,     0,   113,   139,     0,   191,     0,   216,     0,   215,
      61,     0,   173,     0,   139,     0,     0,     0,     0,   133,
      17,   138,   249,     0,     0,     0,   183,     0,   134,   136,
     137,   135,    61,   163,     0,   161,     0,   214,     0,    41,
       0,     0,    72,    71,     1,     0,    21,    23,    25,    27,
      29,    31,   214,     0,   165,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
     229,   230,   231,   228,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   223,     0,   224,   226,   227,   262,   184,
     185,     0,   195,   197,   196,   193,   165,   164,     0,     0,
       0,     0,     0,   217,     0,   214,   209,     0,   155,     0,
       0,     0,   148,   218,   214,     0,   250,     0,     0,     0,
       0,     0,     0,   158,   214,     0,   214,     0,    18,    41,
     214,    37,    39,     4,    80,     0,   249,   227,    75,     0,
       0,    92,    65,    67,    70,   111,   112,   114,   115,   118,
     119,   120,   121,   123,   124,   125,   126,   127,   116,   117,
     128,   129,   130,   132,   131,   140,    46,    47,     0,    61,
     141,    48,    49,   142,   143,   257,   246,     0,   258,     0,
     253,   252,   264,     0,   186,   198,   200,   199,     0,    61,
     190,     0,   192,   206,     0,     0,     0,   215,     0,     0,
     109,     0,     0,     0,   215,    99,    94,   166,   167,   168,
     169,   162,   160,     0,     0,     0,     0,   214,   151,     0,
      40,     0,     0,     0,   215,    34,    88,    87,   214,    81,
      85,    89,   139,    86,    93,   233,   232,   222,     0,    73,
      75,    75,     0,    66,    68,   144,     0,     0,   255,   227,
     227,   247,     0,   256,   259,   225,   260,   257,   251,     0,
     254,   227,   263,   144,   194,   204,   213,   212,     0,   208,
     210,    42,   156,   157,     0,     0,   221,     0,   207,   219,
       0,     0,    96,   159,    55,   214,    54,   154,   153,     0,
     215,     0,   214,    38,    36,    19,    35,    33,     0,     0,
     215,    76,     0,    77,    73,    73,    75,     0,   187,   188,
       0,   245,   244,   227,     0,   261,   265,   211,     0,     0,
     220,     0,    99,    95,    99,     0,     0,     0,   215,   150,
     152,     0,    84,     0,    79,    82,    74,     0,    57,    77,
      77,    73,    50,   189,   243,   248,   146,   147,   100,    97,
      98,    56,    53,    51,    52,   149,    83,    78,    59,    58,
      77,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -346,  -346,   164,   -82,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,  -126,   -27,   -97,  -346,  -346,  -346,  -206,  -238,
       1,  -346,   234,  -247,  -305,  -310,   -85,  -346,  -345,  -346,
    -346,   238,  -234,  -346,  -346,  -195,   -11,   193,     3,  1644,
       0,  -346,  -346,  -346,    57,   -17,    76,  -346,   155,     4,
    -346,  -221,  -346,   177,    93,   -72,  -346,  -346,  -346,  -346,
    -346,  -273,    20,   -74,  -346,  -235,   -29,   -60,  -346,   -33,
    -346,  -346,   -31,  -346,   145,  -346,   104,  -346,   106,  -346,
      -5,  -346
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
     336,   240,   241,   242,   398,    57,    58,   395,   396,    59,
      90,    61,    62,   413,   349,   448,   144,   338,   339,   145,
     146,   147,    63,   316,   391,   392,    64,    65,    66,    67,
     104,    69,    70,    71,   327,   328,    72,   124,   125,    73,
      74,    75,    94,    95,   205,    84,    76,    96,    77,    78,
     215,   216,    98,    99,   224,   249,    85,   346,   194,   347,
     195,   196,   361,   362,   225,   288,   289,   290,   291,   365,
      86,   293
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    60,   199,    91,   116,   206,   218,   337,    87,   103,
     222,   340,   107,   201,    93,   352,   130,    92,   122,   359,
     102,   193,   198,   213,   343,   109,   132,   233,   111,   384,
      13,   128,   377,   238,   380,   367,   118,   119,   120,   121,
     252,   123,   100,   217,   108,   414,   415,   248,    82,   142,
     231,    79,   253,   243,    13,   200,   217,    97,    80,   285,
     250,   159,   160,   442,   131,   445,    79,   105,   371,    20,
     237,    97,   210,    80,    81,   211,   305,   385,    91,   360,
     286,   148,   202,    82,    68,    60,   143,   214,   161,   203,
      91,   372,    92,   287,   220,   106,    82,   223,   466,   133,
     364,   110,   227,   228,   229,   427,   230,   226,    79,   275,
     217,   451,    82,   304,   161,    80,   246,   287,    83,   294,
      40,    47,   157,   158,   159,   160,   149,   150,   164,   165,
     166,   167,   168,    83,   112,    68,    60,   292,    82,   468,
     469,   307,   217,    47,   135,    47,   247,   235,   381,   204,
     314,   161,   350,   351,   164,   165,   166,   167,   168,   432,
     471,   433,   245,   278,   434,   113,   334,   449,   450,   217,
     337,   232,   337,    97,   340,    83,   340,   114,   312,   280,
      97,    97,   283,   284,   115,   332,   408,   343,    97,   343,
     244,   164,   165,   166,   167,   168,   458,   298,    97,   300,
      81,    68,    60,   436,   470,   337,   404,   356,   406,   340,
     311,   301,   382,   280,   126,   303,   423,    68,    60,   424,
     321,   117,   343,   280,   326,   129,   393,   169,   397,  -205,
     462,   378,   464,   123,   341,   306,   405,   459,   387,   460,
     208,   226,   134,   209,   313,   342,    60,   353,   354,   135,
     357,   411,   169,   400,   324,   416,   329,   149,   150,   136,
     333,   138,   178,   179,   410,   208,    82,   237,   219,   137,
     139,   141,   140,   169,   418,   212,   164,   165,   166,   167,
     168,   207,   142,   366,   221,   420,   208,   178,   179,   175,
     217,   234,   236,   376,   214,   239,   214,   295,   143,   421,
     422,   386,   296,   389,   403,   431,   297,   304,   178,   179,
     309,   426,   310,   169,   315,   446,   390,   330,   401,   317,
     318,   438,   170,   171,   172,   173,   174,   419,   400,   175,
     319,   456,   457,   320,   443,   452,   323,   237,   453,   331,
     176,   177,   255,   256,   348,   363,   358,   399,   178,   179,
     467,   355,   369,   375,   373,   388,    68,    60,   409,   425,
     379,   394,   417,   407,   412,   276,   277,   214,   435,   281,
     282,   439,   444,   428,   429,   447,   430,   461,   247,   463,
     465,   308,   254,   440,   251,   383,   402,   322,   302,   401,
     454,   344,   374,   455,   370,   368,     0,   341,     0,   341,
       0,     0,     0,     0,     0,     0,     0,     0,   342,    60,
     342,    60,     0,     0,     0,   437,     0,    68,    60,     0,
      68,    60,   441,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   341,   390,     0,   390,     0,     0,     0,     0,
       0,     0,     0,   342,    60,    -5,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
      13,     0,     0,     0,     0,     0,     0,     0,    -5,    14,
      -5,    15,    -5,    -5,     0,    81,     0,    16,     0,     0,
      17,    18,     0,    19,    20,     0,    21,     0,    22,     0,
      23,     0,     0,     0,     0,    24,     0,    25,     0,    26,
      27,     0,     0,    28,     0,     0,    29,     0,     0,     0,
       0,    30,    31,    32,     0,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,    41,    42,
       0,    43,    44,    45,    46,     0,     0,     0,     0,    -5,
       1,    47,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    -5,    14,    -5,    15,    -5,    -5,     0,     0,
       0,    16,     0,     0,    17,    18,     0,    19,    20,     0,
      21,     0,    22,     0,    23,     0,     0,     0,     0,    24,
       0,    25,     0,    26,    27,     0,     0,    28,     0,     0,
      29,     0,     0,     0,     0,    30,    31,    32,     0,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,    41,    42,     0,    43,    44,    45,    46,     0,
       0,     0,     0,    -5,     1,    47,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    -5,    14,     0,    15,
      -5,     0,     0,     0,     0,    16,     0,     0,    17,    18,
       0,    19,    20,     0,    21,     0,    22,     0,    23,     0,
       0,     0,     0,    24,     0,    25,     0,    26,    27,     0,
       0,    28,     0,     0,    29,     0,     0,     0,     0,    30,
      31,    32,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,    41,    42,     0,    43,
      44,    45,    46,     0,     0,     0,     0,    -5,     1,    47,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,    13,     0,     0,     0,     0,     0,     0,     0,
      -5,    14,     0,    15,     0,     0,     0,     0,     0,    16,
       0,     0,    17,    18,     0,    19,    20,     0,    21,     0,
      22,     0,    23,     0,     0,     0,     0,    24,     0,    25,
       0,    26,    27,     0,     0,    28,     0,     0,    29,     0,
       0,     0,     0,    30,    31,    32,     0,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
      41,    42,     0,    43,    44,    45,    46,     0,     0,     0,
       0,     0,     1,    47,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    -5,    14,     0,    15,    -5,     0,
       0,     0,     0,    16,     0,     0,    17,    18,     0,    19,
      20,     0,    21,     0,    22,     0,    23,     0,     0,     0,
       0,    24,     0,    25,     0,    26,    27,     0,     0,    28,
       0,     0,    29,     0,     0,     0,     0,    30,    31,    32,
       0,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,    41,    42,     0,    43,    44,    45,
      46,     2,     3,     4,     5,     6,     0,    47,     0,     0,
       0,   335,     0,    13,     0,     0,     0,     0,     0,     0,
       0,    97,    14,     0,    15,     0,     0,     0,     0,     0,
      16,     0,     0,    17,    18,     0,    19,    20,     0,    21,
       0,    22,     0,    23,     0,     0,     0,     0,    24,     0,
      25,     0,    26,     0,     0,     0,    28,     0,     0,    29,
       0,     0,     0,     0,    30,    31,    32,     0,    33,    34,
       0,     0,    35,    36,    37,    38,    39,     2,     3,     4,
       5,     6,     0,     0,     0,     0,     0,   335,    40,    13,
       0,     0,    42,     0,     0,     0,    45,    46,    14,     0,
      15,     0,     0,     0,    47,     0,    16,     0,     0,    17,
      18,     0,    19,    20,     0,    21,     0,    22,     0,    23,
       0,     0,     0,     0,    24,     0,    25,     0,    26,     0,
       0,     0,    28,     0,     0,    29,     0,     0,     0,     0,
      30,    31,    32,     0,    33,    34,     0,     0,    35,    36,
      37,    38,    39,   100,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,    40,    13,     0,     0,    42,     0,
       0,     0,    45,    46,    89,     0,    15,     0,     0,     0,
      47,     0,    16,     0,     0,    17,    18,     0,    19,    20,
       0,    21,     0,    22,     0,    23,     0,     0,     0,     0,
      24,     0,    25,     0,    26,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,     0,
      33,    34,     0,     0,    35,    36,    37,    38,    39,     0,
     100,     3,     4,     5,     6,     0,     0,     0,     0,     0,
      40,     0,    13,     0,    42,   325,     0,     0,    45,    46,
      97,    89,     0,    15,     0,     0,    47,     0,     0,    16,
       0,     0,    17,    18,     0,    19,    20,     0,    21,     0,
      22,     0,    23,     0,     0,     0,     0,    24,     0,    25,
       0,    26,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    32,     0,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    88,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,    40,    13,     0,
       0,    42,     0,     0,     0,    45,    46,    89,     0,    15,
       0,     0,     0,    47,     0,    16,     0,     0,    17,    18,
       0,    19,    20,     0,    21,     0,    22,     0,    23,     0,
       0,     0,     0,    24,     0,    25,     0,    26,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,   100,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,    40,    13,     0,     0,    42,     0,     0,
       0,    45,    46,    89,     0,    15,     0,     0,     0,    47,
       0,    16,     0,     0,    17,    18,     0,    19,    20,     0,
      21,     0,    22,     0,    23,     0,     0,     0,     0,    24,
       0,    25,     0,    26,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,    30,    31,    32,     0,    33,
      34,     0,     0,    35,    36,    37,    38,    39,   100,     3,
       4,     5,     6,     0,     0,     0,     0,     0,     0,    40,
      13,     0,     0,    42,     0,     0,     0,    45,    46,    89,
       0,   127,     0,     0,     0,    47,     0,    16,     0,     0,
      17,    18,     0,    19,    20,     0,    21,     0,    22,     0,
      23,     0,     0,     0,     0,    24,     0,    25,     0,    26,
       0,     0,     0,    28,     0,   100,     3,     4,     5,     6,
       0,    30,    31,    32,     0,    33,    34,    13,     0,    35,
      36,    37,    38,    39,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,    16,    40,     0,    17,    18,    42,
       0,     0,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    25,     0,    26,     0,     0,     0,
      28,     0,   100,     3,     4,     5,     6,     0,    30,    31,
      32,     0,    33,    34,    13,     0,    35,    36,    37,    38,
      39,     0,     0,   101,     0,   279,     3,     4,     5,     6,
       0,    16,     0,     0,    17,    18,     0,    13,     0,     0,
      45,    46,     0,     0,     0,     0,   101,     0,    47,     0,
       0,     0,     0,    26,    16,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,    30,    31,    32,     0,    33,
      34,     0,     0,    35,     0,     0,    26,     0,     0,   299,
       3,     4,     5,     6,     0,     0,     0,     0,    30,    31,
      32,    13,    33,    34,     0,     0,    35,    45,    46,     0,
     101,     0,     0,     0,     0,    47,     0,     0,    16,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    47,     0,
      26,     0,     0,    88,     3,     4,     5,     6,     0,     0,
       0,     0,    30,    31,    32,    13,    33,    34,     0,     0,
      35,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,    18,     0,     0,   345,
       0,     0,     0,     0,    45,    46,   151,   152,   153,   154,
     155,   156,    47,     0,    26,     0,     0,     0,     0,     0,
       0,   157,   158,   159,   160,     0,    30,    31,    32,     0,
      33,    34,     0,     0,    35,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   197,
     161,     0,   162,   163,     0,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,     0,     0,
     164,   165,   166,   167,   168,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192
};

static const yytype_int16 yycheck[] =
{
       0,     0,    84,    14,    33,    90,   103,   245,    13,    20,
     107,   245,    23,    85,    14,   250,    43,    14,     3,    29,
      16,    81,    82,    97,   245,    25,     3,   124,    28,    44,
      15,    42,   305,   130,   307,     3,    36,    37,    38,    39,
       3,    40,     3,    26,    24,   350,   351,   144,    52,    24,
     122,    22,    15,   135,    15,    84,    26,    23,    29,     3,
     145,    33,    34,   408,    44,   410,    22,    24,    28,    39,
      53,    23,    25,    29,    30,    28,    28,    92,    89,    89,
      24,    61,    22,    52,    84,    84,    61,    98,    60,    29,
     101,    51,    89,    61,   105,     3,    52,   108,   443,    76,
      69,     6,   113,   114,   115,   378,   117,   112,    22,   169,
      26,   416,    52,    29,    60,    29,   143,    61,    89,   201,
      90,   106,    31,    32,    33,    34,    56,    57,   100,   101,
     102,   103,   104,    89,     3,   135,   135,   197,    52,   449,
     450,   215,    26,   106,    23,   106,    30,   127,    27,    89,
     224,    60,   249,   250,   100,   101,   102,   103,   104,    23,
     470,    25,   142,   174,    28,    24,   240,   414,   415,    26,
     408,    28,   410,    23,   408,    89,   410,    24,    28,   175,
      23,    23,   178,   179,    24,    28,    28,   408,    23,   410,
      25,   100,   101,   102,   103,   104,   431,   208,    23,   210,
      30,   201,   201,    28,   451,   443,   332,   279,   334,   443,
     221,   211,   309,   209,     3,   212,    25,   217,   217,    28,
     231,    24,   443,   219,   235,     3,   323,    37,   325,    28,
     436,   305,   438,   232,   245,   215,   333,   432,   312,   434,
      50,   246,     0,    53,   224,   245,   245,   252,   253,    23,
     279,   348,    37,   327,   234,   352,   236,    56,    57,     8,
     240,    11,    72,    73,   338,    50,    52,    53,    53,    10,
       9,    14,    12,    37,   356,    28,   100,   101,   102,   103,
     104,    25,    24,   288,    29,   357,    50,    72,    73,    53,
      26,    24,    26,   304,   305,     3,   307,    58,    61,   359,
     360,   312,    58,   314,   331,   390,    58,    29,    72,    73,
      40,   371,    25,    37,    24,   412,   315,     3,   329,    25,
      25,   395,    46,    47,    48,    49,    50,   356,   402,    53,
      25,   428,   429,    25,   408,   417,    91,    53,   420,    29,
      64,    65,   149,   150,    42,     3,    53,   327,    72,    73,
     447,    51,     3,    25,    51,    51,   356,   356,   338,   364,
      27,     3,    22,    13,    58,   172,   173,   378,    29,   176,
     177,    27,    25,   384,   385,    59,   387,     4,    30,    25,
      27,   217,   148,   400,   146,   309,   329,   232,   211,   400,
     423,   246,   299,   424,   290,   289,    -1,   408,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,   408,
     410,   410,    -1,    -1,    -1,   395,    -1,   417,   417,    -1,
     420,   420,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   432,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,   443,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    32,    -1,    -1,
      35,    36,    -1,    38,    39,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,
      55,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,     0,
       1,   106,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    -1,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    -1,    54,    55,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,     0,     1,   106,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    36,
      -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    -1,    54,    55,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,     0,     1,   106,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    36,    -1,    38,    39,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      -1,    54,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,     1,   106,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38,
      39,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    -1,    54,    55,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,    98,
      99,     3,     4,     5,     6,     7,    -1,   106,    -1,    -1,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    -1,    38,    39,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    90,    15,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,    24,    -1,
      26,    -1,    -1,    -1,   106,    -1,    32,    -1,    -1,    35,
      36,    -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,    -1,
      -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    15,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,    24,    -1,    26,    -1,    -1,    -1,
     106,    -1,    32,    -1,    -1,    35,    36,    -1,    38,    39,
      -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,    54,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    15,    -1,    94,    95,    -1,    -1,    98,    99,
      23,    24,    -1,    26,    -1,    -1,   106,    -1,    -1,    32,
      -1,    -1,    35,    36,    -1,    38,    39,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    90,    15,    -1,
      -1,    94,    -1,    -1,    -1,    98,    99,    24,    -1,    26,
      -1,    -1,    -1,   106,    -1,    32,    -1,    -1,    35,    36,
      -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    -1,    54,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    15,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,    24,    -1,    26,    -1,    -1,    -1,   106,
      -1,    32,    -1,    -1,    35,    36,    -1,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    -1,    54,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      15,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,    24,
      -1,    26,    -1,    -1,    -1,   106,    -1,    32,    -1,    -1,
      35,    36,    -1,    38,    39,    -1,    41,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,
      -1,    -1,    -1,    58,    -1,     3,     4,     5,     6,     7,
      -1,    66,    67,    68,    -1,    70,    71,    15,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    90,    -1,    35,    36,    94,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    52,    -1,    54,    -1,    -1,    -1,
      58,    -1,     3,     4,     5,     6,     7,    -1,    66,    67,
      68,    -1,    70,    71,    15,    -1,    74,    75,    76,    77,
      78,    -1,    -1,    24,    -1,     3,     4,     5,     6,     7,
      -1,    32,    -1,    -1,    35,    36,    -1,    15,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    24,    -1,   106,    -1,
      -1,    -1,    -1,    54,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
      71,    -1,    -1,    74,    -1,    -1,    54,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    66,    67,
      68,    15,    70,    71,    -1,    -1,    74,    98,    99,    -1,
      24,    -1,    -1,    -1,    -1,   106,    -1,    -1,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      54,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    66,    67,    68,    15,    70,    71,    -1,    -1,
      74,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    98,    99,    16,    17,    18,    19,
      20,    21,   106,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    -1,    66,    67,    68,    -1,
      70,    71,    -1,    -1,    74,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    50,
      60,    -1,    62,    63,    -1,    -1,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    15,    24,    26,    32,    35,    36,    38,
      39,    41,    43,    45,    50,    52,    54,    55,    58,    61,
      66,    67,    68,    70,    71,    74,    75,    76,    77,    78,
      90,    93,    94,    96,    97,    98,    99,   106,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   122,   123,   126,
     127,   128,   129,   139,   143,   144,   145,   146,   147,   148,
     149,   150,   153,   156,   157,   158,   163,   165,   166,    22,
      29,    30,    52,    89,   162,   173,   187,   187,     3,    24,
     127,   143,   145,   147,   159,   160,   164,    23,   169,   170,
       3,    24,   156,   143,   147,    24,     3,   143,   169,   147,
       6,   147,     3,    24,    24,    24,   173,    24,   147,   147,
     147,   147,     3,   127,   154,   155,     3,    26,   143,     3,
     120,   169,     3,    76,     0,    23,     8,    10,    11,     9,
      12,    14,    24,    61,   133,   136,   137,   138,   169,    56,
      57,    16,    17,    18,    19,    20,    21,    31,    32,    33,
      34,    60,    62,    63,   100,   101,   102,   103,   104,    37,
      46,    47,    48,    49,    50,    53,    64,    65,    72,    73,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   174,   175,   177,   178,    50,   174,   110,
     173,   162,    22,    29,    89,   161,   133,    25,    50,    53,
      25,    28,    28,   170,   143,   167,   168,    26,   121,    53,
     143,    29,   121,   143,   171,   181,   187,   143,   143,   143,
     143,   162,    28,   121,    24,   169,    26,    53,   121,     3,
     118,   119,   120,   110,    25,   169,   120,    30,   121,   172,
     133,   138,     3,    15,   129,   144,   144,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   174,   144,   144,   143,     3,
     156,   144,   144,   156,   156,     3,    24,    61,   182,   183,
     184,   185,   174,   188,   110,    58,    58,    58,   143,     3,
     143,   147,   160,   145,    29,    28,   169,   170,   109,    40,
      25,   143,    28,   169,   170,    24,   140,    25,    25,    25,
      25,   143,   155,    91,   169,    95,   143,   151,   152,   169,
       3,    29,    28,   169,   170,    13,   117,   126,   134,   135,
     139,   143,   147,   158,   181,    38,   174,   176,    42,   131,
     121,   121,   172,   187,   187,    51,   162,   173,    53,    29,
      89,   179,   180,     3,    69,   186,   187,     3,   185,     3,
     183,    28,    51,    51,   161,    25,   143,   168,   170,    27,
     168,    27,   121,   153,    44,    92,   143,   170,    51,   143,
     127,   141,   142,   121,     3,   124,   125,   121,   121,   169,
     170,   143,   151,   120,   119,   121,   119,    13,    28,   169,
     170,   121,    58,   130,   131,   131,   121,    22,   110,   173,
     162,   174,   174,    25,    28,   187,   174,   168,   143,   143,
     143,   133,    23,    25,    28,    29,    28,   169,   170,    27,
     152,   169,   135,   170,    25,   135,   121,    59,   132,   130,
     130,   131,   110,   110,   176,   179,   121,   121,   172,   142,
     142,     4,   125,    25,   125,    27,   135,   121,   132,   132,
     130,   132
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   120,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   124,   124,   124,   125,   125,   126,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     136,   137,   137,   138,   139,   140,   141,   141,   141,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   148,   148,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   153,   153,   153,
     154,   154,   155,   155,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   160,   160,   161,   161,   161,   161,   161,
     161,   162,   162,   162,   163,   164,   164,   165,   166,   167,
     167,   167,   167,   168,   169,   169,   170,   170,   171,   171,
     171,   171,   172,   173,   174,   174,   174,   175,   175,   175,
     175,   175,   176,   176,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   178,   179,   179,   180,   180,   180,   181,
     181,   182,   182,   183,   183,   184,   185,   185,   186,   186,
     186,   186,   187,   187,   188,   188
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
       8,     1,     2,     1,     2,     3,     4,     3,     4,     1,
       3,     2,     2,     0,     2,     0,     2,     0,     2,     5,
       2,     1,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     3,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     3,     3,     4,     1,     7,     7,     3,     7,
       6,     1,     3,     2,     2,     3,     5,     5,     3,     5,
       3,     1,     3,     1,     3,     2,     4,     4,     4,     4,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     4,     5,     5,     6,
       4,     1,     3,     2,     4,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     5,     1,     3,     5,     5,     1,
       3,     4,     3,     3,     0,     1,     1,     2,     1,     3,
       4,     3,     2,     2,     1,     3,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     2,     0,     1,     3,     0,
       1,     2,     1,     1,     2,     2,     2,     1,     0,     1,
       1,     2,     2,     4,     1,     3
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
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].functionName)->name.c_str(), (yyvsp[-5].functionName)->templateTypeNames, (yyvsp[-5].functionName)->attributes, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-5].functionName); 
					}

    break;

  case 58:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-6].functionName)->name.c_str(), (yyvsp[-6].functionName)->templateTypeNames, (yyvsp[-6].functionName)->attributes, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 59:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-6].functionName)->name.c_str(), (yyvsp[-6].functionName)->templateTypeNames, (yyvsp[-6].functionName)->attributes, 
							nullptr, shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 60:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-7].functionName)->name.c_str(), (yyvsp[-7].functionName)->templateTypeNames, (yyvsp[-7].functionName)->attributes, 
							shared_ptr<CTypeNameList>((yyvsp[-6].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 61:

    { (yyval.functionName) = new CFunctionName((yyvsp[0].string)->c_str(), nullptr, nullptr); delete (yyvsp[0].string); }

    break;

  case 62:

    { (yyval.functionName) = new CFunctionName((yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), nullptr); delete (yyvsp[-1].string); }

    break;

  case 63:

    { (yyval.functionName) = new CFunctionName((yyvsp[0].string)->c_str(), nullptr, nullptr); delete (yyvsp[0].string); }

    break;

  case 64:

    { (yyval.functionName) = new CFunctionName((yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), nullptr); delete (yyvsp[-1].string); }

    break;

  case 65:

    { (yyval.functionName) = new CFunctionName((yyvsp[0].string)->c_str(), nullptr, shared_ptr<vector<string>>((yyvsp[-2].strings))); delete (yyvsp[0].string); }

    break;

  case 66:

    { (yyval.functionName) = new CFunctionName((yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), shared_ptr<vector<string>>((yyvsp[-3].strings))); delete (yyvsp[-1].string); }

    break;

  case 67:

    { (yyval.functionName) = new CFunctionName((yyvsp[0].string)->c_str(), nullptr, shared_ptr<vector<string>>((yyvsp[-2].strings))); delete (yyvsp[0].string); }

    break;

  case 68:

    { (yyval.functionName) = new CFunctionName((yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), shared_ptr<vector<string>>((yyvsp[-3].strings))); delete (yyvsp[-1].string); }

    break;

  case 69:

    { (yyval.strings) = new vector<string>(); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 70:

    { (yyval.strings) = (yyvsp[-2].strings); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 71:

    { (yyval.string) = new string("heap"); }

    break;

  case 72:

    { (yyval.string) = (yyvsp[0].string); }

    break;

  case 73:

    { (yyval.node) = nullptr; }

    break;

  case 74:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 75:

    { (yyval.node) = nullptr; }

    break;

  case 76:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 77:

    { (yyval.node) = nullptr; }

    break;

  case 78:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 79:

    { (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 80:

    { (yyval.exprvec) = new NodeList(); }

    break;

  case 81:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 82:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 83:

    { if ((yyvsp[0].node)) { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 84:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 88:

    { (yyval.node) = (yyvsp[0].ccode); }

    break;

  case 89:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 90:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 91:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 92:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 93:

    { string t = (yyvsp[-1].strings)->back(); (yyvsp[-1].strings)->pop_back(); (yyval.typeName) = new CTypeName(CTC_Interface, CTM_Stack, *(yyvsp[-1].strings), t, shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].strings); }

    break;

  case 94:

    { (yyval.node) = new NInterface(LOC, *(yyvsp[-2].string), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), nullptr, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 95:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 96:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 97:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 98:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 99:

    { (yyval.node) = nullptr; }

    break;

  case 100:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].functionName)->name.c_str(), (yyvsp[-2].functionName)->templateTypeNames, (yyvsp[-2].functionName)->attributes, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 101:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 103:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 105:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 106:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 109:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 110:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 111:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 112:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 114:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::EQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 115:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::NE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 116:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PEQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 117:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PNE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 118:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 119:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 120:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 121:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 122:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 123:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 124:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 125:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 126:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 127:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mod, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 128:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Xor, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 129:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Or, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 130:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::And, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 131:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::ShiftRight, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 132:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::ShiftLeft, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 133:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 134:

    { (yyval.var) = new NChangeMode(LOC, CTM_Stack, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 135:

    { (yyval.var) = new NChangeMode(LOC, CTM_Local, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 136:

    { (yyval.var) = new NChangeMode(LOC, CTM_Heap, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 137:

    { (yyval.var) = new NChangeMode(LOC, CTM_Weak, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 138:

    { (yyval.var) = new NCopy(LOC, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 139:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 140:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 141:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 142:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 143:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 144:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 145:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 146:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), true); delete (yyvsp[-5].string); }

    break;

  case 147:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), false); delete (yyvsp[-5].string); }

    break;

  case 148:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 149:

    { (yyval.node) = new NSwitch(LOC, shared_ptr<NBase>((yyvsp[-5].node)), *(yyvsp[-2].switchClauses)); delete (yyvsp[-2].switchClauses); }

    break;

  case 150:

    { (yyval.node) = new NSwitch(LOC, nullptr, *(yyvsp[-2].switchClauses)); delete (yyvsp[-2].switchClauses); }

    break;

  case 151:

    { (yyval.switchClauses) = new vector<shared_ptr<NSwitchClause>>(); (yyval.switchClauses)->push_back(shared_ptr<NSwitchClause>((yyvsp[0].switchClause))); }

    break;

  case 152:

    { (yyval.switchClauses) = (yyvsp[-2].switchClauses); (yyval.switchClauses)->push_back(shared_ptr<NSwitchClause>((yyvsp[0].switchClause))); }

    break;

  case 153:

    { (yyval.switchClause) = new NSwitchClause(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 154:

    { (yyval.switchClause) = new NSwitchClause(LOC, nullptr, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 155:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 156:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 157:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 158:

    { (yyval.node) = new NIfValid(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 159:

    { (yyval.node) = new NIfValid(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 160:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 161:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 162:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 163:

    { (yyval.node) = new NVariable(LOC, (yyvsp[0].functionName)->name.c_str(), (yyvsp[0].functionName)->templateTypeNames); delete (yyvsp[0].functionName); }

    break;

  case 164:

    { (yyval.var) = new NVariableStub(shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 165:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].functionName)->name.c_str(), (yyvsp[-1].functionName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].functionName); }

    break;

  case 166:

    { (yyval.var) = new NIsEmptyOrValid(LOC, shared_ptr<NBase>((yyvsp[-1].node)), true); }

    break;

  case 167:

    { (yyval.var) = new NIsEmptyOrValid(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 168:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 169:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 170:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].functionName)->name.c_str(), (yyvsp[0].functionName)->templateTypeNames); delete (yyvsp[0].functionName); }

    break;

  case 171:

    { (yyval.var) = new NParent(LOC); }

    break;

  case 172:

    { (yyval.var) = new NThis(LOC); }

    break;

  case 173:

    { (yyval.var) = new NNegate(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 174:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 175:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 176:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 177:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 178:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 179:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 180:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 181:

    { (yyval.var) = new NNullPtr(LOC); }

    break;

  case 182:

    { (yyval.var) = new NUnderscore(LOC); }

    break;

  case 183:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 184:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 185:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 186:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 187:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 188:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 189:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 190:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 191:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 192:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 193:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 194:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 195:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 196:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 197:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 198:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 199:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 200:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 201:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 202:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 203:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 204:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[-1].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec))); }

    break;

  case 205:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 206:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 207:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 208:

    { (yyval.node) = new NHash(LOC, *(yyvsp[-2].hashArgs)); delete (yyvsp[-2].hashArgs); }

    break;

  case 209:

    { (yyval.hashArgs) = new vector<pair<shared_ptr<NBase>, shared_ptr<NBase>>>(); (yyval.hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 210:

    { (yyvsp[-2].hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 211:

    { (yyvsp[-3].hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 212:

    { (yyvsp[-2].hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 213:

    { (yyval.hashArg) = new pair<shared_ptr<NBase>, shared_ptr<NBase>>(shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 214:

    { (yyval.node) = nullptr; }

    break;

  case 215:

    { (yyval.node) = nullptr; }

    break;

  case 216:

    { (yyval.node) = nullptr; }

    break;

  case 217:

    { (yyval.node) = nullptr; }

    break;

  case 218:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 219:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 220:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 221:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 222:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 223:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 224:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 225:

    { (yyval.typeName) = new CTypeName((yyvsp[-1].typeNameParts)->isHash ? CTC_Interface : CTC_Value, (yyvsp[-2].typeMode), (yyvsp[-1].typeNameParts)->packageNamespace, (yyvsp[-1].typeNameParts)->name, shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].typeNameParts); }

    break;

  case 226:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 227:

    { (yyval.typeMode) = CTM_Undefined; }

    break;

  case 228:

    { (yyval.typeMode) = CTM_Local; }

    break;

  case 229:

    { (yyval.typeMode) = CTM_Stack; }

    break;

  case 230:

    { (yyval.typeMode) = CTM_Heap; }

    break;

  case 231:

    { (yyval.typeMode) = CTM_Weak; }

    break;

  case 232:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 233:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, "void", false); }

    break;

  case 234:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i32", false); }

    break;

  case 235:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u32", false); }

    break;

  case 236:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f32", false); }

    break;

  case 237:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i64", false); }

    break;

  case 238:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u64", false); }

    break;

  case 239:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f64", false); }

    break;

  case 240:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "char", false); }

    break;

  case 241:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "bool", false); }

    break;

  case 242:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "ptr", false); }

    break;

  case 243:

    { (yyval.typeName) = new CTypeName((yyvsp[-4].typeMode), shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 244:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Mutable; }

    break;

  case 245:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Immutable; }

    break;

  case 246:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 247:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 248:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 249:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 250:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 251:

    { (yyval.typeNameParts) = (yyvsp[0].typeNameParts); (yyval.typeNameParts)->packageNamespace = *(yyvsp[-1].strings); delete (yyvsp[-1].strings); }

    break;

  case 252:

    { (yyval.typeNameParts) = (yyvsp[0].typeNameParts); }

    break;

  case 253:

    { (yyval.strings) = new vector<string>(); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 254:

    { (yyval.strings) = (yyvsp[0].strings); (yyval.strings)->push_back(*(yyvsp[-1].string)); delete (yyvsp[-1].string); }

    break;

  case 255:

    { (yyval.string) = (yyvsp[-1].string); }

    break;

  case 256:

    { (yyval.typeNameParts) = new CTypeNameParts(); (yyval.typeNameParts)->isHash = true;  (yyval.typeNameParts)->name = *(yyvsp[0].string); delete (yyvsp[0].string); }

    break;

  case 257:

    { (yyval.typeNameParts) = new CTypeNameParts(); (yyval.typeNameParts)->isHash = false; (yyval.typeNameParts)->name = *(yyvsp[0].string); delete (yyvsp[0].string); }

    break;

  case 258:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 259:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 260:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 261:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 262:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 263:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 264:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 265:

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

