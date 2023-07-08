#include <stdio.h>
#define MAX_LENGTH 100

void getReferenceString(int rs[], int length)
{
    printf("Enter the reference string: ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &rs[i]);
    }
}

int isPageHit(int m[], int frameCount, int page)
{
    for (int i = 0; i < frameCount; i++)
    {
        if (m[i] == page)
        {
            return 1; // Page hit
        }
    }
    return 0; // Page fault
}

int getLRUPageIndex(int count[], int frameCount)
{
    int minIndex = 0;
    for (int i = 1; i < frameCount; i++)
    {
        if (count[i] < count[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void printMemoryLayout(int m[], int frameCount, int pageFault)
{
    for (int i = 0; i < frameCount; i++)
    {
        printf("%d\t", m[i]);
    }
    printf("PF No. : %d\n", pageFault);
}

int main()
{
    printf("Enter the length of the reference string: ");
    int length;
    scanf("%d", &length);

    if (length <= 0 || length > MAX_LENGTH)
    {
        printf("Invalid length of the reference string.\n");
        return 1;
    }

    int rs[MAX_LENGTH];
    getReferenceString(rs, length);

    printf("Enter the number of frames: ");
    int frameCount;
    scanf("%d", &frameCount);

    if (frameCount <= 0)
    {
        printf("Invalid number of frames.\n");
        return 1;
    }

    int m[frameCount], count[frameCount];
    for (int i = 0; i < frameCount; i++)
    {
        count[i] = 0;
        m[i] = -1;
    }

    int pageFault = 0, next = 0;

    for (int i = 0; i < length; i++)
    {
        if (!isPageHit(m, frameCount, rs[i]))
        {
            if (i < frameCount)
            {
                m[i] = rs[i];
                count[i] = next;
                next++;
            }
            else
            {
                int pageIndex = getLRUPageIndex(count, frameCount);
                m[pageIndex] = rs[i];
                count[pageIndex] = next;
                next++;
            }
            pageFault++;
        }
        else
        {
            for (int j = 0; j < frameCount; j++)
            {
                if (m[j] == rs[i])
                {
                    count[j] = next;
                    next++;
                    break;
                }
            }
        }
        printMemoryLayout(m, frameCount, pageFault);
    }

    printf("Number of page faults using LRU: %d\n", pageFault);

    return 0;
}
