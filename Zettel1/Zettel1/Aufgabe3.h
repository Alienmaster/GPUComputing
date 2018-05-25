#pragma once
// Aufgabe3.h

#include <GL/glut.h>
#include <iostream>

using namespace std;

double transA = 0.0;
double transB = 0.0;
int Vertices = 50;
double eyex = 0.0;
double eyey = 2.0;
double eyez = 5.0;
int Displaylist;


void triangle(GLdouble color[])
{
	glBegin(GL_TRIANGLE_FAN);
	glColor4dv(color);
	glVertex4d(0, 0, 1.0, 1.0);
	glVertex4d(1, 0, 1.0, 1.0);
	glVertex4d(0.5, 1, 1.0, 1.0);
	glEnd();
}

void initDisplayList()
{
	GLdouble blue[] = { 0.0, 0.0, 1.0, 1.0 };
	
	int Displaylist = glGenLists(1);
	cout << Displaylist;
	
	glNewList(Displaylist, GL_COMPILE);
	
	glPushMatrix();
	glRotatef(transA, 0, 0, 1);
	glTranslated(0, 0, 0);
	triangle(blue);
	glPopMatrix();
	glEndList();

}

void translation() //From local to global Modelmatrix
{
	GLdouble blue[] = { 0.0, 0.0, 1.0, 1.0 };
	GLdouble red[] = { 1.0, 0.0, 0.0, 1.0 };
	GLdouble green[] = { 0.0, 1.0, 0.0, 1.0 };
	glPushMatrix();
	cout << Displaylist;
	glCallList(1);	//Bekommt aktuell immer eine 0 zurück. Wenn hartkodiert eine 1 eingetragen
					//wird geht es. Displaylist =! Displaylist *shrugg*
	////first Object
	//glPushMatrix();
	//glRotatef(transA, 0, 0, 1);
	//glTranslated(0, 0, 0);
	//triangle(blue);
	//glPopMatrix();

	////second Object
	//glPushMatrix();
	//glTranslated(4, 4, 4);
	//triangle(red);
	//glPopMatrix();

	////third and fourth Object
	//glPushMatrix();
	//glTranslated(1, 0, 3);
	//glRotatef(30, 0, 1, 0);
	//glScalef(2, 2, 2);
	//triangle(green);
	//glTranslated(0, 0, 3);
	//glRotatef(30, 0, 1, 0);
	//glScalef(2, 2, 2);
	//triangle(green);
	glPopMatrix();
	glutSwapBuffers();
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
	case 27: //ESC
		exit(0);
		break;
	case 43: //+
		if (Vertices < 50)
		{
			Vertices++;
		}
		break;
	case 45: //-
		if (Vertices > 4)
		{
			Vertices--;
		}
		break;
	case 97: //a
		transA++;
		break;
	case 115: //s
		transA--;
		break;
	}
	cout << int(key); //Print key pressed
}