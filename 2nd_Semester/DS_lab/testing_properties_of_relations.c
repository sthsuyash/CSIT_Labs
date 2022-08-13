/**** algorithm ( testing properties of relations ) ****/
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter required number of elements of set: ");
    scanf("%d", &n);
    int mat[n][n];
    // entering matrix representation
    printf("Enter matrix representation of relation:(one row at a time)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    /**** checking reflexive ****/
    /**** initialization of key variable ****/
    int key = 1;
    for (int i = 0; i < n; i++)
    {
        key = key && mat[i][i];
    }
    if (key == 1)
    {
        printf("\nThe given relation is reflexive.\n");
    }
    else
    {
        printf("\nThe given relation is not reflexive.\n");
    }

    /**** checking symmetricity ****/
    /**** reinitialization of key variable ****/
    key = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != mat[j][i])
                key = 0;
        }
    }
    if (key == 1)
    {
        printf("The given relation is symmetric.\n");
    }
    else
    {
        printf("The given relation is not symmetric.\n");
    }

    /**** checking antisymmetricity ****/
    /**** reinitialization of key variable ****/
    key = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j != i && j < n; j++)
        {
            if ((mat[i][j] && mat[j][i]) == 1)
                key = 0;
        }
    }
    if (key == 1)
    {
        printf("The given relation is antisymmetric.\n");
    }
    else
    {
        printf("The given relation is not antisymmetric.\n");
    }
    return 0;
}