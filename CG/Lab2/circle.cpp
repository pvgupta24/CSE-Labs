#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

#define PI 3.1415926
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
 
/* Window repaint event handler */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    float cx = -0.4, cy = 0.4, r = 0.2;
   
    const int NUM_SEGMENTS = 5e3;
    glColor3f(0.0, 0, 1.0);
    glBegin(GL_LINE_LOOP); 
        for(int i = 0; i < NUM_SEGMENTS; i++) 
        { 
            float theta = 2.0f * PI * float(i) / float(NUM_SEGMENTS);//get the current angle 

            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            
            glVertex2f(x + cx, y + cy);

        } 
    glEnd();

    cx = 0.4;
    glBegin(GL_LINE_LOOP); 
        for(int i = 0; i < NUM_SEGMENTS; i++) 
        { 
            float theta = 2.0f * PI * float(i) / float(NUM_SEGMENTS);//get the current angle 

            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            
            glVertex2f(x + cx, y + cy);

        } 
    glEnd();

    glColor3f(0, 1.0, 0);
    glBegin(GL_LINES);
        glVertex2f(0.0f, -0.1f);
        glVertex2f(0.0f, 0.3f);
    glEnd();

    cx = 0, cy = 0, r=0.5;
    glColor3f(1.0, 0, 0.0);
    glBegin(GL_LINE_LOOP); 
        for(int i = 225; i < 315; i++) 
        { 
            float theta = PI * float(i) / float(180);//get the current angle 

            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            
            glVertex2f(x + cx, y + cy);

        } 
    glEnd();


    cx = 0, cy = 0, r=0.9;
    glBegin(GL_LINE_LOOP); 
        for(int i = 0; i < NUM_SEGMENTS; i++) 
        { 
            float theta = 2.0f * PI * float(i) / float(NUM_SEGMENTS);//get the current angle 

            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            
            glVertex2f(x + cx, y + cy);

        } 
    glEnd();
    glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Circle");  // Create window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}