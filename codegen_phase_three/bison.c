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
void ERROR();
int yyerror(const char *s);
int yylex(void);

struct object {
    string name;
    string type;
    int size;
};

struct op {
    string val;
    string type;
};

vector<object> var_table;
vector<string> func_table;
vector<op> op_table;
vector<string> ident_stack;
vector<string> param_table;
vector<string> buff;
vector<vector<string> > if_label;
vector<vector<string> > loop_label;
string last_temp_name;
bool is_param = false;
bool is_local = false;


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

string get_next_label() {
    static int global_label_num = 0;
    string temp = "L" + SSTR(global_label_num);
    global_label_num += 1;
    return temp;

}

// adds a temp variable 
//  *params: takes in type and size
void add_temp(string t = "null", int s = 1){
    object *x = new object();
    x->name = get_next_num();
    last_temp_name = x->name;
    x->type = t;
    x->size = s;
    var_table.push_back(*x);
}

string check_op_type(){
    return op_table.back().type;

} 

void add_op(string v, string t = "int") {
    op *x = new op();
    x->val = v;
    x->type = t;
    op_table.push_back(*x);

}

string get_op_val() {
    if(!op_table.empty()) {
	string temp = op_table.back().val;
	op_table.pop_back();
	return temp;	
    }
    else {
	cout << "ERROR: no op in op table" << endl;
	exit(1);
    }
}

bool in_var_table(string v){
    for (unsigned int i = 0; i < var_table.size(); i++){
        if (var_table.at(i).name == v){
            return true;
        }
    }
    return false;
}

bool in_func_table(string v){
    for (unsigned int i = 0; i < func_table.size(); i++){
        if (func_table.at(i) == v){
            return true;
        }
    }
    return false;
}

bool in_op_table(string v){
    for (unsigned int i = 0; i < op_table.size(); i++){
        if (op_table.at(i).val == v){
            return true;
        }
    }
    return false;
}

bool in_ident_stack(string v){
    for (unsigned int i = 0; i < ident_stack.size(); i++){
        if (ident_stack.at(i) == v){
            return true;
        }
    }
    return false;
}

bool in_param_table(string v){
    for (unsigned int i = 0; i < param_table.size(); i++){
        if (param_table.at(i) == v){
            return true;
        }
    }
    return false;
}

bool in_buff(string v){
    for (unsigned int i = 0; i < buff.size(); i++){
        if (buff.at(i) == v){
            return true;
        }
    }
    return false;
}


void ERROR(string error){
    extern int lineNum;
    cerr << "ERROR at line " << lineNum << ": " << error << endl;
   // exit(1);
}

void write(string s) {
    buff.push_back(s);
}




#line 227 "mini.tab.c" /* yacc.c:339  */

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
#line 166 "mini.y" /* yacc.c:355  */

  int		int_val;
  string*	op_val;
  char*		code;

