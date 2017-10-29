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
    TCEQ = 264,
    TCNE = 265,
    TCLT = 266,
    TCLE = 267,
    TCGT = 268,
    TCGE = 269,
    TEQUAL = 270,
    TEND = 271,
    TLPAREN = 272,
    TRPAREN = 273,
    TLBRACE = 274,
    TRBRACE = 275,
    TCOMMA = 276,
    TCOLON = 277,
    TQUOTE = 278,
    TPLUS = 279,
    TMINUS = 280,
    TMUL = 281,
    TDIV = 282,
    TTRUE = 283,
    TFALSE = 284,
    TAS = 285,
    TVOID = 286,
    TIF = 287,
    TELSE = 288,
    TTHROW = 289,
    TCATCH = 290,
    TEXTERN = 291,
    TFOR = 292,
    TTO = 293,
    TWHILE = 294,
    TPLUSPLUS = 295,
    TMINUSMINUS = 296,
    TPLUSEQUAL = 297,
    TMINUSEQUAL = 298,
    TLBRACKET = 299,
    TRBRACKET = 300,
    TEXCLAIM = 301,
    TDOT = 302,
    TTHIS = 303,
    TINCLUDE = 304,
    TAND = 305,
    TOR = 306,
    TDESTROY = 307,
    TMOD = 308,
    THASH = 309
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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   633

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    87,    88,    91,    92,    93,    94,    95,
      96,    97,   100,   103,   104,   105,   106,   107,   108,   109,
     112,   118,   123,   128,   133,   139,   140,   143,   144,   147,
     148,   151,   154,   155,   156,   159,   160,   161,   162,   165,
     168,   169,   172,   175,   178,   181,   182,   183,   186,   187,
     190,   191,   192,   193,   194,   195,   198,   199,   200,   203,
     204,   205,   206,   207,   208,   209,   212,   213,   214,   215,
     216,   217,   218,   221,   222,   223,   224,   227,   230,   233,
     234,   235,   238,   239,   242,   243,   244,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   258,   259,   260,   261,
     262,   263,   266,   267,   270,   273,   274,   277,   280,   283,
     284,   285,   288,   289,   292,   295,   296,   299,   300,   301,
     304,   305,   308,   309,   312,   313
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TINTEGER", "TDOUBLE",
  "TINVALID", "TSTRING", "TCHAR", "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT",
  "TCGE", "TEQUAL", "TEND", "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE",
  "TCOMMA", "TCOLON", "TQUOTE", "TPLUS", "TMINUS", "TMUL", "TDIV", "TTRUE",
  "TFALSE", "TAS", "TVOID", "TIF", "TELSE", "TTHROW", "TCATCH", "TEXTERN",
  "TFOR", "TTO", "TWHILE", "TPLUSPLUS", "TMINUSMINUS", "TPLUSEQUAL",
  "TMINUSEQUAL", "TLBRACKET", "TRBRACKET", "TEXCLAIM", "TDOT", "TTHIS",
  "TINCLUDE", "TAND", "TOR", "TDESTROY", "TMOD", "THASH", "$accept",
  "program", "stmts", "stmt", "block", "var_decl", "func_decl",
  "func_type_name", "catch", "destroy", "func_block", "func_args",
  "func_arg", "implement", "implement_args", "implement_arg",
  "interface_decl", "interface_block", "interface_args", "interface_arg",
  "expr", "expr_and", "expr_comp", "expr_math", "expr_var", "for_expr",
  "while_expr", "if_expr", "var", "var_right", "const", "assign",
  "assign_type", "array", "array_args", "return_type_quote",
  "arg_type_quote", "arg_type", "return_type", "func_type",
  "func_arg_type", "func_arg_type_list", "temp_block_optional",
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     375,  -145,   175,  -145,  -145,  -145,  -145,   521,    50,  -145,
    -145,  -145,   521,    22,    27,    46,   521,   521,   574,  -145,
      78,    96,   109,   103,  -145,  -145,  -145,    11,  -145,    85,
    -145,    93,   128,  -145,  -145,  -145,  -145,   160,  -145,  -145,
    -145,  -145,  -145,  -145,    24,     3,   219,    99,  -145,     4,
     111,    62,   121,  -145,  -145,    23,   521,   127,   126,    23,
      85,    14,  -145,  -145,   136,  -145,   323,   475,   182,    81,
     111,   165,  -145,    24,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,  -145,  -145,   271,
     271,   521,     8,   136,   135,   184,  -145,  -145,  -145,   185,
    -145,  -145,   271,  -145,  -145,    12,   427,   156,    87,   173,
     521,  -145,   521,  -145,   177,  -145,  -145,  -145,   140,  -145,
      85,   149,  -145,   136,     9,   170,   176,    81,   154,  -145,
    -145,  -145,   106,   106,   106,   106,   106,   106,   -10,   -10,
     157,   157,  -145,  -145,  -145,     7,    64,  -145,  -145,    24,
      24,  -145,   148,   136,   136,    43,  -145,   104,     1,  -145,
     209,    53,    85,   210,  -145,   475,  -145,   475,  -145,  -145,
    -145,  -145,   176,   163,   170,   170,   176,  -145,   202,   219,
      99,  -145,  -145,     9,   135,  -145,  -145,   222,  -145,  -145,
    -145,  -145,   111,   521,   136,   111,   162,  -145,  -145,  -145,
    -145,   176,  -145,   163,   163,   170,   271,  -145,  -145,   271,
    -145,  -145,  -145,   205,    23,   205,   210,  -145,   210,  -145,
    -145,  -145,   163,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    85,    88,    90,    94,    95,     0,     0,    91,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     2,     3,     6,     7,     0,     8,     9,
      53,    58,    65,    72,    51,    52,    50,    74,    83,    76,
      13,    75,   102,   103,     0,     0,     0,     0,    26,    85,
       0,     0,    74,    87,    89,     0,     0,     0,     0,     0,
     105,     0,    71,    10,   120,     1,     0,    35,     0,    84,
       0,    39,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,   120,   117,     0,   108,   111,   122,     0,
      96,    97,     0,    84,    73,     0,     0,    79,     0,     0,
       0,    78,     0,   104,     0,   121,     4,    37,     0,    32,
      38,    74,    36,   120,     0,    27,     0,     0,     0,    55,
      56,    57,    59,    60,    61,    62,    63,    64,    66,    67,
      68,    69,    70,    16,    17,     0,    85,    82,   109,     0,
       0,   118,     0,   120,   120,     0,    98,     0,     0,    54,
       0,     0,   106,    48,    43,    35,    31,    35,    42,   113,
     112,   107,     0,    29,    27,    27,     0,    41,    18,     0,
       0,   115,   116,     0,     0,   110,   124,     0,   123,    12,
      80,    81,     0,     0,    25,     0,     0,    45,    33,    34,
      28,     0,    20,    29,    29,    27,     0,    99,   100,     0,
     114,   119,   125,     0,     0,     0,    48,    44,    48,    30,
      22,    21,    29,    19,   101,    24,    77,    49,    46,    47,
      23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   124,   -32,   -50,  -145,   -42,     0,  -144,  -129,
     -46,  -145,   -83,  -145,  -145,   105,  -145,  -145,  -145,   -56,
       6,   101,  -145,   547,   213,  -145,  -145,    74,     5,   -60,
    -145,   -38,   -45,  -145,  -145,  -117,   -43,   -37,    51,  -145,
      54,  -145,   -85,    -1,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,   107,    25,    26,    50,   173,   202,
      69,   118,   119,    70,    71,    72,    28,   164,   196,   197,
      29,    30,    31,    32,    33,    34,    35,    36,    52,    38,
      39,    40,    46,    41,    61,   126,    47,   170,   171,    97,
     151,   152,   114,   115,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    48,   102,   101,   103,    37,    98,    96,   148,   111,
     176,   146,    93,    51,   100,    49,    84,    85,    55,   125,
     106,   -25,    59,    60,   127,   117,    94,    93,    67,   122,
     203,   204,   147,    12,   116,   112,   129,    73,   168,    56,
     169,    94,   106,    86,    57,   147,    27,    99,    48,    58,
      45,    37,   178,    73,    53,    54,    19,   143,   144,   113,
      19,   222,   108,    95,   187,    68,    27,    27,   185,   186,
     156,    37,   121,   120,   220,   221,   174,   175,    95,    42,
     104,   -25,   198,    73,   199,    63,    43,    44,   188,    27,
      27,   193,    73,   230,    37,    37,   225,   145,   227,    64,
     106,   179,    27,   180,   124,   159,    27,    37,   190,    65,
      45,    37,   181,   182,    42,    73,   161,    73,   162,    66,
      66,    43,   200,   117,   189,   117,   205,   122,    67,   122,
      82,    83,    84,    85,   109,   209,   208,    76,    77,    78,
      79,    80,    81,    74,    75,    48,   213,   207,   110,   215,
     149,   219,    82,    83,    84,    85,   165,   150,   166,    86,
     228,   167,   229,   195,   226,    27,   183,    27,   105,   184,
     121,   120,   121,   120,   223,   130,   131,   224,   216,    27,
     217,    86,    45,   218,    37,   123,   128,   153,   154,   158,
      42,   160,   -25,    48,   163,   106,    92,    43,    44,   214,
      87,    88,    89,    90,    91,   172,    27,    92,    68,    27,
      86,    37,   192,   194,    37,   201,   195,   206,   195,    -5,
       1,    45,     2,     3,     4,   212,     5,     6,   124,   -25,
     157,    62,   191,   177,   210,    -5,     7,    -5,   211,    -5,
      -5,     0,    44,     0,     8,     0,     0,     9,    10,     0,
      11,    12,     0,    13,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    17,     0,    18,     0,    19,    20,     0,
       0,    -5,     1,    21,     2,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,    -5,     7,    -5,
       0,    -5,    -5,     0,     0,     0,     8,     0,     0,     9,
      10,     0,    11,    12,     0,    13,     0,    14,    15,     0,
      16,     0,     0,     0,     0,    17,     0,    18,     0,    19,
      20,     0,     0,    -5,     1,    21,     2,     3,     4,     0,
       5,     6,     0,     0,     0,     0,     0,     0,     0,    -5,
       7,     0,     0,    -5,     0,     0,     0,     0,     8,     0,
       0,     9,    10,     0,    11,    12,     0,    13,     0,    14,
      15,     0,    16,     0,     0,     0,     0,    17,     0,    18,
       0,    19,    20,     0,     0,    -5,     1,    21,     2,     3,
       4,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,    -5,     7,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     9,    10,     0,    11,    12,     0,    13,
       0,    14,    15,     0,    16,     0,     0,     0,     0,    17,
       0,    18,     0,    19,    20,     0,     0,     0,     1,    21,
       2,     3,     4,     0,     5,     6,     0,     0,     0,     0,
       0,     0,     0,    -5,     7,     0,     0,    -5,     0,     0,
       0,     0,     8,     0,     0,     9,    10,     0,    11,    12,
       0,    13,     0,    14,    15,     0,    16,     0,     0,     0,
       0,    17,     0,    18,     0,    19,    20,     0,     2,     3,
       4,    21,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     9,    10,     0,    11,    12,     0,    13,
       0,    14,    15,     0,    16,     0,     0,     0,     0,    17,
       0,    18,     0,    19,    49,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     9,
      10,     0,    11,    12,     0,    13,     0,     0,    15,     0,
      16,     0,     0,     0,     0,    17,     0,    18,     0,    19,
      49,     3,     4,     0,     5,     6,     0,    49,     3,     4,
       0,     5,     6,     0,     7,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     9,    10,     0,    11,     8,
       0,     0,     9,    10,     0,    11,     0,     0,     0,     0,
       0,    17,     0,    18,     0,    19,     0,     0,    17,     0,
       0,     0,    19,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
       0,     2,    47,    46,    50,     0,     3,    44,    93,    59,
     127,     3,     3,     7,    46,     3,    26,    27,    12,    69,
      19,    17,    16,    17,    70,    67,    17,     3,    17,    67,
     174,   175,    92,    32,    66,    21,    73,    30,   123,    17,
      31,    17,    19,    53,    17,   105,    46,    44,    49,     3,
      46,    46,    45,    30,     4,     5,    48,    89,    90,    45,
      48,   205,    56,    54,    21,    54,    66,    67,   153,   154,
     102,    66,    67,    67,   203,   204,   126,   127,    54,    15,
      18,    17,   165,    30,   167,     7,    22,    23,    45,    89,
      90,    38,    30,   222,    89,    90,   213,    91,   215,     3,
      19,   146,   102,   146,    23,    18,   106,   102,   158,     0,
      46,   106,   149,   150,    15,    30,   110,    30,   112,    16,
      16,    22,   172,   165,    20,   167,   176,   165,    17,   167,
      24,    25,    26,    27,     7,   180,   179,     9,    10,    11,
      12,    13,    14,    50,    51,   146,   192,   179,    22,   195,
      15,   201,    24,    25,    26,    27,    16,    22,    18,    53,
     216,    21,   218,   163,   214,   165,    18,   167,    47,    21,
     165,   165,   167,   167,   206,    74,    75,   209,    16,   179,
      18,    53,    46,    21,   179,     3,    21,     3,     3,    33,
      15,    18,    17,   194,    17,    19,    47,    22,    23,   193,
      40,    41,    42,    43,    44,    35,   206,    47,    54,   209,
      53,   206,     3,     3,   209,    52,   216,    15,   218,     0,
       1,    46,     3,     4,     5,     3,     7,     8,    23,    54,
     106,    18,   158,   128,   183,    16,    17,    18,   184,    20,
      21,    -1,    23,    -1,    25,    -1,    -1,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    36,    37,    -1,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,    -1,    48,    49,    -1,
      -1,     0,     1,    54,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      29,    -1,    31,    32,    -1,    34,    -1,    36,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    -1,    46,    -1,    48,
      49,    -1,    -1,     0,     1,    54,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    28,    29,    -1,    31,    32,    -1,    34,    -1,    36,
      37,    -1,    39,    -1,    -1,    -1,    -1,    44,    -1,    46,
      -1,    48,    49,    -1,    -1,     0,     1,    54,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    -1,    31,    32,    -1,    34,
      -1,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,    48,    49,    -1,    -1,    -1,     1,    54,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    -1,    31,    32,
      -1,    34,    -1,    36,    37,    -1,    39,    -1,    -1,    -1,
      -1,    44,    -1,    46,    -1,    48,    49,    -1,     3,     4,
       5,    54,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    -1,    31,    32,    -1,    34,
      -1,    36,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,    48,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,
      29,    -1,    31,    32,    -1,    34,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    -1,    46,    -1,    48,
       3,     4,     5,    -1,     7,     8,    -1,     3,     4,     5,
      -1,     7,     8,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    25,    -1,    -1,    28,    29,    -1,    31,    25,
      -1,    -1,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46,    -1,    48,    -1,    -1,    44,    -1,
      -1,    -1,    48,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     7,     8,    17,    25,    28,
      29,    31,    32,    34,    36,    37,    39,    44,    46,    48,
      49,    54,    56,    57,    58,    60,    61,    62,    71,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    88,    15,    22,    23,    46,    87,    91,    98,     3,
      62,    75,    83,     4,     5,    75,    17,    17,     3,    75,
      75,    89,    79,     7,     3,     0,    16,    17,    54,    65,
      68,    69,    70,    30,    50,    51,     9,    10,    11,    12,
      13,    14,    24,    25,    26,    27,    53,    40,    41,    42,
      43,    44,    47,     3,    17,    54,    92,    94,     3,    44,
      58,    91,    87,    65,    18,    47,    19,    59,    75,     7,
      22,    59,    21,    45,    97,    98,    58,    61,    66,    67,
      75,    83,    86,     3,    23,    59,    90,    65,    21,    92,
      76,    76,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    58,    58,    75,     3,    84,    97,    15,
      22,    95,    96,     3,     3,    99,    58,    57,    33,    18,
      18,    75,    75,    17,    72,    16,    18,    21,    97,    31,
      92,    93,    35,    63,    59,    59,    90,    70,    45,    87,
      91,    92,    92,    18,    21,    97,    97,    21,    45,    20,
      59,    82,     3,    38,     3,    62,    73,    74,    67,    67,
      59,    52,    64,    63,    63,    59,    15,    58,    91,    87,
      93,    95,     3,    65,    75,    65,    16,    18,    21,    59,
      64,    64,    63,    58,    58,    90,    59,    90,    74,    74,
      64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    66,    66,    66,    67,    67,    67,    67,    68,
      69,    69,    70,    71,    72,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    80,    81,    82,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    89,    89,    90,    91,    92,
      92,    92,    93,    93,    94,    95,    95,    96,    96,    96,
      97,    97,    98,    98,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     2,     3,     3,     4,     6,
       5,     6,     6,     7,     7,     1,     2,     0,     2,     0,
       2,     3,     1,     3,     3,     0,     1,     1,     1,     1,
       1,     3,     3,     4,     3,     1,     3,     3,     0,     3,
       1,     1,     1,     1,     4,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     2,     1,     3,     1,     1,     1,     7,     3,     3,
       5,     5,     3,     1,     2,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     5,
       5,     6,     1,     1,     3,     1,     3,     2,     2,     2,
       3,     1,     1,     1,     4,     2,     2,     0,     1,     3,
       0,     1,     2,     4,     2,     3
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

  case 10:

    { (yyval.node) = new NInclude(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 11:

    { (yyval.node) = nullptr; /* yyclearin; */ result->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }

    break;

  case 12:

    { (yyval.block) = (yyvsp[-1].block); }

    break;

  case 14:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Inc, nullptr); }

    break;

  case 15:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-1].var)), NMAO_Dec, nullptr); }

    break;

  case 16:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Add, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 17:

    { (yyval.node) = new NMathAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), NMAO_Sub, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 18:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-3].var)), make_shared<NCall>(LOC, "get", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-1].node))))); }

    break;

  case 19:

    { (yyval.node) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), make_shared<NCall>(LOC, "set", nullptr, make_shared<NodeList>(shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[0].node))))); }

    break;

  case 20:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-4].typeName)->name.c_str(), (yyvsp[-4].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-3].exprvec)), 
							shared_ptr<NBlock>((yyvsp[-2].block)), shared_ptr<NBlock>((yyvsp[-1].block)), shared_ptr<NBlock>((yyvsp[0].block)));
						delete (yyvsp[-4].typeName); 
					}

    break;

  case 21:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, nullptr, (yyvsp[-5].typeName)->name.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-4].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-3].exprvec)), 
							shared_ptr<NBlock>((yyvsp[-2].block)), shared_ptr<NBlock>((yyvsp[-1].block)), shared_ptr<NBlock>((yyvsp[0].block))); 
					}

    break;

  case 22:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-3].typeName)), (yyvsp[-5].typeName)->name.c_str(), (yyvsp[-5].typeName)->templateTypeNames, 
							nullptr, shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBlock>((yyvsp[-2].block)), shared_ptr<NBlock>((yyvsp[-1].block)), shared_ptr<NBlock>((yyvsp[0].block))); 
					}

    break;

  case 23:

    { 
						(yyval.node) = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>((yyvsp[-3].typeName)), (yyvsp[-6].typeName)->name.c_str(), (yyvsp[-6].typeName)->templateTypeNames, 
							shared_ptr<CTypeNameList>((yyvsp[-5].templateTypeNames)), shared_ptr<NodeList>((yyvsp[-4].exprvec)), 
							shared_ptr<NBlock>((yyvsp[-2].block)), shared_ptr<NBlock>((yyvsp[-1].block)), shared_ptr<NBlock>((yyvsp[0].block))); 
					}

    break;

  case 24:

    { 
						(yyval.node) = new NFunction(LOC, FT_Extern, (yyvsp[-4].string)->c_str(), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), shared_ptr<NodeList>((yyvsp[-1].exprvec))); 
						delete (yyvsp[-4].string); 
					}

    break;

  case 25:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 26:

    { (yyval.typeName) = new CTypeName(CTC_Value, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames))); delete (yyvsp[-1].string); }

    break;

  case 27:

    { (yyval.block) = nullptr; }

    break;

  case 28:

    { (yyval.block) = (yyvsp[0].block); }

    break;

  case 29:

    { (yyval.block) = nullptr; }

    break;

  case 30:

    { (yyval.block) = (yyvsp[0].block); }

    break;

  case 31:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 32:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 33:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 34:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 35:

    { (yyval.node) = nullptr; }

    break;

  case 39:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 40:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 41:

    { (yyval.templateTypeNames) = (yyvsp[-2].templateTypeNames); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 42:

    { (yyval.typeName) = new CTypeName(CTC_Interface, (yyvsp[-1].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames))); delete (yyvsp[-1].string); }

    break;

  case 43:

    { (yyval.node) = new NInterface(LOC, (yyvsp[-2].string)->c_str(), shared_ptr<CTypeNameList>((yyvsp[-1].templateTypeNames)), shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-2].string); }

    break;

  case 44:

    { (yyval.exprvec) = (yyvsp[-1].exprvec); }

    break;

  case 45:

    { (yyval.exprvec) = new NodeList(); if ((yyvsp[0].node)) { (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 46:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 47:

    { if ((yyvsp[0].node)) { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); } }

    break;

  case 48:

    { (yyval.node) = nullptr; }

    break;

  case 49:

    { (yyval.node) = new NInterfaceMethod(LOC, (yyvsp[-2].typeName)->name.c_str(), (yyvsp[-2].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[-1].exprvec)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 50:

    { (yyval.node) = (NBase*)(yyvsp[0].nif); }

    break;

  case 54:

    { (yyval.node) = new NThrow(LOC, shared_ptr<NBase>((yyvsp[-1].node))); }

    break;

  case 55:

    { (yyval.node) = new NCast(LOC, shared_ptr<CTypeName>((yyvsp[0].typeName)), shared_ptr<NBase>((yyvsp[-2].node))); }

    break;

  case 56:

    { (yyval.node) = new NAnd(LOC, shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 57:

    { (yyval.node) = new NOr(LOC, shared_ptr<NBase>((yyvsp[-2].node)), shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 59:

    { (yyval.node) = new NCompare(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NCompareOp::EQ, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 60:

    { (yyval.node) = new NCompare(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NCompareOp::NE, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 61:

    { (yyval.node) = new NCompare(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NCompareOp::LT, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 62:

    { (yyval.node) = new NCompare(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NCompareOp::LE, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 63:

    { (yyval.node) = new NCompare(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NCompareOp::GT, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 64:

    { (yyval.node) = new NCompare(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NCompareOp::GE, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 66:

    { (yyval.node) = new NMath(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NMathOp::Add, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 67:

    { (yyval.node) = new NMath(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NMathOp::Sub, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 68:

    { (yyval.node) = new NMath(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NMathOp::Mul, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 69:

    { (yyval.node) = new NMath(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NMathOp::Div, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 70:

    { (yyval.node) = new NMath(LOC, shared_ptr<NBase>((yyvsp[-2].node)), NMathOp::Mod, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 71:

    { (yyval.node) = new NNot(LOC, shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 73:

    { (yyval.node) = (yyvsp[-1].node); }

    break;

  case 74:

    { (yyval.node) = (yyvsp[0].var); }

    break;

  case 77:

    { (yyval.node) = new NFor(LOC, (yyvsp[-5].string)->c_str(), shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].block))); delete (yyvsp[-5].string); }

    break;

  case 78:

    { (yyval.node) = new NWhile(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].block))); }

    break;

  case 79:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-1].node)), shared_ptr<NBase>((yyvsp[0].block)), nullptr); }

    break;

  case 80:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].block)), shared_ptr<NBase>((yyvsp[0].block))); }

    break;

  case 81:

    { (yyval.nif) = new NIf(LOC, shared_ptr<NBase>((yyvsp[-3].node)), shared_ptr<NBase>((yyvsp[-2].block)), shared_ptr<NBase>((yyvsp[0].nif))); }

    break;

  case 82:

    { (yyval.var) = new NDot(LOC, shared_ptr<NVariableBase>((yyvsp[-2].var)), shared_ptr<NVariableBase>((yyvsp[0].var))); }

    break;

  case 84:

    { (yyval.var) = new NCall(LOC, (yyvsp[-1].typeName)->name.c_str(), (yyvsp[-1].typeName)->templateTypeNames, shared_ptr<NodeList>((yyvsp[0].exprvec))); delete (yyvsp[-1].typeName); }

    break;

  case 85:

    { (yyval.var) = new NVariable(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 86:

    { (yyval.var) = new NThis(LOC); }

    break;

  case 87:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.node) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 88:

    { (yyval.node) = new NInteger(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 89:

    { (yyvsp[0].string)->insert(0, "-"); (yyval.node) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 90:

    { (yyval.node) = new NDouble(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 91:

    { (yyval.node) = new NBool(LOC, true); }

    break;

  case 92:

    { (yyval.node) = new NBool(LOC, false); }

    break;

  case 93:

    { (yyval.node) = new NVoid(LOC); }

    break;

  case 94:

    { (yyval.node) = new NString(LOC, (yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }

    break;

  case 95:

    { (yyval.node) = new NChar(LOC, (yyvsp[0].string)->c_str()[0]); delete (yyvsp[0].string); }

    break;

  case 96:

    { (yyval.node) = new NAssignment(LOC, nullptr, nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 97:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].isMutable)); }

    break;

  case 98:

    { (yyval.node) = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 99:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), nullptr, (yyvsp[-2].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 100:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-4].var)), shared_ptr<CTypeName>((yyvsp[0].typeName)), (yyvsp[-2].string)->c_str(), nullptr, (yyvsp[-1].isMutable)); }

    break;

  case 101:

    { (yyval.node) = new NAssignment(LOC, shared_ptr<NVariableBase>((yyvsp[-5].var)), shared_ptr<CTypeName>((yyvsp[-2].typeName)), (yyvsp[-3].string)->c_str(), shared_ptr<NBase>((yyvsp[0].node)), (yyvsp[-1].isMutable)); }

    break;

  case 102:

    { (yyval.isMutable) = true; }

    break;

  case 103:

    { (yyval.isMutable) = false; }

    break;

  case 104:

    { (yyval.node) = new NList(LOC, shared_ptr<NodeList>((yyvsp[-1].exprvec))); }

    break;

  case 105:

    { (yyval.exprvec) = new NodeList(); (yyval.exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 106:

    { (yyvsp[-2].exprvec)->push_back(shared_ptr<NBase>((yyvsp[0].node))); }

    break;

  case 107:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 108:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 109:

    { (yyval.typeName) = new CTypeName(CTC_Value, *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames))); delete (yyvsp[-1].string); }

    break;

  case 110:

    { (yyval.typeName) = new CTypeName(CTC_Interface, *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames))); delete (yyvsp[-1].string); }

    break;

  case 111:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 112:

    { (yyval.typeName) = (yyvsp[0].typeName); }

    break;

  case 113:

    { (yyval.typeName) = new CTypeName(CTC_Value, "void"); }

    break;

  case 114:

    { (yyval.typeName) = new CTypeName(shared_ptr<CTypeNameList>((yyvsp[-2].templateTypeNames)), shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 115:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTM_Mutable; }

    break;

  case 116:

    { (yyval.typeName) = (yyvsp[0].typeName); (yyval.typeName)->mutability = CTM_Immutable; }

    break;

  case 117:

    { (yyval.templateTypeNames) = new CTypeNameList(); }

    break;

  case 118:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 119:

    { (yyvsp[-2].templateTypeNames)->push_back(shared_ptr<CTypeName>((yyvsp[0].typeName))); }

    break;

  case 120:

    { (yyval.templateTypeNames) = nullptr; }

    break;

  case 121:

    { (yyval.templateTypeNames) = (yyvsp[0].templateTypeNames); }

    break;

  case 122:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(make_shared<CTypeName>(CTC_Value, *(yyvsp[0].string))); delete (yyvsp[0].string); }

    break;

  case 123:

    { (yyval.templateTypeNames) = (yyvsp[-1].templateTypeNames); }

    break;

  case 124:

    { (yyval.templateTypeNames) = new CTypeNameList(); (yyval.templateTypeNames)->push_back(make_shared<CTypeName>(CTC_Value, *(yyvsp[-1].string), shared_ptr<CTypeNameList>((yyvsp[0].templateTypeNames)))); delete (yyvsp[-1].string); }

    break;

  case 125:

    { (yyvsp[-2].templateTypeNames)->push_back(make_shared<CTypeName>(CTC_Value, *(yyvsp[0].string))); delete (yyvsp[0].string); }

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

