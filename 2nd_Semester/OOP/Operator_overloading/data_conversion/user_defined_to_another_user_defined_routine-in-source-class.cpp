/*
This type of conversion can be carried out either by a constructor or an operator function.
It depends upon where we want the routine(code for conversion) to be located
– in the source class or
- in the destination class.
*/

// a. Routine in the Source class:
// If we want to convert objects of one class to object of another class, it
// is necessary that the operator function be placed in the source class.

#include <iostream>
using namespace std;

class distances
{
private:
    int feet, inch;

public:
    distances() {}
    distances(int f, int i)
    {
        feet = f;
        inch = i;
    }
    void getData()
    {
        cout << "Feets=" << feet << endl
             << "Inches=" << inch << endl;
    }
};

class dist
{
private:
    int meter, centimeter;

public:
    dist(int m, int c)
    {
        meter = m;
        centimeter = c;
    }
    operator distances()
    { // routine in source class
        int f, i;
        f = meter * 3.3;
        i = centimeter * 0.4;
        f = f + i / 12;
        i = i % 12;
        return distances(f, i); // nameless temporary objects
    }
};

int main()
{
    distances d1;
    dist d2(4, 50);
    d1 = distances(d2);
    d1.getData();
    return 0;
}
