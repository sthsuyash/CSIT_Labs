// Ambiguity in Multiple Inheritance
/*
Suppose two base classes have an exactly similar member.
Also, suppose a class derived from both of these base classes has not this member.
Then, if we try to access this member from the objects of the derived class, it will be ambiguous.
We can remove this ambiguity by using the syntax :
obj.classname::variablename
    or
methodname
*/

// Avoiding ambiguity in multiple inheritance using scope resolution operator.
#include <iostream>
#include <conio.h>
using namespace std;

class A
{
public:
    int x;
};

class B
{
public:
    int x;
};

class C : public A, public B
{
};

int main()
{
    C c;
    // c.x=10; - ambiguous, will not compile OUTPUT:
    c.A::x = 10;
    c.B::x = 20;
    cout << "Value of x in class A=" << c.A::x << endl;
    cout << "Value of x in class B=" << c.B::x << endl;
    getch();
    return 0;
}
