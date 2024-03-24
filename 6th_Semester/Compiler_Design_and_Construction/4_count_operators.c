#include <stdio.h>

int count_operators(const char *expression)
{
    int count = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        switch (expression[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            count++;
            break;
        default:
            break;
        }
    }
    return count;
}

int main()
{
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);
    int count = count_operators(expression);
    printf("The number of operators in the expression is %d\n", count);
    return 0;
}
