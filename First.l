%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%%
[A-Z]+ {ECHO; printf("First is: %s", yytext);}
[a-z]+ {ECHO; printf("\n Terminal \n");}
"->" {}
%%

int yywrap() {}
int main()
{
    yylex();
    
}