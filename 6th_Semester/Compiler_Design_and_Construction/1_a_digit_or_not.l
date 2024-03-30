%{
#include<stdio.h>
#include<stdlib.h>
%}
%%
^[0-9]*  printf("digit");
^[^0-9]|[0-9]*[a-zA-Z]  printf("not a digit");
. ;
%%
int main()
{
        // The function that starts the analysis
    yylex();
        return 0;
}
