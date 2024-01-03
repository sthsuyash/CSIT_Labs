/*
 *
 * Problem: Travelling Salesman Problem
 *
 * Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.
 *
 * Time Complexity: O(n^2 * 2^n)
 * Space Complexity: O(n * 2^n)
 *
 */

#include <iostream>
#include <climits>
using namespace std;

#define MAX 9999

int n;
int distan[20][20];

int completed_visit;

int DP[32][8];

int TSP(int mark, int position)
{
    if (mark == completed_visit)
        return distan[position][0];
    if (DP[mark][position] != -1)
        return DP[mark][position];
    int answer = MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mark & (1 << city)) == 0)
        {
            int newAnswer = distan[position][city] + TSP(mark | (1 << city), city);
            answer = min(answer, newAnswer);
        }
    }
    return DP[mark][position] = answer;
}

int main()
{
    cout << "Enter the number of cities: ";
    cin >> n;

    completed_visit = (1 << n) - 1;

    cout << "Enter the distance matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> distan[i][j];
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            DP[i][j] = -1;
    }

    cout << "Minimum Distance Travelled -> " << TSP(1, 0) << endl;

    return 0;
}
