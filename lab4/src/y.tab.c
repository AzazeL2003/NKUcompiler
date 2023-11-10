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
#line 1 "parser.y"

    #include <iostream>
    #include <string>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
    bool issysinit = false;
    Type* vtype = nullptr;

#line 80 "y.tab.c"




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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 13 "parser.y"

    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"

#line 124 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    FLT = 259,                     /* FLT  */
    INTEGER = 260,                 /* INTEGER  */
    OCTAL = 261,                   /* OCTAL  */
    HEX = 262,                     /* HEX  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    CONTINUE = 266,                /* CONTINUE  */
    BREAK = 267,                   /* BREAK  */
    INT = 268,                     /* INT  */
    VOID = 269,                    /* VOID  */
    CONST = 270,                   /* CONST  */
    FLOAT = 271,                   /* FLOAT  */
    LPAREN = 272,                  /* LPAREN  */
    RPAREN = 273,                  /* RPAREN  */
    LBRACE = 274,                  /* LBRACE  */
    RBRACE = 275,                  /* RBRACE  */
    SEMICOLON = 276,               /* SEMICOLON  */
    COMMA = 277,                   /* COMMA  */
    LBRACKET = 278,                /* LBRACKET  */
    RBRACKET = 279,                /* RBRACKET  */
    ADD = 280,                     /* ADD  */
    SUB = 281,                     /* SUB  */
    MUL = 282,                     /* MUL  */
    DIV = 283,                     /* DIV  */
    MOD = 284,                     /* MOD  */
    LESS = 285,                    /* LESS  */
    ASSIGN = 286,                  /* ASSIGN  */
    GREATER = 287,                 /* GREATER  */
    NGREATER = 288,                /* NGREATER  */
    NLESS = 289,                   /* NLESS  */
    NEQUAL = 290,                  /* NEQUAL  */
    EQUAL = 291,                   /* EQUAL  */
    NOT = 292,                     /* NOT  */
    LOR = 293,                     /* LOR  */
    LAND = 294,                    /* LAND  */
    RETURN = 295,                  /* RETURN  */
    THEN = 296                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define FLT 259
#define INTEGER 260
#define OCTAL 261
#define HEX 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define CONTINUE 266
#define BREAK 267
#define INT 268
#define VOID 269
#define CONST 270
#define FLOAT 271
#define LPAREN 272
#define RPAREN 273
#define LBRACE 274
#define RBRACE 275
#define SEMICOLON 276
#define COMMA 277
#define LBRACKET 278
#define RBRACKET 279
#define ADD 280
#define SUB 281
#define MUL 282
#define DIV 283
#define MOD 284
#define LESS 285
#define ASSIGN 286
#define GREATER 287
#define NGREATER 288
#define NLESS 289
#define NEQUAL 290
#define EQUAL 291
#define NOT 292
#define LOR 293
#define LAND 294
#define RETURN 295
#define THEN 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

    int itype;
    float ftype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    SeqNode* seqtype;
    Type* type;
    VarIds* vistype;
    VarId* vitype;
    DeclStmt* dectype;
    ArrayList* altype;
    ArrayNode* artype;
    FArrayList* faltype;
    FArrayNode* fartype;
    ConstDeclStmt* cdectype;
    InitVal* ivtype;
    InitVals* vivtype;
    FuncParam* fptype;
    FuncParams* fpstype;
    CallParams* cptype;

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

