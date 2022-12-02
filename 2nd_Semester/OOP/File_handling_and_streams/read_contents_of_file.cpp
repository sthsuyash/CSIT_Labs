#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    char chars;
    ifstream fin;
    fin.open("lab1.txt");
    while (!fin.eof())
    {
        fin.get(chars);
        cout.put(chars);
    }
    return 0;
}
