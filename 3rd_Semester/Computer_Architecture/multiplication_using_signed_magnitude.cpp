// Multiplication using signed Magnitude

#include <iostream>
#include <math.h>

int q = 0, b = 0, c = 0, e = 0, q1 = 0, b1 = 0;
int qnum[4] = {0}, bnum[4] = {0};
int acc[4] = {0}, res[4] = {0};
int sc = 0, bs = 0, qs = 0, asize = 0;

void binary()
{
    b1 = fabs(b);
    q1 = fabs(q);
    int r1, r2, i, temp;
    for (i = 0; i < 4; i++)
    {
        r1 = b1 % 2;
        b1 = b1 / 2;
        r2 = q1 % 2;
        q1 = q1 / 2;
        bnum[i] = r1;
        qnum[i] = r2;
    }
    sc = sizeof(qnum) / sizeof(int);

    asize = sc;
}

void add(int num[])
{
    int i;
    c = 0;
    for (i = 0; i < 4; i++)
    {
        res[i] = acc[i] + num[i] + c;
        if (res[i] >= 2)
        {
            c = 1;
        }
        else
        {
            c = 0;
        }
        e = c;
        res[i] = res[i] % 2;
    }

    for (i = 3; i >= 0; i--)
    {
        acc[i] = res[i];
        printf("%d", acc[i]);
    }
    printf(" : ");
    for (i = 3; i >= 0; i--)
    {
        printf("%d", qnum[i]);
    }
}
void rshift()
{ // for shift right
    int temp2 = acc[0], i;
    for (i = 1; i < 4; i++)
    { // shift the MSB of product
        acc[i - 1] = acc[i];
    }
    acc[3] = e;
    e = 0;
    for (i = 1; i < 4; i++)
    { // shift the LSB of product
        qnum[i - 1] = qnum[i];
    }
    qnum[3] = temp2;

    printf("\n R-SHIFT: "); // display together
    for (i = 3; i >= 0; i--)
    {
        printf("%d", acc[i]);
    }
    printf(":");
    for (i = 3; i >= 0; i--)
    {
        printf("%d", qnum[i]);
    }
}
int main()
{
    int i;
    int p = 0, n = 1;
    printf("\t\tSIGNED MAGNITUDE MULTIPLICATION ALGORITHM");
    printf("\nEnter two numbers to multiply: ");
    printf("\nBoth must be less than 16");
    // simulating for two numbers each below 16
    do
    {
        printf("\nEnter b: ");
        scanf("%d", &b);
        printf("Enter Q: ");
        scanf("%d", &q);
    } while (b >= 16 || q >= 16);

    printf("\n Expected product = %d", b * q);
    binary();

    printf("\nS.C. = %d", sc);

    printf("\n\n Signed Binary Equivalents are: ");
    printf("\n b = ");
    for (i = 3; i >= 0; i--)
    {
        printf("%d", bnum[i]);
    }

    printf("\n q = ");
    for (i = 3; i >= 0; i--)
    {
        printf("%d", qnum[i]);
    }
    printf("\n\n");

    while (sc != 0)
    {
        printf("\nS.C. = %d", sc);
        if (qnum[0] == 0)
        {
            printf("\n-->");
            rshift();
        }
        else
        {
            printf("\n-->");
            printf("\n ADD B: ");
            add(bnum);
            rshift();
        }
        sc--;
    }

    printf("\nproduct is = ");

    if ((b < 0 && q > 0) || (b > 0 && q < 0))
        printf("%d", n);
    else
        printf("%d", p);

    for (i = 3; i >= 0; i--)
    {
        printf("%d", acc[i]);
    }
    for (i = 3; i >= 0; i--)
    {
        printf("%d", qnum[i]);
    }

    return 0;
}
