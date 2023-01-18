#include <GL/glut.h>

void tri()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.8);
    glVertex2f(-0.8, 0.8);
    glVertex2f(0.8, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);     // whole window size initialize
    glutInitWindowPosition(100, 100); // window position initialize
    glutCreateWindow("Triangle");
    glutDisplayFunc(tri);
    glutMainLoop();
    return 0;
}
