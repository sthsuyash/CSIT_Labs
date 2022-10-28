#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;

int maxx, maxy, midx, midy;

void axis(int maxx, int maxy, int midx, int midy)
{
    getch();
    cleardevice();
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}

void translation(int maxx, int maxy, int midx, int midy)
{
    int x, y;
    outtextxy(100, 20, "TRANSLATION");

    cout << "Enter the Translation vector(x,y): ";
    cin >> x >> y;

    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    bar3d(midx + (x + 100), midy - (y + 20), midx + (x + 60), midy - (y + 90), 20, 5);

    axis(maxx, maxy, midx, midy);
    outtextxy(100, 100, "END OF PROGRAM. Goto terminal window");
}

void scaling(int maxx, int maxy, int midx, int midy)
{
    int x, y, z;
    outtextxy(100, 20, "SCALING");

    cout << "Enter the Scaling Factor: ";
    cin >> x >> y >> z;

    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    bar3d(midx + (x * 100), midy - (y * 20), midx + (x * 60), midy - (y * 90), 20 * z, 5);

    axis(maxx, maxy, midx, midy);
    outtextxy(100, 100, "END OF PROGRAM. Goto terminal window");
}

void rotation(int maxx, int maxy, int midx, int midy)
{
    int ang, x1, y1, x2, y2;

    outtextxy(100, 20, "ROTATION");

    cout << "Enter the Rotation angle: ";
    cin >> ang;

    x1 = 100 * cos(ang * 3.14 / 180) - 20 * sin(ang * 3.14 / 180);
    y1 = 100 * sin(ang * 3.14 / 180) + 20 * sin(ang * 3.14 / 180);
    x2 = 60 * cos(ang * 3.14 / 180) - 90 * sin(ang * 3.14 / 180);
    y2 = 60 * sin(ang * 3.14 / 180) + 90 * sin(ang * 3.14 / 180);

    // outtextxy(100, 20, "After rotating about z-axis");
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    bar3d(midx + x1, midy - y1, midx + x2, midy - y2, 20, 5);
    getch();
    // axis();

    // outtextxy(100, 20, "After rotating about x-axis");
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    bar3d(midx + 100, midy - x1, midx + 60, midy - x2, 20, 5);
    getch();
    // axis();

    // outtextxy(100, 20, "After rotating about y-axis");
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    bar3d(midx + x1, midy - 20, midx + x2, midy - 90, 20, 5);

    axis(maxx, maxy, midx, midy);
    outtextxy(100, 100, "END OF PROGRAM. Goto terminal window");
}

// driver function
int main()
{
    int choice;
    cout << "Menu driven program for 3D transformation" << endl
         << "1.Translation" << endl
         << "2.Scaling" << endl
         << "3.Rotation" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");

    setfillstyle(3, 25);
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    // draw original object
    outtextxy(100, 100, "ORIGINAL OBJECT");
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    axis(maxx, maxy, midx, midy);
    cout << "\nPress any key to continue..." << endl
         << endl;

    // char continue_choice;
    // do
    // {
    // menu for program
    switch (choice)
    {
    case 1:
        translation(maxx, maxy, midx, midy);
        break;

    case 2:
        scaling(maxx, maxy, midx, midy);
        break;

    case 3:
        rotation(maxx, maxy, midx, midy);
        break;

    default:
        cout << "Invalid choice" << endl;
        break;
    }
    //     cout << "Do you want to continue?(y/n): ";
    // } while (continue_choice == 'y');

    getch();
    closegraph();
}
