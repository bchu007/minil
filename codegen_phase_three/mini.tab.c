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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "mini.y" /* yacc.c:339  */

#include "heading.h"
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( std::ostringstream() << std::dec << x ).str()

int yyerror(const char *s);
int yylex(void);

struct object {
    string name;
    string type;
    int size;
};


vector<object> var_table;
vector<string> func_table;
vector<string> op_table;
vector<string> ident_stack;
vector<string> param_table;
bool is_param = false;

void add_object(string n, string t = "null", int v = 1) {
    object *x = new object();
    x->name = n;
    x->type = t;
    x->size = v;
    var_table.push_back(*x); 
} 

string get_next_num() {
    static int global_temp_num = 0;
    string temp = "t" + SSTR(global_temp_num);
    global_temp_num += 1;
    return temp;
}

// adds a temp variable 
//  *params: takes in type and size
void add_temp(string t = "null", int s = 1){
    object *x = new object();
    x->name = get_next_num();
    x->type = t;
    x->size = s;
    var_table.push_back(*x);
}

string get_op() {
    if(!op_table.empty()) {
	string temp = op_table.back();
	op_table.pop_back();
	return temp;	
    }
    else {
	cout << "ERROR: no op in op table" << endl;
	exit(1);
    }
}

#line 127 "mini.tab.c" /* yacc.c:339  */

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
   by #include "mini.tab.h".  */
#ifndef YY_YY_MINI_TAB_H_INCLUDED
# define YY_YY_MINI_TAB_H_INCLUDED
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
    NUMBER = 258,
    IDENT = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    FOREACH = 276,
    IN = 277,
    BEGINLOOP = 278,
    ENDLOOP = 279,
    CONTINUE = 280,
    READ = 281,
    WRITE = 282,
    TRUE = 283,
    FALSE = 284,
    SEMICOLON = 285,
    COLON = 286,
    COMMA = 287,
    L_PAREN = 288,
    R_PAREN = 289,
    L_SQUARE_BRACKET = 290,
    R_SQUARE_BRACKET = 291,
    RETURN = 292,
    SUB = 293,
    ADD = 294,
    MULT = 295,
    DIV = 296,
    MOD = 297,
    EQ = 298,
    NEQ = 299,
    LT = 300,
    GT = 301,
    LTE = 302,
    GTE = 303,
    NOT = 304,
    AND = 305,
    OR = 306,
    ASSIGN = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "mini.y" /* yacc.c:355  */

  int		int_val;
  string*	op_val;
  char*		code;

