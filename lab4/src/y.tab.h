/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 55 "y.tab.h"

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

#line 180 "y.tab.h"

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
