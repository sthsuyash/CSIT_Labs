#include <stdio.h>

int main()
{
    int n, i, j, arrival_time[10], burst_time[10], waiting_time[10], turnaround_time[10], total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process: \n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d:", i + 1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
    }

    // Calculating waiting time and turnaround time
    waiting_time[0] = 0;
    for (i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
    }
    for (i = 0; i < n; i++)
        turnaround_time[i] = burst_time[i] + waiting_time[i];

    // Calculating total waiting time and total turnaround time
    for (i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculating average waiting time and average turnaround time
    avg_waiting_time = (float)total_waiting_time / n;
    avg_turnaround_time = (float)total_turnaround_time / n;

    // Displaying results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    printf("\nAverage Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);

    return 0;
}
