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

GLfloat Vertices[] =
{
	30.0, 30.0, 0.0,
	10.0, 10.0, 0.0,
	70.0, 30.0, 0.0,
	90.0, 10.0, 0.0,
	70.0, 70.0, 0.0,
	90.0, 90.0, 0.0,
	30.0, 70.0, 0.0,
	10.0, 90.0, 0.0,
	30.0, 30.0, 0.0,
	10.0, 10.0, 0.0
};

GLfloat Colors[] =
{
	0.0, 0.0, 0.0,
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
	1.0, 1.0, 1.0,
	1.0, 0.0, 1.0,
	0.0, 1.0, 1.0,
	1.0, 0.0, 0.0
};


/* reshape callback function
executed when window is moved or resized */
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	/* uses orthographic (parallel) projection
	use xmin = -1, xmax = 1
	ymin = -1, ymax = 1
	znear = -1, zfar = 1 - not relevant here (2D) */
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}



/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear window */
	glColor3f(red, green, blue);        /* white drawing objects */
	//---------------------------------------------------------------------
	glColorPointer(3, GL_FLOAT, 0, Colors); /*data sets,type,stride,array*/
	glVertexPointer(3, GL_FLOAT, 0, Vertices);
	glDrawArrays(GL_LINE_LOOP, 0, 8);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 10);
	glFlush();     /* execute drawing commands in buffer */
}

/* graphics initialisation */
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);   /* window will be cleared to black */
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
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glutMainLoop();
	return 0;
}

