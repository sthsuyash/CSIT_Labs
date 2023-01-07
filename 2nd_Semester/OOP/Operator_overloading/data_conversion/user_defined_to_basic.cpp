// Conversion from user defined type to basic type(float(d)):

/*
To convert user defined types (objects) to basic type it is necessary to overload cast operator. 
Overloaded cast operator doesn’t have return type. 
Its implicit return type is the type to which object need to be converted. 
To convert object to basic type, we use conversion function as below:
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
    operator float()
    { // typecast overloading
        float b = feet + inch / 12.0;
        return b;
    }
};

int main()
{
    distances d(3, 6);
    float a = float(d);
    cout << "Basic type=" << a << endl;
    return 0;
}
