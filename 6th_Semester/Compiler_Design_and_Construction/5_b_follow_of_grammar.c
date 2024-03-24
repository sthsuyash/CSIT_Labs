#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, j;
char a[10][10], Result[10];
char subResult[20];

void follow(char *Result, char c);
void first(char *Result, char c);
void addToResultSet(char[], char);

int main()
{
    int i;
    char c;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter %d productions.\nProduction with multiple terms should be give as separate productions\n", n);
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    printf("Find FOLLOW of: ");
    scanf(" %c", &c);
    follow(Result, c);
    printf("FOLLOW(%c) = { ", c);
    for (i = 0; Result[i] != '\0'; i++)
        printf("%c ", Result[i]);
    printf(" }\n");
    return 0;
}

void follow(char *Result, char c)
{
    int k;
    subResult[0] = '\0';
    Result[0] = '\0';
    if (a[0][0] == c)
        addToResultSet(Result, '$');
    for (int i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(subResult, a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(subResult, a[i][0]);
                for (k = 0; subResult[k] != '\0'; k++)
                    addToResultSet(Result, subResult[k]);
            }
        }
    }
}

void first(char *R, char c)
{
    int k, m;
    if (!(isupper(c)) && c != '#')
        addToResultSet(R, c);
    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '#' && c != a[k][0])
                follow(R, a[k][0]);
            else if (!(isupper(a[k][2])) && a[k][2] != '#')
                addToResultSet(R, a[k][2]);
            else
                first(R, a[k][2]);
            for (m = 0; R[m] != '\0'; m++)
                addToResultSet(Result, R[m]);
        }
    }
}

void addToResultSet(char Result[], char val)
{
    int k;
    for (k = 0; Result[k] != '\0'; k++)
    {
        if (Result[k] == val)
            return;
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
