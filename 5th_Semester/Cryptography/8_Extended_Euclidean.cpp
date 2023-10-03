#include <iostream>
#include <vector>
#include <iomanip>
#include "./returnName.h"

using namespace std;

vector<vector<long long>> extendedEuclideanTable(long long a, long long b);

int main()
{
    generateHeader("Program to perform the Extended Euclidean Algorithm");
    long long a, b;

    cout << "Enter two positive integers a and b (a > b): ";
    cin >> a >> b;
    vector<vector<long long>> table = extendedEuclideanTable(a, b);

    cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;
    cout << "|   i        |   r[i-1]   |    r[i]    |    q[i]    |   x[i-2]   |   x[i-1]   |    x[i]    |   y[i-2]   |   y[i-1]   |    y[i]    |" << endl;
    cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;

    for (size_t i = 0; i < table.size(); ++i)
    {
        const vector<long long> &row = table[i];
        for (size_t j = 0; j < row.size(); ++j)
        {
            cout << "| " << setw(10) << row[j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;

    long long gcd = table.back()[1];
    long long x = table.back()[8];
    long long y = table.back()[9];

    cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}

vector<vector<long long>> extendedEuclideanTable(long long a, long long b)
{
    vector<vector<long long>> table;
    long long rPrev = a, r = b;
    long long xPrev = 1, xCurr = 0;
    long long yPrev = 0, yCurr = 1;
    vector<long long> initialRow;
    initialRow.push_back(0);
    initialRow.push_back(rPrev);
    initialRow.push_back(r);
    initialRow.push_back(rPrev / r);
    initialRow.push_back(xPrev);
    initialRow.push_back(xCurr);
    initialRow.push_back(yPrev);
    initialRow.push_back(yCurr);
    initialRow.push_back(-1);
    initialRow.push_back(-1);
    table.push_back(initialRow);

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

        vector<long long> row;
        row.push_back(table.size());
        row.push_back(rPrev);
        row.push_back(r);
        row.push_back(q);
        row.push_back(xPrev);
        row.push_back(xCurr);
        row.push_back(yPrev);
        row.push_back(yCurr);
        row.push_back(xPrev);
        row.push_back(yPrev);
        table.push_back(row);
    }
    return table;
}