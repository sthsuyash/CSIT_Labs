#include <stdio.h>
#include <math.h>
#define MAX 10
#define EPS 0.0001

int main(void)
{
    int i, j, k, n, count = 0;
    float ev = 1.0, ev_temp, temp_max, a[MAX][MAX], x[MAX], y[MAX];

    printf("Input the size of matrix: ");
    scanf("%d", &n);

    printf("Input elements a(i,j) row-wise (one row at a time): ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        x[i] = 1;
    }
    do
    {
        for (i = 1; i <= n; i++)
        {
            y[i] = 0;
        }
        ev_temp = ev;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                y[i] = y[i] + a[i][j] * x[j];
            }
        }

        for (i = 1; i <= n; i++)
        {
            x[i] = y[i];
        }
        temp_max = fabs(x[1]);
        k = 1;

        for (j = 2; j <= n; j++)
        {
            if (fabs(x[j]) > temp_max)
            {
                temp_max = fabs(x[j]);
                k = j;
            }
        }
        ev = x[k];
        for (i = 1; i <= n; i++)
        {
            x[i] = x[i] / ev;
        }
        count++;
        printf("Eigen value: %f\n", ev);
        printf("Eigen vector: ");
        for (i = 1; i <= n; i++)
        {
            printf("%f\t", x[i]);
        }
        printf("\n");

    } while (fabs((ev_temp - ev) / ev) > EPS);

    printf("Approximate eigen value is: %f.\n", ev);
    printf("Corresponding eigen vector is: \n");
    for (i = 1; i <= n; i++)
    {
        printf("%f\t", x[i]);
    }
    printf("\nNumber of iterations: %d", count);

    return 0;
}
