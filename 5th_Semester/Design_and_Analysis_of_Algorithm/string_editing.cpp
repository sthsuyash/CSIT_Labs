/*
 * Program: String Editing
 *
 * The problem is to find the minimum number of operations required to convert one string into another.
 * The operations allowed are:
 * 1. Insertion
 * 2. Deletion
 * 3. Substitution
 * The cost of each operation is 1.
 *
 * Time Complexity: O(mn)
 * Space Complexity: O(mn)
 */
#include <iostream>
#include <string>
using namespace std;

int min(int, int, int);
int editDistance(const string &str1, const string &str2);

int main()
{
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    int distance = editDistance(str1, str2);

    cout << "Edit Distance between \"" << str1 << "\" and \"" << str2 << "\" is: " << distance << endl;

    return 0;
}

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistance(const string &str1, const string &str2)
{
    int m = str1.length();
    int n = str2.length();

    // Create a 2D array to store results of subproblems
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = new int[n + 1];
    }

    // Fill the dp table in a bottom-up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j; // Insert j characters to make str1 equal to empty str2
            else if (j == 0)
                dp[i][j] = i; // Remove i characters from str1 to make it equal to empty str2
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed for matching characters
            else
                dp[i][j] = 1 + min(dp[i - 1][j],      // Remove
                                   dp[i][j - 1],      // Insert
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    int result = dp[m][n];

    // Deallocate memory
    for (int i = 0; i <= m; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}