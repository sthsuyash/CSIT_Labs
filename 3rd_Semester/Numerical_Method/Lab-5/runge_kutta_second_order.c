#include <stdio.h>
#include <math.h>
#define EPS 0.00001

float f1(float x, float y1, float y2)
{
    return y2;
}

float f2(float x, float y1, float y2)
{
    return 2 * y2 - y1 + x * (exp(x) - 1);
}

// Routine for Runge-Kutta method
float rk(float x0, float x1, float y0, float y1, float h)
{
    float k1, k2, k3, k4, l1, l2, l3, l4;
    printf("\n\nCalculation of y(%f):", x1);
    printf("\nx \t\t y(x)");

    while (fabs(x0 - x1) > 0.0001)
    {
        printf("\n%f\t%f", x0, y0);
        k1 = f1(x0, y0, y1);
        l1 = f2(x0, y0, y1);

        k2 = f1(x0 + 0.5 * h, y0 + 0.5 * h * k1, y1 + 0.5 * h * l1);
        l2 = f2(x0 + 0.5 * h, y0 + 0.5 * h * k1, y1 + 0.5 * h * l1);

        k3 = f1(x0 + 0.5 * h, y0 + 0.5 * h * k2, y1 + 0.5 * h * l2);
        l3 = f2(x0 + 0.5 * h, y0 + 0.5 * h * k2, y1 + 0.5 * h * l2);

        k4 = f1(x0 + h, y0 + h * k3, y1 + h * l3);
        l4 - f2(x0 + h, y0 + h * k3, y1 + h * l3);

        y0 = y0 + (h / 6) * (k1 + 2 * (k2 + k3) + k4);
        y1 = y1 + (h / 6) * (l1 + 2 * (l2 + l3) + l4);
        x0 = x0 + h;
    }
    printf("\n%f\t%f", x0, y0);
    return y0;
}

// driver program
int main(int argc, char const *argv[])
{
    float x0, yx0, yx1, xp, yxp, h;

    printf("Enter the initial point x: ");
    scanf("%f", &x0);

    printf("Enter the value of y(x): ");

    scanf("%f", &yx0);

    printf("Enter the value of y'(x): ");
    scanf("%f", &yx1);

    printf("Enter the step length: ");
    scanf("%f", &h);

    printf("Enter the point x at which y(x) is required: ");
    scanf("%f", &xp);
    yxp = rk(x0, xp, yx0, yx1, h);
    printf("\nThe approximate value of y(%f) = %f.\n", xp, yxp);

    return 0;
}
