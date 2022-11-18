#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int x1, y1, x2, y2, x3, y3, a, b;
void draw();
void rotate();

int main(void)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    printf("Enter first co-ordinate value for triangle:");
    scanf("%d%d", &x1, &y1);
    printf("Enter second co-ordinatevalues for triangle:");
    scanf("%d%d", &x2, &y2);
    printf("Enter third co-ordinate valuesfor triangle:");
    scanf("%d%d", &x3, &y3);
    draw();
    getch();
    rotate();
    getch();

    return 0;
}

void draw()
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void rotate()
{
    int a1, a2, a3, b1, b2, b3;
    float angle;

    printf("Enter the rotation angle co-ordinates:");
    scanf("%f", &angle);

    
    cleardevice();
    angle = (angle * 3.14) / 180;
    a1 = a + (x1 - a) * cos(angle) - (y1 - b) * sin(angle);
    b1 = b + (x1 - a) * sin(angle) + (y2 - b) * cos(angle);
    a2 = a + (x2 - a) * cos(angle) - (y1 - b) * sin(angle);
    b2 = b + (x2 - a) * sin(angle) + (y2 - b) * cos(angle);
    a3 = a + (x3 - a) * cos(angle) - (y1 - b) * sin(angle);
    b3 = b + (x3 - a) * sin(angle) + (y2 - b) * cos(angle);

    printf("ROTATION");
    printf("\nChanged coordinates\n");
    printf("%d %d\n%d %d\n%d %d", a1, b1, a2, b2, a3, b3);
    line(a1, b1, a2, b2);
    line(a2, b2, a3, b3);
    line(a3, b3, a1, b1);
}