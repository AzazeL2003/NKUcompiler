
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define YYSTYPE char*

int yylex();
extern int yyparse();
void yyerror(const char* s);
char numStr[101];
%}
%token NUMBER
%token ADD
%token SUB
%token MUL
%token DIV
%token LEFT_PAR
%token RIGHT_PAR

%left ADD 
%left SUB
%left MUL
%left DIV
%right UMINUS 
%%
line  :    line expr '\n' { printf("%s\n", $2); } 
      |    line '\n'
      |   
      ;
expr  :    expr ADD expr  { 
        $$ = (char*)malloc(100*sizeof(char)); 
        strcpy($$,$1);
        strcat($$,$3); 
        strcat($$,"+ "); 
    }
      |    expr SUB expr  { 
            $$ = (char*)malloc(100*sizeof(char)); 
            strcpy($$,$1); 
            strcat($$,$3); 
            strcat($$,"- "); 
        }
      |    expr MUL expr  { 
            $$ = (char*)malloc(100*sizeof(char)); 
            strcpy($$,$1); 
            strcat($$,$3); 
            strcat($$,"* "); 
        }
      |    expr DIV expr  { 
            $$ = (char*)malloc(100*sizeof(char)); 
            strcpy($$,$1); 
            strcat($$,$3);
            strcat($$,"/ "); 
        }
      |    LEFT_PAR expr RIGHT_PAR   { $$ = $2; }
      |    SUB  expr %prec UMINUS  {
            $$ = (char*)malloc(50*sizeof(char)); 
            strcpy($$,"- "); 
            strcat($$,$2); 
         }
      |    NUMBER         { 
            $$ = (char*)malloc(100*sizeof(char)); 
            strcpy($$,$1); 
            strcat($$," "); 
        }
      ;
%%

int yylex() 
{
    int ch;
    while(1){
        ch=getchar();
        if(ch==' ' || ch=='\t')
            ;
        else if ((ch>='0' && ch<= '9')){
            int i=0;
            while((ch>='0'&&ch<='9')){
                numStr[i]=ch;
                ch=getchar();
                i++;
            }
            numStr[i]='\0';
            yylval=numStr;
            ungetc(ch,stdin);
            return NUMBER;
        }
        else if(ch=='+') {
            return ADD;  
        }
        else if(ch=='-'){
            return SUB;
        }
        else if(ch=='*'){
            return MUL;
        }
        else if(ch=='/'){
            return DIV;
        }
        else if(ch=='('){
            return LEFT_PAR;
        }
        else if(ch==')'){
            return RIGHT_PAR;
        }
        else {
            return ch;
        }
    }
}

int main(void)
{
    FILE* cin = stdin;
    do{
        yyparse();
    } while(!feof(cin));
    return 0;
}
void yyerror(const char* s){
    fprintf(stderr, "error: %s\n", s);
    exit(1);
}
