#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2; // coordinates of the first and second point
    int x, y;           // scaling factor

    cout << "Enter the coordinates of the first point: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point: ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Before scaling:" << endl;
    rectangle(x1, y1, x2, y2);

    cout << "Enter the scaling factor: ";
    cin >> x >> y;

    setcolor(YELLOW);
    cout << "After scaling:" << endl;
    rectangle(x1 * x, y1 * y, x2 * x, y2 * y);

    getch();
    closegraph();
    
    return 0;
}
