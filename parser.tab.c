/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <cstdio>
    #include <cstdlib>
    #include <string.h>
    #include <malloc.h>

    int yylex();
    int yylineo();
    void yyerror(const char *s) {
        fprintf(stderr, "Error at line %i: %s\n",yylineo(), s);
    }

#line 84 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_RELOP = 5,                      /* RELOP  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_TIMES = 15,                     /* TIMES  */
  YYSYMBOL_DIV = 16,                       /* DIV  */
  YYSYMBOL_PV = 17,                        /* PV  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_OP = 19,                        /* OP  */
  YYSYMBOL_CP = 20,                        /* CP  */
  YYSYMBOL_OB = 21,                        /* OB  */
  YYSYMBOL_CB = 22,                        /* CB  */
  YYSYMBOL_OCB = 23,                       /* OCB  */
  YYSYMBOL_CCB = 24,                       /* CCB  */
  YYSYMBOL_EQUAL = 25,                     /* EQUAL  */
  YYSYMBOL_VEJODEPOIS = 26,                /* VEJODEPOIS  */
  YYSYMBOL_ERROR = 27,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_programa = 29,                  /* programa  */
  YYSYMBOL_30_declaracao_lista = 30,       /* declaracao-lista  */
  YYSYMBOL_declaracao = 31,                /* declaracao  */
  YYSYMBOL_32_var_declaracao = 32,         /* var-declaracao  */
  YYSYMBOL_33_tipo_especificador = 33,     /* tipo-especificador  */
  YYSYMBOL_34_fun_declaracao = 34,         /* fun-declaracao  */
  YYSYMBOL_params = 35,                    /* params  */
  YYSYMBOL_36_params_lista = 36,           /* params-lista  */
  YYSYMBOL_param = 37,                     /* param  */
  YYSYMBOL_38_composto_decl = 38,          /* composto-decl  */
  YYSYMBOL_39_local_declaracoes = 39,      /* local-declaracoes  */
  YYSYMBOL_40_statement_lista = 40,        /* statement-lista  */
  YYSYMBOL_statement = 41,                 /* statement  */
  YYSYMBOL_42_expressao_decl = 42,         /* expressao-decl  */
  YYSYMBOL_43_selecao_decl = 43,           /* selecao-decl  */
  YYSYMBOL_44_iteracao_decl = 44,          /* iteracao-decl  */
  YYSYMBOL_45_retorno_decl = 45,           /* retorno-decl  */
  YYSYMBOL_expressao = 46,                 /* expressao  */
  YYSYMBOL_var = 47,                       /* var  */
  YYSYMBOL_48_simples_expressao = 48,      /* simples-expressao  */
  YYSYMBOL_49_soma_expressao = 49,         /* soma-expressao  */
  YYSYMBOL_soma = 50,                      /* soma  */
  YYSYMBOL_termo = 51,                     /* termo  */
  YYSYMBOL_mult = 52,                      /* mult  */
  YYSYMBOL_fator = 53,                     /* fator  */
  YYSYMBOL_ativacao = 54,                  /* ativacao  */
  YYSYMBOL_args = 55,                      /* args  */
  YYSYMBOL_56_arg_lista = 56               /* arg-lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    51,    57,    64,    69,    76,    85,   101,
     106,   114,   129,   134,   141,   148,   155,   164,   178,   188,
     194,   200,   206,   212,   217,   222,   227,   232,   239,   244,
     250,   259,   272,   283,   288,   296,   303,   310,   318,   331,
     341,   346,   349,   356,   363,   368,   375,   382,   389,   394,
     401,   408,   413,   418,   427,   440,   445,   450,   457
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "ID",
  "RELOP", "INT", "VOID", "IF", "ELSE", "RETURN", "WHILE", "FOR", "PLUS",
  "MINUS", "TIMES", "DIV", "PV", "COMMA", "OP", "CP", "OB", "CB", "OCB",
  "CCB", "EQUAL", "VEJODEPOIS", "ERROR", "$accept", "programa",
  "declaracao-lista", "declaracao", "var-declaracao", "tipo-especificador",
  "fun-declaracao", "params", "params-lista", "param", "composto-decl",
  "local-declaracoes", "statement-lista", "statement", "expressao-decl",
  "selecao-decl", "iteracao-decl", "retorno-decl", "expressao", "var",
  "simples-expressao", "soma-expressao", "soma", "termo", "mult", "fator",
  "ativacao", "args", "arg-lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      43,   -42,   -42,    10,    68,   -42,   -42,    27,   -42,   -42,
     -42,   -42,    17,   -42,    64,    11,     1,    31,    22,    45,
     -42,    23,    55,    49,    43,    65,    59,   -42,   -42,   -42,
     -42,   -42,    43,   -42,    82,     5,   -16,   -42,   -42,   -17,
      69,    50,    70,   -42,    54,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    73,    62,   -42,    51,    63,   -42,   -42,    40,
      54,    54,   -42,   -42,    54,    72,   -42,    54,     8,   -42,
     -42,     8,   -42,   -42,     8,   -42,    74,    75,    76,    77,
      79,   -42,   -42,   -42,    71,    63,   -42,   -42,    54,   -42,
      29,    29,   -42,    86,   -42,    29,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     0,     4,     5,     0,     6,     1,
       2,     3,     0,     7,     0,     0,    10,     0,     0,    12,
      15,     0,    16,     0,     0,     0,     0,    20,    11,    14,
       8,    17,    22,    19,     0,     0,     0,    41,    53,    37,
       0,     0,     0,    29,     0,    18,    24,    21,    23,    25,
      26,    27,     0,    51,    36,    40,    43,    47,    52,     0,
       0,     0,    33,    34,     0,     0,    28,     0,     0,    44,
      45,     0,    48,    49,     0,    58,     0,    55,     0,     0,
       0,    50,    35,    51,    39,    42,    46,    54,     0,    38,
       0,     0,    57,    30,    32,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,    87,    78,    -7,   -42,   -42,   -42,    80,
      83,   -42,   -42,   -29,   -42,   -42,   -42,   -42,   -41,     9,
     -42,    28,   -42,    30,   -42,    26,   -42,   -42,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    32,    35,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    71,    56,    74,    57,    58,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    13,    59,    65,    60,    15,    37,    17,    38,    39,
       9,    38,    39,    40,    21,    41,    42,    17,    75,    78,
      79,   -13,    43,    80,    44,    34,    82,    44,    27,    45,
      37,    12,    38,    39,    13,    22,    14,    40,    15,    41,
      42,    37,    23,    38,    39,    25,    43,    92,    44,     1,
       2,    37,    27,    38,    39,    37,    68,    38,    39,    44,
     -56,    93,    94,    24,    69,    70,    96,    62,    10,    44,
       1,    16,    27,    44,     1,     2,    26,    83,    72,    73,
      83,    31,    30,    83,    69,    70,    36,    67,    61,    64,
      66,    11,    81,    88,    87,    95,    84,    90,    89,    91,
      86,    85,     0,     0,    29,     0,    28,     0,     0,     0,
      33
};

static const yytype_int8 yycheck[] =
{
      41,    17,    19,    44,    21,    21,     1,    14,     3,     4,
       0,     3,     4,     8,     3,    10,    11,    24,    59,    60,
      61,    20,    17,    64,    19,    32,    67,    19,    23,    24,
       1,     4,     3,     4,    17,     4,    19,     8,    21,    10,
      11,     1,    20,     3,     4,    22,    17,    88,    19,     6,
       7,     1,    23,     3,     4,     1,     5,     3,     4,    19,
      20,    90,    91,    18,    13,    14,    95,    17,     0,    19,
       6,     7,    23,    19,     6,     7,    21,    68,    15,    16,
      71,    22,    17,    74,    13,    14,     4,    25,    19,    19,
      17,     4,    20,    18,    20,     9,    68,    20,    22,    20,
      74,    71,    -1,    -1,    24,    -1,    23,    -1,    -1,    -1,
      32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    29,    30,    31,    32,    33,    34,     0,
       0,    31,     4,    17,    19,    21,     7,    33,    35,    36,
      37,     3,     4,    20,    18,    22,    21,    23,    38,    37,
      17,    22,    39,    32,    33,    40,     4,     1,     3,     4,
       8,    10,    11,    17,    19,    24,    38,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    51,    53,    54,    19,
      21,    19,    17,    46,    19,    46,    17,    25,     5,    13,
      14,    50,    15,    16,    52,    46,    55,    56,    46,    46,
      46,    20,    46,    47,    49,    51,    53,    20,    18,    22,
      20,    20,    46,    41,    41,     9,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    32,    32,    33,
      33,    34,    35,    35,    36,    36,    37,    37,    38,    39,
      39,    40,    40,    41,    41,    41,    41,    41,    42,    42,
      43,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    54,    55,    55,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     2,     3,     1,     1,     4,     3,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* programa: declaracao-lista $end  */
