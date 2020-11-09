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

void drawSquare(GLfloat length, GLfloat centerX, GLfloat centerY)
{
	glRectf(centerX - (length / 2), centerY + (length / 2), centerX + (length / 2), centerY - (length / 2));
}

void drawRect(GLfloat centerX, GLfloat centerY, GLfloat height, GLfloat width)
{
	glBegin(GL_POLYGON);
	glVertex2f(centerX - (width / 2), centerY + (height / 2));
	glVertex2f(centerX + (width / 2), centerY + (height / 2));
	glVertex2f(centerX + (width / 2), centerY - (height / 2));
	glVertex2f(centerX - (width / 2), centerY - (height / 2));
	glEnd();
}

void drawStar(GLfloat radius, GLfloat centerX, GLfloat centerY)
{
	glBegin(GL_LINES);
	glVertex2f(centerX, centerY + radius);
	glVertex2f(radius * sin(144), radius * cos(144));
	
	glVertex2f(radius * sin(144), radius * cos(144));
	glVertex2f(radius * sin(288), radius * cos(288));

	glEnd();
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	* This chunck will draw triangles and a square to scene
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	
	glLineWidth(2.0f); //Doubling the line width of the drawing 
	glBegin(GL_LINES);
	
	
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(-25.0f, -25.0f);
	glVertex2f(0.0f, 25.0f);

	
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(25.0f, -25.0f);
	glVertex2f(0.0f, 25.0f);


	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(25.0f, -25.0f);
	glVertex2f(-25.0f, -25.0f);

	glEnd(); */

	
	drawSquare(4.0f, 5.0f, 5.0f);
	drawSquare(20.0f, 0.0f, 0.0f);
	drawSquare(10.0f, 16.0f, 21.0f);
	drawSquare(10.0f, -16.0f, 21.0f);

	drawRect(-20.0f,80.0f, 8.0f, 2.0f);
	drawStar(10.0f, 32.0f, 42.0f);

	glFlush();

}



void SetupRC()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
 }

void ChangeSize(GLsizei w,GLsizei h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;

	if (w <= h)
		glOrtho(-100.0, 100.0, -100/aspectRatio,100.0/aspectRatio,1.0,-1.0 );
	else 
		glOrtho(-100.0*aspectRatio, 100.0*aspectRatio, -100, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*void myFirstmenu(GLint id)
{
	boolColor = 1.0;

}*/

/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here

//rename this to main(...) and change example 2 to run this main function

int main(int argc, char** argv)
{
	/* window management code ... */
	/* initialises GLUT and processes any command line arguments */
	glutInit(&argc, argv);
	/* use single-buffered window and RGBA colour model */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* window width = 400 pixels, height = 400 pixels */
	/* window upper left corner at (100, 100) */
	/*688x384 Center in the laptop*/
	/* creates an OpenGL window with command argument in its title bar */
	glutCreateWindow("Tutorial 02");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(100,100);
	glutDisplayFunc(RenderScene);
	//glViewport(0, 0, 250, 250);
	glutReshapeFunc(ChangeSize);
	SetupRC();

	printf("Application is running");
	glutMainLoop();
	return 0;
}

