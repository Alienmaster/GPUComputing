#pragma once

#include <math.h>
#include <GL/glut.h>
#include <iostream>

#define M_PI           3.14159265358979323846  /* pi */

using namespace std;

int Vertices = 50;
double eyex = 0.0;
double eyey = 2.0;
double eyez = 5.0;

void hourglass() //Dedicated to Pacman <3
{
	int radius = 1;
	double angle = 360 / (Vertices - 1);
	double x = 0;
	double z = 0;
	double HourglassMidpoint[] = { 0, -2, 0, 1.0 };
	GLdouble color[] = { 1.0, 1.0, 0.0, 1.0 }; //Yellow

	glBegin(GL_TRIANGLE_FAN);
	glColor4dv(color);

	glVertex4dv(HourglassMidpoint); //Midpoint hourglass

	for (int i = 0; i <= (Vertices + 2); i++) { //only with +2 the surface is closed

		double ganzerWinkel = i * angle; //Berechnung des Winkels gegen den Uhrzeigersinn von der x-Achse aus.
		x = (cos(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // x
		z = (sin(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // z
		glVertex4d(x, 0, z, 1.0);
	}

	glVertex4dv(HourglassMidpoint);

	for (int i = 0; i <= (Vertices + 2); i++) {

		double ganzerWinkel = i * angle;
		x = (cos(ganzerWinkel * ((M_PI * 2) / 360))) * radius;
		z = (sin(ganzerWinkel * ((M_PI * 2) / 360))) * radius;
		glVertex4d(x, -4, z, 1.0);
	}
	glEnd();
}

void translation() //From local to global Modelmatrix
{
	hourglass();
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