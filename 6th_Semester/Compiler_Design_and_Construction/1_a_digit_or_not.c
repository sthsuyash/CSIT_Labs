#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);

    int i = 0;
    int all_digits = 1; // Assume all characters are digits initially

    while (input[i] != '\0')
    {
        if (input[i] < '0' || input[i] > '9')
        {
            all_digits = 0; // Found a non-digit character
            break;          // No need to check further, exit the loop
        }
        i++;
    }

    if (all_digits)
        printf("Digits.\n");
    else
        printf("Not digits.\n");
    return 0;
}
