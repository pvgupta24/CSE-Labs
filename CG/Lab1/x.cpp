#include <GL/freeglut.h>
#include <GL/gl.h>
#include <unistd.h>

float a[2] = {  0.0f,  0.70f };
float b[2] = { -0.3f, -0.50f };
float c[2] = {  0.5f, -0.55f };
float m[2] = {  0.0f,  0.00f };

void midpoint(float p[], float q[], float* k) {
  for (int i = 0; i < 2; i++)
    k[i] = (p[i] + q[i]) / 2;
}

void chaos() {
  glPointSize(1.0);
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);

  for(int i = 0; i < 100000; i++) {
    int num = (rand() % 6) + 1;
    if (num < 3)
      midpoint(m, a, m);
    else if (num < 5)
      midpoint(m, b, m);
    else
      midpoint(m, c, m);

    glBegin(GL_POINTS);
      glVertex2f(m[0], m[1]);
    glEnd();
    glFlush();
  }
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - Creating a triangle");
  glutDisplayFunc(chaos);
  glutMainLoop();
  return 0;
}