// WAP in C that takes numbers as input from the keyboard and finds the maximum. IMP Question
#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int mat[n], max;

	// data entry
	printf("Enter the data:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mat[i]);
	}

	max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (max < mat[i])
			max = mat[i];
	}
	printf("Largest number : %d", max);

	return 0;
}
