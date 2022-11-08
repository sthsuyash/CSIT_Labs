#include <stdio.h>

void sort();

int main()
{
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	int arr[n];

	// data entry
	printf("Enter the data:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	// sort
	sort(arr, n);

	// print sorted
	printf("Sorted Numbers:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

// swap function
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// sort function
void sort(int mat[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (mat[j] > mat[j + 1])
			{
				swap(&mat[j], &mat[j + 1]);
			}
		}
	}
}
