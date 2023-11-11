/*
 * Program: Job Sequencing Problem
 *
 * Job Sequencing Problem is a variation of the Activity Selection Problem.
 * The difference between the two is that in the Activity Selection Problem, a single resource is available and each activity is to be scheduled in this single resource, whereas in Job Sequencing Problem there are multiple resources available and each activity is to be scheduled in a single resource.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"

using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

int compare(const void *, const void *);
void jobSequencing(struct Job[], int);

int main()
{
    // generateHeader("Job Sequencing Problem Program");

    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    struct Job jobs[n];
    cout << "Enter the deadline and profit of each job: ";
    for (int i = 0; i < n; i++)
    {
        jobs[i].id = i + 1;
        cin >> jobs[i].deadline >> jobs[i].profit;
    }
    jobSequencing(jobs, n);

    // generateName("0");
    return 0;
}

/*
 * This function compares two jobs based on their profit
 *
 * @param a - pointer to the first job
 * @param b - pointer to the second job
 *
 * @returns 1 if profit of the first job is greater than that of the second job, else -1
 */
int compare(const void *a, const void *b)
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

/*
 * This function prints the maximum profit sequence of jobs
 *
 * @param jobs - array of jobs
 * @param n - number of jobs
 */
void jobSequencing(struct Job jobs[], int n)
{
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        jobs[i].deadline > maxDeadline ? maxDeadline = jobs[i].deadline : maxDeadline;

    int slots[maxDeadline]; // array to store job slots
    for (int i = 0; i < maxDeadline; i++)
        slots[i] = -1;

    int totalProfit = 0;
    int numJobs = 0;
    for (int i = 0; i < n; i++)
    {
        int deadline = jobs[i].deadline;
        // find a slot before the deadline for the current job
        while (deadline > 0 && slots[deadline - 1] != -1)
            deadline--;
        // if a slot is found, assign the job to the slot
        if (deadline > 0)
        {
            slots[deadline - 1] = i;
            totalProfit += jobs[i].profit;
            numJobs++;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;
    cout << "Number of jobs: " << numJobs << endl;
    cout << "Maximum profit sequence of jobs : ";
    for (int i = 0; i < maxDeadline; i++)
    {
        (slots[i] != -1) ? cout << jobs[slots[i]].id << " " : cout << "";
    }
    cout << endl;
}

// {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
