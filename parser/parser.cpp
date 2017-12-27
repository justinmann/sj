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



#include <sjc.h>
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
    TAT = 361,
    TCARET = 362
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
#define YYFINAL  141
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1827

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  268
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  478

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   362

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
     105,   106,   107
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   128,   129,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   150,   151,   154,   155,   158,   159,   162,   163,   166,
     167,   170,   171,   174,   175,   178,   179,   180,   183,   184,
     187,   188,   191,   194,   195,   196,   197,   198,   199,   200,
     201,   204,   207,   208,   209,   212,   213,   216,   222,   227,
     232,   239,   240,   241,   242,   243,   244,   245,   246,   249,
     250,   253,   254,   257,   258,   261,   262,   265,   266,   269,
     270,   273,   274,   275,   276,   279,   280,   281,   282,   283,
     286,   289,   290,   293,   296,   299,   302,   303,   304,   307,
     308,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   323,   324,   325,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   361,   362,   363,   364,   365,   368,   369,
     372,   375,   376,   379,   380,   383,   384,   387,   388,   389,
     390,   391,   394,   395,   398,   399,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   427,   428,   429,
     430,   431,   432,   433,   436,   437,   440,   441,   444,   445,
     446,   447,   448,   449,   452,   453,   454,   457,   460,   461,
     464,   467,   470,   471,   472,   473,   476,   479,   480,   483,
     484,   487,   488,   489,   490,   493,   496,   499,   500,   501,
     504,   505,   506,   507,   508,   511,   512,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   526,   529,   530,   533,
     534,   535,   538,   539,   542,   543,   546,   547,   550,   553,
     554,   557,   558,   559,   560,   563,   564,   567,   568
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
  "TAT", "TCARET", "$accept", "program", "stmts", "stmt", "cblock",
  "cdefine", "cstruct", "cfunction", "cinclude", "ctypedef", "cvar",
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
     355,   356,   357,   358,   359,   360,   361,   362
};
# endif

#define YYPACT_NINF -357

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-357)))

