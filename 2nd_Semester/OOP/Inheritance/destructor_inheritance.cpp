// Destructors under Inheritance
#include <iostream>
using namespace std;

class A
{
public:
    ~A()
    {
        cout << "Class A Destructor" << endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        cout << "Class B Destructor" << endl;
    }
};

class C : public B
{
public:
    ~C()
    {
        cout << "Class C Destructor" << endl;
    }
};

int main()
{
    {
        C x;
    } // destructor is called at this point
    return 0;
}
