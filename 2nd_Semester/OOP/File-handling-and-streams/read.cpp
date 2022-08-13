#include <iostream>
#include <fstream>

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
        cout << "Student ID: " << student_id << endl
             << "Name: " << name << endl
             << "--------------------------------" << endl;
    }
};

using namespace std;

int main()
{
    Student std;
    ifstream fin;
    cout << "Reading from file." << endl;
    fin.open("studentsWrite.txt");
    fin.read((char *)&std, sizeof(Student));
    std.getter();
    fin.close();
    return 0;
}