#define YYTABLE_NINF -209

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     787,  -357,    31,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,   -10,  1296,    45,  1562,  -357,  -357,  -357,
    1372,    57,    47,  1372,    45,  1562,  -357,    93,  1562,   103,
      98,   107,   131,   126,   141,  -357,  1562,  1562,  1562,  1562,
      20,   180,  1448,   187,    45,  -357,  -357,  1562,    18,   140,
     197,   189,  -357,   207,   226,   234,   248,   249,   257,  -357,
    -357,  -357,    16,    45,  -357,  -357,  -357,  -357,   169,   129,
     304,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  1740,  1707,  -357,   463,    41,  -357,  -357,
      44,  1372,   267,   247,    84,   120,   147,  -357,   266,    45,
    1372,  -357,   -10,  1372,   121,   270,   121,  1372,   268,   270,
    1372,   121,  -357,   121,   -10,  1372,  1372,  1372,  -357,  1372,
     121,   121,   121,   121,    99,  -357,   172,  -357,   274,    45,
     275,  -357,   101,   300,   121,  -357,  -357,   219,   894,  -357,
     270,  -357,   679,  -357,  -357,  -357,  -357,  -357,  -357,   187,
      88,   267,   251,  -357,    28,  1505,  1505,  1505,  1505,  1505,
    1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,
    1505,  1505,  1505,  1505,  1505,  1505,  1740,  -357,  -357,  1505,
    1505,  1372,  1584,  1505,  1505,  1562,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
      48,  -357,  -357,  1740,  -357,  -357,  -357,   571,   252,   255,
     256,  -357,  -357,  -357,  1372,  1638,  1372,  1660,  1505,  -357,
     278,    46,  -357,  1562,   269,   291,  1372,  -357,  -357,    52,
     294,  -357,   296,   302,   305,   307,  1372,    20,   228,    45,
    1143,    45,   317,  -357,   310,   246,  -357,   272,  -357,  1067,
      55,  -357,  -357,     4,  1694,   292,   270,    88,  -357,   -10,
     -10,  -357,  -357,  -357,   245,   245,   245,   245,   245,   245,
     295,   295,   162,   162,   308,   245,   245,  -357,   261,   261,
     261,   261,   261,  -357,  -357,  -357,   285,    31,  -357,  -357,
    -357,  -357,   306,    -5,   341,     2,    49,   357,  -357,  -357,
      34,  -357,  -357,  -357,  -357,   311,    44,  -357,   120,  -357,
     336,  1372,  1220,   343,  1372,     7,  -357,    23,  1220,   320,
    1372,    29,  -357,  -357,  -357,  -357,  -357,  -357,  -357,   270,
     369,   270,   150,    45,  -357,  1143,  -357,   187,   300,   270,
     300,  -357,   361,  -357,   259,  -357,  -357,  -357,   202,  -357,
    -357,  -357,  -357,  -357,  -357,   270,   318,   292,   292,   270,
    -357,  -357,   353,   463,    41,  -357,  1740,  1740,  -357,   171,
    -357,   -10,  -357,  -357,  -357,  -357,   306,  -357,  1740,  -357,
    -357,  -357,  -357,  -357,  -357,  1372,  -357,  -357,  -357,  -357,
    1372,  1372,  -357,  1372,  -357,  -357,   267,   223,  -357,  -357,
     355,   262,  -357,  -357,  -357,   358,  1143,   270,    45,   272,
    -357,  -357,  -357,  -357,   991,   362,  1067,  -357,   270,   329,
     318,   318,   292,   571,  -357,  -357,   571,  -357,  -357,  1694,
      -5,  -357,  -357,  -357,   270,   270,  -357,   359,    29,  -357,
      29,   387,   369,   367,   369,  -357,  -357,   366,  -357,  1067,
    -357,  -357,  -357,   270,  -357,   329,   329,   318,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   329,  -357
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    20,    61,   178,   179,   182,   183,    22,    28,    24,
      26,    30,    32,    63,     0,   217,     0,   180,   181,   110,
       0,     0,     0,     0,   217,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,   217,   185,   184,     0,     0,     0,
       0,     2,     3,    11,    12,    13,    14,    15,    16,     6,
       9,     7,   172,   217,    69,     8,    10,   105,   113,   122,
     142,   102,   104,   103,   101,   147,   177,    43,   106,   107,
     108,   204,   206,   230,   230,   205,     0,     0,    62,    64,
      61,     0,   172,     0,   113,   142,     0,   194,     0,   219,
       0,   218,    61,     0,   134,     0,   142,     0,     0,     0,
       0,   135,    17,   140,   252,     0,     0,     0,   186,     0,
     136,   138,   139,   137,    61,   165,     0,   163,     0,   217,
       0,    41,     0,     0,   133,    72,    71,   217,     0,   174,
       0,     1,     0,    21,    23,    25,    27,    29,    31,     0,
     167,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,    44,    45,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,   231,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   226,
       0,   227,   229,   230,   265,   187,   188,     0,   198,   200,
     199,   196,   167,   166,     0,     0,     0,     0,     0,   220,
       0,   217,   212,     0,   157,     0,     0,   150,   221,   217,
       0,   253,     0,     0,     0,     0,     0,     0,   160,   217,
       0,   217,     0,    18,    41,   217,    37,    39,    80,     0,
       0,   173,     4,   252,   230,    75,     0,     0,    92,    65,
      67,    70,   111,   112,   114,   115,   118,   119,   120,   121,
     123,   124,   125,   126,   127,   116,   117,   141,   128,   129,
     130,   132,   131,   143,    46,    47,     0,    61,   144,    48,
      49,   145,   260,   249,     0,   261,     0,   256,   255,   267,
       0,   189,   201,   203,   202,     0,    61,   193,     0,   195,
     209,     0,     0,     0,   218,     0,   109,     0,     0,     0,
     218,    99,    94,   168,   169,   170,   171,   164,   162,     0,
       0,     0,     0,   217,   153,     0,    40,     0,     0,     0,
     218,    34,    88,    87,   217,    81,    85,    89,   142,    86,
      42,    93,   236,   235,   225,     0,    73,    75,    75,     0,
      66,    68,   146,     0,     0,   258,   230,   230,   250,     0,
     259,   262,   228,   263,   260,   254,     0,   257,   230,   266,
     146,   197,   207,   216,   215,     0,   211,   213,   158,   159,
       0,     0,   224,     0,   210,   222,     0,     0,    96,   161,
      55,   217,    54,   156,   155,     0,   218,     0,   217,    38,
      36,    19,    35,    33,     0,     0,   218,    76,     0,    77,
      73,    73,    75,     0,   190,   191,     0,   248,   247,   230,
       0,   264,   268,   214,     0,     0,   223,     0,    99,    95,
      99,     0,     0,     0,   218,   152,   154,     0,    84,     0,
      79,    82,    74,     0,    57,    77,    77,    73,    50,   192,
     246,   251,   148,   149,   100,    97,    98,    56,    53,    51,
      52,   151,    83,    78,    59,    58,    77,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -357,  -357,   263,   -83,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,   -80,   -26,    27,  -357,  -357,  -357,  -174,  -236,
       1,  -357,   253,  -356,  -309,  -339,   -58,  -357,  -324,  -357,
    -357,   254,  -230,  -357,  -357,  -152,   -12,    26,    -2,  1639,
       0,  -357,  -357,  -357,    65,    -3,    90,  -357,   176,    58,
    -357,  -229,  -357,   201,   113,   -69,  -357,  -357,  -357,  -357,
    -357,  -285,   -18,   -77,  -357,  -242,   -28,   -74,  -357,    -9,
    -357,  -357,    -8,  -357,   168,  -357,   128,  -357,   132,  -357,
      -6,  -357
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     342,   245,   246,   247,   404,    59,    60,   401,   402,    61,
      92,    63,    64,   419,   356,   454,   140,   344,   345,   151,
     152,   153,    65,   322,   397,   398,    66,    67,    68,    69,
     106,    71,    72,    73,   333,   334,    74,   126,   127,    75,
      76,    77,    96,    97,   211,    86,    78,    98,    79,    80,
     221,   222,   100,   101,   229,   256,    87,   353,   200,   354,
     201,   202,   368,   369,   230,   295,   296,   297,   298,   372,
      88,   300
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    62,    93,   205,   150,   118,   110,    89,   105,   199,
     204,   109,    94,   343,    95,   359,   104,   132,   207,   346,
     349,   135,   219,   124,   366,   111,   133,   384,   113,   387,
     130,   259,   102,   138,   212,    13,   120,   121,   122,   123,
     137,   125,    84,   260,    13,   154,    20,   134,   420,   421,
     108,   292,   374,    81,    84,   236,    84,   242,   206,   252,
      82,    83,   378,    81,   455,   456,   208,   390,    99,    99,
      82,   371,   293,   209,   312,    99,   139,   149,   142,    93,
     318,   107,   350,    84,   367,   379,    70,    62,   220,    94,
     448,    93,   451,   257,   136,   225,    84,    40,   228,   112,
     433,   476,   283,   232,   233,   234,   114,   235,   231,   294,
     294,   240,  -208,   457,   138,   391,   474,   475,   254,   249,
      85,    81,   115,   253,   301,   472,    48,   138,    82,   299,
      85,   116,   224,   210,    48,    48,   227,   477,    70,    62,
     155,   156,    70,    62,   314,   157,   158,   159,   160,   161,
     162,    84,   320,   238,   242,   117,    83,   176,   176,   243,
     163,   164,   165,   166,   137,   119,   138,   251,   340,   286,
     214,   214,   216,   215,   223,   217,   138,   255,   343,   311,
     343,   262,   263,   128,   346,   349,   346,   349,    85,   167,
     131,   168,   169,   185,   185,   464,   429,   141,   138,   430,
     237,   170,   305,   313,   307,   284,   285,    70,    62,   289,
     290,   319,   142,   343,   317,   143,   310,   308,   363,   346,
     349,   330,   167,   335,   327,   155,   156,   339,   332,   171,
     172,   173,   174,   175,   170,   385,   144,   347,   125,   176,
     288,   393,    99,   291,   248,   145,   438,   231,   439,   348,
      62,   440,   214,   360,   361,   182,   406,   146,   410,   364,
     412,   147,   171,   172,   173,   174,   175,   416,   468,    99,
     470,   148,   213,   288,   338,   185,   163,   164,   165,   166,
     424,   288,    99,   357,   358,    99,   465,   414,   466,   373,
     442,   137,   427,   428,   218,   426,   138,   226,   239,   383,
     220,   241,   220,   244,   432,   167,   392,   311,   395,   315,
     302,   409,   149,   303,   304,   405,   316,   170,   321,   329,
     336,   323,   396,   407,   444,   242,   415,   324,   165,   166,
     325,   406,   326,   170,   355,   425,   362,   449,   437,   337,
     458,   176,   388,   459,   370,   171,   172,   173,   174,   175,
     177,   178,   179,   180,   181,   167,   399,   182,   403,   365,
     376,   382,   380,    70,    62,   431,   411,   170,   183,   184,
     386,   394,   400,   220,   413,   423,   418,   185,   434,   435,
     170,   436,   417,   443,   441,   445,   422,   450,   453,   254,
     447,   467,   469,   471,   407,   171,   172,   173,   174,   175,
     408,   250,   347,   446,   347,   389,   258,   261,   171,   172,
     173,   174,   175,   328,   348,    62,   348,    62,   309,   381,
     460,   351,   461,    70,    62,   377,    70,    62,   375,     0,
       0,     0,     0,     0,     0,     0,     0,   347,     0,   396,
       0,   396,     0,     0,     0,   452,     0,     0,     0,   348,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   463,    -5,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,     0,
     473,     0,     0,     0,     0,     0,    -5,    14,    -5,    15,
      -5,    -5,     0,    83,     0,    16,     0,     0,    17,    18,
       0,    19,    20,     0,    21,     0,    22,     0,    23,     0,
       0,     0,     0,    24,     0,    25,     0,    26,    27,     0,
       0,    28,     0,     0,    29,     0,     0,     0,     0,    30,
      31,    32,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,    41,    42,     0,    43,
      44,    45,    46,     0,     0,     0,     0,     0,    47,    48,
      49,    -5,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    -5,    14,    -5,    15,    -5,    -5,
       0,     0,     0,    16,     0,     0,    17,    18,     0,    19,
      20,     0,    21,     0,    22,     0,    23,     0,     0,     0,
       0,    24,     0,    25,     0,    26,    27,     0,     0,    28,
       0,     0,    29,     0,     0,     0,     0,    30,    31,    32,
       0,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,    41,    42,     0,    43,    44,    45,
      46,     0,     0,     0,     0,     0,    47,    48,    49,    -5,
       1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    -5,    14,     0,    15,    -5,     0,     0,     0,
       0,    16,     0,     0,    17,    18,     0,    19,    20,     0,
      21,     0,    22,     0,    23,     0,     0,     0,     0,    24,
       0,    25,     0,    26,    27,     0,     0,    28,     0,     0,
      29,     0,     0,     0,     0,    30,    31,    32,     0,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,    41,    42,     0,    43,    44,    45,    46,     0,
       0,     0,     0,     0,    47,    48,    49,    -5,     1,     0,
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
       0,     0,    47,    48,    49,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,    13,
       0,     0,     0,     0,     0,     0,     0,    -5,    14,     0,
      15,    -5,     0,     0,     0,     0,    16,     0,     0,    17,
      18,     0,    19,    20,     0,    21,     0,    22,     0,    23,
       0,     0,     0,     0,    24,     0,    25,     0,    26,    27,
       0,     0,    28,     0,     0,    29,     0,     0,     0,     0,
      30,    31,    32,     0,    33,    34,     0,     0,    35,    36,
      37,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,    41,    42,     0,
      43,    44,    45,    46,     2,     3,     4,     5,     6,    47,
      48,    49,     0,     0,   341,     0,    13,     0,     0,     0,
       0,     0,     0,     0,    99,    14,     0,    15,     0,     0,
       0,     0,     0,    16,     0,     0,    17,    18,     0,    19,
      20,     0,    21,     0,    22,     0,    23,     0,     0,     0,
       0,    24,     0,    25,     0,    26,     0,     0,     0,    28,
       0,     0,    29,     0,     0,     0,     0,    30,    31,    32,
       0,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       2,     3,     4,     5,     6,     0,     0,     0,     0,     0,
     341,    40,    13,     0,     0,    42,     0,     0,     0,    45,
      46,    14,     0,    15,     0,     0,    47,    48,    49,    16,
       0,     0,    17,    18,     0,    19,    20,     0,    21,     0,
      22,     0,    23,     0,     0,     0,     0,    24,     0,    25,
       0,    26,     0,     0,     0,    28,     0,     0,    29,     0,
       0,     0,     0,    30,    31,    32,     0,    33,    34,     0,
       0,    35,    36,    37,    38,    39,   102,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,    40,    13,     0,
       0,    42,     0,     0,     0,    45,    46,    91,     0,    15,
       0,     0,    47,    48,    49,    16,     0,     0,    17,    18,
       0,    19,    20,     0,    21,     0,    22,     0,    23,     0,
       0,     0,     0,    24,     0,    25,     0,    26,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,   102,     3,     4,     5,     6,     0,     0,
       0,     0,     0,    40,     0,    13,     0,    42,   331,     0,
       0,    45,    46,    99,    91,     0,    15,     0,    47,    48,
      49,     0,    16,     0,     0,    17,    18,     0,    19,    20,
       0,    21,     0,    22,     0,    23,     0,     0,     0,     0,
      24,     0,    25,     0,    26,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,     0,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    90,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
      40,    13,     0,     0,    42,     0,     0,     0,    45,    46,
      91,     0,    15,     0,     0,    47,    48,    49,    16,     0,
       0,    17,    18,     0,    19,    20,     0,    21,     0,    22,
       0,    23,     0,     0,     0,     0,    24,     0,    25,     0,
      26,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,    30,    31,    32,     0,    33,    34,     0,     0,
      35,    36,    37,    38,    39,   102,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,    40,    13,     0,     0,
      42,     0,     0,     0,    45,    46,    91,     0,    15,     0,
       0,    47,    48,    49,    16,     0,     0,    17,    18,     0,
      19,    20,     0,    21,     0,    22,     0,    23,     0,     0,
       0,     0,    24,     0,    25,     0,    26,     0,     0,     0,
      28,     0,     0,     0,     0,     0,     0,     0,    30,    31,
      32,     0,    33,    34,     0,     0,    35,    36,    37,    38,
      39,   102,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,    40,    13,     0,     0,    42,     0,     0,     0,
      45,    46,    91,     0,   129,     0,     0,    47,    48,    49,
      16,     0,     0,    17,    18,     0,    19,    20,     0,    21,
       0,    22,     0,    23,     0,     0,     0,     0,    24,     0,
      25,     0,    26,     0,     0,     0,    28,     0,   102,     3,
       4,     5,     6,     0,    30,    31,    32,     0,    33,    34,
      13,     0,    35,    36,    37,    38,    39,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,    16,    40,     0,
      17,    18,    42,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,    47,    48,    49,     0,    25,     0,    26,
       0,     0,     0,    28,     0,   102,     3,     4,     5,     6,
       0,    30,    31,    32,     0,    33,    34,    13,     0,    35,
      36,    37,    38,    39,     0,     0,   103,   287,     3,     4,
       5,     6,     0,     0,     0,     0,     0,    17,    18,    13,
       0,     0,     0,    45,    46,     0,     0,     0,   103,     0,
      47,    48,    49,     0,     0,     0,    26,     0,     0,    17,
      18,     0,     0,     0,     0,     0,     0,     0,    30,    31,
      32,     0,    33,    34,     0,     0,    35,     0,    26,     0,
       0,   306,     3,     4,     5,     6,     0,     0,     0,     0,
      30,    31,    32,    13,    33,    34,     0,     0,    35,     0,
      45,    46,   103,    90,     3,     4,     5,     6,    48,    49,
       0,     0,     0,    17,    18,    13,     0,     0,     0,     0,
       0,     0,    45,    46,   103,     0,     0,     0,     0,     0,
      48,    49,    26,     0,     0,    17,    18,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    32,     0,    33,    34,
       0,     0,    35,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,     0,
      33,    34,   352,     0,    35,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,    45,    46,
       0,     0,     0,     0,     0,     0,    48,    49,     0,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198
};

