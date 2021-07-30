#include <Windows.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>

void tree()
{
	//leaves


	float theta1;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta1 = i * 3.14159 / 180;
		glVertex2f(0.7 + 1.2 * cos(theta1), 2.3 + 1.2 * sin(theta1));
	}
	glEnd();

	float theta2;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta2 = i * 3.14159 / 180;
		glVertex2f(0.7 + 1.0 * cos(theta2), 3.1 + 1.0 * sin(theta2));
	}
	glEnd();

	float theta3;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta3 = i * 3.14159 / 180;
		glVertex2f(0.7 + 0.5 * cos(theta3), 4.2 + 0.5 * sin(theta3));
	}
	glEnd();

	//trunk

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.7, 0.0, 0.0);
	glVertex3f(0.7, 4.0, 0.0);
	glEnd();

	//branches

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.7, 2.0, 0.0);
	glVertex3f(1.7, 2.3, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.7, 2.0, 0.0);
	glVertex3f(-0.3, 2.3, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.7, 3.0, 0.0);
	glVertex3f(1.7, 3.3, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.7, 3.0, 0.0);
	glVertex3f(-0.3, 3.3, 0.0);
	glEnd();
}

void sun()
{
	float theta;
	glColor3f(1, 0.4, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.14159 / 180;
		glVertex2f(2.0 + 0.5*cos(theta), 8.0 + 0.5*sin(theta));
	}
	glEnd();
}

void house()
{
	//body
	glColor3f(1.0, 1.0, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(5.0, 1.0, 0.0);
	glVertex3f(9.0, 1.0, 0.0);
	glVertex3f(9.0, 4.0, 0.0);
	glVertex3f(7.0, 6.5, 0.0);
	glVertex3f(5.0, 4.0, 0.0);
	glEnd();

	//border
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(5.0, 1.0, 0.0);
	glVertex3f(9.0, 1.0, 0.0);
	glVertex3f(9.0, 4.0, 0.0);
	glVertex3f(7.0, 6.0, 0.0);
	glVertex3f(5.0, 4.0, 0.0);
	glEnd();

	//door
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(5.5, 1.0, 0.0);
	glVertex3f(6.5, 1.0, 0.0);
	glVertex3f(6.5, 3.0, 0.0);
	glVertex3f(5.5, 3.0, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);

	glBegin(GL_POINTS);
	glVertex2f(6.4, 2.0);
	glEnd();

	//border
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(5.5, 1.0, 0.0);
	glVertex3f(6.5, 1.0, 0.0);
	glVertex3f(6.5, 3.0, 0.0);
	glVertex3f(5.5, 3.0, 0.0);
	glEnd();

	//window
	float theta;
	glColor3f(0.4, 0.5, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.14159 / 180;
		glVertex2f(8.0 + 0.5 * cos(theta), 2.0 + 0.5 * sin(theta));
	}
	glEnd();

	//roof
	glColor3f(0.0, 1.0, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(7.0, 7.0, 0.0);
	glVertex3f(4.0, 4.0, 0.0);
	glVertex3f(4.5, 3.5, 0.0);
	glVertex3f(7.0, 6.0, 0.0);
	glVertex3f(9.5, 3.5, 0.0);
	glVertex3f(10.0, 4.0, 0.0);
	glEnd();

	//border
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(7.0, 7.0, 0.0);
	glVertex3f(4.0, 4.0, 0.0);
	glVertex3f(4.5, 3.5, 0.0);
	glVertex3f(7.0, 6.0, 0.0);
	glVertex3f(9.5, 3.5, 0.0);
	glVertex3f(10.0, 4.0, 0.0);
	glEnd();
}

void grass()
{

	//base

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(8.4, 0.75, 0.0);
	glVertex3f(8.6, 0.75, 0.0);
	glVertex3f(8.6, 0.85, 0.0);
	glVertex3f(8.4, 0.85, 0.0);
	glEnd();

	//blades

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(8.4, 0.85, 0.0);
	glVertex3f(8.34, 1.07, 0.0);
	glVertex3f(8.2, 1.1, 0.0);
	glVertex3f(8.2, 0.97, 0.0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(8.6, 0.85, 0.0);
	glVertex3f(8.8, 0.97, 0.0);
	glVertex3f(8.8, 1.1, 0.0);
	glVertex3f(8.66, 1.07, 0.0);
	glEnd();
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//tree
	tree();
	glFlush();
	
	//sun
	sun();
	glFlush();

	//house
	house();
	glFlush();

	//grass
	grass();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 11.5, 0, 10);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);

	glutCreateWindow("House");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
}


