/*
We can define more than one constructor in a class
- either with different number of arguments or
- with different type of argument
which is called constructor overloading.
It is a variation of function overloading and is used to achieve polymorphism.
*/
// For example:
#include <iostream>
using namespace std;

class item
{
private:
    int code, price;

public:
    item()
    { // default constructor
        code = price = 0;
    }
    item(int c, int p)
    { // parameterized constructor
        code = c;
        price = p;
    }
    item(item &x)
    { // copy constructor
        code = x.code;
        price = x.price;
    }
    void display()
    {
        cout << "Code: " << code << endl
             << "Price: " << price << endl
             << endl;
    }
};

int main()
{
    item a;
    item b(100, 200);
    item d = b;
    item c(b); // copying b into c
    a.display();
    b.display();
    c.display();
    d.display();
    return 0;
}
