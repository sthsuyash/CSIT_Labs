#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

typedef struct Point
{
    int x;
    int y;
} Point;

// calculating bezier coefficients
void coefficients_caclulate(int n, int *coefficients)
{
    int k, j;
    for (k = 0; k <= n; k++)
    {
        coefficients[k] = 1;
        for (j = n; j >= k + 1; j--)
        {
            coefficients[k] *= j;
        }
        for (j = n - k; j >= 2; j--)
        {
            coefficients[k] /= j;
        }
    }
}

// calculating bezier points
void bezier_points(float parameter, Point *curve, int control_points_num, Point *control_points, int *coefficients)
{
    int k, n = control_points_num - 1;
    float blending;

    curve->x = 0.0;
    curve->y = 0.0;

    for (k = 0; k < control_points_num; k++)
    {
        blending = coefficients[k] * pow(parameter, k) * pow(1 - parameter, n - k);
        curve->x += control_points[k].x * blending;
        curve->y += control_points[k].y * blending;
    }
    putpixel(curve->x, curve->y, WHITE);
}

// drawing bezier curve
void bezier_curve(int divisions, int control_points_num, Point *control_points, int *coefficeints, Point *curve)
{
    coefficients_caclulate(control_points_num - 1, coefficeints);
    for (int i = 0; i <= divisions; i++)
    {
        float param = i / (float)divisions;
        bezier_points(param, curve, control_points_num, control_points, coefficeints);
    }
}

int main()
{
    int gd = DETECT, gm, control_points_num, coefficients[control_points_num], order;

    cout << "Enter number of control points: ";
    cin >> control_points_num;

    Point control_points[control_points_num];
    cout << "Enter control points (x,y): ";
    for (int i = 0; i < control_points_num; i++)
    {
        cin >> control_points[i].x >> control_points[i].y;
    }

    cout << "Enter the order of bezier curve: ";
    cin >> order;

    Point curve[order];

    bezier_curve(10000, control_points_num, control_points, coefficients, curve);
    initgraph(&gd, &gm, NULL);
    getch();
    closegraph();

    return 0;
}