#line 226 "mini.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "mini.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    97,    98,   101,   106,   112,   118,   123,
     129,   136,   142,   149,   160,   162,   168,   171,   179,   180,
     183,   184,   187,   190,   193,   196,   199,   202,   205,   208,
     214,   217,   223,   226,   232,   236,   240,   247,   250,   255,
     260,   264,   270,   277,   280,   283,   286,   289,   292,   297,
     300,   303,   306,   311,   314,   317,   322,   325,   328,   332,
     336,   340,   344,   348,   355,   361
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE",
  "READ", "WRITE", "TRUE", "FALSE", "SEMICOLON", "COLON", "COMMA",
  "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "RETURN",
  "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE",
  "GTE", "NOT", "AND", "OR", "ASSIGN", "$accept", "program", "functions",
  "funchead", "params_end", "params_start", "function", "ident",
  "identifiers", "declaration", "declarations", "vars", "statements",
  "statement", "relation_expr", "relation_expr_param", "relation_expr_not",
  "relation_and_expr_next", "relation_and_expr", "bool_expr_next",
  "bool_expr", "comp", "multiplicative_expr", "expression", "expressions",
  "term", "var", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,     2,     8,   -54,    18,    -4,   -54,   -15,   -54,   -54,
       2,   -54,   -54,    -2,     4,     3,    40,     2,     9,     2,
     -54,    44,   -54,   -54,    20,   -54,     2,    54,    50,    25,
      55,    56,   114,    61,    63,    63,    52,     2,   -54,     2,
       2,     7,    45,    68,    53,    34,   -54,   -54,   -54,   -54,
      78,     1,    86,   -16,    37,   -54,   -54,    42,    79,    10,
     109,   -14,   -54,    71,   114,    81,   -54,    72,   -54,     7,
     -54,     7,   -54,   114,     7,    75,   102,   -54,     7,   -54,
       7,    63,   -54,    63,   -54,   114,     7,     7,   -54,   -54,
     -54,   -54,   -54,   -54,     7,     7,     7,     7,   114,    89,
       2,     2,    76,    84,   -54,   -54,   -54,   -54,    83,    90,
      87,   -54,   -54,    60,   -54,   -54,   -54,   -54,   -54,   -54,
      99,   106,   103,   -54,   -54,   -54,     7,   -54,   -54,   114,
     -54,    63,   114,   -54,   110,   -54,   108,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     0,     3,     9,     0,     1,     7,
      14,     4,     5,    10,     0,     0,     0,     0,     0,    14,
       6,     0,    11,    12,     0,    15,    14,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    28,     0,
       0,     0,    64,     0,     0,     0,    13,    59,    35,    36,
       0,     0,     0,    64,    37,    30,    32,    40,     0,    53,
       0,    49,    58,     0,    18,     0,    26,    16,    27,     0,
      29,     0,     8,    18,     0,     0,     0,    61,     0,    31,
       0,     0,    39,     0,    42,    18,     0,     0,    43,    44,
      45,    46,    47,    48,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,    20,    33,    60,     0,    56,
       0,    38,    41,     0,    55,    54,    34,    50,    51,    52,
       0,     0,     0,    17,    65,    62,     0,    63,    22,    18,
      23,     0,    18,    57,     0,    24,     0,    21,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   125,   -54,   -54,   -54,   -54,    -1,   120,   -54,
     -12,   -37,   -44,   -54,   -54,    91,    88,   -54,    77,   -54,
     -33,   -54,   -53,   -18,    16,   -54,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    21,    10,     5,    53,    14,    15,
      16,    66,    43,    44,    54,    55,    56,    82,    57,    84,
      58,    94,    59,    60,   110,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,     1,    63,    68,    77,    45,     6,    25,     8,    13,
      47,     6,    67,    67,    28,    12,    13,    80,    13,    71,
      99,    23,    24,    70,     9,    13,    95,    96,    97,   104,
      17,    42,    76,    19,    78,    18,    65,    45,    42,    42,
      69,   113,   117,   118,   119,    51,    45,    20,    86,    87,
     112,   102,    26,   103,   120,    27,   105,    29,    45,    30,
     108,    31,   109,    42,   123,    32,    47,     6,   114,   115,
      33,    45,    42,    46,    67,    64,   116,   128,   129,    72,
      71,    47,     6,    73,    42,   134,    74,    81,   136,    47,
       6,    48,    49,    83,    98,    85,    50,    42,   135,   122,
      42,    51,    45,   100,   101,    45,    48,    49,   109,   106,
     107,    69,    52,   121,    48,    49,    51,   125,     6,    50,
     124,   127,   126,   130,    51,   131,   132,   137,    42,    34,
      11,    42,   138,    35,    36,    37,   107,    22,    75,    38,
      39,    40,   133,    79,     0,    88,    89,    90,    91,    92,
      93,    41,    88,    89,    90,    91,    92,    93,   111
};

