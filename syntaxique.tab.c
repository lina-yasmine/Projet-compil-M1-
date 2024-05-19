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
#line 1 "syntaxique.y"

	#include "quad.c"
	#include <stddef.h>
	#include <stdio.h>
	#include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <time.h>
	#include "pile.h"
	#include "mot.c"
	#include "ts.c"

	int line_number=1, Col=0;
	int ntemp=1;
	char temp [20];
	char temp2 [20];
	char temp3 [20];
	char suavT [20];
	char suavType [20];
	char* sauvidf; 
	char * out;
	char opr1 [20];
	int valTab;
	char sauv_list_obj [20][100];
	int indice_obj = 0;
	char sauv_list_obj2 [20][100];
	int indice_obj2 = 0;
	int qcT=0;
	int qcElse=0;
	int qct2=0;

	int yylex();
	int yyerror(char* msg);
	void afficheErreur(char* d , int a);



#line 109 "syntaxique.tab.c"

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

#include "syntaxique.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_mc_var = 3,                     /* mc_var  */
  YYSYMBOL_mc_dec = 4,                     /* mc_dec  */
  YYSYMBOL_mc_inst = 5,                    /* mc_inst  */
  YYSYMBOL_mc_read = 6,                    /* mc_read  */
  YYSYMBOL_mc_write = 7,                   /* mc_write  */
  YYSYMBOL_mc_int = 8,                     /* mc_int  */
  YYSYMBOL_mc_float = 9,                   /* mc_float  */
  YYSYMBOL_mc_const = 10,                  /* mc_const  */
  YYSYMBOL_mc_struct = 11,                 /* mc_struct  */
  YYSYMBOL_mc_if = 12,                     /* mc_if  */
  YYSYMBOL_mc_else = 13,                   /* mc_else  */
  YYSYMBOL_mc_for = 14,                    /* mc_for  */
  YYSYMBOL_mc_while = 15,                  /* mc_while  */
  YYSYMBOL_idf = 16,                       /* idf  */
  YYSYMBOL_entier = 17,                    /* entier  */
  YYSYMBOL_entier_sign = 18,               /* entier_sign  */
  YYSYMBOL_reel = 19,                      /* reel  */
  YYSYMBOL_reel_sign = 20,                 /* reel_sign  */
  YYSYMBOL_chaineC = 21,                   /* chaineC  */
  YYSYMBOL_and = 22,                       /* and  */
  YYSYMBOL_or = 23,                        /* or  */
  YYSYMBOL_negation = 24,                  /* negation  */
  YYSYMBOL_sup = 25,                       /* sup  */
  YYSYMBOL_inf = 26,                       /* inf  */
  YYSYMBOL_sup_eg = 27,                    /* sup_eg  */
  YYSYMBOL_inf_eg = 28,                    /* inf_eg  */
  YYSYMBOL_egal = 29,                      /* egal  */
  YYSYMBOL_not_egal = 30,                  /* not_egal  */
  YYSYMBOL_slash = 31,                     /* slash  */
  YYSYMBOL_plus = 32,                      /* plus  */
  YYSYMBOL_minus = 33,                     /* minus  */
  YYSYMBOL_multiply = 34,                  /* multiply  */
  YYSYMBOL_pnt_vir = 35,                   /* pnt_vir  */
  YYSYMBOL_virgule = 36,                   /* virgule  */
  YYSYMBOL_aff = 37,                       /* aff  */
  YYSYMBOL_square_brackets_o = 38,         /* square_brackets_o  */
  YYSYMBOL_square_brackets_f = 39,         /* square_brackets_f  */
  YYSYMBOL_curly_brackets_o = 40,          /* curly_brackets_o  */
  YYSYMBOL_curly_brackets_f = 41,          /* curly_brackets_f  */
  YYSYMBOL_round_brackets_o = 42,          /* round_brackets_o  */
  YYSYMBOL_round_brackets_f = 43,          /* round_brackets_f  */
  YYSYMBOL_pnt = 44,                       /* pnt  */
  YYSYMBOL_double_pnt = 45,                /* double_pnt  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_S = 47,                         /* S  */
  YYSYMBOL_GLOBAL_DECLARATIONS = 48,       /* GLOBAL_DECLARATIONS  */
  YYSYMBOL_LOCAL_DECLARATIONS = 49,        /* LOCAL_DECLARATIONS  */
  YYSYMBOL_DECLARATION_VARIABLE = 50,      /* DECLARATION_VARIABLE  */
  YYSYMBOL_TYPE = 51,                      /* TYPE  */
  YYSYMBOL_LISTE_VAR = 52,                 /* LISTE_VAR  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_VALUE = 54,                     /* VALUE  */
  YYSYMBOL_PARTIE_CODE = 55,               /* PARTIE_CODE  */
  YYSYMBOL_SIMPLE_INSTRUCTIONS = 56,       /* SIMPLE_INSTRUCTIONS  */
  YYSYMBOL_LEFT_SIDE = 57,                 /* LEFT_SIDE  */
  YYSYMBOL_RIGHT_SIDE = 58,                /* RIGHT_SIDE  */
  YYSYMBOL_ELEMENT = 59,                   /* ELEMENT  */
  YYSYMBOL_OPER = 60,                      /* OPER  */
  YYSYMBOL_case = 61,                      /* case  */
  YYSYMBOL_var = 62,                       /* var  */
  YYSYMBOL_COMPLEX_INSTRUCTIONS = 63,      /* COMPLEX_INSTRUCTIONS  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_INSTRUCTION_WRITE = 68,         /* INSTRUCTION_WRITE  */
  YYSYMBOL_write_arg = 69,                 /* write_arg  */
  YYSYMBOL_ELSE = 70,                      /* ELSE  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_CONDITION = 72,                 /* CONDITION  */
  YYSYMBOL_CMP = 73,                       /* CMP  */
  YYSYMBOL_INIT_FINISH = 74                /* INIT_FINISH  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    88,    89,    92,    93,    96,    98,   121,
     136,   148,   169,   170,   174,   174,   187,   203,   204,   205,
     210,   219,   220,   221,   227,   247,   262,   273,   279,   305,
     330,   336,   377,   404,   418,   421,   425,   426,   427,   428,
     431,   448,   459,   466,   465,   473,   472,   509,   513,   508,
     524,   525,   529,   530,   534,   535,   538,   538,   547,   553,
     568,   588,   607,   619,   635,   654,   678,   696,   724,   725,
     726,   727,   728,   729,   732,   733
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
  "\"end of file\"", "error", "\"invalid token\"", "mc_var", "mc_dec",
  "mc_inst", "mc_read", "mc_write", "mc_int", "mc_float", "mc_const",
  "mc_struct", "mc_if", "mc_else", "mc_for", "mc_while", "idf", "entier",
  "entier_sign", "reel", "reel_sign", "chaineC", "and", "or", "negation",
  "sup", "inf", "sup_eg", "inf_eg", "egal", "not_egal", "slash", "plus",
  "minus", "multiply", "pnt_vir", "virgule", "aff", "square_brackets_o",
  "square_brackets_f", "curly_brackets_o", "curly_brackets_f",
  "round_brackets_o", "round_brackets_f", "pnt", "double_pnt", "$accept",
  "S", "GLOBAL_DECLARATIONS", "LOCAL_DECLARATIONS", "DECLARATION_VARIABLE",
  "TYPE", "LISTE_VAR", "$@1", "VALUE", "PARTIE_CODE",
  "SIMPLE_INSTRUCTIONS", "LEFT_SIDE", "RIGHT_SIDE", "ELEMENT", "OPER",
  "case", "var", "COMPLEX_INSTRUCTIONS", "$@2", "$@3", "$@4", "$@5",
  "INSTRUCTION_WRITE", "write_arg", "ELSE", "$@6", "CONDITION", "CMP",
  "INIT_FINISH", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -30,    18,    75,   -85,   -85,   -85,    55,    15,    46,
      77,    54,    94,    75,    -8,   -85,    40,    61,   -85,    40,
      23,    78,   -85,   -85,   -85,    97,   -85,    75,   -85,    79,
      82,   101,    76,    81,    95,   -85,   -85,    96,   -85,   -85,
     123,    75,    92,   -85,    88,    87,    91,    98,    99,   100,
     105,   103,    88,   102,   -85,    88,   118,    49,    -3,   119,
     -85,    33,   -85,   -85,     6,   -85,   104,   -85,   -85,   106,
     109,   105,   108,    16,   -85,    80,    93,   -85,   110,   107,
      -3,   -85,   -85,   112,    27,   111,   113,   120,    49,     6,
      80,    45,   -85,   -85,   -85,   -85,   -85,   -85,     6,   -85,
     -85,   -85,   -85,     6,   -85,    73,   114,   -85,    45,   -85,
     -85,   -85,   -85,    80,     6,    93,     6,    39,   -85,   116,
     -85,   -85,   115,   -85,     6,     6,   121,     6,   122,    -3,
      -3,    88,   137,   126,   122,   124,    74,   -85,    93,   -85,
     -85,   117,   125,    88,    89,    -3,    -3,     6,   146,    73,
     127,    -3,    -3,   -85,   -85,   -85,   -85,   148,   128,   -85,
     -85,   -85,   129,   -85,    88,   132,   133,    88,   -85,   134,
     -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     1,    12,    13,     0,     0,     0,
       0,     0,     0,     4,    14,     7,     0,     0,     3,     0,
       0,     0,    17,    19,    20,     0,     9,     6,     8,     0,
       0,     0,     0,     0,     0,    10,    11,    14,    15,    18,
       0,     6,     0,     5,    23,     0,     0,     0,     0,     0,
      25,     0,    23,     0,    26,    23,     0,     0,     0,     0,
      47,     0,     2,    21,     0,    22,     0,    55,    54,     0,
      52,    33,     0,     0,    35,     0,    27,    34,     0,     0,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    68,    69,    70,    71,    72,    73,     0,    38,
      36,    37,    39,     0,    43,     0,     0,    40,     0,    24,
      50,    51,    53,     0,     0,    30,     0,    59,    28,     0,
      75,    74,     0,    48,     0,     0,     0,     0,    28,     0,
       0,    23,     0,     0,     0,     0,    62,    29,    32,    60,
      61,     0,     0,    23,    63,     0,     0,     0,    58,     0,
       0,     0,     0,    64,    66,    31,    44,     0,     0,    49,
      65,    67,     0,    45,    23,     0,     0,    23,    57,     0,
      46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   149,   135,   -22,   -85,   142,   -85,    56,   -51,
     -85,   -85,   -61,   -64,   -84,   -44,   -85,   -85,   -85,   -85,
     -85,   -85,    48,   -85,   -85,   -85,   -78,   -75,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,    33,     9,    10,    15,    21,    74,    51,
      52,    53,    75,    76,   103,    77,    83,    55,   119,   165,
      80,   133,    69,    70,   156,   157,    78,    98,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    63,   106,    85,    65,    34,     1,   116,    54,    91,
       3,    54,    90,    71,    22,   114,    23,    24,     4,    34,
     108,    72,    71,    22,   124,    23,    24,   -16,   113,    19,
      20,   127,    71,    22,    32,    23,    24,   117,   125,    73,
      29,    30,   118,    71,    22,    32,    23,    24,    84,    81,
      82,   139,   140,   126,   147,   128,    12,    22,    84,    23,
      24,   129,   130,   134,   135,    67,   137,   153,   154,    25,
      68,    11,    26,   160,   161,    28,    99,   100,   101,   102,
     141,    13,    25,     5,     6,     7,   155,    54,   115,   120,
     121,    16,   150,    14,    45,    46,   145,   146,    17,    54,
      47,    27,    48,    49,    50,    92,    93,    94,    95,    96,
      97,   151,   152,   166,    31,    32,   169,    37,    35,    39,
      54,    36,    40,    54,    99,   100,   101,   102,    42,    56,
      41,   -16,    44,    57,    66,    79,   112,   158,     0,    64,
      58,    59,    60,    61,    62,    88,   109,    86,   110,    87,
      89,   107,   105,   104,   142,   111,   131,   123,   148,   -56,
     132,   162,    18,     0,   136,   138,   143,   144,   159,   164,
     149,   163,   167,    38,   168,   170,    43
};

static const yytype_int16 yycheck[] =
{
      44,    52,    80,    64,    55,    27,     3,    91,    52,    73,
      40,    55,    73,    16,    17,    90,    19,    20,     0,    41,
      84,    24,    16,    17,   108,    19,    20,    35,    89,    37,
      38,   115,    16,    17,    18,    19,    20,    98,   113,    42,
      17,    18,   103,    16,    17,    18,    19,    20,    42,    16,
      17,   129,   130,   114,   138,   116,    41,    17,    42,    19,
      20,    22,    23,   124,   125,    16,   127,   145,   146,    42,
      21,    16,    16,   151,   152,    19,    31,    32,    33,    34,
     131,    35,    42,     8,     9,    10,   147,   131,    43,    16,
      17,    37,   143,    16,     6,     7,    22,    23,     4,   143,
      12,    40,    14,    15,    16,    25,    26,    27,    28,    29,
      30,    22,    23,   164,    36,    18,   167,    16,    39,    43,
     164,    39,    41,   167,    31,    32,    33,    34,     5,    42,
      35,    35,    40,    42,    16,    16,    88,   149,    -1,    37,
      42,    42,    42,    38,    41,    36,    35,    43,    35,    43,
      42,    39,    45,    43,    17,    35,    40,    43,    41,    13,
      45,    13,    13,    -1,    43,    43,    40,    43,    41,    40,
      45,    43,    40,    31,    41,    41,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    40,     0,     8,     9,    10,    48,    50,
      51,    16,    41,    35,    16,    52,    37,     4,    48,    37,
      38,    53,    17,    19,    20,    42,    54,    40,    54,    17,
      18,    36,    18,    49,    50,    39,    39,    16,    52,    43,
      41,    35,     5,    49,    40,     6,     7,    12,    14,    15,
      16,    55,    56,    57,    61,    63,    42,    42,    42,    42,
      42,    38,    41,    55,    37,    55,    16,    16,    21,    68,
      69,    16,    24,    42,    54,    58,    59,    61,    72,    16,
      66,    16,    17,    62,    42,    58,    43,    43,    36,    42,
      58,    59,    25,    26,    27,    28,    29,    30,    73,    31,
      32,    33,    34,    60,    43,    45,    72,    39,    59,    35,
      35,    35,    68,    58,    73,    43,    60,    58,    58,    64,
      16,    17,    74,    43,    60,    73,    58,    60,    58,    22,
      23,    40,    45,    67,    58,    58,    43,    58,    43,    72,
      72,    55,    17,    40,    43,    22,    23,    60,    41,    45,
      55,    22,    23,    72,    72,    58,    70,    71,    74,    41,
      72,    72,    13,    43,    40,    65,    55,    40,    41,    55,
      41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    50,    51,    51,    53,    52,    52,    54,    54,    54,
      54,    55,    55,    55,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      61,    62,    62,    64,    63,    65,    63,    66,    67,    63,
      63,    63,    68,    68,    69,    69,    71,    70,    70,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    12,     3,     0,     3,     0,     2,     4,     4,
       5,     5,     1,     1,     0,     4,     1,     1,     3,     1,
       1,     2,     2,     0,     4,     1,     1,     1,     3,     5,
       3,     7,     5,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     0,     9,     0,    14,     0,     0,     9,
       5,     5,     1,     3,     1,     1,     0,     5,     0,     3,
       5,     5,     5,     6,     7,     8,     7,     8,     1,     1,
       1,     1,     1,     1,     1,     1
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
  case 2: /* S: mc_var curly_brackets_o GLOBAL_DECLARATIONS curly_brackets_f mc_dec curly_brackets_o LOCAL_DECLARATIONS curly_brackets_f mc_inst curly_brackets_o PARTIE_CODE curly_brackets_f  */
