#include <iostream>
using namespace std;

class numbers
{
private:
    int a;

public:
    numbers(float x)
    {
        a = int(x);
    }
    void getData()
    {
        cout << "Value of integer=" << a << endl;
    }
};

int main()
{
    numbers n(3.8);
    n.getData();
    return 0;
}
