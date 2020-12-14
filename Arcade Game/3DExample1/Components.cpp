#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Components.h"

#define ANGLE 90.0f
//Globals
GLfloat cordinates[20]; //Obsatacle Possitions
int totalScore = 50; // Starting Score

//Collision Status
extern bool cubeOne = FALSE;
extern bool cubeTwo = FALSE;
extern bool cubeThree = FALSE;
extern bool cubeFour = FALSE;
extern bool cubeFive = FALSE;

int calcScore()
{
	/*
	* Calculating Score
	*/
	if (cubeOne)
	{
		totalScore = totalScore - 10;
		cubeOne = FALSE;
	}
	if (cubeTwo)
	{
		totalScore = totalScore - 10;
		cubeTwo = FALSE;
	}
	if (cubeThree)
	{
		totalScore = totalScore - 10;
		cubeThree = FALSE;
	}
	if (cubeFour)
	{
		totalScore = totalScore - 10;
		cubeFour = FALSE;
	}
	if (cubeFive)
	{
		totalScore = totalScore - 10;
		cubeFive = FALSE;
	}
	return totalScore;
}
// Routine to draw a bitmap character string.
void writeBitmapString(void* font, char* string)
{
	char* c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void writeScore()
{
	/*
	* Updating Score
	*/
	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(5, 485);
	std::string s = "Score "+ std::to_string(calcScore());
	char* cstr = &s[0];
	writeBitmapString(GLUT_BITMAP_HELVETICA_18,cstr);
}

void drawContainer()
{
	/*
	* Drawing the outline in the window
	*/
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(5.0f, 480.0f);
	glVertex2f(495.0f, 480.0f);
	glVertex2f(495.0f, 0.0f);
	glVertex2f(5.0f, 0.0f);
	glEnd();
}

void drawGrid(bool option)
{
	if (option)
	{
		glLineWidth(2);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
		/*
		* Drawing Coloums
		*/
		glVertex2f(30.0f, 0.0f);
		glVertex2f(30.0f, 480.0f);
		glVertex2f(55.0f, 0.0f);
		glVertex2f(55.0f, 480.0f);
		glVertex2f(80.0f, 0.0f);
		glVertex2f(80.0f, 480.0f);
		glVertex2f(105.0f, 0.0f);
		glVertex2f(105.0f, 480.0f);
		glVertex2f(130.0f, 0.0f);
		glVertex2f(130.0f, 480.0f);
		glVertex2f(155.0f, 0.0f);
		glVertex2f(155.0f, 480.0f);
		glVertex2f(180.0f, 0.0f);
		glVertex2f(180.0f, 480.0f);
		glVertex2f(205.0f, 0.0f);
		glVertex2f(205.0f, 480.0f);
		glVertex2f(230.0f, 0.0f);
		glVertex2f(230.0f, 480.0f);
		glVertex2f(255.0f, 0.0f);
		glVertex2f(255.0f, 480.0f);
		glVertex2f(280.0f, 0.0f);
		glVertex2f(280.0f, 480.0f);
		glVertex2f(305.0f, 0.0f);
		glVertex2f(305.0f, 480.0f);
		glVertex2f(330.0f, 0.0f);
		glVertex2f(330.0f, 480.0f);
		glVertex2f(355.0f, 0.0f);
		glVertex2f(355.0f, 480.0f);
		glVertex2f(380.0f, 0.0f);
		glVertex2f(380.0f, 480.0f);
		glVertex2f(405.0f, 0.0f);
		glVertex2f(405.0f, 480.0f);
		glVertex2f(430.0f, 0.0f);
		glVertex2f(430.0f, 480.0f);
		glVertex2f(455.0f, 0.0f);
		glVertex2f(455.0f, 480.0f);
		glVertex2f(480.0f, 0.0f);
		glVertex2f(480.0f, 480.0f);
		/*
		* Drawing the Rows
		*/
		glVertex2f(0.0f, 25.0f);
		glVertex2f(500.0f, 25.0f);
		glVertex2f(0.0f, 50.0f);
		glVertex2f(500.0f, 50.0f);
		glVertex2f(0.0f, 75.0f);
		glVertex2f(500.f, 75.0f);
		glVertex2f(0.0f, 100.0f);
		glVertex2f(500.0f, 100.0f);
		glVertex2f(0.0f, 125.0f);
		glVertex2f(500.0f, 125.0f);
		glVertex2f(0.0f, 150.0f);
		glVertex2f(500.0f, 150.0f);
		glVertex2f(0.0f, 175.0f);
		glVertex2f(500.0f, 175.0f);
		glVertex2f(0.0f, 200.0f);
		glVertex2f(500.0f, 200.0f);
		glVertex2f(0.0f, 225.0f);
		glVertex2f(500.0f, 225.0f);
		glVertex2f(0.0f, 250.0f);
		glVertex2f(500.0f, 250.0f);
		glVertex2f(0.0f, 275.0f);
		glVertex2f(500.0f, 275.0f);
		glVertex2f(0.0f, 300.0f);
		glVertex2f(500.0f, 300.0f);
		glVertex2f(0.0f, 325.0f);
		glVertex2f(500.0f, 325.0f);
		glVertex2f(0.0f, 350.0f);
		glVertex2f(500.0f, 350.0f);
		glVertex2f(0.0f, 375.0f);
		glVertex2f(500.0f, 375.0f);
		glVertex2f(0.0f, 400.0f);
		glVertex2f(500.0f, 400.0f);
		glVertex2f(0.0f, 425.0f);
		glVertex2f(500.0f, 425.0f);
		glVertex2f(0.0f, 450.0f);
		glVertex2f(500.0f, 450.0f);
		glVertex2f(0.0f, 475.0f);
		glVertex2f(500.0f, 475.0f);
		glEnd();
	}
}

void drawStartLine()
{
	/*
	* Drawing Starting Line
	*/
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(5.2f, 12.0f, 50.0f, 1.0f);
}

void drawFinishLine()
{
	/*
	* Draw Finishing Line 
	*/
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(450.0f, 480.0f, 495.0f, 468.0f);
}

void collisionDetec(int xPos,int yPos)
{
	/*
	* Collision with cubes detection 
	* 
	*/
	
	if (((xPos >= (int)cordinates[0])&& (xPos <=(int)cordinates[2]))&&((yPos<=(int)cordinates[1])&&(yPos>=(int)cordinates[3])))
	{
		cubeOne = TRUE;
		printf("%s","Possible Collusion - cube 1 ");
	}
	if (((xPos+50 >= (int)cordinates[0]) && (xPos+50 <= (int)cordinates[2])) && ((yPos+25 <= (int)cordinates[1]) && (yPos+25 >= (int)cordinates[3])))
	{
		cubeOne = TRUE;
		printf("%s", "Possible Collusion - cube 1 ");
	}

	if (((xPos >= (int)cordinates[4]) && (xPos <= (int)cordinates[6])) && ((yPos <= (int)cordinates[5]) && (yPos >= (int)cordinates[7])))
	{
		cubeTwo = TRUE;
		printf("%s", "Possible Collusion- Cube 2 ");
	}
	if (((xPos+50 >= (int)cordinates[4]) && (xPos+50 <= (int)cordinates[6])) && ((yPos+25 <= (int)cordinates[5]) && (yPos+25 >= (int)cordinates[7])))
	{
		cubeTwo = TRUE;
		printf("%s", "Possible Collusion- Cube 2 ");
	}

	if (((xPos >= (int)cordinates[8]) && (xPos <= (int)cordinates[10])) && ((yPos <= (int)cordinates[9]) && (yPos >= (int)cordinates[11])))
	{
		cubeThree = TRUE;
		printf("%s", "Possible Collusion- Cube 3 ");
	}
	if (((xPos+50 >= (int)cordinates[8]) && (xPos+50 <= (int)cordinates[10])) && ((yPos+25 <= (int)cordinates[9]) && (yPos+25 >= (int)cordinates[11])))
	{
		cubeThree = TRUE;
		printf("%s", "Possible Collusion- Cube 3 ");
	}

	if (((xPos >= (int)cordinates[12]) && (xPos <= (int)cordinates[14])) && ((yPos <= (int)cordinates[13]) && (yPos >= (int)cordinates[15])))
	{
		cubeFour = TRUE;
		printf("%s", "Possible Collusion- Cube 4 ");
	}
	if (((xPos+50 >= (int)cordinates[12]) && (xPos+50 <= (int)cordinates[14])) && ((yPos+25 <= (int)cordinates[13]) && (yPos+25 >= (int)cordinates[15])))
	{
		cubeFour = TRUE;
		printf("%s", "Possible Collusion- Cube 4 ");
	}

	if (((xPos >= (int)cordinates[16]) && (xPos <= (int)cordinates[18])) && ((yPos <= (int)cordinates[17]) && (yPos >= (int)cordinates[19])))
	{
		cubeFive = TRUE;
		printf("%s", "Possible Collusion- Cube 5");
	}
	if (((xPos+50 >= (int)cordinates[16]) && (xPos+50 <= (int)cordinates[18])) && ((yPos+25 <= (int)cordinates[17]) && (yPos+25 >= (int)cordinates[19])))
	{
		cubeFive = TRUE;
		printf("%s", "Possible Collusion- Cube 5");
	}
}

void squareCordinate(int i)
{
	srand(time(NULL));
	if(i==0)
	{
		cordinates[i] = 50+rand() % (100 - 50+1);
		cordinates[i + 1] =30+ rand() % (100 - 30+1);
		cordinates[i + 2] = cordinates[i] + 50;
		cordinates[i + 3] = cordinates[i + 1] - 50;
		/*if (cordinates[i + 3] < 0)
		{
			int outFrame = 0 - cordinates[i + 3];
			int differVal = 50 - outFrame;
			cordinates[i + 3] = cordinates[i + 1] + outFrame+differVal;
			cordinates[i + 1] = cordinates[i + 3] + outFrame+differVal;

		}*/
	}
	else if (i == 4)
	{
		cordinates[i] = (int)cordinates[i - 2] +rand() % (200 -(int)cordinates[i - 2] +1);
		cordinates[i + 1] = (int)cordinates[i - 3] +rand() % (200 - (int)cordinates[i - 3] +1);
		cordinates[i + 2] = cordinates[i] + 50;
		cordinates[i + 3] = cordinates[i + 1] - 50;
		/*if (cordinates[i + 3] < 100)
		{
			int outFrame = 100 - cordinates[i + 3];
			int differVal = 50 - outFrame;
			cordinates[i + 3] = cordinates[i + 3] - outFrame;
			cordinates[i + 1] = cordinates[i + 1] - outFrame;

		}
		if (cordinates[i + 2] < 200)
		{
			int outFrame = 300 - cordinates[i + 2];
			int differVal = 50 + outFrame;
			cordinates[i + 2] = cordinates[i + 2] - outFrame;
			cordinates[i] = cordinates[i] - outFrame;

		}*/
	}
	else if (i == 8)
	{
		cordinates[i] = (int)cordinates[i - 2] +rand() % (300 - (int)cordinates[i - 2] +1);
		cordinates[i + 1] = (int)cordinates[i - 3] +rand() % (300 - (int)cordinates[i - 3] +1);
		cordinates[i + 2] = cordinates[i] + 50;
		cordinates[i + 3] = cordinates[i + 1] - 50;
		/*if (cordinates[i + 3] < 200)
		{
			int outFrame = 200 - cordinates[i + 3];
			int differVal = 50 - outFrame;
			cordinates[i + 3] = cordinates[i + 3] -outFrame;
			cordinates[i + 1] = cordinates[i + 1] -outFrame;

		}
		if (cordinates[i + 2] < 300)
		{
			int outFrame = 300 - cordinates[i + 2];
			int differVal = 50 + outFrame;
			cordinates[i+2] = cordinates[i+2] - outFrame;
			cordinates[i] = cordinates[i] -outFrame;

		}*/

	}

	else if (i == 12)
	{
		cordinates[i] = (int)cordinates[i - 2] +rand() % (400 - (int)cordinates[i - 2] +1);
		cordinates[i + 1] = (int)cordinates[i - 3] +rand() % (400 - (int)cordinates[i - 3] +1);
		cordinates[i + 2] = cordinates[i] + 50;
		cordinates[i + 3] = cordinates[i + 1] - 50;
		/*if (cordinates[i + 3] < 300)
		{
			int outFrame = 300 - cordinates[i + 3];
			int differVal = 50 - outFrame;
			cordinates[i + 3] = cordinates[i + 1] + outFrame + differVal;
			cordinates[i + 1] = cordinates[i + 3] + outFrame + differVal;

		}*/
	}
	else if (i == 16)
	{
		cordinates[i] = (int)cordinates[i - 2] + rand() % (450 - (int)cordinates[i - 2] + 1);
		cordinates[i + 1] = (int)cordinates[i - 3] + rand() % (460 - (int)cordinates[i - 3] + 1);
		cordinates[i + 2] = cordinates[i] + 50;
		cordinates[i + 3] = cordinates[i + 1] - 50;

	}
	
}
void genObstacles()
{ /*
  * Loading the array with possition data 
  */
	
	for (int i = 0; i < 20; i++)
	{
		squareCordinate(i);
		
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%f\n", cordinates[i]);
	}
	
}
void drawObstacles()
{
	/*
	* Drawing the obstacles
	*/
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(cordinates[0], cordinates[1], cordinates[2], cordinates[3]);
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(cordinates[4], cordinates[5], cordinates[6], cordinates[7]);
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(cordinates[8], cordinates[9], cordinates[10], cordinates[11]);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(cordinates[12], cordinates[13], cordinates[14], cordinates[15]);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRectf(cordinates[16], cordinates[17], cordinates[18], cordinates[19]);

	
}
void drawCar()
{
	/*
	* Drawing a simple object with primitives
	*/
	glColor3f(1.0f, 0.0f, 1.0f);
	glLineWidth(3.0f);
	glBegin(GL_QUADS);
	glVertex2f(5.0f, 25.0f);
	glVertex2f(30.0f, 25.0f);
	glVertex2f(30.0f, 0.0f);
	glVertex2f(5.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(30.0f, 25.0f);
	glVertex2f(50.0f, 12.5f);
	glVertex2f(30.0f, 0.0f);
	glEnd();
	
}

void moveCar(GLfloat xPos, GLfloat yPos)
{
	/*
	* Function called when active positions are changed
	* Re drawing when keyboard input is processed
	*/
	if (xPos > 0 || yPos > 0)
	{
		
		glPushMatrix();
		glTranslatef(xPos, yPos, -1);
		drawCar();
		glPopMatrix();
	}
	else
	{
		drawCar();
	}
}

void rotateCar(GLboolean rotateSatus)
{
	if (rotateSatus == TRUE)
	{
		glPushMatrix();
		glRotatef(90.0f, 0.0f, 0.0f, -1.0f);
		drawCar();
		glPopMatrix();
	}
	rotateSatus = FALSE;
}