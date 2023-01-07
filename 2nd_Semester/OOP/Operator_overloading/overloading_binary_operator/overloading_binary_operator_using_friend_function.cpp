#include <iostream>
using namespace std;

class distances
{
private:
    int feet, inch;

public:
    distances()
    {
    }
    distances(int f, int i)
    {
        feet = f;
        inch = i;
    }
    friend distances operator+(distances, distances);
    void getData()
    {
        cout << "Feets=" << feet << endl
             << "Inches=" << inch << endl;
    }
};

distances operator+(distances x, distances y)
{
    distances d;
    d.feet = x.feet + y.feet;
    d.inch = x.inch + y.inch;
    d.feet = d.feet + d.inch / 12;
    d.inch = d.inch % 12;
    return d;
}

int main()
{
    distances d1(2, 7), d2(8, 6), d3;
    d3 = d1 + d2;
    d3.getData();
    return 0;
}
