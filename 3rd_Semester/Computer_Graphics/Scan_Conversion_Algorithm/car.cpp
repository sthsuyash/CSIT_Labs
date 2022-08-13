#include <graphics.h>
#include <stdio.h>

// Function to draw moving car
void draw_moving_car()
{
	int i = 10, j = -10;
	int gd = DETECT, gm;
	//	initgraph(&gd, &gm, "");
	initwindow(900, 700);

	while (true)
	{
		int i = 0, x = 0;
		char ch;

		// Set color of car
		

		while (true)
		{
			setcolor(7);

			// Thease lines for bonnet and body of car
			line(0 + i, 300, 210 + i, 300);
			line(50 + i, 300, 75 + i, 270);
			line(75 + i, 270, 150 + i, 270);
			line(150 + i, 270, 165 + i, 300);
			line(0 + i, 300, 0 + i, 330);
			line(210 + i, 300, 210 + i, 330);

			line(0, 345, getmaxx(), 345);

			// For left wheel of car
			circle(65 + i, 330, 15);
			circle(65 + i, 330, 2);

			// For right wheel of car
			circle(145 + i, 330, 15);
			circle(145 + i, 330, 2);

			// Line left of left wheel
			line(0 + i, 330, 50 + i, 330);

			// Line middle of both wheel
			line(80 + i, 330, 130 + i, 330);

			// Line right of right wheel
			line(210 + i, 330, 160 + i, 330);

			delay(100);

			if (kbhit()) // check if a key is pressed
			{
				ch = getch();
				setcolor(BLACK);
				cleardevice();

				if (ch == 61) // move left
				{
					x = -10;
					
				}

				if (ch == 63) // move right
				{
					x = 10;
				}

				if (ch == 27) // exit when esc pressed
					exit(0);
			}
			i = i + x;

			delay(50);
		
		}
	}

	// To erase previous drawn car, draw
	// the whole car at same position
	// but color using black
	// setcolor(BLACK);

	// // Lines for bonnet and body of car
	// line(0, 300, 210, 300);
	// line(50, 300, 75, 270);
	// line(75, 270, 150, 270);
	// line(150, 270, 165, 300);
	// line(0, 300, 0, 330);
	// line(210, 300, 210, 330);

	// // For left wheel of car
	// circle(65, 330, 15);
	// circle(65, 330, 2);

	// // For right wheel of car
	// circle(145, 330, 15);
	// circle(145, 330, 2);

	// // Line left of left wheel
	// line(0, 330, 50, 330);

	// // Line middle of both wheel
	// line(80, 330, 130, 330);

	// // Line right of right wheel
	// line(210, 330, 160, 330);

	getch();
	closegraph();
}

// Driver code
int main()
{
	draw_moving_car();

	return 0;
}
