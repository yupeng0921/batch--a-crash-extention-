#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20100216

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

#line 2 "batch.y"
#include "batch.h"
#line 5 "batch.y"
typedef union {
       LONG iValue;
       char *pStr;
       nodeType *nPtr;
} YYSTYPE;
#line 42 "y.tab.c"
#define INTEGER 257
#define VARIABLE 258
#define STRING 259
#define CALL 260
#define GET 261
#define LINES 262
#define LEN 263
#define STR2LONG 264
#define LONG2DECSTR 265
#define LONG2HEXSTR 266
#define STRPARAM 267
#define LONGPARAM 268
#define WHILE 269
#define IF 270
#define PRINT 271
#define IFX 272
#define ELSE 273
#define OR 274
#define AND 275
#define GE 276
#define LE 277
#define EQ 278
#define NE 279
#define PP 280
#define SS 281
#define UMINUS 282
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    5,    6,    6,    6,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    3,    7,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    4,
    4,    4,    4,    4,    4,    4,
};
static const short yylen[] = {                            2,
    2,    0,    2,    3,    0,    1,    2,    3,    4,    5,
    5,    7,    3,    1,    2,    1,    1,    1,    1,    1,
    1,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    4,
   10,    4,    4,    4,    4,    4,
};
static const short yydefred[] = {                         2,
    0,    5,    0,    0,   17,    0,   18,    0,    0,    0,
    0,    0,    0,    0,   20,   21,    0,    0,    0,    0,
    0,    0,   16,    3,    0,   39,    6,    4,   23,   24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,    0,   14,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,   38,   13,   15,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   27,   28,   31,    9,   40,    0,
   42,   43,   44,   45,   46,    0,    0,    0,   10,    0,
    0,    0,    0,   12,    0,    0,   41,
};
static const short yydgoto[] = {                          1,
   24,   25,   46,   26,    2,    3,   27,
};
static const short yysindex[] = {                         0,
    0,    0,  477,  -47,    0,  -50,    0,  -27,  -22,  -20,
  -16,  -13,  -12,  -11,    0,    0,   -7,   -5,  297,  297,
  297,  507,    0,    0,  -28,    0,    0,    0,    0,    0,
  297,  297,  297,  297,  297,  297,  297,  297,  297,  297,
 -278,  -28,    0,    2,    0,  492,  297,  297,  297,  297,
  297,  297,  297,  297,  297,  297,  297,  297,  297,    0,
  -28,   11,   32,   41,   48,   70,   86,   97,  108,  119,
    0,    0,    0,    0,  174,  291,  256,  256,  256,  256,
  256,  256,  -21,  -21,    0,    0,    0,    0,    0,  297,
    0,    0,    0,    0,    0,  507,  507,  130,    0, -237,
  297,  507,  141,    0,  297,  152,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,   37,    0,    0,  163,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   55,   22,  419,  425,  433,  439,
  445,  453,  402,  413,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  198,  554,    0,    0,    0,    0,   26,
};
#define YYTABLESIZE 778
static const short yytable[] = {                         19,
   11,   29,   30,   19,   19,   19,   19,   19,   59,   19,
   31,   23,   32,   57,   55,   59,   56,   33,   58,   34,
   57,   19,   19,   35,   19,   58,   36,   37,   38,   28,
   23,   54,   39,   53,   40,  102,    1,    0,   59,    0,
   11,    0,   72,   57,   55,   11,   56,   59,   58,    0,
   60,   89,   57,   55,    0,   56,    0,   58,    0,   11,
    0,   54,   32,   53,    0,   32,    0,   71,   59,    0,
   54,    0,   53,   57,   55,   90,   56,   59,   58,    0,
   32,   91,   57,   55,   59,   56,   88,   58,   92,   57,
   55,   54,   56,   53,   58,   33,    0,    0,   33,    0,
   54,    0,   53,    0,    0,    0,   59,   54,    0,   53,
   93,   57,   55,   33,   56,    0,   58,    0,    0,    0,
    0,    0,   59,   11,    0,   11,   94,   57,   55,   54,
   56,   53,   58,   59,    0,    0,    0,   95,   57,   55,
    0,   56,    0,   58,   59,   54,    0,   53,   96,   57,
   55,    0,   56,    0,   58,   59,   54,    0,   53,   97,
   57,   55,    0,   56,    0,   58,   59,   54,    0,   53,
    0,   57,   55,  101,   56,    0,   58,   59,   54,    0,
   53,    0,   57,   55,  105,   56,    0,   58,   59,   54,
    0,   53,  107,   57,   55,    0,   56,    0,   58,   19,
   54,    0,   53,    0,   19,   19,    0,   19,    0,   19,
   59,   54,    0,   53,    0,   57,   55,    0,   56,   45,
   58,   19,   19,    0,   19,    0,    0,    0,    0,   29,
   30,    0,    0,   54,    0,   53,   19,   19,   19,   19,
   19,   19,    0,   74,    0,   47,   48,   49,   50,   51,
   52,    0,    0,    0,    0,    0,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,    0,    0,    0,   47,   48,   49,   50,   51,
   52,    0,    0,    0,   47,   48,   49,   50,   51,   52,
    0,    0,   59,   99,  100,   32,   32,   57,   55,  104,
   56,    0,   58,    0,    0,   47,   48,   49,   50,   51,
   52,    0,    0,    0,   47,   48,   49,   50,   51,   52,
    0,   47,   48,   49,   50,   51,   52,   59,   33,    0,
    0,    0,   57,   55,    0,   56,   21,   58,    0,    0,
    0,   20,    0,   47,   48,   49,   50,   51,   52,    0,
   54,    0,   53,    0,    0,    0,    0,    0,    0,   47,
   48,   49,   50,   51,   52,    0,    0,    0,    0,    0,
   47,   48,   49,   50,   51,   52,    0,    0,    0,    0,
    0,   47,   48,   49,   50,   51,   52,    0,    0,    0,
    0,    0,   47,   48,   49,   50,   51,   52,    0,    0,
    0,    0,    0,   47,   48,   49,   50,   51,   52,    0,
    0,    0,    0,    0,   47,   48,   49,   50,   51,   52,
    0,    0,    0,    0,    0,   47,   48,   49,   50,   51,
   52,    0,    0,    0,    0,    0,   19,   19,   19,   19,
   19,   19,   25,    0,   25,   25,   25,    0,   48,   49,
   50,   51,   52,   26,    0,   26,   26,   26,    0,   34,
   25,   25,   34,   25,    0,   35,    0,    0,   35,    0,
    0,   26,   26,   37,   26,    0,   37,   34,   34,   36,
   34,    0,   36,   35,   35,   30,   35,    0,   30,    0,
    0,   37,   37,   29,   37,    0,   29,   36,   36,    0,
   36,    0,    0,   30,   30,    0,   30,    0,    0,    0,
    0,   29,   29,    0,   29,    0,   21,    0,    0,    0,
    0,   20,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,    0,    0,    0,   23,   20,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,    0,    0,    0,
   23,   20,    0,    5,   41,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   23,   49,   50,   51,   52,
    0,    0,   42,   43,   44,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   61,   62,   63,   64,   65,   66,
   67,   68,   69,   70,    0,    0,    0,    0,    0,   22,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
   85,   86,   87,    0,   22,    0,   73,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   98,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  103,    0,    0,    0,  106,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,   25,   25,   25,   25,
   25,    0,    0,    0,    0,    0,   26,   26,   26,   26,
   26,   26,   34,   34,   34,   34,   34,   34,   35,   35,
   35,   35,   35,   35,    0,    0,   37,   37,   37,   37,
   37,   37,   36,   36,   36,   36,   36,   36,   30,   30,
   30,   30,   30,   30,    0,    0,   29,   29,   29,   29,
   29,   29,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   18,   19,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   18,   19,
};
static const short yycheck[] = {                         37,
    0,  280,  281,   41,   42,   43,   44,   45,   37,   47,
   61,   59,   40,   42,   43,   37,   45,   40,   47,   40,
   42,   59,   60,   40,   62,   47,   40,   40,   40,    4,
   59,   60,   40,   62,   40,  273,    0,   -1,   37,   -1,
   40,   -1,   41,   42,   43,   45,   45,   37,   47,   -1,
   25,   41,   42,   43,   -1,   45,   -1,   47,   -1,   59,
   -1,   60,   41,   62,   -1,   44,   -1,   42,   37,   -1,
   60,   -1,   62,   42,   43,   44,   45,   37,   47,   -1,
   59,   41,   42,   43,   37,   45,   61,   47,   41,   42,
   43,   60,   45,   62,   47,   41,   -1,   -1,   44,   -1,
   60,   -1,   62,   -1,   -1,   -1,   37,   60,   -1,   62,
   41,   42,   43,   59,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   37,  123,   -1,  125,   41,   42,   43,   60,
   45,   62,   47,   37,   -1,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,   37,   60,   -1,   62,   41,   42,
   43,   -1,   45,   -1,   47,   37,   60,   -1,   62,   41,
   42,   43,   -1,   45,   -1,   47,   37,   60,   -1,   62,
   -1,   42,   43,   44,   45,   -1,   47,   37,   60,   -1,
   62,   -1,   42,   43,   44,   45,   -1,   47,   37,   60,
   -1,   62,   41,   42,   43,   -1,   45,   -1,   47,   37,
   60,   -1,   62,   -1,   42,   43,   -1,   45,   -1,   47,
   37,   60,   -1,   62,   -1,   42,   43,   -1,   45,   22,
   47,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,  280,
  281,   -1,   -1,   60,   -1,   62,  274,  275,  276,  277,
  278,  279,   -1,   46,   -1,  274,  275,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,   -1,   -1,   -1,  274,  275,  276,  277,  278,
  279,   -1,   -1,   -1,  274,  275,  276,  277,  278,  279,
   -1,   -1,   37,   96,   97,  274,  275,   42,   43,  102,
   45,   -1,   47,   -1,   -1,  274,  275,  276,  277,  278,
  279,   -1,   -1,   -1,  274,  275,  276,  277,  278,  279,
   -1,  274,  275,  276,  277,  278,  279,   37,  274,   -1,
   -1,   -1,   42,   43,   -1,   45,   40,   47,   -1,   -1,
   -1,   45,   -1,  274,  275,  276,  277,  278,  279,   -1,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
  274,  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,  274,  275,  276,  277,  278,  279,   -1,   -1,   -1,
   -1,   -1,  274,  275,  276,  277,  278,  279,   -1,   -1,
   -1,   -1,   -1,  274,  275,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,  274,  275,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,
  278,  279,   41,   -1,   43,   44,   45,   -1,  275,  276,
  277,  278,  279,   41,   -1,   43,   44,   45,   -1,   41,
   59,   60,   44,   62,   -1,   41,   -1,   -1,   44,   -1,
   -1,   59,   60,   41,   62,   -1,   44,   59,   60,   41,
   62,   -1,   44,   59,   60,   41,   62,   -1,   44,   -1,
   -1,   59,   60,   41,   62,   -1,   44,   59,   60,   -1,
   62,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   40,   -1,   -1,   -1,
   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   -1,   -1,   -1,   59,   45,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,
   59,   45,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,   59,  276,  277,  278,  279,
   -1,   -1,   19,   20,   21,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   31,   32,   33,   34,   35,   36,
   37,   38,   39,   40,   -1,   -1,   -1,   -1,   -1,  123,
   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,
   57,   58,   59,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   90,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  101,   -1,   -1,   -1,  105,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,
  278,  279,  274,  275,  276,  277,  278,  279,  274,  275,
  276,  277,  278,  279,   -1,   -1,  274,  275,  276,  277,
  278,  279,  274,  275,  276,  277,  278,  279,  274,  275,
  276,  277,  278,  279,   -1,   -1,  274,  275,  276,  277,
  278,  279,  256,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"INTEGER","VARIABLE","STRING","CALL","GET","LINES","LEN",
"STR2LONG","LONG2DECSTR","LONG2HEXSTR","STRPARAM","LONGPARAM","WHILE","IF",
"PRINT","IFX","ELSE","OR","AND","GE","LE","EQ","NE","PP","SS","UMINUS",
};
static const char *yyrule[] = {
"$accept : program",
"program : init parsed",
"init :",
"parsed : parsed stmt",
"parsed : parsed error separator",
"parsed :",
"stmt : separator",
"stmt : expr separator",
"stmt : PRINT expr separator",
"stmt : VARIABLE '=' expr separator",
"stmt : WHILE '(' expr ')' stmt",
"stmt : IF '(' expr ')' stmt",
"stmt : IF '(' expr ')' stmt ELSE stmt",
"stmt : '{' stmt_list '}'",
"stmt_list : stmt",
"stmt_list : stmt_list stmt",
"separator : ';'",
"expr : INTEGER",
"expr : STRING",
"expr : VARIABLE",
"expr : STRPARAM",
"expr : LONGPARAM",
"expr : '-' expr",
"expr : VARIABLE PP",
"expr : VARIABLE SS",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '%' expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr EQ expr",
"expr : '(' expr ')'",
"expr : function",
"function : CALL '(' expr ')'",
"function : GET '(' expr ',' expr ',' expr ',' expr ')'",
"function : LINES '(' expr ')'",
"function : LEN '(' expr ')'",
"function : STR2LONG '(' expr ')'",
"function : LONG2DECSTR '(' expr ')'",
"function : LONG2HEXSTR '(' expr ')'",

};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

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

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;

