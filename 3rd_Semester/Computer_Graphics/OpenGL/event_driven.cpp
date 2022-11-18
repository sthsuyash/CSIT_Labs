#include <math.h>
#include <GL/glut.h>

float transZ = 50;
float rotateA = 0;
float rotateAspeed = 0.0;

static GLfloat theta[] = {60.0, 60.0, 60.0};

void cube(float dimX, float dimY, float dimZ);
void display(void);
void init(void);
void reshape(int w, int h);
void idle(void);
void mouse(int button, int state, int x, int y);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);     // sets inistial window size to the provided res
    glutInitWindowPosition(100, 100); // position of the window
    glutCreateWindow("Cube");
    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

// function to draw the cube
void cube(float dimX, float dimY, float dimZ)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(0, dimY / 2, 0);

    glScalef(dimX / 2, dimY / 2, dimZ / 2);

    glRotatef(theta[0], 1, 0, 0); // rotate alpha around the x axis
    glRotatef(theta[1], 0, 1, 0); // rotate beta around the y axis
    glRotatef(theta[2], 0, 0, 1); // rotate gamma around the z axis

    glBegin(GL_QUADS);

    glColor3f(0.0, 1.0, 0.0); // Color Green - TOP

    glVertex3f(1.0, 1.0, 1.0);   // TOP-RIGHT-NEAR
    glVertex3f(-1.0, 1.0, 1.0);  // TOP-LEFT-NEAR
    glVertex3f(-1.0, 1.0, -1.0); // TOP-LEFT-FAR
    glVertex3f(1.0, 1.0, -1.0);  // TOP-RIGHT-FAR

    glColor3f(1.0, 0.0, 0.0); // Color RED - Bottom

    glVertex3f(1.0, -1.0, 1.0);   // BOTTOM-RIGHT-NEAR
    glVertex3f(-1.0, -1.0, 1.0);  // BOTTOM-LEFT-NEAR
    glVertex3f(-1.0, -1.0, -1.0); // BOTTOM-LEFT-FAR
    glVertex3f(1.0, -1.0, -1.0);  // BOTTOM-RIGHT-FAR

    glColor3f(1.0, 1.0, 0.0); // Color Yellow - Back

    glVertex3f(1.0, 1.0, -1.0);   // TOP-RIGHT-FAR
    glVertex3f(-1.0, 1.0, -1.0);  // TOP-LEFT-FAR
    glVertex3f(-1.0, -1.0, -1.0); // BOTTOM-LEFT-FAR
    glVertex3f(1.0, -1.0, -1.0);  // BOTTOM-RIGHT-FAR

    glColor3f(0.0, 0.0, 1.0); // Color Blue - RIGHT

    glVertex3f(1.0, 1.0, 1.0);   // TOP-FRONT-NEAR
    glVertex3f(1.0, 1.0, -1.0);  // TOP-BACK-FAR
    glVertex3f(1.0, -1.0, -1.0); // BOTTOM-BACK-FAR
    glVertex3f(1.0, -1.0, 1.0);  // BOTTOM-FRONT-NEAR

    glColor3f(1.0, 0.5, 0.0); // Color Orange - Left

    glVertex3f(-1.0, 1.0, 1.0);   // TOP-FRONT-NEAR
    glVertex3f(-1.0, 1.0, -1.0);  // TOP-BACK-FAR
    glVertex3f(-1.0, -1.0, -1.0); // BOTTOM-BACK-FAR
    glVertex3f(-1.0, -1.0, 1.0);  // BOTTOM-FRONT-NEAR

    glColor3f(1.0, 0.0, 1.0); // Color Violet - Front

    glVertex3f(1.0, 1.0, 1.0);   // TOP-RIGHT-NEAR
    glVertex3f(-1.0, 1.0, 1.0);  // TOP-LEFT-NEAR
    glVertex3f(-1.0, -1.0, 1.0); // BOTTOM-LEFT-NEAR
    glVertex3f(1.0, -1.0, 1.0);  // BOTTOM-RIGHT-NEAR

    glEnd();

    glPopMatrix();
}

// function for display
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(transZ * cos(rotateA), 10, transZ * sin(rotateA), 0, 10, 0, 0, 1, 0);
    cube(30, 30, 30);
    glFlush();
    glutSwapBuffers();
}

// function initializing the conditions
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // clearing residue from previous runs

    glFrustum(-1, 1, -1, 1, 1, 1000);

    glEnable(GL_DEPTH_TEST); // for back face detection of the surface of the cube
}

// function for idle case
void idle(void)
{
    rotateA = rotateA + rotateAspeed;
    glutPostRedisplay();
}

// function for mouse rotation
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        rotateAspeed -= 0.01f;
    }

    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        rotateAspeed = 0;
    }

    if (button == 3 && state == GLUT_UP)
    {
        transZ -= 1.0f;
    }

    if (button == 4 && state == GLUT_UP)
    {
        transZ += 1.0f;
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        rotateAspeed += 0.01f;
    }
}

// function for maintaining the aspect ratio whenever we change the window size
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glFrustum(-1.0, 1.0, -1.0 * (GLfloat)h / (GLfloat)w, 1.0 * (GLfloat)h / (GLfloat)w, 1.0, 1000.0);
    else
        glFrustum(-1.0 * (GLfloat)w / (GLfloat)h, 1.0 * (GLfloat)w / (GLfloat)h, -1.0, 1.0, 1.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
}
