#include<iostream>
#include "../../../utils/generateHeader.h"
#include "../../../utils/name.h"

using namespace std;

void bubbleSort(int[], int);

int main()
{
    generateHeader("Bubble Sort Program");

    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    generateName("2(a)");
    return 0;
}

void bubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}