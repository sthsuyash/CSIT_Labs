#include <stdio.h>

int main()
{
	int i, arr[3], sum = 0;
	printf("Enter any three integer numbers: ");
	for (i = 0; i <= 2; i++)
	{
		scanf("%d", arr + i);
		sum += *(arr + i);
		// scanf("%d",&arr[i]);
		// sum+=arr[i];
	}
	printf("\nSum is %d", sum);
	
	return 0;
}
