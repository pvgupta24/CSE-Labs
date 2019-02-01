#include <GL/glut.h>
#include<stdio.h>

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glEnable(GL_PROGRAM_POINT_SIZE);
    
}
 
/* Window repaint event handler */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
   glPointSize(10.0);             //and this one

   glBegin(GL_LINES);
      glColor3f(1, 1, 1);
      glVertex2f(0.0f, 0.0f);

      glColor3f(0, 0, 1);
      glVertex2f(0.0f, 0.3f);
   glEnd();

   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}