#if !defined yyerror && !defined YYERROR_IS_DECLARED
void yyerror (const char *msg);
#endif
#if !defined yylex && !defined YYLEX_IS_DECLARED
int yylex (void);
#endif

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
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
  YYSYMBOL_BreakStmt = 46,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 47,              /* ContinueStmt  */
  YYSYMBOL_PlainStmt = 48,                 /* PlainStmt  */
  YYSYMBOL_BType = 49,                     /* BType  */
  YYSYMBOL_ConstDeclStmt = 50,             /* ConstDeclStmt  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_DeclStmt = 52,                  /* DeclStmt  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_TempDecl = 55,                  /* TempDecl  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_ConstVarIds = 57,               /* ConstVarIds  */
  YYSYMBOL_ConstVarId = 58,                /* ConstVarId  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_VarIds = 60,                    /* VarIds  */
  YYSYMBOL_VarId = 61,                     /* VarId  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_TempVarId = 63,                 /* TempVarId  */
  YYSYMBOL_InitVal = 64,                   /* InitVal  */
  YYSYMBOL_InitVals = 65,                  /* InitVals  */
  YYSYMBOL_ConstInitVal = 66,              /* ConstInitVal  */
  YYSYMBOL_ConstInitVals = 67,             /* ConstInitVals  */
  YYSYMBOL_FuncParams = 68,                /* FuncParams  */
  YYSYMBOL_FuncParam = 69,                 /* FuncParam  */
  YYSYMBOL_CallParams = 70,                /* CallParams  */
  YYSYMBOL_FArrayList = 71,                /* FArrayList  */
  YYSYMBOL_FArrayNode = 72,                /* FArrayNode  */
  YYSYMBOL_ArrayList = 73,                 /* ArrayList  */
  YYSYMBOL_ArrayNode = 74,                 /* ArrayNode  */
  YYSYMBOL_ConstExp = 75,                  /* ConstExp  */
  YYSYMBOL_AssignStmt = 76,                /* AssignStmt  */
  YYSYMBOL_BlockStmt = 77,                 /* BlockStmt  */
  YYSYMBOL_78_7 = 78,                      /* $@7  */
  YYSYMBOL_IfStmt = 79,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 80,                 /* WhileStmt  */
  YYSYMBOL_ReturnStmt = 81,                /* ReturnStmt  */
  YYSYMBOL_Exp = 82,                       /* Exp  */
  YYSYMBOL_Cond = 83,                      /* Cond  */
  YYSYMBOL_LVal = 84,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 85,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 86,                  /* UnaryExp  */
  YYSYMBOL_MulExp = 87,                    /* MulExp  */
  YYSYMBOL_AddExp = 88,                    /* AddExp  */
  YYSYMBOL_RelExp = 89,                    /* RelExp  */
  YYSYMBOL_EqExp = 90,                     /* EqExp  */
  YYSYMBOL_LAndExp = 91,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 92                     /* LOrExp  */
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
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

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
       0,    74,    74,    79,    80,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    98,   103,   107,   108,   110,
     113,   119,   119,   128,   128,   136,   135,   158,   162,   161,
     183,   186,   192,   192,   209,   212,   218,   218,   229,   237,
     246,   249,   252,   257,   261,   267,   270,   273,   278,   282,
     289,   292,   295,   301,   307,   317,   320,   326,   329,   335,
     340,   343,   349,   354,   358,   364,   363,   372,   378,   381,
     386,   392,   395,   401,   405,   408,   428,   431,   436,   441,
     446,   451,   457,   460,   471,   482,   486,   490,   497,   499,
     505,   511,   519,   521,   527,   535,   537,   543,   549,   555,
     563,   565,   571,   579,   581,   589,   591
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
  "Stmts", "Stmt", "BreakStmt", "ContinueStmt", "PlainStmt", "BType",
  "ConstDeclStmt", "$@1", "DeclStmt", "$@2", "$@3", "TempDecl", "$@4",
  "ConstVarIds", "ConstVarId", "$@5", "VarIds", "VarId", "$@6",
  "TempVarId", "InitVal", "InitVals", "ConstInitVal", "ConstInitVals",
  "FuncParams", "FuncParam", "CallParams", "FArrayList", "FArrayNode",
  "ArrayList", "ArrayNode", "ConstExp", "AssignStmt", "BlockStmt", "$@7",
  "IfStmt", "WhileStmt", "ReturnStmt", "Exp", "Cond", "LVal", "PrimaryExp",
  "UnaryExp", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-29)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     182,    -6,  -153,  -153,  -153,  -153,     0,    20,    12,    23,
    -153,    92,    81,  -153,   235,    60,  -153,   235,   235,   235,
      15,   121,   182,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,   105,    96,  -153,  -153,    77,
      42,   206,   107,   235,   235,  -153,  -153,  -153,  -153,   111,
    -153,  -153,   182,  -153,  -153,  -153,  -153,   112,  -153,  -153,
     131,  -153,   235,   235,   235,   235,   235,   235,  -153,    25,
    -153,   235,  -153,   120,    42,    44,    52,   100,   102,   123,
     127,   143,  -153,   144,  -153,   136,  -153,    80,  -153,   145,
    -153,  -153,  -153,    77,    77,  -153,   235,   147,   182,   235,
     235,   235,   235,   235,   235,   235,   235,   182,    81,  -153,
      94,  -153,  -153,   150,  -153,  -153,   165,  -153,  -153,  -153,
     163,    42,    42,    42,    42,    44,    44,    52,   100,  -153,
     170,    57,  -153,  -153,  -153,   143,    81,  -153,     8,  -153,
    -153,   182,   151,   156,    81,    19,  -153,    71,   235,   106,
    -153,  -153,   152,  -153,  -153,   211,   156,   153,    42,     9,
    -153,  -153,  -153,    66,  -153,  -153,  -153,  -153,  -153,  -153,
      29,   107,  -153,  -153,    76,  -153,   106,  -153,   211,  -153,
    -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    57,    80,    77,    78,    79,     0,     0,     0,     0,
      19,     0,     0,    20,     0,    65,    17,     0,     0,     0,
       0,     0,     2,     3,    13,    14,    12,    23,    11,    10,
       5,     6,     7,     8,     9,     0,    76,    82,    88,    92,
      73,     0,    75,     0,     0,    16,    15,    25,    21,     0,
      76,    67,     0,    85,    86,    87,    72,     0,     1,     4,
       0,    18,     0,     0,     0,     0,     0,     0,    83,     0,
      55,     0,    58,     0,    95,   100,   103,   105,    74,     0,
       0,     0,    81,     0,    71,    36,    24,     0,    34,     0,
      89,    90,    91,    93,    94,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    32,
       0,    30,    66,     0,    60,    27,     0,    64,    56,    59,
      68,    96,    97,    98,    99,   102,   101,   104,   106,    70,
       0,     0,    51,    60,    22,     0,    50,    37,    38,    36,
      35,     0,    53,     0,     0,     0,    31,     0,     0,     0,
      61,    69,     0,    26,    52,     0,     0,     0,    63,     0,
      39,    40,    57,     0,    33,    45,    29,    62,    42,    43,
       0,    54,    47,    48,     0,    41,     0,    46,     0,    44,
      49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   126,   -17,  -153,  -153,  -153,    -8,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,    45,  -153,  -153,    63,
    -153,  -153,  -152,  -153,  -133,  -153,    46,    39,  -153,    38,
    -153,    58,  -153,    54,  -153,  -118,  -153,  -153,  -153,  -153,
     -14,   160,     1,  -153,    -9,    51,   -41,    16,   101,    99,
    -153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    21,    22,    23,    24,    25,    26,    27,    28,    81,
      29,    60,    80,    86,   113,   110,   111,   133,    87,    88,
     114,   137,   160,   170,   164,   174,   131,   132,    69,    42,
      72,   138,   150,   165,    30,    31,    52,    32,    33,    34,
      35,    73,    50,    37,    38,    39,    40,    75,    76,    77,
      78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    36,    74,    74,    48,    59,    57,   169,    53,    54,
      55,    41,     1,     2,     3,     4,     5,    43,     1,     2,
       3,     4,     5,    36,   179,   153,    14,    70,   159,   168,
     173,   148,    14,    45,    17,    18,    56,    44,   166,   149,
      17,    18,   148,    95,    46,   180,    19,    96,    89,   175,
     155,   176,    19,    36,    90,    91,    92,    97,   121,   122,
     123,   124,    74,    74,    74,    74,    59,    66,    67,     1,
       2,     3,     4,     5,    99,   143,   100,   101,   102,   144,
      51,   120,   118,    14,    36,   163,   172,   103,   104,   156,
     129,    17,    18,   144,    10,    47,   177,    13,   178,    36,
     130,   115,   116,    19,    63,    64,    65,   158,    36,     1,
       2,     3,     4,     5,   158,   134,   135,    93,    94,   125,
     126,    58,   158,    14,   151,   159,    61,    62,   130,    82,
      71,    17,    18,    84,    85,   161,   130,   158,    98,   105,
     106,   107,    36,    19,   108,   161,   109,     1,     2,     3,
       4,     5,     6,   -28,     7,     8,     9,    10,    11,    12,
      13,    14,   161,    15,   112,    16,   117,   136,   139,    17,
      18,   119,   141,   142,   152,    15,   162,   167,    83,   140,
     146,    19,   147,   154,    20,     1,     2,     3,     4,     5,
       6,   145,     7,     8,     9,    10,    11,    12,    13,    14,
     171,    15,   157,    16,    79,   128,   127,    17,    18,     1,
       2,     3,     4,     5,     1,     2,     3,     4,     5,    19,
       0,     0,    20,    14,    68,     0,     0,     0,    14,     0,
     163,    17,    18,     0,     0,     0,    17,    18,     1,     2,
       3,     4,     5,    19,     0,     0,     0,     0,    19,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19
};

