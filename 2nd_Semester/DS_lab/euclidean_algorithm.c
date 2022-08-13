/**** algorithm ( euclidean algorithm ) ****/
#include <stdio.h>

int main(void)
{
    int x, y;
    int a, b, r;

    printf("Enter value for x: ");
    scanf("%d", &x);
    printf("Enter value for y: ");
    scanf("%d", &y);
    a = x, b = y;

    /**** gcd calculation ****/
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    printf("G.C.D(%d,%d) is %d", x, y, a);
    return 0;
}
