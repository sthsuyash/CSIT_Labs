#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f1(float x, float y, float z)
{
    return (z);
}

float f2(float x, float y, float z)
{
    return (x + y);
}

float shoot(float x0, float y0, float z0, float xn, float h, int p)
{
    float x, y, z, k1, k2, k3, k4, l1, l2, l3, l4, k, l, x1, y1, z1;
    x = x0;
    y = y0;
    z = z0;

    do
    {
        k1 = h * f1(x, y, z);
        l1 = h * f2(x, y, z);
        k2 = h * f1(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
        l2 = h * f2(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
        k3 = h * f1(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
        l3 = h * f2(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
        k4 = h * f1(x + h, y + k3, z + l3);
        l4 = h * f2(x + h, y + k3, z + l3);
        l = 1 / 6.0 * (l1 + 2 * l2 + 2 * l3 + l4);
        k = 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
        y1 = y + k;
        x1 = x + h;
        z1 = z + l;
        x = x1;
        y = y1;
        z = z1;

        if (p == 1)
        {
            printf("\n%f\t%f", x, y);
        }
    } while (x < xn);

    return y;
}

int main()
{
    float x0, y0, h, xn, yn, z0, m1, m2, m3, b, b1, b2, b3, e;
    int p = 0;

    printf("Enter x0: ");
    scanf("%f", &x0);

    printf("Enter y0: ");
    scanf("%f", &y0);

    printf("Enter xn: ");
    scanf("%f", &xn);

    printf("Enter yn: ");
    scanf("%f", &yn);

    printf("Enter h: ");
    scanf("%f", &h);

    printf("\nEnter the trial M1: ");
    scanf("%f", &m1);
    b = yn;
    z0 = m1;
    b1 = shoot(x0, y0, z0, xn, h, p = 1);

    printf("\nB1 is %f\n", b1);

    if (fabs(b1 - b) < 0.00005)
    {
        printf("\nThe value of x and respective z are:\n");
        e = shoot(x0, y0, z0, xn, h, p = 1);
        return 0;
    }
    else
    {
        printf("\nEnter the value of M2: ");
        scanf("%f", &m2);

        z0 = m2;
        b2 = shoot(x0, y0, z0, xn, h, p = 1);
        printf("\nB2 is %f", b2);
    }
    if (fabs(b2 - b) < 0.00005)
    {
        printf("\nThe value of x and respective z are:\n");
        e = shoot(x0, y0, z0, xn, h, p = 1);
        return 0;
    }
    else
    {
        printf("\nM2 = %f\tM1 = %f\n", m2, m1);
        m3 = m2 + (((m2 - m1) * (b - b2)) / (1.0 * (b2 - b1)));
        if (b1 - b2 == 0)
        {
            exit(0);
        }
        printf("\nExact value of M = %f", m3);
        z0 = m3;
        b3 = shoot(x0, y0, z0, xn, h, p = 0);
    }
    if (fabs(b3 - b) < 0.000005)
    {
        printf("\nThere is solution :\n");
        e = shoot(x0, y0, z0, xn, h, p = 1);
        exit(0);
    }
    do
    {
        m1 = m2;
        m2 = m3;
        b1 = b2;
        b2 = b3;
        m3 = m2 + (((m2 - m1) * (b - b2)) / (1.0 * (b2 - b1)));
        z0 = m3;
        b3 = shoot(x0, y0, z0, xn, h, p = 0);

    } while (fabs(b3 - b) < 0.0005);
    z0 = m3;
    e = shoot(x0, y0, z0, xn, h, p = 1);

    return 0;
}