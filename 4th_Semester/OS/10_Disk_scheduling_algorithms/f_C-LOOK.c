#include <stdio.h>
#include <stdlib.h>

int size = 8;
int disk_size = 200;

// Function to perform C-LOOK on the request
// array starting from the given head
void CLOOK(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int left_count = 0, right_count = 0;

    // Tracks on the left of the
    // head will be serviced when
    // once the head comes back
    // to the beginning (left end)
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    // Sorting left and right arrays
    for (int i = 0; i < left_count - 1; i++)
    {
        for (int j = 0; j < left_count - i - 1; j++)
        {
            if (left[j] > left[j + 1])
            {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < right_count - 1; i++)
    {
        for (int j = 0; j < right_count - i - 1; j++)
        {
            if (right[j] > right[j + 1])
            {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // First service the requests
    // on the right side of the
    // head
    for (int i = 0; i < right_count; i++)
    {
        cur_track = right[i];

        // Calculate absolute distance
        distance = abs(cur_track - head);

        // Increase the total count
        seek_count += distance;

        // Accessed track is now new head
        head = cur_track;
    }

    // Once reached the right end
    // jump to the last track that
    // is needed to be serviced in
    // left direction
    seek_count += abs(head - left[0]);
    head = left[0];

    // Now service the requests again
    // which are left
    for (int i = 0; i < left_count; i++)
    {
        cur_track = left[i];

        // Calculate absolute distance
        distance = abs(cur_track - head);

        // Increase the total count
        seek_count += distance;

        // Accessed track is now the new head
        head = cur_track;
    }

    printf("Total number of seek operations = %d\n", seek_count);
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
    CLOOK(arr, head);

    return 0;
}
