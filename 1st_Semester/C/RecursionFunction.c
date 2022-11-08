/*4 types of user defined function:

1. No arguments passed and no return value
void testfunction(){
	//body
}

2. No arguments passed  but a return value
int testfunction(){
	//body
}

3. Arguments passed but no return value
void testfunction(int num1, int num2, float percentage,...){
	//body
}

4. Arguments passed and a return value
float testfunction(int num1, float num2,.....){
	//body
}
*/

// Recursion function
/*
void test(){
	printf("this is test function");
	test();
}
*/
#include <stdio.h>
// void test(){
//  	printf("This is a test function");
//  	test();//recursion
//  }
// 5 -> 5+4+3+2+1+0
// 3 -> 3+2+1+0
// 10 -> 10+9+8+7+6+5+4+3+2+1+0
// 0 -> 0
// 1 -> 1+0=1
int sum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n + sum(n - 1); // return 3+2+1+0
	}
}

int main()
{
	int num, result;
	printf("Enter a number to find sum: ");
	scanf("%d", &num);
	result = sum(num);
	printf("%d", result);
	return 0;
}
