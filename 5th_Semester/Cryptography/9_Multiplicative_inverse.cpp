/*
 * C++ program to find modular inverse of A under modulo M
 */

#include <bits/stdc++.h>
#include "./returnName.h"
using namespace std;

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }
    return -1; // Modular inverse does not exist
}

int main()
{
    generateHeader("Program to find modular inverse of A under modulo M");
    int a, m, result;

    cout << "Enter two positive integers a and m (a > m): ";
    cin >> a >> m;

    result = modInverse(a, m);
    if (result == -1)
    {
        cout << "Modular inverse of " << a << " under modulo " << m << " does not exist." << endl;
    }
    else
    {
        cout << "Modular inverse of " << a << " under modulo " << m << " is " << result << "." << endl;
    }

    cin.get();
    return 0;
}
