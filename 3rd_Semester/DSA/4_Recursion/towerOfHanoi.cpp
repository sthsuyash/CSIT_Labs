#include <iostream>
using namespace std;

void towerOfHanoi(int n, string source, string temp, string destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, temp);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, temp, source, destination);
}

// Driver code
int main()
{
    int n; // Number of disks
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, "Source", "Temp", "Destination"); // A, B and C are names of rods
    return 0;
}
