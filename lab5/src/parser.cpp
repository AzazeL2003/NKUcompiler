/* A Bison parser, made by GNU Bison 3.8.  */

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
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/parser.y"

    #include <iostream>
    #include <assert.h>
    #include <functional>
    #include "parser.h"
    #include <cstring>
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
    Type* vtype = nullptr;
    std::string name{};
    bool issysinit = false;
    int isCalculable (ExprNode* node1,ExprNode* node2=nullptr)
    {  
        if(node1->hasInt())
        {
            if(node2==nullptr)
            {
                return 1;
            }
            else if(node2->hasInt())
            {
                return 1;
            }
            else if(node2->hasFloat())
            {
                return 2;
            }
            return 0;
        }
        if(node1->hasFloat())
        {
            if(node2==nullptr)
            {
                return 2;
            }
            else if(node2->hasInt())
            {
                return 3;
            }
            else if(node2->hasFloat())
            {
                return 4;
            }
            return 0;
        }
        return 0;
    }

#line 118 "src/parser.cpp"




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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_FLT = 4,                        /* FLT  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_OCTAL = 6,                      /* OCTAL  */
  YYSYMBOL_HEX = 7,                        /* HEX  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_LPAREN = 17,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 18,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 19,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 20,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_LBRACKET = 23,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 24,                  /* RBRACKET  */
  YYSYMBOL_ADD = 25,                       /* ADD  */
  YYSYMBOL_SUB = 26,                       /* SUB  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_MOD = 29,                       /* MOD  */
  YYSYMBOL_LESS = 30,                      /* LESS  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_GREATER = 32,                   /* GREATER  */
  YYSYMBOL_NGREATER = 33,                  /* NGREATER  */
  YYSYMBOL_NLESS = 34,                     /* NLESS  */
  YYSYMBOL_NEQUAL = 35,                    /* NEQUAL  */
  YYSYMBOL_EQUAL = 36,                     /* EQUAL  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_LOR = 38,                       /* LOR  */
  YYSYMBOL_LAND = 39,                      /* LAND  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_THEN = 41,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_Stmts = 44,                     /* Stmts  */
  YYSYMBOL_Stmt = 45,                      /* Stmt  */
  YYSYMBOL_PlainStmt = 46,                 /* PlainStmt  */
  YYSYMBOL_LVal = 47,                      /* LVal  */
  YYSYMBOL_ContinueStmt = 48,              /* ContinueStmt  */
  YYSYMBOL_BreakStmt = 49,                 /* BreakStmt  */
  YYSYMBOL_AssignStmt = 50,                /* AssignStmt  */
  YYSYMBOL_BlockStmt = 51,                 /* BlockStmt  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_IfStmt = 53,                    /* IfStmt  */
  YYSYMBOL_ReturnStmt = 54,                /* ReturnStmt  */
  YYSYMBOL_Cond = 55,                      /* Cond  */
  YYSYMBOL_PrimaryExp = 56,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 57,                  /* UnaryExp  */
  YYSYMBOL_MulExp = 58,                    /* MulExp  */
  YYSYMBOL_AddExp = 59,                    /* AddExp  */
  YYSYMBOL_RelExp = 60,                    /* RelExp  */
  YYSYMBOL_EqExp = 61,                     /* EqExp  */
  YYSYMBOL_LAndExp = 62,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 63,                    /* LOrExp  */
  YYSYMBOL_BType = 64,                     /* BType  */
  YYSYMBOL_ConstDeclStmt = 65,             /* ConstDeclStmt  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_ConstVarIds = 67,               /* ConstVarIds  */
  YYSYMBOL_ConstVarId = 68,                /* ConstVarId  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_ConstInitVal = 70,              /* ConstInitVal  */
  YYSYMBOL_ConstInitVals = 71,             /* ConstInitVals  */
  YYSYMBOL_CallParams = 72,                /* CallParams  */
  YYSYMBOL_DeclStmt = 73,                  /* DeclStmt  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_TempDecl = 76,                  /* TempDecl  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_VarIds = 78,                    /* VarIds  */
  YYSYMBOL_FuncParams = 79,                /* FuncParams  */
  YYSYMBOL_FuncParam = 80,                 /* FuncParam  */
  YYSYMBOL_FArrayList = 81,                /* FArrayList  */
  YYSYMBOL_FArrayNode = 82,                /* FArrayNode  */
  YYSYMBOL_VarId = 83,                     /* VarId  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_TempVarId = 85,                 /* TempVarId  */
  YYSYMBOL_ArrayList = 86,                 /* ArrayList  */
  YYSYMBOL_ArrayNode = 87,                 /* ArrayNode  */
  YYSYMBOL_Exp = 88,                       /* Exp  */
  YYSYMBOL_ConstExp = 89,                  /* ConstExp  */
  YYSYMBOL_InitVal = 90,                   /* InitVal  */
  YYSYMBOL_InitVals = 91,                  /* InitVals  */
  YYSYMBOL_WhileStmt = 92                  /* WhileStmt  */
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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   114,   115,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   133,   134,   137,   199,   204,
     210,   216,   215,   224,   230,   233,   239,   242,   248,   252,
     255,   258,   264,   270,   276,   285,   288,   311,   334,   350,
     366,   373,   375,   393,   411,   424,   426,   444,   464,   466,
     472,   478,   484,   492,   494,   500,   508,   510,   518,   520,
     527,   530,   536,   536,   544,   547,   553,   553,   736,   739,
     742,   747,   751,   758,   761,   768,   768,   774,   774,   783,
     787,   786,   814,   817,   825,   828,   831,   837,   843,   864,
     867,   873,   878,   878,   891,   906,   923,   926,   932,   938,
     959,   965,   968,   971,   976,   980,   986
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "FLT", "INTEGER",
  "OCTAL", "HEX", "IF", "ELSE", "WHILE", "CONTINUE", "BREAK", "INT",
  "VOID", "CONST", "FLOAT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "LBRACKET", "RBRACKET", "ADD", "SUB", "MUL", "DIV",
  "MOD", "LESS", "ASSIGN", "GREATER", "NGREATER", "NLESS", "NEQUAL",
  "EQUAL", "NOT", "LOR", "LAND", "RETURN", "THEN", "$accept", "Program",
  "Stmts", "Stmt", "PlainStmt", "LVal", "ContinueStmt", "BreakStmt",
  "AssignStmt", "BlockStmt", "$@1", "IfStmt", "ReturnStmt", "Cond",
  "PrimaryExp", "UnaryExp", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "BType", "ConstDeclStmt", "$@2", "ConstVarIds",
  "ConstVarId", "$@3", "ConstInitVal", "ConstInitVals", "CallParams",
  "DeclStmt", "$@4", "$@5", "TempDecl", "$@6", "VarIds", "FuncParams",
  "FuncParam", "FArrayList", "FArrayNode", "VarId", "$@7", "TempVarId",
  "ArrayList", "ArrayNode", "Exp", "ConstExp", "InitVal", "InitVals",
  "WhileStmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-156)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     183,    -1,  -156,  -156,  -156,  -156,    27,    34,    35,    54,
    -156,  -156,    29,  -156,   236,    61,  -156,   236,   236,   236,
      73,   101,   183,  -156,  -156,    60,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,    57,     9,  -156,  -156,  -156,    87,
    -156,   100,    89,   236,   236,  -156,  -156,   116,  -156,  -156,
     103,  -156,   183,  -156,  -156,  -156,  -156,   102,  -156,  -156,
     236,   236,   236,   236,   236,   236,   116,  -156,  -156,    -4,
    -156,   236,  -156,   109,     9,    63,    13,    92,    94,   115,
     117,  -156,     0,  -156,   132,  -156,   145,  -156,   120,  -156,
    -156,  -156,    57,    57,  -156,  -156,   236,   118,   183,   236,
     236,   236,   236,   236,   236,   236,   236,   183,   126,  -156,
    -156,   141,  -156,    47,  -156,  -156,  -156,  -156,  -156,   136,
       9,     9,     9,     9,    63,    63,    13,    92,  -156,    29,
    -156,    10,  -156,  -156,  -156,  -156,   132,   183,   143,    -3,
    -156,   236,   207,  -156,    24,  -156,  -156,   124,   144,    29,
       9,   148,     6,  -156,  -156,   212,   149,  -156,  -156,  -156,
    -156,  -156,    67,    33,  -156,  -156,  -156,  -156,   207,  -156,
    -156,    91,    89,  -156,  -156,   212,  -156
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    89,    34,    31,    32,    33,     0,     0,     0,     0,
      60,    77,     0,    61,     0,    21,    15,     0,     0,     0,
       0,     0,     2,     3,    14,    30,    13,    12,     5,     6,
       7,     9,    35,    41,    45,    99,    75,    11,    10,     0,
       8,     0,    17,     0,     0,    18,    19,     0,    62,    30,
       0,    23,     0,    38,    39,    40,    27,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     0,    16,    36,     0,
      73,     0,    90,     0,    48,    53,    56,    58,    28,     0,
      92,    78,     0,    82,     0,    29,     0,    26,     0,    42,
      43,    44,    46,    47,    76,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      79,     0,    66,     0,    64,    22,    20,    74,    91,    24,
      49,    50,    51,    52,    55,    54,    57,    59,   106,    84,
      93,    94,    92,    83,    96,    63,     0,     0,     0,     0,
      85,     0,     0,    97,     0,    65,    25,    87,     0,     0,
     100,     0,     0,   101,    95,     0,     0,    81,    86,    98,
     103,   104,     0,     0,    67,    68,    89,   102,     0,    70,
      71,     0,    88,   105,    69,     0,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,   122,   -15,  -156,     2,  -156,  -156,  -156,    19,
    -156,  -156,  -156,   125,  -156,    11,    50,   -39,    26,    70,
      62,  -156,    -9,  -156,  -156,  -156,    40,  -156,  -155,  -156,
    -156,  -156,  -156,  -156,   111,  -156,  -156,  -156,    30,    12,
    -156,    69,  -156,  -156,    49,  -156,   -14,    43,  -151,  -156,
    -156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    21,    22,    23,    24,    49,    26,    27,    28,    29,
      52,    30,    31,    73,    32,    33,    34,    35,    75,    76,
      77,    78,    36,    37,    84,   113,   114,   134,   164,   171,
      69,    38,    66,    47,    81,   108,    82,   139,   140,    42,
      72,    83,   109,   130,   131,   143,    39,   165,   154,   162,
      40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   161,    25,    48,    74,    74,    57,    59,   170,     1,
       2,     3,     4,     5,    95,   148,    41,   173,    96,   149,
     176,   110,   111,    14,    25,   152,   160,    70,    53,    54,
      55,    17,    18,   141,    64,    65,     1,     2,     3,     4,
       5,   142,    10,    19,    43,    13,    88,   141,   103,   104,
      14,    44,   163,   169,    25,   155,    45,    97,    17,    18,
     120,   121,   122,   123,    74,    74,    74,    74,   135,   136,
      19,    59,    89,    90,    91,    46,     1,     2,     3,     4,
       5,    51,   117,   119,    61,    62,    63,   167,    25,   168,
      14,    60,   128,    99,    56,   100,   101,   102,    17,    18,
      25,    58,   150,     1,     2,     3,     4,     5,    67,    25,
      19,   174,    71,   175,    92,    93,   150,    14,    68,    80,
     138,    85,   146,    87,   150,    17,    18,    98,   153,   124,
     125,   105,   106,   107,   -80,   112,   150,    19,   153,    25,
     138,   116,   118,   129,   132,   137,   147,   156,     1,     2,
       3,     4,     5,     6,   153,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    15,   115,    16,   157,   127,    79,
      17,    18,   159,   166,    86,   126,   145,    94,   172,   158,
     133,     0,    19,   144,   151,    20,     1,     2,     3,     4,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     0,    15,     0,    16,     0,     0,     0,    17,    18,
       1,     2,     3,     4,     5,     1,     2,     3,     4,     5,
      19,     0,     0,    20,    14,     0,   152,     0,     0,    14,
       0,   163,    17,    18,     0,     0,     0,    17,    18,     1,
       2,     3,     4,     5,    19,     0,     0,     0,     0,    19,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
      14,   152,     0,    12,    43,    44,    20,    22,   163,     3,
       4,     5,     6,     7,    18,    18,    17,   168,    22,    22,
     175,    21,    22,    17,    22,    19,    20,    41,    17,    18,
      19,    25,    26,    23,    25,    26,     3,     4,     5,     6,
       7,    31,    13,    37,    17,    16,    60,    23,    35,    36,
      17,    17,    19,    20,    52,    31,    21,    71,    25,    26,
      99,   100,   101,   102,   103,   104,   105,   106,    21,    22,
      37,    86,    61,    62,    63,    21,     3,     4,     5,     6,
       7,    20,    96,    98,    27,    28,    29,    20,    86,    22,
      17,    31,   107,    30,    21,    32,    33,    34,    25,    26,
      98,     0,   141,     3,     4,     5,     6,     7,    21,   107,
      37,    20,    23,    22,    64,    65,   155,    17,    18,     3,
     129,    18,   137,    21,   163,    25,    26,    18,   142,   103,
     104,    39,    38,    18,    17,     3,   175,    37,   152,   137,
     149,    21,    24,    17,     3,     9,     3,    23,     3,     4,
       5,     6,     7,     8,   168,    10,    11,    12,    13,    14,
      15,    16,    17,    19,    19,    20,    21,   148,   106,    44,
      25,    26,    24,    24,    52,   105,   136,    66,   166,   149,
     111,    -1,    37,   134,   141,    40,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    -1,    21,    -1,    -1,    -1,    25,    26,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      37,    -1,    -1,    40,    17,    -1,    19,    -1,    -1,    17,
      -1,    19,    25,    26,    -1,    -1,    -1,    25,    26,     3,
       4,     5,     6,     7,    37,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    19,    21,    25,    26,    37,
      40,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      53,    54,    56,    57,    58,    59,    64,    65,    73,    88,
      92,    17,    81,    17,    17,    21,    21,    75,    64,    47,
      88,    20,    52,    57,    57,    57,    21,    88,     0,    45,
      31,    27,    28,    29,    25,    26,    74,    21,    18,    72,
      88,    23,    82,    55,    59,    60,    61,    62,    63,    55,
       3,    76,    78,    83,    66,    18,    44,    21,    88,    57,
      57,    57,    58,    58,    76,    18,    22,    88,    18,    30,
      32,    33,    34,    35,    36,    39,    38,    18,    77,    84,
      21,    22,     3,    67,    68,    20,    21,    88,    24,    45,
      59,    59,    59,    59,    60,    60,    61,    62,    45,    17,
      85,    86,     3,    83,    69,    21,    22,     9,    64,    79,
      80,    23,    31,    87,    86,    68,    45,     3,    18,    22,
      59,    89,    19,    88,    90,    31,    23,    51,    80,    24,
      20,    90,    91,    19,    70,    89,    24,    20,    22,    20,
      70,    71,    81,    90,    20,    22,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    47,    48,    49,
      50,    52,    51,    51,    53,    53,    54,    54,    55,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    66,    65,    67,    67,    69,    68,    70,    70,
      70,    71,    71,    72,    72,    74,    73,    75,    73,    76,
      77,    76,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    82,    84,    83,    85,    85,    86,    86,    87,    88,
      89,    90,    90,    90,    91,    91,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       4,     0,     4,     2,     5,     7,     3,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     4,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     0,     5,     1,     3,     0,     5,     1,     3,
       2,     1,     3,     1,     3,     0,     3,     0,     3,     2,
       0,     6,     1,     3,     0,     1,     3,     2,     5,     0,
       2,     3,     0,     3,     1,     3,     0,     2,     3,     1,
       1,     1,     3,     2,     1,     3,     5
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
  case 2: /* Program: Stmts  */
