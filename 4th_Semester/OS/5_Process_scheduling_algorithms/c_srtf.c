#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

int main()
{
    int n, i, j, current_time = 0, completed = 0, min_burst_time, min_index;
    float total_waiting_time = 0, total_turnaround_time = 0, average_waiting_time, average_turnaround_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    while (completed < n)
    {
        min_burst_time = 9999;
        min_index = -1;

        for (i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_burst_time && processes[i].remaining_time > 0)
            {
                min_burst_time = processes[i].remaining_time;
                min_index = i;
            }
        }

        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            processes[min_index].remaining_time--;
            current_time++;

            if (processes[min_index].remaining_time == 0)
            {
                completed++;
                processes[min_index].waiting_time = current_time - processes[min_index].arrival_time - processes[min_index].burst_time;
                processes[min_index].turnaround_time = current_time - processes[min_index].arrival_time;
                total_waiting_time += processes[min_index].waiting_time;
                total_turnaround_time += processes[min_index].turnaround_time;
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    average_waiting_time = total_waiting_time / n;
    average_turnaround_time = total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", average_turnaround_time);

    return 0;
}
