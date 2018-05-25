#pragma once
// Aufgabe3.h

#include <GL/glut.h>
#include <iostream>

using namespace std;

static GLfloat spin = 0.0;
double transA = 0.0;
double transB = 0.0;
int Vertices = 50;


void triangle(GLdouble color[])
{
	glBegin(GL_TRIANGLE_FAN);
	glColor4dv(color);
	glVertex4d(0, 0, 1.0, 1.0);
	glVertex4d(1, 0, 1.0, 1.0);
	glVertex4d(0.5, 1, 1.0, 1.0);
	glEnd();
}

void translation() //From local to global Modelmatrix
{
	glPushMatrix();
	glTranslated(3, 4, 4);
	GLdouble color[] = { 1.0, 0.5, 0.0, 1.0 };
	triangle(color);
	glPopMatrix();
	// first Object
	glPushMatrix();
	glTranslated(3, 4, 4);
	triangle(color);
	glPopMatrix();
	// second Object
	glPushMatrix();
	glTranslated(1, transA, 3);
	glRotatef(30, 0, 1, 0);
	glScalef(2, 2, 2);
	triangle(color);
	glTranslated(transA, 0, 3);
	glRotatef(30, 0, 1, 0);
	glScalef(2, 2, 2);
	triangle(color);
	glPopMatrix();
	glutSwapBuffers();
}

void redisplay(void) // Would like to get this function into the cpp File :)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor4d(1.0, 1.0, 1.0, 1.0);
	translation();
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
	case 97: // a
		transA++;
		break;
	}
	cout << int(key); //Print key pressed
}