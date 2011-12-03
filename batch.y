%{
#include "batch.h"
%}

%union {
       LONG iValue;
       char *pStr;
       nodeType *nPtr;
};

%token <iValue> INTEGER
%token <pStr> VARIABLE
%token <pStr> STRING CALL
%token <pStr> GET
%token <iValue> LINES LEN STR2LONG
%token <pStr> LONG2DECSTR LONG2HEXSTR

%type <nPtr> stmt expr stmt_list function

%token WHILE IF PRINT

%nonassoc IFX
%nonassoc ELSE

%left OR
%left AND
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%left PP SS
%nonassoc UMINUS

%%
program:
	init parsed	{ freeSymTable(); }
	;
init: /* NULL*/             { yylineno = 0; initSymTable();}
  ;
parsed:
    parsed stmt             { free_itpType(interpret($2)); freeNode($2); }
  | parsed error separator  { fprintf(stdout, "error!!\n"); yyerrok; }
  | /* NULL */
  ;

stmt:
    separator               { $$ = opr(';', 2, NULL, NULL);  }
  | expr separator          { $$ = opr(PRINT, 1, $1); }
  | PRINT expr separator    { $$ = opr(PRINT, 1, $2); }
  | VARIABLE '=' expr separator     { $$ = (($3 == NULL)?NULL:(symname_install($1),opr('=', 2, var($1), $3)));}
  | WHILE '(' expr ')' stmt         { $$ = opr(WHILE, 2, $3, $5);  }
  | IF '(' expr ')' stmt %prec IFX  { $$ = opr(IF, 2, $3, $5); }
  | IF '(' expr ')' stmt ELSE stmt  { $$ = opr(IF, 3, $3, $5, $7); }
  | '{' stmt_list '}'       { $$ = $2; }
  ;

stmt_list:
    stmt                    { $$ = $1; }
  | stmt_list stmt          { $$ = opr(';', 2, $1, $2); }
  ;

separator:
    ';'
  ;

expr:
    INTEGER                 { $$ = con_long($1); }
  | STRING                  { $$ = con_str($1); }
  | VARIABLE                { $$ = var($1); }
  | '-' expr %prec UMINUS   { $$ = opr(UMINUS, 1, $2); }
  | VARIABLE PP             { $$ = ((var($1)==NULL) ? NULL: opr(PP, 1, var($1))); }
  | VARIABLE SS             { $$ = ((var($1)==NULL) ? NULL: opr(SS, 1, var($1))); }
  | expr '+' expr           { $$ = opr('+', 2, $1, $3); }
  | expr '-' expr           { $$ = opr('-', 2, $1, $3); }
  | expr '*' expr           { $$ = opr('*', 2, $1, $3); }
  | expr '/' expr           { $$ = opr('/', 2, $1, $3); }
  | expr '<' expr           { $$ = opr('<', 2, $1, $3); }
  | expr '>' expr           { $$ = opr('>', 2, $1, $3); }
  | expr '%' expr           { $$ = opr('%', 2, $1, $3); }
  | expr AND expr           { $$ = opr(AND, 2, $1, $3); }
  | expr OR expr            { $$ = opr(OR, 2, $1, $3); }
  | expr GE expr            { $$ = opr(GE, 2, $1, $3); }
  | expr LE expr            { $$ = opr(LE, 2, $1, $3); }
  | expr NE expr            { $$ = opr(NE, 2, $1, $3); }
  | expr EQ expr            { $$ = opr(EQ, 2, $1, $3); }
  | '(' expr ')'            { $$ = $2; }
  | function                { $$ = $1; }
  ;

function:
    CALL '(' expr ')'       { $$ = opr(CALL,1,$3); }
  | GET '(' expr ',' expr ',' expr ',' expr ')' { $$ = opr(GET, 4, $3, $5, $7, $9); }
  | LINES '(' expr ')' { $$ = opr(LINES, 1, $3); }
  | LEN '(' expr ')' { $$ = opr(LEN, 1, $3); }
  | STR2LONG '(' expr ')' { $$ = opr(STR2LONG, 1, $3); }
  | LONG2DECSTR '(' expr ')' { $$ = opr(LONG2DECSTR, 1, $3); }
  | LONG2HEXSTR '(' expr ')' { $$ = opr(LONG2HEXSTR, 1, $3); }
  ;

%%
extern int yylineno;
void yyerror(char *s) 
{
    fprintf(stderr, "line: %d: %s\n", yylineno, s);
}

#include "lex.yy.c"
#include "batch.c" /* routines for parse */
