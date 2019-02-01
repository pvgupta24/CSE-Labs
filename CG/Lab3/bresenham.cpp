#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

#define PI 3.1415926

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glEnable(GL_PROGRAM_POINT_SIZE);

}

// Integral Points/pixels in space
const float floatFactor = 0.1;

void bresenham(int x1, int y1, int x2, int y2) 
{ 
   const float r = 0.02;
   int dy = y2 - y1;
   int dx = x2 - x1;
   int curr_slope = 2 * dy; 
   int error_slope = curr_slope - dx;
   
   glColor3f(0, 0.3, 1);
   for (int x = x1, y = y1; x <= x2; x++) 
   { 
        glBegin(GL_POLYGON); 
        for(int k = 0; k < 360; k++) 
        { 
            float theta = PI * float(k) / float(180);//get the current angle 
            float cx = x*floatFactor, cy = y*floatFactor;

            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            
            glVertex2f(x + cx, y + cy);
        } 
        glEnd();

        error_slope += curr_slope;

        //Choose upper picel 
        if (error_slope >= 0) { 
            y++; 
            error_slope  -= 2 * dx; 
        } 
   } 
} 

/* Window repaint event handler */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    // Axes
    glPointSize(20.0); 
    glColor3f(0.827, 0.827, 0.827);    
    glBegin(GL_LINES);
        glVertex2f(0, 0.9);
        glVertex2f(0, -0.9f);

        glVertex2f(0.9, 0);
        glVertex2f(-0.9f, 0);
    glEnd();

    float r=0.008;
    for(int i=-9; i<10; i+=1){
        for(int j=-9; j<10; j+=1){
            glBegin(GL_POLYGON); 
                for(int k = 0; k < 360; k++) 
                { 
                    float theta = PI * float(k) / float(180);//get the current angle 
                    float cx = i*floatFactor, cy = j*floatFactor;

                    float x = r * cos(theta);//x = rcostheta 
                    float y = r * sin(theta);//y = rsintheta 
                    
                    glVertex2f(x + cx, y + cy);
                } 
            glEnd();
        }
    }


    // Given end points to be divided by 10
    const int endX[] = {-8, 5};
    const int endY[] = {-3, 6};
   
    if(endX[0] < endX[1])
        bresenham(endX[0], endY[0], endX[1], endY[1]);
    else
        bresenham(endX[1], endY[1], endX[0], endY[0]);

    r = 0.02;
    glColor3f(1, 0, 0);    
    for(int i=0; i<2; ++i) {
        glBegin(GL_POLYGON);
        for(int k = 0; k < 360; k++) 
        { 
            float theta = PI * float(k) / float(180);//get the current angle 
            float cx = endX[i]*floatFactor, cy = endY[i]*floatFactor;

            float x = r * cos(theta);//x = rcostheta 
            float y = r * sin(theta);//y = rsintheta 
            
            glVertex2f(x + cx, y + cy);
        } 
        glEnd();
    }
    glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
   glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
   glutCreateWindow("Line algorithm");  // Create window with the given title   
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}