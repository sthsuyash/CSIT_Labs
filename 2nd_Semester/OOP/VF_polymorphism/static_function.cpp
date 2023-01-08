#include <iostream>
#include <conio.h>
using namespace std;

class student
{
private:
    int roll;
    char name[20];
    static int count; // static data member
public:
    void setData()
    {
        cout << "Enter roll and name:" << endl;
        cin >> roll >> name;
        count++;
    }
    static void getData()
    { // static function
        cout << "count=" << count << endl;
    }
};

int student::count = 0;

int main()
{
    student s1, s2, s3;
    s1.setData();
    s2.setData();
    s3.setData();
    student::getData();
    return 0;
}
