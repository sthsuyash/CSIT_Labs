// Polynomial interpolation using Newton's Interpolation

#include <stdio.h>
#include <math.h>
#define MAX 15

int main()
{
    int n;
    float xp, fp, sum, pi, x[MAX], f[MAX], a[MAX], d[MAX][MAX];
    char q;

    printf("\nInput the number of data pairs: ");
    scanf("%d", &n);

    printf("\nInput data pairs x(i) and values f(i) (one set in each line): ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%f %f", &x[i], &f[i]);
    }

    /*Construct difference table*/
    for (int i = 1; i <= n; i++)
    {
        d[i][1] = f[i];
    }

    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= n - j + 1; i++)
        {
            d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j + 1] - x[i]);
        }
    }

    /* Set the coefficients of interpolation polynomial*/
    for (int j = 1; j <= n; j++)
    {
        a[j] = d[1][j];
    }

    /*Compute interpolation value*/
    do
    {
        printf("\nInput x at which interpolation is required:");
        scanf("%f", &xp);
        sum = a[1];

        for (int i = 2; i <= n; i++)
        {
            pi = 1.0;
            for (int j = 1; j <= i - 1; j++)
            {
                pi = pi * (xp - x[j]);
            }
            sum = sum + a[i] * pi;
        }
        fp = sum;

        /*write results*/
        printf("\nInterpolated function value at x=%f is %f.\n", xp, fp);
        printf("Do you want to input another value? (y/n): ");
        fflush(stdin);
        scanf("%c", &q);
    } while (q == 'y');
    return 0;
}
