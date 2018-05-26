#pragma once
// Aufgabe3.h

#include <GL/glut.h>
#include <iostream>

using namespace std;

double hinge1 = 0.0;
double hinge2 = 0.0;
double hinge3 = 0.0;
double hinge4 = 0.0;
int actualHinge = 0;

int Vertices = 50;
double eyex = 0.0;
double eyey = 2.0;
double eyez = 5.0;
int Displaylist;


void triangle()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex4d(0, 0, 1.0, 1.0);
	glVertex4d(1, 0, 1.0, 1.0);
	glVertex4d(0.5, 1, 1.0, 1.0);
	glEnd();
}

void initDisplayList()
{

	int Displaylist = glGenLists(1);
	cout << Displaylist;

	glNewList(Displaylist, GL_COMPILE_AND_EXECUTE);
	triangle();
	glEndList();

}

void translation() //From local to global Modelmatrix
{
	GLdouble blue[] = { 0.0, 0.0, 1.0, 1.0 };
	GLdouble red[] = { 1.0, 0.0, 0.0, 1.0 };
	GLdouble green[] = { 0.0, 1.0, 0.0, 1.0 };
	glPushMatrix();
	//cout << Displaylist;
	glRotated(hinge1, 0, 0, 1); //first object
	glColor4dv(blue);
	glCallList(1);	//Bekommt aktuell immer eine 0 zurück. Wenn hartkodiert eine 1 eingetragen
					//wird geht es. Displaylist =! Displaylist *shrugg*

	glColor4dv(red); //second object
	glTranslated(1, 0, 0);
	glRotated(hinge2, 0, 0, 1);
	glCallList(1);

	glColor4dv(green); //third object
	glTranslated(1, 0, 0);
	glRotated(hinge3, 0, 0, 1);
	glCallList(1);
	//glRotated((hinge3 - 1), 0, 0, 1);
	glColor4dv(green); //fourth object
	glTranslated(0, 1, 0);
	glRotated(hinge4, 0, 0, 1);
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

void setActualHinge(int hinge)
{
	cout << actualHinge; //Actual Hinge
	actualHinge = hinge;
	
}

void changeAngle(bool up)
{
	if (actualHinge == 1)
	{
		if (up == true && hinge1 <= 44)
		{
			hinge1++;
		}
		else if (up == false && hinge1 >= -45)
		{
			hinge1--;
		}
	}
	if (actualHinge == 2)
	{
		if (up == true && hinge2 <= 44)
		{
			hinge2++;
		}
		else if (up == false && hinge2 >= -45)
		{
			hinge2--;
		}
	}
	if (actualHinge == 3)
	{
		if (up == true && hinge3 <= 44)
		{
			hinge3++;
		}
		else if (up == false && hinge3 >= -45)
		{
			hinge3--;
		}
	}
	if (actualHinge == 4)
	{
		if (up == true && hinge4 <= 44)
		{
			hinge4++;
		}
		else if (up == false && hinge4 >= -45)
		{
			hinge4--;
		}
	}
	cout << actualHinge; //Actual Hinge
}

void printKey(unsigned char key, int x, int y)
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