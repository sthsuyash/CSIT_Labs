#include <stdio.h>
#include <stdlib.h>

#include "../name.c"

struct Process
{
    int pid;
    int priority;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_priority(struct Process *process_list, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (process_list[j].priority < process_list[j + 1].priority)
            {
                swap(&process_list[j], &process_list[j + 1]);
            }
        }
    }
}

int find_highest_priority_process(struct Process *process_list, int n, int current_time)
{
    int highest_priority = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (process_list[i].remaining_time > 0 && process_list[i].priority > highest_priority && process_list[i].burst_time <= current_time)
        {
            highest_priority = process_list[i].priority;
            index = i;
        }
    }
    return index;
}

void calculate_waiting_time(struct Process *process_list, int n)
{
    for (int i = 0; i < n; i++)
    {
        process_list[i].waiting_time = process_list[i].turnaround_time - process_list[i].burst_time;
    }
}

void calculate_turnaround_time(struct Process *process_list, int n)
{
    for (int i = 0; i < n; i++)
    {
        process_list[i].turnaround_time = process_list[i].waiting_time + process_list[i].burst_time;
    }
}

void calculate_average_times(struct Process *process_list, int n, float *avg_waiting_time, float *avg_turnaround_time)
{
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += process_list[i].waiting_time;
        total_turnaround_time += process_list[i].turnaround_time;
    }
    *avg_waiting_time = total_waiting_time / n;
    *avg_turnaround_time = total_turnaround_time / n;
}

void print_table(struct Process *process_list, int n)
{
    printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process_list[i].pid, process_list[i].priority, process_list[i].burst_time, process_list[i].waiting_time, process_list[i].turnaround_time);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *process_list = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++)
    {
        process_list[i].pid = i + 1;
        printf("Enter the priority of process %d: ", process_list[i].pid);
        scanf("%d", &process_list[i].priority);
        printf("Enter the burst time of process %d: ", process_list[i].pid);
        scanf("%d", &process_list[i].burst_time);
        process_list[i].remaining_time = process_list[i].burst_time;
    }

    sort_by_priority(process_list, n);

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n)
    {
        int index = find_highest_priority_process(process_list, n, current_time);
        if (index == -1)
        {
            current_time++;
            continue;
        }
        process_list[index].remaining_time--;
        current_time++;
        if (process_list[index].remaining_time == 0)
        {
            completed_processes++;
            process_list[index].turnaround_time = current_time;
        }
    }

    calculate_waiting_time(process_list, n);
    calculate_turnaround_time(process_list, n);

    float avg_waiting_time, avg_turnaround_time;
    calculate_average_times(process_list, n, &avg_waiting_time, &avg_turnaround_time);

    print_table(process_list, n);

    printf("\nAverage Waiting Time: %f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time);

    name("5(f)");

    return 0;
}