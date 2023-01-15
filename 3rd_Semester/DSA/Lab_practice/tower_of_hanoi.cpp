/* Cpp program for tower of hanoi */

#include <iostream>
using namespace std;

void towerOfHanoi(int n, string from_rod, string to_rod, string temp_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from_rod << " to " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, temp_rod, to_rod);
    cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
    towerOfHanoi(n - 1, temp_rod, to_rod, from_rod);
}

int main()
{
    int n = 2;
    towerOfHanoi(n, "Source", "Destination", "Temp");
    return 0;
}
