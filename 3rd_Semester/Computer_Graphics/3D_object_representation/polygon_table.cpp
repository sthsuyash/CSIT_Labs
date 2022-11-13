#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int ver, face, n;

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    printf("Enter the number of faces: ");
    scanf("%d", &face);
    n = face;

    for (int j = 0; face != j; face--)
    {
        printf("Enter the total number of vertex in face %d: ", n - face + 1);
        scanf("%d", &ver);
        int poly[ver], i;

        printf("Enter vertex from face %d (x,y): \n", n - face + 1);
        for (i = 0; i < (ver * 2); i++)
        {
            printf("\tx%d , y%d : ", i / 2, i / 2);
            scanf("%d %d", &poly[i], &poly[i + 1]);
            i++;
        }
        poly[ver * 2] = poly[0];
        poly[(ver * 2) + 1] = poly[1];
        //		face=face-1;
        setcolor(getmaxcolor());
        setfillstyle(SOLID_FILL, n - face + 1);
        fillpoly(ver + 1, poly);
    }

    getch();
    closegraph();

    return 0;
}
