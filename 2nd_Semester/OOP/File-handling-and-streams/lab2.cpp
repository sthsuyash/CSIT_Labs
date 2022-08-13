#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    string name;
    int age;

    fout.open("names.txt");
    cout << "Enter name: ";
    cin >> name;
    fout << name << endl;
    cout << "Enter age: ";
    cin >> age;
    fout << age << endl;
    fout.close();

    fin.open("names.txt");
    getline(fin, name);
    fin >> age;
    cout << "Name: " << name << endl
         << "Age: " << age << endl;
    fin.close();

    return 0;
}