static const yytype_int16 yycheck[] =
{
      14,     0,    43,    44,    12,    22,    20,   159,    17,    18,
      19,    17,     3,     4,     5,     6,     7,    17,     3,     4,
       5,     6,     7,    22,   176,   143,    17,    41,    19,    20,
     163,    23,    17,    21,    25,    26,    21,    17,   156,    31,
      25,    26,    23,    18,    21,   178,    37,    22,    62,    20,
      31,    22,    37,    52,    63,    64,    65,    71,    99,   100,
     101,   102,   103,   104,   105,   106,    83,    25,    26,     3,
       4,     5,     6,     7,    30,    18,    32,    33,    34,    22,
      20,    98,    96,    17,    83,    19,    20,    35,    36,    18,
     107,    25,    26,    22,    13,     3,    20,    16,    22,    98,
     108,    21,    22,    37,    27,    28,    29,   148,   107,     3,
       4,     5,     6,     7,   155,    21,    22,    66,    67,   103,
     104,     0,   163,    17,   141,    19,    21,    31,   136,    18,
      23,    25,    26,    21,     3,   149,   144,   178,    18,    39,
      38,    18,   141,    37,    17,   159,     3,     3,     4,     5,
       6,     7,     8,    17,    10,    11,    12,    13,    14,    15,
      16,    17,   176,    19,    20,    21,    21,    17,     3,    25,
      26,    24,     9,     3,    23,    19,    24,    24,    52,   116,
     135,    37,   136,   144,    40,     3,     4,     5,     6,     7,
       8,   133,    10,    11,    12,    13,    14,    15,    16,    17,
     162,    19,   148,    21,    44,   106,   105,    25,    26,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    37,
      -1,    -1,    40,    17,    18,    -1,    -1,    -1,    17,    -1,
      19,    25,    26,    -1,    -1,    -1,    25,    26,     3,     4,
       5,     6,     7,    37,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    19,    21,    25,    26,    37,
      40,    43,    44,    45,    46,    47,    48,    49,    50,    52,
      76,    77,    79,    80,    81,    82,    84,    85,    86,    87,
      88,    17,    71,    17,    17,    21,    21,     3,    49,    82,
      84,    20,    78,    86,    86,    86,    21,    82,     0,    45,
      53,    21,    31,    27,    28,    29,    25,    26,    18,    70,
      82,    23,    72,    83,    88,    89,    90,    91,    92,    83,
      54,    51,    18,    44,    21,     3,    55,    60,    61,    82,
      86,    86,    86,    87,    87,    18,    22,    82,    18,    30,
      32,    33,    34,    35,    36,    39,    38,    18,    17,     3,
      57,    58,    20,    56,    62,    21,    22,    21,    82,    24,
      45,    88,    88,    88,    88,    89,    89,    90,    91,    45,
      49,    68,    69,    59,    21,    22,    17,    63,    73,     3,
      61,     9,     3,    18,    22,    73,    58,    68,    23,    31,
      74,    45,    23,    77,    69,    31,    18,    75,    88,    19,
      64,    82,    24,    19,    66,    75,    77,    24,    20,    64,
      65,    71,    20,    66,    67,    20,    22,    20,    22,    64,
      66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    47,    48,    48,    49,
      49,    51,    50,    53,    52,    54,    52,    55,    56,    55,
      57,    57,    59,    58,    60,    60,    62,    61,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    75,    76,    78,    77,    77,    79,    79,
      80,    81,    81,    82,    83,    84,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     2,     1,
       1,     0,     5,     0,     3,     0,     7,     2,     0,     6,
       1,     3,     0,     5,     1,     3,     0,     3,     1,     3,
       1,     3,     2,     1,     3,     1,     3,     2,     1,     3,
       0,     1,     3,     2,     5,     1,     3,     0,     2,     3,
       0,     2,     3,     1,     4,     0,     4,     2,     5,     7,
       5,     3,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     4,     2,     2,     2,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3
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
#line 74 "parser.y"
            {
        ast.setRoot((yyvsp[0].seqtype));
    }
#line 1478 "y.tab.c"
    break;

  case 3: /* Stmts: Stmt  */
#line 79 "parser.y"
           {(yyval.seqtype) = new SeqNode((yyvsp[0].stmttype));}
#line 1484 "y.tab.c"
    break;

  case 4: /* Stmts: Stmts Stmt  */
#line 80 "parser.y"
                {
        (yyvsp[-1].seqtype)->push_back((yyvsp[0].stmttype));
        (yyval.seqtype) = (yyvsp[-1].seqtype);
    }
#line 1493 "y.tab.c"
    break;

  case 5: /* Stmt: AssignStmt  */
#line 86 "parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1499 "y.tab.c"
    break;

  case 6: /* Stmt: BlockStmt  */
#line 87 "parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1505 "y.tab.c"
    break;

  case 7: /* Stmt: IfStmt  */
#line 88 "parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1511 "y.tab.c"
    break;

  case 8: /* Stmt: WhileStmt  */
#line 89 "parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1517 "y.tab.c"
    break;

  case 9: /* Stmt: ReturnStmt  */
#line 90 "parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1523 "y.tab.c"
    break;

  case 10: /* Stmt: DeclStmt  */
#line 91 "parser.y"
               {(yyval.stmttype)=(yyvsp[0].dectype);}
#line 1529 "y.tab.c"
    break;

  case 11: /* Stmt: ConstDeclStmt  */
#line 92 "parser.y"
                    {(yyval.stmttype)=(yyvsp[0].cdectype);}
#line 1535 "y.tab.c"
    break;

  case 12: /* Stmt: PlainStmt  */
#line 93 "parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1541 "y.tab.c"
    break;

  case 13: /* Stmt: BreakStmt  */
#line 94 "parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1547 "y.tab.c"
    break;

  case 14: /* Stmt: ContinueStmt  */
#line 95 "parser.y"
                   {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1553 "y.tab.c"
    break;

  case 15: /* BreakStmt: BREAK SEMICOLON  */
#line 98 "parser.y"
                     {
        (yyval.stmttype) = new BreakStmt();
    }
#line 1561 "y.tab.c"
    break;

  case 16: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 103 "parser.y"
                        {
        (yyval.stmttype) = new ContinueStmt();
    }
#line 1569 "y.tab.c"
    break;

  case 17: /* PlainStmt: SEMICOLON  */
#line 107 "parser.y"
                {(yyval.stmttype) = new PlainStmt();}
#line 1575 "y.tab.c"
    break;

  case 18: /* PlainStmt: Exp SEMICOLON  */
#line 108 "parser.y"
                    {(yyval.stmttype) = new PlainStmt((yyvsp[-1].exprtype));}
#line 1581 "y.tab.c"
    break;

  case 19: /* BType: INT  */
#line 110 "parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 1589 "y.tab.c"
    break;

  case 20: /* BType: FLOAT  */
#line 113 "parser.y"
            {
        (yyval.type) = TypeSystem::floatType;
    }
#line 1597 "y.tab.c"
    break;

  case 21: /* $@1: %empty  */
#line 119 "parser.y"
                {
        vtype = (yyvsp[0].type);
    }
#line 1605 "y.tab.c"
    break;

  case 22: /* ConstDeclStmt: CONST BType $@1 ConstVarIds SEMICOLON  */
#line 122 "parser.y"
                         {
        (yyval.cdectype) = new ConstDeclStmt((yyvsp[-1].vistype));
    }
#line 1613 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 128 "parser.y"
          {
        vtype = (yyvsp[0].type);
    }
#line 1621 "y.tab.c"
    break;

  case 24: /* DeclStmt: BType $@2 TempDecl  */
#line 132 "parser.y"
    {
        (yyval.dectype) = (yyvsp[0].dectype);
    }
#line 1629 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 136 "parser.y"
    {
        Type *funcType;
        funcType = new FunctionType(TypeSystem::voidType,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        identifiers = new SymbolTable(identifiers);
    }
#line 1641 "y.tab.c"
    break;

  case 26: /* DeclStmt: VOID ID $@3 LPAREN FuncParams RPAREN BlockStmt  */
#line 144 "parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-5].strtype));
        assert(se != nullptr);
        (yyval.dectype) = new FunctionDef(se, (yyvsp[0].stmttype),(yyvsp[-2].fpstype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-5].strtype);

    }
#line 1657 "y.tab.c"
    break;

  case 27: /* TempDecl: VarIds SEMICOLON  */
#line 158 "parser.y"
                    {
        (yyval.dectype) = new DeclStmt((yyvsp[-1].vistype));
    }
#line 1665 "y.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 162 "parser.y"
    {
        Type *funcType;
        funcType = new FunctionType(vtype,{});//TODO
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        identifiers = new SymbolTable(identifiers);
    }
#line 1677 "y.tab.c"
    break;

  case 29: /* TempDecl: ID $@4 LPAREN FuncParams RPAREN BlockStmt  */
#line 170 "parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-5].strtype));
        assert(se != nullptr);
        (yyval.dectype) = new FunctionDef(se, (yyvsp[0].stmttype),(yyvsp[-2].fpstype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev(); 
        delete top;
        delete [](yyvsp[-5].strtype);

    }
#line 1693 "y.tab.c"
    break;

  case 30: /* ConstVarIds: ConstVarId  */
#line 183 "parser.y"
              {
        (yyval.vistype) = new VarDefs((yyvsp[0].vitype));
    }
#line 1701 "y.tab.c"
    break;

  case 31: /* ConstVarIds: ConstVarIds COMMA ConstVarId  */
#line 186 "parser.y"
                                  {
        (yyvsp[-2].vistype)->push_back((yyvsp[0].vitype));
        (yyval.vistype) = (yyvsp[-2].vistype);
    }
#line 1710 "y.tab.c"
    break;

  case 32: /* $@5: %empty  */
#line 192 "parser.y"
        {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(vtype, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
    }
#line 1720 "y.tab.c"
    break;

  case 33: /* ConstVarId: ID $@5 ArrayList ASSIGN ConstInitVal  */
#line 198 "parser.y"
    {
        auto se = identifiers->lookup((yyvsp[-4].strtype));
        assert(se!=nullptr)
        (yyval.vitype) = new VarId(se,(yyvsp[-2].altype),(yyvsp[0].ivtype));
        (yyval.vitype)->changeinit(true);
        (yyval.vitype)->changeconst(true);
        delete [](yyvsp[-4].strtype);
    }
#line 1733 "y.tab.c"
    break;

  case 34: /* VarIds: VarId  */
#line 209 "parser.y"
         {
        (yyval.vistype) = new VarDefs((yyvsp[0].vitype));
    }
#line 1741 "y.tab.c"
    break;

  case 35: /* VarIds: VarIds COMMA VarId  */
#line 212 "parser.y"
                        {
        (yyvsp[-2].vistype)->push_back((yyvsp[0].vitype));
        (yyval.vistype) = (yyvsp[-2].vistype);
    }
#line 1750 "y.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 218 "parser.y"
         {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(vtype, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
    }
#line 1760 "y.tab.c"
    break;

  case 37: /* VarId: ID $@6 TempVarId  */
#line 224 "parser.y"
    {
        (yyval.vitype) = (yyvsp[0].vitype);
    }
#line 1768 "y.tab.c"
    break;

  case 38: /* TempVarId: ArrayList  */
#line 230 "parser.y"
    {
        auto se = identifiers->lookup((yyvsp[0].altype));
        assert(se!=nullptr)
        (yyval.vitype) = new VarId(se,(yyvsp[0].altype));
        (yyval.vitype)->changeinit(true);
        delete [](yyvsp[0].altype);
    }
#line 1780 "y.tab.c"
    break;

  case 39: /* TempVarId: ArrayList ASSIGN InitVal  */
#line 238 "parser.y"
    {
        auto se = identifiers->lookup((yyvsp[-2].altype));
        assert(se!=nullptr)
        (yyval.vitype) = new VarId(se,(yyvsp[-2].altype),(yyvsp[0].ivtype));
        (yyval.vitype)->changeinit(true);
        delete [](yyvsp[-2].altype);
    }
#line 1792 "y.tab.c"
    break;

  case 40: /* InitVal: Exp  */
#line 246 "parser.y"
         {
        (yyval.ivtype) = new InitVal((yyvsp[0].exprtype));
    }
#line 1800 "y.tab.c"
    break;

  case 41: /* InitVal: LBRACE InitVals RBRACE  */
#line 249 "parser.y"
                            {
        (yyval.ivtype) = new InitVal((yyvsp[-1].vivtype)->vals);
    }
#line 1808 "y.tab.c"
    break;

  case 42: /* InitVal: LBRACE RBRACE  */
#line 252 "parser.y"
                   {
        (yyval.ivtype) = new InitVal();
    }
#line 1816 "y.tab.c"
    break;

  case 43: /* InitVals: InitVal  */
#line 257 "parser.y"
              {
        (yyval.vivtype) = new InitVals();
        (yyval.vivtype)->vals.push_back((yyvsp[0].ivtype));
    }
#line 1825 "y.tab.c"
    break;

  case 44: /* InitVals: InitVals COMMA InitVal  */
#line 261 "parser.y"
                            {
        (yyvsp[-2].vivtype)->vals.push_back((yyvsp[0].ivtype));
        (yyval.vivtype) = (yyvsp[-2].vivtype);
    }
#line 1834 "y.tab.c"
    break;

  case 45: /* ConstInitVal: ConstExp  */
#line 267 "parser.y"
              {
        (yyval.ivtype) = new InitVal((yyvsp[0].exprtype));
    }
#line 1842 "y.tab.c"
    break;

  case 46: /* ConstInitVal: LBRACE ConstInitVals RBRACE  */
#line 270 "parser.y"
                                 {
        (yyval.ivtype) = new InitVal((yyvsp[-1].vivtype)->vals);
    }
#line 1850 "y.tab.c"
    break;

  case 47: /* ConstInitVal: LBRACE RBRACE  */
#line 273 "parser.y"
                   {
        (yyval.ivtype) = new InitVal();
    }
#line 1858 "y.tab.c"
    break;

  case 48: /* ConstInitVals: ConstInitVal  */
#line 278 "parser.y"
                   {
        (yyval.vivtype) = new InitVals();
        (yyval.vivtype)->vals.push_back((yyvsp[0].ivtype));
    }
#line 1867 "y.tab.c"
    break;

  case 49: /* ConstInitVals: ConstInitVals COMMA ConstInitVal  */
#line 282 "parser.y"
                                      {
        (yyvsp[-2].vivtype)->vals.push_back((yyvsp[0].ivtype));
        (yyval.vivtype) = (yyvsp[-2].vivtype);
    }
#line 1876 "y.tab.c"
    break;

  case 50: /* FuncParams: %empty  */
#line 289 "parser.y"
           {
        (yyval.fpstype) = new FuncParams();
    }
#line 1884 "y.tab.c"
    break;

  case 51: /* FuncParams: FuncParam  */
#line 292 "parser.y"
                {
        (yyval.fpstype) = new FuncParams((yyvsp[0].fptype));
    }
#line 1892 "y.tab.c"
    break;

  case 52: /* FuncParams: FuncParams COMMA FuncParam  */
#line 295 "parser.y"
                                {
        (yyvsp[-2].fpstype)->push_back((yyvsp[0].fptype));
        (yyval.fpstype) = (yyvsp[-2].fpstype);
    }
#line 1901 "y.tab.c"
    break;

  case 53: /* FuncParam: BType ID  */
#line 301 "parser.y"
               {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.fptype) = new FuncParam(se);
    }
#line 1912 "y.tab.c"
    break;

  case 54: /* FuncParam: BType ID LBRACKET RBRACKET FArrayList  */
#line 307 "parser.y"
                                           {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-4].type), (yyvsp[-3].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-3].strtype), se);
        (yyval.fptype) = new FuncParam(se,(yyvsp[0].faltype));
        (yyval.fptype)->changearray(true);
    }
