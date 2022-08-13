// Newton's Interpolation using Backward Difference Formula
#include <stdio.h>
#include <math.h>
#define MAX 15

int main()
{
    float x[MAX], fx[MAX], bd[MAX], xp, s, h, v, p;
    int n;
    char q;
    printf("\nInput the number of data pairs: ");
    scanf("%d", &n);
    printf("\nInput data pairs x(i) and values f(i) (one set in each line): ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%f%f", &x[i], &fx[i]);
    }
    h = x[2] - x[1];

    do
    {
        printf("\nEnter the value at which interpolation is required: ");
        scanf("%f", &xp);
        s = (xp - x[n]) / h;
        p = 1;
        v = fx[n];
        for (int i = 1; i <= n; i++)
            bd[i] = fx[i];

        for (int i = n, k = 1; i >= 1, k < n; i--, k++)
        {
            for (int j = n; j >= n - 1; j--)
            {
                bd[j] = bd[j] - bd[j - 1];
            }

            p = p * (s + k - 1) / k;
            v = v + p * bd[n];
        }

        printf("\nInterpolated function value at x=%f is %f.", xp, v);
        printf("\nDo you want to input another value? (y/n): ");
        fflush(stdin);
        scanf("%c", &q);
    } while (q == 'y');
    return 0;
}