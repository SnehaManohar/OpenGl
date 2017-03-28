/*
 * OGL02Animation.cpp: 3D Shapes with animation
 */
#include <windows.h>  // for MS Windows
#include<iostream>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
using namespace std;
/* Global variables */
GLfloat angle;
GLfloat angler=0.0;
GLfloat  axii[3]={0.0f,0.0f,0.0f};
char title[] = "Rotating Cube";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 1;        // refresh interval in milliseconds [NEW]
 
void MouseHandler(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{axii[0]=1.0;axii[1]=0.0;axii[2]=0.0;}
	else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		{axii[0]=0.0;axii[1]=1.0;axii[2]=0.0;}
	else if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
		 {axii[0]=0.0;axii[1]=0.0;axii[2]=1.0;}
}
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);     
 
   
   glLoadIdentity();                 
   glTranslatef(1.0f, 0.0f, -7.0f);  
   glRotatef(angle, axii[0], axii[1],axii[2]); 
 
   glBegin(GL_QUADS);               
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f( 1.0f, 1.0f, -1.0f);
	  glColor3f(0.0f, 1.0f, 1.0f); 
      glVertex3f(-1.0f, 1.0f, -1.0f);
	   glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
	  glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f( 1.0f, -1.0f,  1.0f);
	  glColor3f(1.0f, 1.0f, 0.0f);   
      glVertex3f(-1.0f, -1.0f,  1.0f);
	  glColor3f(1.0f, 0.0f, 1.0f);   
      glVertex3f(-1.0f, -1.0f, -1.0f);
	  glColor3f(0.0f, 1.0f, 1.0f);   
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
    
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f( 1.0f,  1.0f, 1.0f);
	    glColor3f(0.0f, 1.0f, 1.0f); 
      glVertex3f(-1.0f,  1.0f, 1.0f);
	   glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
	   glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      
      glColor3f(1.0f, 1.0f, 0.0f); 
      glVertex3f( 1.0f, -1.0f, -1.0f);
	   glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
	   glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
	   glColor3f(0.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      
      glColor3f(0.0f, 1.0f, 1.0f);     
      glVertex3f(-1.0f,  1.0f,  1.0f);
	   glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
	   glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
	   glColor3f(0.0f, 1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
 
      
      glColor3f(1.0f, 0.0f, 1.0f);    
      glVertex3f(1.0f,  1.0f, -1.0f);
	   glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
	   glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
	   glColor3f(0.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube
 

 Sleep(300);
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
 
   angle-=angler;
 
}
 
/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);// Initialize GLUT
   char axis;// x,y,z
   
   cout<<"Enter angle resp.\n";
  cin>>angler;
 
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);  
      // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);  
   glutMouseFunc(MouseHandler);// Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutTimerFunc(0, timer, 0);
   // First timer call immediately [NEW]
   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;
}