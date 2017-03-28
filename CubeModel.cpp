#include <windows.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
static GLfloat theta[ ]={0.0,0.0,0.0};
static GLint axis=1;
GLfloat vertices[ ][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},
{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};

GLfloat normals[ ][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},
{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};

GLfloat colors[ ][3]={{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},
{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};

void cube(int a,int b,int c,int d){
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}
void color_cube(void){
    cube(0,3,2,1);
    cube(2,3,7,6);
    cube(0,4,7,3);
    cube(1,2,6,5);
    cube(4,5,6,7);
    cube(0,1,5,4);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);
    color_cube();
    glFlush();
    glutSwapBuffers();
}
void spinCube(){
    theta[axis]+=.05;
    if(theta[axis]>360.0)
        theta[axis]-=360.0;
    glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y){
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {printf("Enter theta value in float:\n");
    scanf("%f",&theta[0]);
    axis=0;
    }
    if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
    {printf("Enter theta value in float:\n");
    scanf("%f",&theta[1]);
    axis=1;}
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        printf("Enter theta value in float:\n");
    scanf("%f",&theta[2]);
    axis=2;}
    if(theta[axis]>360.0)
        theta[axis]-=360.0;
    display();
}

void myreshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
int main(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("CUBE");
    glutReshapeFunc(myreshape);
    glutDisplayFunc(display);
	glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0,1.0,1.0,1.0);
    glutMainLoop();
    return 0;
}