#include <iostream>
#include <conio.h>
using namespace std;

struct employee
{
    int eid, salary; // public by default
};

int main()
{
    employee e;
    e.eid = 101;
    e.salary = 25000;
    cout << "Employee ID=" << e.eid << endl
         << "Employee Salary=" << e.salary << endl;
    return 0;
}