static const yytype_int16 yycheck[] =
{
       0,     0,    14,    86,    62,    33,    24,    13,    20,    83,
      84,    23,    14,   249,    14,   257,    16,    43,    87,   249,
     249,     3,    99,     3,    29,    25,    44,   312,    28,   314,
      42,     3,     3,    26,    92,    15,    36,    37,    38,    39,
      24,    40,    52,    15,    15,    63,    39,    47,   357,   358,
       3,     3,     3,    22,    52,   124,    52,    53,    86,   142,
      29,    30,    28,    22,   420,   421,    22,    44,    23,    23,
      29,    69,    24,    29,    28,    23,    49,    61,    23,    91,
      28,    24,    27,    52,    89,    51,    86,    86,   100,    91,
     414,   103,   416,   151,    76,   107,    52,    90,   110,     6,
     385,   457,   176,   115,   116,   117,     3,   119,   114,    61,
      61,   129,    28,   422,    26,    92,   455,   456,    30,   137,
      89,    22,    24,   149,   207,   449,   106,    26,    29,   203,
      89,    24,   105,    89,   106,   106,   109,   476,   138,   138,
      56,    57,   142,   142,   221,    16,    17,    18,    19,    20,
      21,    52,   229,   126,    53,    24,    30,    37,    37,   132,
      31,    32,    33,    34,    24,    24,    26,   140,   245,   181,
      50,    50,    25,    53,    53,    28,    26,   150,   414,    29,
     416,   155,   156,     3,   414,   414,   416,   416,    89,    60,
       3,    62,    63,    73,    73,   437,    25,     0,    26,    28,
      28,    72,   214,   221,   216,   179,   180,   207,   207,   183,
     184,   229,    23,   449,   226,     8,   218,   217,   287,   449,
     449,   239,    60,   241,   236,    56,    57,   245,   240,   100,
     101,   102,   103,   104,    72,   312,    10,   249,   237,    37,
     182,   318,    23,   185,    25,    11,    23,   253,    25,   249,
     249,    28,    50,   259,   260,    53,   333,     9,   338,   287,
     340,    12,   100,   101,   102,   103,   104,   344,   442,    23,
     444,    14,    25,   215,    28,    73,    31,    32,    33,    34,
     363,   223,    23,   256,   257,    23,   438,    28,   440,   295,
      28,    24,   366,   367,    28,   364,    26,    29,    24,   311,
     312,    26,   314,     3,   378,    60,   318,    29,   320,    40,
      58,   337,    61,    58,    58,   333,    25,    72,    24,    91,
       3,    25,   321,   335,   401,    53,   344,    25,    33,    34,
      25,   408,    25,    72,    42,   363,    51,   414,   396,    29,
     423,    37,   315,   426,     3,   100,   101,   102,   103,   104,
      46,    47,    48,    49,    50,    60,   329,    53,   331,    53,
       3,    25,    51,   363,   363,   371,   339,    72,    64,    65,
      27,    51,     3,   385,    13,    22,    58,    73,   390,   391,
      72,   393,   355,   401,    29,    27,   359,    25,    59,    30,
     408,     4,    25,    27,   406,   100,   101,   102,   103,   104,
     335,   138,   414,   406,   416,   315,   152,   154,   100,   101,
     102,   103,   104,   237,   414,   414,   416,   416,   217,   306,
     429,   253,   430,   423,   423,   297,   426,   426,   296,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,   438,
      -1,   440,    -1,    -1,    -1,   418,    -1,    -1,    -1,   449,
     449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   434,   435,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    -1,
     453,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    32,    -1,    -1,    35,    36,
      -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    -1,    54,    55,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38,
      39,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    -1,    54,    55,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    -1,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    -1,    54,    55,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,     0,     1,    -1,
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
      -1,    -1,   105,   106,   107,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,    55,
      -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    98,    99,     3,     4,     5,     6,     7,   105,
     106,   107,    -1,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38,
      39,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    -1,    54,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    90,    15,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,    24,    -1,    26,    -1,    -1,   105,   106,   107,    32,
      -1,    -1,    35,    36,    -1,    38,    39,    -1,    41,    -1,
      43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    90,    15,    -1,
      -1,    94,    -1,    -1,    -1,    98,    99,    24,    -1,    26,
      -1,    -1,   105,   106,   107,    32,    -1,    -1,    35,    36,
      -1,    38,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    -1,    54,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    15,    -1,    94,    95,    -1,
      -1,    98,    99,    23,    24,    -1,    26,    -1,   105,   106,
     107,    -1,    32,    -1,    -1,    35,    36,    -1,    38,    39,
      -1,    41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,    54,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    15,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,
      24,    -1,    26,    -1,    -1,   105,   106,   107,    32,    -1,
      -1,    35,    36,    -1,    38,    39,    -1,    41,    -1,    43,
      -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,
      54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    15,    -1,    -1,
      94,    -1,    -1,    -1,    98,    99,    24,    -1,    26,    -1,
      -1,   105,   106,   107,    32,    -1,    -1,    35,    36,    -1,
      38,    39,    -1,    41,    -1,    43,    -1,    45,    -1,    -1,
      -1,    -1,    50,    -1,    52,    -1,    54,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    70,    71,    -1,    -1,    74,    75,    76,    77,
      78,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    15,    -1,    -1,    94,    -1,    -1,    -1,
      98,    99,    24,    -1,    26,    -1,    -1,   105,   106,   107,
      32,    -1,    -1,    35,    36,    -1,    38,    39,    -1,    41,
      -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    54,    -1,    -1,    -1,    58,    -1,     3,     4,
       5,     6,     7,    -1,    66,    67,    68,    -1,    70,    71,
      15,    -1,    74,    75,    76,    77,    78,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    90,    -1,
      35,    36,    94,    -1,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,    -1,    52,    -1,    54,
      -1,    -1,    -1,    58,    -1,     3,     4,     5,     6,     7,
      -1,    66,    67,    68,    -1,    70,    71,    15,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    24,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    35,    36,    15,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    24,    -1,
     105,   106,   107,    -1,    -1,    -1,    54,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    70,    71,    -1,    -1,    74,    -1,    54,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      66,    67,    68,    15,    70,    71,    -1,    -1,    74,    -1,
      98,    99,    24,     3,     4,     5,     6,     7,   106,   107,
      -1,    -1,    -1,    35,    36,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    24,    -1,    -1,    -1,    -1,    -1,
     106,   107,    54,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      70,    71,    38,    -1,    74,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    15,    24,    26,    32,    35,    36,    38,
      39,    41,    43,    45,    50,    52,    54,    55,    58,    61,
      66,    67,    68,    70,    71,    74,    75,    76,    77,    78,
      90,    93,    94,    96,    97,    98,    99,   105,   106,   107,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   123,
     124,   127,   128,   129,   130,   140,   144,   145,   146,   147,
     148,   149,   150,   151,   154,   157,   158,   159,   164,   166,
     167,    22,    29,    30,    52,    89,   163,   174,   188,   188,
       3,    24,   128,   144,   146,   148,   160,   161,   165,    23,
     170,   171,     3,    24,   148,   144,   148,    24,     3,   144,
     170,   148,     6,   148,     3,    24,    24,    24,   174,    24,
     148,   148,   148,   148,     3,   128,   155,   156,     3,    26,
     144,     3,   121,   170,   148,     3,    76,    24,    26,   122,
     134,     0,    23,     8,    10,    11,     9,    12,    14,    61,
     134,   137,   138,   139,   170,    56,    57,    16,    17,    18,
      19,    20,    21,    31,    32,    33,    34,    60,    62,    63,
      72,   100,   101,   102,   103,   104,    37,    46,    47,    48,
      49,    50,    53,    64,    65,    73,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   175,
     176,   178,   179,    50,   175,   111,   174,   163,    22,    29,
      89,   162,   134,    25,    50,    53,    25,    28,    28,   171,
     144,   168,   169,    53,   122,   144,    29,   122,   144,   172,
     182,   188,   144,   144,   144,   144,   163,    28,   122,    24,
     170,    26,    53,   122,     3,   119,   120,   121,    25,   170,
     110,   122,   111,   121,    30,   122,   173,   134,   139,     3,
      15,   130,   145,   145,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   175,   145,   145,   144,     3,   157,   145,
     145,   157,     3,    24,    61,   183,   184,   185,   186,   175,
     189,   111,    58,    58,    58,   144,     3,   144,   148,   161,
     146,    29,    28,   170,   171,    40,    25,   144,    28,   170,
     171,    24,   141,    25,    25,    25,    25,   144,   156,    91,
     170,    95,   144,   152,   153,   170,     3,    29,    28,   170,
     171,    13,   118,   127,   135,   136,   140,   144,   148,   159,
      27,   182,    38,   175,   177,    42,   132,   122,   122,   173,
     188,   188,    51,   163,   174,    53,    29,    89,   180,   181,
       3,    69,   187,   188,     3,   186,     3,   184,    28,    51,
      51,   162,    25,   144,   169,   171,    27,   169,   122,   154,
      44,    92,   144,   171,    51,   144,   128,   142,   143,   122,
       3,   125,   126,   122,   122,   170,   171,   144,   152,   121,
     120,   122,   120,    13,    28,   170,   171,   122,    58,   131,
     132,   132,   122,    22,   111,   174,   163,   175,   175,    25,
      28,   188,   175,   169,   144,   144,   144,   134,    23,    25,
      28,    29,    28,   170,   171,    27,   153,   170,   136,   171,
      25,   136,   122,    59,   133,   131,   131,   132,   111,   111,
     177,   180,   122,   122,   173,   143,   143,     4,   126,    25,
     126,    27,   136,   122,   133,   133,   131,   133
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   120,   120,
     121,   121,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   125,   125,   125,   126,   126,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   136,   136,   136,   136,   136,
     137,   138,   138,   139,   140,   141,   142,   142,   142,   143,
     143,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   145,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   154,
     154,   154,   155,   155,   156,   156,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   162,   162,   163,   163,   163,   164,   165,   165,
     166,   167,   168,   168,   168,   168,   169,   170,   170,   171,
     171,   172,   172,   172,   172,   173,   174,   175,   175,   175,
     176,   176,   176,   176,   176,   177,   177,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   179,   180,   180,   181,
     181,   181,   182,   182,   183,   183,   184,   184,   185,   186,
     186,   187,   187,   187,   187,   188,   188,   189,   189
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
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     1,     3,     3,     3,     4,     1,     7,     7,
       3,     7,     6,     1,     3,     2,     2,     3,     5,     5,
       3,     5,     3,     1,     3,     1,     3,     2,     4,     4,
       4,     4,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       5,     5,     6,     4,     1,     3,     2,     4,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     5,     1,     3,
       5,     5,     1,     3,     4,     3,     3,     0,     1,     1,
       2,     1,     3,     4,     3,     2,     2,     1,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     2,     2,     0,
       1,     3,     0,     1,     2,     1,     1,     2,     2,     2,
       1,     0,     1,     1,     2,     2,     4,     1,     3
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
						(yyval.node) = new NFunction(LOC, nullptr, (yyvsp[-5].functionName)->name.c_str(), (yyvsp[-5].functionName)->templateTypeNames, (yyvsp[-5].functionName)->attributes, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-5].functionName); 
					}

    break;

  case 58:

    { 
						(yyval.node) = new NFunction(LOC, nullptr, (yyvsp[-6].functionName)->name.c_str(), (yyvsp[-6].functionName)->templateTypeNames, (yyvsp[-6].functionName)->attributes, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 59:

    { 
						(yyval.node) = new NFunction(LOC, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-6].functionName)->name.c_str(), (yyvsp[-6].functionName)->templateTypeNames, (yyvsp[-6].functionName)->attributes, 
							nullptr, shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 60:

    { 
						(yyval.node) = new NFunction(LOC, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-7].functionName)->name.c_str(), (yyvsp[-7].functionName)->templateTypeNames, (yyvsp[-7].functionName)->attributes, 
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

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var)), false); }

    break;

  case 134:

    { (yyval.var) = new NNegate(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 135:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var)), true); }

    break;

  case 136:

    { (yyval.var) = new NChangeMode(LOC, CTM_Stack, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 137:

    { (yyval.var) = new NChangeMode(LOC, CTM_Local, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 138:

    { (yyval.var) = new NChangeMode(LOC, CTM_Heap, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 139:

    { (yyval.var) = new NChangeMode(LOC, CTM_Weak, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 140:

    { (yyval.var) = new NCopy(LOC, shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 141:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 142:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 143:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 144:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 145:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 146:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 147:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 148:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), true); delete (yyvsp[-5].string); }

    break;

  case 149:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), false); delete (yyvsp[-5].string); }

    break;

  case 150:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 151:

    { (yyval.node) = new NSwitch(LOC, shared_ptr<NBase>((yyvsp[-5].node)), *(yyvsp[-2].switchClauses)); delete (yyvsp[-2].switchClauses); }

    break;

  case 152:

    { (yyval.node) = new NSwitch(LOC, nullptr, *(yyvsp[-2].switchClauses)); delete (yyvsp[-2].switchClauses); }

    break;

  case 153:

    { (yyval.switchClauses) = new vector<shared_ptr<NSwitchClause>>(); (yyval.switchClauses)->push_back(shared_ptr<NSwitchClause>((yyvsp[0].switchClause))); }

    break;

  case 154:

    { (yyval.switchClauses) = (yyvsp[-2].switchClauses); (yyval.switchClauses)->push_back(shared_ptr<NSwitchClause>((yyvsp[0].switchClause))); }

    break;

  case 155:

    { (yyval.switchClause) = new NSwitchClause(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 156:

    { (yyval.switchClause) = new NSwitchClause(LOC, nullptr, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 157:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 158:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 159:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 160:

    { (yyval.node) = new NIfValid(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 161:

    { (yyval.node) = new NIfValid(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 162:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 163:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 164:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 165:

    { (yyval.node) = new NVariable(LOC, (yyvsp[0].functionName)->name.c_str(), (yyvsp[0].functionName)->templateTypeNames); delete (yyvsp[0].functionName); }

    break;

  case 166:

    { (yyval.var) = new NVariableStub(shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 167:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].functionName)->name.c_str(), (yyvsp[-1].functionName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].functionName); }

    break;

  case 168:

    { (yyval.var) = new NIsEmptyOrValid(LOC, shared_ptr<NBase>((yyvsp[-1].node)), true); }

    break;

  case 169:

    { (yyval.var) = new NIsEmptyOrValid(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 170:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 171:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 172:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].functionName)->name.c_str(), (yyvsp[0].functionName)->templateTypeNames); delete (yyvsp[0].functionName); }

    break;

  case 173:

    { (yyval.var) = new NVariableStub(make_shared<NLambda>(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<NBase>((yyvsp[0].node)))); }

    break;

  case 174:

    { (yyval.var) = new NVariableStub(make_shared<NLambda>(LOC, nullptr, shared_ptr<NBase>((yyvsp[0].node)))); }

    break;

  case 175:

    { (yyval.var) = new NParent(LOC); }

    break;

  case 176:

    { (yyval.var) = new NThis(LOC); }

    break;

  case 177:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 178:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 179:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 180:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 181:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 182:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 183:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 184:

    { (yyval.var) = new NNullPtr(LOC); }

    break;

  case 185:

    { (yyval.var) = new NUnderscore(LOC); }

    break;

  case 186:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 187:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 188:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 189:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 190:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 191:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 192:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 193:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 194:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 195:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 196:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 197:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 198:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 199:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 200:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 201:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 202:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 203:

    { (yyval.assignOp).isCopy = true; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 204:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 205:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 206:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 207:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[-1].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec))); }

    break;

  case 208:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 209:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 210:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 211:

    { (yyval.node) = new NHash(LOC, *(yyvsp[-2].hashArgs)); delete (yyvsp[-2].hashArgs); }

    break;

  case 212:

    { (yyval.hashArgs) = new vector<pair<shared_ptr<NBase>, shared_ptr<NBase>>>(); (yyval.hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 213:

    { (yyvsp[-2].hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 214:

    { (yyvsp[-3].hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 215:

    { (yyvsp[-2].hashArgs)->push_back(*(yyvsp[0].hashArg)); delete (yyvsp[0].hashArg); }

    break;

  case 216:

    { (yyval.hashArg) = new pair<shared_ptr<NBase>, shared_ptr<NBase>>(shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 217:

    { (yyval.node) = nullptr; }

    break;

  case 218:

    { (yyval.node) = nullptr; }

    break;

  case 219:

    { (yyval.node) = nullptr; }

    break;

  case 220:

    { (yyval.node) = nullptr; }

    break;

  case 221:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 222:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 223:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 224:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 225:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 226:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 227:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 228:

    { (yyval.typeName) = new CTypeName((yyvsp[-1].typeNameParts)->isHash ? CTC_Interface : CTC_Value, (yyvsp[-2].typeMode), (yyvsp[-1].typeNameParts)->packageNamespace, (yyvsp[-1].typeNameParts)->name, shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].typeNameParts); }

    break;

  case 229:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 230:

    { (yyval.typeMode) = CTM_Undefined; }

    break;

  case 231:

    { (yyval.typeMode) = CTM_Local; }

    break;

  case 232:

    { (yyval.typeMode) = CTM_Stack; }

    break;

  case 233:

    { (yyval.typeMode) = CTM_Heap; }

    break;

  case 234:

    { (yyval.typeMode) = CTM_Weak; }

    break;

  case 235:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 236:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, "void", false); }

    break;

  case 237:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i32", false); }

    break;

  case 238:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u32", false); }

    break;

  case 239:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f32", false); }

    break;

  case 240:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i64", false); }

    break;

  case 241:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u64", false); }

    break;

  case 242:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f64", false); }

    break;

  case 243:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "char", false); }

    break;

  case 244:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "bool", false); }

    break;

  case 245:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "ptr", false); }

    break;

  case 246:

    { (yyval.typeName) = new CTypeName((yyvsp[-4].typeMode), shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 247:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Mutable; }

    break;

  case 248:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Immutable; }

    break;

  case 249:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 250:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 251:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 252:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 253:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 254:

    { (yyval.typeNameParts) = (yyvsp[0].typeNameParts); (yyval.typeNameParts)->packageNamespace = *(yyvsp[-1].strings); delete (yyvsp[-1].strings); }

    break;

  case 255:

    { (yyval.typeNameParts) = (yyvsp[0].typeNameParts); }

    break;

  case 256:

    { (yyval.strings) = new vector<string>(); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 257:

    { (yyval.strings) = (yyvsp[0].strings); (yyval.strings)->push_back(*(yyvsp[-1].string)); delete (yyvsp[-1].string); }

    break;

  case 258:

    { (yyval.string) = (yyvsp[-1].string); }

    break;

  case 259:

    { (yyval.typeNameParts) = new CTypeNameParts(); (yyval.typeNameParts)->isHash = true;  (yyval.typeNameParts)->name = *(yyvsp[0].string); delete (yyvsp[0].string); }

    break;

  case 260:

    { (yyval.typeNameParts) = new CTypeNameParts(); (yyval.typeNameParts)->isHash = false; (yyval.typeNameParts)->name = *(yyvsp[0].string); delete (yyvsp[0].string); }

    break;

  case 261:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 262:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 263:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 264:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 265:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 266:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 267:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 268:

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

