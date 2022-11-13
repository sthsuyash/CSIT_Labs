/*  C Program to implement 3-D rotation in Graphics  */

#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>

#define ORG -50

double face1[5][2] = {
    {250, 125},
    {350, 125},
    {350, 225},
    {250, 225},
    {250, 125}};

double face2[5][2] = {
    {250 + ORG, 125 - ORG},
    {350 + ORG, 125 - ORG},
    {350 + ORG, 225 - ORG},
    {250 + ORG, 225 - ORG},
    {250 + ORG, 125 - ORG}};

double angle = 5.0 * M_PI / 180;
double midx1, midy1, midx2, midy2;

void rotate(void)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        double xnew, ynew;

        xnew = midx1 + (face1[i][0] - midx1) * cos(angle) -
               (face1[i][1] - midy1) * sin(angle);
        ynew = midy1 + (face1[i][0] - midx1) * sin(angle) +
               (face1[i][1] - midy1) * cos(angle);

        face1[i][0] = xnew;
        face1[i][1] = ynew;

        xnew = midx2 + (face2[i][0] - midx2) * cos(angle) -
               (face2[i][1] - midy2) * sin(angle);
        ynew = midy2 + (face2[i][0] - midx2) * sin(angle) +
               (face2[i][1] - midy2) * cos(angle);

        face2[i][0] = xnew;
        face2[i][1] = ynew;
    }

    cleardevice();

    for (i = 0; i < 4; i++)
    {
        setcolor(7);
        line(face1[i][0], face1[i][1], face1[i + 1][0], face1[i + 1][1]);
        setcolor(8);
        line(face2[i][0], face2[i][1], face2[i + 1][0], face2[i + 1][1]);
        setcolor(9);
        line(face1[i][0], face1[i][1], face2[i][0], face2[i][1]);
    }

    delay(125);
}

int main()
{
    int gd = DETECT, gm;

    midx1 = (face1[0][0] + face1[1][0]) / 2.0;
    midy1 = (face1[1][1] + face1[2][1]) / 2.0;
    midx2 = (face2[0][0] + face2[1][0]) / 2.0;
    midy2 = (face2[1][1] + face2[2][1]) / 2.0;

    initgraph(&gd, &gm, "");

    while (!kbhit())
        rotate();

    closegraph();
    
    return 0;
}