#line 84 "syntaxique.y"
{ printf ("\n\nProgramme syntaxiquement correcte\n\n"); YYACCEPT; }
#line 1283 "syntaxique.tab.c"
    break;

  case 8: /* DECLARATION_VARIABLE: TYPE idf aff VALUE  */
#line 99 "syntaxique.y"
                                           { 
						   if(doubleDeclaration((yyvsp[-2].str))==0 ) 
							{  
									if(strcmp(suavType, (yyvsp[0].EXP).type) != 0) 
									{
										afficheErreur( (yyvsp[-2].str) , 2);
									}
									else 
									{      
										inserIdfDecl((yyvsp[-2].str),"Variable"); 
										insererType((yyvsp[-2].str),suavType,"Variable",1); // taille de ifd = 1
							            insererVal((yyvsp[-2].str),(yyvsp[0].EXP).val,(yyvsp[0].EXP).type); 
										createQuad("=",(yyvsp[0].EXP).t,"",(yyvsp[-2].str));
									}
										 
							}
							else  
							{       
								afficheErreur((yyvsp[-2].str) , 1); 
							}
						}
#line 1309 "syntaxique.tab.c"
    break;

  case 9: /* DECLARATION_VARIABLE: mc_const idf aff VALUE  */
#line 123 "syntaxique.y"
                                    { 
					    if(doubleDeclaration((yyvsp[-2].str))==0 ) 
						{ 
							inserIdfDecl((yyvsp[-2].str),"Constante"); 
							insererType((yyvsp[-2].str) ,suavType,"Constante",1); 
							insererVal((yyvsp[-2].str),(yyvsp[0].EXP).val,(yyvsp[0].EXP).type); 
						}
                        else  
						{   
                            afficheErreur((yyvsp[-2].str) , 1); 
					    }   
					}
