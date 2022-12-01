// Copy Constructor:

/*
A copy constructor is a member function that initializes an object using another object of the same class.
It has a single parameter of reference type that refers to the class itself.
*/
// For example:
#include <iostream>
#include <conio.h>
using namespace std;
class item
{
private:
    int code, price;

public:
    item(int c, int p)
    { // parameterized constructor
        code = c;
        price = p;
    }
    item(item &x)
    {                  // copy constructor-need to pass object of item as argument
        code = x.code; // b.code=a.code
        price = x.price;
    }
    void display()
    {
        cout << "Code: " << code << endl
             << "Price: " << price;
    }
};
int main()
{
    item a(100, 200);
    item b(a); // copying a into b
    b.display();
    getch();
    return 0;
}
