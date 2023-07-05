#include <stdio.h>
#include <stdlib.h>

int size = 8;
int disk_size = 200;

void CSCAN(int arr[], int head)
{
	int seek_count = 0;
	int distance, cur_track;
	int left[size], right[size];
	int left_size = 0, right_size = 0;

	// Appending end values which has to be visited before reversing the direction
	left[left_size++] = 0;
	right[right_size++] = disk_size - 1;

	// Tracks on the left of the head will be serviced when once the head comes back to the beginning (left end).
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < head)
			left[left_size++] = arr[i];
		if (arr[i] > head)
			right[right_size++] = arr[i];
	}

	// Sorting left and right arrays
	for (int i = 0; i < left_size - 1; i++)
	{
		for (int j = i + 1; j < left_size; j++)
		{
			if (left[i] > left[j])
			{
				int temp = left[i];
				left[i] = left[j];
				left[j] = temp;
			}
		}
	}

	for (int i = 0; i < right_size - 1; i++)
	{
		for (int j = i + 1; j < right_size; j++)
		{
			if (right[i] > right[j])
			{
				int temp = right[i];
				right[i] = right[j];
				right[j] = temp;
			}
		}
	}

	// First service the requests on the right side of the head.
	for (int i = 0; i < right_size; i++)
	{
		cur_track = right[i];
		// Appending current track to seek sequence
		printf("%d ", cur_track);
		// Calculate absolute distance
		distance = abs(cur_track - head);
		// Increase the total count
		seek_count += distance;
		// Accessed track is now new head
		head = cur_track;
	}

	// Once reached the right end jump to the beginning.
	head = 0;

	// Adding seek count for head returning from 199 to 0
	seek_count += (disk_size - 1);

	// Now service the requests again which are left.
	for (int i = 0; i < left_size; i++)
	{
		cur_track = left[i];
		// Appending current track to seek sequence
		printf("%d ", cur_track);
		// Calculate absolute distance
		distance = abs(cur_track - head);
		// Increase the total count
		seek_count += distance;
		// Accessed track is now the new head
		head = cur_track;
	}
	printf("\nTotal number of seek operations = %d\n", seek_count);
}

void main()
{
	// Request array
	// int arr[] = {98, 183, 41, 122, 14, 124, 65, 67};
	// int head = 53;
	int n, head;
	printf("Enter number of requests: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter requests: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter the head position: ");
	scanf("%d", &head);

	CSCAN(arr, head);
}
