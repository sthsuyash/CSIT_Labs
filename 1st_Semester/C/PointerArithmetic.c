#include <stdio.h>

int main()
{
	int arr[] = {100, 200, 300};

	int i, *ptr;

	ptr = &arr[2];
	for (i = 0; i <= 2; i++)
	{
		printf("Address of arr[%d] is %d\n", i, ptr);
		printf("Value of arr[%d] is %d\n", i, *ptr);
		ptr--;
	}

	//	int *ptr1 = &arr[1], *ptr2=&arr[2];
	//	printf("%d\t%d",ptr1, ptr2);
	//
	//	if(ptr1 > ptr2){
	//		printf("ptr1 is greater");
	//	}else {
	//		printf("prt2 is greater");
	//	}

	return 0;
}
