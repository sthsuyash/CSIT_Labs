#include <windows.h>
#include <GL/glut.h>

void init(void);
void lineSegment(void);

// driver program
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);	  // whole window size initialize
	glutInitWindowPosition(100, 100); // window position initialize
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Line");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
	return EXIT_SUCCESS;
}

void init(void)
{
	glClearColor(1.0, 10.0, 100.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	// GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUAD_STRIP, and GL_POLYGON
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();
	glFinish();
}

