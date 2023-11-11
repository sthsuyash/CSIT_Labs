#include <iostream>
#include "../../../utils/generateHeader.h"
#include "../../../utils/name.h"

using namespace std;

void insertionSort(int[], int);

int main()
{
    generateHeader("Insertion Sort Program");

    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    generateName("2(c)");
    return 0;
}

void insertionSort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}