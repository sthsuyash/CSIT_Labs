#include <iostream>
using namespace std;

// base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle." << endl;
    }
};

// first sub class
class Car : public Vehicle
{
};

// second sub class
class Bus : public Vehicle
{
};

int main()
{
    // creating object of sub class will OUTPUT:
    // invoke the constructor of base class
    Car obj1;
    Bus obj2;
    return 0;
}
