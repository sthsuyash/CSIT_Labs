#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// If page found, updates the second chance bit to true
static bool findAndUpdate(int x, int arr[], bool second_chance[], int frames)
{
    int i;

    for (i = 0; i < frames; i++)
    {
        if (arr[i] == x)
        {
            // Mark that the page deserves a second chance
            second_chance[i] = true;

            // Return 'true', that is there was a hit
            // and so there's no need to replace any page
            return true;
        }
    }

    // Return 'false' so that a page for replacement is selected
    // as the requested page doesn't exist in memory
    return false;
}

// Updates the page in memory and returns the pointer
static int replaceAndUpdate(int x, int arr[], bool second_chance[], int frames, int pointer)
{
    while (1)
    {
        // We found the page to replace
        if (!second_chance[pointer])
        {
            // Replace with new page
            arr[pointer] = x;

            // Return updated pointer
            return (pointer + 1) % frames;
        }

        // Mark it 'false' as it got one chance
        // and will be replaced next time unless accessed again
        second_chance[pointer] = false;

        // Pointer is updated in round robin manner
        pointer = (pointer + 1) % frames;
    }
}

static void printHitsAndFaults(char *reference_string, int frames)
{
    int pointer, i, l = 0, x, pf;

    // Initially, we consider frame 0 is to be replaced
    pointer = 0;

    // Number of page faults
    pf = 0;

    // Create an array to hold page numbers
    int *arr = (int *)malloc(frames * sizeof(int));

    // No pages initially in frame, which is indicated by -1
    memset(arr, -1, frames * sizeof(int));

    // Create second chance array.
    // Can also be a byte array for optimizing memory
    bool *second_chance = (bool *)malloc(frames * sizeof(bool));

    // Split the string into tokens, that is page numbers, based on space
    char *str;
    str = strtok(reference_string, " ");

    while (str != NULL)
    {
        x = atoi(str);

        // Finds if there exists a need to replace any page at all
        if (!findAndUpdate(x, arr, second_chance, frames))
        {
            // Selects and updates a victim page
            pointer = replaceAndUpdate(x, arr, second_chance, frames, pointer);

            // Update page faults
            pf++;
        }

        str = strtok(NULL, " ");
    }

    printf("Total page faults were %d\n", pf);

    free(arr);
    free(second_chance);
}

// Driver code
int main()
{
    char reference_string[] = "0 4 1 4 2 4 3 4 2 4 0 4 1 4 2 4 3 4";
    int frames = 3;

    printHitsAndFaults(reference_string, frames);

    return 0;
}