#line 1924 "y.tab.c"
    break;

  case 55: /* CallParams: Exp  */
#line 317 "parser.y"
        {
        (yyval.cptype) = new CallParams((yyvsp[0].exprtype));
    }
#line 1932 "y.tab.c"
    break;

  case 56: /* CallParams: CallParams COMMA Exp  */
#line 320 "parser.y"
                          {
        (yyvsp[-2].cptype)->push_back((yyvsp[0].exprtype));
        (yyval.cptype) = (yyvsp[-2].cptype);
    }
#line 1941 "y.tab.c"
    break;

  case 57: /* FArrayList: %empty  */
#line 326 "parser.y"
             { 
        (yyval.faltype) = new FArrayList();
    }
#line 1949 "y.tab.c"
    break;

  case 58: /* FArrayList: FArrayList FArrayNode  */
#line 329 "parser.y"
                              {
        (yyvsp[-1].faltype)->push_back((yyvsp[0].fartype));
        (yyval.faltype) = (yyvsp[-1].faltype);
    }
#line 1958 "y.tab.c"
    break;

  case 59: /* FArrayNode: LBRACKET Exp RBRACKET  */
#line 335 "parser.y"
                            {
        (yyval.fartype) = new FArrayNode((yyvsp[-1].exprtype));
    }