#line 326 "mini.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 343 "mini.tab.c" /* yacc.c:358  */

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
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

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
       0,   194,   194,   197,   198,   201,   207,   213,   218,   224,
     230,   253,   259,   266,   272,   283,   298,   300,   306,   310,
     316,   320,   326,   329,   334,   350,   358,   370,   378,   388,
     392,   415,   420,   425,   431,   436,   440,   444,   448,   464,
     471,   474,   482,   486,   493,   504,   511,   521,   524,   534,
     539,   543,   555,   562,   566,   570,   574,   578,   582,   588,
     591,   599,   607,   617,   620,   628,   638,   642,   648,   664,
     668,   672,   677,   683,   698,   709
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
  "funchead", "params_end", "params_start", "begin_locals", "end_locals",
  "function", "ident", "identifiers", "declaration", "declarations",
  "read_vars", "write_vars", "statements", "if_bool", "if_else", "while",
  "while_bool", "do", "do_once", "statement", "relation_expr",
  "relation_expr_param", "relation_expr_not", "relation_and_expr_next",
  "relation_and_expr", "bool_expr_next", "bool_expr", "comp",
  "multiplicative_expr", "expression", "expressions", "term", "var", YY_NULLPTR
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

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,     7,    15,   -58,    11,     2,   -58,    -8,   -58,   -58,
       7,   -58,   -58,   -13,     1,    16,    53,     7,    12,     7,
     -58,    55,   -58,   -58,    30,   -58,   -58,     7,    66,    62,
      37,   -58,    70,    60,   100,    69,    26,   -58,    67,     7,
     -58,     7,     7,    64,    41,    81,    78,    26,   100,   100,
      76,    71,    47,   -58,   -58,   -58,   -58,    58,    -2,    85,
     -25,    50,   -58,   -58,    52,   -58,   -11,    86,     3,   -58,
     -58,    83,   -58,    74,   -58,    75,    64,   -58,    64,   -58,
     100,    89,    93,   104,    26,   100,    64,    90,   101,   -58,
      64,   -58,    64,    26,   -58,    26,   -58,    64,    64,   -58,
     -58,   -58,   -58,   -58,   -58,    64,    64,    64,    64,     7,
       7,     7,   102,   103,    18,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   106,   109,   108,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   127,   -58,   -58,   -58,   -58,   100,
     134,   -58,    64,   -58,   100,   -58,   -58,   -58,   128,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     0,     3,    11,     0,     1,     7,
      16,     4,     5,    12,     0,     0,     0,     0,     0,    16,
       6,     0,    13,    14,     0,    17,     8,    16,     0,     0,
       0,     9,     0,     0,    22,     0,     0,    26,     0,     0,
      38,     0,     0,     0,    74,     0,     0,     0,    22,    22,
       0,     0,     0,    15,    69,    45,    46,     0,     0,     0,
      74,    47,    40,    42,    50,    24,    63,     0,    59,    68,
      28,     0,    36,    18,    37,    20,     0,    39,     0,    10,
      22,     0,     0,     0,     0,    22,     0,     0,     0,    71,
       0,    41,     0,     0,    49,     0,    52,     0,     0,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    33,    29,    34,    23,
      30,    43,    70,     0,    66,     0,    48,    51,    65,    64,
      44,    60,    61,    62,     0,    19,    21,    75,    32,    22,
       0,    72,     0,    73,    22,    25,    31,    67,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   148,   -58,   -58,   -58,   -58,   -58,   -58,    -1,
     137,   -58,   -15,    45,    46,   -46,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,    97,   105,   -58,    65,   -58,   -42,
     -58,   -57,   -20,    17,   -58,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    21,    10,    27,    32,     5,    60,
      14,    15,    16,    72,    74,    45,    46,   140,    47,    48,
      49,    50,    51,    61,    62,    63,    94,    64,    96,    65,
     105,    66,    67,   125,    68,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    89,    82,    83,    25,    81,    52,     1,    92,    13,
      78,     6,    29,    73,    75,     8,    13,     9,    13,    17,
      52,    52,    12,    77,    23,    24,    13,    97,    98,    54,
       6,    90,    18,    44,   114,   138,   139,    88,    71,   119,
      44,    44,   118,   106,   107,   108,    19,    44,    44,   131,
     132,   133,    52,   127,    55,    56,   112,    52,   113,    57,
      20,    54,     6,    26,    58,    28,   120,    54,     6,    30,
     123,    31,   124,    33,    35,    59,    78,   128,   129,    44,
      34,    53,    73,    75,    44,   130,    55,    56,    54,     6,
      70,    76,    79,   145,    80,    84,    58,    76,   148,    86,
      93,    85,    58,    95,     6,   109,   110,   111,   134,    44,
      44,    52,   115,    55,    56,    36,    52,   116,    57,    37,
      38,    39,   124,    58,   121,    40,    41,    42,   117,    99,
     100,   101,   102,   103,   104,   122,   122,    43,    44,   137,
     141,   142,   143,    44,    99,   100,   101,   102,   103,   104,
     144,   146,   149,    11,    22,   135,    91,   136,   126,   147,
       0,     0,    87
};

