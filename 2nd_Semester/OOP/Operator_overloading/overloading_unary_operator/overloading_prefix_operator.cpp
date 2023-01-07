#include <iostream>
using namespace std;

class rectangle
{
private:
    int length, breadth;

public:
    rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    void operator++()
    {
        ++length;
        ++breadth;
    }
    void getData()
    {
        cout << "Length=" << length << endl;
        cout << "Breadth=" << breadth << endl;
    }
};

int main()
{
    rectangle r1(5, 3);
    ++r1;
    r1.getData();
    return 0;
}
