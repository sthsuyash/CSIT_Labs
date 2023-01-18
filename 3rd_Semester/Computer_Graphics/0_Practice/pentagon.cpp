#include "GL/glut.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.9);
    glVertex2f(-0.9, 0.2);
    glVertex2f(0.0, 0.9);
    glVertex2f(0.9, 0.2);
    glVertex2f(0.6, -0.9);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Pentagon");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}