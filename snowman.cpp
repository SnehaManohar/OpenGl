#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1415926
#include<stdlib.h>
#include<time.h>

 void display(void)
{ /* clear all pixels */ glClear (GL_COLOR_BUFFER_BIT);
//arms
glLineWidth(1.5);
glColor3f (1.0, 0.0, 0.0);      // Set line segment color to red.
glBegin (GL_LINES);
glVertex2i (60,135);       // Specify line-segment geometry.
glVertex2i (95,168);
glEnd ();
glBegin (GL_LINES);
glVertex2i (190,135);       // Specify line-segment geometry.
glVertex2i (155,168);
glEnd ();
//moon
glColor3f(1.0,1.0,0.5);
glBegin(GL_TRIANGLE_FAN);
int r=25,cx=440,cy=440,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();

 glColor3f (1.0, 1.0, 1.0);
//glBegin(GL_LINE_LOOP);// when we want an unfilled circle
//snowflakes
int x,y;
for(int i=0;i<10;i++){
x=rand()%500;
y=rand()%500;
float theta=float(30)*3.14159f/float(180);
glBegin( GL_LINES);
glVertex3d( x, y, 0);
glVertex3d( x, y+50, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x-25*cosf(theta),y+12.5, 0);
glVertex3d(x+25*cosf(theta),y+37.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d(x-25*cosf(theta),y+37.5, 0);
glVertex3d(x+25*cosf(theta),y+12.5, 0);
glEnd();
//top half
glBegin( GL_LINES);
glVertex3d( x-25*cosf(theta)+15*cosf(theta*2),y+42.5, 0);
glVertex3d(x-25*cosf(theta)+15*cosf(theta*2),y+31.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x-25*cosf(theta)+15*cosf(theta*2),y+31.5, 0);
glVertex3d(x-25*cosf(theta),y+27.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d(x+25*cosf(theta),y+27.5, 0);
glVertex3d(x+25*cosf(theta)-15*cosf(theta*2),y+31.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x+25*cosf(theta)-15*cosf(theta*2),y+42.5,0);
glVertex3d( x+25*cosf(theta)-15*cosf(theta*2),y+31.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x,y+41.5,0);
glVertex3d( x+15*cos(theta*2),y+47.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x,y+41.5,0);
glVertex3d( x-15*cos(theta*2),y+47.5, 0);
glEnd();
//bottom half
glBegin( GL_LINES);
glVertex3d( x,y+12.5,0);
glVertex3d( x+15*cosf(theta*2),y+2.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x,y+12.5,0);
glVertex3d( x-15*cosf(theta*2),y+2.5, 0);
glEnd();
//sides on the bottom
glBegin( GL_LINES);
glVertex3d( x-25*cosf(theta)+15*cosf(theta*2),y+15.5, 0);
glVertex3d(x-25*cosf(theta)+15*cosf(theta*2),y+5.0, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x-25*cosf(theta)+15*cosf(theta*2),y+15.5, 0);
glVertex3d(x-25*cosf(theta),y+20.5, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x+25*cosf(theta)-15*cosf(theta*2),y+15.5, 0);
glVertex3d(x+25*cosf(theta)-15*cosf(theta*2),y+5.0, 0);
glEnd();
glBegin( GL_LINES);
glVertex3d( x+25*cosf(theta)-15*cosf(theta*2),y+15.5, 0);
glVertex3d(x+25*cosf(theta),y+20.5, 0);
glEnd();
}
//base
glBegin(GL_POLYGON);
glVertex3f (0, 0, 0.0);
glVertex3f (0, 100, 0.0);
glVertex3f (500, 100, 0.0);
glVertex3f (500, 0, 0.0);
glEnd();
//lower ball
glBegin(GL_TRIANGLE_FAN);
r=45,cx=125,cy=135,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();
//upper ball
glBegin(GL_TRIANGLE_FAN);
r=35,cx=125,cy=205,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();
//buttons
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_TRIANGLE_FAN);
r=5,cx=125,cy=155,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();
glBegin(GL_TRIANGLE_FAN);
r=5,cx=125,cy=115,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();
//eyes
glBegin(GL_TRIANGLE_FAN);
r=4,cx=110,cy=215,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();
glBegin(GL_TRIANGLE_FAN);
r=4,cx=140,cy=215,num_segments=2500;
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta); // r=radius
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);//output vertex cx nd cy are x nd y corodinates of circle

    }
glEnd();
//nose
glColor3f(1.0,0.0,0.0);
glBegin(GL_TRIANGLES);//start drawing triangles
glVertex3f(120,205,0);//triangle one first vertex
glVertex3f(130,205,0);//triangle one second vertex
glVertex3f(125,200,0);//triangle one third vertex
glEnd();//end drawing of triangles
/*glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (57, 235, 0.0);
glVertex3f (57, 265, 0.0);
glVertex3f (101, 265, 0.0);
glVertex3f (101,235, 0.0);
glEnd();
*/

glFlush (); }
void init (void) {
 /* select clearing (background) color */
glClearColor (0.0, 0.0, 0.299, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0,500,0,500,0,500);

 }
/* * Declare initial window size, position, and display mode * (single buffer and RGBA). Open window with "hello" * in its title bar. Call initialization routines. * Register callback function to display graphics. * Enter main loop and process events. */

int  main(int argc, char** argv) {
srand(time(NULL));
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500,500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("SnOwMaN");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

