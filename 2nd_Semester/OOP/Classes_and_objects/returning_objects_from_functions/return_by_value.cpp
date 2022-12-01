// Return by value

/*
In this method, a copy of the object is returned to the function call.
One can return any type of object by value. It is slow when working with large objects.
*/
// For example
#include <iostream>
#include <conio.h>
using namespace std;

class point
{
private:
    float x, y;

public:
    void setPoint(float a, float b)
    {
        x = a;
        y = b;
    }
    point midPoint(point p1, point p2)
    {
        point p; // declare object of point to return later
        x = (p1.x + p2.x) / 2;
        y = (p1.y + p2.y) / 2;
        p.x = x;
        p.y = y;
        return p;
    }
    void showMidpoint()
    {
        cout << "Co-ordinate of midpoint:" << endl;
        cout << "x= " << x << endl
             << "y= " << y << endl;
    }
};

int main()
{
    point c, d, e;
    c.setPoint(1, 3);
    d.setPoint(2, 4);
    e.midPoint(c, d);
    e.showMidpoint();
    getch();
    return 0;
}
