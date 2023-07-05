// SCAN Disk Scheduling algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 8;
int disk_size = 200;

void SCAN(int arr[], int head, char *direction)
{
	int seek_count = 0;
	int distance, cur_track;
	int left[size], right[size];
	int left_size = 0, right_size = 0;

	// Appending end values which has to be visited before reversing the direction
	if (strcmp(direction, "left") == 0)
		left[left_size++] = 0;
	else if (strcmp(direction, "right") == 0)
		right[right_size++] = disk_size - 1;

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

	// Run the while loop two times.
	// One by one scanning right and left of the head
	int run = 2;
	while (run--)
	{
		if (strcmp(direction, "left") == 0)
		{
			for (int i = left_size - 1; i >= 0; i--)
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
			strcpy(direction, "right");
		}
		else if (strcmp(direction, "right") == 0)
		{
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
			strcpy(direction, "left");
		}
	}

	printf("\nTotal number of seek operations = %d\n", seek_count);
}

// Driver code
int main()
{
	// Request array
	// int arr[] = {98, 183, 41, 122, 14, 124, 65, 67};
	// int head = 53;
	// char direction[] = "right";

	int n, head;
	printf("Enter the size of queue request: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the queue request: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Enter the initial head position: ");
	scanf("%d", &head);

	char direction[10];
	printf("Enter the direction of head movement (left/right): ");
	scanf("%s", direction);

	SCAN(arr, head, direction);

	return 0;
}