#line 1326 "syntaxique.tab.c"
    break;

  case 10: /* DECLARATION_VARIABLE: TYPE idf square_brackets_o entier square_brackets_f  */
#line 137 "syntaxique.y"
                        { 
						    if(doubleDeclaration((yyvsp[-3].str))==0 ) 
							{ 
							    inserIdfDecl((yyvsp[-3].str),"Tableau"); 
								insererType((yyvsp[-3].str),suavType,"Tableau",(yyvsp[-1].num)); 
			                }
                            else 
							{       
                                afficheErreur((yyvsp[-3].str) , 1);
			                }
                        }
#line 1342 "syntaxique.tab.c"
    break;

  case 11: /* DECLARATION_VARIABLE: TYPE idf square_brackets_o entier_sign square_brackets_f  */
#line 149 "syntaxique.y"
                                            { 
						    if(doubleDeclaration((yyvsp[-3].str))==0 ) 
							{ 
							    if( (yyvsp[-1].num)>0 )
								{
             					    inserIdfDecl((yyvsp[-3].str),"Tableau"); 
									insererType((yyvsp[-3].str),suavType,"Tableau",(yyvsp[-1].num)); 
			                    }
							    else 
								{
                                    afficheErreur((yyvsp[-3].str) , 3); 
								}
							}
							else 
							{      
                                afficheErreur((yyvsp[-3].str) , 1);
				            }
                        }
