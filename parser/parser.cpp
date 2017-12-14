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
    TUNDERSCORE = 353
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
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   353

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
      95,    96,    97,    98
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   108,   109,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     129,   130,   133,   134,   135,   136,   139,   140,   141,   142,
     143,   144,   145,   146,   149,   152,   153,   154,   157,   158,
     161,   167,   172,   177,   184,   185,   188,   189,   192,   193,
     196,   197,   200,   201,   204,   205,   206,   207,   210,   211,
     212,   213,   214,   217,   220,   221,   224,   227,   230,   233,
     234,   235,   238,   239,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   256,   257,   258,   261,
     262,   263,   264,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   290,   291,   292,   293,   294,   297,   298,   301,
     304,   305,   306,   307,   308,   311,   312,   315,   316,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   330,   331,
     332,   333,   334,   335,   336,   339,   340,   341,   342,   343,
     344,   345,   348,   349,   352,   353,   354,   357,   358,   359,
     362,   365,   366,   369,   372,   373,   376,   377,   380,   381,
     382,   383,   386,   389,   392,   393,   394,   395,   398,   399,
     400,   401,   404,   405,   408,   409,   410,   411,   412,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   426,   429,
     430,   433,   434,   435,   438,   439,   442,   443,   444,   445,
     448,   449,   452,   453
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
  "TCASE", "TDEFAULT", "TPACKAGE", "TIMPORT", "TUNDERSCORE", "$accept",
  "program", "stmts", "stmt", "namespace", "block", "var_decl",
  "enum_decl", "enum_args", "enum_arg", "func_decl", "func_type_name",
  "copy", "catch", "destroy", "func_block", "func_args", "func_arg",
  "implement", "implement_args", "implement_arg", "interface_decl",
  "interface_block", "interface_args", "interface_arg", "expr", "expr_and",
  "expr_and_inner", "expr_comp", "expr_math", "expr_var", "for_expr",
  "while_expr", "if_expr", "ifValue_vars", "ifValue_var", "var_right",
  "const", "assign", "assign_tuple", "assign_tuple_arg", "assign_type",
  "tuple", "tuple_args", "array", "end_optional", "end_star", "array_args",
  "return_type_quote", "arg_type_quote", "arg_type", "arg_mode",
  "arg_type_interface", "return_type", "value_type", "func_type",
  "func_arg_type", "func_arg_type_list", "temp_block_optional",
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
     345,   346,   347,   348,   349,   350,   351,   352,   353
};
# endif

#define YYPACT_NINF -296

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-296)))