static const yytype_int16 yycheck[] =
{
       1,     3,    48,    49,    19,    47,    34,     5,    33,    10,
      35,     4,    27,    41,    42,     0,    17,     6,    19,    32,
      48,    49,    30,    43,    12,    13,    27,    38,    39,     3,
       4,    33,    31,    34,    80,    17,    18,    57,    39,    85,
      41,    42,    84,    40,    41,    42,    30,    48,    49,   106,
     107,   108,    80,    95,    28,    29,    76,    85,    78,    33,
       7,     3,     4,     8,    38,    35,    86,     3,     4,     3,
      90,     9,    92,    36,    14,    49,    35,    97,    98,    80,
      10,    12,   110,   111,    85,   105,    28,    29,     3,     4,
      23,    33,    11,   139,    16,    19,    38,    33,   144,    52,
      50,    30,    38,    51,     4,    22,    32,    32,   109,   110,
     111,   139,    23,    28,    29,    15,   144,    24,    33,    19,
      20,    21,   142,    38,    34,    25,    26,    27,    24,    43,
      44,    45,    46,    47,    48,    34,    34,    37,   139,    36,
      34,    32,    34,   144,    43,    44,    45,    46,    47,    48,
      23,    17,    24,     5,    17,   110,    59,   111,    93,   142,
      -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,    56,    61,     4,    62,     0,     6,
      58,    55,    30,    62,    63,    64,    65,    32,    31,    30,
       7,    57,    63,    12,    13,    65,     8,    59,    35,    65,
       3,     9,    60,    36,    10,    14,    15,    19,    20,    21,
      25,    26,    27,    37,    62,    68,    69,    71,    72,    73,
      74,    75,    88,    12,     3,    28,    29,    33,    38,    49,
      62,    76,    77,    78,    80,    82,    84,    85,    87,    88,
      23,    62,    66,    88,    67,    88,    33,    85,    35,    11,
      16,    82,    68,    68,    19,    30,    52,    78,    85,     3,
      33,    77,    33,    50,    79,    51,    81,    38,    39,    43,
      44,    45,    46,    47,    48,    83,    40,    41,    42,    22,
      32,    32,    85,    85,    68,    23,    24,    24,    82,    68,
      85,    34,    34,    85,    85,    86,    80,    82,    85,    85,
      85,    84,    84,    84,    62,    66,    67,    36,    17,    18,
      70,    34,    32,    34,    23,    68,    17,    86,    68,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    71,    72,    73,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    79,    79,    80,
      81,    81,    82,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     1,     1,     1,     1,
      10,     1,     1,     3,     3,     8,     0,     3,     1,     3,
       1,     3,     0,     3,     2,     2,     1,     3,     2,     3,
       3,     5,     4,     3,     3,     7,     2,     2,     1,     2,
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
#line 194 "mini.y" /* yacc.c:1646  */
    {}
#line 1532 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 201 "mini.y" /* yacc.c:1646  */
    {
		     cout << " > " <<"func " << *(yyvsp[-1].op_val) <<  endl;
		     write(": start ");
		}
#line 1541 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 207 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in prams params_end" << endl;
		    is_param = false;
		}
#line 1550 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 213 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in params params_start" << endl;
		    is_param = true;
		}
#line 1559 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 218 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in begin_locals" << endl;
		    is_local = true;
		}
#line 1568 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 224 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in end_locals" << endl;
		    is_local = false;
		}
#line 1577 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 230 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in function ---------------" << endl;
		    
		    for(unsigned int i=0; i < var_table.size(); ++i) {
			if(var_table.at(i).type == "int") {
			    cout << "    . " << var_table.at(i).name << endl;

			}
			else {
			    cout << "    .[] " << var_table.at(i).name << endl;
			}
		    }
		    for(unsigned int i=0; i < buff.size(); ++i) {
			if(buff.at(i).at(0) == ':' && buff.at(i).at(1) == ' '){
			    cout << buff.at(i) << endl;
			}
			else {
			    cout << "    " <<  buff.at(i) << endl;
			}
		    }
		}
#line 1603 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 253 "mini.y" /* yacc.c:1646  */
    {
		    (yyval.op_val) = (yyvsp[0].op_val); 
		}
#line 1611 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 259 "mini.y" /* yacc.c:1646  */
    {
		    ident_stack.clear();
		    ident_stack.push_back(*(yyvsp[0].op_val));
		    if(is_param) {
			param_table.push_back("_" + *((yyvsp[0].op_val)));
		    }
		}
#line 1623 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 266 "mini.y" /* yacc.c:1646  */
    {
		    ident_stack.push_back(*(yyvsp[-2].op_val));
		}
