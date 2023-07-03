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

    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
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

    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (int i = 1; i < n; i++)
    {
        // Calculate the completion time of the current process
        ct[i] = ct[i - 1] + bt[i];

        // Calculate the turnaround time and waiting time of the current process
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

int main()
{
    int n;
    n = 5;
    int p[] = {1, 2, 3, 4, 5};
    int at[] = {3, 1, 4, 0, 2};
    int bt[] = {1, 4, 2, 6, 3};
    int ct[n], tat[n], wt[n];

    get_timings(bt, at, ct, tat, wt, p, n);

    printf("Before sorting:\n");
    print_table(p, at, bt, ct, tat, wt, n);

    printf("\n");

    print_gantt_chart(at, ct, p, n);

    printf("\n");
    print_average_times(tat, wt, n);

    return 0;
}
