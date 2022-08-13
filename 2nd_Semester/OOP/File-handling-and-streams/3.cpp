#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    int student_id;
    char name[20];

public:
    void setter()
    {
        cout << "Enter your name: ";
        cin.getline(name, 20);
        cout << "Enter student id: ";
        cin >> student_id;
    }
    void getter()
    {
        cout << "--------------------------------" << endl
             << "Student ID: " << student_id << endl
             << "Name: " << name << endl;
    }
};

int main()
{
    Student std;
    ofstream fout;
    ifstream fin;
    try
    {
        fout.open("studentsWrite.txt");
        std.setter();
        fout.write((char *)&std, sizeof(Student));
        cout << "Successfully written in file." << endl;
        fout.close();
    }
    catch (string error)
    {
        cout << "Error: " << error << endl;
    }
    return 0;
}