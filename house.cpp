#include <GL/gl.h>
#include <GL/glut.h>
 void display(void)
{ /* clear all pixels */ glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */
 glColor3f (1.0, 1.0, 1.0);
 glBegin(GL_POLYGON);
glVertex3f (0.15, 0.15, 0.0);
glVertex3f (0.65, 0.15, 0.0);
glVertex3f (0.65, 0.65, 0.0);
glVertex3f (0.15, 0.65, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.75, 0.25, 0.0);
glVertex3f (0.65, 0.15, 0.0);
glVertex3f (0.65, 0.65, 0.0);
glVertex3f (0.75, 0.75, 0.0);
glEnd();

glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.15, 0.65, 0.0);
glVertex3f (0.65, 0.65, 0.0);
glVertex3f (0.40, 0.90, 0.0);
glEnd();
glColor3f(0.9 , 0.0, 0.1);
glBegin(GL_POLYGON);
glVertex3f (0.75, 0.75, 0.0);
glVertex3f (0.65, 0.65, 0.0);
glVertex3f (0.40, 0.90, 0.0);
glEnd();
glColor3f (1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.675, 0.175, 0.0);
glVertex3f (0.675, 0.53, 0.0);
glVertex3f (0.757, 0.55, 0.0);
glVertex3f (0.757, 0.177, 0.0);
glEnd();
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (0.275, 0.49, 0.0);
glVertex3f (0.275, 0.51, 0.0);
glVertex3f (0.475, 0.51, 0.0);
glVertex3f (0.475, 0.49, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.275, 0.29, 0.0);
glVertex3f (0.275, 0.31, 0.0);
glVertex3f (0.475, 0.31, 0.0);
glVertex3f (0.475, 0.29, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.275, 0.39, 0.0);
glVertex3f (0.275, 0.41, 0.0);
glVertex3f (0.475, 0.41, 0.0);
glVertex3f (0.475, 0.39, 0.0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f (0.275, 0.29, 0.0);
glVertex3f (0.275, 0.49, 0.0);
glVertex3f (0.28, 0.49, 0.0);//we need a greater differnce because the window is relativly smaller along the y axis
glVertex3f (0.28, 0.29, 0.0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f (0.375, 0.29, 0.0);
glVertex3f (0.375, 0.49, 0.0);
glVertex3f (0.38, 0.49, 0.0);//we need a greater differnce because the window is relativly smaller along the y axis
glVertex3f (0.38, 0.29, 0.0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f (0.47, 0.29, 0.0);
glVertex3f (0.47, 0.49, 0.0);
glVertex3f (0.475, 0.49, 0.0);//we need a greater differnce because the window is relativly smaller along the y axis
glVertex3f (0.475, 0.29, 0.0);
glEnd();
glFlush (); }
void init (void) {
 /* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
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
glutCreateWindow ("house");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
