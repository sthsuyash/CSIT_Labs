#include <iostream>
#include <fstream>
using namespace std;

class student
{
private:
    int roll;
    string name, address;

public:
    void setter()
    {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Roll: ";
        cin >> roll;
        cout << "Address: ";
        cin >> address;
    }

    void getter()
    {
        cout << "Name: " << name << endl
             << "Roll: " << roll << endl
             << "Address: " << address << endl;
    }
};

int main()
{
    student std;
    // ofstream fout;
    // fout.open("Lab3.txt");
    // std.setter();
    // fout.write((char *)&std, sizeof(student));
    // fout.close();

    ifstream fin;
    fin.open("Lab3.txt");
    fin.read((char *)&std, sizeof(student));
    std.getter();

    system("pause");
    return 0;
}