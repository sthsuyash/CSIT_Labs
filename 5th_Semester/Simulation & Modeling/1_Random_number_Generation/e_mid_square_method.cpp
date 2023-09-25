// Random number generation using Mid Square Method
// 2 digit seed value

#include <iostream>
using namespace std;

int seed_value;

int midSquareMethod();

int main(int argc, char const *argv[])
{
    cout << "Enter the seed value: ";
    cin >> seed_value;

    cout << "Generated random numbers are: ";
    cout << seed_value << " ";
    for (int i = 0; i < 10; i++)
    {
        cout << midSquareMethod() << " ";
    }

    return 0;
}

int midSquareMethod()
{
    int squared = seed_value * seed_value;
    return seed_value = (squared / 10) % 100; // extract middle 2 digits
}