#include<unistd.h>
#include <GL/gl.h>
#include <GL/glut.h>
 void display(void)
{ /* clear all pixels */ glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */
 float c=0.0;
	  while(c<10.0){
		  sleep(0.01);
		  c=c+0.0001;
		     glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.0, 0.0, 0.0);
glVertex3f (1.0, 0.0, 0.0);
glVertex3f (1.0, 0.25, 0.0);
glVertex3f (0.0, 0.25, 0.0);
glEnd();
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (0.1, 0.110, 0.0);
glVertex3f (0.2, 0.110, 0.0);
glVertex3f (0.23, 0.140, 0.0);
glVertex3f (0.13, 0.140, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.3, 0.110, 0.0);
glVertex3f (0.4, 0.110, 0.0);
glVertex3f (0.43, 0.140, 0.0);
glVertex3f (0.33, 0.140, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.5, 0.110, 0.0);
glVertex3f (0.6, 0.110, 0.0);
glVertex3f (0.63, 0.140, 0.0);
glVertex3f (0.53, 0.140, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.7, 0.110, 0.0);
glVertex3f (0.8, 0.110, 0.0);
glVertex3f (0.83, 0.140, 0.0);
glVertex3f (0.73, 0.140, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.40+c, 0.55+c, 0.0);
glVertex3f (0.70+c, 0.55+c, 0.0);
glVertex3f (0.70+c, 0.65+c, 0.0);
glVertex3f (0.40+c, 0.65+c, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.70+c, 0.60+c, 0.0);
glVertex3f (0.74+c, 0.60+c, 0.0);
glVertex3f (0.735+c, 0.62+c, 0.0);
glVertex3f (0.70+c, 0.65+c, 0.0);
glEnd();
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.40+c, 0.65+c, 0.0);
glVertex3f (0.40+c, 0.75+c, 0.0);
glVertex3f (0.42+c, 0.75+c, 0.0);
glVertex3f (0.50+c, 0.65+c, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.57+c, 0.65+c, 0.0);
glVertex3f (0.50+c, 0.70+c, 0.0);
glVertex3f (0.55+c, 0.70+c, 0.0);
glVertex3f (0.63+c, 0.65+c, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.57+c, 0.58+c, 0.0);
glVertex3f (0.50+c, 0.53+c, 0.0);
glVertex3f (0.55+c, 0.53+c, 0.0);
glVertex3f (0.63+c, 0.58+c, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.70+c, 0.55+c, 0.0);
glVertex3f (0.735+c, 0.58+c, 0.0);
glVertex3f (0.74+c, 0.60+c, 0.0);
glVertex3f (0.70+c, 0.60+c, 0.0);
glEnd();

glFlush (); 
 }
 }
void init (void) {
 /* select clearing (background) color */
glClearColor (0.0, 0.0, 1.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); }
/* * Declare initial window size, position, and display mode * (single buffer and RGBA). Open window with "hello" * in its title bar. Call initialization routines. * Register callback function to display graphics. * Enter main loop and process events. */

int  main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (650,450);
glutInitWindowPosition (500, 100);
glutCreateWindow ("movingplane");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
