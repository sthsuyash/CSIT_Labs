#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void getPoints(int &x1, int &y1, int &x2, int &y2)
{
    cout << "Enter the coordinates of the first point: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point: ";
    cin >> x2 >> y2;
}

int main()
{
    int x1, y1, x2, y2; // coordinates of the first and second point
    float theta;        // angle of rotation

    getPoints(x1, y1, x2, y2);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Rectangle before rotation:" << endl;
    rectangle(x1, y1, x2, y2);

    cout << "Enter the angle of rotation: ";
    cin >> theta;

    theta = (theta * 3.14) / 180; // convert angle to radians
    long xr = x1 + ((x2 - x1) * cos(theta) - (y2 - y1) * sin(theta));
    long yr = y1 + ((x2 - x1) * sin(theta) + (y2 - y1) * cos(theta));

    cout << "Rectangle after rotation:" << endl;
    rectangle(x1, y1, xr, yr);

    getch();
    closegraph();
    
    return 0;
}

