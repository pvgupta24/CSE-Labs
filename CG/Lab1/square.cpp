#include <GL/glut.h>
 
/* Window repaint event handler */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 
   // Draw a 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(0.0f, 0.0f, 1.0f); // RGB Values for the QUAD
      glVertex2f(-0.5f, -0.5f);
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();
 
   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT with command line options
   glutCreateWindow("OpenGL Hello World"); // Create a window with the given title
   glutInitWindowSize(500, 500);   // Set the window's initial width & height in pixels
   glutInitWindowPosition(200, 200); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the GLUT event-processing loop
   return 0;
}