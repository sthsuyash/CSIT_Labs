#include <stdio.h>
#include <math.h>

int main(void)
{
    double num, floored, ceiled;
    printf("Enter a floating value: ");
    scanf("%lf", &num);
    floored = floor(num);
    ceiled = ceil(num);
    printf("The entered value is: %lf\nFloored value: %.0lf\nCeiled value: %.0lf", num, floored, ceiled);
    return 0;
}
