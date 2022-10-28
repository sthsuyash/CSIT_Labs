#include <iostream>
#include <graphics.h>
#include <math.h>

void p3e(float x, float y, float z)
{
    float end = 1000;
    float p = end / (end + z);
    x = 300 - x * p;
    y = 250 + y * p;
    ellipse(x, y, 0, 360, 3, 1);
}

int main()
{
    int gd = 0, gm, z, x, y, i, r = 150, j, lo, la;
    initgraph(&gd, &gm, NULL);
    float rd = 3.1428 / 180, an = 40;
    for (lo = 0; lo < 100; lo++)
    {
        for (i = 0; i < 180; i += 15)
        {
            for (j = 0; j < 360; j += 15)
            {
                x = r * cos(rd * j) * sin(rd * i);
                y = r * sin(rd * j) * sin(rd * i);
                z = r * cos(rd * i);
                // x rotation
                y = y * cos(rd * an) - z * sin(rd * an);
                z = y * sin(rd * an) + z * cos(rd * an);
                // x=x*cos(rd*an)-y*sin(rd*an);
                // y=x*sin(rd*an)+y*cos(rd*an);
                p3e(x, y, z);
            }
        }
        delay(200);
        cleardevice();
        an += 1;
    }
    getch();
    closegraph();
    return 0;
}
