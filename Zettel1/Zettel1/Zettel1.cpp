// Zettel1.cpp
//

#include "stdafx.h"
#include <iostream>
#include <GL/glut.h>
#include "Aufgabe2.h"

using namespace std;

static GLfloat spin = 0.0;

char WindowName[] = { "Hallo Pacman" }; //Window Name

void redisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor4d(1.0, 1.0, 1.0, 1.0);
	hourglass();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLdouble)w / h, 1.0, 100.0);
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