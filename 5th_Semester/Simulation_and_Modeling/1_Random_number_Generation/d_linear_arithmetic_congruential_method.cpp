// Random number generation using Arithmetic Congruential Method

#include <iostream>
using namespace std;

int seed_value1 = 9;
int seed_value2 = 13;

int random_num(int);

int main(int argc, char const *argv[])
{
    int m, i, n;

    cout << "Enter the number of values you want to generate: ";
    cin >> n;
    cout << "Enter the value of m: ";
    cin >> m;

    cout << "Generated random numbers are: ";
    cout << seed_value1 << " ";
    cout << seed_value2 << " ";

    for (i = 0; i < n - 1; i++)
    {
        cout << random_num(n) << " ";
    }
    return 0;
}

int random_num(int m)
{
    // Linear mix congruential formula
    int next_value = (seed_value1 + seed_value2) % m;
    seed_value1 = seed_value2;
    seed_value2 = next_value;

    return next_value;
}