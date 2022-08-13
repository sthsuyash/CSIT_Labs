/**** algorithm ( power modulo using recursion ) ****/
#include <stdio.h>

int power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return base * power(base, pow - 1);
}

int powerModulo(int base, int pow, int m)
{
    int ans = power(base, pow);
    return ans % m;
}

int main(void)
{
    int base, pow, m;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter power: ");
    scanf("%d", &pow);
    printf("Enter the number to be modded: ");
    scanf("%d", &m);
    printf("%d^%d mod %d: %d", base, pow, m, powerModulo(base, pow, m));
    return 0;
}