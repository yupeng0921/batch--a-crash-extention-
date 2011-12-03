%{
#include "batch.h"
%}

digit		[0-9]
xdigit		[0-9a-fA-F]

dec_long	0|[1-9]{digit}*
hex_long	0(x|X){xdigit}+

letter		[a-zA-Z_]
variable	{letter}({letter}|{digit})*
string		\"[^"\n]*["\n]

comment		(\/\/.*\n)|(\#.*\n)
%%
                char *s, *v;

"while"		return WHILE;
"if"		return IF;
"else"		return ELSE;
"print"		return PRINT;

"call"		return CALL;
"get"		return GET;
"lines"		return LINES;
"len"		return LEN;
"str2long"	return STR2LONG;
"long2decstr"	return LONG2DECSTR;
"long2hexstr"	return LONG2HEXSTR;

{string}	{
			s = strdup(yytext+1);
			if (s[yyleng-2] != '"')
			   fprintf(stderr, "improperly terminated string");
			else
				s[yyleng-2] = 0;
			yylval.pStr = s;
			return STRING;
		}

{variable}	{
			v = malloc(yyleng+1);
			strncpy(v, yytext, yyleng);
			v[yyleng] = '\0';
			yylval.pStr = v;
			return VARIABLE;
		}

{dec_long}	{
			yylval.iValue = STR_TO_LONG(yytext);
			return INTEGER;
		}

{hex_long}	{
			int i = 2;
			LONG val = 0;
			while (i < yyleng) {
			      if (islower(yytext[i])) val = (val<<4) + yytext[i] - 'a' + 10;
			      else if (isupper(yytext[i])) val = (val<<4) + yytext[i] - 'A' + 10;
			      else val = (val<<4) + yytext[i] - '0';
			      i++;
			}
			yylval.iValue = val;
			return INTEGER;
		}

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"&&"            return AND;
"||"            return OR;
"++"            return PP;
"--"            return SS;

[-()<>=+*/{}.;,%]	return *yytext;

[ \t]+          ;       /* ignore whitespace */
\n              { yylineno++; }
{comment}	{ yylineno++; }
.               yyerror("Unknown character");

%%
int yywrap(void) 
{
    return 1;
}
