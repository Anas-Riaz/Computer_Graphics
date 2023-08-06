#include <GL/glut.h>

// Define the control points for the Bézier curve
float controlPoints[4][3] = {
    {-1.0, 0.0, 0.0},
    {-0.5, 1.0, 0.0},
    {0.5, -1.0, 0.0},
    {1.0, 0.0, 0.0}
};

// Function to calculate points on the Bézier curve
void calculateBezierPoint(float t, float* point) {
    float u = 1.0 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    for (int i = 0; i < 3; i++) {
        point[i] = uuu * controlPoints[0][i] +
                   3.0 * uu * t * controlPoints[1][i] +
                   3.0 * u * tt * controlPoints[2][i] +
                   ttt * controlPoints[3][i];
    }
}

// Function to render the curved surface
void renderCurvedSurface() {
    glBegin(GL_LINE_STRIP);

    int numSegments = 100; // Adjust the number of segments for smoothness
    for (int i = 0; i <= numSegments; i++) {
        float t = static_cast<float>(i) / numSegments;
        float point[3];
        calculateBezierPoint(t, point);
        glVertex3fv(point);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0); // Move the surface away from the camera

    renderCurvedSurface();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, static_cast<float>(width) / static_cast<float>(height), 1.0, 100.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Curved Surface with OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
