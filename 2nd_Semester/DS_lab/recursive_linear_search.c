/**** algorithm ( linear search using recursion ) ****/
#include <stdio.h>

int search(int *list, int i, int n, int searchItem)
{
    if (list[i] == searchItem)
        return i;
    else if (i == n)
        return 0;
    else
        return search(list, i + 1, n, searchItem);
}

int main(void)
{
    int n, searchItem;
    printf("Enter the number of elements you want in list: ");
    scanf("%d", &n);
    // declare the list array with the size inputed
    int list[n];
    printf("Enter the elements of list: ");
    // input data
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    printf("Enter the element to search in the list: ");
    scanf("%d", &searchItem);
    int location = search(list, 1, n, searchItem);
    if (location == 0)
        printf("The item you searched for is not available in the list.\n");
    else
        printf("The element '%d' is at location: %d", searchItem, location + 1);
    return 0;
}
