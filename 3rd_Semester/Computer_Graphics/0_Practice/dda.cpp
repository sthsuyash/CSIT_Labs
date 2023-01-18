// C program for DDA line generation
#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>

// DDA Function for line generation
void DDA(int X0, int Y0, int X1, int Y1)
{
    int gd = DETECT, gm;
    // Initialize graphics function
    initgraph(&gd, &gm, "");
    /*
    Step 1:
    getting input of two end points from user,
        => passed as function arguements from main function in this case.
    */

    /*
    Step 2:
    calculate dx & dy
    */
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    /*
    Step 3:
    calculate steps required for generating pixels
    if (dx>dy) steps = absolute(dx);
    else steps = absolute(dy)
    */
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    /*
    Step 4:
    calculate increment in x & y for each steps
    */
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    /*
    Step 5:
    Put pixel for each by successfully incrementing x and y coordinates accoordingly to complete drawing the line.
    */
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(X), round(Y), WHITE); // put pixel at (X,Y) with color white
        X += Xinc;                           // increment in x at each step
        Y += Yinc;                           // increment in y at each step
                                             // delay(100);          // for visualization of generation step by step
    }
    getch();
    closegraph();

    printf("\n\nDDA Completed.");
}

// Driver program
int main()
{
    // declaring necessary points
    int X0, Y0, X1, Y1;

    // scanning the points for drawing
    printf("Enter the initial cordinates: ");
    scanf("%d %d", &X0, &Y0);
    printf("Enter the final X-coordinates: ");
    scanf("%d %d", &X1, &Y1);

    // implement the DDA algorithm code
    DDA(X0, Y0, X1, Y1);

    // hold the display of line until any key is pressed.
    getch();
    return 0;
}
