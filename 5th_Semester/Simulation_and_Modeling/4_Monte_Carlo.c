// Estimate the value of pie using monte carlo simulation

#include <stdlib.h>
#include <stdio.h>
#define SEED 35791246

int main()
{
    int N = 0; // N is the total number of points generated
    double x, y;
    int i, n = 0; // n is the number of points in the 1st quadrant of a circle
    double d;     // distance between center of circle to border
    double pi;

    printf("Enter the number of iterations used to estimate pi: ");
    scanf("%d", &N);

    // initialize random numbers
    srand(SEED);
    n = 0;
    for (i = 0; i < N; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        d = x * x + y * y;
        if (d <= 1)
            n++;
    }
    pi = ((double)n / N) * 4;
    printf("Number of trials = %d\nEstimated value of pi = %g \n", N, pi);
}