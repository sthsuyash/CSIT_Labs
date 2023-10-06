/*
* Cpp program to find discrete logarithm using baby-step giant-step algorithm
*/

#include <iostream>
#include <cmath>
#include <unordered_map>
// #include "./returnName.h"

using namespace std;

int discreteLog(int, int, int);
int modularInverse(int, int);

int main()
{
    // generateHeader("Program to find discrete logarithm using baby-step giant-step algorithm");
    int g, y, n;
    do
    {
        cout << "Enter base (g): ";
        cin >> g;
        cout << "Enter value (y): ";
        cin >> y;
        cout << "Enter modulus (n): ";
        cin >> n;

        int result = discreteLog(g, y, n);
        if (result != -1)
            cout << "Discrete logarithm x such that " << g << "^x === " << y << " (mod " << n << ") is: " << result << endl;
        else
            cout << "No discrete logarithm found for the given inputs." << endl;

        char choice;
        cout << "Do you want to continue (y/n): ";
        cin >> choice;
        if (choice == 'n')
            break;
    } while (true);

    return 0;
}

// Function to find the discrete logarithm using the baby-step giant-step algorithm
int discreteLog(int g, int y, int n)
{
    unordered_map<int, int> giantStep;

    // Giant step: precompute g^(j*m) % n for j = 0, 1, 2, ...
    int m = static_cast<int>(sqrt(n)) + 1;
    int value = 1;
    for (int j = 0; j < m; ++j)
    {
        giantStep[value] = j;
        value = (value * g) % n;
    }

    // Compute g^(-m) % n
    int invM = 1;
    for (int j = 0; j < m; ++j)
    {
        invM = (invM * g) % n;
    }
    invM = modularInverse(invM, n); // Calculate modular inverse of g^(-m) % n

    // Baby step: search for a match
    value = y;
    for (int i = 0; i < m; ++i)
    {
        if (giantStep.find(value) != giantStep.end())
        {
            return i * m + giantStep[value];
        }
        value = (value * invM) % n;
    }

    return -1; // No discrete logarithm found
}

// Function to calculate modular inverse using extended Euclidean algorithm
int modularInverse(int a, int n)
{
    int t = 0, newT = 1;
    int r = n, newR = a;

    while (newR != 0)
    {
        int quotient = r / newR;
        int tempT = newT;
        newT = t - quotient * newT;
        t = tempT;

        int tempR = newR;
        newR = r - quotient * newR;
        r = tempR;
    }

    if (r > 1)
    {
        // Modular inverse doesn't exist
        return -1;
    }
    if (t < 0)
    {
        t += n;
    }

    return t;
}