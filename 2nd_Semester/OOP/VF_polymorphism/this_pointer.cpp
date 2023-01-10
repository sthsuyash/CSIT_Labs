// This pointer
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class person
{
private:
    string name;
    int age;

public:
    void setData(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void getData()
    {
        cout << "Name:" << name << endl
             << "Age:" << age << endl;
    }
    person isElder(person p)
    {
        if (age > p.age)
            return *this;
        else
            return p;
    }
};

int main()
{
    person p, p1, p2;
    p1.setData("Ram", 20);
    p2.setData("Sita", 21);
    p = p1.isElder(p2);
    cout << "Elder one is:" << endl;
    p.getData();
    getchar();
    return 0;
}
