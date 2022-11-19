// C program to draw rectangle in opengl

#include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // last value is alpha (transparency)
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0); // orthographic projection
}

void rectangle(void)
{
    glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0, 1.0, 0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Single frame buffer
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangle");
    glutDisplayFunc(rectangle);
    glutMainLoop();
    return 0;
}
