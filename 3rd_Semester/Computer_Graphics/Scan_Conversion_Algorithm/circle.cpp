#include <iostream>
#include <graphics.h>
using namespace std;

void drawcircle(int x0, int y0, int radius)
{
	// graphics initialization
	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, "");

	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		putpixel(x0 + x, y0 + y, 7);
		putpixel(x0 + y, y0 + x, 7);
		putpixel(x0 - y, y0 + x, 7);
		putpixel(x0 - x, y0 + y, 7);
		putpixel(x0 - x, y0 - y, 7);
		putpixel(x0 - y, y0 - x, 7);
		putpixel(x0 + y, y0 - x, 7);
		putpixel(x0 + x, y0 - y, 7);

		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
	getch();
}

int main()
{
	int x, y, r;

	cout << "Enter radius of circle: ";
	cin >> r;

	cout << "Enter co-ordinates of center(x and y): ";
	cin >> x >> y;

	drawcircle(x, y, r);

	return 0;
}
