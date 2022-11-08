#include <stdio.h>

int main()
{
	int num, *ptr;
	num = 100;
	ptr = &num;
	num = 200;
	printf("Address is %d", ptr);
	printf("Value is %d", *ptr);

	//	int* ptr;//valid
	//	int * ptr;//valid
	//	int *ptr; //valid
	//
	//	float *ptr;
	//	double *ptr;
	//	char *ptr;

	return 0;
}