#line 1966 "y.tab.c"
    break;

  case 60: /* ArrayList: %empty  */
#line 340 "parser.y"
             { 
        (yyval.altype) = new ArrayList();
    }
#line 1974 "y.tab.c"
    break;

  case 61: /* ArrayList: ArrayList ArrayNode  */
#line 343 "parser.y"
                            {
        (yyvsp[-1].altype)->push_back((yyvsp[0].artype));
        (yyval.altype) = (yyvsp[-1].altype);
    }
#line 1983 "y.tab.c"
    break;

  case 62: /* ArrayNode: LBRACKET ConstExp RBRACKET  */
#line 349 "parser.y"
                                 {
        (yyval.artype) = new ArrayNode((yyvsp[-1].exprtype));
    }
#line 1991 "y.tab.c"
    break;

  case 63: /* ConstExp: AddExp  */
#line 354 "parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1997 "y.tab.c"
    break;

  case 64: /* AssignStmt: LVal ASSIGN Exp SEMICOLON  */
#line 358 "parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 2005 "y.tab.c"
    break;

  case 65: /* $@7: %empty  */
#line 364 "parser.y"
        {identifiers = new SymbolTable(identifiers);}
#line 2011 "y.tab.c"
    break;

  case 66: /* BlockStmt: LBRACE $@7 Stmts RBRACE  */
