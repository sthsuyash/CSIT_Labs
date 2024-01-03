/*
 * Program: 0/1 Knapsack Problem
 *
 * The 0/1 knapsack problem is a combinatorial optimization problem where we have a set of items, each with a weight and a value,
 * and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

int max(int, int);
int knapSack(int, int[], int[], int);

int main()
{
    cout << "Enter the number of items in a Knapsack: ";
    int n, W;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    cout << knapSack(W, w, v, n);

    return 0;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int knapSack(int W, int w[], int v[], int n)
{
    int i, wt;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (wt = 0; wt <= W; wt++)
        {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (w[i - 1] <= wt)
                K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
            else
                K[i][wt] = K[i - 1][wt];
        }
    }
    return K[n][W];
}