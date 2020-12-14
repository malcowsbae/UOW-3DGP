#pragma once
//Function Declarations 
extern int totalScore;
void writeBitmapString(void* font, char* string);
void writeScore();
void drawContainer();
void drawGrid(bool option);
void drawStartLine();
void drawFinishLine();
void drawObstacles();
void genObstacles();
void drawCar();
void moveCar(GLfloat xPos, GLfloat yPos);
void rotateCar(GLboolean rotateSatus);
void collisionDetec(int xPos, int yPos);