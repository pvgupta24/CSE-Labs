#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415926
#define BLACK true
#define WHITE false


/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glEnable(GL_PROGRAM_POINT_SIZE);
}

const float floatFactor = 0.2;


/* Window repaint event handler */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    bool curr_color = BLACK;

    for(int x=-4; x<4; ++x){
        for(int y=-4; y<4; ++y){
            if (curr_color == BLACK)
                glColor3f(0.0f, 0.0f, 1.0f);
            else
                glColor3f(1.0f, 1.0f, 1.0f);
            curr_color = !curr_color;

            glBegin(GL_POLYGON);
                glVertex2f(x*floatFactor, y*floatFactor);
                glVertex2f((1+x)*floatFactor, y*floatFactor);
                glVertex2f((1+x)*floatFactor, (1+y)*floatFactor);
                glVertex2f(x*floatFactor, (1+y)*floatFactor);
            glEnd();
        }
        curr_color = !curr_color;
    }

    glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
   glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
   glutCreateWindow("Chess Board");  // Create window with the given title   
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}