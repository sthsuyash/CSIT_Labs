#include <stdio.h>
#include <stdlib.h>

void get_timings(int *, int *, int *, int *, int *, int *, int);
void swap(int *, int *);
void sort_processes(int *, int *, int *, int);
void print_table(int *, int *, int *, int *, int *, int *, int);
void print_gantt_chart(int *, int *, int *, int);
void print_average_times(int *, int *, int);

int main()
{
    // number of processes
    int n = 5;
    // process id's
    int p[] = {1, 2, 3, 4, 5};
    // arrival time
    int at[] = {3, 1, 4, 0, 2};
    // burst time
    int bt[] = {1, 4, 2, 6, 3};
    
    int ct[n], tat[n], wt[n];

    get_timings(bt, at, ct, tat, wt, p, n);

    printf("Before sorting:\n");
    print_table(p, at, bt, ct, tat, wt, n);

    printf("\n");

    print_gantt_chart(at, ct, p, n);

    printf("\n");
    print_average_times(tat, wt, n);

    system("pause");

    return 0;
}

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_gantt_chart(int *at, int *ct, int *p, int n)
{
    int empty = 0;

    for (int i = 0; i < n; i++)
    {
        if (at[i] > ct[i - 1])
        {
            empty += 1;
        }
    }

    printf("\nGantt Chart:\n");
    printf("+");
    for (int i = 0; i < n + empty; i++)
    {

        for (int j = 0; j < 9; j++)
        {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
    printf("|");
    for (int i = 0; i < n; i++)
    {

        if (at[i] > ct[i - 1])
        {
            printf("         |");
            printf("    P%d   |", p[i]);
        }
        else
        {

            printf("    P%d   |", p[i]);
        }
    }
    printf("\n");
    printf("+");
    for (int i = 0; i < n + empty; i++)
    {

        for (int j = 0; j < 9; j++)
        {
            printf("-");
        }
        printf("+");
    }
    printf("\n");

    printf("%d", at[0]);

    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
        {
            printf("         %d", ct[i - 1]);
            printf("         %d", at[i]);
        }
        else
        {
            printf("         %d", ct[i - 1]);
        }
    }
    printf("        %d\n", ct[n - 1]);
}

void print_table(int *p, int *at, int *bt, int *ct, int *tat, int *wt, int n)
{
    printf("Process\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

void get_inputs(int *p, int *at, int *bt, int n)
{
    int i;
    printf("Enter the process IDs: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
}

void print_average_times(int *tat, int *wt, int n)
{
    float avg_tat = 0, avg_wt = 0;

    for (int i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Average Turnaround Time: %f\n", avg_tat);
    printf("Average Waiting Time: %f\n", avg_wt);
}