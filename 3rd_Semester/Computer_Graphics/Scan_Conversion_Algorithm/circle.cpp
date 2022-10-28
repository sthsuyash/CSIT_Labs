#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;

void midPointCircleDraw(int x_centre, int y_centre, int r)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	int x = 0, y = r;

	putpixel(x + x_centre, y + y_centre, WHITE);

	if (r > 0)
	{
		putpixel(x + x_centre, -y + y_centre, WHITE);
		putpixel(y + x_centre, x + y_centre, WHITE);
		putpixel(-y + x_centre, x + y_centre, WHITE);
	}

	int P = 1 - r;
	while (x <= y)
	{
		x++;
		if (P <= 0)
		{
			P = P + 2 * x + 1;
		}
		else
		{
			y--;
			P = P + 2 * x - 2 * y + 1;
		}
		if (x > y)
			break;

		putpixel(x + x_centre, y + y_centre, WHITE);
		putpixel(-x + x_centre, y + y_centre, WHITE);
		putpixel(x + x_centre, -y + y_centre, WHITE);
		putpixel(-x + x_centre, -y + y_centre, WHITE);

		if (x != y)
		{
			putpixel(y + x_centre, x + y_centre, WHITE);
			putpixel(-y + x_centre, x + y_centre, WHITE);
			putpixel(y + x_centre, -x + y_centre, WHITE);
			putpixel(-y + x_centre, -x + y_centre, WHITE);
		}
	}
	getch();
	closegraph();
}

int main()
{
	int x, y, r;
	cout << "Enter centre coordinates(x,y): ";
	cin >> x >> y;
	cout << "Enter radius: ";
	cin >> r;
	midPointCircleDraw(x, y, r); //(h,k,radius)

	return 0;
}
