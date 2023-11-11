#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

void generateHeader(const char *programName)
{
    int headerLength = strlen(programName) + 8;
    printf("\n");
    for (int i = 0; i < headerLength; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("**  %s  **\n", programName);
    for (int i = 0; i < headerLength; i++)
    {
        printf("*");
    }
    printf("\n\n");
}

#endif