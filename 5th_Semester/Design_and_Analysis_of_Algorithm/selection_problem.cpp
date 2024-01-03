/*
 * Program: Selection Problem with Divide and Conquer
 *
 * Selection Problem is the problem of finding the kth smallest element in an array.
 * This program uses the Divide and Conquer approach to solve the problem.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int[], int, int);
int randomizedQuickSelect(int[], int, int, int);
int findKthSmallest(int[], int, int);

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthSmallest(arr, n, k);

    if (result != -1)
        cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}

// Helper function to partition the array
int partition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];

    swap(arr[pivotIndex], arr[high]);

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivotValue)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Helper function to perform randomized quickselect
int randomizedQuickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex == k)
            return arr[partitionIndex];
        else if (partitionIndex < k)
            return randomizedQuickSelect(arr, partitionIndex + 1, high, k);
        else
            return randomizedQuickSelect(arr, low, partitionIndex - 1, k);
    }

    // This should not happen if the input is valid
    return -1;
}

// Function to find the kth smallest element in an array
int findKthSmallest(int arr[], int size, int k)
{
    // Check if k is within the valid range
    if (k >= 1 && k <= size)
        return randomizedQuickSelect(arr, 0, size - 1, k - 1);
    else
    {
        cout << "Invalid value of k\n";
        return -1;
    }
}