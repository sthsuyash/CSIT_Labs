#include <stdio.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int i, n, time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    int completed[MAX_PROCESSES];
    int front = 0, rear = 0;
    struct process queue[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        completed[i] = 0;
    }

    while (front != rear || time == 0)
    {
        for (i = 0; i < n; i++)
        {
            if (processes[i].arrival_time == time)
            {
                queue[rear] = processes[i];
                rear = (rear + 1) % MAX_PROCESSES;
            }
        }

        if (queue[front].remaining_time <= TIME_QUANTUM && queue[front].remaining_time > 0)
        {
            time += queue[front].remaining_time;
            queue[front].remaining_time = 0;
            completed[queue[front].pid - 1] = 1;
            queue[front].turnaround_time = time - queue[front].arrival_time;
            queue[front].waiting_time = queue[front].turnaround_time - queue[front].burst_time;
            total_waiting_time += queue[front].waiting_time;
            total_turnaround_time += queue[front].turnaround_time;
            front = (front + 1) % MAX_PROCESSES;
        }
        else if (queue[front].remaining_time > 0)
        {
            time += TIME_QUANTUM;
            queue[front].remaining_time -= TIME_QUANTUM;
            rear = (rear + 1) % MAX_PROCESSES;
            queue[rear - 1] = queue[front];
            front = (front + 1) % MAX_PROCESSES;
        }
        else
        {
            front = (front + 1) % MAX_PROCESSES;
        }
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);

    return 0;
}
