#include <iostream>
#include <graphics.h>

int main()
{
    // Initialize the drivers
    int gm, gd = DETECT;

    int x1, y1, x2, y2, x3, y3; // coordinates of the first, second and third point

    cout << "Enter the coordinates of the first point(x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point(x2, y2): ";
    cin >> x2 >> y2;
    cout << "Enter the coordinates of the third point(x3, y3): ";
    cin >> x3 >> y3;

    initgraph(&gd, &gm, "");
    cleardevice();

    // Draw the graph
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

    // Object initially at 2nd quadrant
    cout << "Before Reflection Object in 2nd Quadrant" << endl;

    // Set the color
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    getch();

    // After reflection
    cout << "After Reflection" << endl;

    // Reflection along origin i.e., in 4th quadrant
    setcolor(4);
    line(getmaxx() - x1, getmaxy() - y1, getmaxx() - x2, getmaxy() - y2);

    line(getmaxx() - x2, getmaxy() - y2, getmaxx() - x3, getmaxy() - y3);

    line(getmaxx() - x3, getmaxy() - y3, getmaxx() - x1, getmaxy() - y1);

    // Reflection along x-axis i.e., in 1st quadrant
    setcolor(3);
    line(getmaxx() - x1, y1, getmaxx() - x2, y2);
    line(getmaxx() - x2, y2, getmaxx() - x3, y3);
    line(getmaxx() - x3, y3, getmaxx() - x1, y1);

    // Reflection along y-axis i.e., in 3rd quadrant
    setcolor(2);
    line(x1, getmaxy() - y1, x2, getmaxy() - y2);
    line(x2, getmaxy() - y2, x3, getmaxy() - y3);
    line(x3, getmaxy() - y3, x1, getmaxy() - y1);
    getch();

    // Close the graphics
    closegraph();
    return 0;
}
