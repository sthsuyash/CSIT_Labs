// program to demonstrate static variable
#include <stdio.h>

void func()
{
	static int count = 0;
	count++;
	printf("%d\n", &count);
	printf("%d\n", count);
}

int main()
{
	func(); // 1
	func(); // 1
	func(); // 1
	func(); // 1
	return 0;
}