#line 42 "parser.y"
                          { 
        (yyval.ast) = new ASTNode("programa");
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        AST* tree = new AST((yyval.ast));
        tree->transformToAST();
        tree->printTree();
    }
#line 1198 "parser.tab.c"
    break;

  case 3: /* declaracao-lista: declaracao-lista declaracao  */
#line 51 "parser.y"
                                { 
        //printf("Parsed a declaracao-lista com 2\n"); 
        (yyval.ast) = new ASTNode("declaracao-lista");
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
        }
#line 1209 "parser.tab.c"
    break;

  case 4: /* declaracao-lista: declaracao  */
#line 57 "parser.y"
               { 
        //printf("Parsed a declaracao-listacom 1\n"); 
        (yyval.ast) = new ASTNode("declaracao-lista");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
        }
#line 1219 "parser.tab.c"
    break;

  case 5: /* declaracao: var-declaracao  */
#line 64 "parser.y"
                   { 
        //printf("Parsed a declaracao\n"); 
        (yyval.ast) = new ASTNode("declaracao");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
        }
#line 1229 "parser.tab.c"
    break;

  case 6: /* declaracao: fun-declaracao  */
#line 69 "parser.y"
                   { 
        //printf("Parsed a declaracao\n"); 
        (yyval.ast) = new ASTNode("declaracao");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1239 "parser.tab.c"
    break;

  case 7: /* var-declaracao: tipo-especificador ID PV  */
#line 76 "parser.y"
                             { 
        //printf("Parsed a var-declaracao\n"); 
        (yyval.ast) = new ASTNode("var-declaracao");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[-1].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);
    }
