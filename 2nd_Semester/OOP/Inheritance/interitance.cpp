#include <iostream>
using namespace std;

// Base class
class Parent
{
public:
    int pid;
};

// Sub class inheriting from Base Class(Parent)
class Child : public Parent
{
public:
    int cid;
};

// main function
int main()
{
    Child c; // an object of class child has all data members and member functions of class parent
    c.pid = 10;
    c.cid = 20;
    cout << "Parent id=" << c.pid << endl;
    cout << "Child id=" << c.cid << endl;
    return 0;
}