#line 1631 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 272 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in declaration colon integer" << endl;
		    while(!ident_stack.empty()) {
			bool boolTemp = in_var_table("_" + ident_stack.back());
			if(boolTemp){
			    ERROR("ident redeclaration");
			}
			add_object("_" + ident_stack.back(), "int");
			ident_stack.pop_back();
		    }
		}
#line 1647 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 283 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in declaration colon array" << endl;
		    while(!ident_stack.empty()) {
			bool boolTemp = in_var_table("_" + ident_stack.back());
			if(boolTemp){
			    ERROR("ident redeclaration");
			}
			add_object("_" + ident_stack.back(), "arr<int>", (yyvsp[-3].int_val));
			ident_stack.pop_back();
		    }
		}
#line 1663 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 298 "mini.y" /* yacc.c:1646  */
    {   
		}
#line 1670 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 300 "mini.y" /* yacc.c:1646  */
    {      
		    //cout<< "in declarations semicolon" << endl; 
		}
#line 1678 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 306 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in read_vars var" << endl;
		    write(".< " + get_op_val());
		}
#line 1687 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 310 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in read_vars var comma" << endl;
		    write(".< " + get_op_val());
		}
#line 1696 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 316 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in write_vars var" << endl;
		    //write(
		}
#line 1705 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 320 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in write_vars var comma" << endl;
		
		}
#line 1714 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 326 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statements epsilon" << endl;
		}
#line 1722 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 329 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statements statement semicolon statements" << endl;
		}
#line 1730 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 334 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in if_bool if bool_expr" << endl;	
		    string L1 = get_next_label();
		    string L2 = get_next_label();
		    string L3 = get_next_label();
		    vector<string> temp;
		    temp.push_back(L1);
		    temp.push_back(L2);
		    temp.push_back(L3);
		    if_label.push_back(temp);
		    write("?:= " + if_label.back().at(0) + ", " + get_op_val());
		    write(":= " + if_label.back().at(1));
		    write(": " + if_label.back().at(0));  
		}
#line 1749 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 350 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in if_else else statements" << endl;
		    write(":= " + if_label.back().at(2));
		    write(": " + if_label.back().at(1));
		}
#line 1759 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 358 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in while while" << endl;
		    vector<string> temp;
		    temp.push_back("while");
		    temp.push_back(get_next_label());
		    temp.push_back(get_next_label());
		    temp.push_back(get_next_label());
		    loop_label.push_back(temp);
		    write(": " + loop_label.back().at(1));
		}
#line 1774 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 370 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in while_bool while bool_expr beginloop" << endl;
		    write("?:= " + loop_label.back().at(2) + ", " + get_op_val());
		    write(":= " + loop_label.back().at(3));
		    write(": " + loop_label.back().at(2));
		}
#line 1785 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 378 "mini.y" /* yacc.c:1646  */
    {
		    vector<string> temp;
		    temp.push_back("do_while");
		    temp.push_back(get_next_label());
		    temp.push_back(get_next_label());
		    loop_label.push_back(temp);
		    write(": " + loop_label.back().at(1));
		}
#line 1798 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 388 "mini.y" /* yacc.c:1646  */
    {
		    write(": " + loop_label.back().at(2));
		}
#line 1806 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 392 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statment var assign expression" << endl;
		    //TODO: check if in table
		    write("val next" );
		    string op2 = get_op_val();
		    if(check_op_type() == "int") {
			string op1 = get_op_val();
			bool tempBool = in_var_table(op1);
			if(!tempBool){
			    ERROR("variable not declared in this scope");
			}
			write("= " + op1 + ", " + op2);
		    }
		    //TODO: ARRAY errors
		    else {
			string op1 = get_op_val();
			write("[]= " + op1 + ", " + op2); 
			bool tempBool = in_var_table(op1);
			if(!tempBool){
			    ERROR("variable not declared in this scope");
			}
		    }
		}
#line 1834 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 415 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement if then else" << endl;
		    write(": " + if_label.back().at(2));
		    if_label.pop_back();
		}
#line 1844 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 420 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement if then" << endl;
		    write(": " + if_label.back().at(1));
		    if_label.pop_back();
		}
#line 1854 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 425 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement while loop" << endl;
		    write(":= " + loop_label.back().at(1));
		    write(": " + loop_label.back().at(3));
		    loop_label.pop_back();
		}