#line 109 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].seqtype));
    }
#line 1350 "src/parser.cpp"
    break;

  case 3: /* Stmts: Stmt  */
#line 114 "src/parser.y"
           {(yyval.seqtype) = new SeqNode((yyvsp[0].stmttype));}
#line 1356 "src/parser.cpp"
    break;

  case 4: /* Stmts: Stmts Stmt  */
#line 115 "src/parser.y"
                {
        (yyvsp[-1].seqtype)->emplace_back((yyvsp[0].stmttype));
        (yyval.seqtype) = (yyvsp[-1].seqtype);
    }
#line 1365 "src/parser.cpp"
    break;

  case 5: /* Stmt: AssignStmt  */
#line 121 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1371 "src/parser.cpp"
    break;

  case 6: /* Stmt: BlockStmt  */
#line 122 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1377 "src/parser.cpp"
    break;

  case 7: /* Stmt: IfStmt  */
#line 123 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1383 "src/parser.cpp"
    break;

  case 8: /* Stmt: WhileStmt  */
#line 124 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1389 "src/parser.cpp"
    break;

  case 9: /* Stmt: ReturnStmt  */
#line 125 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1395 "src/parser.cpp"
    break;

  case 10: /* Stmt: DeclStmt  */
#line 126 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].tdectype);}
#line 1401 "src/parser.cpp"
    break;

  case 11: /* Stmt: ConstDeclStmt  */
