#include "operation.h"

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);   //设置机口
	glMatrixMode(GL_PROJECTION);  //指定哪一个矩阵是当前矩阵
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 20);   //创建透视投影矩阵(fovy,aspect,zNear,zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 2.5, 2.5, 0, 0, 0, 0, 1, -1);
}

void display()
{
	int i;
	glFrontFace(GL_CCW);
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	for (i = 0; i < n;++i)
	{
		glEdgeFlag(true);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glEdgeFlag(true);
		glVertex3f(cos(2 * Pi*i / n), 1.0f, sin(2 * Pi*i / n));
		glEdgeFlag(true);
		glVertex3f(cos(2 * Pi*i / n), -1.0f, sin(2 * Pi*i / n));
		glEdgeFlag(false);
		glVertex3f(0.0f, -1.0f, 0.0f);
	}

	glEnd();
	glFlush();
}