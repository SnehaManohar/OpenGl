#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <GL/gl.h> 
#include <GL/glut.h>
using namespace std;
static int mainmenu,v=0;


void menu(int val){
    if(val==0){
        exit(0);
    }
    else{
    v=val;
    }
    glutPostRedisplay();
}
void createMenu(void){

mainmenu=glutCreateMenu(menu);
glutAddMenuEntry("Rotate",1);
glutAddMenuEntry("Scale",2);
glutAddMenuEntry("Translate",3);
glutAddMenuEntry("Exit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void rotate(void){ 
	glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
 glBegin(GL_POLYGON); 
glVertex3f (250, 250, 0.0); 
glVertex3f (200, 250, 0.0); 
glVertex3f (200, 200, 0.0); 
glVertex3f (250, 200, 0.0); 
glEnd();

    glRotatef(10,0,0,1);
}
void scale(void){
glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON); 
glVertex3f (250, 250, 0.0); 
glVertex3f (200, 250, 0.0); 
glVertex3f (200, 200, 0.0); 
glVertex3f (250, 200, 0.0); 
glEnd();
glScaled(1.1, 1.1, 1.1);
}
void translate(void){
glClear (GL_COLOR_BUFFER_BIT); 
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON); 
glVertex3f (250, 250, 0.0); 
glVertex3f (200, 250, 0.0); 
glVertex3f (200, 200, 0.0); 
glVertex3f (250, 200, 0.0); 
glEnd();
glTranslatef(40,0,0);
}
     void display(void) 
    { 
glClearColor (1.0, 1.0, 1.0, 0.0); 
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON); 
glVertex3f (250, 250, 0.0); 
glVertex3f (200, 250, 0.0); 
glVertex3f (200, 200, 0.0); 
glVertex3f (250, 200, 0.0); 
glEnd();


    if(v==1){
   rotate();
    }
    else if(v==2){
    scale();
    }
	  else if(v==3){
    translate();
    }
glFlush();    
     } 
    void init (void) {
     /* select clearing (background) color */ 
    glClearColor (1.0, 1.0, 1.0, 0.0); 
    /* initialize viewing values */ 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(0,500,0,500,0,500); } 
    /* * Declare initial window size, position, and display mode * (single buffer and RGBA). Open window with "hello" * in its title bar. Call initialization routines. * Register callback function to display graphics. * Enter main loop and process events. */ 
    
    int main(int argc, char** argv) {
    srand( time(0) );
    glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (500, 500);
     glutInitWindowPosition (100, 100); 
    glutCreateWindow ("Graph"); 
    init (); 
    createMenu();
    glutDisplayFunc(display);
    glutMainLoop();
    glutPostRedisplay();
    return 0; 
    }
