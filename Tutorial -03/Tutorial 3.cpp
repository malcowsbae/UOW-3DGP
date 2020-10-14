/*
* 5CCGD003W - Tutorial 3 - example solution code
* program uses different functions to draw various objects
*/
// Code by Dr Anastassia Angelopoulou 

#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>


//set up some constants
#define X_CENTRE 0.0      /* centre point of square */
#define Y_CENTRE 0.0
#define LENGTH   10.0      /* lengths of sides of square */

GLdouble PI = 3.14159;	    //Mathematical constant used for cos and sin functions
GLfloat angle = 2.0 * PI;

GLfloat angle_new = 0.0;

GLfloat red = 1.0, green = 1.0, blue = 1.0;


//forward declaration - best in the header
void drawStar1(GLfloat radius, GLfloat x, GLfloat y);
void drawStar2(GLfloat radius, GLfloat x, GLfloat y);
void drawSquare(GLfloat length, GLfloat x, GLfloat y);
void drawRect(GLfloat lengthX, GLfloat lengthY, GLfloat x, GLfloat y);
void drawCircle(GLfloat radius, GLfloat x, GLfloat y);
void drawCircle1(GLfloat radius, GLfloat x, GLfloat y);
void drawParabola();


/* reshape callback function
executed when window is moved or resized. */
void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, width, height);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);   //In all examples except the last task use these values
													//	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); //This is used in the last example
	glMatrixMode(GL_MODELVIEW);
}

/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     /* clear window */
									  /*glColor3f(red, green, blue);        /* white drawing objects */
	glColor3f(0.0, 0.0, blue);          /* blue drawing objects */
	glLoadIdentity();

	////Drawing Points
	//glPointSize(4.0);
	//glBegin(GL_POINTS);
	//glVertex2f( X_CENTRE - LENGTH / 2, Y_CENTRE - LENGTH / 2);
	//glVertex2f( X_CENTRE - LENGTH / 2, Y_CENTRE + LENGTH / 2);
	//glVertex2f( X_CENTRE + LENGTH / 2, Y_CENTRE + LENGTH / 2);
	//glVertex2f( X_CENTRE + LENGTH / 2, Y_CENTRE - LENGTH / 2);
	//glEnd();

	//////Drawing lines
	//glLineWidth(3);
	//glBegin(GL_LINE_LOOP);
	//glColor3f(0.2, 0.9, 0.5);
	//glVertex2f( X_CENTRE - LENGTH / 2, Y_CENTRE - LENGTH / 2);
	//glVertex2f( X_CENTRE - LENGTH / 2, Y_CENTRE + LENGTH / 2);
	//glVertex2f( X_CENTRE + LENGTH / 2, Y_CENTRE + LENGTH / 2);
	//glVertex2f( X_CENTRE + LENGTH / 2, Y_CENTRE - LENGTH / 2);
	//glEnd();

	//////Drawing a Triangle
	//glBegin(GL_TRIANGLES);
	//glColor3f(0.0, 0.4, 0.5);
	//glVertex2f( X_CENTRE - LENGTH / 2, Y_CENTRE - LENGTH / 2);
	//glVertex2f( X_CENTRE - LENGTH / 2, Y_CENTRE + LENGTH / 2);
	//glVertex2f( X_CENTRE + LENGTH / 2, Y_CENTRE + LENGTH / 2);
	//glEnd();

	////Drawing a Triangle Strip
	//glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(0.2, 0.9, 0.5);
	//glVertex3f(-5.0f, -5.0f, 0.0f); //vertex 1 = vo
	//glVertex3f(5.0f, 0.0f, 0.0f); //vertex 2 = v1
	//glVertex3f(0.0f, 5.0f, 0.0f); //vertex 3 = v2
	//glVertex3f(10.0f, 10.0f, 0.0f); //vertex 4 = v3
	//glEnd();

	//Drawing a Triangle fan 
	//glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.2, 0.9, 0.5);
	//glVertex3f(-1.0f, -0.5f, 0.0f);    // A
	//glVertex3f( 1.0f, -0.5f, 0.0f);    // B
	//glVertex3f( 0.0f,  0.5f, 0.0f);    // C

	//glVertex3f(-1.5f,  0.0f, 0.0f);    // D
	//glVertex3f(-1.8f, -1.0f, 0.0f);    // E
	//glVertex3f( 0.2f, -1.5f, 0.0f);    // F

	//glVertex3f( 1.0f, -0.5f, 0.0f);    // G
	//glEnd();


//Draws various shapes by calling the functions we created.....such as rectangle, cirdle, parabola, etc.
	drawRect(5.0, 2.0, -6.0, 3.0);


	// drawCircle(2, -3, -5);

	 //glColor3f(red, green, 0.0);
	 //drawCircle(3, 2, -6);
	 //glColor3f(0.0, 0.0, blue);
	 //drawCircle1(3, 2, -6);
	 //glColor3f(0.0, green, 0.0);
	 //drawCircle1(3.5, 2, -6);

