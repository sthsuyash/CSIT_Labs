/*
* In a single pump service station, vehicles arrive for fuelling with an average of 5 minutes between arrivals.
* If an hour is taken as unit of time, cars arrive according to Poisonís process with an average of average arrival rate L= 12 cars/hr.

* Write a C program to generate Poisson distribution for x = 0,1,2, Ö. 15.
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int fact_x;
    float L, pr; // L = average arrival rate, fact_x = factorial of x
    cout << "Enter arrival rate per hours: ";
    cin >> L;
    for (int x = 0; x < 16; x++)
    {
        fact_x = 1;
        for (int i = 1; i <= x; i++)
            fact_x = fact_x * i;
        pr = (pow(2.71, -L) * pow(L, x)) / fact_x;
        cout << "P (X = " << x << ") = " << pr << endl;
    }
    return 0;
}