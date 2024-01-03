/*
 * Program: Fibonacci Sequence Program
 *
 * Fibonacci sequence is a sequence of numbers where each number is the sum of the two preceding ones, starting from 0 and 1.
 * The Fibonacci sequence begins as follows: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,...
 * The first two terms are 0 and 1. All other terms are obtained by adding the preceding two terms.
 * The Fibonacci sequence can be defined recursively as follows:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2) for n > 1
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
#include "../../utils/generateHeader.h"
#include "../../utils/name.h"

using namespace std;

void generateFibonacciSequence(int);

int main()
{
    generateHeader("Fibonacci Sequence Program");

    int n;
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;

    cout << "Fibonacci Sequence: ";
    generateFibonacciSequence(n);

    generateName("0");
    return 0;
}

void generateFibonacciSequence(int n)
{
    int a = 0, b = 1, f;
    cout << a << " " << b << " ";
    for (int i = 0; i < n - 2; i++)
    {
        f = a + b;
        cout << f << " ";
        a = b;
        b = f;
    }
}
