#pragma once
// Aufgabe3.h

#include <GL/glut.h>
#include <iostream>

using namespace std;

double hinge[5] = { 0,0,0,0,0 };
int actualHinge = 0;

int Vertices = 50;
double eyex = 0.0;
double eyey = 2.0;
double eyez = 5.0;
int Displaylist;


void triangle()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(0.5, 1, 0);
	glEnd();
}

void initDisplayList()
{

	int Displaylist = glGenLists(1);
	cout << Displaylist;

	glNewList(Displaylist, GL_COMPILE);
	triangle();
	glEndList();

}

void translation() //From local to global Modelmatrix
{
	GLdouble blue[] = { 0.0, 0.0, 1.0 };
	GLdouble red[] = { 1.0, 0.0, 0.0 };
	GLdouble green[] = { 0.0, 1.0, 0.0 };
	glPushMatrix();
	//cout << Displaylist;
	glRotated(hinge[0], 0, 0, 1); //first object
	glRotated(hinge[1], 0, 1, 0); //first object
	glColor3dv(blue);
	glCallList(1);	//Bekommt aktuell immer eine 0 zurück. Wenn hartkodiert eine 1 eingetragen
					//wird geht es. Displaylist =! Displaylist *shrugg*

	glColor3dv(red); //second object
	glTranslated(1, 0, 0);
	glRotated(hinge[2], 0, 0, 1);
	glCallList(1);

	glColor3dv(green); //third object
	glTranslated(1, 0, 0);
	glRotated(hinge[3], 0, 0, 1);
	glCallList(1);

	glRotated((-hinge[3]), 0, 0, 1);
	glColor3dv(green); //fourth object
	glTranslated(0, 1, 0);
	glRotated(hinge[4], 0, 0, 1);
	glCallList(1);

	glPopMatrix();
	glutSwapBuffers();
}

void ArrowKey(int key, int x, int y)
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

void setActualHinge(int ActHinge)
{
	actualHinge = ActHinge;
	//cout << actualHinge; //Actual Hinge
}

void changeAngle(bool up)
{
	if (up == true && hinge[actualHinge] <= 19)
	{
		hinge[actualHinge]++;
	}
	else if (up == false && hinge[actualHinge] >= -19)
	{
		hinge[actualHinge]--;
	}

	//cout << actualHinge; //Actual Hinge print
}

void pressKey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //ESC
		exit(0);
		break;
	case 43: //+
		changeAngle(true);
		break;
	case 45: //-
		changeAngle(false);
		break;
	case 48: //0
		setActualHinge(0);
		break;
	case 49: //1
		setActualHinge(1);
		break;
	case 50: //2
		setActualHinge(2);
		break;
	case 51: //3
		setActualHinge(3);
		break;
	case 52: //4
		setActualHinge(4);
		break;
	}
	//cout << int(key); //Print key pressed
}