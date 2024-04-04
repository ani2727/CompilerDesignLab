%{
    #include<stdio.h>
    int lines = 0 ,spaces = 0,words = 0,characters = 0, tabs = 0,c = 0;
%}

%%
\n {lines ++;}
" " {spaces ++;}
\t {tabs ++;}
. {characters ++,c ++;}
[a-zA-Z0-9]+ {words ++;c=c+yyleng;}
%%

int yywrap() {}
int main()
{
    printf("Enter a Input String: ");
    yylex();
    printf("lines = %d\n spaces = %d \n words = %d \n characters = %d \ntabs = %d\n totalchars = %d",lines,spaces,words+characters,tabs,c);
    return 0;
}