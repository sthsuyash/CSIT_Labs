/**** algorithm ( addition of two bit strings ) ****/
/*
    Note:
 *(a+i) = a[i]
  (a+i) = &a[i]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n; // declaring variable n to store the size of bit string the user wants.
    int d, c = 0;
    // int *a = NULL, *b = NULL, *s = NULL; // declaring pointers a, b and s to store two bit strings and the resultant string respectively
                                         // and initialize them to NULL.

    printf("\nEnter the size of bit strings you want: ");
    scanf("%d", &n);
    /** allocate list for each **/
    int a[n], b[n], s[n+1]; // declaring a, b and s to store two bit strings and the resultant string arrays respectively.

    /*
    /**** dyamically allocate the memory for a, b and s pointers ****/
    // a = malloc(n * sizeof(int));
    // b = malloc(n * sizeof(int));
    // s = malloc((n + 1) * sizeof(int));
    
    /**** scanning values for a and b ****/
    // 0th index of the array is considered to be the n-1th position and so on till last index of array is considered as 0 position
    printf("\nEnter the value of a (Enter 1 bit at a time): ");
    for (int i = n - 1; i >= 0; i--)
    {
         // scanf("%d", (a + i));
         scanf("%d", &a[i]);
    }

    printf("Enter the value of b (Enter 1 bit at a time): ");
    for (int i = n - 1; i >= 0; i--)
    {
         // scanf("%d", (b + i));
         scanf("%d", &b[i]);   
    }

    /**** printing the values for a and b ****/
    // printing in reverse as the data index is considered inverse
    printf("Value of a: ");
    for (int i = n - 1; i >= 0; i--)
    {
        // printf("%d", *(a + i));
        printf("%d", a[i]);
    }
    printf("\nValue of b: ");
    for (int i = n - 1; i >= 0; i--)
    {
        // printf("%d", *(b + i));
        printf("%d", b[i]);
    }
    printf("\n");

    /**** logic to add ****/
    for (int i = 0; i < n; i++)
    {
        d = floor((a[i]+b[i]+c)/2);   // d = floor((*(a + i) + *(b + i) + c) / 2);   // 
        s[i] = a[i]+b[i]+c-2*d;       // *(s + i) = *(a + i) + *(b + i) + c - 2 * d; // 
        c = d;
    }
    s[n] = c ; // the very first index item is put as the carry // *(s + n) = c; 

    /**** display the final summation result ****/
    // display in opposite as the index is in opposite
    printf("The binary expansion of the sum is: ");
    for (int i = n; i >= 0; i--)
    {
        // printf("%d", *(s + i));
        printf("%d", s[i]);
    }

    /**** free the memory space occupied by the pointers in heap ****/
//     free(a);
//     free(b);
//     free(s);
    
    return 0;
}
