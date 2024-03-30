%{
#include<stdio.h>
%}
%%
bool|int|float printf("Keyword");
[-,+]?[0-9]+ printf("Constants");
[,.'"]+ printf("Punctuation Chars");
[!@#$%^&*()]+ printf("Special Chars");
[a-zA-Z]+ printf("Identifiers");
%%
int main()
{yylex();
}
