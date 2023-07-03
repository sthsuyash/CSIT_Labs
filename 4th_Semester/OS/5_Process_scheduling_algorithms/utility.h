#include <stdio.h>

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