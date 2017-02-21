#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<ctime>
#include <GL/gl.h> 
#include <GL/glut.h>
using namespace std;
 void display(void) 
{ /* clear all pixels */ glClear (GL_COLOR_BUFFER_BIT); 
/* draw white polygon (rectangle) with corners at * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */
 glColor3f (0.0, 0.0, 0.0);
 /*glBegin(GL_POLYGON); 
glVertex3f (25, 25, 0.0); 
glVertex3f (75, 25, 0.0); 
glVertex3f (75, 75, 0.0); 
glVertex3f (25, 75, 0.0); 
glEnd();*/ 
glLineWidth(2.5);
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex3f(40.0, 25.0, 0.0);
glVertex3f(40.0,440.00,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f(40.0, 25.0, 0.0);
glVertex3f(450.0,25.00,0.0);
glEnd();
glLineWidth(0.5);
glColor3f(0.0, 0.5, 0.5);
for(int i=0;i<500;){
glBegin(GL_LINES);
glVertex3f(0,i,0.0);
glVertex3f(500.0,i,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f(i,0,0.0);
glVertex3f(i,500,0.0);
glEnd();
i=i+20;
}
 }
 void bar(){
//printf("enter the values");
//scanf("%d",
//rand() % (max_number + 1 - minimum_number) + minimum_number
glColor3f(0.0, 0.0, .0);
int x=rand() % (60 + 1 - 0) + 50;
int y=rand() % (105 + 1 - 0) + 50;
y=y+150;
//int y=rand()%100;
//glPrint(x);
glBegin(GL_POLYGON); 
glVertex3f (x, 25, 0.0); 
glVertex3f (x, y, 0.0); 
glVertex3f (x+50, y, 0.0); 
glVertex3f (x+50, 25, 0.0); 
glEnd();
y=rand() % (105 + 1 - 0) + 50;
glBegin(GL_POLYGON); 
glVertex3f (x+75, 25, 0.0); 
glVertex3f (x+75, y, 0.0); 
glVertex3f (x+125,y, 0.0); 
glVertex3f (x+125, 25, 0.0); 
glEnd();
y=rand() % (105 + 1 - 0) + 50;
glBegin(GL_POLYGON); 
glVertex3f (x+150, 25, 0.0); 
glVertex3f (x+150, y, 0.0); 
glVertex3f (x+200, y, 0.0); 
glVertex3f (x+200, 25, 0.0); 
glEnd();
y=rand() % (105 + 1 - 0) + 50;
glBegin(GL_POLYGON); 
glVertex3f (x+225, 25, 0.0); 
glVertex3f (x+225, y, 0.0); 
glVertex3f (x+275, y, 0.0); 
glVertex3f (x+275, 25, 0.0); 
glEnd();
y=rand() % (105 + 1 - 0) + 50;
glBegin(GL_POLYGON); 
glVertex3f (x+300, 25, 0.0); 
glVertex3f (x+300, y, 0.0); 
glVertex3f (x+350, y, 0.0); 
glVertex3f (x+350, 25, 0.0); 
glEnd();
 glFlush (); } 
 void line(){
glColor3f(0.0, 0.0,0.0);	 
/*int a[6]={150,170,220,270,290,320};
int b[6]={300,210,370,387,400,421};
for(int i=0;i<5;i++){
glBegin(GL_LINES);
glVertex3f(a[i], b[i], 0.0);
glVertex3f(a[i+1],b[i+1],0.0);
glEnd();*/
int a[8],b[8];
    for(int i=0;i<8;i++){
        int y=rand() % (325 + 1 - 150) + 150;
        a[i]=y;
        int x=rand() % (420 + 1 - 150) + 150;
        b[i]=x;
    }
    sort(a,a+8);
    sort(b,b+8);
    for(int i=0;i<7;i++){
    glBegin(GL_LINES);
    glVertex3f(a[i], b[i], 0.0);
    glVertex3f(a[i+1],b[i+1],0.0);
    glEnd();
    }

glFlush ();
 }
 void keyboard(unsigned char key, int x, int y)
{
switch(key) {
case 'b':{
bar();
//glClearColor (0.0,0.0,0.0,0.0);
		glClear (GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
		 
		break;}
case 'l':{
line();
//glClearColor (0.0,0.0,0.0,0.0);
		//glClear (GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
		break;}
case 'q':
	exit(0);
	break;
default:
break;
}
 }

void init (void) {
 /* select clearing (background) color */ 
glClearColor (1.0, 1.0, 1.0, 0.0); 
/* initialize viewing values */ 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
glOrtho(0,500,0,500,0,500); } 
/* * Declare initial window size, position, and display mode * (single buffer and RGBA). Open window with "hello" * in its title bar. Call initialization routines. * Register callback function to display graphics. * Enter main loop and process events. */ 

int  main(int argc, char** argv) {
	srand( time(0) );
glutInit(&argc, argv); 
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize (250, 250);
 glutInitWindowPosition (100, 100); 
glutCreateWindow ("Bargraph"); 
init (); 
glutDisplayFunc(display); 
 glutKeyboardFunc(keyboard);
glutMainLoop(); 
return 0; 
} 
