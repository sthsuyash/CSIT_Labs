/*
* Write a C/C++ program to find the growth in national consumption for five years using Distributed Lag Model given below:
   I = 2 + 0.1Y0
   Y = 45.45 + 2.27(I+G)
   T = 0.2Y
   C = 20 + 0.7(Y-T)

* Assume the initial value of Y0 is 80 and take the governmental expenditure in the 5 years to be as follows:
   Year  G
   1     20
   2     25
   3     30
   4     35
   5     40
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float Y0, Y, I, T, C[5];
    float G[5] = {20, 25, 30, 35, 40};
    cout << "Enter initial value of logged variable Y0: ";
    cin >> Y0;
    cout << "\nThe growth in consumption is given following tables:\n";
    cout << "Year \t Consumption";
    for (int i = 0; i < 5; i++)
    {
        for (i = 0; i < 5; i++)
        {
            I = 2 + 0.1 * Y0;
            Y = 45.45 + 2.27 * (I + G[i]);
            T = 0.2 * Y;
            C[i] = 20 + 0.7 * (Y - T);
            cout << "\n " << i + 1 << " \t " << C[i];
            Y0 = Y;
        }
    }
    return 0;
}