#line 1253 "parser.tab.c"
    break;

  case 8: /* var-declaracao: tipo-especificador ID OB NUMBER CB PV  */
#line 85 "parser.y"
                                          { 
        //printf("Parsed a var-declaracao\n"); 
        (yyval.ast) = new ASTNode("var-declaracao");
        (yyval.ast)->insertChildren((yyvsp[-5].ast));
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[-4].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);
        (yyval.ast)->insertChildren(new ASTNode("OB"));
        char* number = (char*) malloc(sizeof(char)*20);
        sprintf(number, "NUM(%d)", (yyvsp[-2].intval));
        (yyval.ast)->insertChildren(new ASTNode(number));
        (yyval.ast)->insertChildren(new ASTNode("CB"));
    }
#line 1272 "parser.tab.c"
    break;

  case 9: /* tipo-especificador: INT  */
#line 101 "parser.y"
        { 
        //printf("Parsed a tipo-especificador \n") ;
        (yyval.ast) = new ASTNode("tipo-especificador");
        (yyval.ast)->insertChildren(new ASTNode("int"));
    }
#line 1282 "parser.tab.c"
    break;

  case 10: /* tipo-especificador: VOID  */
#line 106 "parser.y"
         { 
        //printf("Parsed a tipo-especificador \n") ;
        (yyval.ast) = new ASTNode("tipo-especificador");
        (yyval.ast)->insertChildren(new ASTNode("void"));
    }
