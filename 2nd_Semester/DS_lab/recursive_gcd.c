/**** algorithm ( gcd using recursion ) ****/
#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int main(void)
{
    int a, b;
    printf("Enter a non-negative integer: ");
    scanf("%d", &a);
    printf("Enter another non-negative integer: ");
    scanf("%d", &b);
    printf("G.C.D (%d,%d): %d", a, b, gcd(a, b));
    return 0;
}