#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4; // coordinates of the first and second point
    int shx;                            // shearing factor

    cout << "Enter the first point(x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter the second point(x2,y2): ";
    cin >> x2 >> y2;
    cout << "Enter the third point(x3,y3): ";
    cin >> x3 >> y3;
    cout << "Enter the fourth point(x4,y4): ";
    cin >> x4 >> y4;

    cout << "Enter the shearing factor: ";
    cin >> shx;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Before shearing of rectangle" << endl;
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x3, y3, x4, y4);
    line(x2, y2, x4, y4);

    setcolor(YELLOW);
    cout << "After shearing of rectangle" << endl;
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x3, y3, x4, y4);
    line(x2, y2, x4, y4);

    getch();
    closegraph();

    return 0;
}
