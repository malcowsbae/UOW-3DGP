/*
* 5CCGD003W - Tutorial 6 - PARTB
* An introduction to glut 3D objects
*/
// Code by Dr Anastassia Angelopoulou


#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <iostream>
#include <stdio.h>
#include <math.h>



// Add your Globals here
GLint objID = 1; // Object ID.


// reshape callback function executed when window is moved or resized. 
void reshape(GLsizei w, GLsizei h)
{
	GLfloat fAspect;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Calculate aspect ratio of the window
	fAspect = (GLfloat)w / (GLfloat)h;

	// Set the perspective coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// field of view of 45 degrees, near and far planes 1.0 and 425
	gluPerspective(45.0f, fAspect, 1.0, 600.0);

	// Modelview matrix reset
	glMatrixMode(GL_MODELVIEW);
}


/* display callback function
   called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display()
{
	// Clear the window with current clearing colour
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//	glColor3f(0.0,0.0,1.0);
  
//	glTranslatef(0.0f, 0.0f, -20.0f);

	// Position the objects for viewing.
	gluLookAt(10.00, 0.00, 20.0,//eye
		0.00, 0.00, 0.00,//centre
		0.00, 1.00, 0.00);//up 

	glLineWidth(2.0); // Thicken the wireframes.

   // Save the matrix state 
	glPushMatrix();

	// Draw objects.
	switch (objID)
	{
	case 1:
		glutWireSphere(5.0, 40, 40);
		break;
	case 2:
		glutSolidSphere(5.0, 40, 40);
		break;
	case 3:
		glutWireCone(3.0, 8.0, 30, 30);	
		break;
	case 4:
		glutSolidCone(3.0, 8.0, 30, 30);
		break;
	case 5:
		glutWireTorus(1.0, 4.0, 30, 30);
		break;
	case 6:
		glutSolidTorus(1.0, 4.0, 30, 30);
		break;
	case 7:
		glutWireTeapot(4.0);
		break;
	case 8:
		glutSolidTeapot(4.0);
		break;
	case 9:
		glScalef(5.0, 5.0, 2.0); //octahedron does not take any parameters, have to scale the object
		glutSolidOctahedron();
		break;
	case 10:
		glScalef(5.0, 5.0, 2.0); //octahedron does not take any parameters, have to scale the object
		glutWireOctahedron();
		break;
	case 11:
		glutSolidCube(5.0);
		break;
	case 12:
		glutWireCube(5.0);
		break;
	}

	glPopMatrix();

   glutSwapBuffers();
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN)
	{
		if (objID < 12) objID++;
		else objID = 1;
	}

	if (key == GLUT_KEY_UP)
	{
		if (objID > 1) objID--;
		else objID = 12;
	}

	glutPostRedisplay();
}

void init(void)
{

/* Ignore the lighting properties for the time being
explanation will be given when you do lighting in the lectures*/

	// Material property vectors.
	float matSpec[] = { 0.0, 1.0, 1.0, 1.0 };
	float matShine[] = { 50.0 };
	float matAmbAndDif[] = { 0.0, 0.1, 1.0, 1.0 };

	// Light property vectors.
	float lightAmb[] = { 0.0, 0.1, 1.0, 1.0 };
	float lightDifAndSpec[] = { 0.0, 0.1, 1.0, 1.0 };
	float lightPos[] = { 0.0, 7.0, 3.0, 0.0 };
	float globAmb[] = { 0.4, 0.4, 0.2, 1.0 };

	// Material properties of the objects.
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matAmbAndDif);

	// Light0 properties.
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Poperties of the ambient light.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.

	glEnable(GL_LIGHTING); // Enable lighting calculations.
	glEnable(GL_LIGHT0); // Enable particular light source.
	glEnable(GL_DEPTH_TEST); // Enable depth testing.

	glEnable(GL_NORMALIZE); // Enable automatic normalization of normals.

	glClearColor(0.9, 0.8, 0.5, 1.0);
}

//rename this to main(...) and change example 2 to run this main function
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 500);
	glutCreateWindow("Tutorial 6");
	glutDisplayFunc(display);

	init();
	
	//keyboard interaction
	glutSpecialFunc(specialKeyInput);

	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