#line 1365 "syntaxique.tab.c"
    break;

  case 12: /* TYPE: mc_int  */
#line 169 "syntaxique.y"
                 {strcpy(suavType,(yyvsp[0].str));}
#line 1371 "syntaxique.tab.c"
    break;

  case 13: /* TYPE: mc_float  */
#line 170 "syntaxique.y"
                           {strcpy(suavType,(yyvsp[0].str));}
#line 1377 "syntaxique.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 174 "syntaxique.y"
                {p = NULL;}
#line 1383 "syntaxique.tab.c"
    break;

  case 15: /* LISTE_VAR: idf $@1 virgule LISTE_VAR  */
#line 175 "syntaxique.y"
                                                    { 
							    if(doubleDeclaration((yyvsp[-3].str))==0 )
								{ 
									inserIdfDecl((yyvsp[-3].str),"Variable"); 
									empiler((yyvsp[-3].str)); 
									while(p != NULL)  insererType(depiler(),suavType,"Variable",1); 
								}
                                else  
								{      
                                    afficheErreur((yyvsp[-3].str) , 1); 
							    }
							}
#line 1400 "syntaxique.tab.c"
    break;

  case 16: /* LISTE_VAR: idf  */
#line 188 "syntaxique.y"
                        { 
			    if(doubleDeclaration((yyvsp[0].str))==0 )
				{ 
					inserIdfDecl((yyvsp[0].str),"Variable"); 
					empiler((yyvsp[0].str)); insererType(depiler(),suavType,"Variable",1);
				}
                else  
				{       
                    afficheErreur((yyvsp[0].str) , 1 ); 
			    }
			}
#line 1416 "syntaxique.tab.c"
    break;

  case 17: /* VALUE: entier  */
#line 203 "syntaxique.y"
               { (yyval.EXP.type)=strdup("INTEGER"); char cstE[15];  sprintf(cstE,"%d",(yyvsp[0].num));    (yyval.EXP).val=strdup(cstE);  (yyval.EXP).t=strdup(cstE);  }
#line 1422 "syntaxique.tab.c"
    break;

  case 18: /* VALUE: round_brackets_o entier_sign round_brackets_f  */
#line 204 "syntaxique.y"
                                                              { (yyval.EXP.type)=strdup("INTEGER"); char cstE[15];  sprintf(cstE,"%d",(yyvsp[-1].num));    (yyval.EXP).val=strdup(cstE);  (yyval.EXP).t=strdup(cstE);   }
#line 1428 "syntaxique.tab.c"
    break;

  case 19: /* VALUE: reel  */
#line 205 "syntaxique.y"
                        { (yyval.EXP.type)=strdup("FLOAT"); char cstReel[20]; 
			int C = (yyvsp[0].real);		
             sprintf(cstReel,"%d",C); 
               (yyval.EXP).val=strdup(cstReel);
			   (yyval.EXP).t=strdup(cstReel); }
#line 1438 "syntaxique.tab.c"
    break;

  case 20: /* VALUE: reel_sign  */
#line 210 "syntaxique.y"
                             { (yyval.EXP.type)=strdup("FLOAT"); char cstReel[20];  
		int C = (yyvsp[0].real);
             sprintf(cstReel,"%d",C);  
               (yyval.EXP).val=strdup(cstReel);  
			   (yyval.EXP).t=strdup(cstReel);}
#line 1448 "syntaxique.tab.c"
    break;

  case 24: /* SIMPLE_INSTRUCTIONS: LEFT_SIDE aff RIGHT_SIDE pnt_vir  */
#line 228 "syntaxique.y"
                                                {
                           if ( routineModifCst((yyvsp[-3].EXP).val) != -1)
                            {  
								if(strcmp((yyvsp[-3].EXP).type,(yyvsp[-1].EXP).type) != 0 )
									{
										printf("\nErreur semantique %d:%d, incompatibilite des types: type %s:%s  type %s:%s \n", line_number, Col,(yyvsp[-3].EXP).val,(yyvsp[-3].EXP).type,(yyvsp[-1].EXP).val,(yyvsp[-1].EXP).type);
										_Exit(0);
									}
									else
									{
										
							            insererVal(sauvidf,(yyvsp[-1].EXP).val,(yyvsp[-1].EXP).type); 
										createQuad("=",(yyvsp[-1].EXP).t,"",(yyvsp[-3].EXP).val);
									}
							}
						}
#line 1469 "syntaxique.tab.c"
    break;

  case 25: /* LEFT_SIDE: idf  */
#line 248 "syntaxique.y"
                                {  
					if(routinIdfDeclar((yyvsp[0].str)) == 0)
					{
					   afficheErreur((yyvsp[0].str) , 5); 
					}
					sauvidf=(yyvsp[0].str);
					char t2[12];
					typeDeIdf(t2,(yyvsp[0].str));
					(yyval.EXP.type)=strdup(t2);
					(yyval.EXP).val=strdup((yyvsp[0].str)) ;
					(yyval.EXP).t=strdup((yyvsp[0].str)) ;
					
					   
				}
