#include "operation.h"

void init()
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT); //选择平面明暗模式或光滑明暗模式
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);   //设置机口
	glMatrixMode(GL_PROJECTION);  //指定哪一个矩阵是当前矩阵
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 20);   //创建透视投影矩阵(fovy,aspect,zNear,zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, -1);
}

void display()
{
	int i;
	glFrontFace(GL_CCW);
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);
	for (i = 0; i < n;++i)
	{
		glPushMatrix();  //压栈
		glRotatef((GLfloat)(360 * i / n), 0, 1, 0);  //沿y轴旋转 
		glTranslatef(2, 0, 0); //将场景中的物体沿x轴正方向移动2个单位长
		glRotatef((GLfloat)(360 *i / n), 0, 1, 0);  //沿y轴旋转
		glBegin(GL_POLYGON);
		glEdgeFlag(true);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glEdgeFlag(true);
		glVertex3f(0.5*cos(2 * Pi*i / n), 0.5f, 0.5*sin(2 * Pi*i / n));
		glEdgeFlag(true);
		glVertex3f(0.5*cos(2 * Pi*i / n), -0.5f, 0.5*sin(2 * Pi*i / n));
		glEdgeFlag(true);
		glVertex3f(0.0f, -0.5f, 0.0f);
		glEnd();
		glPopMatrix(); //出栈
	}

	glutSwapBuffers();
	glFlush();   //刷新窗口以显示当前绘制图形
}