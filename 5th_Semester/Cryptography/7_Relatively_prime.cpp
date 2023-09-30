/*
 *  Program to check if two numbers are relatively prime or not.
 */

#include <iostream>
#include "./returnName.h"
using namespace std;

int main()
{
    generateHeader("Program to check if two numbers are relatively prime or not.");
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Finding HCF
    int hcf = 1;
    for (int i = 2; i <= num1 && i <= num2; ++i)
    {
        num1 % i == 0 && num2 % i == 0 ? hcf = i : hcf = hcf;
    }

    // Making Decision
    if (hcf == 1)
        cout << num1 << " and " << num2 << " are relatively prime numbers." << endl;
    else
        cout << num1 << " and " << num2 << " are NOT relatively prime numbers." << endl;

    // Wait for user input before exiting
    cin.get();
    return 0;
}