#line 366 "parser.y"
        {
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].seqtype));
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 2022 "y.tab.c"
    break;

  case 67: /* BlockStmt: LBRACE RBRACE  */
#line 373 "parser.y"
        {
            (yyval.stmttype) = new CompoundStmt(nullptr);
        }
#line 2030 "y.tab.c"
    break;

  case 68: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 378 "parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 2038 "y.tab.c"
    break;

  case 69: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 381 "parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 2046 "y.tab.c"
    break;

  case 70: /* WhileStmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 386 "parser.y"
                                    {
        (yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 2054 "y.tab.c"
    break;

  case 71: /* ReturnStmt: RETURN Exp SEMICOLON  */
#line 392 "parser.y"
                        {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 2062 "y.tab.c"
    break;

  case 72: /* ReturnStmt: RETURN SEMICOLON  */
#line 395 "parser.y"
                      {
        (yyval.stmttype) = new ReturnStmt(nullptr);
    }
#line 2070 "y.tab.c"
    break;

  case 73: /* Exp: AddExp  */
#line 401 "parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2076 "y.tab.c"
    break;

  case 74: /* Cond: LOrExp  */
#line 405 "parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2082 "y.tab.c"
    break;

  case 75: /* LVal: ID FArrayList  */
#line 408 "parser.y"
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
        delete [](yyvsp[-1].strtype);
    }
