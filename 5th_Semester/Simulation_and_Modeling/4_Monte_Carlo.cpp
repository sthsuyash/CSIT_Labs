/*
 * Program to estimate the value of pie using monte carlo simulation
 */

#include <iostream>
#include <cstdlib>
#define SEED 35791246
using namespace std;

int main()
{
    // N is the total number of points generated
    int N, n = 0;       // n is the number of points in the 1st quadrant of a circle
    double x, y, pi, d; // distance between center of circle to border

    cout << "Enter the number of iterations used to estimate pi: ";
    cin >> N;

    // initialize random numbers
    srand(SEED);
    for (int i = 0; i < N; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        d = x * x + y * y;
        if (d <= 1)
            n++;
    }
    pi = ((double)n / N) * 4;
    cout << "Number of trials = " << N << endl
         << "Estimated value of pi = " << pi << endl;
}