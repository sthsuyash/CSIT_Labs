// Return by Value

/*
In case of return by value, copy of the value is returned to the user.
*/
// For example
#include <iostream>
#include <conio.h>
using namespace std;

float simpleInterest(float p, float t, float r)
{
    return (p * t * r) / 100;
}

int main()
{
    float p, t, r;
    cout << "Enter principal, time and rate: " << endl;
    cin >> p >> t >> r;
    cout << "Simple interest= " << simpleInterest(p, t, r);
    getch();
    return 0;
}
