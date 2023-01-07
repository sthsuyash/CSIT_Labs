// Routine in the Destination Class
/*
In this case, it is necessary that the constructor be placed in the destination class.
This constructor is a single argument constructor and serves as an instruction
for converting the argument’s type to the class type of which it is a member.
*/

#include <iostream>
using namespace std;

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

    int getMeter()
    {
        return meter;
    }

    int getCentimeter()
    {
        return centimeter;
    }
};

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

    distances(dist d)
    { // routine in destination class
        int m, c;
        m = d.getMeter();
        c = d.getCentimeter();
        feet = m * 3.3;
        inch = c * 0.4;
        feet = feet + inch / 12;
        inch = inch % 12;
    }

    void getData()
    {
        cout << "Feets: " << feet << endl
             << "Inches: " << inch << endl;
    }
};

int main()
{
    distances d1;
    dist d2(4, 50);
    d1 = d2;
    d1.getData();
    return 0;
}
