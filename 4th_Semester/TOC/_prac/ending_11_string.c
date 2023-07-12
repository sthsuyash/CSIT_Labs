// DFA for the language of string over {0,1} in which each string ends with 11
#include<stdio.h>
#include <string.h>

int main()
{
    char str[100];     // string to be checked
    char state = 0; // initial state (q0)

    printf("Enter the string: ");
    scanf("%s", str);

    // loop to check each character of the string for the DFA
    for (int i = 0; i < strlen(str); i++)
    {
        // check if the string is over {0,1} or not
        if (str[i] != '0' && str[i] != '1')
        {
            printf("String not accepted.\nPlease enter a string over {0,1}\n");
            return 0;
        }

        // dfa transition check
        if (state == 0 && str[i] == '0')
        {
            state = 0;
        }
        else if (state == 0 && str[i] == '1')
        {
            state = 1;
        }
        else if (state == 1 && str[i] == '0')
        {
            state = 0;
        }
        else if (state == 1 && str[i] == '1')
        {
            state = 2;
        }
        else if (state == 2 && str[i] == '0')
        {
            state = 0;
        }
        else if (state == 2 && str[i] == '1')
        {
            state = 1;
        }
    }

    // check if the string is accepted or not,
    // i.e. if the final state is 2 then string is accepted
    // else string is not accepted
    if (state == 2)
    {
        printf("String accepted");
    }
    else
    {
        printf("String not accepted");
    }
    return 0;
}

// --------------------------------------------------------------------------------------
// NFA
// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// #define ALPHABET_SIZE 2

// // Define the NFA transition table
// int nfaTransitions[][ALPHABET_SIZE] = {
//     {0, 1}, // State 0 transitions: '0' -> State 0, '1' -> State 1
//     {0, 2}, // State 1 transitions: '0' -> State 0, '1' -> State 2
//     {0, 0}  // State 2 transitions: '0' -> State 0, '1' -> State 0 (Trap state)
// };

// bool simulateNFA(const char *input)
// {
//     int state = 0;
//     int ip = strlen(input);

//     for (int i = 0; i < ip; i++)
//     {
//         char curr_char = input[i];
//         int char_index;

//         if (curr_char == '0')
//         {
//             char_index = 0;
//         }
//         else if (curr_char == '1')
//         {
//             char_index = 1;
//         }
//         else
//         {
//             return false; // Invalid input character
//         }

//         int nextState = nfaTransitions[state][char_index];
//         state = nextState;
//     }

//     return (state == 2); // Accept if the final state is 2
// }

// int main()
// {
//     char input[100];

//     printf("Enter a string: ");
//     scanf("%s", input);

//     if (simulateNFA(input))
//     {
//         printf("String ends with '11'.\n");
//     }
//     else
//     {
//         printf("String does not end with '11'.\n");
//     }

//     return 0;
// }
