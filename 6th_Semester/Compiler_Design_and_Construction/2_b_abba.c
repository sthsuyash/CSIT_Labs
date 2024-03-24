#include <stdio.h>

int main()
{
    char str[20];
    int i = 0, state = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[i] != '\0')
    {
        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 1;
            else
                state = 5;
            break;
        case 1:
            if (str[i] == 'b')
                state = 2;
            else
                state = 5;
            break;
        case 2:
            if (str[i] == 'b')
                state = 3;
            else
                state = 5;
            break;
        case 3:
            if (str[i] == 'a')
                state = 4;
            else
                state = 5;
            break;
        case 4:
            state = 5; // Any additional characters after 'abba' will lead to invalid state
            break;
        case 5:
            break; // Invalid state
        }
        i++;
    }

    if (state == 4)
        printf("The string is accepted\n");
    else
        printf("The string is invalid\n");

    return 0;
}
