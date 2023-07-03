#include <stdio.h>
#include <string.h>
#include "utility.h"
#include <limits.h>

void sort_processes(int *bt, int *at, int *p, int n)
{
    // Sorting based on arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

    int rem_bt[n];
    memcpy(rem_bt, bt, sizeof(rem_bt));

    int completed = 0, t = 0, min_bt = INT_MAX, min_bt_index;

    while (completed != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && rem_bt[i] < min_bt && rem_bt[i] > 0)
            {
                min_bt = rem_bt[i];
                min_bt_index = i;
            }
        }

        rem_bt[min_bt_index]--;

        if (rem_bt[min_bt_index] == 0)
        {
            completed++;
            min_bt = INT_MAX;
            ct[min_bt_index] = t + 1;
            tat[min_bt_index] = ct[min_bt_index] - at[min_bt_index];
            wt[min_bt_index] = tat[min_bt_index] - bt[min_bt_index];
        }

        t++;
    }
}

int main()
{
    int n = 5;
    int p[] = {1, 2, 3, 4, 5};
    int at[] = {3, 1, 4, 0, 2};
    int bt[] = {1, 4, 2, 6, 3};
    int ct[n], tat[n], wt[n];

    get_timings(bt, at, ct, tat, wt, p, n);

    printf("After SRTN scheduling:\n");
    print_table(p, at, bt, ct, tat, wt, n);

    printf("\n");

    return 0;
}