#line 127 "src/parser.y"
                    {(yyval.stmttype)=(yyvsp[0].dectype);}
#line 1407 "src/parser.cpp"
    break;

  case 12: /* Stmt: BreakStmt  */
#line 128 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1413 "src/parser.cpp"
    break;

  case 13: /* Stmt: ContinueStmt  */
#line 129 "src/parser.y"
                   {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1419 "src/parser.cpp"
    break;

  case 14: /* Stmt: PlainStmt  */
#line 130 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1425 "src/parser.cpp"
    break;

  case 15: /* PlainStmt: SEMICOLON  */
#line 133 "src/parser.y"
                {(yyval.stmttype) = new PlainStmt();}
#line 1431 "src/parser.cpp"
    break;

  case 16: /* PlainStmt: Exp SEMICOLON  */
#line 134 "src/parser.y"
                    {(yyval.stmttype) = new PlainStmt((yyvsp[-1].exprtype));}
#line 1437 "src/parser.cpp"
    break;

  case 17: /* LVal: ID FArrayList  */
#line 137 "src/parser.y"
                    {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-1].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[-1].strtype));
            delete [](char*)(yyvsp[-1].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new Id(se,(yyvsp[0].faltype));
        if((yyvsp[0].faltype)==nullptr||(yyvsp[0].faltype)->empty())
        {
            if(dynamic_cast<IdentifierSymbolEntry*>(se)->hasValue())
            {
                if(dynamic_cast<IdentifierSymbolEntry*>(se)->hasInt())
                {
                    (yyval.exprtype)->changeInt(std::make_optional<int>(dynamic_cast<IdentifierSymbolEntry*>(se)->getInt()));
                }
                else
                {
                    (yyval.exprtype)->changeFloat(std::make_optional<float>(dynamic_cast<IdentifierSymbolEntry*>(se)->getFloat()));
                }
            }
        }
        else
        {
            if(dynamic_cast<IdentifierSymbolEntry*>(se)->hasArray())
            {
                std::vector<int> d{};
                bool doable = true;
                for(auto& node : (yyvsp[0].faltype)->getVector())
                {
                    if(node->getExprNode()->hasInt())
                        d.emplace_back(node->getExprNode()->getIntop().value());
                    else
                    {
                        doable = false;
                        break;
                    }
                }
                if(doable)
                {
                    if(dynamic_cast<IdentifierSymbolEntry*>(se)->hasIntArray())
                    {
                        (yyval.exprtype)->changeInt(std::make_optional<int>(dynamic_cast<IdentifierSymbolEntry*>(se)->getInt(d)));
                    }
                    else
                    {
                        (yyval.exprtype)->changeFloat(std::make_optional<float>(dynamic_cast<IdentifierSymbolEntry*>(se)->getFloat(d)));
                    }
                }
            }
        }
        delete [](yyvsp[-1].strtype);
    }