#line 1292 "parser.tab.c"
    break;

  case 11: /* fun-declaracao: tipo-especificador ID OP params CP composto-decl  */
#line 114 "parser.y"
                                                     { 
        //printf("Parsed a fun-declaracao\n"); 
        (yyval.ast) = new ASTNode("fun-declaracao");
        (yyval.ast)->insertChildren((yyvsp[-5].ast));
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[-4].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);
        (yyval.ast)->insertChildren(new ASTNode("OP"));
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("CP"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1310 "parser.tab.c"
    break;

  case 12: /* params: params-lista  */
#line 129 "parser.y"
                 { 
        //printf("Parsed a params\n"); 
        (yyval.ast) = new ASTNode("params");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1320 "parser.tab.c"
    break;

  case 13: /* params: VOID  */
#line 134 "parser.y"
         { 
        //printf("Parsed a params\n"); 
        (yyval.ast) = new ASTNode("params");
        (yyval.ast)->insertChildren(new ASTNode("void"));
        }
#line 1330 "parser.tab.c"
    break;

  case 14: /* params-lista: params-lista COMMA param  */
#line 141 "parser.y"
                             { 
        //printf("Parsed a params-lista\n"); 
        (yyval.ast) = new ASTNode("params-lista");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("COMMA"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1342 "parser.tab.c"
    break;

  case 15: /* params-lista: param  */
#line 148 "parser.y"
          { 
        //printf("Parsed a params-lista\n"); 
        (yyval.ast) = new ASTNode("params-lista");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1352 "parser.tab.c"
    break;

  case 16: /* param: tipo-especificador ID  */
#line 155 "parser.y"
                          { 
        //printf("Parsed a param\n"); 
        (yyval.ast) = new ASTNode("param");
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[0].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);
    }
#line 1366 "parser.tab.c"
    break;

  case 17: /* param: tipo-especificador ID OB CB  */
#line 164 "parser.y"
                                { 
        //printf("Parsed a param\n"); 
        (yyval.ast) = new ASTNode("param");
        (yyval.ast)->insertChildren((yyvsp[-3].ast));
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[-2].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);
        (yyval.ast)->insertChildren(new ASTNode("OB"));
        (yyval.ast)->insertChildren(new ASTNode("CB"));
        (yyval.ast)->insertChildren(new ASTNode("vector"));
    }
#line 1383 "parser.tab.c"
    break;

  case 18: /* composto-decl: OCB local-declaracoes statement-lista CCB  */
#line 178 "parser.y"
                                              { 
        //printf("Parsed a composto-decl\n"); 
        (yyval.ast) = new ASTNode("composto-decl");
        (yyval.ast)->insertChildren(new ASTNode("OCB"));
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren(new ASTNode("CCB"));
    }
#line 1396 "parser.tab.c"
    break;

  case 19: /* local-declaracoes: local-declaracoes var-declaracao  */
#line 188 "parser.y"
                                     { 
        //printf("Parsed a local-declaracoes\n"); 
        (yyval.ast) = new ASTNode("local-declaracoes");
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren((yyvsp[0].ast));    
    }
#line 1407 "parser.tab.c"
    break;

  case 20: /* local-declaracoes: %empty  */
#line 194 "parser.y"
                  {         
        //printf("Parsed a local-declaracoes\n"); 
        (yyval.ast) = new ASTNode("local-declaracoes");
    }
#line 1416 "parser.tab.c"
    break;

  case 21: /* statement-lista: statement-lista statement  */
#line 200 "parser.y"
                              { 
        //printf("Parsed a statement-lista\n"); 
        (yyval.ast) = new ASTNode("statement-lista");
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren((yyvsp[0].ast));  
    }
#line 1427 "parser.tab.c"
    break;

  case 22: /* statement-lista: %empty  */
#line 206 "parser.y"
                  { 
        //printf("Parsed a statement-lista\n"); 
        (yyval.ast) = new ASTNode("statement-lista");
     }
#line 1436 "parser.tab.c"
    break;

  case 23: /* statement: expressao-decl  */
#line 212 "parser.y"
                   { 
        //printf("Parsed a statement\n"); 
        (yyval.ast) = new ASTNode("statement");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1446 "parser.tab.c"
    break;

  case 24: /* statement: composto-decl  */
#line 217 "parser.y"
                  { 
        //printf("Parsed a statement\n"); 
        (yyval.ast) = new ASTNode("statement");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1456 "parser.tab.c"
    break;

  case 25: /* statement: selecao-decl  */
#line 222 "parser.y"
                 { 
        //printf("Parsed a statement\n"); 
        (yyval.ast) = new ASTNode("statement");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1466 "parser.tab.c"
    break;

  case 26: /* statement: iteracao-decl  */
#line 227 "parser.y"
                  { 
        //printf("Parsed a statement\n"); 
        (yyval.ast) = new ASTNode("statement");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1476 "parser.tab.c"
    break;

  case 27: /* statement: retorno-decl  */
#line 232 "parser.y"
                 { 
        //printf("Parsed a statement\n"); 
        (yyval.ast) = new ASTNode("statement");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1486 "parser.tab.c"
    break;

  case 28: /* expressao-decl: expressao PV  */
#line 239 "parser.y"
                 { 
        //printf("Parsed a expressao-decl\n"); 
        (yyval.ast) = new ASTNode("expressao-decl");
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
    }
#line 1496 "parser.tab.c"
    break;

  case 29: /* expressao-decl: PV  */
#line 244 "parser.y"
       { 
        //printf("Parsed a expressao-decl\n"); 
        (yyval.ast) = new ASTNode("expressao-decl");
    }
#line 1505 "parser.tab.c"
    break;

  case 30: /* selecao-decl: IF OP expressao CP statement  */
#line 250 "parser.y"
                                 { 
        //printf("Parsed a selecao-decl\n"); 
        (yyval.ast) = new ASTNode("selecao-decl");
        (yyval.ast)->insertChildren(new ASTNode("IF"));
        (yyval.ast)->insertChildren(new ASTNode("OP"));
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("CP"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1519 "parser.tab.c"
    break;

  case 31: /* selecao-decl: IF OP expressao CP statement ELSE statement  */
#line 259 "parser.y"
                                                { 
        //printf("Parsed a selecao-decl\n"); 
        (yyval.ast) = new ASTNode("selecao-decl");
        (yyval.ast)->insertChildren(new ASTNode("IF"));
        (yyval.ast)->insertChildren(new ASTNode("OP"));
        (yyval.ast)->insertChildren((yyvsp[-4].ast));
        (yyval.ast)->insertChildren(new ASTNode("CP"));
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("ELSE"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1535 "parser.tab.c"
    break;

  case 32: /* iteracao-decl: WHILE OP expressao CP statement  */
#line 272 "parser.y"
                                    { 
        //printf("Parsed a iteracao-decl\n"); 
        (yyval.ast) = new ASTNode("iteracao-decl");
        (yyval.ast)->insertChildren(new ASTNode("WHILE"));
        (yyval.ast)->insertChildren(new ASTNode("OP"));
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("CP"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1549 "parser.tab.c"
    break;

  case 33: /* retorno-decl: RETURN PV  */
#line 283 "parser.y"
              { 
        //printf("Parsed a retorno-decl\n"); 
        (yyval.ast) = new ASTNode("retorno-decl");
        (yyval.ast)->insertChildren(new ASTNode("RETURN"));
    }
#line 1559 "parser.tab.c"
    break;

  case 34: /* retorno-decl: RETURN expressao  */
#line 288 "parser.y"
                     { 
        //printf("Parsed a retorno-decl\n"); 
        (yyval.ast) = new ASTNode("retorno-decl");
        (yyval.ast)->insertChildren(new ASTNode("RETURN"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1570 "parser.tab.c"
    break;

  case 35: /* expressao: var EQUAL expressao  */
#line 296 "parser.y"
                        { 
        //printf("Parsed a expressao\n"); 
        (yyval.ast) = new ASTNode("expressao");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("EQUAL"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));    
    }
#line 1582 "parser.tab.c"
    break;

  case 36: /* expressao: simples-expressao  */
#line 303 "parser.y"
                      { 
        //printf("Parsed a expressao\n"); 
        (yyval.ast) = new ASTNode("expressao");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1592 "parser.tab.c"
    break;

  case 37: /* var: ID  */
#line 310 "parser.y"
       { 
        //printf("Parsed a var\n"); 
        (yyval.ast) = new ASTNode("var");
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[0].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id); 
    }
#line 1605 "parser.tab.c"
    break;

  case 38: /* var: ID OB expressao CB  */
#line 318 "parser.y"
                       { 
        //printf("Parsed a var\n"); 
        (yyval.ast) = new ASTNode("var");
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[-3].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);    
        (yyval.ast)->insertChildren(new ASTNode("OB"));
        (yyval.ast)->insertChildren((yyvsp[-1].ast)); 
        (yyval.ast)->insertChildren(new ASTNode("CB"));  
    }
#line 1621 "parser.tab.c"
    break;

  case 39: /* simples-expressao: soma-expressao RELOP soma-expressao  */
#line 331 "parser.y"
                                        { 
        //printf("Parsed a simplex-exmpressao\n"); 
        (yyval.ast) = new ASTNode("simples-expressao");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        char* relop = (char*) malloc(sizeof(char) * 10);
        sprintf(relop, "%s", (yyvsp[-1].strval));
        (yyval.ast)->insertChildren(new ASTNode(relop));
        free(relop); 
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1636 "parser.tab.c"
    break;

  case 40: /* simples-expressao: soma-expressao  */
#line 341 "parser.y"
                   { 
        //printf("Parsed a simplex-exmpressao\n"); 
        (yyval.ast) = new ASTNode("simples-expressao");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1646 "parser.tab.c"
    break;

  case 42: /* soma-expressao: soma-expressao soma termo  */
#line 349 "parser.y"
                              { 
        //printf("Parsed a soma-expressao\n"); 
        (yyval.ast) = new ASTNode("soma-expressao");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1658 "parser.tab.c"
    break;

  case 43: /* soma-expressao: termo  */
#line 356 "parser.y"
          { 
        //printf("Parsed a soma-expressao\n"); 
        (yyval.ast) = new ASTNode("soma-expressao");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1668 "parser.tab.c"
    break;

  case 44: /* soma: PLUS  */
#line 363 "parser.y"
         { 
        //printf("Parsed a soma\n"); 
        (yyval.ast) = new ASTNode("soma");
        (yyval.ast)->insertChildren(new ASTNode("PLUS"));    
    }
#line 1678 "parser.tab.c"
    break;

  case 45: /* soma: MINUS  */
#line 368 "parser.y"
          { 
        //printf("Parsed a soma\n"); 
        (yyval.ast) = new ASTNode("soma");
        (yyval.ast)->insertChildren(new ASTNode("MINUS"));    
    }
#line 1688 "parser.tab.c"
    break;

  case 46: /* termo: termo mult fator  */
#line 375 "parser.y"
                     { 
        //printf("Parsed a termo\n"); 
        (yyval.ast) = new ASTNode("termo");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1700 "parser.tab.c"
    break;

  case 47: /* termo: fator  */
#line 382 "parser.y"
          { 
        //printf("Parsed a termo\n"); 
        (yyval.ast) = new ASTNode("termo");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1710 "parser.tab.c"
    break;

  case 48: /* mult: TIMES  */
#line 389 "parser.y"
          { 
        //printf("Parsed a mult\n"); 
        (yyval.ast) = new ASTNode("mult");
        (yyval.ast)->insertChildren(new ASTNode("TIMES"));    
    }
#line 1720 "parser.tab.c"
    break;

  case 49: /* mult: DIV  */
#line 394 "parser.y"
        { 
        //printf("Parsed a div\n"); 
        (yyval.ast) = new ASTNode("div");
        (yyval.ast)->insertChildren(new ASTNode("DIV"));    
    }
#line 1730 "parser.tab.c"
    break;

  case 50: /* fator: OP expressao CP  */
#line 401 "parser.y"
                    { 
        //printf("Parsed a fator\n"); 
        (yyval.ast) = new ASTNode("fator");
        (yyval.ast)->insertChildren(new ASTNode("OP"));
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren(new ASTNode("CP"));
    }
#line 1742 "parser.tab.c"
    break;

  case 51: /* fator: var  */
#line 408 "parser.y"
        { 
        //printf("Parsed a fator\n"); 
        (yyval.ast) = new ASTNode("fator");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1752 "parser.tab.c"
    break;

  case 52: /* fator: ativacao  */
#line 413 "parser.y"
             { 
        //printf("Parsed a fator\n"); 
        (yyval.ast) = new ASTNode("fator");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1762 "parser.tab.c"
    break;

  case 53: /* fator: NUMBER  */
#line 418 "parser.y"
           { 
        //printf("Parsed a fator\n"); 
        (yyval.ast) = new ASTNode("fator");
        char* number = (char*) malloc(sizeof(char)*20);
        sprintf(number, "NUM(%d)", (yyvsp[0].intval));
        (yyval.ast)->insertChildren(new ASTNode(number));
    }
#line 1774 "parser.tab.c"
    break;

  case 54: /* ativacao: ID OP args CP  */
#line 427 "parser.y"
                  { 
        //printf("Parsed a ativacao\n"); 
        (yyval.ast) = new ASTNode("ativacao");
        char* id = (char*) malloc(sizeof(char)*50);
        sprintf(id, "ID(%s)", (yyvsp[-3].strval));
        (yyval.ast)->insertChildren(new ASTNode(id));
        free(id);
        (yyval.ast)->insertChildren(new ASTNode("OP"));
        (yyval.ast)->insertChildren((yyvsp[-1].ast));
        (yyval.ast)->insertChildren(new ASTNode("CP"));    
    }
#line 1790 "parser.tab.c"
    break;

  case 55: /* args: arg-lista  */
#line 440 "parser.y"
              { 
        //printf("Parsed a args\n"); 
        (yyval.ast) = new ASTNode("args");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1800 "parser.tab.c"
    break;

  case 56: /* args: %empty  */
#line 445 "parser.y"
                  { 
        //printf("Parsed a args\n"); 
        (yyval.ast) = new ASTNode("args");
     }
#line 1809 "parser.tab.c"
    break;

  case 57: /* arg-lista: arg-lista COMMA expressao  */
#line 450 "parser.y"
                              { 
        //printf("Parsed a arg-lista\n"); 
        (yyval.ast) = new ASTNode("arg-lista");
        (yyval.ast)->insertChildren((yyvsp[-2].ast));
        (yyval.ast)->insertChildren(new ASTNode("COMMA"));
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1821 "parser.tab.c"
    break;

  case 58: /* arg-lista: expressao  */
#line 457 "parser.y"
              { 
        //printf("Parsed a arg-lista\n"); 
        (yyval.ast) = new ASTNode("arg-lista");
        (yyval.ast)->insertChildren((yyvsp[0].ast));
    }
#line 1831 "parser.tab.c"
    break;


#line 1835 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 462 "parser.y"


