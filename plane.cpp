#include <GL/gl.h>
#include <GL/glut.h>
 void display(void)
{ /* clear all pixels */ glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */
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
glVertex3f (0.40, 0.55, 0.0);
glVertex3f (0.70, 0.55, 0.0);
glVertex3f (0.70, 0.65, 0.0);
glVertex3f (0.40, 0.65, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.70, 0.60, 0.0);
glVertex3f (0.74, 0.60, 0.0);
glVertex3f (0.735, 0.62, 0.0);
glVertex3f (0.70, 0.65, 0.0);
glEnd();
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.40, 0.65, 0.0);
glVertex3f (0.40, 0.75, 0.0);
glVertex3f (0.42, 0.75, 0.0);
glVertex3f (0.50, 0.65, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.57, 0.65, 0.0);
glVertex3f (0.50, 0.70, 0.0);
glVertex3f (0.55, 0.70, 0.0);
glVertex3f (0.63, 0.65, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.57, 0.58, 0.0);
glVertex3f (0.50, 0.53, 0.0);
glVertex3f (0.55, 0.53, 0.0);
glVertex3f (0.63, 0.58, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.70, 0.55, 0.0);
glVertex3f (0.735, 0.58, 0.0);
glVertex3f (0.74, 0.60, 0.0);
glVertex3f (0.70, 0.60, 0.0);
glEnd();
glLineWidth(0.5);
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex3f(0.70, 0.55, 0.0);
glVertex3f(0.70, 0.65, 0.0);
glEnd();
glLineWidth(0.5);
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex3f(0.70, 0.60, 0.0);
glVertex3f(0.741, 0.60, 0.0);
glEnd();
glFlush ();
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
glutInitWindowSize (450,250);
glutInitWindowPosition (500, 100);
glutCreateWindow ("plane");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