#line 1502 "src/parser.cpp"
    break;

  case 18: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 199 "src/parser.y"
                        {
        (yyval.stmttype) = new ContinueStmt();
    }
#line 1510 "src/parser.cpp"
    break;

  case 19: /* BreakStmt: BREAK SEMICOLON  */
#line 204 "src/parser.y"
                     {
        (yyval.stmttype) = new BreakStmt();
    }
#line 1518 "src/parser.cpp"
    break;

  case 20: /* AssignStmt: LVal ASSIGN Exp SEMICOLON  */
#line 210 "src/parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 1526 "src/parser.cpp"
    break;

  case 21: /* $@1: %empty  */
#line 216 "src/parser.y"
        {identifiers = new SymbolTable(identifiers);}
#line 1532 "src/parser.cpp"
    break;

  case 22: /* BlockStmt: LBRACE $@1 Stmts RBRACE  */
#line 218 "src/parser.y"
        {
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].seqtype));
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 1543 "src/parser.cpp"
    break;

  case 23: /* BlockStmt: LBRACE RBRACE  */
#line 225 "src/parser.y"
        {
            (yyval.stmttype) = new CompoundStmt(nullptr);
        }
#line 1551 "src/parser.cpp"
    break;

  case 24: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 230 "src/parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1559 "src/parser.cpp"
    break;

  case 25: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 233 "src/parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1567 "src/parser.cpp"
    break;

  case 26: /* ReturnStmt: RETURN Exp SEMICOLON  */
#line 239 "src/parser.y"
                        {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 1575 "src/parser.cpp"
    break;

  case 27: /* ReturnStmt: RETURN SEMICOLON  */
#line 242 "src/parser.y"
                      {
        (yyval.stmttype) = new ReturnStmt(nullptr);
    }
#line 1583 "src/parser.cpp"
    break;

  case 28: /* Cond: LOrExp  */
#line 248 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1589 "src/parser.cpp"
    break;

  case 29: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 252 "src/parser.y"
                      {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1597 "src/parser.cpp"
    break;

  case 30: /* PrimaryExp: LVal  */
#line 255 "src/parser.y"
           {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1605 "src/parser.cpp"
    break;

  case 31: /* PrimaryExp: INTEGER  */
#line 258 "src/parser.y"
              {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new IntSymbolEntry(TypeSystem::intType,std::stol(temp, 0, 10));
        (yyval.exprtype) = new Constant(se);
        (yyval.exprtype)->changeInt(std::make_optional<int>(std::stol(temp, 0, 10)));
    }
#line 1616 "src/parser.cpp"
    break;

  case 32: /* PrimaryExp: OCTAL  */
#line 264 "src/parser.y"
            {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new IntSymbolEntry(TypeSystem::intType,std::stol(temp, 0, 8));
        (yyval.exprtype) = new Constant(se);
        (yyval.exprtype)->changeInt(std::make_optional<int>(std::stol(temp, 0, 8)));
    }
#line 1627 "src/parser.cpp"
    break;

  case 33: /* PrimaryExp: HEX  */
#line 270 "src/parser.y"
          {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new IntSymbolEntry(TypeSystem::intType,std::stol(temp.substr(2), 0, 16));
        (yyval.exprtype) = new Constant(se);
        (yyval.exprtype)->changeInt(std::make_optional<int>(std::stol(temp, 0, 16)));
    }
#line 1638 "src/parser.cpp"
    break;

  case 34: /* PrimaryExp: FLT  */
#line 276 "src/parser.y"
          {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new FloatSymbolEntry(TypeSystem::floatType,std::stod(temp));
        (yyval.exprtype) = new Constant(se);
        (yyval.exprtype)->changeFloat(std::make_optional<float>(std::stof(temp)));
    }
#line 1649 "src/parser.cpp"
    break;

  case 35: /* UnaryExp: PrimaryExp  */
#line 285 "src/parser.y"
               {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1657 "src/parser.cpp"
    break;

  case 36: /* UnaryExp: ID LPAREN RPAREN  */
#line 288 "src/parser.y"
                       {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        if(issysruntime((yyvsp[-2].strtype)))
        {
            char additionalChar = '_';
            size_t originalLen = strlen((yyvsp[-2].strtype));
            char* newStr = new char[originalLen + 2];
            newStr[0] = additionalChar;
            strcpy(newStr + 1, (yyvsp[-2].strtype));
            newStr[originalLen + 1] = '\0';
            delete[] (yyvsp[-2].strtype);
            (yyvsp[-2].strtype) = newStr;
        }
        auto tse = identifiers->lookup((yyvsp[-2].strtype));
        assert(tse != nullptr);
        SymbolEntry *se = new TemporarySymbolEntry(dynamic_cast<FunctionType*>(tse->getType())->getRetType(), SymbolTable::getLabel());//todo
        (yyval.exprtype) = new UnaryExpr(se,tse,nullptr);
        delete[] (yyvsp[-2].strtype);
    }
#line 1685 "src/parser.cpp"
    break;

  case 37: /* UnaryExp: ID LPAREN CallParams RPAREN  */
#line 311 "src/parser.y"
                                  {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        if(issysruntime((yyvsp[-3].strtype)))
        {
            char additionalChar = '_';
            size_t originalLen = strlen((yyvsp[-3].strtype));
            char* newStr = new char[originalLen + 2];
            newStr[0] = additionalChar;
            strcpy(newStr + 1, (yyvsp[-3].strtype));
            newStr[originalLen + 1] = '\0';
            delete[] (yyvsp[-3].strtype);
            (yyvsp[-3].strtype) = newStr;
        }
        auto tse = identifiers->lookup((yyvsp[-3].strtype));
        assert(tse != nullptr);
        SymbolEntry *se = new TemporarySymbolEntry(dynamic_cast<FunctionType*>(tse->getType())->getRetType(), SymbolTable::getLabel());//todo
        (yyval.exprtype) = new UnaryExpr(se,tse,(yyvsp[-1].cptype));
        delete[] (yyvsp[-3].strtype);
    }
#line 1713 "src/parser.cpp"
    break;

  case 38: /* UnaryExp: ADD UnaryExp  */
#line 334 "src/parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::ADD, (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[0].exprtype));
        if(cond)
        {
            if(cond==1)
            {
                (yyval.exprtype)->changeInt(std::make_optional<int>((yyvsp[0].exprtype)->getIntop().value()));
            }
            else
            {
                (yyval.exprtype)->changeFloat(std::make_optional<float>((yyvsp[0].exprtype)->getFloat()));
            }
        }
    }
#line 1734 "src/parser.cpp"
    break;

  case 39: /* UnaryExp: SUB UnaryExp  */
#line 350 "src/parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::SUB, (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[0].exprtype));
        if(cond)
        {
            if(cond==1)
            {
                (yyval.exprtype)->changeInt(std::make_optional<int>(-(yyvsp[0].exprtype)->getIntop().value()));
            }
            else
            {
                (yyval.exprtype)->changeFloat(std::make_optional<float>(-(yyvsp[0].exprtype)->getFloat()));
            }
        }
    }
#line 1755 "src/parser.cpp"
    break;

  case 40: /* UnaryExp: NOT UnaryExp  */
#line 366 "src/parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::NOT, (yyvsp[0].exprtype));
    }
#line 1764 "src/parser.cpp"
    break;

  case 41: /* MulExp: UnaryExp  */
#line 373 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1770 "src/parser.cpp"
    break;

  case 42: /* MulExp: MulExp MUL UnaryExp  */
#line 376 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[-2].exprtype),(yyvsp[0].exprtype));
        if(cond)
        {
            if(cond==1)
            {
                (yyval.exprtype)->changeInt(std::make_optional<int>((yyvsp[-2].exprtype)->getIntop().value()*(yyvsp[0].exprtype)->getIntop().value()));
            }
            else
            {
                (yyval.exprtype)->changeFloat(std::make_optional<float>((yyvsp[-2].exprtype)->getFloat()*(yyvsp[0].exprtype)->getFloat()));
            }
        }
    }
