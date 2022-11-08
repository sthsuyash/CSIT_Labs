#include <stdio.h>
/*Ternary operator
condition_is_true ? return_x : return_y;
*/
int main()
{
	int num1 = 2, num2 = 10, largeNumber;
	largeNumber = num1 > 0 ? num1 : num2;
	printf("Largest number is %d", largeNumber);
	return 0;
}