#define YYTABLE_NINF -163

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     636,  -296,     9,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  1099,  1113,  -296,  -296,  -296,  1026,    22,
      62,  1026,    57,  1113,  -296,    69,  1026,   115,    82,   114,
     112,   151,  -296,  1026,  1026,  1026,  -296,  -296,   176,   190,
     197,   210,   192,  -296,  -296,  -296,  -296,    -1,  -296,  -296,
    -296,   255,  1187,   260,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  1220,  1191,  -296,   354,    20,  -296,    33,
    1104,   195,   219,   201,   152,    87,  -296,  -296,   203,   183,
      45,   362,    74,  1026,   223,   362,    57,  1026,  -296,    45,
    -296,  -296,   183,  1026,  1026,  -296,  1026,  -296,  -296,  -296,
      33,  -296,   273,  -296,   224,  -296,   144,  -296,   542,   142,
     266,   311,   195,   213,  -296,  1104,  1104,  1104,  1104,  1104,
    1104,  1104,  1104,  1104,  1104,  1104,  1104,  1104,  1104,  1104,
    1104,  1220,  -296,  -296,  1104,  1104,  1026,   206,  1104,  1104,
     344,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,    17,  -296,  -296,  1220,  -296,  -296,
    -296,   448,   112,   169,  -296,  -296,  1104,  1104,   774,  1104,
    1190,  1104,   344,  -296,  -296,  -296,   730,   249,  1026,   271,
    1026,  -296,  -296,  -296,    85,   274,  -296,   275,   279,   289,
    1026,   176,   228,    57,   319,  -296,  -296,  -296,   880,   276,
     183,  1153,   284,   362,   311,  -296,  -296,  -296,   125,   125,
     125,   125,   125,   125,   154,   154,    15,    15,   262,   125,
     125,  -296,  -296,  -296,  -296,   283,     9,  -296,  -296,  -296,
    -296,    92,    16,   266,  -296,    42,  -296,  -296,  -296,  -296,
      33,  -296,    51,  -296,   307,   113,    43,   285,  -296,   -18,
     953,   287,  1026,   340,  -296,  -296,  -296,  -296,  -296,  -296,
     362,   342,  -296,  -296,  -296,   239,  -296,  -296,  -296,   145,
    -296,   266,  -296,  -296,    53,  -296,  -296,  -296,   362,   291,
     284,   284,   362,   325,   354,    20,   183,  -296,  -296,  1220,
    1220,  -296,   141,    92,  1220,  -296,  -296,  -296,  -296,  -296,
    -296,  1026,  1026,  -296,  1026,  -296,  -296,   195,   231,  -296,
    -296,   324,   264,  -296,   807,   332,   880,  -296,    92,   266,
    -296,   362,   309,   291,   291,   284,   448,  -296,  -296,   448,
    -296,  -296,  -296,  1153,    16,  -296,  -296,   362,   362,  -296,
     345,   340,  -296,   340,   365,   342,   349,   342,  -296,   880,
    -296,  -296,  -296,    92,  -296,   362,  -296,   309,   309,   291,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,   309,  -296
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    44,   138,   139,   142,   143,    11,    14,    12,
      13,    15,    16,     0,     0,   140,   141,    85,     0,     0,
       0,     0,   164,     0,   135,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,   136,   137,     0,     0,
       0,     0,     2,     3,     6,     9,     7,   133,     8,    10,
      77,    88,   101,   111,    75,    76,    74,   115,   116,    26,
      78,   157,   159,   178,   178,   158,     0,     0,    45,    44,
       0,   133,     0,    92,   111,     0,   152,    91,     0,    44,
     108,     0,   111,     0,     0,     0,   166,     0,   165,   109,
      17,    83,   204,     0,     0,   144,     0,    80,    82,    81,
      44,   128,     0,   126,     0,    21,     0,     1,     0,   164,
       0,   129,     0,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,    27,    28,     0,     0,     0,     0,     0,     0,
       0,   180,   181,   179,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   173,     0,   174,   177,   178,   210,   145,
     146,     0,   154,   111,   129,   112,     0,     0,     0,     0,
       0,     0,     0,    23,    25,    24,     0,   120,     0,     0,
       0,   119,   167,   168,   164,     0,   205,     0,     0,     0,
       0,     0,   123,   164,     0,    18,     4,    53,     0,   182,
     204,   178,    48,     0,     0,    65,    86,    87,    93,    94,
      97,    98,    99,   100,   102,   103,   104,   105,   106,    95,
      96,   107,   110,    29,    30,     0,    44,   113,    31,    32,
     114,   206,   201,     0,   212,     0,   147,   155,    89,    90,
      44,   151,     0,   153,   160,     0,     0,     0,    79,     0,
       0,     0,   165,    72,    67,   130,   131,   132,   127,   125,
       0,     0,    20,    61,    60,   164,    54,    58,    62,   111,
      59,     0,    66,   188,     0,   172,   184,   187,     0,    46,
      48,    48,     0,    84,     0,     0,   207,   175,   208,   178,
     178,   202,     0,   206,   178,   211,   156,    22,   121,   122,
      84,     0,     0,   171,     0,   163,   169,     0,     0,    69,
     124,    38,   164,    37,     0,     0,   165,   183,   206,     0,
      49,     0,    50,    46,    46,    48,     0,   148,   149,     0,
     209,   200,   199,   178,     0,   176,   213,     0,     0,   170,
       0,    72,    68,    72,     0,     0,     0,   165,    57,     0,
      52,    55,   185,   206,    47,     0,    40,    50,    50,    46,
      33,   150,   198,   203,   117,   118,    73,    70,    71,    39,
      36,    34,    35,    56,   186,    51,    42,    41,    50,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -296,  -296,   199,   -62,  -296,   -75,  -296,  -296,  -296,  -156,
    -189,     1,  -295,  -191,  -146,   -69,  -296,  -228,  -296,  -296,
     269,  -174,  -296,  -296,   -51,    37,   110,  -296,    -8,  1162,
       0,  -296,  -296,   133,  -296,   193,   102,  -296,  -166,  -296,
     220,   -20,  -296,  -296,  -296,   -93,   -83,  -296,  -196,   -24,
     -53,  -186,  -221,    60,  -184,  -182,    61,  -296,   200,  -236,
     -85,  -296
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,    42,    43,   106,   177,    44,    45,   312,   313,
      46,    71,   322,   279,   356,   111,   265,   266,   112,   113,
     114,    48,   254,   308,   309,    49,    50,    72,    51,    52,
     163,    54,    55,    56,   102,   103,    57,    58,    59,    75,
      76,    66,    77,    78,    60,    87,    88,   184,   203,    67,
     153,   154,   200,   275,   155,   156,   291,   292,   185,   287,
      68,   235
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    47,   164,   182,   159,    73,    95,   186,   282,   264,
     181,   158,   293,    74,    80,   274,   198,   276,    82,   277,
     231,    82,   109,    89,   267,   301,    82,   192,   357,   358,
      61,   195,   270,    82,    82,    82,   202,    62,    63,   101,
     232,    61,   160,   204,   289,    83,   196,   161,    62,   162,
     317,   173,   174,   175,    61,    81,   318,   335,    85,   110,
      64,    62,    73,    91,   378,    84,    53,    47,   176,   294,
      97,    98,    99,   302,   127,    90,   232,   233,   222,    86,
     190,    18,   352,    82,    64,   130,   348,    82,   351,   323,
     324,   251,   295,    82,    82,    65,    82,   172,   353,   236,
     261,   252,   290,   168,   234,    93,    65,    86,    53,    47,
     131,   169,   250,   319,   170,   186,   140,   374,    92,    65,
     179,   373,   140,   178,   183,   264,   172,   264,   280,   281,
     187,   188,    38,   189,   359,   108,    82,    94,   237,   297,
     267,    63,   267,    64,   366,   140,   288,   274,   270,   276,
     270,   277,   173,   174,   175,   123,   124,   125,   126,   286,
     264,    53,    47,   244,    86,   333,   197,   304,   334,   176,
     242,   298,   315,   225,    96,   267,    53,    47,    82,   100,
      82,   131,   316,   270,   127,   310,   125,   126,   131,   370,
      82,   372,   101,   104,   178,   130,   194,   137,   269,    47,
     105,   330,   285,   320,   168,   131,   284,   325,   288,   226,
     107,   376,   377,   127,   108,   247,   140,   249,   109,   346,
     296,   172,   327,   140,   130,   206,   207,   258,  -161,   347,
     171,   349,   379,   288,    64,   268,   331,   332,   340,   227,
     140,   336,   230,   165,   223,   224,   354,   193,   228,   229,
      82,   180,    82,   341,   307,   342,   166,   167,   343,    24,
     328,    86,   364,   365,   360,   329,   314,   361,   288,   199,
     227,    28,    29,   110,   227,    31,   238,   239,    32,   241,
     375,   173,   174,   175,    53,    47,    86,   303,   246,   306,
     367,   345,   368,    36,    37,   248,   131,   253,   176,   255,
     191,    82,    82,   256,    82,   132,   133,   134,   135,   136,
     115,   116,   137,   257,   269,    47,   269,    47,   260,   173,
     174,   175,   262,   138,   139,   278,    53,    47,   271,    53,
      47,   140,   130,   283,  -162,   300,   176,   305,   337,   338,
     201,   339,   307,    79,   307,   311,   326,    79,   321,   269,
      47,   268,   344,   268,    -5,     1,   350,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   355,    12,   369,
     173,   174,   175,   371,   201,   245,    -5,    13,    -5,   299,
      -5,    -5,   205,    63,   259,    14,   268,   176,    15,    16,
     243,    17,    18,   362,    19,   363,    20,    24,    21,     0,
     272,     0,     0,    22,     0,    23,     0,    24,    25,    28,
      29,    26,     0,    31,    27,     0,    32,     0,     0,    28,
      29,     0,    30,    31,     0,     0,    32,    33,    34,    35,
       0,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,    39,     0,    -5,     1,
      40,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      -5,    13,    -5,     0,    -5,    -5,     0,     0,     0,    14,
       0,     0,    15,    16,     0,    17,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,    22,     0,    23,
       0,    24,    25,     0,     0,    26,     0,     0,    27,     0,
       0,     0,     0,    28,    29,     0,    30,    31,     0,     0,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,     0,    -5,     1,    40,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
       0,     0,     0,     0,    -5,    13,     0,     0,    -5,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,    17,
      18,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,    22,     0,    23,     0,    24,    25,     0,     0,    26,
       0,     0,    27,     0,     0,     0,     0,    28,    29,     0,
      30,    31,     0,     0,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,    39,     0,    -5,     1,    40,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,     0,     0,     0,     0,    -5,    13,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,     0,    17,    18,     0,    19,     0,    20,     0,
      21,     0,     0,     0,     0,    22,     0,    23,     0,    24,
      25,     0,     0,    26,     0,     0,    27,     0,     0,     0,
       0,    28,    29,     0,    30,    31,     0,     0,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,    39,     0,
       0,     1,    40,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,     0,     0,     0,     0,
       0,     0,    -5,    13,     0,     0,    -5,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     0,    17,    18,     0,
      19,     0,    20,     0,    21,     0,     0,   240,     0,    22,
       0,    23,     0,    24,    25,     0,     0,    26,     0,     0,
      27,     0,     0,     0,     0,    28,    29,     0,    30,    31,
       0,     0,    32,    33,    34,    35,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,    36,    37,    38,
     263,     0,    39,     0,     0,     0,    40,    24,     0,    86,
      13,     0,     0,     0,     0,     0,     0,     0,    14,    28,
      29,    15,    16,    31,    17,    18,    32,    19,     0,    20,
       0,    21,     0,     0,     0,     0,    22,     0,    23,     0,
      24,    36,    37,     0,    26,     0,     0,    27,     0,     0,
       0,     0,    28,    29,     0,    30,    31,     0,     0,    32,
      33,    34,    35,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,   263,    36,    37,    38,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     0,    17,    18,     0,
      19,     0,    20,     0,    21,     0,     0,     0,     0,    22,
       0,    23,     0,    24,     0,     0,     0,    26,     0,     0,
      27,     0,     0,     0,     0,    28,    29,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    79,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,     0,     0,    86,    70,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
      17,    18,     0,    19,     0,    20,     0,    21,     0,     0,
       0,     0,    22,     0,    23,     0,    24,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    79,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,     0,    17,    18,     0,    19,     0,    20,     0,
      21,     0,     0,     0,     0,    22,     0,    23,     0,    24,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,    28,    29,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    69,     3,     4,     5,     6,    79,     3,     4,
       5,     6,     0,    36,    37,    38,    79,     3,     4,     5,
       6,     0,    70,     0,     0,     0,     0,    70,     0,     0,
      14,     0,     0,    15,    16,    14,    70,     0,    15,    16,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
      23,     0,    24,     0,     0,    23,     0,    24,     0,     0,
       0,     0,     0,     0,    28,    29,    24,    30,    31,    28,
      29,    32,    30,    31,     0,     0,    32,     0,    28,    29,
       0,    30,    31,     0,     0,    32,    36,    37,     0,     0,
     273,    36,    37,    69,     3,     4,     5,     6,     0,     0,
      36,    37,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,    70,     0,     0,     0,   123,   124,   125,
     126,     0,     0,     0,    15,    16,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     157,     0,     0,    24,     0,     0,   127,     0,   128,   129,
       0,     0,     0,     0,     0,    28,    29,   130,    30,    31,
       0,     0,    32,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,    36,    37,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152
};

