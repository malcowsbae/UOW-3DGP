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

//===========Tutorial 1 part 2 starts here!================
//Creating a function to draw the squares
void drawSquare(GLfloat length, GLfloat centerX, GLfloat centerY) {
	glBegin(GL_POLYGON);
	glVertex2f(centerX - length / 2, centerY - length / 2);
	glVertex2f(centerX - length / 2, centerY + length / 2);
	glVertex2f(centerX + length / 2, centerY + length / 2);
	glVertex2f(centerX + length / 2, centerY - length / 2);
	glEnd();
}

//Creating a function to draw the rectangle
void drawRectangle(GLfloat width, GLfloat height, GLfloat centerX, GLfloat centerY) {
	glBegin(GL_POLYGON);
	glVertex2f(centerX - width / 2, centerY - height / 2);
	glVertex2f(centerX - width / 2, centerY + height / 2);
	glVertex2f(centerX + width / 2, centerY + height / 2);
	glVertex2f(centerX + width / 2, centerY - height / 2);
	glEnd();

}


/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear window */
	glColor3f(red, green, blue);        /* white drawing objects */
	
	//Calling the square function and passing parameters
	//glColor3f(0, 0, blue);
	//drawSquare(3, -5, 5);

	


	//glColor3f(0, 0, 0);
	//drawSquare(5, 7, 7);

	//Calling the recatngle function and passing the parameters
	//glColor3f(0, green, 0);
	//drawRectangle(4, 2, -4, -8);
	

	glFlush();     /* execute drawing commands in buffer */
}

/* graphics initialisation */
void init(void)
{
	glClearColor(red, 0.0, 0.0, 0.0);   /* window will be cleared to black */
}

void glutMenu1(GLint option) {
	if (option == 1) {
		glClearColor(0.0, 0.0, 0.9, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0, green, 0);
		drawSquare(3, 0, 0);
		glFlush();
	} 
	else {
		glClearColor(0.0, 0.9, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(red, 0, 0);
		drawSquare(3, 0, 0);
		glFlush();
	}
	glutPostRedisplay();
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
	glutInitWindowPosition(568, 232);
	/* creates an OpenGL window with command argument in its title bar */
	glutCreateWindow("Example 1");
	//std::cout << "Display width" << glutGet(GLUT_SCREEN_WIDTH) << "\n";
	//std::cout << "Display height" << glutGet(GLUT_SCREEN_HEIGHT);
	glutCreateMenu(glutMenu1);
	glutAddMenuEntry("Blue bg with green square", 1);
	glutAddMenuEntry("Green bg with red square", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

