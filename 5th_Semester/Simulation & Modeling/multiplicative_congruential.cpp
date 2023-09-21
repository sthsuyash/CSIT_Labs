// Random number generation using multiplicative Congruential Method
// where c=0
#include <iostream>
using namespace std;
int seed_value;

int random_number(int, int);

int main(int argc, char const *argv[])
{
    int a, m, i, n;
    cout << "Enter the seed value: ";
    cin >> seed_value;

    cout << "Enter the number of values you want to generate: ";
    cin >> n;

    cout << "Enter the value of a and m: ";
    cin >> a >> m;

    cout << "Generated random numbers are: ";
    cout << seed_value << ", ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << random_number(a, m) << ", ";
    }

    return 0;
}

int random_number(int a, int m)
{
    return seed_value = (a * seed_value) % m;
}