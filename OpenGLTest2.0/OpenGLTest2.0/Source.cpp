#include <Windows.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>


void arc_left(float theta)
{
	float _theta;
	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	for (int i = 0; i < theta; i++)
	{
		_theta = i * 3.14159 / 180;
		glVertex2f(-1.4 + 1.382 * cos(_theta), 1 + 1.382 * sin(_theta));
	}
	glEnd();
}

void arc_right(float theta)
{
	float _theta;
	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	for (int i = 0; i < theta; i++)
	{
		_theta = i * 3.14159 / 180;
		glVertex2f(1.4 + 1.382 * cos(_theta), 1 + 1.382 * sin(_theta));
	}
	glEnd();
}


float angle = 0;

void face()
{
	//left outer ear


	float theta1;
	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	for (int i = 52.78; i < 265; i++)
	{
		theta1 = i * 3.14159 / 180;
		glVertex2f(-4.66 + 2.74 * cos(theta1), 1.82 + 2.74 * sin(theta1));
	}
	glEnd();


	//left inner ear


	float theta2;
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	for (float i = 56.39; i < 261.84; i += 0.01)
	{
		theta2 = i * 3.14159 / 180;
		glVertex2f(-4.66 + 2.13 * cos(theta2), 1.82 + 2.13 * sin(theta2));
	}
	glEnd();


	//right outer ear


	float theta3;
	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	for (int i = -95; i < 127.22; i++)
	{
		theta3 = i * 3.14159 / 180;
		glVertex2f(4.66 + 2.74 * cos(theta3), 1.82 + 2.74 * sin(theta3));
	}
	glEnd();


	//right inner ear


	float theta4;
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.01)
	{
		theta4 = i * 3.14159 / 180;
		glVertex2f(4.66 + 2.13 * cos(theta4), 1.82 + 2.13 * sin(theta4));
	}
	glEnd();


	//irregular shape on top


	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 5.0, 0.0);
	glVertex3f(-1.2, 6.0, 0.0);
	glVertex3f(-2.29, 4.45, 0.0);
	glEnd();

	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	glVertex3f(2.34, 4.42, 0.0);
	glVertex3f(1.7, 5.65, 0.0);
	glVertex3f(1.05, 4.89, 0.0);
	glEnd();


	//main body


	float theta5;
	glColor3f(0.72, 0.89, 0.99);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta5 = i * 3.14159 / 180;
		glVertex2f(5 * cos(theta5), 5 * sin(theta5));
	}
	glEnd();


	//eyes


	float theta6;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta6 = i * 3.14159 / 180;
		glVertex2f(-1.4 + 1.382 * cos(theta6), 1 + 1.382 * sin(theta6));
	}
	glEnd();

	float theta7;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta7 = i * 3.14159 / 180;
		glVertex2f(1.4 + 1.382 * cos(theta7), 1 + 1.382 * sin(theta7));
	}
	glEnd();


	//eye balls


	float theta8;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta8 = i * 3.14159 / 180;
		glVertex2f(-1.4 + 0.458 * cos(theta8), 1 + 0.458 * sin(theta8));
	}
	glEnd();

	float theta9;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta9 = i * 3.14159 / 180;
		glVertex2f(1.4 + 0.458 * cos(theta9), 1 + 0.458 * sin(theta9));
	}
	glEnd();

	//eye lids

	arc_left(angle);
	arc_right(angle);

	//nose


	float theta10;
	glColor3f(1.0, 0.65, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++)
	{
		theta10 = i * 3.14159 / 180;
		glVertex2f(0.8 * cos(theta10), -0.25 + 0.8 * sin(theta10));
	}
	glEnd();

	glColor3f(1.0, 0.65, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.8, -0.25, 0.0);
	glVertex3f(-0.8, -0.25, 0.0);
	glVertex3f(-0.8, -2.0, 0.0);
	glVertex3f(0.8, -2.0, 0.0);
	glEnd();

	float theta11;
	glColor3f(1.0, 0.65, 0.0);
	glBegin(GL_POLYGON);
	for (int i = -180; i < 0; i++)
	{
		theta11 = i * 3.14159 / 180;
		glVertex2f(0.8 * cos(theta11), -2 + 0.8 * sin(theta11));
	}
	glEnd();
}

int state = 1;

void display()
{
	glClearColor(0.53, 0.81, 0.92, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();


	//face

	face();
	glutSwapBuffers();
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 25, timer, 0);

	switch (state)
	{
	case 1:
		if (angle < 360)
		{
			angle += 180;
		}
		else
			state = -1;
		break;
	case -1:
		if (angle > 0)
		{
			angle -= 180;
		}
		else
			state = 1;
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);

	glutCreateWindow("Face");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000, timer, 0);

	glutMainLoop();
}


