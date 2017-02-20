#include<cmath>
#include <GL/glut.h>
GLsizei MOUSEx=0, MOUSEy=0;
GLfloat SIDE=50;
GLfloat BLUE[3] = {0,0,1};

void drawSquare1()
{
    glColor3fv(BLUE);
   glBegin(GL_TRIANGLE_FAN);
int r=100,cx=MOUSEx,cy=MOUSEy,num_segments=6;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
	glEnd();
    	glFlush();
}   
void drawStar()
{
    glColor3fv(BLUE);
     glBegin(GL_POLYGON); 
int x=MOUSEx,y=MOUSEy;
glVertex3f (x, y, 0.0);
glVertex3f (x+80, y, 0.0);
glVertex3f (x+40, y+65, 0.0);
//glVertex3f (x, y+75, 0.0);
glEnd(); 
//int x=MOUSEx,y=MOUSEy;
glBegin(GL_POLYGON);
glVertex3f (x, y+50, 0.0);
glVertex3f (x+80, y+50, 0.0);
glVertex3f (x+40, y-15, 0.0);
//glVertex3f (x, y+75, 0.0);
glEnd();

/*glColor3f(0.65,0.0,0.0);
glBegin(GL_TRIANGLES);
    glVertex3f(0.30, 0.65, 0.0);
    glVertex3f(0.40, 0.60, 0.0);
    glVertex3f(0.50, 0.65, 0.0);
glEnd();
glBegin(GL_QUADS);
    glVertex3f(0.30, 0.50, 0.0);//a

    glVertex3f(0.40, 0.60, 0.0);//b

    glVertex3f(0.50, 0.50, 0.0);//c

    glVertex3f(0.40, 0.70, 0.0);//d
glEnd();*/
/*   glBegin(GL_TRIANGLE_FAN);
int r=100,cx=MOUSEx,cy=MOUSEy,num_segments=5;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
    glEnd();
    */
    glFlush();
}   
void display(void)
{   
   // glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
   // glLoadIdentity(); 
   //drawSquare1();
    //glFlush();
}
void reshape(int w, int h)
{   
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     //gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glOrtho(0.0,1368,768,0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spindisplay(void)
{       
    glutPostRedisplay();
}

void setX(int x)
{
    MOUSEx=x;
}

void setY(int y)
{
    MOUSEy=y;
}
void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)   
    {
        setX(x);
        setY(y);
        //drawSquare(MOUSEx,HEIGHT-MOUSEy);
		drawSquare1();
		glClearColor (0.0,0.0,0.0,1.0);
		glClear (GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)   
    {
       setX(x);
        setY(y);
        //drawSquare(MOUSEx,HEIGHT-MOUSEy);
		drawStar();
		glClearColor (0.0,0.0,0.0,1.0);
		glClear (GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
switch(key) {
case 'q':
exit(0);
break;
case 'Q':
exit(0);
break;
default:
break;
}
}
int main(int argc, char **argv)
{   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("DRAW");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
	//glLoadIdentity(); 
    glutIdleFunc(spindisplay);
    glutMainLoop();


}

