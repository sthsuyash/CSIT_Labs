#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

typedef struct
{
    int size;
    int *bitmap;
} Bitmap;

void initBitmap(Bitmap *bitmap, int size)
{
    bitmap->size = size;
    bitmap->bitmap = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        bitmap->bitmap[i] = 0;
    }
}

int allocate(Bitmap *bitmap, int blocks)
{
    int start = -1;
    int count = 0;

    for (int i = 0; i < bitmap->size; i++)
    {
        if (bitmap->bitmap[i] == 0)
        {
            if (count == 0)
            {
                start = i;
            }
            count++;

            if (count == blocks)
            {
                for (int j = start; j < start + blocks; j++)
                {
                    bitmap->bitmap[j] = 1;
                }
                return start;
            }
        }
        else
        {
            count = 0;
        }
    }
    return -1;
}

void deallocate(Bitmap *bitmap, int start, int blocks)
{
    for (int i = start; i < start + blocks; i++)
    {
        bitmap->bitmap[i] = 0;
    }
}

void printBitmap(Bitmap *bitmap)
{
    for (int i = 0; i < bitmap->size; i++)
    {
        printf("%d ", bitmap->bitmap[i]);
    }
    printf("\n");
}

int main()
{
    Bitmap bitmap;
    initBitmap(&bitmap, SIZE);
    printf("\nInitial Bitmap: ");
    printBitmap(&bitmap);

    int start = allocate(&bitmap, 3);
    printf("\nAllocated blocks at index %d\n", start);
    printf("Updated Bitmap: ");
    printBitmap(&bitmap);

    deallocate(&bitmap, start, 3);
    printf("\nDeallocated blocks at index %d\n", start);
    printf("Updated Bitmap: ");
    printBitmap(&bitmap);

    free(bitmap.bitmap);

    return 0;
}
