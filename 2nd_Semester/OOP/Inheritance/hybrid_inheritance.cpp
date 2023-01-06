// C++ program for Hybrid Inheritance

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

// base class
class Fare
{
public:
    Fare()
    {
        cout << "Fare of vehicle" << endl;
    }
};

// first sub class
class Car : public Vehicle
{ // hierarchical due to both Car and Bus inherits Vehicle class
};

// second sub class
class Bus : public Vehicle, public Fare
{ // multiple since Bus inherits more than one class
public:
    Bus()
    {
        cout << "This is a Bus." << endl;
    }
};

// main function
int main()
{
    // creating object of sub class will
    // invoke the constructor of base class
    Bus obj2;
    return 0;
}
