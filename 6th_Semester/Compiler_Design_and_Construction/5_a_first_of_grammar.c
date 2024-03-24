#include <stdio.h>
#include <ctype.h>

int numOfProductions;
char productionSet[10][10];

void FIRST(char[], char);
void addToResultSet(char[], char);

int main()
{
    int i;
    char choice, c, result[20];

    printf("How many number of productions?: ");
    scanf(" %d", &numOfProductions);

    for (i = 0; i < numOfProductions; i++)
    {
        printf("Enter productions Number %d: ", i + 1);
        scanf(" %s", productionSet[i]);
    }

    do
    {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c);
        FIRST(result, c); // Compute FIRST; Get Answer in 'result' array
        printf("\nFIRST(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++)
            printf("%c ", result[i]); // Display result
        printf("}\n");
        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void FIRST(char *Result, char c)
{
    int i, j, k;
    char subResult[20];
    int foundEpsilon;

    subResult[0] = '\0';
    Result[0] = '\0';

    // If X is terminal, FIRST(X) = {X}
    if (!(isupper(c)))
    {
        addToResultSet(Result, c);
        return;
    }

    // If X is non-terminal then read each production
    for (i = 0; i < numOfProductions; i++)
    {
        // Find production with X as LHS
        if (productionSet[i][0] == c)
        {
            if (productionSet[i][2] == '$') // epsilon production
                addToResultSet(Result, '$');
            else
            {
                j = 2;
                while (productionSet[i][j] != '\0')
                {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for (k = 0; subResult[k] != '\0'; k++)
                        addToResultSet(Result, subResult[k]);
                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    }
                    // No epsilon found, no need to check next element
                    if (!foundEpsilon)
                        break;
                    j++;
                }
            }
        }
    }
    return;
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
