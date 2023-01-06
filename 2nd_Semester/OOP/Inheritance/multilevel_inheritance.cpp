// C++ program to implement Multilevel Inheritance
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

// first sub_class derived from class vehicle
class FourWheeler : public Vehicle
{
public:
    FourWheeler()
    {
        cout << "This is 4 Wheeler." << endl;
    }
};

// sub class derived from the derived base class fourWheeler OUTPUT:
class Car : public FourWheeler
{
public:
    Car()
    {
        cout << "This is a Car." << endl;
    }
};

// main function
int main()
{
    // creating object of sub class will invoke the constructor of base classes
    Car obj;
    return 0;
}
