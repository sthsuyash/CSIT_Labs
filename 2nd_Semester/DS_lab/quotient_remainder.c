/**** algorithm ( finding quotient and remainder ) ****/
// a = dq + r
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, d;     // declaring variables for a = dividend and d = divisor
    int q = 0, r; // initializing variables for quotient and remainder

    printf("Enter the number to be divided: ");
    scanf("%d", &a);
    printf("Enter the number that divides: ");
    scanf("%d", &d);

    r = abs(a);
    while (r >= d)
    {
        r = r - d;
        q = q + 1;
    }
    if (a < 0)
    {
        if (r > 0)
        {
            r = d - r;
            q = -(q + 1);
        }
        else if (r == 0)
        {
            q = -q;
        }
    }
    // printf("%d = %d x %d + %d\n", a, d, q, r);
    printf("%d is the quotient and %d is the remainder.\n", q, r);
    return 0;
}