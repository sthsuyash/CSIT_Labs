#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void recursivePart(int pages[])
{
    int st, len, k, c, j;
    printf("Enter the index of the starting block and its length: ");
    scanf("%d%d", &st, &len);
    k = len;
    if (pages[st] == 0)
    {
        for (j = st; j < (st + k); j++)
        {
            if (pages[j] == 0)
            {
                pages[j] = 1;
                printf("%d------>%d\n", j, pages[j]);
            }
            else
            {
                printf("The block %d is already allocated \n", j);
                k++;
            }
        }
    }
    else
        printf("The block %d is already allocated \n", st);
    printf("Do you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &c);
    if (c == 1)
        recursivePart(pages);
    else
        exit(0);
    return;
}

int main()
{
    int pages[50], p, a;

    for (int i = 0; i < 50; i++)
        pages[i] = 0;
    printf("Enter the number of blocks already allocated: ");
    scanf("%d", &p);
    if (p != 0)
    {
        printf("Enter the blocks already allocated: ");
        for (int i = 0; i < p; i++)
        {
            scanf("%d", &a);
            pages[a] = 1;
        }
    }

    recursivePart(pages);
    getch();
    return 0;
}