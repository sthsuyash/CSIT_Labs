#include <iostream>
#include <conio.h>
using namespace std;

class employee
{
public:
    employee()
    {
        cout << "Constructor invoked." << endl;
    }
    ~employee()
    {
        cout << "Destructor invoked." << endl;
    }
};

int main()
{
    employee e;
    getch();
    return 0;
}