static const yytype_int16 yycheck[] =
{
       1,     5,    35,    40,     3,    32,     4,    19,     0,    10,
       3,     4,    39,    40,    26,    30,    17,    33,    19,    35,
      64,    12,    13,    41,     6,    26,    40,    41,    42,    73,
      32,    32,    50,    30,    33,    31,    37,    64,    39,    40,
      33,    85,    95,    96,    97,    38,    73,     7,    38,    39,
      83,    69,     8,    71,    98,    35,    74,     3,    85,     9,
      78,    36,    80,    64,   101,    10,     3,     4,    86,    87,
      14,    98,    73,    12,   101,    23,    94,    17,    18,    11,
      35,     3,     4,    30,    85,   129,    52,    50,   132,     3,
       4,    28,    29,    51,    23,    16,    33,    98,   131,   100,
     101,    38,   129,    22,    32,   132,    28,    29,   126,    34,
      34,    33,    49,    24,    28,    29,    38,    34,     4,    33,
      36,    34,    32,    24,    38,    19,    23,    17,   129,    15,
       5,   132,    24,    19,    20,    21,    34,    17,    50,    25,
      26,    27,   126,    52,    -1,    43,    44,    45,    46,    47,
      48,    37,    43,    44,    45,    46,    47,    48,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,    56,    59,     4,    60,     0,     6,
      58,    55,    30,    60,    61,    62,    63,    32,    31,    30,
       7,    57,    61,    12,    13,    63,     8,    35,    63,     3,
       9,    36,    10,    14,    15,    19,    20,    21,    25,    26,
      27,    37,    60,    65,    66,    79,    12,     3,    28,    29,
      33,    38,    49,    60,    67,    68,    69,    71,    73,    75,
      76,    78,    79,    73,    23,    60,    64,    79,    64,    33,
      76,    35,    11,    30,    52,    69,    76,     3,    33,    68,
      33,    50,    70,    51,    72,    16,    38,    39,    43,    44,
      45,    46,    47,    48,    74,    40,    41,    42,    23,    65,
      22,    32,    76,    76,    65,    76,    34,    34,    76,    76,
      77,    71,    73,    65,    76,    76,    76,    75,    75,    75,
      65,    24,    60,    64,    36,    34,    32,    34,    17,    18,
      24,    19,    23,    77,    65,    73,    65,    17,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    58,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    70,    70,    71,
      72,    72,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     1,     1,    10,     1,
       1,     3,     3,     8,     0,     3,     1,     3,     0,     3,
       3,     7,     5,     5,     6,     7,     2,     2,     1,     2,
       1,     2,     1,     3,     3,     1,     1,     0,     2,     2,
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       3,     2,     4,     4,     1,     4
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 94 "mini.y" /* yacc.c:1646  */
    {}
#line 1421 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "mini.y" /* yacc.c:1646  */
    {
		     cout << " > " <<"func " << *(yyvsp[-1].op_val) <<  endl;
		}
#line 1429 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in prams params_end" << endl;
		    is_param = false;
		}
#line 1438 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in params params_start" << endl;
		    is_param = true;
		}
#line 1447 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in function" << endl;
		}
#line 1455 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "mini.y" /* yacc.c:1646  */
    {
		    (yyval.op_val) = (yyvsp[0].op_val); 
		}
#line 1463 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "mini.y" /* yacc.c:1646  */
    {
		    ident_stack.clear();
		    ident_stack.push_back(*(yyvsp[0].op_val));
		    if(is_param) {
			param_table.push_back("_" + *((yyvsp[0].op_val)));
		    }
		}
#line 1475 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "mini.y" /* yacc.c:1646  */
    {
		    ident_stack.push_back(*(yyvsp[-2].op_val));
		}
#line 1483 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 142 "mini.y" /* yacc.c:1646  */
    {
		    cout<< "in declaration colon integer" << endl;
		    while(!ident_stack.empty()) {
			add_object("_" + ident_stack.back(), "int");
			ident_stack.pop_back();
		    }
		}
#line 1495 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "mini.y" /* yacc.c:1646  */
    {
		    cout<< "in declaration colon array" << endl;
		    while(!ident_stack.empty()) {
			add_object("_" + ident_stack.back(), "arr<int>", (yyvsp[-3].int_val));
			ident_stack.pop_back();
		    }
		}
#line 1507 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 160 "mini.y" /* yacc.c:1646  */
    {   
		}
#line 1514 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 162 "mini.y" /* yacc.c:1646  */
    {      
		    //cout<< "in declarations semicolon" << endl; 
		}
#line 1522 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 168 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in vars var" << endl;
		}
#line 1530 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 171 "mini.y" /* yacc.c:1646  */
    {
		
		}
#line 1538 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 184 "mini.y" /* yacc.c:1646  */
    {
		    // If / Else if statement
		}
#line 1546 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 187 "mini.y" /* yacc.c:1646  */
    {
		    // If statement 
		}
#line 1554 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 190 "mini.y" /* yacc.c:1646  */
    {
		    // while loop   
		}
#line 1562 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 193 "mini.y" /* yacc.c:1646  */
    {
		    // Do while loop
		}
#line 1570 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 196 "mini.y" /* yacc.c:1646  */
    {
		    // for each?
		}
#line 1578 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 199 "mini.y" /* yacc.c:1646  */
    {
		    // read vars
		}
