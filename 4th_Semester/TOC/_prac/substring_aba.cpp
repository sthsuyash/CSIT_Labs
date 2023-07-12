// DFA for substring 'aba'

// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// bool containsABA(const char *str)
// {
//     int state = 0;
//     int strLength = strlen(str);

//     for (int i = 0; i < strLength; i++)
//     {
//         char currentChar = str[i];

//         if (state == 0 && currentChar == 'a')
//         {
//             state = 1;
//         }
//         else if (state == 1 && currentChar == 'b')
//         {
//             state = 2;
//         }
//         else if (state == 2 && currentChar == 'a')
//         {
//             return true;
//         }
//         else
//         {
//             state = 0;
//         }
//     }

//     return false;
// }

// int main()
// {
//     char str[100];

//     printf("Enter a string: ");
//     scanf("%s", str);

//     if (containsABA(str))
//     {
//         printf("String contains 'aba' substring.\n");
//     }
//     else
//     {
//         printf("String does not contain 'aba' substring.\n");
//     }

//     return 0;
// }

// --------------------------------------------------------------

// NFA

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool containsABA(const char *str)
{
    int state = 0;
    int strLength = strlen(str);

    for (int i = 0; i < strLength; i++)
    {
        char currentChar = str[i];

        if (state == 0 && currentChar == 'a')
        {
            state = 1;
        }
        else if (state == 1 && currentChar == 'b')
        {
            state = 2;
        }
        else if (state == 2 && currentChar == 'a')
        {
            return true;
        }
        else
        {
            state = 0;
        }
    }

    return false;
}

bool simulateNFA(const char *str)
{
    int strLength = strlen(str);

    for (int i = 0; i <= strLength; i++)
    {
        // Split the string at each position and check both substrings
        if (containsABA(str + i))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (simulateNFA(str))
    {
        printf("String contains 'aba' substring.\n");
    }
    else
    {
        printf("String does not contain 'aba' substring.\n");
    }

    return 0;
}
