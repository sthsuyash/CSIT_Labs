#include <iostream>
#include "../../utils/generateHeader.h"
#include "../../utils/name.h"

using namespace std;

int gcd(int, int);

int main()
{
    generateHeader("GCD Calculation Program");

    int num1, num2, gcdResult;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    gcdResult = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is " << gcdResult;

    generateName("1(a)");
    return 0;
}

int gcd(int a, int b)
{
    int temp;
    (b == 0) ? temp = a : temp = gcd(b, a % b);
    return temp;
}