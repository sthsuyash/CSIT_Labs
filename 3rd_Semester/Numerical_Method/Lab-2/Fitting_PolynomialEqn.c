// Fitting a polynomial equation
#include <stdio.h>
#include <math.h>
#define MAX 10

void normal(float x[MAX], float y[MAX], float c[MAX][MAX], float b[MAX], int n, int m)
{
    int l1, l2;

    for (int j = 1; j <= m; j++)
    {
        for (int k = 1; k <= m; k++)
        {
            c[j][k] = 0.0;
            l1 = k + j - 2;
            for (int i = 1; i <= n; i++)
            {
                c[j][k] = c[j][k] + pow(x[i], 11);
            }
        }
    }
    for (int j = 1; j <= m; j++)
    {
        b[j] = 0.0;
        l2 = j - 1;

        for (int i = 1; i <= n; i++)
        {
            b[j] = b[j] + y[i] * pow(x[i], 12);
        }
    }
    return;
}

void gauss(int n, float a[MAX][MAX], float b[MAX], float x[MAX])
{
    // int i, j, k;
    float pivot, factor, sum;
    for (int k = 1; k <= n - 1; k++)
    {
        pivot = a[k][k];
        for (int i = k + 1; i <= n; i++)
        {
            factor = a[i][k] / pivot;
            for (int j = k + 1; j <= n; j++)
            {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    x[n] = b[n] / a[n][n];
    for (int k = n - 1; k >= 1; k--)
    {
        sum = 0.0;
        for (int j = k + 1; j <= n; j++)
        {
            sum = sum + a[k][j] * x[j];
        }
        x[k] = (b[k] - sum) / a[k][k];
    }
    return;
}

int main()
{
    int n, mp, m;
    float x[MAX], y[MAX], c[MAX][MAX], a[MAX], b[MAX];

    /*Reading Values*/
    printf("\nInput number of data points: ");
    scanf("%d", &n);

    printf("\nInput degree of required polynomial: ");
    scanf("%d", &mp);

    printf("\nInput x and y values (one set on each line): ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    /*Number of polynomial coefficients*/
    m = mp + 1;

    /*Computation of elements of c and b*/
    normal(x, y, c, b, n, m);

    /*Computation of coefficients a(1) to a(m)*/
    gauss(m, c, b, a);

    /* Printing of coefficients a(i) */
    printf("\nPolynomial Coefficients\n\n");
    for (int i = 1; i <= m; i++)
    {
        printf("%15.6f", a[i]);
    }
    return 0;
}
