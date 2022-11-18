#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm, i = 0, maxx, cy;

    initgraph(&gd, &gm, "");
    cleardevice();
    setbkcolor(WHITE); // set background color to white

    maxx = getmaxx();   // get maximum x coordinate of screen
    cy = getmaxy() / 2; // get y coordinate of center of screen

    // set red for border of car
    setcolor(RED);

    for (i = 0; i < maxx - 148; i++)
    {
        cleardevice();

        line(0, cy + 32, maxx, cy + 32);
        line(0, cy + 37, maxx, cy + 37);

        setfillstyle(1, RED);
        floodfill(0 + i, cy + 33, 4);

        line(0 + i, cy - 30, 0 + i, cy + 15);
        line(0 + i, cy - 30, 30 + i, cy - 30);

        line(30 + i, cy - 30, 45 + i, cy - 60);
        line(45 + i, cy - 60, 120 + i, cy - 60);

        line(120 + i, cy - 60, 135 + i, cy - 30);
        line(135 + i, cy - 30, 165 + i, cy - 30);
        line(165 + i, cy + 15, 165 + i, cy - 30);

        line(0 + i, cy + 15, 22 + i, cy + 15);
        circle(40 + i, cy + 15, 18);

        line(58 + i, cy + 15, 112 + i, cy + 15);
        circle(130 + i, cy + 15, 18);

        line(148 + i, cy + 15, 164 + i, cy + 15);

        // window
        rectangle(55 + i, cy - 50, 110 + i, cy - 30);

        // fill the interior of the car
        setfillstyle(1, BLUE);
        floodfill(50 + i, cy - 50, RED);

        // set below road to green
        setfillstyle(1, GREEN);
        floodfill(0 + i, cy * 2, RED);

        delay(10);
    }
    getch();
    closegraph();

    return 0;
}
