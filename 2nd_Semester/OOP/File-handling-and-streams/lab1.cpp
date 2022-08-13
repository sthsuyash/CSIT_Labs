#include <iostream>
#include <string>
#include <fstream>

int main()
{
    char chars;
    std::ifstream fin;
    fin.open("lab1.txt");
    while (!fin.eof())
    {
        fin.get(chars);
        std::cout.put(chars);
    }
    return 0;
}