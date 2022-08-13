/**** algorithm ( Chinese Remainder Theorem ) ****/
// x = E(i=0 to n)(summation) a[i].M[i].s[i]
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**** function declaration ****/
int inverse(int, int);

int main(void)
{
    int n; // variable to store the number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    /** allocate array sizes for variables **/
    int m[n], a[n], s[n], Mk[n];
    // int *m = NULL, *a = NULL, *s = NULL, *Mk = NULL; // declare and initialize the pointers to NULL

    // dynamically allocating the size of pointers
    // m = malloc(n * sizeof(int));
    // a = malloc(n * sizeof(int));
    // s = malloc(n * sizeof(int));
    // Mk = malloc(n * sizeof(int));
    
    
    // loop to input the value of a and m form the expected number of equations
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of a%d:", i + 1);
        // scanf("%d", (a + i));
        scanf("%d", &a[i]);
        printf("Enter the value of m%d:", i + 1);
        // scanf("%d", (m + i));
        scanf("%d", &m[i]);
    }

    // displaying the equations
    printf("\nThe equations are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x === %d ( mod %d )\n", *(a + i), *(m + i));
    }

    int M = 1; // initialize M to 1 as we must multiply and so the initial value must be 1
    // loop to calculate the product of all m's in the equation
    for (int i = 0; i < n; i++)
    {
        // M = M * *(m + i);
        M = M * m[i];
    }
    // loop to calculate the value of individual M's required
    for (int i = 0; i < n; i++)
    {
        // *(Mk + i) = M / *(m + i);
        Mk[i] = M / m[i];
    }
    // loop to calculate the inverse s[i] for corresponding Mk[i] and m[i]
    for (int i = 0; i < n; i++)
    {
        s[i] = inverse(Mk[i], m[i]);  // *(s + i) = inverse(*(Mk + i), *(m + i)); 
    }
    int x = 0; // calculate the answer
    // loop to calculate the value of x by the formula of chinese remainder theorem
    for (int i = 0; i < n; i++)
    {
        x = x + (a[i] * Mk[i] * s[i]);
    }

    // free the dynamic variables
    // free(m);
    // free(a);
    // free(s);
    // free(Mk);

    // display the data
    printf("x: %d", x);
    x = x % M;
    printf("\nThe solution of the given system is: %d+%dk where k is an integer.", x, M);
    return 0;
}

// function to return the inverse 's' as we need it to calculate the value of x
int inverse(int a, int b)
{
    int s1 = 0, s2 = 1, t1 = 1, t2 = 0;
    int q, r, s, t;
    while (b != 0)
    {
        q = a / b;
        r = a % b;
        s = s2 - q * s1;
        t = t2 - q * t1;
        a = b;
        b = r;
        s2 = s1;
        s1 = s;
        t2 = t1;
        t1 = t;
    }
    return s2;
}