#line 1791 "src/parser.cpp"
    break;

  case 43: /* MulExp: MulExp DIV UnaryExp  */
#line 394 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[-2].exprtype),(yyvsp[0].exprtype));
        if(cond)
        {
            if(cond==1)
            {
                (yyval.exprtype)->changeInt(std::make_optional<int>((yyvsp[-2].exprtype)->getIntop().value()/(yyvsp[0].exprtype)->getIntop().value()));
            }
            else
            {
                (yyval.exprtype)->changeFloat(std::make_optional<float>((yyvsp[-2].exprtype)->getFloat()/(yyvsp[0].exprtype)->getFloat()));
            }
        }
    }
#line 1812 "src/parser.cpp"
    break;

  case 44: /* MulExp: MulExp MOD UnaryExp  */
#line 412 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[-2].exprtype),(yyvsp[0].exprtype));
        if(cond==1)
        {
            (yyval.exprtype)->changeInt(std::make_optional<int>((yyvsp[-2].exprtype)->getIntop().value()%(yyvsp[0].exprtype)->getIntop().value()));
        }
    }
#line 1826 "src/parser.cpp"
    break;

  case 45: /* AddExp: MulExp  */
#line 424 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1832 "src/parser.cpp"
    break;

  case 46: /* AddExp: AddExp ADD MulExp  */
#line 427 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[-2].exprtype),(yyvsp[0].exprtype));
        if(cond)
        {
            if(cond==1)
            {
                (yyval.exprtype)->changeInt(std::make_optional<int>((yyvsp[-2].exprtype)->getIntop().value()+(yyvsp[0].exprtype)->getIntop().value()));
            }
            else
            {
                (yyval.exprtype)->changeFloat(std::make_optional<float>((yyvsp[-2].exprtype)->getFloat()+(yyvsp[0].exprtype)->getFloat()));
            }
        }
    }
#line 1853 "src/parser.cpp"
    break;

  case 47: /* AddExp: AddExp SUB MulExp  */
#line 445 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());//todo
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        int cond = isCalculable((yyvsp[-2].exprtype),(yyvsp[0].exprtype));
        if(cond)
        {
            if(cond==1)
            {
                (yyval.exprtype)->changeInt(std::make_optional<int>((yyvsp[-2].exprtype)->getIntop().value()-(yyvsp[0].exprtype)->getIntop().value()));
            }
            else
            {
                (yyval.exprtype)->changeFloat(std::make_optional<float>((yyvsp[-2].exprtype)->getFloat()-(yyvsp[0].exprtype)->getFloat()));
            }
        }
    }
#line 1874 "src/parser.cpp"
    break;

  case 48: /* RelExp: AddExp  */
#line 464 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1880 "src/parser.cpp"
    break;

  case 49: /* RelExp: RelExp LESS AddExp  */
#line 467 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1889 "src/parser.cpp"
    break;

  case 50: /* RelExp: RelExp GREATER AddExp  */
#line 473 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1898 "src/parser.cpp"
    break;

  case 51: /* RelExp: RelExp NGREATER AddExp  */
#line 479 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NGREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1907 "src/parser.cpp"
    break;

  case 52: /* RelExp: RelExp NLESS AddExp  */
#line 485 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NLESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1916 "src/parser.cpp"
    break;

  case 53: /* EqExp: RelExp  */
#line 492 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1922 "src/parser.cpp"
    break;

  case 54: /* EqExp: EqExp EQUAL RelExp  */
#line 495 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1931 "src/parser.cpp"
    break;

  case 55: /* EqExp: EqExp NEQUAL RelExp  */
#line 501 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NEQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1940 "src/parser.cpp"
    break;

  case 56: /* LAndExp: EqExp  */
