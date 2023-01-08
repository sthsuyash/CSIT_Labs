// Pure virtual functions:
/*
- A pure virtual function is one with the expression =0 added to the declaration.
- In such cases, the compiler requires each derived class
    to either define the function or redeclare it as a pure virtual function.
- Thus, a pure virtual function simply acts as a placeholder that is meant to be redefined by derived classes.
We can define pure virtual function as below:
class base{//abstract class- object can’t be created of abstract class.
    private:
        int x,y;
    public:
    virtual void setData()=0; //doesn’t mean assignment of zero to the function. It is only the
    virtual void getData()=0;}; //specification for telling the compiler that the function is
    class derived: public base{ // pure virtual function.
    Data members
    Member functions};
*/

/*
Abstract class: (base class)
- An abstract class is a class containing at least one pure virtual function.
They can’t be instantiated into an object directly. However, we can create pointers and references to an abstract class.
Abstract classes are designed to be specifically used as base classes.
Only a subclass of an abstract class can be instantiated directly if all inherited pure virtual methods have been implemented by that class.

class A{
    public:
    fun1()=0;
    fun2()=0;
};

- With above abstract class, we can’t create its object of but we can create pointer to A class as below:
A a; //invalid
A *p; //valid
*/

/*
Concrete class: (derived class)
- A derived class that implements all the missing functionality is called a concrete class.
*/

// Pure virtual function, abstract base class and concrete class
#include <iostream>
using namespace std;

class Shape
{ // abstract class
protected:
    int width, height;

public:
    void setData(int a, int b)
    {
        width = a;
        height = b;
    }
    virtual int area() = 0; // pure virtual function
};

class Rectangle : public Shape
{ // concrete class
public:
    int area()
    {
        return width * height;
    }
};

class Triangle : public Shape
{ // concrete class
public:
    int area()
    {
        return (width * height) / 2;
    }
};

int main()
{
    Shape *s;
    Rectangle r;
    Triangle t;
    s = &r;
    s->setData(2, 4);
    cout << "Area of rectangle=" << s->area() << endl;
    s = &t;
    s->setData(2, 4);
    cout << "Area of triangle=" << s->area() << endl;

    return 0;
}