#line 1488 "syntaxique.tab.c"
    break;

  case 26: /* LEFT_SIDE: case  */
#line 263 "syntaxique.y"
                            {   
				    (yyval.EXP.type)=strdup((yyvsp[0].EXP).type); 
					(yyval.EXP).val=strdup((yyvsp[0].EXP).val) ; 
					(yyval.EXP).t=strdup((yyvsp[0].EXP).val) ;
					
				}
#line 1499 "syntaxique.tab.c"
    break;

  case 27: /* RIGHT_SIDE: ELEMENT  */
#line 274 "syntaxique.y"
                        {  
				(yyval.EXP.type)=strdup((yyvsp[0].EXP).type); (yyval.EXP).val=strdup((yyvsp[0].EXP).val) ; 
				(yyval.EXP).t = strdup((yyvsp[0].EXP).val);
			}
#line 1508 "syntaxique.tab.c"
    break;

  case 28: /* RIGHT_SIDE: ELEMENT OPER RIGHT_SIDE  */
#line 280 "syntaxique.y"
                        {
			    if(strcmp((yyvsp[-2].EXP).type,(yyvsp[-2].EXP).type) == 0)
				{ 
					(yyval.EXP.type)=strdup((yyvsp[-2].EXP).type); 
				}
				else 
				{
					(yyval.EXP.type)=strdup("FLOAT");
				}
				
				strcpy(opr1,(yyvsp[-2].EXP).val);
				sprintf(temp, "T%d", ntemp); 
				createQuad((yyvsp[-1].str),opr1,(yyvsp[0].EXP).t,temp); 

				double result=operationMath(atoi((yyvsp[-2].EXP).val),(yyvsp[-1].str), atoi((yyvsp[0].EXP).val));
				char result_str[50];
				sprintf(result_str, "%.3f", result);
				(yyval.EXP).val = strdup(result_str);
				(yyval.EXP).t = strdup(temp);
			    ntemp++;
				
			}
#line 1535 "syntaxique.tab.c"
    break;

  case 29: /* RIGHT_SIDE: round_brackets_o ELEMENT round_brackets_f OPER RIGHT_SIDE  */
#line 306 "syntaxique.y"
                        {  
				if(strcmp((yyvsp[-3].EXP).type,(yyvsp[0].EXP).type) == 0)
				{ 
					(yyval.EXP.type)=strdup((yyvsp[-3].EXP).type); 
				}
				else 
				{
					(yyval.EXP.type)=strdup("FLOAT");
				}
				sprintf(temp, "T%d", ntemp); 
				strcpy(opr1,(yyvsp[-3].EXP).val);
				createQuad((yyvsp[-1].str),opr1,(yyvsp[0].EXP).t,temp);
				
				double result=operationMath(atoi((yyvsp[-3].EXP).val),(yyvsp[-1].str), atoi((yyvsp[0].EXP).val));
				char result_str[50];
				sprintf(result_str, "%f", result);
				(yyval.EXP).val = strdup(result_str);
				(yyval.EXP).t = strdup(temp);
			    ntemp++;
				
			}
#line 1561 "syntaxique.tab.c"
    break;

  case 30: /* RIGHT_SIDE: round_brackets_o ELEMENT round_brackets_f  */
#line 331 "syntaxique.y"
                        {  
				(yyval.EXP.type)=strdup((yyvsp[-1].EXP).type); (yyval.EXP).val=strdup((yyvsp[-1].EXP).val) ; (yyval.EXP).t = strdup((yyvsp[-1].EXP).val);	
			}
#line 1569 "syntaxique.tab.c"
    break;

  case 31: /* RIGHT_SIDE: round_brackets_o ELEMENT OPER RIGHT_SIDE round_brackets_f OPER RIGHT_SIDE  */
#line 337 "syntaxique.y"
                        {
				
				if(strcmp((yyvsp[-5].EXP).type,(yyvsp[-3].EXP).type) == 0 && strcmp((yyvsp[-5].EXP).type,(yyvsp[0].EXP).type) == 0)
				{ 
					(yyval.EXP.type)=strdup((yyvsp[-5].EXP).type); 
				}
				else 
				{
					(yyval.EXP.type)=strdup("FLOAT");
				}
				
           			if(strcmp((yyvsp[-5].EXP).type,(yyvsp[-3].EXP).type) == 0)
					{ 
						(yyval.EXP.type)=strdup((yyvsp[-5].EXP).type); 
					}
					else 
					{
						(yyval.EXP.type)=strdup("FLOAT");
					}	
					
					sprintf(temp, "T%d", ntemp); 
					strcpy(opr1,(yyvsp[-5].EXP).val);
					createQuad((yyvsp[-4].str),opr1,(yyvsp[-3].EXP).t,temp);
					ntemp++;

					sprintf(temp2, "T%d", ntemp); 
					strcpy(opr1,(yyvsp[-5].EXP).val);
					createQuad((yyvsp[-1].str),temp,(yyvsp[0].EXP).t,temp2);

					double result=operationMath(atoi((yyvsp[-5].EXP).val),(yyvsp[-1].str), atoi((yyvsp[0].EXP).val));
					char result_str[50];
				    sprintf(result_str, "%f", result);
				    (yyval.EXP).val = strdup(result_str);
				    (yyval.EXP).t = strdup(temp2);
			        ntemp++;
				
										
			}
#line 1612 "syntaxique.tab.c"
    break;

  case 32: /* RIGHT_SIDE: round_brackets_o ELEMENT OPER RIGHT_SIDE round_brackets_f  */
