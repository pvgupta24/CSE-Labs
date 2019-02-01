#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

#define PI 3.1415926
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glEnable(GL_PROGRAM_POINT_SIZE);

}
 GLdouble size=0.5;

/* Window repaint event handler */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
   glColor3f(0.827, 0.827, 0.827);    
   glutSolidTeapot(size);
   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(500, 500);   // Set the window's initial width & height
   glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
   glutCreateWindow("Cup");  // Create window with the given title   
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}