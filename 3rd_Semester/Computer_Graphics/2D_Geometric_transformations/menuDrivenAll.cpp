#include <iostream>
#include <complex>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;

typedef complex<double> point;
#define x real()
#define y imag()

void displaymenu();
int drawpolygon(point, point, point, point);
point translation(point, int, int);
point scaling(point, int, int);
point rotation(point, int, int, float);
void reflectionmenu();
point reflectionthx(point);
point reflectionthy(point);
point reflectionthymx(point);
point reflectionthyx(point);
point reflectionthline(point, point, point);
void shearingmenu();
point shearingx(point, int);
point shearingy(point, int);
point shearingxy(point, int, int);

int main()
{
	int gd = DETECT, gm;
	point E, F, G, H;

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	int x1, y1, x2, y2, x3, y3, x4, y4, choice, subchoice, i;

	cout << "Enter four coordinates of polygon(one in a single line): ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

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

		cout << "Enter scaling factors(Sx,Sy): ";
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

		case 3:
			E = reflectionthyx(A);
			F = reflectionthyx(B);
			G = reflectionthyx(C);
			H = reflectionthyx(D);
			setcolor(RED);
			drawpolygon(E, F, G, H);
			break;

		case 4:
			E = reflectionthymx(A);
			F = reflectionthymx(B);
			G = reflectionthymx(C);
			H = reflectionthymx(D);
			setcolor(RED);
			drawpolygon(E, F, G, H);
			break;

		case 5:
			int a1, b1, a2, b2;

			cout << "Enter starting and end coordinates of line:";
			cin >> a1 >> b1 >> a2 >> b2;

			point X(a1, b1);
			point Y(a2, b2);

			E = reflectionthline(A, X, Y);
			F = reflectionthline(B, X, Y);
			G = reflectionthline(C, X, Y);
			H = reflectionthline(D, X, Y);
			setcolor(RED);
			drawpolygon(E, F, G, H);
			break;
		}
		break;

	case 5:
		shearingmenu();
		int shx, shy;

		cout << "Choose shearing option:";
		cin >> subchoice;

		switch (subchoice)
		{
		case 1:
			cout << "enter shearing distance: ";
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

		case 3:
			cout << "Enter x and y shearing distance: ";
			cin >> shx >> shy;
			E = shearingxy(A, shx, shy);
			F = shearingxy(B, shx, shy);
			G = shearingxy(C, shx, shy);
			H = shearingxy(D, shx, shy);
			setcolor(RED);
			drawpolygon(E, F, G, H);
			break;
		}
		break;

	default:
		cout << "Invalid Choice..";
		break;
	}
	getch();
	closegraph();

	return 0;
}

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
	cout << "press 3 for reflection through line y=x." << endl;
	cout << "press 4 for reflection through line y=-x." << endl;
	cout << "press 5 for reftection through a line" << endl;
}

void shearingmenu()
{
	cout << "press 1 for shearing through x-axis." << endl;
	cout << "press 2 for shearing through y-axis." << endl;
	cout << "press 3 for shearing through xy-axis." << endl;
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

point reflectionthyx(point A)
{
	int p, q;
	p = A.imag();
	q = A.real();
	point C(p, q);

	return C;
}

point reflectionthymx(point A)
{
	int p, q;
	p = A.imag();
	q = A.real();
	point C(-p, -q);
	point B = translation(C, 500, 500);
	return B;
}

point reflectionthline(point P, point A, point B)
{
	point Pt = P - A;
	point Bt = B - A;
	point Pr = Pt / Bt;
	return conj(Pr) * Bt + A;
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

point shearingxy(point A, int shx, int shy)
{
	point B((A.real() + shx * A.imag()), (A.imag() + shy * A.real()));
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