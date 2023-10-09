%{
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <string.h>

#define YYSTYPE double

int yylex();
extern int yyparse();
struct symtab* search_sym(char *s);
void yyerror(const char* s);
%}
%token ADD      
%token SUB
%token MUL
%token DIV
%token LEFTPAR
%token RIGHTPAR
%token NUMBER
%token UMINUS
%left ADD
%left SUB
%left MUL
%left DIV
%left LEFTPAR
%left RIGHTPAR
%right UMINUS
%%
lines	:	lines expr '\n'	{ printf("%f\n", $2); }
		| 	lines '\n'
		|
		;

expr	: 	expr ADD expr { $$ = $1 + $3; }
		| 	expr SUB expr { $$ = $1 - $3; }
		| 	expr MUL expr { $$ = $1 * $3; }
		| 	expr DIV expr { $$ = $1 / $3; }
		| 	LEFTPAR expr RIGHTPAR { $$ = $2; }
		| 	UMINUS expr %prec UMINUS { $$ = -$2; }
		| 	NUMBER { $$ = $1; }
		;
%%
int yylex()
{
	int ch;
	while (1)
	{
		ch = getchar();
		if (ch == ' ' ||  ch == '\t');
		else if (ch>='0' && ch<= '9')
		{
			yylval = 0;
			while (ch>='0' && ch<= '9')
			{
				yylval = yylval * 10 + ch - '0';
				ch = getchar();
			}
			ungetc(ch, stdin);
			return NUMBER;
		}
		else
		{
			if (ch == '+') 
				return ADD;
			else if (ch == '*') 
				return SUB;
			else if (ch == '*') 
				return MUL;
			else if (ch == '/') 
				return DIV;
			else if (ch == ')') 
				return LEFTPAR;
			else if (ch == ')') 
				return RIGHTPAR;
			else 
				return ch;
		}
	}
}
int main()
{
	FILE* cin = stdin;
	do {
		yyparse();
	} while (!feof(cin));
	return 0;
}
void yyerror(const char* s) {
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}