#line 2104 "y.tab.c"
    break;

  case 76: /* PrimaryExp: LVal  */
#line 428 "parser.y"
         {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2112 "y.tab.c"
    break;

  case 77: /* PrimaryExp: INTEGER  */
#line 431 "parser.y"
              {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new IntSymbolEntry(std::stoi(temp, 0, 10));
        (yyval.exprtype) = new Int(se);
    }
#line 2122 "y.tab.c"
    break;

  case 78: /* PrimaryExp: OCTAL  */
#line 436 "parser.y"
            {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new IntSymbolEntry(std::stoi(temp, 0, 8));
        (yyval.exprtype) = new Int(se);
    }
#line 2132 "y.tab.c"
    break;

  case 79: /* PrimaryExp: HEX  */
#line 441 "parser.y"
          {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new IntSymbolEntry(std::stoi(temp.substr(2), 0, 16));
        (yyval.exprtype) = new Int(se);
    }
#line 2142 "y.tab.c"
    break;

  case 80: /* PrimaryExp: FLT  */
#line 446 "parser.y"
          {
        std::string temp = (yyvsp[0].strtype);
        SymbolEntry *se = new FloatSymbolEntry(std::stof(temp));
        (yyval.exprtype) = new Float(se);
    }
#line 2152 "y.tab.c"
    break;

  case 81: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 451 "parser.y"
                        {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 2160 "y.tab.c"
    break;

  case 82: /* UnaryExp: PrimaryExp  */
#line 457 "parser.y"
               {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2168 "y.tab.c"
    break;

  case 83: /* UnaryExp: ID LPAREN RPAREN  */
#line 460 "parser.y"
                       {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        auto tse = identifiers->lookup((yyvsp[-2].strtype));
        assert(tse != nullptr);
        SymbolEntry *se = new TemporarySymbolEntry(dynamic_cast<FunctionType*>(tse->getType())->getReturn(), SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se,nullptr);
    }
#line 2184 "y.tab.c"
    break;

  case 84: /* UnaryExp: ID LPAREN CallParams RPAREN  */
#line 471 "parser.y"
                                  {
        if(!issysinit)
        {
            initsys();
            issysinit = true;
        }
        auto tse = identifiers->lookup((yyvsp[-3].strtype));
        assert(tse != nullptr);
        SymbolEntry *se = new TemporarySymbolEntry(dynamic_cast<FunctionType*>(tse->getType())->getReturn(), SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se,(yyvsp[-1].cptype));
    }
#line 2200 "y.tab.c"
    break;

  case 85: /* UnaryExp: ADD UnaryExp  */
#line 482 "parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::ADD, (yyvsp[0].exprtype));
    }
#line 2209 "y.tab.c"
    break;

  case 86: /* UnaryExp: SUB UnaryExp  */
#line 486 "parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::SUB, (yyvsp[0].exprtype));
    }
#line 2218 "y.tab.c"
    break;

  case 87: /* UnaryExp: NOT UnaryExp  */
#line 490 "parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::NOT, (yyvsp[0].exprtype));
    }
