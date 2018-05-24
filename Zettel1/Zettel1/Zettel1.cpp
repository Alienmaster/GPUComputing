// Zettel1.cpp
//

#include "stdafx.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

static GLfloat spin = 0.0;
double eyex = 0.0;
double eyey = 2.0;
double eyez = 15.0;
int Vertices = 50;
char WindowName[] = { "Hallo Pacman" }; //Window Name

void Hourglass() //Dedicated to Pacman. <3
{
	int radius = 10;
	double angle = 360 / (Vertices - 1);
	double x = 0;
	double z = 0;
	double HourglassMidpoint[] = { 0, -10, 0, 1.0 };
	GLdouble color[] = { 1.0, 1.0, 0.0, 1.0 }; //Yellow

	glBegin(GL_TRIANGLE_FAN);
	glColor4dv(color);

	glVertex4dv(HourglassMidpoint); //Midpoint hourglass

	for (int i = 0; i <= (Vertices +2); i++) { //only with +2 the surface is closed

		double ganzerWinkel = i * angle; //Berechnung des Winkels gegen den Uhrzeigersinn von der x-Achse aus.
		x = (cos(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // x
		z = (sin(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // z
		glVertex4d(x, 10, z, 1.0);

	}

	glVertex4dv(HourglassMidpoint); // Midpoint hourglass

	for (int i = 0; i <= (Vertices +2); i++) {

		double ganzerWinkel = i * angle; //Berechnung des Winkels gegen den Uhrzeigersinn von der x-Achse aus.
		x = (cos(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // x
		z = (sin(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // z
		glVertex4d(x, -30, z, 1.0);
	}

	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void redisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor4d(1.0, 1.0, 1.0, 1.0);
	Hourglass();
}

//void spindisplay(void)
//{
//	spin = spin + 2.0;
//	if (spin > 360.0) spin = spin - 360.0;
//	glutPostRedisplay();
//}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(215.0, (GLdouble)w / h, 1.0, 100.0);

}

void idleFunc() //Camera Position
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, //eye
		0.0, 0.0, 0.0, //center
		0.0, 1.0, 0.0); //up
	glutPostRedisplay();
}

void printArrowKey(int key, int x, int y)
{
	switch (key)
	{
	case 100: eyex++; // Left Arrow
		break;
	case 102: eyex--; // Right Arrow
		break;
	case 103: eyez++; // Down Arrow
		break;
	case 101: eyez--; // Up Arrow
	}
	cout << key; // Print key pressed
}

void printKey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // ESC
		exit(0);
		break;
	case 43: // +
		if (Vertices < 50)
		{
			Vertices++;
		}
		break;
	case 45: // -
		if (Vertices > 4)
		{
			Vertices--;
		}
		break;
	}
	cout << int(key); //Print key pressed
}

int _tmain(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(WindowName);
	glutDisplayFunc(redisplay);
	glutReshapeFunc(reshape);
	glutIdleFunc(idleFunc);
	glutSpecialFunc(printArrowKey);
	glutKeyboardFunc(printKey);
	glutMainLoop();

	return 0;
}