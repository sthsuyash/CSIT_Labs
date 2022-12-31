// Ambiguity in Multipath Inheritance:
/*
- Another kind of ambiguity arises if we derive a class from two classes that are each derived from the same class, which is called multipath hybrid inheritance.
- In this case, public or protected member of grandparent is derived in the child class twice which creates confusion to the compiler.
- We can remove this kind of ambiguity by using the concept of virtual base classes.
- Consider a figure in right side, this creates a diamond-shaped inheritance tree
    and all the public and protected members from class A inherited into class D twice
    once through the path A->B->D and again through the path A->B->C.
    This causes ambiguity and should be avoided.
    For this, we make direct base classes (B and C) virtual base classes.
    When this happens, compiler creates direct path from A to D.
*/

// Avoiding ambiguity in multipath hybrid inheritance using virtual base class:

#include <iostream>
#include <conio.h>
using namespace std;

class A
{
public:
    int a;
};

class B : virtual public A
{ // virtual keyword is used so that the grandchild class will get only one copy of parent class data members and functions.
public:
    int b;
};

class C : virtual public A
{
public:
    int c;
};

class D : public B, public C
{
public:
    int d;
};

int main()
{
    D obj;
    obj.a = 100;
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
    cout << "Value of a=" << obj.a << endl;
    cout << "Value of b=" << obj.b << endl;
    cout << "Value of c=" << obj.c << endl;
    cout << "Value of d=" << obj.d << endl;
    getch();
    return 0;
}
