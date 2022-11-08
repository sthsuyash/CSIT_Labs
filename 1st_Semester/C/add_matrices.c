// Program to add two matrices.
#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the no. of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    int matA[m][n], matB[m][n], sum[m][n];

    // enter elements for matrix A
    printf("Enter the elements of matrix A: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }

    // enter elements for matrix B
    printf("Enter the elements of matrix B: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }

    sum[m][n] = 0;
    // add matrices
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }

    // print sum matrix
    printf("\nSum matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
