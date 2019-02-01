#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
 
/* Window repaint event handler */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glColor3f(0.0, 0, 1.0);
    glBegin(GL_LINE_LOOP); 
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.4f, 0.f);//left

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, -0.8f);//bottom
        

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.8f); //top

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.4f, 0.0f); //right


        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, -0.8f);//bottom

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.4f, 0.0f); //right

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.4f, 0.f);//left        

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.8f); //top
    glEnd();

    glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("KITE");  // Create window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}