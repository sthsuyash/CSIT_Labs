#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int n, i, j, total_waiting_time = 0, total_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;
    struct process temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].burst_time > processes[j + 1].burst_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    total_turnaround_time += processes[0].turnaround_time;

    for (i = 1; i < n; i++)
    {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    average_waiting_time = (float)total_waiting_time / n;
    average_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", average_turnaround_time);

    return 0;
}