#define YYPURE 0

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 104 "batch.y"
extern int yylineno;
void yyerror(char *s) 
{
    fprintf(stderr, "line: %d: %s\n", yylineno, s);
}

#include "lex.yy.c"
#include "batch.c" /* routines for parse */
#line 409 "y.tab.c"
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
    newss = (data->s_base != 0)
          ? (short *)realloc(data->s_base, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base  = newss;
    data->s_mark = newss + i;

    newvs = (data->l_base != 0)
          ? (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
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
        if ((yychar = yylex()) < 0) yychar = 0;
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
#line 37 "batch.y"
	{ freeSymTable(); }
break;
case 2:
#line 39 "batch.y"
	{ yylineno = 1; initSymTable();}
break;
case 3:
#line 42 "batch.y"
	{ free_itpType(interpret(yystack.l_mark[0].nPtr)); freeNode(yystack.l_mark[0].nPtr); }
break;
case 4:
#line 43 "batch.y"
	{ fprintf(stdout, "error!!\n"); yyerrok; }
break;
case 6:
#line 48 "batch.y"
	{ yyval.nPtr = opr(';', 2, NULL, NULL);  }
break;
case 7:
#line 49 "batch.y"
	{ yyval.nPtr = opr(PRINT, 1, yystack.l_mark[-1].nPtr); }
break;
case 8:
#line 50 "batch.y"
	{ yyval.nPtr = opr(PRINT, 1, yystack.l_mark[-1].nPtr); }
break;
case 9:
#line 51 "batch.y"
	{ int index; yyval.nPtr = ((yystack.l_mark[-1].nPtr == NULL)?NULL:(index = symname_install(yystack.l_mark[-3].pStr),opr('=', 2, var1(index), yystack.l_mark[-1].nPtr)));}
break;
case 10:
#line 52 "batch.y"
	{ yyval.nPtr = opr(WHILE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr);  }
break;
case 11:
#line 53 "batch.y"
	{ yyval.nPtr = opr(IF, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 12:
#line 54 "batch.y"
	{ yyval.nPtr = opr(IF, 3, yystack.l_mark[-4].nPtr, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 13:
#line 55 "batch.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
case 14:
#line 59 "batch.y"
	{ yyval.nPtr = yystack.l_mark[0].nPtr; }
break;
case 15:
#line 60 "batch.y"
	{ yyval.nPtr = opr(';', 2, yystack.l_mark[-1].nPtr, yystack.l_mark[0].nPtr); }
break;
case 17:
#line 68 "batch.y"
	{ yyval.nPtr = con_long(yystack.l_mark[0].iValue); }
break;
case 18:
#line 69 "batch.y"
	{ yyval.nPtr = con_str(yystack.l_mark[0].pStr); }
break;
case 19:
#line 70 "batch.y"
	{ yyval.nPtr = var(yystack.l_mark[0].pStr); }
break;
case 20:
#line 71 "batch.y"
	{ yyval.nPtr = str_param(yystack.l_mark[0].iValue); }
break;
case 21:
#line 72 "batch.y"
	{ yyval.nPtr = long_param(yystack.l_mark[0].iValue); }
break;
case 22:
#line 73 "batch.y"
	{ yyval.nPtr = opr(UMINUS, 1, yystack.l_mark[0].nPtr); }
break;
case 23:
#line 74 "batch.y"
	{ yyval.nPtr = ((var(yystack.l_mark[-1].pStr)==NULL) ? NULL: opr(PP, 1, var(yystack.l_mark[-1].pStr))); }
break;
case 24:
#line 75 "batch.y"
	{ yyval.nPtr = ((var(yystack.l_mark[-1].pStr)==NULL) ? NULL: opr(SS, 1, var(yystack.l_mark[-1].pStr))); }
break;
case 25:
#line 76 "batch.y"
	{ yyval.nPtr = opr('+', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 26:
#line 77 "batch.y"
	{ yyval.nPtr = opr('-', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 27:
#line 78 "batch.y"
	{ yyval.nPtr = opr('*', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 28:
#line 79 "batch.y"
	{ yyval.nPtr = opr('/', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 29:
#line 80 "batch.y"
	{ yyval.nPtr = opr('<', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 30:
#line 81 "batch.y"
	{ yyval.nPtr = opr('>', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 31:
#line 82 "batch.y"
	{ yyval.nPtr = opr('%', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 32:
#line 83 "batch.y"
	{ yyval.nPtr = opr(AND, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 33:
#line 84 "batch.y"
	{ yyval.nPtr = opr(OR, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 34:
#line 85 "batch.y"
	{ yyval.nPtr = opr(GE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 35:
#line 86 "batch.y"
	{ yyval.nPtr = opr(LE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 36:
#line 87 "batch.y"
	{ yyval.nPtr = opr(NE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 37:
#line 88 "batch.y"
	{ yyval.nPtr = opr(EQ, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 38:
#line 89 "batch.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
case 39:
#line 90 "batch.y"
	{ yyval.nPtr = yystack.l_mark[0].nPtr; }
break;
case 40:
#line 94 "batch.y"
	{ yyval.nPtr = opr(CALL,1,yystack.l_mark[-1].nPtr); }
break;
case 41:
#line 95 "batch.y"
	{ yyval.nPtr = opr(GET, 4, yystack.l_mark[-7].nPtr, yystack.l_mark[-5].nPtr, yystack.l_mark[-3].nPtr, yystack.l_mark[-1].nPtr); }
break;
case 42:
#line 96 "batch.y"
	{ yyval.nPtr = opr(LINES, 1, yystack.l_mark[-1].nPtr); }
break;
case 43:
#line 97 "batch.y"
	{ yyval.nPtr = opr(LEN, 1, yystack.l_mark[-1].nPtr); }
break;
case 44:
#line 98 "batch.y"
	{ yyval.nPtr = opr(STR2LONG, 1, yystack.l_mark[-1].nPtr); }
break;
case 45:
#line 99 "batch.y"
	{ yyval.nPtr = opr(LONG2DECSTR, 1, yystack.l_mark[-1].nPtr); }
break;
case 46:
#line 100 "batch.y"
	{ yyval.nPtr = opr(LONG2HEXSTR, 1, yystack.l_mark[-1].nPtr); }
break;
#line 787 "y.tab.c"
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
            if ((yychar = yylex()) < 0) yychar = 0;
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
