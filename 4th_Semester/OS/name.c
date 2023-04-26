#include <stdio.h>
#include <string.h>

void name(char *lab_no)
{
    // Replace with your name, roll and section
    char username[50] = "Suyash Shrestha";
    int roll = 22;
    char sec = 'B';

    // lab number is passed from the main function
    printf("\nLab No: %s", lab_no);
    printf("\nName: %s", username);
    printf("\nRoll No : %d\tSection : %c\n", roll, sec);
}