#line 378 "syntaxique.y"
                        {
				    if(strcmp((yyvsp[-3].EXP).type,(yyvsp[-1].EXP).type) == 0)
					{ 
						(yyval.EXP.type)=strdup((yyvsp[-3].EXP).type); 
					}
					else 
					{
						(yyval.EXP.type)=strdup("FLOAT");
					}	
					
					sprintf(temp, "T%d", ntemp); 
					strcpy(opr1,(yyvsp[-3].EXP).val);
					createQuad((yyvsp[-2].str),opr1,(yyvsp[-1].EXP).t,temp);

					double result=operationMath(atoi((yyvsp[-3].EXP).val),(yyvsp[-2].str), atoi((yyvsp[-1].EXP).val));
					char result_str[50];
				    sprintf(result_str, "%f", result);
				    (yyval.EXP).val = strdup(result_str);
				    (yyval.EXP).t = strdup(temp);
			        ntemp++;					
			}
#line 1638 "syntaxique.tab.c"
    break;

  case 33: /* ELEMENT: idf  */
#line 405 "syntaxique.y"
            {  
                if(routinIdfDeclar((yyvsp[0].str)) == 0)
				{
                    afficheErreur((yyvsp[0].str) , 5);
				}
                char t2[12];
                typeDeIdf(t2,(yyvsp[0].str));
                (yyval.EXP.type)=strdup(t2);
				(yyval.EXP).val=strdup((yyvsp[0].str)) ;
				(yyval.EXP).t=strdup((yyvsp[0].str)) ;
			}
#line 1654 "syntaxique.tab.c"
    break;

  case 34: /* ELEMENT: case  */
#line 418 "syntaxique.y"
                       {   (yyval.EXP.type)=strdup((yyvsp[0].EXP).type); (yyval.EXP).val=strdup((yyvsp[0].EXP).val) ;(yyval.EXP).t=strdup((yyvsp[0].EXP).val) ;  }
#line 1660 "syntaxique.tab.c"
    break;

  case 35: /* ELEMENT: VALUE  */
#line 421 "syntaxique.y"
                {   (yyval.EXP.type)=strdup((yyvsp[0].EXP).type); (yyval.EXP).val=strdup((yyvsp[0].EXP).val) ; (yyval.EXP).t=strdup((yyvsp[0].EXP).val) ; }
#line 1666 "syntaxique.tab.c"
    break;

  case 40: /* case: idf square_brackets_o var square_brackets_f  */
#line 432 "syntaxique.y"
        {  
		    if(routinIdfDeclar((yyvsp[-3].str)) == 0) 
			{
                afficheErreur((yyvsp[-3].str) , 5); 
			}
			sauvidf=(yyvsp[-3].str);
           routineDebordementTab((yyvsp[-3].str),valTab); 
            char idft[12];
            typeDeIdf(idft, (yyvsp[-3].str));
            (yyval.EXP.type)=strdup(idft); 
			char Tmp[50]; strcpy(Tmp,(yyvsp[-3].str)); strcat(Tmp,"["); strcat(Tmp,(yyvsp[-1].str)); strcat(Tmp,"]"); 
			(yyval.EXP).val = strdup(Tmp);
			(yyval.EXP).t = strdup(Tmp);

        }
#line 1686 "syntaxique.tab.c"
    break;

  case 41: /* var: idf  */
#line 449 "syntaxique.y"
        { 
		    if(routinIdfDeclar((yyvsp[0].str)) == 0)
			{
                afficheErreur((yyvsp[0].str) , 7);
		    }                                    
            else   
			{ 
			    (yyval.str)=strdup((yyvsp[0].str));
            }
        }
#line 1701 "syntaxique.tab.c"
    break;

  case 42: /* var: entier  */
#line 459 "syntaxique.y"
             { valTab=(yyvsp[0].num) ; char cstNat[15];  sprintf(cstNat,"%d",(yyvsp[0].num)); (yyval.str)=strdup(cstNat); }
#line 1707 "syntaxique.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 466 "syntaxique.y"
                                                {
							qcT=qc;createQuad("BZ","",liste[qc-1].res,"");
						}
#line 1715 "syntaxique.tab.c"
    break;

  case 45: /* $@3: %empty  */
#line 473 "syntaxique.y"
                                                {
						
							if(routinIdfDeclar((yyvsp[-7].str)) == 0)
							{
                                afficheErreur((yyvsp[-7].str) , 5); 
							}
							
							createQuad("=",(yyvsp[-5].str),"",(yyvsp[-7].str));
							qcT=qc;
							sprintf(temp, "T%d", ntemp); 
							createQuadC(3,(yyvsp[-7].str),(yyvsp[-5].str),temp);
							ntemp++;
							
							sprintf(temp2, "T%d", ntemp); 
							createQuadC(4,(yyvsp[-7].str),(yyvsp[-1].str),temp2);
							ntemp++;
							
							sprintf(temp3, "T%d", ntemp);
							createQuadL(3,temp,temp2,temp3);
							ntemp++;
							qct2=qc;
							createQuad("BZ","",temp3,"");
							
						}
#line 1744 "syntaxique.tab.c"
    break;

  case 46: /* COMPLEX_INSTRUCTIONS: mc_for round_brackets_o idf double_pnt INIT_FINISH double_pnt entier double_pnt INIT_FINISH round_brackets_f $@3 curly_brackets_o PARTIE_CODE curly_brackets_f  */
#line 498 "syntaxique.y"
                                                    {
								sprintf(temp, "T%d", ntemp);
								createQuad("+",(yyvsp[-11].str),convert((yyvsp[-7].num)),temp);
								createQuad("=",temp,"",(yyvsp[-11].str));
								ntemp++;
						        createQuad("BR",convert(qcT),"","");
								liste[qct2].op1=convert(qc);
						    }
#line 1757 "syntaxique.tab.c"
    break;

  case 47: /* $@4: %empty  */
#line 509 "syntaxique.y"
                                                {
							qcT=qc;
						}
#line 1765 "syntaxique.tab.c"
    break;

  case 48: /* $@5: %empty  */
#line 513 "syntaxique.y"
                                                {
							qct2=qc;
							createQuad("BZ","",liste[qc-1].res,"");
							
						}
