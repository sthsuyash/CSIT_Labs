/*
- Inheritance is often called a "kind of" or "is a" relationship.
- In inheritance, if a class B is derived from a class A, we can say “B is a kind of A”.This is because B has all the characteristics of A, and in addition some of its own.
- There is another type of relationship, called a “has a” relationship or containership.
- In object oriented programming, has a relationship occurs when one object is contained in another.PREPARED BY : ER.SHARAT MAHARJAN LAB 11 :
*/
#include <iostream>
using namespace std;

class Employee
{
    int eid, salary;

public:
    void setData()
    {
        cout << "Enter employee id and salary:" << endl;
        cin >> eid >> salary;
    }
    void getData()
    {
        cout << "Employee ID=" << eid << endl
             << "Employee salary=" << salary << endl;
    }
};

class Company
{ // company has an employee relationship OUTPUT:
    int cid;
    string cname;
    Employee e;

public:
    void setData()
    {
        cout << "Enter company id and name:" << endl;
        cin >> cid >> cname;
        e.setData();
    }
    void getData()
    {
        cout << "Company ID=" << cid << endl
             << "Company name=" << cname << endl;
        e.getData();
    }
};

int main()
{
    Company c;
    c.setData();
    c.getData();
    return 0;
}
