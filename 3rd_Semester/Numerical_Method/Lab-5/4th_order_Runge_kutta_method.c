/*** 4th order Runge kutta method ***/

#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return y - x * x + 1;
}

int main()
{
    int n, i;
    float x, y, xp, h, m1, m2, m3, m4;

    printf("\nInput initial value of x: ");
    scanf("%f", &x);

    printf("Input initial value of y: ");
    scanf("%f", &y);

    printf("Input x at which y is required: ");
    scanf("%f", &xp);

    printf("Input step-size h: ");
    scanf("%f", &h);

    n = (int)((xp - x) / h + 0.5);

    for (i = 1; i <= n; i++)
    {
        m1 = f(x, y);
        m2 = f(x + 0.5 * h, y + 0.5 * m1 * h);
        m3 = f(x + h, y + m3 * h);
        m4 = f(x + h, y + m3 * h);
        x += h;
        y = y + (m1 + 2.0 * m2 + 2.0 * m3 + m4) * h / 6.0;
        printf("Value of y at x = %f is %f.\n", xp, y);
    }

    return 0;
}
