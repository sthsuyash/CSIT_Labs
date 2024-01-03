/*
*
* Problem: Subset Sum Problem
* 
* Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
*
* Time Complexity: O(2^n)
* Space Complexity: O(n)
*
*/

#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum, int subset[]);
void subsetSum(int set[], int n, int sum);

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    cout << "Subset(s) with sum " << targetSum << ": ";
    subsetSum(set, n, targetSum);

    return 0;
}

// Function to check if there is a subset with a given sum using backtracking
bool isSubsetSum(int set[], int n, int sum, int subset[])
{
    // Base cases
    if (sum == 0)
    {
        // Found a subset with the given sum
        for (int i = 0; i < n; ++i)
        {
            if (subset[i] == 1)
            {
                cout << set[i] << " ";
            }
        }
        cout << endl;
        return true;
    }

    if (n == 0 && sum != 0)
    {
        // Subset not found
        return false;
    }

    // If the last element is greater than the sum, it cannot be included
    if (set[n - 1] > sum)
    {
        return isSubsetSum(set, n - 1, sum, subset);
    }

    // Recur with or without the last element
    subset[n - 1] = 0;
    bool withoutLast = isSubsetSum(set, n - 1, sum, subset);

    subset[n - 1] = 1;
    bool withLast = isSubsetSum(set, n - 1, sum - set[n - 1], subset);

    return withoutLast || withLast;
}

// Wrapper function to initialize the backtracking process
void subsetSum(int set[], int n, int sum)
{
    int subset[n] = {0}; // Initialize subset array
    if (!isSubsetSum(set, n, sum, subset))
    {
        cout << "No subset with the given sum found." << endl;
    }
}