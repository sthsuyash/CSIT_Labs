void input_array_elements(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << "arr[" << i << "]: ";
        std::cin >> arr[i];
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Swap function
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
