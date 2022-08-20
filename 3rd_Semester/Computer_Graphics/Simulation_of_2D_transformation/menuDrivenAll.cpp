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
    int choice;
    cout << "Press: " << endl
         << "1. Translation" << endl
         << "2. Rotation" << endl
         << "3. Scaling" << endl
         << "4. Reflection" << endl
         << "5. Shearing" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    switch (choice)
    {
    // Translation
    case 1:
        int x1, y1, x2, y2; // coordinates of the first and second point
        int tx, ty;         // Translation factor

        getPoints(x1, y1, x2, y2);
        cout << "Rectangle before translation" << endl;
        rectangle(x1, y1, x2, y2);

        setcolor(YELLOW);
        cout << "Enter the translation matrix: ";
        cin >> tx >> ty;

        cout << "Rectangle after translation:" << endl;
        rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);

        break;

    // Rotation
    case 2:
        int x1, y1, x2, y2; // coordinates of the first and second point
        float theta;        // angle of rotation

        getPoints(x1, y1, x2, y2);
        cout << "Rectangle before rotation:" << endl;
        rectangle(x1, y1, x2, y2);

        cout << "Enter the angle of rotation: ";
        cin >> theta;

        theta = (theta * 3.14) / 180; // convert angle to radians
        long xr = x1 + ((x2 - x1) * cos(a) - (y2 - y1) * sin(a));
        long yr = y1 + ((x2 - x1) * sin(a) + (y2 - y1) * cos(a));

        setcolor(YELLOW);
        cout << "Rectangle after rotation:" << endl;
        rectangle(x1, y1, xr, yr);

        break;

    // Scaling
    case 3:
        int x1, y1, x2, y2; // coordinates of the first and second point
        int x, y;           // scaling factor

        getPoints(x1, y1, x2, y2);
        cout << "Before scaling:" << endl;
        rectangle(x1, y1, x2, y2);

        cout << "Enter the scaling factor: ";
        cin >> x >> y;

        setcolor(YELLOW);
        cout << "After scaling:" << endl;
        rectangle(x1 * x, y1 * y, x2 * x, y2 * y);

        break;

    // Reflection
    case 4:
        int x1, y1, x2, y2, x3, y3; // coordinates of the first and second point
        int x;                      // reflection factor

        getPoints(x1, y1, x2, y2);
        cout << "Enter the coordinates of the third point: ";
        cin >> x3 >> y3;

        cout << "Enter the reflection factor: ";
        cin >> x;

        cout << "Before reflection:" << endl;

        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x2, y2, x3, y3);

        setcolor(YELLOW);
        printf("Triangle after reflection\n");
        line(x1, -y1 + x, x2, -y2 + x);
        line(x1, -y1 + x, x3, -y3 + x);
        line(x2, -y2 + x, x3, -y3 + x);

        break;

    // Shearing
    case 5:
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

        cout << "Before shearing of rectangle" << endl;
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x3, y3, x4, y4);
        line(x2, y2, x4, y4);

        cout << "Enter the shearing factor: ";
        cin >> shx;

        printf("After shearing of rectangle\n");
        x1 = x1 + shx * y1;
        x2 = x2 + shx * y2;
        x3 = x3 + shx * y3;
        x4 = x4 + shx * y4;
        setcolor(YELLOW);
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x3, y3, x4, y4);
        line(x2, y2, x4, y4);
        break;

    default:
        cout << "Enter a valid option\b" << endl;
        main();
        break;
    }

    getch();
    closegraph();
    return 0;
}