#line 1775 "syntaxique.tab.c"
    break;

  case 49: /* COMPLEX_INSTRUCTIONS: mc_while round_brackets_o $@4 CONDITION round_brackets_f $@5 curly_brackets_o PARTIE_CODE curly_brackets_f  */
#line 519 "syntaxique.y"
                                                {
							createQuad("BR",convert(qcT),"","");
							liste[qct2].op1=convert(qc);
						}
#line 1784 "syntaxique.tab.c"
    break;

  case 56: /* $@6: %empty  */
#line 538 "syntaxique.y"
        {
			liste[qcT].op1=convert(qc+1);
			qcElse=qc;
			createQuad("BR","","","");
		}
#line 1794 "syntaxique.tab.c"
    break;

  case 57: /* ELSE: $@6 mc_else curly_brackets_o PARTIE_CODE curly_brackets_f  */
#line 544 "syntaxique.y"
                {
			liste[qcElse].op1=convert(qc);
		}
#line 1802 "syntaxique.tab.c"
    break;

  case 58: /* ELSE: %empty  */
#line 547 "syntaxique.y"
                  {
			liste[qcT].op1=convert(qc);

		}
#line 1811 "syntaxique.tab.c"
    break;

  case 59: /* CONDITION: RIGHT_SIDE CMP RIGHT_SIDE  */
#line 554 "syntaxique.y"
                        {


				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-1].EXP).val),(yyvsp[-2].EXP).val,(yyvsp[0].EXP).val,temp);
                int res = compare(atoi((yyvsp[-2].EXP).val),(yyvsp[-1].EXP).val,atoi((yyvsp[0].EXP).val));
				const char *res_str = (res == 0) ? "0" : "1"; 
				(yyval.EXP).val = strdup(res_str);
				(yyval.EXP).t = strdup(temp);
				ntemp++;


			}
#line 1829 "syntaxique.tab.c"
    break;

  case 60: /* CONDITION: RIGHT_SIDE CMP RIGHT_SIDE and CONDITION  */
#line 569 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-3].EXP).val),(yyvsp[-4].EXP).val,(yyvsp[-2].EXP).val,temp);
                int res = compare(atoi((yyvsp[-4].EXP).val),(yyvsp[-3].EXP).val,atoi((yyvsp[-2].EXP).val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(3,temp,(yyvsp[0].EXP).val,temp2);

				 if (res == 1 && strcmp((yyvsp[0].EXP).val, "1") == 0) {
					 (yyval.EXP).val = strdup("1");
					 } else {
						 (yyval.EXP).val = strdup("0");
						 }
				(yyval.EXP).t = strdup(temp2);
				ntemp++;
			}
#line 1851 "syntaxique.tab.c"
    break;

  case 61: /* CONDITION: RIGHT_SIDE CMP RIGHT_SIDE or CONDITION  */
#line 589 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-3].EXP).val),(yyvsp[-4].EXP).val,(yyvsp[-2].EXP).val,temp);
                int res = compare(atoi((yyvsp[-4].EXP).val),(yyvsp[-3].EXP).val,atoi((yyvsp[-2].EXP).val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(2,temp,(yyvsp[0].EXP).val,temp2);
				 if (res == 1 || strcmp((yyvsp[0].EXP).val, "1") == 0) {
					 (yyval.EXP).val = strdup("1");
					 } else {
						 (yyval.EXP).val = strdup("0");
						 }
				(yyval.EXP).t = strdup(temp2);
				ntemp++;
			}
#line 1872 "syntaxique.tab.c"
    break;

  case 62: /* CONDITION: round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f  */
#line 608 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-2].EXP).val),(yyvsp[-3].EXP).val,(yyvsp[-1].EXP).val,temp);
				int res = compare(atoi((yyvsp[-3].EXP).val),(yyvsp[-2].EXP).val,atoi((yyvsp[-1].EXP).val));
				const char *res_str = (res == 0) ? "0" : "1"; 
				(yyval.EXP).val = strdup(res_str);
				(yyval.EXP).t = strdup(temp);
				ntemp++;
			}
#line 1886 "syntaxique.tab.c"
    break;

  case 63: /* CONDITION: negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f  */
#line 620 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-2].EXP).val),(yyvsp[-3].EXP).val,(yyvsp[-1].EXP).val,temp);
				ntemp++;
				int res = compare(atoi((yyvsp[-3].EXP).val),(yyvsp[-2].EXP).val,atoi((yyvsp[-1].EXP).val));
				const char *res_str = (res == 0) ? "1" : "0"; 
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(1,temp,"",temp2);
				
				(yyval.EXP).val = strdup(res_str);
				(yyval.EXP).t = strdup(temp2);
				ntemp++;
			}
#line 1905 "syntaxique.tab.c"
    break;

  case 64: /* CONDITION: round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f and CONDITION  */
#line 636 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-4].EXP).val),(yyvsp[-5].EXP).val,(yyvsp[-3].EXP).val,temp);
				int res = compare(atoi((yyvsp[-5].EXP).val),(yyvsp[-4].EXP).val,atoi((yyvsp[-3].EXP).val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(3,temp,(yyvsp[0].EXP).val,temp2);

				 if (res == 1 && strcmp((yyvsp[0].EXP).val, "1") == 0) {
					 (yyval.EXP).val = strdup("1");
					 } else {
						 (yyval.EXP).val = strdup("0");
						 }
				(yyval.EXP).t = strdup(temp2);
				ntemp++;
			}
#line 1927 "syntaxique.tab.c"
    break;

  case 65: /* CONDITION: negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f and CONDITION  */
#line 655 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-4].EXP).val),(yyvsp[-5].EXP).val,(yyvsp[-3].EXP).val,temp);
				int res = compare(atoi((yyvsp[-5].EXP).val),(yyvsp[-4].EXP).val,atoi((yyvsp[-3].EXP).val));
				ntemp++;
			

				sprintf(temp2, "T%d", ntemp);
				createQuadL(1,temp,"",temp2);
				ntemp++;
			
				sprintf(temp3, "T%d", ntemp);
				createQuadL(3,temp,(yyvsp[0].EXP).val,temp3);

				 if (res == 1 || strcmp((yyvsp[0].EXP).val, "1") == 0) {
					 (yyval.EXP).val = strdup("0");
					 } else {
						 (yyval.EXP).val = strdup("1");
						 }	
				(yyval.EXP).t = strdup(temp3);
				ntemp++;
			}
