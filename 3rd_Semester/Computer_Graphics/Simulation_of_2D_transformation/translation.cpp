#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2; // coordinates of the first and second point
    int tx, ty;         // Translation factor

    cout << "Enter the coordinates of the first point: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point: ";
    cin >> x2 >> y2;

    cout << "Enter the translation matrix: ";
    cin >> tx >> ty;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Rectangle before translation" << endl;
    rectangle(x1, y1, x2, y2);

    setcolor(YELLOW);
    cout << "Rectangle after translation:" << endl;
    rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);

    getch();
    closegraph();
    
    return 0;
}
