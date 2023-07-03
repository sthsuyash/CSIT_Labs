#include <stdio.h>
#include "utility.h"

void sort_processes(int *bt, int *at, int *p, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}

void get_timings(int *bt, int *at, int *ct, int *tat, int *wt, int *p, int n)
{
    sort_processes(bt, at, p, n);

    ct[0] = bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (int i = 1; i < n; i++)
    {
        // Calculate the completion time of the current process
        if (at[i] > ct[i - 1])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }

        // Calculate the turnaround time and waiting time of the current process
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

int main()
{
    // int i, n = 5;               // Number of processes
    // int p[] = {1, 2, 3, 4, 5};  // Process IDs
    // int bt[] = {5, 4, 3, 2, 4}; // Burst times of processes
    // int at[] = {4, 6, 0, 6, 5}; // Arrival times of processes

    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], at[n];

    int ct[n], tat[n], wt[n];

    get_inputs(p, at, bt, n);

    get_timings(bt, at, ct, tat, wt, p, n);

    print_table(p, at, bt, ct, tat, wt, n);
    print_gantt_chart(at, ct, p, n);

    return 0;
}
