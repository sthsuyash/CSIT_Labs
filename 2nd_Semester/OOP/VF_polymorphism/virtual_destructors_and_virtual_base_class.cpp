// Virtual destructors and virtual base class
#include <iostream>
using namespace std;

class Base1
{
public:
    ~Base1() { cout << "Inside 1st base." << endl; }
};

class Derived1 : public Base1
{
public:
    ~Derived1() { cout << "Inside 1st derived." << endl; }
};

class Base2
{
public:
    virtual ~Base2() { cout << "Inside 2nd base." << endl; }
};

class Derived2 : public Base2
{
public:
    ~Derived2() { cout << "Inside 2nd derived." << endl; }
};

int main()
{
    Base1 *b1 = new Derived1;
    Base2 *b2 = new Derived2;
    delete b1;
    delete b2;
    
    return 0;
}
