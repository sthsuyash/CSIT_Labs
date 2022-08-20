/** Derivative using Newton's Divided Differences Table **/
#include <stdio.h>
#include <math.h>
#define MAX 15

int main()
{
    int n;
    float x[MAX], f[MAX], a[MAX], d[MAX][MAX], xp, dif, sum, p;
    char q;

    printf("\nInput number of data points: ");
    scanf("%d", &n);

    printf("\nInput values of x and f(x) one set on each line: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%f %f", &x[i], &f[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        d[i][1] = f[i];
    }
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= n - j + 1; i++)
        {
            d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j - 1] - x[i]);
        }
        for (int j = 1; j <= n; j++)
        {
            a[j] = d[1][j];
        }
        do
        {
            printf("\nInput xp where derivative is required: ");
            scanf("%f", &xp);
            dif = a[2];

            for (int k = 3; k <= n; k++)
            {
                sum = 0.0;
                for (int i = 1; i <= k - 1; i++)
                {
                    p = 1.0;
                    for (j = 1; j <= k - 1; j++)
                    {
                        if (i != j)
                            p = p * (xp - x[j]);
                    }
                    sum = sum + p;
                }
                dif = dif + a[k] * sum;
            }

            printf("\nDerivative at x = %f is %f.", xp, dif);
            printf("\nDo you want to input another value? (y/n): ");
            fflush(stdin);
            scanf("%c", &q);
        } while (q == 'y');
    }
    return 0;
}
