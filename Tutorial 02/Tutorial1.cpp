/*
 5CCGD003W - Tutorial 1 - example code
 program draws a white rectangle on a black background
*/
// Code by Dr Anastassia Angelopoulou and Dr Phil Trwoga

#define _USE_MATH_DEFINES 
#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <iostream>
#include <math.h>;

//set up some constants
#define X_CENTRE 0.0      /* centre point of square */
#define Y_CENTRE 0.0
#define LENGTH   1.0  
/* lengths of sides of square */
GLfloat red = 1.0, green = 1.0, blue = 1.0;


/* reshape callback function
executed when window is moved or resized */
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	/* uses orthographic (parallel) projection
	use xmin = -1, xmax = 1
	ymin = -1, ymax = 1
	znear = -1, zfar = 1 - not relevant here (2D) */
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void drawSquare(GLfloat centerX, GLfloat centerY, GLfloat length)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectd(centerX-(length/2.0f),centerY- (length / 2.0f), centerX+(length / 2.0f),centerY+(length/2.0f));

}

void drawStar(GLfloat centerX, GLfloat centerY, GLfloat radius)
{
	glBegin(GL_LINES);
	glVertex2f(radius*sin(72*M_PI/ 180),radius*cos(72*M_PI/180));
	glVertex2f(radius * sin(288 * M_PI / 180), radius * cos(288 * M_PI / 180));

	glVertex2f(radius * sin(288 * M_PI / 180), radius * cos(288 * M_PI / 180));
	glVertex2f(radius * sin(144 * M_PI / 180), radius * cos(144 * M_PI / 180));

	glVertex2f(radius * sin(144 * M_PI / 180), radius * cos(144 * M_PI / 180));
	glVertex2f(radius * sin(0 * M_PI / 180), radius * cos(0 * M_PI / 180));

	glVertex2f(radius * sin(0 * M_PI / 180), radius * cos(0 * M_PI / 180));
	glVertex2f(radius * sin(216 * M_PI / 180), radius * cos(216 * M_PI / 180));

	glVertex2f(radius * sin(216 * M_PI / 180), radius * cos(216 * M_PI / 180));
	glVertex2f(radius * sin(72 * M_PI / 180), radius * cos(72 * M_PI / 180));
	glEnd();
}

/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear window */
	//glColor3f(0.0f, 0.0f, 1.0f);        /* white drawing objects */
   
    /* define object to be drawn as a square polygon */
	//glBegin(GL_POLYGON);

	//specify the vertices (points in 3D space) of the shape - note that these are 2D points
	/*glVertex2f(X_CENTRE - LENGTH / 2, Y_CENTRE - LENGTH / 2);
	glVertex2f(X_CENTRE - LENGTH / 2, Y_CENTRE + LENGTH / 2);
	glVertex2f(X_CENTRE + LENGTH / 2, Y_CENTRE + LENGTH / 2);
	glVertex2f(X_CENTRE + LENGTH / 2, Y_CENTRE - LENGTH / 2);
	glEnd();*/
	//drawSquare(X_CENTRE, Y_CENTRE, LENGTH);
	//drawSquare(0.5f, 0.5f, 2.0f);
	//drawSquare(-1.0f, 0.0f, 1.0f);
	glColor3f(0.5f, 1.0f, 0.5f); //Greenish  blue lines 
	glLineWidth(2.0f);
	
	drawStar(0.0f, 0.0f, 0.5f);
	
	/*
	* Drawing a triangle 
	glBegin(GL_LINE_LOOP);
	
	GLfloat dist = LENGTH / 2;
	glVertex2f(X_CENTRE - dist, Y_CENTRE - dist);
	glVertex2f(X_CENTRE, Y_CENTRE + dist);

	glVertex2f(X_CENTRE, Y_CENTRE + dist);
	glVertex2f(X_CENTRE+ dist, Y_CENTRE - dist);

	glVertex2f(X_CENTRE + dist, Y_CENTRE - dist);
	glVertex2f(X_CENTRE - dist, Y_CENTRE - dist);

	glEnd();*/
	glFlush();     /* execute drawing commands in buffer */
}

/* graphics initialisation */
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);   /* window will be cleared to black */
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
	glutInitWindowSize(640, 480);
	/* window upper left corner at (100, 100) */
	glutInitWindowPosition(100, 100);
	/* creates an OpenGL window with command argument in its title bar */
	glutCreateWindow("Tutorial 2");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

