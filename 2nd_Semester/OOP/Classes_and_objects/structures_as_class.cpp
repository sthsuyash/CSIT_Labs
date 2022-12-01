#include <iostream>
#include <conio.h>
using namespace std;

struct employee
{
private:
    int eid, salary;

public:
    void setData()
    {
        cout << "Enter employee details" << endl;
        cin >> eid >> salary;
    }
    void getData()
    {
        cout << "Employee details:" << endl
             << "Employee ID=" << eid << endl
             << "Employee salary=" << salary << endl;
    }
};

int main()
{
    employee e;
    e.setData();
    e.getData();
    getch();
    return 0;
}