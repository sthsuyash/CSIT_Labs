// Fitting an exponential equation
#include <stdio.h>
#include <math.h>
#define MAX 10

int main()
{
    int n;
    float x[MAX], y[MAX], u[MAX];
    float sumx = 0.0, sumu = 0.0, sumxx = 0.0, sumxu = 0.0, xmean, umean, denom, a, b;

    /*Reading data values*/
    printf("\nInput number of data points: ");
    scanf("%d", &n);

    printf("\nInput x and y values (one set on each line): ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        u[i] = log(y[i]);
    }

    /*Computing constants a and b*/
    for (int i = 1; i <= n; i++)
    {
        sumx += x[i];
        sumu += u[i];
        sumxx += x[i] * x[i];
        sumxu += x[i] * u[i];
    }
    xmean = sumx / n;
    umean = sumu / n;
    denom = n * sumxx - sumx * sumx;
    b = (n * sumxu - sumx * sumu) / denom;
    a = exp(umean - b * xmean);

    printf("\n The exponential equation that is fit to the given data is y = %f e^%fx.", a, b);
    return 0;
}
