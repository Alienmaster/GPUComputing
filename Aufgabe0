// vierzehn.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

static GLfloat spin = 0.0;
double eyex = 0.0;
double eyez = 15.0;
int numberOfVertices = 20;

void drawHourglass()
{
	glBegin(GL_TRIANGLE_FAN);
	GLdouble color[] = { 1.0, 1.0, 0.0 };
	glColor3dv(color);
	float radius = 20;
	double winkel = 360.0 / (numberOfVertices - 1);
	double x = 0;
	double y = 0;
	for (int i = 0; i < numberOfVertices; i++) {
		double ganzerWinkel = i * winkel; //Berechnung des Winkels gegen den Uhrzeigersinn von der x-Achse aus.
		x = (cos(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // x
		y = (sin(ganzerWinkel * ((M_PI * 2) / 360))) * radius;  // y
		glVertex4d(x, y, 0.0, 1.0);
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
	glColor3d(1.0, 1.0, 1.0);
	drawHourglass();
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
	gluPerspective(115.0, (GLdouble)w / h, 1.0, 100.0);

}

void idleFunc()
//Camera Position
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, 0.0, eyez, //eye
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
	cout << key;
}

void printKey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27 : exit(0); // ESC
		break;
	case 43 : numberOfVertices++; // +
		break;
	case 45 : numberOfVertices--; // -
		break;
	}
	cout << int(key);
}

int _tmain(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hallo Welt");
	glutDisplayFunc(redisplay);
	glutReshapeFunc(reshape);
	glutIdleFunc(idleFunc);
	glutSpecialFunc(printArrowKey);
	glutKeyboardFunc(printKey);
	glutMainLoop();

	return 0;
}
