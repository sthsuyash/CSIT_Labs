// Virtual member function accessed with pointers

#include <iostream>
using namespace std;

class A
{
public:
    virtual void display()
    {
        cout << "This is class A." << endl;
    }
};

class B : public A
{
public:
    void display()
    {
        cout << "This is class B." << endl;
    }
};

class C : public A
{
public:
    void display()
    {
        cout << "This is class C." << endl;
    }
};

int main()
{
    A *p, a;
    B b;
    C c;
    p = &b;
    p->display(); // points to Class B’s object’s function since Class A has display() virtual function.
    p = &c;
    p->display();
    p = &a;
    p->display();
    return 0;
}
