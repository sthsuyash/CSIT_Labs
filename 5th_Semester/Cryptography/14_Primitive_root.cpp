/*
 * Cpp program to find Primitive roots of a given number
 */

#include <iostream>
#include <vector>
// #include "./returnName.h"

using namespace std;

// Function to calculate (a^b) % m using modular exponentiation
int power(int a, int b, int m)
{
    int result = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b / 2;
    }
    return result;
}

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find primitive roots of a given number n
vector<int> findPrimitiveRoots(int n)
{
    vector<int> primitiveRoots;

    for (int r = 2; r < n; r++)
    {
        if (gcd(r, n) == 1)
        {
            bool isPrimitiveRoot = true;
            for (int i = 1; i <= n - 2; i++)
            {
                if (power(r, i, n) == 1)
                {
                    isPrimitiveRoot = false;
                    break;
                }
            }
            if (isPrimitiveRoot)
            {
                primitiveRoots.push_back(r);
            }
        }
    }

    return primitiveRoots;
}

int main()
{
    // generateHeader("Program to find Primitive roots of a given number");
    int n;
    do{
        cout << "Enter a positive integer: ";
        cin >> n;
        vector<int> primitiveRoots = findPrimitiveRoots(n);

        if (primitiveRoots.empty())
        {
            cout << "No primitive roots found for " << n << endl;
        }
        else
        {
            cout << "Primitive roots of " << n << " are: ";
            for (int root : primitiveRoots)
            {
                cout << root << " ";
            }
            cout << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            break;

    } while (true);
    return 0;
}
