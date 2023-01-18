#include <GL/glut.h>

void quad()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.5);
    glVertex2f(-0.5, 1);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);     // whole window size initialize
    glutInitWindowPosition(100, 100); // window position initialize
    glutCreateWindow("Quadrilateral");
    glutDisplayFunc(quad);
    glutMainLoop();
    return 0;
}