#line 1586 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 202 "mini.y" /* yacc.c:1646  */
    {
		    // write vars
		}
#line 1594 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "mini.y" /* yacc.c:1646  */
    {
		    // continue
		}
#line 1602 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 208 "mini.y" /* yacc.c:1646  */
    {
		    // return expression   
		}
#line 1610 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 214 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in relation_expr relation_expr_param" << endl;
		}
#line 1618 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 217 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in relation_expr relation_expr_param" << endl;

		}
#line 1627 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "mini.y" /* yacc.c:1646  */
    {
		// checks if relation_expr_not lacks surrounding parens
		}
#line 1635 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 226 "mini.y" /* yacc.c:1646  */
    {
		// check if relation_expr_not contains parens

		}
#line 1644 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 232 "mini.y" /* yacc.c:1646  */
    {
		// checks if realtion_expr is true or false based on e1 and e2
		// create temp variable (dest) to store the comparison
		}
#line 1653 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 236 "mini.y" /* yacc.c:1646  */
    {
		// sets relation_expr to be true

		}
#line 1662 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 240 "mini.y" /* yacc.c:1646  */
    {
		// sets relation_expr to be false

		}
#line 1671 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 247 "mini.y" /* yacc.c:1646  */
    {
    
		}
#line 1679 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 250 "mini.y" /* yacc.c:1646  */
    {
			
		}
#line 1687 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 255 "mini.y" /* yacc.c:1646  */
    {
		// starts AND 

		}
#line 1696 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "mini.y" /* yacc.c:1646  */
    {
		// finished with last OR statment in bool expression

		}
#line 1705 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 264 "mini.y" /* yacc.c:1646  */
    {
		// increment number of bool expressions 

		}
#line 1714 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 270 "mini.y" /* yacc.c:1646  */
    {
		//cout<< "in bool_expr realation_and_expr bool_expr_next" << endl;
		// start of a bool_expr
			
		}
#line 1724 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 277 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp eq" << endl;
		}
#line 1732 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 280 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp neq" << endl;
		}
#line 1740 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 283 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp lt" << endl;
		}
#line 1748 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 286 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp gt" << endl;
		}
#line 1756 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 289 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp lte" << endl;
		}
#line 1764 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 292 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp gte" << endl;
		}
#line 1772 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 297 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in muliplicative_expr term" << endl;
			}
#line 1780 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in multiplicative_expr term mult" << endl;
			}
#line 1788 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in multiplicative_expr term div" << endl;
			}
#line 1796 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 306 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in multiplicative_expr term mod" << endl;
			}
#line 1804 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 311 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expression multiplicative_expr" << endl;
		}
#line 1812 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 314 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expression multiplicative_expr add" << endl;
		}
#line 1820 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 317 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expression multiplicative_expr sub" << endl;
		}
#line 1828 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 322 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expressions expression" << endl;
		}
#line 1836 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 328 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term var" << endl;

		}
#line 1845 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 332 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term number" << endl;
		
		}
#line 1854 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 336 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term (expression)" << endl;

		}
#line 1863 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 340 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term sub number" << endl;

		}
#line 1872 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 344 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term sub (expression)" << endl;

		}
#line 1881 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 348 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term ident (expression)" << endl;

		}
#line 1890 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 355 "mini.y" /* yacc.c:1646  */
    {
		//cout<< "in var ident" << endl; 
		string id = "_" + *((yyvsp[0].op_val));
		op_table.push_back(id);
		
	    }
#line 1901 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 361 "mini.y" /* yacc.c:1646  */
    {
		//cout<< "in var ident[expression]" << endl;
		string id = "_" + *((yyvsp[-3].op_val));
		op_table.push_back("[] " + id + ", " + get_op());
	    }
#line 1911 "mini.tab.c" /* yacc.c:1646  */
    break;


#line 1915 "mini.tab.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 369 "mini.y" /* yacc.c:1906  */




int yyerror(string s) {
    //extern int yylineno;	/* defined and maintained in lex.c */
    extern char *yytext;	/* defined and maintained in lex.c */
    extern int lineNum;    

    cerr << "ERROR: " << s << "at symbol \"" << yytext;
    cerr << "\" on line " <<  lineNum << " "<< s << endl;
    exit(1);
}
int yyerror(const char *s)
{
    return yyerror(string(s));
}


