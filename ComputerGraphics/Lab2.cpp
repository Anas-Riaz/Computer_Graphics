#include <windows.h>
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>

void getScreenResolution();
void Room();
void bgColor();
void reshape(int, int);


int ScreenWidth, ScreenHeight;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    getScreenResolution();
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_ALPHA | GLUT_DEPTH);  // Type of BUFFER  

    glutInitWindowPosition(200, 100);    // position of the window. 
    glutInitWindowSize(ScreenWidth, ScreenHeight);      // total size of the window.


    glutCreateWindow("Room Design");    // title of the window.
    glutDisplayFunc(Room);              // Display function t actually display the window.
    bgColor();                          // function to set bg color of the window.    
    glutReshapeFunc(reshape);           // reshape the window (clipping the drawing size).

    glutMainLoop();                // Application loop(runs our program till it willbe ended by user.

    return 0;
}


void getScreenResolution() {
    ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
}


void bgColor() {
    glClearColor(0, 0, 0, 1.0);  // setting bgcolor of the window to white.
}


void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);  //setting matrix mode to projection. 
    glLoadIdentity();    // resets the current matrix.
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW); // default mode.

}


void Room() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clearing the buffer and setting upto default.
    glLoadIdentity();    // resets the current matrix.


    //front Wall 
    glColor3f(1.0f, 0.90196f, 0.74118f);
    glBegin(GL_POLYGON);  // we actually tell that we are going to define vertices.
    glVertex2f(6, 6);
    glVertex2f(-6, 6);
    glVertex2f(-6, -5);
    glVertex2f(6, -5);
    glEnd();    // tells that we are finish drawing vertices.


    // left side wall
    glColor3f(1.0f, 0.878431f, 0.717647f);
    glBegin(GL_POLYGON);
    glVertex2f(-6, 6);
    glVertex2f(-10, 8);
    glVertex2f(-15, -14);
    glVertex2f(-6, -5);
    glEnd();


    //right side wall
    glColor3f(1.0f, 0.878431f, 0.717647f);
    glBegin(GL_POLYGON);
    glVertex2f(6.0001, 6);
    glVertex2f(10, 8);
    glVertex2f(15, -14);
    glVertex2f(6.0001, -5);
    glEnd();


    // Ceiling
    glColor3f(0.996078f, 0.741176f, 0.615686f);
    glBegin(GL_POLYGON);  // we actually tell that we are going to define vertices.
    glVertex2f(6, 6);
    glVertex2f(10, 8);
    glVertex2f(10, 10);
    glVertex2f(-10, 10);
    glVertex2f(-10, 8);
    glVertex2f(-6, 6);
    glEnd();

    // Ceiling Dec
    glColor3f(0.996078f, 0.792157f, 0.650980f);    //right most
    glBegin(GL_POLYGON);
    glVertex2f(4.8, 5.5);
    glVertex2f(6, 5.5);
    glVertex2f(10, 8);
    glVertex2f(10, 10);
    glVertex2f(7.7, 10);
    glEnd();

    glColor3f(1.0f, 0.639216f, 0.490196f);
    glLineWidth(12.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4.8, 5.5);
    glVertex2f(4.8, 6);
    glVertex2f(7.22, 10);
    glVertex2f(7.65, 10);
    glEnd();


    glColor3f(0.996078f, 0.792157f, 0.650980f);    // Left most
    glBegin(GL_POLYGON);
    glVertex2f(-4.8, 5.5);
    glVertex2f(-6, 5.5);
    glVertex2f(-10, 8);
    glVertex2f(-10, 10);
    glVertex2f(-7.7, 10);
    glEnd();

    glColor3f(1.0f, 0.639216f, 0.490196f);
    glLineWidth(12.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.8, 5.5);
    glVertex2f(-4.8, 6);
    glVertex2f(-7.22, 10);
    glVertex2f(-7.65, 10);
    glEnd();


    glColor3f(0.564706f, 0.168627f, 0.152941f);    // middle right
    glBegin(GL_POLYGON);
    glVertex2f(5.5, 10);
    glVertex2f(3.2, 5.7);
    glVertex2f(2.7, 5.7);
    glVertex2f(4.5, 10);
    glEnd();

    glColor3f(0.380392f, 0.078431f, 0.062745f);
    glLineWidth(12.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4.5, 10);
    glVertex2f(2.7, 5.7);
    glVertex2f(2.7, 6);
    glVertex2f(4.2, 10);
    glEnd();

    glColor3f(0.564706f, 0.168627f, 0.152941f);    // middle left
    glBegin(GL_POLYGON);
    glVertex2f(-5.5, 10);
    glVertex2f(-3.2, 5.7);
    glVertex2f(-2.7, 5.7);
    glVertex2f(-4.5, 10);
    glEnd();

    glColor3f(0.380392f, 0.078431f, 0.062745f);
    glLineWidth(12.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5, 10);
    glVertex2f(-2.7, 5.7);
    glVertex2f(-2.7, 6);
    glVertex2f(-4.2, 10);
    glEnd();


    // Floor
    glColor3f(0.4f, 0.090196f, 0.058823f);
    glBegin(GL_POLYGON);
    glVertex2f(-6, -5);
    glVertex2f(6, -5);
    glVertex2f(15, -14);
    glVertex2f(-15, -14);
    glEnd();



    //Front Wall right Beam
    glColor3f(1.0f, 0.79216f, 0.62745f);
    glBegin(GL_POLYGON);
    glVertex2f(4.8, 4.5);
    glVertex2f(4.2, 4.1);
    glVertex2f(4.2, -4.7);
    glVertex2f(4.8, -5);
    glEnd();


    //front wall upper beam
    glColor3f(0.98039f, 0.62353f, 0.54118f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.8, 4.5);
    glVertex2f(-4.2, 4.1);
    glVertex2f(4.2, 4.1);
    glVertex2f(4.8, 4.5);
    glEnd();


    //Kitchen front wall
    glColor3f(0.988235f, 0.909804f, 0.686275f);
    glBegin(GL_POLYGON);
    glVertex2f(3, 3);
    glVertex2f(-3, 3);
    glVertex2f(-3, -3);
    glVertex2f(3, -3);
    glEnd();


    // Kitchen Floor
    glColor3f(0.678431f, 0.203922f, 0.172549f);
    glBegin(GL_POLYGON);
    glVertex2f(-3.2, -3);
    glVertex2f(0.07, -3);
    glVertex2f(0.2, -5);
    glVertex2f(-4.8, -5);
    glVertex2f(-4.2, -4.7);
    glVertex2f(-4.2, -3.9);
    glEnd();


    //Front Wall Left Beam
    glColor3f(1.0f, 0.79216f, 0.62745f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.8, 4.5);
    glVertex2f(-4.2, 4.1);
    glVertex2f(-4.2, -4.7);
    glVertex2f(-4.8, -5);
    glEnd();


    // kitchen left wall
    glColor3f(0.996078f, 0.945098f, 0.764706f);
    glBegin(GL_POLYGON);
    glVertex2f(-3.2, -3);
    glVertex2f(-3.2, 2.05);
    glVertex2f(-3, 2.05);
    glVertex2f(-3, 3);
    glVertex2f(-4.2, 4.1);
    glVertex2f(-4.2, -3.9);
    glEnd();


    //Kitchen Ceiling
    glColor3f(0.996078f, 0.807843f, 0.529412f);
    glBegin(GL_POLYGON);
    glVertex2f(-3, 3);
    glVertex2f(-4.2, 4.1);
    glVertex2f(4.2, 4.1);
    glVertex2f(3, 3);
    glEnd();


    // Fridge Front
    glColor3f(0.690196f, 0.776471f, 0.752941f);
    glBegin(GL_POLYGON);
    glVertex2f(-3.2, -3);
    glVertex2f(-3.2, 2.05);
    glVertex2f(-2, 2.05);
    glVertex2f(-2, -3);
    glEnd();

    //fridge partition
    glColor3f(0.607843f, 0.639216f, 0.607843f);
    glLineWidth(0.8f);
    glBegin(GL_LINES);
    glVertex2f(-3.09, 0);
    glVertex2f(-2.12, 0);
    glEnd();

    //Fridge lines
    glColor3f(0.686275f, 0.615686f, 0.67451f);
    glLineWidth(3.0f);  // setting width of lines
    glBegin(GL_LINES);
    glVertex2f(-3, 1.4);
    glVertex2f(-3, 0.6);
    glEnd();

    glColor3f(0.686275f, 0.615686f, 0.67451f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(-3, -0.6);
    glVertex2f(-3, -2);
    glEnd();

    //fridge right side
    glColor3f(0.67451f, 0.690196f, 0.713725f);
    glBegin(GL_POLYGON);
    glVertex2f(-2, 2.05);
    glVertex2f(-2, -1);
    glVertex2f(-1.85, -1);
    glVertex2f(-1.85, 1.92);
    glEnd();

    
    // Oven
    glColor3f(0.913725f, 0.854902f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(-2, -3);
    glVertex2f(-2, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, -3);
    glEnd();

    // Oven Glass
    glColor3f(0.690196f, 0.776471f, 0.752941f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.85, -2.5);
    glVertex2f(-1.85, -1.4);
    glVertex2f(-1.2, -1.4);
    glVertex2f(-1.2, -2.5);
    glEnd();


    //Oven Upper
    glColor3f(0.882353f, 0.74902f, 0.666667f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(-1, -1);
    glVertex2f(-1.9, -1);
    glEnd();


    //Oven Handle    
    glColor3f(0.886275f, 0.462745f, 0.282353f);
    glBegin(GL_LINES);
    glVertex2f(-1.9, -1.4);
    glVertex2f(-1.15, -1.4);
    glEnd();


    // kitchen Right wall
    glColor3f(0.996078f, 0.945098f, 0.764706f);
    glBegin(GL_POLYGON);
    glVertex2f(3, -3);
    glVertex2f(4.2, -4.2);
    glVertex2f(4.2, 4.1);
    glVertex2f(3, 3);
    glEnd();


    // lower shelf
    glColor3f(0.988235f, 0.713725f, 0.231373f);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -1.1);
    glVertex2f(-1, -3);
    glVertex2f(0.08, -3);
    glVertex2f(0.08, -1.1);
    glEnd();

    glColor3f(0.886275f, 0.462745f, 0.282353f);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(-1, -1.08);
    glVertex2f(3.1, -1.08);
    glEnd();


    //counter
    glColor3f(0.545098f, 0.141176f, 0.141176f);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, -5);
    glVertex2f(4.7, -5);
    glVertex2f(4.7, -1.2);
    glVertex2f(0.2, -1.2);
    glEnd();


    glColor3f(0.403922f, 0.058824f, 0.086275f);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, -5);
    glVertex2f(0.07, -3.5);
    glVertex2f(0.07, -1.2);
    glVertex2f(0.2, -1.2);
    glEnd();

    
    glColor3f(0.737255f, 0.219608f, 0.12549f);
    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glVertex2f(4.8, -1.2);
    glVertex2f(0.2, -1.2);
    glEnd();


    glColor3f(0.737255f * 0.8f, 0.219608f * 0.8f, 0.12549f * 0.8f);
    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glVertex2f(0.2, -1.2);
    glVertex2f(0, -1.2);
    glEnd();

    //Shelf
    glColor3f(0.988235f, 0.713725f, 0.231373f);
    glBegin(GL_POLYGON);
    glVertex2f(-1, 1.1);
    glVertex2f(-1, 3.15);
    glVertex2f(3.2, 3.15);
    glVertex2f(3.2, 1.1);
    glEnd();


    // Center shelf
    glColor3f(0.909804f, 0.533333f, 0.309804f);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 1.1);
    glVertex2f(0.3, 3.15);
    glVertex2f(1.9, 3.15);
    glVertex2f(1.9, 1.1);
    glEnd();

    glColor3f(1.0f, 0.670588f, 0.231373f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(0.4, 1.8);
    glVertex2f(1.8, 1.8);
    glVertex2f(0.4, 2.4);
    glVertex2f(1.8, 2.4);
    glEnd();

    glColor3f(0.921569f, 0.603922f, 0.301961f);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(-1, 1.1);
    glVertex2f(3.2, 1.1);
    glEnd();

    glColor3f(0.733333f, 0.615686f, 0.462745f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(1.1, -0.2);
    glVertex2f(2.7, -0.2);
    glEnd();

    glColor3f(0.992157f, 0.768627f, 0.568627f);
    glBegin(GL_POLYGON);          
    glVertex2f(-1, 1.04);
    glVertex2f(3.2, 1.04);
    glVertex2f(3, 0.8);
    glVertex2f(-0.8, 0.8);
    glEnd();


    //Floor Dec
    glColor3f(0.619608f, 0.200000f, 0.231373f);   // lower
    glBegin(GL_POLYGON);
    glVertex2f(-4.8, -5.2);
    glVertex2f(-7.7, -9.4);
    glVertex2f(7.7, -9.4);
    glVertex2f(4.8, -5.2);
    glEnd();

    glColor3f(0.996078f, 0.603922f, 0.490196f);  //  upper
    glBegin(GL_POLYGON);
    glVertex2f(-4.75, -5.35);
    glVertex2f(-7.2, -9.1);
    glVertex2f(7.2, -9.1);
    glVertex2f(4.75, -5.35);
    glEnd();


    //table
    glColor3f(0.858824f, 0.223529f, 0.176471f);   // lower
    glBegin(GL_POLYGON);
    glVertex2f(-1.85, -4.25);
    glVertex2f(1.85, -4.25);
    glVertex2f(2.55, -5.45);
    glVertex2f(-2.55, -5.45);
    glEnd();


    glColor3f(0.988235f, 0.658824f, 0.525490f);   // upper
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, -4.3);
    glVertex2f(1.8, -4.3);
    glVertex2f(2.35, -5.3);
    glVertex2f(-2.35, -5.3);
    glEnd();

    glColor3f(0.521569f, 0.050980f, 0.047059f);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glVertex2f(2.54, -5.55);
    glVertex2f(-2.54, -5.55);
    glEnd();


    //table stand
    glColor3f(0.286275f, 0.027451f, 0.098039f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, -5.6);
    glVertex2f(-1.8, -6);
    glVertex2f(-2.25, -7.1);
    glVertex2f(-2.25, -5.6);
    glEnd();


    glColor3f(0.286275f, 0.027451f, 0.098039f);
    glBegin(GL_POLYGON);
    glVertex2f(1.8, -5.6);
    glVertex2f(1.8, -6);
    glVertex2f(2.25, -7.1);
    glVertex2f(2.25, -5.6);
    glEnd();


    glColor3f(0.521569f, 0.050980f, 0.047059f);
    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glVertex2f(-2.31, -7.1);
    glVertex2f(-2.31, -5.59);
    glEnd();


    glColor3f(0.521569f, 0.050980f, 0.047059f);
    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glVertex2f(2.31, -7.1);
    glVertex2f(2.31, -5.59);
    glEnd();

    glFlush();  // it helps to display window.
}