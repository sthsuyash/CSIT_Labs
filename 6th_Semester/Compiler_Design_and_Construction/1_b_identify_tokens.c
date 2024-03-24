#include <stdio.h>
#include <string.h>
#include <ctype.h>

void identifyToken(char *input);

int main()
{
    char input[100];
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);
    identifyToken(input);
    return 0;
}

void identifyToken(char *input)
{
    if (strchr(input, "bool") == 0 || strchr(input, "int") == 0 || strchr(input, "float") == 0)
        printf("Keyword\n");
    else if (isdigit(input[0]) || (input[0] == '+' || input[0] == '-') && isdigit(input[1]))
        printf("Constants\n");
    else if (strspn(input, ",.'\"") == strlen(input))
        printf("Punctuation Chars\n");
    else if (strchr("!@#$%^&*()", input[0]) != NULL)
        printf("Special Chars\n");
    else if (strchr("+-*/", input[0]) != NULL)
        printf("Operators\n");
    else
        printf("Identifiers\n");
}
