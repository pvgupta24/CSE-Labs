#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <bits/stdc++.h>

const double PI = 3.141592654;

int frameNumber = 0;

int season = 2;

void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void drawSolidSector(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void drawWheel() {
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);
	// glRotatef(frameNumber*20,0,0,1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15));
	}
	glEnd();
}

void drawCar() {
	glPushMatrix();
		glTranslatef(-1.5f, -0.1f, 0);
		glScalef(0.8f,0.8f,1);
		drawWheel();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.5f, -0.1f, 0);
		glScalef(0.8f,0.8f,1);
		drawWheel();
	glPopMatrix();

	glColor3f(0.2f,0.2f,1);
	const float car_x = 2.8;
	glBegin(GL_POLYGON);
		glVertex2f(-car_x,0);
		glVertex2f(car_x,0);
		glVertex2f(car_x,2);
		glVertex2f(-car_x,2);
	glEnd();

	glPushMatrix();
		glTranslatef(0, 2.0f, 0);
		glScalef(1.0f,0.8f,1);
		drawDisk(1.8);
	glPopMatrix();
}

void drawHouse(){

	glColor3f(1.0, 0.6, 0);
	const float x = 2, y=4;
	glBegin(GL_POLYGON);
		glVertex2f(-x,0);
		glVertex2f(x,0);
		glVertex2f(x,y);
		glVertex2f(-x,y);
	glEnd();

	glColor3f(0.8, 0, 0.4);
	glBegin(GL_POLYGON);
		glVertex2f(-x/3,0);
		glVertex2f(x/3,0);
		glVertex2f(x/3,y*0.6);
		glVertex2f(-x/3,y*0.6);
	glEnd();

	glColor3f(0.8, 0, 0.4);
	glBegin(GL_POLYGON);
		glVertex2f(0,y*1.5);
		glVertex2f(x,y);
		glVertex2f(-x,y);
	glEnd();

}
void drawSun() {
	int i;

	if(season == 0)
		glColor3f(1,1,0);
	else
		glColor3f(0.94f, 0.76f, 0.60f);
	if(season == 0)
		for (i = 0; i < 13; i++) { 
			glRotatef( 360 / 13, 0, 0, 1 ); 
			glBegin(GL_LINES);
			glVertex2f(0, 0);
			glVertex2f(0.75f, 0);
			glEnd();
		}
	drawDisk(0.5);
	glColor3f(0,0,0);
}

void drawWindmill() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);  // 3rotations for blade
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

void drawRain(){
	srand(time(0));

    glLineWidth(3);
	int num = rand() % 30 + 20;
	// num =1000;
    while(num--) {
        double x1, x2, y1, y2;
        x1 = (rand() % 100) / 50.0 - 1.0;
        y1 = (rand() % 100) / 50.0 - 1.0;
        x2 = x1 - ((rand() % 100) / 10000.0 + 0.09);
        y2 = y1 - ((rand() % 100) / 10000.0 + 0.09);
        glBegin(GL_LINES);
            glColor3f(147.0/255, 230.0/255, 255.0/255);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        glEnd();
    }
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();

	const float hill_base = -1;//-0.5;

	// Hills
	glColor3f(0, 0.6f, 0.3f);
	glBegin(GL_POLYGON);
		glVertex2f(-3,hill_base);
		glVertex2f(1.5f,1.65f);
		glVertex2f(5,hill_base);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(-3,hill_base);
		glVertex2f(3,2.1f);
		glVertex2f(7,hill_base);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(0,hill_base);
		glVertex2f(6,1.2f);
		glVertex2f(20,hill_base);
	glEnd();

	/* Draw a bluish-gray rectangle to represent the road. */

	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
		glVertex2f(0,-0.4f);
		glVertex2f(7,-0.4f);
		glVertex2f(7,0.4f);
		glVertex2f(0,0.4f);
	glEnd();

	/* Road white line */
	glLineWidth(6);  // Set the line width to be 6 pixels.
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(7,0);
	glEnd();
	glLineWidth(1);  // Reset the line width to be 1 pixel.

	glPushMatrix();
	// New reference point to draw sun
	glTranslated(5.8,3,0);
	drawSun();
	glPopMatrix();


	glPushMatrix();
	glTranslated(0.75,1,0);
	glScaled(0.6,0.6,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
		glTranslated(6,0,0);
		glScaled(0.3,0.3,1);
		drawCar();
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(0.8,-0.4,0);
		glScaled(0.4,0.4,1);
		drawHouse();
	glPopMatrix();

	if(season == 2){
		glTranslated(4, 2,0);
		glScaled(3,3,1);
		drawRain();
	}
	glutSwapBuffers();
	// display();

}  // end display

/*
 * This method is called from main() to initialize OpenGL.
 */
void init() {
	if(season == 0)
		glClearColor(0.5f, 0.5f, 1, 1);
	else if(season ==1)
		glClearColor(0.0f, 0.0f, 0, 0.5);
	else
		glClearColor(0.172, 0.18, 0.4, 0);
	// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1400,1000);
    glutInitWindowPosition(500,100);  
    glutCreateWindow("OpenGL Scenary"); 

    init();

    glutDisplayFunc(display);

    glutMainLoop(); 
    return 0;
}    
