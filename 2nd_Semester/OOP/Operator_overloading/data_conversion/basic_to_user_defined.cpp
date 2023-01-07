// Conversion from basic type to user defined type(distances(3.5)):

/*
To convert basic types to user defined type (object) it is necessary to use the constructor.
The constructor in this case takes single argument whose type is to be converted.
*/
#include <iostream>
using namespace std;

class distances
{
private:
    int feet, inch;

public:
    distances(int f, int i)
    {
        feet = f;
        inch = i;
    }
    distances(float x)
    {
        feet = int(x);
        inch = 12 * (x - feet);
    }
    void getData()
    {
        cout << "Feets=" << feet << endl
             << "Inches=" << inch << endl;
    }
};

int main()
{
    distances d(2.5);
    d.getData();
    return 0;
}
