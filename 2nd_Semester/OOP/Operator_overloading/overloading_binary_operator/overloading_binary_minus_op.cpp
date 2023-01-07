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
    distances operator-(distances d5)
    {
        distances d4;
        d4.feet = feet - d5.feet;
        d4.inch = inch - d5.inch;
        d4.feet = d4.feet - d4.inch / 12;
        d4.inch = d4.inch % 12;
        return d4;
    }
    void getData()
    {
        cout << "Feets=" << feet << endl
             << "Inches=" << inch << endl;
    }
};

int main()
{
    distances d1(2, 7), d2(8, 6), d3;
    d3 = d1 - d2;
    d3.getData();
    return 0;
}
