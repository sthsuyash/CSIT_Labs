#include <iostream>
#include <complex>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
typedef complex<double> point;
#define x real()
#define y imag()

void displaymenu()
{
    cout << "Press 1 for translation." << endl;
    cout << "Press 2 for rotation." << endl;
    cout << "Press 3 for scaling." << endl;
    cout << "Press 4 for reflecton." << endl;
    cout << "Press 5 for shearing." << endl;
}

void reflectionmenu()
{
    cout << "press 1 for reflection through x-axis." << endl;
    cout << "press 2 for reflection through y-axis." << endl;
}

void shearingmenu()
{
    cout << "press 1 for shearing through x-axis." << endl;
    cout << "press 2 for shearing through y-axis." << endl;
}

point translation(point A, int a, int b)
{
    point B(A.real() + a, A.imag() + b);
    return B;
}

point rotation(point A, int a, int b, float angl)
{
    point C = translation(A, -a, -b);
    point B(((C.real() * cos(angl)) - (C.imag() * sin(angl))), ((C.real() * sin(angl)) + (C.imag()) * cos(angl)));
    point D = translation(B, +a, +b);
    return D;
}

point scaling(point A, int a, int b)
{
    point B(A.real() * a, A.imag() * b);
    return B;
}

point reflectionthx(point A)
{

    point C(A.real(), -A.imag());
    point B = translation(C, 0, 600);

    return B;
}

point reflectionthy(point A)
{

    point C(-A.real(), A.imag());
    point B = translation(C, 600, 0);
    return B;
}

point shearingx(point A, int shx)
{
    point B(A.real() + shx * A.imag(), A.imag());
    return B;
}

point shearingy(point A, int shy)
{
    point B(A.real(), A.imag() + shy * A.real());
    return B;
}

int drawpolygon(point W, point X, point Y, point Z)
{
    line(W.real(), W.imag(), Z.real(), Z.imag());
    delay(200);
    line(Z.real(), Z.imag(), Y.real(), Y.imag());
    delay(200);
    line(Y.real(), Y.imag(), X.real(), X.imag());
    delay(200);
    line(X.real(), X.imag(), W.real(), W.imag());
    delay(200);
    return 0;
}

int main()
{
    int gd = DETECT, gm;
    point E, F, G, H;
    int x1, y1, x2, y2, x3, y3, x4, y4, choice, subchoice, i;

    cout << "Enter four coordinates of polygon(one in a single line): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    point A(x1, y1);
    point B(x2, y2);
    point C(x3, y3);
    point D(x4, y4);
    drawpolygon(A, B, C, D);
    displaymenu();

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        int a, b;
        cout << "Enter translation distances: ";
        cin >> a >> b;
        E = translation(A, a, b);
        F = translation(B, a, b);
        G = translation(C, a, b);
        H = translation(D, a, b);
        setcolor(RED);
        drawpolygon(E, F, G, H);
        getch();
        break;

    case 2:
        float angle, ang;
        int c, d; // pivot
        cout << "Enter pivot point for rotation: ";
        cin >> c >> d;
        cout << "Enter angle through which u want to rotate: ";
        cin >> ang;
        angle = (ang * 3.14) / 180;
        E = rotation(A, c, d, angle);
        F = rotation(B, c, d, angle);
        G = rotation(C, c, d, angle);
        H = rotation(D, c, d, angle);
        setcolor(RED);
        drawpolygon(E, F, G, H);
        break;

    case 3:
        int sx, sy;
        cout << "Enter scaling factors( Sx, Sy ): ";
        cin >> sx >> sy;
        E = scaling(A, sx, sy);
        F = scaling(B, sx, sy);
        G = scaling(C, sx, sy);
        H = scaling(D, sx, sy);
        setcolor(RED);
        drawpolygon(E, F, G, H);
        break;

    case 4:
        reflectionmenu();
        cout << "Choose type of reflection..";
        cin >> subchoice;
        switch (subchoice)
        {
        case 1:
            E = reflectionthx(A);
            F = reflectionthx(B);
            G = reflectionthx(C);
            H = reflectionthx(D);
            setcolor(RED);
            drawpolygon(E, F, G, H);
            break;

        case 2:
            E = reflectionthy(A);
            F = reflectionthy(B);
            G = reflectionthy(C);
            H = reflectionthy(D);
            setcolor(RED);
            drawpolygon(E, F, G, H);
            break;
        }
        break;

    case 5:
        shearingmenu();
        int shx, shy;
        cout << "Choose shearing option: ";
        cin >> subchoice;
        switch (subchoice)
        {
        case 1:
            cout << "Enter shearing distance: ";
            cin >> shx;
            E = A;
            F = shearingx(B, shx);
            G = shearingx(C, shx);
            H = D;
            setcolor(RED);
            drawpolygon(E, F, G, H);
            break;

        case 2:
            cout << "Enter shearing distance: ";
            cin >> shx;
            E = shearingy(A, shy);
            F = B;
            G = C;
            H = shearingy(D, shy);
            setcolor(RED);
            drawpolygon(E, F, G, H);
            break;
        }
        break;
    default:
        cout << "Invalid Choice..";
        main();
        break;
    }
    getch();
    closegraph();

    return 0;
}
