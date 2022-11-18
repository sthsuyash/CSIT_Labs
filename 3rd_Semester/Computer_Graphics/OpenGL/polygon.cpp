// c program to draw a polygon using openGL

#include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // last value is alpha (transparency)
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0); // orthographic projection
}

void polygon(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.0, 0.5);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Single frame buffer
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polygon");
    glutDisplayFunc(polygon);
    glutMainLoop();
    return 0;
}
