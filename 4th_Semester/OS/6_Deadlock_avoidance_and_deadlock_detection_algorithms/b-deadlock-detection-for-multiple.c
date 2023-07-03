#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void print_deadlocked_processes(bool *deadlocked, int n)
{
    bool found = false;

    printf("Deadlocked processes: ");
    for (int i = 0; i < n; i++)
    {
        if (deadlocked[i])
        {
            printf("%d ", i);
            found = true;
        }
    }

    if (!found)
    {
        printf("None");
    }

    printf("\n");
}

void detect_deadlock(int allocation[][MAX_RESOURCES], int max_claim[][MAX_RESOURCES], int available[], int n, int m)
{
    bool finish[MAX_PROCESSES] = {false};
    bool deadlocked[MAX_PROCESSES] = {false};
    int work[MAX_RESOURCES];

    // Initialize the work array with the available resources
    for (int i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    // Find the processes that have not finished and can be allocated resources
    bool found;
    do
    {
        found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool can_allocate = true;
                for (int j = 0; j < m; j++)
                {
                    if (max_claim[i][j] - allocation[i][j] > work[j])
                    {
                        can_allocate = false;
                        break;
                    }
                }

                if (can_allocate)
                {
                    // Process i can be allocated resources
                    finish[i] = true;
                    found = true;

                    // Add the allocated resources back to the work array
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
    } while (found);

    // Find the processes that are deadlocked
    for (int i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            deadlocked[i] = true;
        }
    }

    // Print the deadlocked processes
    print_deadlocked_processes(deadlocked, n);
}

int main()
{
    int n, m;                                     // Number of processes and resources
    int allocation[MAX_PROCESSES][MAX_RESOURCES]; // Allocated resources for each process
    int max_claim[MAX_PROCESSES][MAX_RESOURCES];  // Maximum claim of each process
    int available[MAX_RESOURCES];                 // Available instances of each resource

    // Input the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Input the allocated resources for each process
    printf("Enter the allocated resources:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input the maximum claim of each process
    printf("Enter the maximum claim for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max_claim[i][j]);
        }
    }

    // Input the available instances of each resource
    printf("Enter the available instances of each resource:\n");
    for (int i = 0; i < m; i++)
    {
        printf("Resource %d: ", i);
        scanf("%d", &available[i]);
    }

    // Detect deadlock
    detect_deadlock(allocation, max_claim, available, n, m);

    return 0;
}
