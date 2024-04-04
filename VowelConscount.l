%{
    int vowels = 0;
    int consts = 0;
%}

%%
[aeiouAEIOU] {vowels ++;}
[a-zA-Z] {consts ++;}
"\n" {printf("No:of vowels = %d No:of consonants = %d",vowels,consts);}
%%

int yywrap() {}

int main()
{
    printf("Enter the String : ");
    yylex();

    return 0;
}