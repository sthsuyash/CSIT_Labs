/*
 * Cpp program to find Primitive roots of a given number
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include "./returnName.h"
#include "./name.h"

using namespace std;

bool isPrime(int);
int power(int, unsigned int, int);
void findPrimeFactors(unordered_set<int> &, int);
vector<int> findPrimitiveRoots(int);

int main()
{
    generateHeader("Program to find Primitive roots of a given number");
    int n;
    cout << "Enter a prime number (n): ";
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

    generateName(14);
    cin.get();
    return 0;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void findPrimeFactors(unordered_set<int> &s, int n)
{
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n / i;
        }
    }

    if (n > 2)
        s.insert(n);
}

vector<int> findPrimitiveRoots(int n)
{
    unordered_set<int> s;

    if (!isPrime(n))
    {
        vector<int> emptyResult;
        return emptyResult;
    }

    int phi = n - 1;
    findPrimeFactors(s, phi);

    vector<int> primitiveRoots;

    for (int r = 2; r <= phi; r++)
    {
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (power(r, phi / (*it), n) == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            primitiveRoots.push_back(r);
    }

    return primitiveRoots;
}