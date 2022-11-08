#include<stdio.h>
int main(){
	float num1, num2;
	printf("Enter first number: ");
	scanf("%f",&num1);
	printf("Enter second number:");
	scanf("%f",&num2);
	printf("Sum of %.2f and %.2f is %.2f",num1,num2, num1+num2);
	return 0;
}
