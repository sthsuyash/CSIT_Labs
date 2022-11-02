#include <iostream>
using namespace std;

// function to shift data front everytime the array encounters specified data
void shift(int *arr, int n, int size)
{
    for (int i = n; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 1, 4, 6, 2, 1, 3, 4};
    int arr[] = {1, 2, 2, 1, 2};
    int n, repeat = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Given data array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter data to delete: ";
    cin >> n;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            shift(arr, i, size);
            repeat++;
        }
    }

    if (!repeat)
    {
        cout << "No given data in array." << endl;
    }
    else
    {
        cout << "Successfully removed the data." << endl;
        for (int i = 0; i < size - repeat; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}