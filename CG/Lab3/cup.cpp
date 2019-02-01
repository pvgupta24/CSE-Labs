#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

#define PI 3.1415926
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glEnable(GL_PROGRAM_POINT_SIZE);

}
 
/* Window repaint event handler */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

   float  a=0.1, b=0.3, cx=0.4, cy=0;
   glPointSize(5);
    glColor3f(1, 0.8, 0.827);    
    glBegin(GL_POINTS);
    for(int i = 0; i >= -360; i--) 
    {  
        // glVertex2f(0.0f, 0.0f);
        float theta = PI * float(i) / float(180);//get the current angle 
        float x = a * cos(theta);//x = rcostheta 
        float y = b * sin(theta);//y = rsintheta 
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    a=0.4, b=0.75, cx=0, cy=0;
   glColor3f(0.827, 0.827, 0.827);    
    glBegin(GL_POLYGON);
    for(int i = 30; i >= -210; i--) 
    {  
        // glVertex2f(0.0f, 0.0f);
        float theta = PI * float(i) / float(180);//get the current angle 
        float x = a * cos(theta);//x = rcostheta 
        float y = b * sin(theta);//y = rsintheta 
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(500, 500);   // Set the window's initial width & height
   glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
   glutCreateWindow("Indian Flag");  // Create window with the given title   
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}