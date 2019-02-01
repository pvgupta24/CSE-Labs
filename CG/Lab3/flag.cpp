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

   const float r=0.1, cx=0, cy=0;
   const float l=0.9, h = 2*r, hl=l/2;
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.6f, 0.2f); // RGB Values for the QUAD
      glVertex2f(-hl, r);
      glVertex2f( hl, r);
      glVertex2f( hl,  3*r);
      glVertex2f(-hl,  3*r);
   glEnd();
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 1.0f); // RGB Values for the QUAD
      glVertex2f(-hl, -r);
      glVertex2f( hl, -r);
      glVertex2f( hl,  r);
      glVertex2f(-hl,  r);
   glEnd();
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(0.0f, 1.0f, 0.0f); // RGB Values for the QUAD
      glVertex2f(-hl, -r);
      glVertex2f( hl, -r);
      glVertex2f( hl,  -3*r);
      glVertex2f(-hl,  -3*r);
   glEnd();

   glColor3f(0.0, 0, 1.0);
   glBegin(GL_LINE_LOOP); 
      for(int i = 0; i < 360; i+=1) 
      { 
         float theta = PI * float(i) / float(180);//get the current angle 
         float x = r * cos(theta);//x = rcostheta 
         float y = r * sin(theta);//y = rsintheta 
         glVertex2f(x + cx, y + cy);

      } 
   glEnd();

      for(int i = 0; i < 360; i+=15) 
      {  
         glBegin(GL_LINES);
            glVertex2f(0.0f, 0.0f);
            float theta = PI * float(i) / float(180);//get the current angle 
            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            glVertex2f(x + cx, y + cy);
         glEnd();
      }

   glPointSize(10.0); 
   glColor3f(0.827, 0.827, 0.827);    
   glBegin(GL_LINES);
      glVertex2f(-hl, 3*r+0.05);
      glVertex2f(-hl, -0.8f);
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