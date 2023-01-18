#include <GL/glut.h>

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // set background color to black
    glClear(GL_COLOR_BUFFER_BIT);     // clear the color buffer

    glColor3f(0.0, 1.0, 0.0); // set the drawing color to green
    glBegin(GL_LINES);        // begin drawing a line
    glVertex2i(-0.4, 0.7);    // set the starting point of the line
    glVertex2i(0.6, -0.7);    // set the ending point of the line
    glEnd();                  // end drawing the line

    glFlush(); // flush the OpenGL pipeline
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);            // initialize GLUT
    glutInitWindowSize(700, 700);     // whole window size initialize
    glutInitWindowPosition(100, 100); // window position initialize
    glutCreateWindow("Green Line");   // create a window with the title "Green Line"
    glutDisplayFunc(display);         // set the display callback function
    glutMainLoop();                   // enter the GLUT event processing loop
    return 0;
}