#line 1954 "syntaxique.tab.c"
    break;

  case 66: /* CONDITION: round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f or CONDITION  */
#line 679 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-4].EXP).val),(yyvsp[-5].EXP).val,(yyvsp[-3].EXP).val,temp);
                int res = compare(atoi((yyvsp[-5].EXP).val),(yyvsp[-4].EXP).val,atoi((yyvsp[-3].EXP).val));
				ntemp++;
				
				sprintf(temp2, "T%d", ntemp);
				createQuadL(2,temp,(yyvsp[0].EXP).val,temp2);
				 if (res == 1 || strcmp((yyvsp[0].EXP).val, "1") == 0) {
					 (yyval.EXP).val = strdup("1");
					 } else {
						 (yyval.EXP).val = strdup("0");
						 }
				(yyval.EXP).t = strdup(temp2);
				ntemp++;
			}
#line 1975 "syntaxique.tab.c"
    break;

  case 67: /* CONDITION: negation round_brackets_o RIGHT_SIDE CMP RIGHT_SIDE round_brackets_f or CONDITION  */
#line 697 "syntaxique.y"
                        {
				sprintf(temp, "T%d", ntemp); 
				createQuadC(atoi((yyvsp[-4].EXP).val),(yyvsp[-5].EXP).val,(yyvsp[-3].EXP).val,temp);
                int res = compare(atoi((yyvsp[-5].EXP).val),(yyvsp[-4].EXP).val,atoi((yyvsp[-3].EXP).val));

				ntemp++;
			

				sprintf(temp2, "T%d", ntemp);
				createQuadL(1,temp,"",temp2);
				ntemp++;
			
				sprintf(temp3, "T%d", ntemp);
				createQuadL(2,temp,(yyvsp[0].EXP).val,temp3);

				 if (res == 1 && strcmp((yyvsp[0].EXP).val, "1") == 0) {
					 (yyval.EXP).val = strdup("0");
					 } else {
						 (yyval.EXP).val = strdup("1");
						 }

				(yyval.EXP).t = strdup(temp3);
				ntemp++;
			}
#line 2004 "syntaxique.tab.c"
    break;

  case 68: /* CMP: sup  */
#line 724 "syntaxique.y"
          {(yyval.EXP).val = strdup(">"); (yyval.EXP).t = strdup(">"); }
#line 2010 "syntaxique.tab.c"
    break;

  case 69: /* CMP: inf  */
#line 725 "syntaxique.y"
              {(yyval.EXP).val = strdup("<"); (yyval.EXP).t = strdup("<");}
#line 2016 "syntaxique.tab.c"
    break;

  case 70: /* CMP: sup_eg  */
#line 726 "syntaxique.y"
                 {(yyval.EXP).val = strdup(">="); (yyval.EXP).t = strdup(">=");}
#line 2022 "syntaxique.tab.c"
    break;

  case 71: /* CMP: inf_eg  */
#line 727 "syntaxique.y"
                 {(yyval.EXP).val = strdup("<="); (yyval.EXP).t = strdup("<=");}
#line 2028 "syntaxique.tab.c"
    break;

  case 72: /* CMP: egal  */
#line 728 "syntaxique.y"
               {(yyval.EXP).val = strdup("=="); (yyval.EXP).t = strdup("==");}
#line 2034 "syntaxique.tab.c"
    break;

  case 73: /* CMP: not_egal  */
#line 729 "syntaxique.y"
                   {(yyval.EXP).val = strdup("!="); (yyval.EXP).t = strdup("!=");}
#line 2040 "syntaxique.tab.c"
    break;

  case 74: /* INIT_FINISH: entier  */
#line 732 "syntaxique.y"
                     {char cstNat[15];  sprintf(cstNat,"%d",(yyvsp[0].num)); (yyval.str)=strdup(cstNat);}
#line 2046 "syntaxique.tab.c"
    break;

  case 75: /* INIT_FINISH: idf  */
#line 733 "syntaxique.y"
                        { 
					if(routinIdfDeclar((yyvsp[0].str)) == 0)
					{
						afficheErreur((yyvsp[0].str) , 5); 
					}
					
				}
#line 2058 "syntaxique.tab.c"
    break;


#line 2062 "syntaxique.tab.c"

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

#line 745 "syntaxique.y"



int yyerror(char *msg){ printf("Line %d ,Col %d : Erreur Syntaxique  \n",line_number, Col);exit(0); }

void afficheErreur(char* d , int a)
    {   
		switch(a)
		{    
		    case 1 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : Double declaration de la variable %s \n", line_number, Col, d);
			break;
			case 2 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : incompatibilité des types %s \n", line_number, Col, d);
			break;
		    case 3 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : la taille du tableau %s est négative ! \n", line_number, Col, d);
			break;
			case 4 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Utilisation d'une Variable %s non initialisé  \n", line_number, Col, d);
				// still did'nt do this one
			break;
			case 5 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Variable Non déclarée %s \n", line_number, Col, d);
			break;
			case 6 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Variable %s non déclarée  \n", line_number, Col, d);
			break;
			case 7 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i :  Indice du tableau non déclarée %s \n", line_number, Col, d);
			break;
			case 8 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : Modification d'une constante: %s \n", line_number, Col, d);
			break;
			case 9 :
				printf(" \n Erreur Semantique a la ligne %i, colonne %i : Dépassement de capacité %s \n", line_number, Col, d);
			break;
			
		}
		exit(0);
    }



int main () 
{ 

initialisationMC();
yyparse();
afficherMS();
afficher();
afficherDecl();

// quadruplets avant optimisation
afficher_qdr();

 /* optimisation();
// quadruplets après l'optimisation
afficher_qdr();
createAssembler(qc,liste);   */
return 0;
}
int yywrap()
{return 0;}
