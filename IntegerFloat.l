%{
    #include<stdio.h>
    int int_count = 0;
    int float_count = 0;
%}

%%
[0-9]+"."[0-9]+ {ECHO;printf(" Decimal Number\n"); float_count ++;}
[0-9]+ {ECHO;printf("Integer Number \n"); int_count ++;}
\n {printf("Integers = %d \n Decimals = %d",int_count,float_count);}
%%
int yywrap() {}
int main()
{
    printf("Enter any numbers");
    yylex();

    return 0;
}