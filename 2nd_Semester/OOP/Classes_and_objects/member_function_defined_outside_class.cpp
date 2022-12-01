#include <iostream>
using namespace std;

class square
{
private:
    int length;

public:
    void setData(int l)
    { // method definition inside the class
        length = l;
    }
    int getArea(); // abstraction
    int getPerimeter();
};

int square ::getArea()
{ // method definition outside of the class
    return length * length;
}

int square ::getPerimeter()
{
    return 4 * length;
}

int main()
{
    square s;
    s.setData(5);
    cout << "Area=" << s.getArea() << endl;
    cout << "Perimeter=" << s.getPerimeter() << endl;
    return 0;
}
