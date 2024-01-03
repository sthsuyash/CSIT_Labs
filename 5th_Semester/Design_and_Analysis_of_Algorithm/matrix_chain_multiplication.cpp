/*
 *
 * Program: Matrix Chain Multiplication
 *
 * The matrix chain multiplication problem is a combinatorial optimization problem where we have a sequence of matrices and the goal is to find the most efficient way to multiply these matrices.
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 */

#include <iostream>
#include <climits>

using namespace std;

int MatrixChainOrder(int p[], int i, int j, int **dp, int **bracket);
void printOptimalParenthesis(int i, int j, int **bracket);

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int *arr = new int[n];
    int **dp = new int *[n];
    int **bracket = new int *[n];

    for (int i = 0; i < n; ++i)
    {
        dp[i] = new int[n];
        bracket[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = -1;
            bracket[i][j] = -1;
        }
    }

    cout << "Enter dimensions of matrices:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, n - 1, dp, bracket) << endl;

    cout << "Optimal Parenthesization: ";
    printOptimalParenthesis(1, n - 1, bracket);

    // Deallocate memory
    for (int i = 0; i < n; ++i)
    {
        delete[] dp[i];
        delete[] bracket[i];
    }
    delete[] arr;
    delete[] dp;
    delete[] bracket;

    return 0;
}

int MatrixChainOrder(int p[], int i, int j, int **dp, int **bracket)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int k;
    int mini = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k, dp, bracket) +
                MatrixChainOrder(p, k + 1, j, dp, bracket) +
                p[i - 1] * p[k] * p[j];

        if (count < mini)
        {
            mini = count;
            bracket[i][j] = k;
        }
    }

    dp[i][j] = mini;
    return mini;
}

void printOptimalParenthesis(int i, int j, int **bracket)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }

    cout << "(";
    printOptimalParenthesis(i, bracket[i][j], bracket);
    printOptimalParenthesis(bracket[i][j] + 1, j, bracket);
    cout << ")";
}
