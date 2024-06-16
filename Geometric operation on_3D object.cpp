#include<GL/glut.h>
#include<iostream>
int width = 800;
int height = 600;
GLfloat rotationX = 0.0f;
GLfloat rotationY =0.0f;
GLfloat scale = 1.0f;


void drawCube()
{
glBegin(GL_QUADS);

//FRONT FACE

glColor3f(1.0f,0.0f,0.0f);
glVertex3f(-0.5f,-0.5f,0.5f);
glVertex3f(0.5f,-0.5f,0.5f);
glVertex3f(0.5f,0.5f,0.5f);
glVertex3f(-0.5f,0.5f,0.5f);

//BACK FACE

glColor3f(0.0f,1.0f,0.0f);
glVertex3f(-0.5f,-0.5f,-0.5f);
glVertex3f(-0.5f,0.5f,-0.5f);
glVertex3f(0.5f,0.5f,-0.5f);
glVertex3f(0.5f,-0.5f,-0.5f);

//TOP FACE

glColor3f(0.0f,0.0f,0.0f);
glVertex3f(-0.5f,0.5f,-0.5f);
glVertex3f(-0.5f,0.5f,0.5f);
glVertex3f(0.5f,0.5f,0.5f);
glVertex3f(0.5f,0.5f,-0.5f);

//BOTTOM FACE

glColor3f(1.0f,1.0f,0.0f);
glVertex3f(-0.5f,-0.5f,-0.5f);
glVertex3f(0.5f,-0.5f,-0.5f);
glVertex3f(0.5f,-0.5f,0.5f);
glVertex3f(-0.5f,-0.5f,0.5f);

//RIGHT FACE

glColor3f(1.0f,0.0f,1.0f);
glVertex3f(0.5f,-0.5f,-0.5f);
glVertex3f(0.5f,0.5f,-0.5f);
glVertex3f(0.5f,0.5f,0.5f);
glVertex3f(0.5f,-0.5f,0.5f);

//LEFT FACE

glColor3f(0.0f,1.0f,1.0f);
glVertex3f(-0.5f,-0.5f,-0.5f);
glVertex3f(-0.5f,-0.5f,0.5f);
glVertex3f(-0.5f,0.5f,0.5f);
glVertex3f(-0.5f,0.5f,-0.5f);
glEnd();

}
 
 void display()
 {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glTranslatef(0.0f,0.0f,-3.0f);
 glRotatef(rotationX,1.0f,0.0f,0.0f);
 glRotatef(rotationY,0.0f,1.0f,0.0);
 glScalef(scale,scale,scale);
 drawCube();
 glutSwapBuffers();
 }
 
 void keyboard(unsigned char key ,int x, int y)
 {
 switch(key)
 {
 case 'x':
  rotationX  += 5.0f;
  break;
 case'X':
  rotationX -= 5.0f;
  break;
 case'y':
  rotationY +=5.0f;
  break;
  case'Y':
  rotationY -= 0.1f;
  break;
 case '+':
  scale += 0.1f;
  break;
 case'-':
  if(scale>0.1f)
  scale -= 0.1f;
  break;
 case 27:
  exit(0);
  break;
}
glutPostRedisplay();
}
void initializeOpenGL(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
glutInitWindowSize(width,height);
glutCreateWindow("Geometric operations in 3D");
glEnable(GL_DEPTH_TEST);
glClearColor(1.0f,1.0f,1.0f,1.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0f,(float) width/(float)height, 1.0f,100.0f);
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
}
int main (int argc,char** argv)
{
initializeOpenGL(argc,argv);
glutMainLoop();
return 0;
}






