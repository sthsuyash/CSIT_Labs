#include <stdio.h>
#include <stdbool.h>

int search(int frames[], int n, int page)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == page)
        {
            return i; // Page found in frame
        }
    }
    return -1; // Page not found in frame
}

void printFrames(int frames[], int n)
{
    printf("| ");
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == -1)
        {
            printf("  | ");
        }
        else
        {
            printf("%d | ", frames[i]);
        }
    }
    printf("\n");
}

void fifo(int pages[], int n, int capacity)
{
    int frames[capacity];
    int faults = 0;
    int nextFrame = 0; // Index of the next frame to be replaced

    // Initialize frames with -1 to indicate an empty frame
    for (int i = 0; i < capacity; i++)
    {
        frames[i] = -1;
    }

    printf("Page Replacement Process:\n");
    printf("--------------------------\n");

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        printf("Page Requested: %d\n", page);

        if (search(frames, capacity, page) == -1)
        {
            // Page fault: Page not found in frame

            // Replace the page in the nextFrame index
            frames[nextFrame] = page;

            // Increment the nextFrame index in a circular manner
            nextFrame = (nextFrame + 1) % capacity;

            faults++;
            printf("Page Fault!\n");
        }
        else
        {
            printf("Page Found in Frame!\n");
        }

        // Print the current state of frames
        printFrames(frames, capacity);
        printf("--------------------------\n");
    }

    printf("\n");
    printf("Total Page Faults: %d\n", faults);
    printf("Page Fault Rate: %.3f\n", (float)faults / n);
    printf("\n ");
    printf("Total Page hits: %d\n", n - faults);
    printf("Page Hit Rate: %.3f\n", (float)(n - faults) / n);
}

int main()
{
    int n;        // Number of page requests
    int capacity; // Capacity of the frame

    // Input the number of page requests
    printf("Enter the number of page requests: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Error: Invalid number of page requests.\n");
        return 0;
    }

    // Input the page requests
    int pages[n];
    printf("Enter the page requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    // Input the capacity of the frame
    printf("Enter the capacity of the frame: ");
    scanf("%d", &capacity);

    if (capacity <= 0)
    {
        printf("Error: Invalid capacity.\n");
        return 0;
    }

    // Simulate FIFO page replacement algorithm
    fifo(pages, n, capacity);

    return 0;
}
