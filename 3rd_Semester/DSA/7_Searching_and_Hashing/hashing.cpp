/* C++ implementation of hashing */
#include <iostream>
#include "../array_functions.h"
using namespace std;

int hash_function(int, int);
void insert(int[], int);
int search(int[], int);

// Driver's code
int main()
{
    int hash_table[10] = {0};

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    input_array_elements(arr, n);

    for (int i = 0; i < n; i++)
        insert(hash_table, arr[i]);

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = search(hash_table, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index: " << result;
    return 0;
}

// Hashing function to map values to key
int hash_function(int key)
{
    return key % 10;
}

// Function to insert key in hash table
void insert(int hash_table[], int key)
{
    int index = hash_function(key);
    hash_table[index] = key;
}

// Function to search key in hash table
int search(int hash_table[], int key)
{
    int index = hash_function(key);
    if (hash_table[index] == key)
        return index;
    return -1;
}
