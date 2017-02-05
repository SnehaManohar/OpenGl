#include<GL/gl.h>
#include<GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //kitetail
glLineWidth(2.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.55, 0.0);
glVertex3f(0.35, 0.45, 0.0);
glEnd();
glLineWidth(2.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.51, 0.0);
glVertex3f(0.33, 0.45, 0.0);
glEnd();
glLineWidth(2.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.51, 0.0);
glVertex3f(0.37, 0.45, 0.0);
glEnd();
//kite
glColor3f(0.65,0.0,0.0);
glBegin(GL_POLYGON);
glVertex3f (0.30, 0.70, 0.0);//leftvertex
glVertex3f (0.35, 0.50, 0.0);//lowervertex
glVertex3f (0.40, 0.70, 0.0);//rightvertex
glVertex3f (0.35, 0.80, 0.0);//uppervertex
glEnd();
//kiteline
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.0, 0.0, 0.0);
glVertex3f(0.35,0.72, 0);
glEnd();
//kiteedges
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.30, 0.70, 0.0);
glVertex3f(0.35,0.80, 0);
glEnd();
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.80, 0.0);
glVertex3f(0.40,0.70, 0);
glEnd();
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.40, 0.70, 0.0);
glVertex3f(0.35,0.50, 0);
glEnd();
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.50, 0.0);
glVertex3f(0.30,0.70, 0);
glEnd();
//kiteinside
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.72, 0.0);
glVertex3f(0.31,0.70, 0);
glEnd();
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.72, 0.0);
glVertex3f(0.35,0.77, 0);
glEnd();
glLineWidth(0.5);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(0.35, 0.72, 0.0);
glVertex3f(0.39,0.70, 0);
glEnd();


glFlush();
}
void init (void) {
glClearColor (0.3, 0.3, 0.87, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); }
int  main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (650,300);
glutInitWindowPosition (500, 100);
glutCreateWindow ("kite");

init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


