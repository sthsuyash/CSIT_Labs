#include <iostream>
#include <conio.h>
using namespace std;

class Parent
{
private:
    int x;

protected:
    int y;

public:
    int z;
};

class Child : public Parent
{
public:
    void setData()
    {
        cout << "Enter values of x, y and z:" << endl;
        // cin>>x; //invalid, generates error because x is private OUTPUT:
        cin >> y >> z;
    }
};

int main()
{
    Child c;
    c.setData();
    // cout<<"x="<<c.x<endl; //invalid, generates error because x is private
    // cout<<"y="<<c.y<endl; //invalid, generates error because y is protected
    cout << "z=" << c.z << endl; // valid
    getch();
    return 0;
}
