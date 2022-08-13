/**** algorithm ( power using recursion ) ****/
#include <stdio.h>

int power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return base * power(base, pow - 1);
}

int main(void)
{
    int base, pow;
    printf("Enter the base number: ");
    scanf("%d", &base);
    printf("Enter the power: ");
    scanf("%d", &pow);
    printf("%d to the power %d: %d", base, pow, power(base, pow));
    return 0;
}