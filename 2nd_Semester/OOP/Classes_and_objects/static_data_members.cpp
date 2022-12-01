/*
- If a data member in a class is defined as static, 
    then only one copy of that member is created for the entire class and is 
    shared by all the objects of that class, no matter how many objects are created.
- Hence, these data members are normally used to 
    maintain values common to the entire class and are also called class variables.
- Memory for static data members is allocated at the time of declaration 
    and is initialized to zero when the first object is created.
- We can’t put it in the class definition but 
    it can be initialized outside the class using the scope resolution operator (::) to identify which class it belongs to.
*/

/*
    Syntax:
    class A{
    static int i;
    public:
    //……};
    int A::i=1;
*/

#include <iostream>
#include <conio.h>
using namespace std;

class employee
{
private:
    char name[20];

public:
    static int objectCount;
    employee()
    {
        objectCount++;
    }
    void setData()
    {
        cout << "Enter employee name: " << endl;
        cin >> name;
    }
    void getData()
    {
        cout << "Employee name: " << name << endl;
    }
};

int employee::objectCount = 0;

int main()
{
    employee e1, e2;
    e1.setData();
    e1.getData();
    e2.setData();
    e2.getData();
    cout << "Total object created= " << employee::objectCount << endl;
    getch();
    return 0;
}
