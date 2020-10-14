/*
 5CCGD003W - Tutorial 1 - example code
 program draws a white rectangle on a black background
*/
// Code by Dr Anastassia Angelopoulou and Dr Phil Trwoga


#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <iostream>

//set up some constants
#define X_CENTRE 0.0      /* centre point of square */
#define Y_CENTRE 0.0
#define LENGTH   1.0      /* lengths of sides of square */

GLfloat red = 1.0, green = 1.0, blue = 1.0;
GLdouble PI = 3.14;


/* reshape callback function
executed when window is moved or resized */
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	/* uses orthographic (parallel) projection
	use xmin = -1, xmax = 1
	ymin = -1, ymax = 1
	znear = -1, zfar = 1 - not relevant here (2D) */
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

//Answer by me
void drawStar(GLfloat radius, GLfloat x, GLfloat y) {
	glBegin(GL_LINE_LOOP);
	GLfloat PI = 3.14;
	GLdouble PI_into_radian = PI / 180;
	glVertex2f(radius * cos(90*PI_into_radian), radius * sin(90 * PI_into_radian));
	glVertex2f( radius * cos(306 * PI_into_radian), radius * sin(306 * PI_into_radian));
	glVertex2f( radius * cos(162 * PI_into_radian),  radius * sin(162 * PI_into_radian));
	glVertex2f(radius * cos(18 * PI_into_radian), radius * sin(18 * PI_into_radian));
	glVertex2f(radius * cos(234 * PI_into_radian), radius * sin(234 * PI_into_radian));
	glEnd();
}

//Answer by lecturer
/*void drawStar_l(GLfloat radius, GLfloat x, GLfloat y)
{
	//x1,y1 is the first coordinate at 72 degrees from the unit circle

	glColor3f(red, green, blue);
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

	x1 = x + cos(72 * PI / 180) * radius;
	y1 = y + sin(72 * PI / 180) * radius;
	x2 = x + cos(144 * PI / 180) * radius;
	y2 = y + sin(144 * PI / 180) * radius;
	x3 = x + cos(216 * PI / 180) * radius;
	y3 = y + sin(216 * PI / 180) * radius;
	x4 = x + cos(288 * PI / 180) * radius;
	y4 = y + sin(288 * PI / 180) * radius;
	x5 = x + radius;
	y5 = y;


	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x3, y3);
	glVertex2f(x1, y1);
	glVertex2f(x4, y4);
	glVertex2f(x2, y2);
	glVertex2f(x4, y4);
	glVertex2f(x2, y2);
	glVertex2f(x5, y5);
	glVertex2f(x3, y3);
	glVertex2f(x5, y5);
	glEnd();
}*/


/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear window */
	glColor3f(red, green, blue);        /* white drawing objects */
	drawStar(5, 0, 0);
	glFlush();     /* execute drawing commands in buffer */
}

/* graphics initialisation */
void init(void)
{
	glClearColor(red, 0.0, 0.0, 0.0);   /* window will be cleared to black */
}

//rename this to main(...) and change example 2 to run this main function
int main(int argc, char** argv)
{
	/* window management code ... */
	/* initialises GLUT and processes any command line arguments */
	glutInit(&argc, argv);
	/* use single-buffered window and RGBA colour model */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* window width = 400 pixels, height = 400 pixels */
	glutInitWindowSize(400, 400);
	/* window upper left corner at (100, 100) */
	glutInitWindowPosition(100, 100);
	/* creates an OpenGL window with command argument in its title bar */
	glutCreateWindow("Example 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

