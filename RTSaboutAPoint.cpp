//rotate by 60, scale by factor of 2 along x-axis and factor of 0.5 along y axis wrt the fixed point

#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <GL/gl.h> 
#include <GL/glut.h>
using namespace std;
void rotate(void){ 
glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
//glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();
//glPushMatrix();
glBegin(GL_POLYGON); 
glVertex3f (60, 260, 0.0);
glVertex3f (120, 260, 0.0); 
glVertex3f (90, 320, 0.0); 
 
//glVertex3f (250, 200, 0.0); 
glEnd();
glTranslatef(60,260,0.0);
glRotatef(30,0,0,1);
glTranslatef(-60,-260,0.0);
//glPopMatrix();
}
void scale(void){
glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON); 
glVertex3f (60, 260, 0.0);
glVertex3f (120, 260, 0.0); 
glVertex3f (90, 320, 0.0);  
//glVertex3f (250, 200, 0.0); 
glEnd();
glScaled(2.0,0.5, 1.0);
}
void translate(void){
glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON); 
glVertex3f (60, 260, 0.0); 
glVertex3f (120, 260, 0.0); 
glVertex3f (90, 320, 0.0); 
///glVertex3f (250, 200, 0.0); 
glEnd();
glTranslatef(40,0,0);
}
void display(void) 
{ 
glClearColor (1.0, 1.0, 1.0, 0.0); 
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON); 
glVertex3f (60, 260, 0.0);
glVertex3f (120, 260, 0.0); 
glVertex3f (90, 320, 0.0); 


//glVertex3f (250, 200, 0.0); 
glEnd();
glFlush();    
} 
void keyboard(unsigned char key, int x, int y)
{
	switch(key){
	case 'r':{
		rotate();
		//glClear(GL_COLOR_BUFFER_BIT);
		glutPostRedisplay();
		break;
		}
	 case 't':{
                translate();
                //glClear(GL_COLOR_BUFFER_BIT);
                glutPostRedisplay();
                break;
                }

	 case 's':{
                scale();
                //glClear(GL_COLOR_BUFFER_BIT);
                glutPostRedisplay();
                break;
                }
	default: break;
}
}	
    void init (void) {
     /* select clearing (background) color */ 
    glClearColor (1.0, 1.0, 1.0, 0.0); 
    /* initialize viewing values */ 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(0,650,0,650,0,650); } 
    /* * Declare initial window size, position, and display mode * (single buffer and RGBA). Open window with "hello" * in its title bar. Call initialization routines. * Register callback function to display graphics. * Enter main loop and process events. */ 
    
    int main(int argc, char** argv) {
    srand( time(0) );
    glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (650, 650);
    glutInitWindowPosition (100, 100); 
    glutCreateWindow ("Graph"); 
    init (); 
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    glutPostRedisplay();
    return 0; 
    }
