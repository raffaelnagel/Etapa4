#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20121003

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "parser.y"
 
#include "ast.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#line 74 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union  
  {
  ast *ast;
  HASH* symbol;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 39 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_WORD 257
#define KW_BOOL 258
#define KW_BYTE 259
#define KW_IF 260
#define KW_THEN 261
#define KW_ELSE 262
#define KW_LOOP 263
#define KW_INPUT 264
#define KW_OUTPUT 265
#define KW_RETURN 266
#define OPERATOR_LE 267
#define OPERATOR_GE 268
#define OPERATOR_EQ 269
#define OPERATOR_NE 270
#define OPERATOR_AND 271
#define OPERATOR_OR 272
#define TK_IDENTIFIER 273
#define LIT_INTEGER 274
#define LIT_TRUE 275
#define LIT_FALSE 276
#define LIT_CHAR 277
#define LIT_STRING 278
#define TOKEN_ERROR 279
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   19,   19,   19,   19,   18,   16,   17,   20,
   21,   21,   22,   22,   15,   15,   25,   25,   26,   26,
   27,   27,    4,    3,    3,    8,    8,    8,    8,    8,
    8,   12,    9,    9,    2,   10,   23,   23,   24,   24,
    6,    7,    7,    7,    5,   11,   11,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,   31,
   31,   28,   28,   29,   30,   30,   14,   14,   14,   14,
   13,   13,   13,
};
static const short yylen[] = {                            2,
    2,    0,    3,    3,    3,    0,    3,    4,    5,    6,
    2,    0,    1,    2,    6,    0,    1,    0,    4,    3,
    2,    0,    3,    2,    0,    1,    1,    1,    1,    1,
    1,    2,    3,    0,    3,    2,    2,    2,    2,    0,
    6,    1,    1,    1,    2,    3,    0,    2,    2,    2,
    1,    1,    1,    1,    4,    4,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    1,    0,    2,    2,    0,    1,    1,    1,    1,
    1,    1,    1,
};
static const short yydefred[] = {                         2,
    6,    1,    0,   81,   82,   83,    0,    0,    0,    0,
    0,    0,    0,    7,    3,    4,    5,    0,    0,    0,
    0,   77,   79,   80,   78,    8,    0,   51,   53,   54,
   52,   71,   70,    0,    0,    0,    0,    0,    0,    0,
   17,    0,    0,    0,   48,   50,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    9,    0,    0,    0,   72,
   57,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,   67,    0,   10,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,   27,   31,   30,   29,   15,
   26,   28,   46,    0,   74,   55,   13,    0,   56,   21,
   19,    0,    0,    0,    0,   36,    0,    0,    0,    0,
   75,   14,    0,   33,    0,   37,   38,   23,    0,   24,
    0,    0,   39,   32,   42,   43,   44,    0,   41,
};
static const short yydgoto[] = {                          1,
   95,   96,  118,   97,   98,   99,  138,  119,  101,  102,
   45,  130,   39,   26,    8,    9,   10,    2,    3,   11,
   85,  108,  116,  126,   40,   41,   88,   69,   70,  105,
   38,
};
static const short yysindex[] = {                         0,
    0,    0, -121,    0,    0,    0,  -21,  -58,  -51,  -49,
  -32,  -36, -250,    0,    0,    0,    0,  -54,  -19, -121,
  -29,    0,    0,    0,    0,    0,  -12,    0,    0,    0,
    0,    0,    0, -242, -241,  -19,  125,   -2,  -20,    4,
    0,  -54,  -19,  -19,    0,    0,    0,   27,  -19,  -19,
  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
  -11,  -19,   -3, -217,  -27,    0,  135,  157,   16,    0,
    0,  106,  106,  106,  106,  338,  338,  106,  106,  -17,
  -17,    0,    0,  -54,    0,   35, -121,    0,   -3,   23,
 -202,  -33,  -19,  -27,  147,    0,    0,    0,    0,    0,
    0,    0,    0,  -19,    0,    0,    0,  -54,    0,    0,
    0,  -19,  -18,   37,  169,    0,  304,  -42,   25,  -19,
    0,    0,   58,    0,  -33,    0,    0,    0,  -27,    0,
  304,  -37,    0,    0,    0,    0,    0,  -27,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,  -49,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   52,
    0,    0,    0,    0,    0,    0,   -8,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,   69,    0,   55,    0,    0,   70,    0,    0,
    0,   47,   63,   68,   72,   82,   91,   98,  103,   -1,
    5,    0,    0,    0,    0,    0,    0,    0,   69,    0,
    0,    0,    0,  -35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   56,    0,    0,
    0,    0,   60,   62,   62,    0,   66,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -35,    0,
   71,    0,    0,    0,    0,    0,    0,   55,    0,
};
static const short yygindex[] = {                         0,
  411,    0,   17,    0,    0,    0,    0,  -63,    0,    0,
   15,    0,  114,  -22,    0,    0,    0,    0,    0,    0,
    0,    0,    9,   30,    0,   67,   74,    0,   51,    0,
    0,
};
#define YYTABLESIZE 608
static const short yytable[] = {                         33,
   14,  100,   34,   20,   35,   33,   36,   15,   34,   16,
   35,   32,   36,   33,   13,   64,   34,   32,   35,   66,
   36,   18,   21,   34,   59,   32,   17,   44,   42,   60,
   46,   47,   47,   47,   47,   47,   47,   62,   47,   64,
   87,   64,   64,   64,   65,   65,   84,   65,   65,   65,
   47,   47,   47,   47,   19,   89,  106,   64,   64,   64,
   64,  107,  112,   65,   65,   65,   65,   71,   59,   57,
  113,   58,   43,   60,  139,  109,   59,   57,   43,   58,
  125,   60,  128,  129,   47,  122,   55,   58,   56,   25,
   58,   64,   18,   73,   55,   94,   56,   65,  132,   59,
   57,   12,   58,   59,   60,   58,   59,   58,   60,   22,
   76,   60,   61,   34,   11,   61,    7,   55,   47,   56,
   40,   59,   62,   59,   45,   62,   60,  124,   60,   35,
   61,   63,   61,  133,   63,    4,    5,    6,   69,   58,
   62,   69,   62,   68,  127,  134,   68,   59,   57,   63,
   58,   63,   60,  110,  121,   59,   69,    0,   69,    0,
   60,   68,  111,   68,   61,    0,   59,   57,    0,   58,
    0,   60,    0,    0,   62,    0,   59,   57,    0,   58,
    0,   60,    0,   63,   55,    0,   56,    0,   59,   57,
   69,   58,    0,   60,   55,   68,   56,    0,   59,   57,
  104,   58,    0,   60,    0,    0,   55,  120,   56,    0,
   59,   57,  125,   58,    0,   60,   55,   61,   56,   22,
   23,   24,   25,  135,  136,  137,    0,  103,   55,    0,
   56,    0,   90,    0,    0,    0,   91,   92,   93,   27,
   28,   29,   30,   31,  114,   27,   28,   29,   30,   31,
    0,   12,   63,   27,   28,   29,   30,   31,   47,   47,
   47,   47,   47,   47,    0,   64,   64,   64,   64,   64,
   64,   65,   65,   65,   65,   65,   65,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   49,   50,   51,   52,   53,   54,    0,
    0,   49,   50,   51,   52,   53,   54,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   58,   58,    0,
    0,    0,    0,    0,   49,   50,   51,   52,   53,   54,
    0,    0,    0,   59,   59,    0,    0,    0,   60,   60,
    0,    0,   61,   61,    0,   59,   57,    0,   58,    0,
   60,    0,   62,   62,    0,    0,    0,    0,    0,    0,
    0,   63,   63,   55,    0,   56,    0,    0,   69,   69,
    0,    0,    0,   68,   68,    0,    0,    0,    0,   59,
   57,    0,   58,    0,   60,    0,    0,    0,    0,    0,
    0,   49,   50,   51,   52,   53,   54,   55,    0,   56,
    0,   49,   50,   51,   52,   53,   54,    0,    0,    0,
    0,    0,    0,   49,   50,   51,   52,   53,   54,    0,
    0,    0,    0,   49,   50,   51,   52,   53,   54,   37,
    0,    0,    0,    0,    0,   49,   50,   51,   52,   53,
   54,    0,    0,    0,    0,    0,   48,    0,    0,    0,
    0,    0,    0,   67,   68,    0,    0,    0,    0,   72,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
   83,    0,   86,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  115,  117,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   68,    0,    0,    0,    0,    0,
    0,    0,  123,    0,    0,    0,    0,    0,    0,    0,
  131,    0,    0,    0,    0,  115,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   50,   51,   52,   53,   54,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   50,   51,   52,
};
static const short yycheck[] = {                         33,
   59,   65,   36,   40,   38,   33,   40,   59,   36,   59,
   38,   45,   40,   33,   36,   36,   36,   45,   38,   42,
   40,   58,  273,   59,   42,   45,   59,   40,   58,   47,
  273,  273,   41,   42,   43,   44,   45,   40,   47,   41,
   44,   43,   44,   45,   41,   41,   58,   43,   44,   45,
   59,   60,   61,   62,   91,  273,   41,   59,   60,   61,
   62,   84,   40,   59,   60,   61,   62,   41,   42,   43,
  273,   45,   91,   47,  138,   41,   42,   43,   91,   45,
   44,   47,  125,   59,   93,  108,   60,   41,   62,  125,
   44,   93,   41,   41,   60,  123,   62,   93,   41,   42,
   43,   59,   45,   41,   47,   59,   44,   61,   41,   41,
   41,   44,   41,   59,   59,   44,    3,   60,   59,   62,
   59,   59,   41,   61,   59,   44,   59,  113,   61,   59,
   59,   41,   61,  125,   44,  257,  258,  259,   41,   93,
   59,   44,   61,   41,  115,  129,   44,   42,   43,   59,
   45,   61,   47,   87,  104,   93,   59,   -1,   61,   -1,
   93,   59,   89,   61,   93,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   93,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   93,   60,   -1,   62,   -1,   42,   43,
   93,   45,   -1,   47,   60,   93,   62,   -1,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   60,   61,   62,   -1,
   42,   43,   44,   45,   -1,   47,   60,   93,   62,  274,
  275,  276,  277,  261,  262,  263,   -1,   93,   60,   -1,
   62,   -1,  260,   -1,   -1,   -1,  264,  265,  266,  273,
  274,  275,  276,  277,  278,  273,  274,  275,  276,  277,
   -1,  273,  273,  273,  274,  275,  276,  277,  267,  268,
  269,  270,  271,  272,   -1,  267,  268,  269,  270,  271,
  272,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,  272,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,  271,  272,   -1,   -1,   -1,  271,  272,
   -1,   -1,  271,  272,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,  272,   60,   -1,   62,   -1,   -1,  271,  272,
   -1,   -1,   -1,  271,  272,   -1,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,  270,  271,  272,   60,   -1,   62,
   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   19,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,
  272,   -1,   -1,   -1,   -1,   -1,   36,   -1,   -1,   -1,
   -1,   -1,   -1,   43,   44,   -1,   -1,   -1,   -1,   49,
   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   92,   93,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  104,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  112,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  120,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 279
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,"'$'",0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_WORD","KW_BOOL","KW_BYTE",
"KW_IF","KW_THEN","KW_ELSE","KW_LOOP","KW_INPUT","KW_OUTPUT","KW_RETURN",
"OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND",
"OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_TRUE","LIT_FALSE","LIT_CHAR",
"LIT_STRING","TOKEN_ERROR",
};
static const char *yyrule[] = {
"$accept : program",
"program : program DECLARACAO",
"program :",
"DECLARACAOVAR : DECLARACAOVAR DECLARACAONORMAL ';'",
"DECLARACAOVAR : DECLARACAOVAR DECLARACAOPOINT ';'",
"DECLARACAOVAR : DECLARACAOVAR DECLARACAOARRAY ';'",
"DECLARACAOVAR :",
"DECLARACAO : DECLARACAOVAR DECLARACAOFUNC ';'",
"DECLARACAONORMAL : TIPO TK_IDENTIFIER ':' LIT",
"DECLARACAOPOINT : TIPO '$' TK_IDENTIFIER ':' LIT",
"DECLARACAOARRAY : TIPO TK_IDENTIFIER '[' EXPR ']' ATRIBDECLARACAOARRAY",
"ATRIBDECLARACAOARRAY : ':' VARLIT",
"ATRIBDECLARACAOARRAY :",
"VARLIT : LIT",
"VARLIT : VARLIT LIT",
"DECLARACAOFUNC : TIPO TK_IDENTIFIER '(' DECLARACAOPARAMFUNC ')' CMD",
"DECLARACAOFUNC :",
"DECLARACAOPARAMFUNC : LISTPARAM",
"DECLARACAOPARAMFUNC :",
"LISTPARAM : TIPO '$' TK_IDENTIFIER RESTLISTPARAM",
"LISTPARAM : TIPO TK_IDENTIFIER RESTLISTPARAM",
"RESTLISTPARAM : ',' LISTPARAM",
"RESTLISTPARAM :",
"BLOCO : '{' LISTCMD '}'",
"LISTCMD : CMD RESTCMD",
"LISTCMD :",
"CMD : IN",
"CMD : ATRIB",
"CMD : OUT",
"CMD : IF",
"CMD : RETURN",
"CMD : BLOCO",
"RESTCMD : ';' LISTCMD",
"IN : KW_INPUT TK_IDENTIFIER VETOR",
"IN :",
"ATRIB : EXPR '=' EXPR",
"OUT : KW_OUTPUT OUTARGS",
"OUTARGS : LIT_STRING RESTARGSOUT",
"OUTARGS : EXPR RESTARGSOUT",
"RESTARGSOUT : ',' OUTARGS",
"RESTARGSOUT :",
"IF : KW_IF '(' EXPR ')' IFCMD CMD",
"IFCMD : KW_THEN",
"IFCMD : KW_ELSE",
"IFCMD : KW_LOOP",
"RETURN : KW_RETURN EXPR",
"VETOR : '[' EXPR ']'",
"VETOR :",
"EXPR : TK_IDENTIFIER VETOR",
"EXPR : '&' TK_IDENTIFIER",
"EXPR : '$' TK_IDENTIFIER",
"EXPR : LIT_INTEGER",
"EXPR : LIT_CHAR",
"EXPR : LIT_TRUE",
"EXPR : LIT_FALSE",
"EXPR : TK_IDENTIFIER '(' VALLIST ')'",
"EXPR : NEG '(' EXPR ')'",
"EXPR : '(' EXPR ')'",
"EXPR : EXPR OPERATOR_LE EXPR",
"EXPR : EXPR OPERATOR_GE EXPR",
"EXPR : EXPR OPERATOR_EQ EXPR",
"EXPR : EXPR OPERATOR_NE EXPR",
"EXPR : EXPR OPERATOR_AND EXPR",
"EXPR : EXPR OPERATOR_OR EXPR",
"EXPR : EXPR '+' EXPR",
"EXPR : EXPR '-' EXPR",
"EXPR : EXPR '*' EXPR",
"EXPR : EXPR '/' EXPR",
"EXPR : EXPR '>' EXPR",
"EXPR : EXPR '<' EXPR",
"NEG : '!'",
"NEG : '-'",
"VALLIST : PARAM",
"VALLIST :",
"PARAM : EXPR RESTPARAM",
"RESTPARAM : ',' PARAM",
"RESTPARAM :",
"LIT : LIT_INTEGER",
"LIT : LIT_CHAR",
"LIT : LIT_TRUE",
"LIT : LIT_FALSE",
"TIPO : KW_WORD",
"TIPO : KW_BOOL",
"TIPO : KW_BYTE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 257 "parser.y"
int yyerror( char* str)
 {
 fprintf(stderr,"ERROR ");
 printf ("Sintax error, line %d\n", getLineNumber());
 exit(3);
 return 0;
 }
#line 456 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 89 "parser.y"
	{printf("OK\n");
				yyval.ast= astCreate(AST_PROGRAM,0,yystack.l_mark[0].ast,0,0,0);
				astPrintTree(yyval.ast,0);
				printf("descompilando \n");
				decompile(yyval.ast);
				printf("setando tipos \n");
				astSetDeclarations(yyval.ast);
				printf("testando tipos\n");
				astCheckDeclarations(yyval.ast);
				printf("verificando natureza dos dados\n");
				astCheckNature(yyval.ast);
				}
break;
case 2:
#line 101 "parser.y"
	{yyval.ast=0;}
break;
case 3:
#line 104 "parser.y"
	{yyval.ast=astCreate(AST_DEC,0,yystack.l_mark[-2].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 4:
#line 105 "parser.y"
	{yyval.ast=astCreate(AST_DEC,0,yystack.l_mark[-2].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 5:
#line 106 "parser.y"
	{yyval.ast=astCreate(AST_DEC,0,yystack.l_mark[-2].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 6:
#line 107 "parser.y"
	{yyval.ast=0;}
break;
case 7:
#line 110 "parser.y"
	{yyval.ast=astCreate(AST_DECLARACAO,0,yystack.l_mark[-2].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 8:
#line 113 "parser.y"
	{yyval.ast=astCreate(AST_NDEC,yystack.l_mark[-2].symbol,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0);}
break;
case 9:
#line 116 "parser.y"
	{yyval.ast=astCreate(AST_POINTER_DEC,yystack.l_mark[-2].symbol,yystack.l_mark[-4].ast,yystack.l_mark[0].ast,0,0);}
break;
case 10:
#line 119 "parser.y"
	{yyval.ast=astCreate(AST_ARRAY_DEC,yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 11:
#line 123 "parser.y"
	{yyval.ast= yystack.l_mark[0].ast;}
break;
case 12:
#line 124 "parser.y"
	{yyval.ast=0;}
break;
case 13:
#line 127 "parser.y"
	{yyval.ast= astCreate(AST_LIT_ATRIB,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 14:
#line 128 "parser.y"
	{yyval.ast= astCreate(AST_LIT_ATRIB,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 15:
#line 132 "parser.y"
	{yyval.ast=astCreate(AST_FUN_DEF,yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 16:
#line 133 "parser.y"
	{yyval.ast=0;}
break;
case 17:
#line 136 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 18:
#line 137 "parser.y"
	{yyval.ast=0;}
break;
case 19:
#line 140 "parser.y"
	{yyval.ast=astCreate(AST_POINTER_DEC,yystack.l_mark[-1].symbol,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0);}
break;
case 20:
#line 141 "parser.y"
	{yyval.ast=astCreate(AST_NDEC,yystack.l_mark[-1].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 21:
#line 145 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 22:
#line 146 "parser.y"
	{yyval.ast=0;}
break;
case 23:
#line 150 "parser.y"
	{yyval.ast= astCreate(AST_BLOCO,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 24:
#line 153 "parser.y"
	{yyval.ast= astCreate(AST_LISTCMD,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 25:
#line 154 "parser.y"
	{yyval.ast=0;}
break;
case 26:
#line 157 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 27:
#line 158 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 28:
#line 159 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 29:
#line 160 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 30:
#line 161 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 31:
#line 162 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 32:
#line 165 "parser.y"
	{yyval.ast= astCreate(AST_LISTCMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 33:
#line 168 "parser.y"
	{yyval.ast= astCreate(AST_IN,yystack.l_mark[-1].symbol,0,yystack.l_mark[0].ast,0,0);}
break;
case 34:
#line 169 "parser.y"
	{yyval.ast=0;}
break;
case 35:
#line 173 "parser.y"
	{yyval.ast=astCreate(AST_ATRIB,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 36:
#line 176 "parser.y"
	{yyval.ast= astCreate(AST_OUT,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 37:
#line 179 "parser.y"
	{yyval.ast=astCreate(AST_OUTARGS_STRING,yystack.l_mark[-1].symbol,0,yystack.l_mark[0].ast,0,0);}
break;
case 38:
#line 180 "parser.y"
	{yyval.ast=astCreate(AST_OUTARGS_EXPR,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 39:
#line 183 "parser.y"
	{yyval.ast= yystack.l_mark[0].ast;}
break;
case 40:
#line 184 "parser.y"
	{yyval.ast=0;}
break;
case 41:
#line 187 "parser.y"
	{yyval.ast=astCreate(AST_IF,0,yystack.l_mark[-3].ast,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0);}
break;
case 42:
#line 190 "parser.y"
	{yyval.ast=astCreate(AST_CMD_THEN,0,0,0,0,0);}
break;
case 43:
#line 191 "parser.y"
	{yyval.ast=astCreate(AST_CMD_ELSE,0,0,0,0,0);}
break;
case 44:
#line 192 "parser.y"
	{yyval.ast=astCreate(AST_CMD_LOOP,0,0,0,0,0);}
break;
case 45:
#line 195 "parser.y"
	{yyval.ast=astCreate(AST_RETURN,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 46:
#line 200 "parser.y"
	{yyval.ast=astCreate(AST_INDEX,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 47:
#line 201 "parser.y"
	{yyval.ast=0;}
break;
case 48:
#line 204 "parser.y"
	{yyval.ast=astCreate(AST_VETOR,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 49:
#line 205 "parser.y"
	{yyval.ast=astCreate(AST_REFERENCE,yystack.l_mark[0].symbol, 0,0,0,0);}
break;
case 50:
#line 206 "parser.y"
	{yyval.ast=astCreate(AST_DE_REFERENCE,yystack.l_mark[0].symbol, 0,0,0,0);}
break;
case 51:
#line 207 "parser.y"
	{yyval.ast=astCreate(AST_LIT_INTEGER,yystack.l_mark[0].symbol, 0,0,0,0);}
break;
case 52:
#line 208 "parser.y"
	{yyval.ast=astCreate(AST_LIT_CHAR,yystack.l_mark[0].symbol, 0,0,0,0);}
break;
case 53:
#line 209 "parser.y"
	{yyval.ast=astCreate(AST_LIT_TRUE,yystack.l_mark[0].symbol, 0,0,0,0);}
break;
case 54:
#line 210 "parser.y"
	{yyval.ast=astCreate(AST_LIT_FALSE,yystack.l_mark[0].symbol, 0,0,0,0);}
break;
case 55:
#line 211 "parser.y"
	{yyval.ast= astCreate(AST_FUNC_CALL,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0);}
break;
case 56:
#line 212 "parser.y"
	{yyval.ast= astCreate(AST_NEG_EXPR,0,yystack.l_mark[-3].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 57:
#line 213 "parser.y"
	{yyval.ast=astCreate(AST_PAR_EXPR,0,0,yystack.l_mark[-1].ast,0,0);}
break;
case 58:
#line 214 "parser.y"
	{yyval.ast=astCreate(AST_LE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 59:
#line 215 "parser.y"
	{yyval.ast=astCreate(AST_GE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 60:
#line 216 "parser.y"
	{yyval.ast=astCreate(AST_EQ,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 61:
#line 217 "parser.y"
	{yyval.ast=astCreate(AST_NE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 62:
#line 218 "parser.y"
	{yyval.ast=astCreate(AST_AND,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 63:
#line 219 "parser.y"
	{yyval.ast=astCreate(AST_OR,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 64:
#line 220 "parser.y"
	{yyval.ast=astCreate(AST_ADD,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 65:
#line 221 "parser.y"
	{yyval.ast=astCreate(AST_SUB,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 66:
#line 222 "parser.y"
	{yyval.ast=astCreate(AST_MUL,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 67:
#line 223 "parser.y"
	{yyval.ast=astCreate(AST_DIV,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 68:
#line 224 "parser.y"
	{yyval.ast=astCreate(AST_GREATER,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 69:
#line 225 "parser.y"
	{yyval.ast=astCreate(AST_LESS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 70:
#line 228 "parser.y"
	{yyval.ast=astCreate(AST_BOOLEAN_NEG,0,0,0,0,0);}
break;
case 71:
#line 229 "parser.y"
	{yyval.ast=astCreate(AST_ARIT_NEG,0,0,0,0,0);}
break;
case 72:
#line 232 "parser.y"
	{yyval.ast=yystack.l_mark[0].ast;}
break;
case 73:
#line 233 "parser.y"
	{yyval.ast=0;}
break;
case 74:
#line 236 "parser.y"
	{yyval.ast=astCreate(AST_PASS_PARAM,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 75:
#line 239 "parser.y"
	{yyval.ast=astCreate(AST_PASS_PARAM,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 76:
#line 240 "parser.y"
	{yyval.ast=0;}
break;
case 77:
#line 243 "parser.y"
	{yyval.ast=astCreate(AST_LIT_INTEGER,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 78:
#line 244 "parser.y"
	{yyval.ast=astCreate(AST_LIT_CHAR,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 79:
#line 245 "parser.y"
	{yyval.ast=astCreate(AST_LIT_TRUE,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 80:
#line 246 "parser.y"
	{yyval.ast=astCreate(AST_LIT_FALSE,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 81:
#line 250 "parser.y"
	{yyval.ast=astCreate(AST_WORD,0,0,0,0,0);}
break;
case 82:
#line 251 "parser.y"
	{yyval.ast=astCreate(AST_BOOL,0,0,0,0,0);}
break;
case 83:
#line 252 "parser.y"
	{yyval.ast=astCreate(AST_BYTE,0,0,0,0,0);}
break;
#line 1005 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
