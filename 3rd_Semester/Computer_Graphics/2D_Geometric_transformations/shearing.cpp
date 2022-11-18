// C++ program for shearing of rectangle
// in X-axis or Y-axis

#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void shear(int, int, int, int, int, int, int, int); // declare function

int main()
{
    int x[4], y[4]; // coordinates of the first and second point
    int sh;         // shearing factor

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the coordinates of the point (x" << i + 1 << ", y" << i + 1 << "): ";
        cin >> x[i] >> y[i];
    }

    char axis;
    cout << "Which axis you want to shear?" << endl
         << "1 for X-axis" << endl
         << "2 for Y-axis" << endl
         << "3 for X-axis and Y-axis" << endl;
    cout << "Enter your choice: ";
    cin >> axis;

    cout << "Enter the shearing factor x: ";
    cin >> sh;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // initial figure
    outtextxy(10, 10, "Before shearing of rectangle");
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
    getch();
    cleardevice();

    switch (axis)
    {
    case 1:
        // shearing X - axis formula
        for (int i = 0; i < 4; i++)
        {
            x[i] = x[i] + sh * y[i];
        }
        outtextxy(10, 10, "After shearing of rectangle in X-axis");
        shear(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
        getch();
        break;

    case 2:
        // shearing Y - axis formula
        for (int i = 0; i < 4; i++)
        {
            y[i] = y[i] + sh * x[i];
        }
        outtextxy(10, 10, "After shearing of rectangle in Y-axis");
        shear(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
        getch();
        break;

    case 3:
        int t[4];
        for (int i = 0; i < 4; i++)
        {
            t[i] = y[i];
        }

        // shearing X & Y - axis formula
        for (int i = 0; i < 4; i++)
        {
            x[i] = x[i] + sh * y[i];
            y[i] = t[i] + sh * x[i];
        }
        outtextxy(10, 10, "After shearing of rectangle in X-Y-axis");
        shear(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
        getch();
        break;

    default:
        cout << "Enter a valid choice." << endl;
        break;
    }
    closegraph();

    return 0;
}

void shear(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3)
{
    setcolor(YELLOW);
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);
}
