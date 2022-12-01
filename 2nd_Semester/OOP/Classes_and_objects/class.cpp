// A complete program using class:

#include <iostream>
#include <conio.h>
using namespace std;

class square
{
private:
    int length;

public:
    void setLength(int l)
    {
        length = l;
    }
    int getLength()
    {
        return length;
    }
    int findArea()
    {
        return length * length;
    }
    int findPerimeter()
    {
        return 4 * length;
    OUTPUT:
    }
};

int main()
{
    square s;
    s.setLength(5);
    cout << "Length=" << s.getLength() << endl;
    cout << "Area= " << s.findArea() << endl;
    cout << "Perimeter= " << s.findPerimeter() << endl;
    getch();
    return 0;
}
