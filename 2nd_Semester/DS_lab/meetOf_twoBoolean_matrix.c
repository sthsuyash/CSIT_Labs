/**** algorithm ( Meet of two boolean matrices ) ****/
#include <stdio.h>

int rows, columns; // declare these global variable as they are needed everywhere

// function to scan values of matrices
void scanMatrix(char matName, int mat[rows][columns])
{
    printf("Enter data for matrix %c:\n", matName);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

// function to print data in matrix form
void printMatrix(char matName, int mat[rows][columns])
{
    printf("\nMatrix %c:\n", matName);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    // int rows, columns; // variables to store the number of rows and columns of matrix the user wants
    printf("Enter the rows for matrix: ");
    scanf("%d", &rows);
    printf("Enter the columns for matrix: ");
    scanf("%d", &columns);
    // make two arrays A and B with the provided rows and columns
    int A[rows][columns], B[rows][columns];
    // call functions to scan the matrix A and B
    scanMatrix('A', A);
    scanMatrix('B', B);
    // displaying data in matrix form
    printMatrix('A', A);
    printMatrix('B', B);
    // displaying the meet of the matrices A and B
    printf("\nMeet of matrices A and B:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", A[i][j] && B[i][j]);
        }
        printf("\n");
    }
    return 0;
}