//	 drawParabola();

	glPushMatrix();
	//The code below draws a parabola and also moves it by the trasnlate function.
	glTranslatef(-4, -6, 0);
	drawParabola();
	glPopMatrix();
	//  glColor3f(0.2, 0.9, 0.5);
	//   drawRect(2.0, 5.0, 8.0, 0.0);


//Draws a 5 point star and rotates by 10 degrees
	for (GLfloat i = 0; i < 16; i++)
	{
		glRotatef(10, 0.0, 0.0, 1.0);
		//modeling transformation 
	   //the above line will cause a 10 degree rotation
		drawStar1(4.0, 4.0, 0.0);
	}


	//glColor3f(0.0, 0.0, blue);
	//drawStar1(2, -5, -3);

	//glColor3f(red, green, 0.0);
	//drawStar2(2, 5, 3);

	glFlush();     /* execute drawing commands in buffer */

}

//Draws a square using polygons
void drawSquare(GLfloat length, GLfloat x, GLfloat y)
{
	//x1,y1 is the top left-hand corner coordinate
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;

	x1 = x - length / 2;
	y1 = y + length / 2;
	x2 = x + length / 2;
	y2 = y + length / 2;
	x3 = x + length / 2;
	y3 = y - length / 2;
	x4 = x - length / 2;
	y4 = y - length / 2;

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	glFlush();
}

//Draws a rectangle using polygons
void drawRect(GLfloat lengthX, GLfloat lengthY, GLfloat x, GLfloat y)
{
	//x1,y1 is the top left-hand corner coordinate
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;

	//This example is for a rectangle 
	x1 = x - lengthX / 2;
	y1 = y + lengthY / 2;
	x2 = x + lengthX / 2;
	y2 = y + lengthY / 2;
	x3 = x + lengthX / 2;
	y3 = y - lengthY / 2;
	x4 = x - lengthX / 2;
	y4 = y - lengthY / 2;

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	glFlush();
}

// Two ways to draw the star. The first uses a positive angle and the sin and cos function.
// The second star uses coordinates with positives and negative values. Both ways are absolutely fine. 

//Draws a 5 pointed star using lines
void drawStar1(GLfloat radius, GLfloat x, GLfloat y)
{
	//x1,y1 is the first coordinate at 72 degrees from the unit circle
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

	//Change the width of the line. You can have a thicker line.
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

	glFlush();
}

void drawStar2(GLfloat radius, GLfloat x, GLfloat y)
{
	//x1,y1 is the top coordinate
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

	x1 = x;
	y1 = y + radius;
	x2 = x + 0.90 * radius;
	y2 = y + 0.40 * radius;
	x3 = x + 0.65 * radius;
	y3 = y - 0.55 * radius;
	x4 = x - 0.65 * radius;
	y4 = y - 0.55 * radius;
	x5 = x - 0.90 * radius;
	y5 = y + 0.40 * radius;

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


	glFlush();
}


//Draws a circle using line loop
void drawCircle(GLfloat radius, GLfloat x, GLfloat y)
{
	GLint i;
	GLint numLines = 1000;   //number of lines-

	glLineWidth(2.0);
	//glColor3f(red, green, 0.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= numLines; i++)
	{
		glVertex2f(x + radius * cos(i * angle / numLines), y + radius * sin(i * angle / numLines));
	}
	glEnd();

	glFlush();
}

//Draws a circle using line loop
void drawCircle1(GLfloat radius, GLfloat x, GLfloat y)
{
	GLint i;
	GLint numLines = 6;   //number of lines

	glLineWidth(2.0);
	//glColor3f(red, green, 0.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= numLines; i++)
	{
		glVertex2f(x + radius * cos(i * angle / numLines), y + radius * sin(i * angle / numLines));
	}
	glEnd();

	glFlush();
}

//Draws a parabola using line strip
void drawParabola(void)
{
	GLint i;
	glLineWidth(2.0);
	glColor3f(0.0, green, 0.4);
	glBegin(GL_LINE_STRIP);
	for (GLfloat i = -40; i <= 40; ++i)
	{
		glVertex2f(3.0 / 40 + 3.0 * i / 40, 4.0 * (i * i) / (30 * 30));
	}
	glEnd();
	glFlush();
}


/* graphics initialisation */
void init(void)
{
	/*glClearColor (0.0, 0.0, 0.0, 0.0);   /* window will be cleared to black */
	glClearColor(1.0, 0.0, 0.5, 0.0);     /* window will be cleared to white */

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
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
	/* window width = 640 pixels, height = 480 pixels for a 4:3 ascpect ratio */
	/* window width = 1024 pixels, height = 576 pixels for a 16:9 ascpect ratio */
	glutInitWindowSize(400, 400);
	/* window upper left corner at (100, 100) */
	glutInitWindowPosition(100, 100);
	/* creates an OpenGL window with command argument in its title bar */
	glutCreateWindow("Example 2");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
