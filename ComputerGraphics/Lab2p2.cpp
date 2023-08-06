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


void getScreenResolution() {              // This will provide our whole screen resolution from the system
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


    //LED
    glColor3f(0, 0, 0);
    glLineWidth(5.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.55, 3.1);
    glVertex2f(-2.55, 3.1);
    glVertex2f(-2.55, -2.09);
    glVertex2f(2.55, -2.09);
    glVertex2f(2.55, 3.1);
    glEnd();

    //LED frame
    glColor3f(0.231373f, 0.192157f, 0.196078f);
    glBegin(GL_POLYGON);  
    glVertex2f(2.5, 3);
    glVertex2f(-2.5, 3);
    glVertex2f(-2.5, -2);
    glVertex2f(2.5, -2);
    glEnd();  


    //LED effect1
    glColor3f(0.882353f, 0.886275f, 0.894118f);
    glBegin(GL_POLYGON);  
    glVertex2f(0.4, 3);
    glVertex2f(0.8, 3);
    glVertex2f(-1, -2);
    glVertex2f(-1.8, -2);
    glEnd();  

    //LED effect1
    glColor3f(0.882353f, 0.886275f, 0.894118f);
    glBegin(GL_POLYGON);  
    glVertex2f(-1.7, 3);
    glVertex2f(-1.3, 3);
    glVertex2f(-2.5, 0);
    glVertex2f(-2.5, 1);
    glEnd();
    
    // left side wall
    glColor3f(1.0f, 0.878431f, 0.717647f);
    glBegin(GL_POLYGON);
    glVertex2f(-6.0001, 6);
    glVertex2f(-10, 8);
    glVertex2f(-15, -14);
    glVertex2f(-6.0001, -5);
    glEnd();


    //right side wall
    glColor3f(1.0f, 0.878431f, 0.717647f);
    glBegin(GL_POLYGON);
    glVertex2f(6.0001, 6);
    glVertex2f(10, 8);
    glVertex2f(15, -14);
    glVertex2f(6.0001, -5);
    glEnd();

    //window right wall
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
    glColor3f(0.858824f, 0.223529f, 0.176471f);   // top (lower layer)
    glBegin(GL_POLYGON);
    glVertex2f(-1.85, -4.25);
    glVertex2f(1.85, -4.25);
    glVertex2f(2.55, -5.45);
    glVertex2f(-2.55, -5.45);
    glEnd();

    glColor3f(0.988235f, 0.658824f, 0.525490f);   // top most layer
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, -4.3);
    glVertex2f(1.8, -4.3);
    glVertex2f(2.35, -5.3);
    glVertex2f(-2.35, -5.3);
    glEnd();

    glColor3f(0.521569f, 0.050980f, 0.047059f); //front line of table 
    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glVertex2f(2.54, -5.55);
    glVertex2f(-2.54, -5.55);
    glEnd();


    //table stand left
    glColor3f(0.286275f, 0.027451f, 0.098039f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.8, -5.6);
    glVertex2f(-1.8, -6);
    glVertex2f(-2.25, -7.1);
    glVertex2f(-2.25, -5.6);
    glEnd();

    glColor3f(0.521569f, 0.050980f, 0.047059f);
    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glVertex2f(-2.31, -7.1);
    glVertex2f(-2.31, -5.59);
    glEnd();


    //table stand right
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
    glVertex2f(2.31, -7.1);
    glVertex2f(2.31, -5.59);
    glEnd();

    glFlush();  // it helps to display window.
}
