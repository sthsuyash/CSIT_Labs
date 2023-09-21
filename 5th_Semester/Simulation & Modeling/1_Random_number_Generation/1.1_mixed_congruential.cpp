// Random number generation using Linear Mixed Congruential Method
// where c!=0
#include <iostream>
using namespace std;
int seed_value;

int random_number(int, int, int);

int main(int argc, char const *argv[])
{
    int a, c, m, i, n;
    cout << "Enter the seed value: ";
    cin >> seed_value;

    cout << "Enter the number of values you want to generate: ";
    cin >> n;

    cout << "Enter the value of a, c and m: ";
    cin >> a >> c >> m;

    cout << "Generated random numbers are: ";
    cout << seed_value << ", ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << random_number(a, c, m) << ", ";
    }

    return 0;
}

int random_number(int a, int c, int m)
{
    return seed_value = (a * seed_value + c) % m;
}