#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Components.h"

/*
* Drive Link https://drive.google.com/drive/folders/1XxrKUbaSK2LWunSGl7UwUuzSAXnS6XhV?usp=sharing
* UOW ID W1761889
* I hereby certify no code was copied or plagiarised all the work done by me.
* Original Template Provided in Tutorial 04 is Used.
*/

//set up some constants
#define ANGLE 90.0f
#define END_LEFT_TOP_X 450.0f
#define END_LEFT_TOP_Y 480.0f
#define END_RIGHT_BOTTOM_X 495.0f
#define END_RIGHT_BOTTOM_Y 468.0f

//glRectf(450.0f, 480.0f, 495.0f, 468.0f);
// Use the STL extension of C++
using namespace std;

GLsizei wh = 500, ww = 500;

GLfloat red = 1.0, green = 1.0, blue = 1.0;

// Add your Globals here
extern GLboolean rotateStatus = FALSE;

//Game status success or fail
bool gameStatus = FALSE;
// Grid view or Close Grid 
bool gridOption = FALSE;
// Active Positions
float xPos=0.0; 
float yPos=0.0;

int finalPoint = 0; //Accumilated points

void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		yPos = yPos + 5;
		printf("%f %s\n",yPos,"Up");
		collisionDetec(xPos, yPos);
		glutPostRedisplay();
		break;
	case 's':
		yPos = yPos -5;
		printf("%f %s\n", yPos, "Down");
		collisionDetec(xPos, yPos);
		glutPostRedisplay();
		break;
	case 'a':
		xPos = xPos - 5;
		printf("%f %s\n", xPos, "Left");
		collisionDetec(xPos, yPos);
		glutPostRedisplay();
		break;
	case 'd':
		xPos = xPos + 5;
		printf("%f %s\n", xPos, "Right");
		collisionDetec(xPos, yPos);
		glutPostRedisplay();
		break;
	case 'r':
		rotateStatus = TRUE;
		printf("%s \n","Rotate Function Requested");
		glutPostRedisplay();
		break;

	}
}

void glutMenu(GLint id)
{
	if (id == 1)
	{
		gridOption = TRUE;
		printf("Option 1 ");
	}
	else if (id ==2)
	{
		gridOption = FALSE;
		printf("Option 2");
	}
	glutPostRedisplay();
}

// reshape callback function executed when window is moved or resized. 
void reshape(GLsizei w, GLsizei h)
{
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	glMatrixMode(GL_PROJECTION);

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	// Set the aspect ratio of the clipping area to match the viewport
	if (w <= h)
		glOrtho(0.0f, ww, 0.0f, wh*h / w, 1.0, -1.0);
	else
		glOrtho(0.0f, ww*w / h, 0.0f, wh, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void reSpawnPostion()
{
	/*
	* Checking whether pointer has reached ending location
	*/
	if ((xPos >= END_LEFT_TOP_X && xPos <= END_RIGHT_BOTTOM_X) && (yPos >= END_RIGHT_BOTTOM_Y && yPos <= END_LEFT_TOP_Y))
	{
		gameStatus = TRUE;
		printf("%s","Respawn Function Triggered");
	}
}
/* display callback function
   called whenever contents of window need to be re-displayed */


void display()
{
	// Clear the window with current clearing colour
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	writeScore();
	drawContainer();
	drawGrid(gridOption);
	drawStartLine();
	drawFinishLine();
	drawObstacles();
	moveCar((GLfloat)xPos, (GLfloat)yPos);
	rotateCar(rotateStatus);
	reSpawnPostion();
	if (gameStatus == TRUE)
	{
		genObstacles();
		drawObstacles();
		xPos = 0.0;
		yPos = 0.0;
		totalScore = 50;
		moveCar((GLfloat)xPos, (GLfloat)yPos);
		finalPoint += totalScore;
		printf("\n %d %s \n", finalPoint," - Accumilated Points");
		gameStatus = FALSE;
	}
	else if (totalScore <= 0)
	{
		genObstacles();
		drawObstacles();
		xPos = 0.0;
		yPos = 0.0;
		totalScore = 50;
		moveCar((GLfloat)xPos, (GLfloat)yPos);
		totalScore = 50;

	}
	
	glutPostRedisplay();
	
	glutSwapBuffers();
}


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Cleared to black
	genObstacles();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Car Game");
	glutDisplayFunc(display);
	//Creating Glut menus
	glutCreateMenu(glutMenu);
	glutAddMenuEntry("Turn on", 1);
	glutAddMenuEntry("Turn off", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	//keyboard interaction

	glutKeyboardFunc(keyInput);


	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

