// C Program to simulate FCFS Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

int calculate_seek_time(int requests[], int n, int start)
{
    int total_seek_time = 0;
    int current_position = start;

    for (int i = 0; i < n; i++)
    {
        int seek_distance = abs(requests[i] - current_position);
        total_seek_time += seek_distance;
        current_position = requests[i];
    }
    return total_seek_time;
}

int main()
{
    // Example requests (track numbers)
    // int requests[] = {98, 183, 41, 122, 14, 124, 65, 67};
    // int n = sizeof(requests) / sizeof(requests[0]);
    // int starting_position = 53;
    int n, starting_position;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the starting position of the disk head: ");
    scanf("%d", &starting_position);

    int seek_time = calculate_seek_time(requests, n, starting_position);
    printf("Total Seek Time: %d\n", seek_time);

    return 0;
}