#line 508 "src/parser.y"
          {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1946 "src/parser.cpp"
    break;

  case 57: /* LAndExp: LAndExp LAND EqExp  */
#line 511 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1955 "src/parser.cpp"
    break;

  case 58: /* LOrExp: LAndExp  */
#line 518 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1961 "src/parser.cpp"
    break;

  case 59: /* LOrExp: LOrExp LOR LAndExp  */
#line 521 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1970 "src/parser.cpp"
    break;

  case 60: /* BType: INT  */
#line 527 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 1978 "src/parser.cpp"
    break;

  case 61: /* BType: FLOAT  */
#line 530 "src/parser.y"
            {
        (yyval.type) = TypeSystem::floatType;
    }
#line 1986 "src/parser.cpp"
    break;

  case 62: /* $@2: %empty  */
#line 536 "src/parser.y"
                {
        vtype = (yyvsp[0].type);
    }
#line 1994 "src/parser.cpp"
    break;

  case 63: /* ConstDeclStmt: CONST BType $@2 ConstVarIds SEMICOLON  */
#line 539 "src/parser.y"
                         {
        (yyval.dectype) = new DeclStmt((yyvsp[-1].vistype));
    }
#line 2002 "src/parser.cpp"
    break;

  case 64: /* ConstVarIds: ConstVarId  */
#line 544 "src/parser.y"
              {
        (yyval.vistype) = new VarIds((yyvsp[0].vitype));
    }
#line 2010 "src/parser.cpp"
    break;

  case 65: /* ConstVarIds: ConstVarIds COMMA ConstVarId  */
#line 547 "src/parser.y"
                                  {
        (yyvsp[-2].vistype)->push_back((yyvsp[0].vitype));
        (yyval.vistype) = (yyvsp[-2].vistype);
    }
#line 2019 "src/parser.cpp"
    break;

  case 66: /* $@3: %empty  */
#line 553 "src/parser.y"
        {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(vtype, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
    }
#line 2029 "src/parser.cpp"
    break;

  case 67: /* ConstVarId: ID $@3 ArrayList ASSIGN ConstInitVal  */
#line 559 "src/parser.y"
    {
        auto se = identifiers->lookup((yyvsp[-4].strtype));
        assert(se!=nullptr);
        if(!((yyvsp[-2].altype)->getVector().empty()))
        {
            std::vector<int> d{};
            for(auto& node : (yyvsp[-2].altype)->getVector())
            {
                d.emplace_back(node->getExprNode()->getIntop().value());
            }
            se->setType(new ArrayType(se->getType(),d));
            bool isint = se->getType()->isInt();
            bool isreturn = false;
            std::vector<int> initiallist{};
            std::vector<float> finitiallist{};
            std::vector<int> dims = dynamic_cast<ArrayType*>(se->getType())->getDims();
            std::vector<int> status(dims.size());
            std::vector<int> target(dims.size());
            for(size_t i=0;i<target.size();++i)
            {
                target[i] = dims[i]-1;
            }
            std::function<void(InitVal*, int)> initarr = [&](InitVal* init,int level){
                if(init->getExprNode()!=nullptr)
                {   
                    if(isint)
                        initiallist.emplace_back(init->getExprNode()->getInt());
                    else
                        finitiallist.emplace_back(init->getExprNode()->getFloat());
                    if(status==target)
                    {
                        isreturn = true;
                        return;
                    }
                    for(int i = dims.size()-1;i>=0;--i)
                    {
                        if(status[i]==dims[i]-1)
                        {
                            if(i!=0)
                            {
                                status[i] = 0;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            ++status[i];
                            break;
                        }
                    }

                }
                else
                {
                    auto childs = init->getChilds();
                    for(auto node : childs)
                    {
                        int st = status[level];
                        initarr(node,level+1);
                        if(node->getExprNode()==nullptr)
                        {
                            if(status==target)
                            {
                                isreturn = true;
                                return;
                            }
                            std::vector<int> temp(status);
                            bool isboundary = true;
                            for(size_t i = level+1;i<status.size();++i)
                            {
                                if(status[i] != 0)
                                {
                                    isboundary=false;
                                    break;
                                }
                            }
                            if(!isboundary||temp[level]==st)
                            {
                                status[level]++;
                                for(size_t i = level+1;i<status.size();++i)
                                {
                                    status[i] = 0;
                                }
                                while(temp!=status)
                                {
                                    if(isint)
                                        initiallist.emplace_back(0);
                                    else
                                        finitiallist.emplace_back(0);        
                                    if(temp==target)
                                    {
                                        isreturn = true;
                                        return;
                                    }
                                    for(int i = dims.size()-1;i>=0;--i)
                                    {
                                        if(temp[i]>=dims[i]-1)
                                        {
                                            if(i!=0)
                                            {
                                                temp[i] = 0;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            ++temp[i];
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            };
            initarr((yyvsp[0].ivtype),0);
            if(!isreturn||status<target)
            {
                while(status!=target)
                {
                    if(isint)
                        initiallist.emplace_back(0);
                    else
                        finitiallist.emplace_back(0);
                    for(int i = target.size()-1;i>=0;--i)
                    {
                        if(status[i]==target[i])
                        {
                            status[i] = 0;
                        }
                        else
                        {
                            ++status[i];
                            break;
                        }
                    }
                }
                if(isint)
                    initiallist.emplace_back(0);
                else
                    finitiallist.emplace_back(0);
            }
            if(isint)
            {
                dynamic_cast<IdentifierSymbolEntry*>(se)->changeIntArray(std::make_optional<std::vector<int>>(initiallist));
            }
            else
            {
                dynamic_cast<IdentifierSymbolEntry*>(se)->changeFloatArray(std::make_optional<std::vector<float>>(finitiallist));
            }
        }
        else
        {
            assert((yyvsp[0].ivtype)->getExprNode()!=nullptr&&(yyvsp[0].ivtype)->getExprNode()->hasValue());
            if(vtype->isInt())
            {
                dynamic_cast<IdentifierSymbolEntry*>(se)->changeInt(std::make_optional<int>((yyvsp[0].ivtype)->getExprNode()->getFloat()));
            }
            else
            {
                dynamic_cast<IdentifierSymbolEntry*>(se)->changeFloat(std::make_optional<float>((yyvsp[0].ivtype)->getExprNode()->getFloat()));
            }
        }
        (yyval.vitype) = new VarId(se,(yyvsp[-2].altype),(yyvsp[0].ivtype));
        (yyval.vitype)->changeinit(true);
        (yyval.vitype)->changeconst(true);
        delete [](yyvsp[-4].strtype);
    }
#line 2209 "src/parser.cpp"
    break;

  case 68: /* ConstInitVal: ConstExp  */
#line 736 "src/parser.y"
              {
        (yyval.ivtype) = new InitVal((yyvsp[0].exprtype));
    }
#line 2217 "src/parser.cpp"
    break;

  case 69: /* ConstInitVal: LBRACE ConstInitVals RBRACE  */
#line 739 "src/parser.y"
                                 {
        (yyval.ivtype) = new InitVal((yyvsp[-1].vivtype)->vals);
    }
#line 2225 "src/parser.cpp"
    break;

  case 70: /* ConstInitVal: LBRACE RBRACE  */
#line 742 "src/parser.y"
                   {
        (yyval.ivtype) = new InitVal();
    }
#line 2233 "src/parser.cpp"
    break;

  case 71: /* ConstInitVals: ConstInitVal  */
#line 747 "src/parser.y"
                   {
        (yyval.vivtype) = new InitVals();
        (yyval.vivtype)->vals.push_back((yyvsp[0].ivtype));
    }
#line 2242 "src/parser.cpp"
    break;

  case 72: /* ConstInitVals: ConstInitVals COMMA ConstInitVal  */
#line 751 "src/parser.y"
                                      {
        (yyvsp[-2].vivtype)->vals.push_back((yyvsp[0].ivtype));
        (yyval.vivtype) = (yyvsp[-2].vivtype);
    }
#line 2251 "src/parser.cpp"
    break;

  case 73: /* CallParams: Exp  */
#line 758 "src/parser.y"
        {
        (yyval.cptype) = new CallParams((yyvsp[0].exprtype));
    }
#line 2259 "src/parser.cpp"
    break;

  case 74: /* CallParams: CallParams COMMA Exp  */
#line 761 "src/parser.y"
                          {
        (yyvsp[-2].cptype)->push_back((yyvsp[0].exprtype));
        (yyval.cptype) = (yyvsp[-2].cptype);
    }
#line 2268 "src/parser.cpp"
    break;

  case 75: /* $@4: %empty  */
#line 768 "src/parser.y"
          {
        vtype = (yyvsp[0].type);
    }
#line 2276 "src/parser.cpp"
    break;

  case 76: /* DeclStmt: BType $@4 TempDecl  */
#line 771 "src/parser.y"
             {
        (yyval.tdectype) = (yyvsp[0].tdectype);
    }
#line 2284 "src/parser.cpp"
    break;

  case 77: /* $@5: %empty  */
#line 774 "src/parser.y"
          {
        vtype = TypeSystem::voidType;
    }
#line 2292 "src/parser.cpp"
    break;

  case 78: /* DeclStmt: VOID $@5 TempDecl  */
#line 777 "src/parser.y"
             {
        (yyval.tdectype) = (yyvsp[0].tdectype);
    }
#line 2300 "src/parser.cpp"
    break;

  case 79: /* TempDecl: VarIds SEMICOLON  */
#line 783 "src/parser.y"
                    {
        (yyval.tdectype) = new TDeclStmt(new DeclStmt((yyvsp[-1].vistype)));
    }
#line 2308 "src/parser.cpp"
    break;

  case 80: /* $@6: %empty  */
#line 787 "src/parser.y"
    {
        Type *funcType;
        funcType = new FunctionType(vtype,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        identifiers = new SymbolTable(identifiers);
    }
#line 2320 "src/parser.cpp"
    break;

  case 81: /* TempDecl: ID $@6 LPAREN FuncParams RPAREN BlockStmt  */
#line 795 "src/parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-5].strtype));
        std::vector<Type*> t{};
        for(const auto& node : (yyvsp[-2].fpstype)->getVector())
        {
            t.emplace_back(node->getType());
        }
        dynamic_cast<FunctionType*>(se->getType())->changeParams(t);
        assert(se != nullptr);
        (yyval.tdectype) = new TDeclStmt(new FunctionDef(se, (yyvsp[0].stmttype),(yyvsp[-2].fpstype)));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev(); 
        delete top;
        delete [](yyvsp[-5].strtype);

    }
#line 2342 "src/parser.cpp"
    break;

  case 82: /* VarIds: VarId  */
#line 814 "src/parser.y"
         {
        (yyval.vistype) = new VarIds((yyvsp[0].vitype));
    }
#line 2350 "src/parser.cpp"
    break;

  case 83: /* VarIds: VarIds COMMA VarId  */
#line 817 "src/parser.y"
                        {
        (yyvsp[-2].vistype)->push_back((yyvsp[0].vitype));
        (yyval.vistype) = (yyvsp[-2].vistype);
    }
#line 2359 "src/parser.cpp"
    break;

  case 84: /* FuncParams: %empty  */
#line 825 "src/parser.y"
           {
        (yyval.fpstype) = new FuncParams();
    }
#line 2367 "src/parser.cpp"
    break;

  case 85: /* FuncParams: FuncParam  */
#line 828 "src/parser.y"
                {
        (yyval.fpstype) = new FuncParams((yyvsp[0].fptype));
    }
#line 2375 "src/parser.cpp"
    break;

  case 86: /* FuncParams: FuncParams COMMA FuncParam  */
#line 831 "src/parser.y"
                                {
        (yyvsp[-2].fpstype)->push_back((yyvsp[0].fptype));
        (yyval.fpstype) = (yyvsp[-2].fpstype);
    }
#line 2384 "src/parser.cpp"
    break;

  case 87: /* FuncParam: BType ID  */
#line 837 "src/parser.y"
               {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.fptype) = new FuncParam(se);
    }
#line 2395 "src/parser.cpp"
    break;

  case 88: /* FuncParam: BType ID LBRACKET RBRACKET FArrayList  */
#line 843 "src/parser.y"
                                           {
        SymbolEntry *se;
        if(!((yyvsp[0].faltype)->getVector().empty()))
        {
            std::vector<int> d{};
            for(auto& node : (yyvsp[0].faltype)->getVector())
            {
                d.emplace_back(node->getExprNode()->getIntop().value());
            }
            se = new IdentifierSymbolEntry((new PointerType(new ArrayType((yyvsp[-4].type),d))), (yyvsp[-3].strtype), identifiers->getLevel());
        }
        else
        {
            se = new IdentifierSymbolEntry((new PointerType((yyvsp[-4].type))), (yyvsp[-3].strtype), identifiers->getLevel());
        }
        identifiers->install((yyvsp[-3].strtype), se);
        (yyval.fptype) = new FuncParam(se,(yyvsp[0].faltype));
        (yyval.fptype)->changearray(true);
    }
#line 2419 "src/parser.cpp"
    break;

  case 89: /* FArrayList: %empty  */
#line 864 "src/parser.y"
             { 
        (yyval.faltype) = new FArrayList();
    }
#line 2427 "src/parser.cpp"
    break;

  case 90: /* FArrayList: FArrayList FArrayNode  */
#line 867 "src/parser.y"
                              {
        (yyvsp[-1].faltype)->push_back((yyvsp[0].fartype));
        (yyval.faltype) = (yyvsp[-1].faltype);
    }
#line 2436 "src/parser.cpp"
    break;

  case 91: /* FArrayNode: LBRACKET Exp RBRACKET  */
#line 873 "src/parser.y"
                            {
        (yyval.fartype) = new FArrayNode((yyvsp[-1].exprtype));
    }
#line 2444 "src/parser.cpp"
    break;

  case 92: /* $@7: %empty  */
#line 878 "src/parser.y"
         {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(vtype, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        name = (yyvsp[0].strtype);
        delete [](yyvsp[0].strtype);
    }
#line 2456 "src/parser.cpp"
    break;

  case 93: /* VarId: ID $@7 TempVarId  */
#line 886 "src/parser.y"
    {
        (yyval.vitype) = (yyvsp[0].vitype);
    }
#line 2464 "src/parser.cpp"
    break;

  case 94: /* TempVarId: ArrayList  */
#line 892 "src/parser.y"
    {
        auto se = identifiers->lookup(name);
        assert(se!=nullptr);
        if(!((yyvsp[0].altype)->getVector().empty()))
        {
            std::vector<int> d{};
            for(auto& node : (yyvsp[0].altype)->getVector())
            {
                d.emplace_back(node->getExprNode()->getIntop().value());
            }
            se->setType(new ArrayType(se->getType(),d));
        }
        (yyval.vitype) = new VarId(se,(yyvsp[0].altype));
    }
#line 2483 "src/parser.cpp"
    break;

  case 95: /* TempVarId: ArrayList ASSIGN InitVal  */
#line 907 "src/parser.y"
    {
        auto se = identifiers->lookup(name);
        assert(se!=nullptr);
        if(!((yyvsp[-2].altype)->getVector().empty()))
        {
            std::vector<int> d{};
            for(auto& node : (yyvsp[-2].altype)->getVector())
            {
                d.emplace_back(node->getExprNode()->getIntop().value());
            }
            se->setType(new ArrayType(se->getType(),d));
        }
        (yyval.vitype) = new VarId(se,(yyvsp[-2].altype),(yyvsp[0].ivtype));
        (yyval.vitype)->changeinit(true);
    }
#line 2503 "src/parser.cpp"
    break;

  case 96: /* ArrayList: %empty  */
#line 923 "src/parser.y"
             { 
        (yyval.altype) = new ArrayList();
    }
#line 2511 "src/parser.cpp"
    break;

  case 97: /* ArrayList: ArrayList ArrayNode  */
#line 926 "src/parser.y"
                            {
        (yyvsp[-1].altype)->push_back((yyvsp[0].artype));
        (yyval.altype) = (yyvsp[-1].altype);
    }
#line 2520 "src/parser.cpp"
    break;

  case 98: /* ArrayNode: LBRACKET ConstExp RBRACKET  */
#line 932 "src/parser.y"
                                 {
        (yyval.artype) = new ArrayNode((yyvsp[-1].exprtype));
    }
#line 2528 "src/parser.cpp"
    break;

  case 99: /* Exp: AddExp  */
#line 938 "src/parser.y"
           {
        if((yyvsp[0].exprtype)->hasValue())
        {
            if((yyvsp[0].exprtype)->hasInt())
            {
                SymbolEntry *se = new IntSymbolEntry(TypeSystem::intType,(yyvsp[0].exprtype)->getInt());
                (yyval.exprtype) = new Constant(se);
            }
            else
            {
                SymbolEntry *se = new FloatSymbolEntry(TypeSystem::floatType,(yyvsp[0].exprtype)->getFloat());
                (yyval.exprtype) = new Constant(se);
            }
        }
        else
        {
            (yyval.exprtype) = (yyvsp[0].exprtype);
        }
    }
#line 2552 "src/parser.cpp"
    break;

  case 100: /* ConstExp: AddExp  */
#line 959 "src/parser.y"
             {
        assert((yyvsp[0].exprtype)->hasValue());
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2561 "src/parser.cpp"
    break;

  case 101: /* InitVal: Exp  */
#line 965 "src/parser.y"
         {
        (yyval.ivtype) = new InitVal((yyvsp[0].exprtype));
    }
#line 2569 "src/parser.cpp"
    break;

  case 102: /* InitVal: LBRACE InitVals RBRACE  */
#line 968 "src/parser.y"
                            {
        (yyval.ivtype) = new InitVal((yyvsp[-1].vivtype)->vals);
    }
#line 2577 "src/parser.cpp"
    break;

  case 103: /* InitVal: LBRACE RBRACE  */
#line 971 "src/parser.y"
                   {
        (yyval.ivtype) = new InitVal();
    }
#line 2585 "src/parser.cpp"
    break;

  case 104: /* InitVals: InitVal  */
#line 976 "src/parser.y"
              {
        (yyval.vivtype) = new InitVals();
        (yyval.vivtype)->vals.push_back((yyvsp[0].ivtype));
    }
#line 2594 "src/parser.cpp"
    break;

  case 105: /* InitVals: InitVals COMMA InitVal  */
#line 980 "src/parser.y"
                            {
        (yyvsp[-2].vivtype)->vals.push_back((yyvsp[0].ivtype));
        (yyval.vivtype) = (yyvsp[-2].vivtype);
    }
#line 2603 "src/parser.cpp"
    break;

  case 106: /* WhileStmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 986 "src/parser.y"
                                    {
        (yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 2611 "src/parser.cpp"
    break;


#line 2615 "src/parser.cpp"

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

#line 990 "src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