#line 1865 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 431 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement do while loop" << endl;
		    write("?:= " + loop_label.back().at(1) + ", " + get_op_val());
		    loop_label.pop_back();
		}
#line 1875 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 436 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement foreach loop" << endl;
		
		}
#line 1884 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 440 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement read vars" << endl;		
    		
		}
#line 1893 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 444 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement write vars" << endl;
		
		}
#line 1902 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 448 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement continue" << endl;
		    if(!loop_label.empty()) {
			string type = loop_label.back().at(0);
			if(type == "while") {
			    write(":= " + loop_label.back().at(1));
			}
			else if(type == "do_while") {
			    write(":= " + loop_label.back().at(2));
			}
			else {
			    write("ERROR");
			}
		    }
		
		}
#line 1923 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 464 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in statement return expression" << endl;
		
		}
#line 1932 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 471 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in relation_expr relation_expr_param" << endl;
		}
#line 1940 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 474 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in relation_expr relation_expr_param" << endl;
		    add_temp("int");
		    write("! " + last_temp_name + ", " + get_op_val());
		    add_op(last_temp_name);
		}
#line 1951 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 482 "mini.y" /* yacc.c:1646  */
    {
		// checks if relation_expr_not lacks surrounding parens
		    //cout<< "in relation_expr_param relation_expr_not" << endl;
		}
#line 1960 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 486 "mini.y" /* yacc.c:1646  */
    {
		// check if relation_expr_not contains parens
		    //cout<< "in relation_expr_param (relation_expr_not)" << endl;

		}
#line 1970 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 493 "mini.y" /* yacc.c:1646  */
    {
		// checks if realtion_expr is true or false based on e1 and e2
		// create temp variable (dest) to store the comparison
		    //cout<< "in relation_expr_not expression comp expression" << endl; 
		    add_temp("int");
		    string op2 = get_op_val();
		    string comp = get_op_val();
		    string op1 = get_op_val();
		    write(comp + " " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);	
		}
#line 1986 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 504 "mini.y" /* yacc.c:1646  */
    {
		// sets relation_expr to be true
		    //cout<< "in relation_expr_not true" << endl;
		    add_temp("int");
		    write("= " + last_temp_name + ", 1");
		    add_op(last_temp_name);
		}
#line 1998 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 511 "mini.y" /* yacc.c:1646  */
    {
		// sets relation_expr to be false
		    //cout<< "in relation_expression_not false" << endl;
		    add_temp("int");
		    write("= " + last_temp_name + ", 0");
		    add_op(last_temp_name);
		}
#line 2010 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 521 "mini.y" /* yacc.c:1646  */
    {
    
		}
#line 2018 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 524 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in relattion_and_expr_next" << endl;
		    add_temp("int");
		    string op2 = get_op_val();
		    string op1 = get_op_val();
		    write("&& " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);		
		}
#line 2031 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 534 "mini.y" /* yacc.c:1646  */
    {
		// starts AND 
		    //cout<< "in relation_and_expr relation_expr relation_and_expr_next" << endl;
		}
#line 2040 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 539 "mini.y" /* yacc.c:1646  */
    {
		// finished with last OR statment in bool expression
		    //cout<< "in bool_expr_next epsilon" << endl;
		}
#line 2049 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 543 "mini.y" /* yacc.c:1646  */
    {
		// increment number of bool expressions 
		    //cout<< "in bool_expr_next or bool_expr" << endl;
		    add_temp("int");
		    string op2 = get_op_val();
		    string op1 = get_op_val();
		    write("|| " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);

		}
#line 2064 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 555 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in bool_expr realation_and_expr bool_expr_next" << endl;
		// start of a bool_expr
			
		}
#line 2074 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 562 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp eq" << endl;
		    add_op("==");	
		}
#line 2083 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 566 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp neq" << endl;
		    add_op("!=");
		}
#line 2092 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 570 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp lt" << endl;
		    add_op("<");
		}
#line 2101 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 574 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp gt" << endl;
		    add_op(">");
		}
#line 2110 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 578 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp lte" << endl;
		    add_op("<=");
		}
#line 2119 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 582 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in comp gte" << endl;
		    add_op(">=");	
		}
#line 2128 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 588 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in muliplicative_expr term" << endl;
			}