static const yytype_int16 yycheck[] =
{
       0,     0,    71,    86,    66,    13,    30,    92,   204,   198,
      85,    64,   233,    13,    14,   201,   109,   201,    18,   201,
       3,    21,    23,    23,   198,    43,    26,   102,   323,   324,
      21,   106,   198,    33,    34,    35,   111,    28,    29,    38,
      23,    21,    66,   112,    28,    23,   108,    67,    28,    69,
     271,     8,     9,    10,    21,    18,     3,   293,    21,    60,
      51,    28,    70,    26,   359,     3,    66,    66,    25,    27,
      33,    34,    35,    91,    59,     6,    23,    60,   131,    22,
     100,    38,   318,    83,    51,    70,   314,    87,   316,   280,
     281,   184,    50,    93,    94,    86,    96,    52,   319,   161,
     193,   184,    86,    52,   157,    23,    86,    22,   108,   108,
      36,    24,    27,    60,    27,   200,    71,   353,     3,    86,
      83,   349,    71,    49,    87,   314,    52,   316,   203,   204,
      93,    94,    89,    96,   325,    22,   136,    23,   162,    26,
     314,    29,   316,    51,   340,    71,   231,   333,   314,   333,
     316,   333,     8,     9,    10,    30,    31,    32,    33,    67,
     349,   161,   161,   171,    22,    24,    24,   250,    27,    25,
     170,   246,   265,   136,    23,   349,   176,   176,   178,     3,
     180,    36,   265,   349,    59,   260,    32,    33,    36,   345,
     190,   347,   191,     3,    49,    70,    52,    52,   198,   198,
       3,   286,   226,   278,    52,    36,   226,   282,   293,     3,
       0,   357,   358,    59,    22,   178,    71,   180,    23,   312,
     240,    52,   284,    71,    70,   115,   116,   190,    27,   312,
      27,   314,   378,   318,    51,   198,   289,   290,   307,   137,
      71,   294,   140,    24,   134,   135,   321,    23,   138,   139,
     250,    28,   252,    22,   253,    24,    55,    56,    27,    53,
     284,    22,   337,   338,   326,   285,    27,   329,   353,     3,
     168,    65,    66,    60,   172,    69,   166,   167,    72,   169,
     355,     8,     9,    10,   284,   284,    22,   250,    39,   252,
     341,    27,   343,    87,    88,    24,    36,    23,    25,    24,
      27,   301,   302,    24,   304,    45,    46,    47,    48,    49,
      55,    56,    52,    24,   314,   314,   316,   316,    90,     8,
       9,    10,     3,    63,    64,    41,   326,   326,    52,   329,
     329,    71,    70,    50,    27,    50,    25,    50,   301,   302,
      29,   304,   341,     3,   343,     3,    21,     3,    57,   349,
     349,   314,    28,   316,     0,     1,    24,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    58,    14,     4,
       8,     9,    10,    24,    29,   176,    22,    23,    24,   246,
      26,    27,   113,    29,   191,    31,   349,    25,    34,    35,
     170,    37,    38,   333,    40,   334,    42,    53,    44,    -1,
     200,    -1,    -1,    49,    -1,    51,    -1,    53,    54,    65,
      66,    57,    -1,    69,    60,    -1,    72,    -1,    -1,    65,
      66,    -1,    68,    69,    -1,    -1,    72,    73,    74,    75,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    -1,    -1,    92,    -1,     0,     1,
      96,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
      92,    -1,     0,     1,    96,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    37,
      38,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    -1,    53,    54,    -1,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    -1,    -1,    92,    -1,     0,     1,    96,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    37,    38,    -1,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,
      54,    -1,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    -1,    -1,    92,    -1,
      -1,     1,    96,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    -1,    42,    -1,    44,    -1,    -1,     3,    -1,    49,
      -1,    51,    -1,    53,    54,    -1,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,
      -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    87,    88,    89,
      13,    -1,    92,    -1,    -1,    -1,    96,    53,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    65,
      66,    34,    35,    69,    37,    38,    72,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      53,    87,    88,    -1,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,
      73,    74,    75,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,
      -1,    -1,    72,    73,    74,    75,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
      37,    38,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    -1,    53,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    68,    69,    -1,    -1,    72,    73,    74,    75,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    37,    38,    -1,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,    73,
      74,    75,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    -1,    87,    88,    89,     3,     4,     5,     6,
       7,    -1,    23,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      31,    -1,    -1,    34,    35,    31,    23,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      51,    -1,    53,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    53,    68,    69,    65,
      66,    72,    68,    69,    -1,    -1,    72,    -1,    65,    66,
      -1,    68,    69,    -1,    -1,    72,    87,    88,    -1,    -1,
      37,    87,    88,     3,     4,     5,     6,     7,    -1,    -1,
      87,    88,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    34,    35,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      49,    -1,    -1,    53,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    65,    66,    70,    68,    69,
      -1,    -1,    72,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    87,    88,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    23,    31,    34,    35,    37,    38,    40,
      42,    44,    49,    51,    53,    54,    57,    60,    65,    66,
      68,    69,    72,    73,    74,    75,    87,    88,    89,    92,
      96,   100,   101,   102,   105,   106,   109,   110,   120,   124,
     125,   127,   128,   129,   130,   131,   132,   135,   136,   137,
     143,    21,    28,    29,    51,    86,   140,   148,   159,     3,
      23,   110,   126,   127,   129,   138,   139,   141,   142,     3,
     129,   124,   129,    23,     3,   124,    22,   144,   145,   129,
       6,   124,     3,    23,    23,   148,    23,   124,   124,   124,
       3,   110,   133,   134,     3,     3,   103,     0,    22,    23,
      60,   114,   117,   118,   119,    55,    56,    15,    16,    17,
      18,    19,    20,    30,    31,    32,    33,    59,    61,    62,
      70,    36,    45,    46,    47,    48,    49,    52,    63,    64,
      71,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   149,   150,   153,   154,    49,   149,   102,
     148,   140,   140,   129,   114,    24,    55,    56,    52,    24,
      27,    27,    52,     8,     9,    10,    25,   104,    49,   124,
      28,   104,   145,   124,   146,   157,   159,   124,   124,   124,
     140,    27,   104,    23,    52,   104,   102,    24,   144,     3,
     151,    29,   104,   147,   114,   119,   125,   125,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   149,   125,   125,   124,     3,   135,   125,   125,
     135,     3,    23,    60,   149,   160,   102,   148,   125,   125,
       3,   125,   129,   139,   127,   101,    39,   124,    24,   124,
      27,   144,   145,    23,   121,    24,    24,    24,   124,   134,
      90,   144,     3,    13,   109,   115,   116,   120,   124,   129,
     137,    52,   157,    37,   150,   152,   153,   154,    41,   112,
     104,   104,   147,    50,   140,   148,    67,   158,   159,    28,
      86,   155,   156,   151,    27,    50,   140,    26,   104,   132,
      50,    43,    91,   124,   145,    50,   124,   110,   122,   123,
     104,     3,   107,   108,    27,   144,   145,   151,     3,    60,
     104,    57,   111,   112,   112,   104,    21,   102,   148,   140,
     159,   149,   149,    24,    27,   158,   149,   124,   124,   124,
     114,    22,    24,    27,    28,    27,   144,   145,   116,   145,
      24,   116,   158,   151,   104,    58,   113,   111,   111,   112,
     102,   102,   152,   155,   104,   104,   147,   123,   123,     4,
     108,    24,   108,   116,   158,   104,   113,   113,   111,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   106,   107,   107,   107,   108,   108,
     109,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   117,   118,   118,   119,   120,   121,   122,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   126,
     126,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   130,   130,   131,
     132,   132,   132,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   136,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   140,
     141,   142,   142,   143,   144,   144,   145,   145,   146,   146,
     146,   146,   147,   148,   149,   149,   149,   149,   150,   150,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   154,   155,
     155,   156,   156,   156,   157,   157,   158,   158,   158,   158,
     159,   159,   160,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     6,     7,     3,     3,     1,     1,     3,
       6,     7,     7,     8,     1,     2,     0,     2,     0,     2,
       0,     2,     5,     2,     1,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     1,
       3,     3,     0,     3,     1,     1,     1,     1,     1,     4,
       2,     2,     2,     2,     4,     1,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     3,     3,     3,     1,     1,     7,     7,     3,
       3,     5,     5,     3,     5,     3,     1,     3,     1,     2,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     5,     5,
       6,     4,     1,     3,     2,     3,     4,     1,     1,     1,
       3,     1,     3,     5,     0,     1,     1,     2,     1,     3,
       4,     3,     2,     2,     1,     3,     4,     1,     0,     1,
       1,     1,     1,     3,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       2,     0,     1,     3,     0,     1,     0,     1,     1,     2,
       2,     4,     1,     3
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

    { (yyval.node) = new NCCode(LOC, NCC_BLOCK, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 12:

    { (yyval.node) = new NCCode(LOC, NCC_DEFINE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 13:

    { (yyval.node) = new NCCode(LOC, NCC_STRUCT, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 14:

    { (yyval.node) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 15:

    { (yyval.node) = new NCCode(LOC, NCC_INCLUDE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 16:

    { (yyval.node) = new NCCode(LOC, NCC_TYPEDEF, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 17:

    { (yyval.node) = new NInclude(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 18:

    { (yyval.node) = new NPackage(LOC, *(yyvsp[-1].strings), shared_ptr<NBase>((yyvsp[0].node))); delete (yyvsp[-1].strings); }

    break;

  case 19:

    { (yyval.node) = nullptr; /* yyclearin; */ compiler->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }

    break;

  case 20:

    { (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 21:

    { (yyval.strings) = new vector<string>(); (yyval.strings)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 22:

    { (yyval.node) = (yyvsp[-1].block); }

    break;

  case 23:

    { (yyval.node) = new NCCode(LOC, NCC_BLOCK, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 24:

    { (yyval.node) = new NCCode(LOC, NCC_DEFINE, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 25:

    { (yyval.node) = new NCCode(LOC, NCC_FUNCTION, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 27:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Inc, nullptr); }

    break;

  case 28:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Dec, nullptr); }

    break;

  case 29:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 30:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 31:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 32:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 33:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), make_shared<NCall>(LOC, "setAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[0].node))))); }

    break;

  case 34:

    { (yyval.node) = new NEnum(LOC, shared_ptr<EnumArgs>((yyvsp[-2].enumArgs))); }

    break;

  case 35:

    { (yyvsp[-2].enumArgs)->push_back(shared_ptr<EnumArg>((yyvsp[0].enumArg))); }

    break;

  case 36:

    { (yyvsp[-2].enumArgs)->push_back(shared_ptr<EnumArg>((yyvsp[0].enumArg))); }

    break;

  case 37:

    { (yyval.enumArgs) = new EnumArgs(shared_ptr<EnumArg>((yyvsp[0].enumArg))); }

    break;

  case 38:

    { (yyval.enumArg) = new EnumArg(*(yyvsp[0].string)); delete (yyvsp[0].string); }

    break;

  case 39:

    { (yyval.enumArg) = new EnumArg(*(yyvsp[-2].string), *(yyvsp[0].string)); delete (yyvsp[-2].string); delete (yyvsp[0].string); }

    break;

  case 40:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].typeName)->valueName.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)));
						delete (yyvsp[-5].typeName); 
					}

    break;

  case 41:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 42:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-6].typeName)->valueName.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 43:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-4].typeName)), (yyvsp[-7].typeName)->valueName.c_str(), (yyvsp[-7].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-6].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-5].exprvec)), 
							shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); 
					}

    break;

  case 44:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, (yyvsp[0].string)->c_str(), false); delete (yyvsp[0].string); }

    break;

  case 45:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 46:

    { (yyval.node) = nullptr; }

    break;

  case 47:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 48:

    { (yyval.node) = nullptr; }

    break;

  case 49:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 50:

    { (yyval.node) = nullptr; }

    break;

  case 51:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 52:

    { (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 53:

    { (yyval.exprvec) = new NodeList(); }

    break;

  case 54:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 55:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 56:

    { if ((yyvsp[0].node)) { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 57:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 61:

    { (yyval.node) = new NCCode(LOC, NCC_VAR, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 62:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 63:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 64:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 65:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 66:

    { (yyval.typeName) = new CTypeName(CTC_Interface, CTM_Stack, *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)), false); delete (yyvsp[-1].string); }

    break;

  case 67:

    { (yyval.node) = new NInterface(LOC, *(yyvsp[-2].string), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 68:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 69:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 70:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 71:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 72:

    { (yyval.node) = nullptr; }

    break;

  case 73:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].typeName)->valueName.c_str(), (yyvsp[-2].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 74:

    { (yyval.node) = (yyvsp[0].node); }

    break;

  case 77:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 79:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 80:

    { (yyval.node) = new NChangeMode(LOC, CTM_Stack, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 81:

    { (yyval.node) = new NChangeMode(LOC, CTM_Local, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 82:

    { (yyval.node) = new NChangeMode(LOC, CTM_Heap, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 83:

    { (yyval.node) = new NCopy(LOC, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 84:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 85:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 86:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 87:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 89:

    { (yyval.var) = new NAnd(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 90:

    { (yyval.var) = new NOr(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 91:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 93:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::EQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 94:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::NE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 95:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PEQ, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 96:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::PNE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 97:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 98:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::LE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 99:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GT, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 100:

    { (yyval.var) = new NCompare(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NCompareOp::GE, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 101:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 102:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Add, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 103:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Sub, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 104:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mul, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 105:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Div, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 106:

    { (yyval.var) = new NMath(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMathOp::Mod, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 107:

    { (yyval.var) = new NGetOrElse(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 108:

    { (yyval.var) = new NNegate(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 109:

    { (yyval.var) = new NNot(LOC, shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 110:

    { (yyval.var) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NVariableBase>((yyvsp[-2].var))); }

    break;

  case 111:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 112:

    { (yyval.var) = (yyvsp[-1].var); }

    break;

  case 113:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 114:

    { (yyval.var) = new NOptionDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 115:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 116:

    { (yyval.var) = (yyvsp[0].var); }

    break;

  case 117:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), true); delete (yyvsp[-5].string); }

    break;

  case 118:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), false); delete (yyvsp[-5].string); }

    break;

  case 119:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 120:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 121:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 122:

    { (yyval.node) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 123:

    { (yyval.node) = new NIfValue(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<NBase>((yyvsp[0].node)), nullptr); }

    break;

  case 124:

    { (yyval.node) = new NIfValue(LOC, shared_ptr<NodeList>((yyvsp[-3].exprvec)), shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 125:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); (yyval.exprvec) = (yyvsp[-2].exprvec); }

    break;

  case 126:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 127:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 128:

    { (yyval.node) = new NVariable(LOC, (yyvsp[0].typeName)->valueName.c_str(), (yyvsp[0].typeName)->templateTypeNames); delete (yyvsp[0].typeName); }

    break;

  case 129:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].typeName)->valueName.c_str(), (yyvsp[-1].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].typeName); }

    break;

  case 130:

    { (yyval.var) = new NIsEmpty(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 131:

    { (yyval.var) = new NGetValue(LOC, shared_ptr<NBase>((yyvsp[-1].node)), false); }

    break;

  case 132:

    { (yyval.var) = new NValue(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 133:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].typeName)->valueName.c_str(), (yyvsp[0].typeName)->templateTypeNames); delete (yyvsp[0].typeName); }

    break;

  case 134:

    { (yyval.var) = new NParent(LOC, false); }

    break;

  case 135:

    { (yyval.var) = new NThis(LOC, false); }

    break;

  case 136:

    { (yyval.var) = new NParent(LOC, true); }

    break;

  case 137:

    { (yyval.var) = new NThis(LOC, true); }

    break;

  case 138:

    { (yyval.var) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 139:

    { (yyval.var) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 140:

    { (yyval.var) = new NBool(LOC, true); }

    break;

  case 141:

    { (yyval.var) = new NBool(LOC, false); }

    break;

  case 142:

    { (yyval.var) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 143:

    { (yyval.var) = new NChar(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 144:

    { (yyval.var) = new NEmpty(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 145:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 146:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 147:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 148:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 149:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].assignOp)); }

    break;

  case 150:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].assignOp)); }

    break;

  case 151:

    { (yyval.node) = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>((yyvsp[-2].tupleAssignmentArgList)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 152:

    { (yyval.tupleAssignmentArgList) = new NTupleAssignmentArgList(); (yyval.tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 153:

    { (yyvsp[-2].tupleAssignmentArgList)->push_back(shared_ptr<NTupleAssignmentArg>((yyvsp[0].tupleAssignmentArg))); }

    break;

  case 154:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 155:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), (yyvsp[-1].assignOp)); }

    break;

  case 156:

    { (yyval.tupleAssignmentArg) = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), nullptr, (yyvsp[-1].string)->c_str(), (yyvsp[0].assignOp)); }

    break;

  case 157:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = false; }

    break;

  case 158:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = true;  (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 159:

    { (yyval.assignOp).isCopy = false; (yyval.assignOp).typeMode = CTM_Undefined; (yyval.assignOp).isMutable = false; (yyval.assignOp).isFirstAssignment = true; }

    break;

  case 160:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); (yyval.var) = new NTuple(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 161:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 162:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].var))); }

    break;

  case 163:

    { (yyval.node) = new NArray(LOC, shared_ptr<NodeList>((yyvsp[-2].exprvec))); }

    break;

  case 164:

    { (yyval.node) = nullptr; }

    break;

  case 165:

    { (yyval.node) = nullptr; }

    break;

  case 166:

    { (yyval.node) = nullptr; }

    break;

  case 167:

    { (yyval.node) = nullptr; }

    break;

  case 168:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 169:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 170:

    { (yyvsp[-3].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 171:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 172:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 173:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 174:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 175:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-2].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 176:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-3].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 177:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 178:

    { (yyval.typeMode) = CTM_Undefined; }

    break;

  case 179:

    { (yyval.typeMode) = CTM_Local; }

    break;

  case 180:

    { (yyval.typeMode) = CTM_Stack; }

    break;

  case 181:

    { (yyval.typeMode) = CTM_Heap; }

    break;

  case 182:

    { (yyval.string) = (yyvsp[0].string); }

    break;

  case 183:

    { (yyval.string) = new string(*(yyvsp[-2].string) + "." + *(yyvsp[0].string)); }

    break;

  case 184:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 185:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-2].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 186:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-3].typeMode), *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].optionAndTypeList).templateTypeNames), (yyvsp[0].optionAndTypeList).isOption); delete (yyvsp[-1].string); }

    break;

  case 187:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 188:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Stack, "void", false); }

    break;

  case 189:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "i32", false); }

    break;

  case 190:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "u32", false); }

    break;

  case 191:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "f32", false); }

    break;

  case 192:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "i64", false); }

    break;

  case 193:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "u64", false); }

    break;

  case 194:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "f64", false); }

    break;

  case 195:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "char", false); }

    break;

  case 196:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "bool", false); }

    break;

  case 197:

    { (yyval.typeName) = new CTypeName(CTC_Value, CTM_Value, "ptr", false); }

    break;

  case 198:

    { (yyval.typeName) = new CTypeName((yyvsp[-4].typeMode), shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 199:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Mutable; }

    break;

  case 200:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTI_Immutable; }

    break;

  case 201:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 202:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 203:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 204:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 205:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 206:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 207:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = nullptr; }

    break;

  case 208:

    { (yyval.optionAndTypeList).isOption = false;  (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 209:

    { (yyval.optionAndTypeList).isOption = true;   (yyval.optionAndTypeList).templateTypeNames = (yyvsp[0].templateTypeNames); }

    break;

  case 210:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 211:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 212:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 213:

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

