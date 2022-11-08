/*Types of function
1. Standard library function/ Built in function(ex: printf(), scanf(),
strlen(), strcmp(), strcat(), sqrt())
2. User defined function
 Declaration:
 return_type function_name(){
	body of function
 }


 1. No argument and no return value   =   void test(){ }
 2. No argument but return value      =   int test(){ }
 3. Argument but no return value      =   void test(int a, int b){}
 4. Argument and return value         =   int test(int a, float b){}
*/

#include <stdio.h>

// Parameterized function
void sum(int num1, int num2)
{
	printf("Sum is %d", num1 + num2);
}

// function returning values
int multiply(int num1, int num2)
{
	int product = num1 * num2;
	return product;
}

int main()
{
	// display();
	// sum(8,7);
	int result = multiply(2, 10);
	printf("%d", result);
	return 0;
}

// non parameterized function
void display()
{
	printf("this is display function");
}