#line 2136 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 591 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in multiplicative_expr term mult" << endl;
			    add_temp("int");
			    string op2 = get_op_val();
			    string op1 = get_op_val();
			    write("* " + last_temp_name + ", " + op1 + ", " + op2);
			    add_op(last_temp_name);
		    	}
#line 2149 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 599 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in multiplicative_expr term div" << endl;
			    add_temp("int");
			    string op2 = get_op_val();
			    string op1 = get_op_val();
			    write("/ " + last_temp_name + ", " + op1 + ", " + op2);
			    add_op(last_temp_name);
			}
#line 2162 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 607 "mini.y" /* yacc.c:1646  */
    {
			    //cout<< "in multiplicative_expr term mod" << endl;
			    add_temp("int");
			    string op2 = get_op_val();
			    string op1 = get_op_val();
			    write("% " + last_temp_name + ", " + op1 + ", " + op2);
			    add_op(last_temp_name);
			}
#line 2175 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 617 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expression multiplicative_expr" << endl;
		}
#line 2183 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 620 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expression multiplicative_expr add" << endl;
		    add_temp("int");
		    string op2 = get_op_val();
		    string op1 = get_op_val();
		    write("+ " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);
		}
#line 2196 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 628 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expression multiplicative_expr sub" << endl;
		    add_temp("int");
		    string op2 = get_op_val();
		    string op1 = get_op_val();
		    write("- " + last_temp_name + ", " + op1 + ", " + op2);
		    add_op(last_temp_name);
		}
#line 2209 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 638 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expressions expression" << endl;

		}
#line 2218 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 642 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in expressions expression comma expression" << endl;

		}
#line 2227 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 648 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term var" << endl;
		    add_op(get_op_val(), check_op_type());
		    /*
		    add_temp("int");
		    
		    if(check_op_type() == "int") {
			write("= " + last_temp_name + ", " + get_op_val());
		    }
		    else {
			write("=[] " + last_temp_name + ". " + get_op_val());
		    }
		    add_op(last_temp_name);
		    */

		}
#line 2248 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 664 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term number" << endl;
		    add_op(SSTR((yyvsp[0].int_val)));		    
		}
#line 2257 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 668 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term (expression)" << endl;
		    
		}
#line 2266 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 672 "mini.y" /* yacc.c:1646  */
    {
		    add_op(SSTR((yyvsp[0].int_val) * -1));
		    //cout<< "in term sub number" << endl;

		}
#line 2276 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 677 "mini.y" /* yacc.c:1646  */
    {
		    //cout<< "in term sub (expression)" << endl;
		    add_temp("int");
		    write("- " + last_temp_name + ", 0, " + get_op_val());
		    add_op(last_temp_name);
		}
#line 2287 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 683 "mini.y" /* yacc.c:1646  */
    { //FUNCTIONS
		    //cout<< "in term ident (expression)" << endl;
		    add_temp("int");
		    //TODO:check if id exists
		    //bool tempBool = in_func_table(*($1));
		    //if(!tempBool){
		    //	ERROR("Function not declared in this scope");
                    //} 
		    write("call " + *((yyvsp[-3].op_val)) + ", " + last_temp_name);
		    add_op(last_temp_name);
		    
		}
#line 2304 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 698 "mini.y" /* yacc.c:1646  */
    {
		//cout<< "in var ident" << endl; 
		string id = "_" + *((yyvsp[0].op_val));
		//TODO: check if id exists already
		bool tempBool = in_var_table(*((yyvsp[0].op_val)));
		if(!tempBool){
		    ERROR("variable is not defined in this scope");
		}
		add_op(id);
		
	    }
#line 2320 "mini.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 709 "mini.y" /* yacc.c:1646  */
    {
		//cout<< "in var ident[expression]" << endl;
		string id = "_" + *((yyvsp[-3].op_val));
		//TODO: check if id exists already
		bool tempBool = in_var_table(*((yyvsp[-3].op_val)));
		if(!tempBool){
		    ERROR("variable is not defined in this scope");
		}
		add_op( id + ", " + get_op_val(), "arr<int>");
		//cout << " >  []" << id << endl;
	    }
#line 2336 "mini.tab.c" /* yacc.c:1646  */
    break;


#line 2340 "mini.tab.c" /* yacc.c:1646  */
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
#line 723 "mini.y" /* yacc.c:1906  */




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


