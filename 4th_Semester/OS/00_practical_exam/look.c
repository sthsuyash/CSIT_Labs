#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 8;

// Compare function for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void LOOK(int arr[], int head, char *direction)
{
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int left_size = 0, right_size = 0;

    // Appending values which are currently at left and right direction from the head.
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    // Sorting left and right arrays for servicing tracks in the correct sequence.
    qsort(left, left_size, sizeof(int), compare);
    qsort(right, right_size, sizeof(int), compare);

    // Run the while loop two times, one by one scanning right and left side of the head.
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
            // Reversing the direction
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

                // Accessed track is now the new head
                head = cur_track;
            }
            // Reversing the direction
            strcpy(direction, "left");
        }
    }

    printf("\nTotal number of seek operations = %d\n", seek_count);
}

int main()
{
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

    LOOK(arr, head, direction);

    return 0;
}