/* C++ implementation of binary search */

#include <bits/stdc++.h>
#include "../array_functions.h"
using namespace std;

int binary_search(int[], int, int, int);

// Driver's code
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    input_array_elements(arr, n);

    sort(arr, arr + n); // sort the array

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = binary_search(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index: " << result;
    return 0;
}

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // if the element is present at the middle itself
        if (arr[mid] == x)
            return mid; // return index of element

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binary_search(arr, mid + 1, r, x);
    }
    return -1; // element not present
}
