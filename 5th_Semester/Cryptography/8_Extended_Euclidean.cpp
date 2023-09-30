/*
 * Program to perform the Extended Euclidean Algorithm
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include "./returnName.h"
using namespace std;

vector<vector<long long>> extendedEuclideanTable(long long, long long);

int main()
{
    generateHeader("Program to perform the Extended Euclidean Algorithm");
    long long a, b;

    cout << "Enter two positive integers a and b (a > b): ";
    cin >> a >> b;

    vector<vector<long long>> table = extendedEuclideanTable(a, b);

    // Display the table header
    cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;
    cout << "|   i        |   r[i-1]   |    r[i]    |    q[i]    |   x[i-2]   |   x[i-1]   |    x[i]    |   y[i-2]   |   y[i-1]   |    y[i]    |" << endl;
    cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;

    // Display the table rows with equal spacing
    for (const auto &row : table)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            cout << "| " << setw(10) << row[i] << " ";
        }
        cout << "|" << endl;
    }
    cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;

    long long gcd = table.back()[1];
    long long x = table.back()[8];
    long long y = table.back()[9];

    cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
    cout << "x = " << x << ", y = " << y << endl;

    cin.get();
    return 0;
}

// Function to perform the Extended Euclidean Algorithm and create a table
vector<vector<long long>> extendedEuclideanTable(long long a, long long b)
{
    vector<vector<long long>> table;

    long long rPrev = a, r = b;
    long long xPrev = 1, xCurr = 0;
    long long yPrev = 0, yCurr = 1;

    table.push_back({0, rPrev, r, rPrev / r, xPrev, xCurr, yPrev, yCurr, -1, -1});

    while (r != 0)
    {
        long long q = rPrev / r;
        long long temp = r;

        r = rPrev - q * r;
        rPrev = temp;

        temp = xCurr;
        xCurr = xPrev - q * xCurr;
        xPrev = temp;

        temp = yCurr;
        yCurr = yPrev - q * yCurr;
        yPrev = temp;

        table.push_back({static_cast<long long>(table.size()), rPrev, r, static_cast<long long>(q), xPrev, xCurr, yPrev, yCurr, xPrev, yPrev});
    }
    return table;
}