#line 2227 "y.tab.c"
    break;

  case 88: /* MulExp: UnaryExp  */
#line 497 "parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2233 "y.tab.c"
    break;

  case 89: /* MulExp: MulExp MUL UnaryExp  */
#line 500 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[-2].exprtype)->isInteger()&&(yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2242 "y.tab.c"
    break;

  case 90: /* MulExp: MulExp DIV UnaryExp  */
#line 506 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[-2].exprtype)->isInteger()&&(yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2251 "y.tab.c"
    break;

  case 91: /* MulExp: MulExp MOD UnaryExp  */
#line 512 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2260 "y.tab.c"
    break;

  case 92: /* AddExp: MulExp  */
#line 519 "parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2266 "y.tab.c"
    break;

  case 93: /* AddExp: AddExp ADD MulExp  */
#line 522 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[-2].exprtype)->isInteger()&&(yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2275 "y.tab.c"
    break;

  case 94: /* AddExp: AddExp SUB MulExp  */
#line 528 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(((yyvsp[-2].exprtype)->isInteger()&&(yyvsp[0].exprtype)->isInteger())?TypeSystem::intType:TypeSystem::floatType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2284 "y.tab.c"
    break;

  case 95: /* RelExp: AddExp  */
#line 535 "parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2290 "y.tab.c"
    break;

  case 96: /* RelExp: RelExp LESS AddExp  */
#line 538 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2299 "y.tab.c"
    break;

  case 97: /* RelExp: RelExp GREATER AddExp  */
#line 544 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2308 "y.tab.c"
    break;

  case 98: /* RelExp: RelExp NGREATER AddExp  */
#line 550 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NGREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2317 "y.tab.c"
    break;

  case 99: /* RelExp: RelExp NLESS AddExp  */
#line 556 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NLESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2326 "y.tab.c"
    break;

  case 100: /* EqExp: RelExp  */
#line 563 "parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2332 "y.tab.c"
    break;

  case 101: /* EqExp: EqExp EQUAL RelExp  */
#line 566 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2341 "y.tab.c"
    break;

  case 102: /* EqExp: EqExp NEQUAL RelExp  */
#line 572 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NEQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2350 "y.tab.c"
    break;

  case 103: /* LAndExp: EqExp  */
#line 579 "parser.y"
          {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2356 "y.tab.c"
    break;

  case 104: /* LAndExp: LAndExp LAND EqExp  */
#line 582 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LAND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2365 "y.tab.c"
    break;

  case 105: /* LOrExp: LAndExp  */
#line 589 "parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2371 "y.tab.c"
    break;

  case 106: /* LOrExp: LOrExp LOR LAndExp  */
#line 592 "parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LOR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2380 "y.tab.c"
    break;


#line 2384 "y.tab.c"

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

#line 597 "parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
