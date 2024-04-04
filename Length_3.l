%{
    #include<stdio.h>
    int length = 0;
    int fun(int k);
%}

%%
[a-zA-Z0-9]+ {length = yyleng; fun(length);}
\n {return 0;}
%%

int fun(int l)
{
    if(yytext[0]=='A' || yytext[0]=='a') {
        if(l == 3) printf("The word is of Length 3 starting with A: %s\n",yytext);
        else printf("The word is not of length 3\n");
    }
    else printf("The word is not starting with A\n");
}

int yywrap() {}
int main() {
    printf("Enter any string:");
    yylex();
}