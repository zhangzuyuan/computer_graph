#include "operation.h"

void setLightRes()
{
    GLfloat lightPosition[] ={ 0.0f, 0.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
void init()
{
	//设置双缓冲，RGB像素格式的窗口
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//设置窗口大小
    glutInitWindowSize(1440, 768);
	//创建窗口
    glutCreateWindow("Teapot");
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    setLightRes();
    glEnable(GL_DEPTH_TEST);
}

void display()
{
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	//清理颜色缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	setLightRes();
	//将当前矩阵压入栈中保存
	glPushMatrix();
	//平移变换
	glTranslatef(xOffset,yOffset,0.0);
	//伸缩变换
	glScalef(xscale,yscale,1.0f);
	//摄像机镜头
    gluLookAt(r*cos(c*degree) , 0, r*sin(c*degree) , 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	
	objModel.Draw();
	//还原绘制变换前的矩阵
	glPopMatrix();
	//交换缓冲区，将正在显示的颜色缓冲区和正在绘制的颜色缓冲区数据交换
	glutSwapBuffers();
}

void reshape(int width,int height)
{
	//设置视口矩形区域，在默认情况下，视口被设置为占据打开窗口的整个像素矩形
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	//对投影矩阵应用随后的矩阵操作
	glMatrixMode(GL_PROJECTION);
	//等于是将之前矩阵变换导致变化过的栈顶矩阵重新归位，置为单位矩阵！等于是之前的矩阵变换带来的影响到此为止了！
	glLoadIdentity();
	// //设置裁剪坐标系
    // glOrtho(60.0f, (GLdouble)width / (GLdouble)height, -50.0f, 50.0f, -1.0f, 1.0f);
	gluPerspective(60.0f, (GLdouble)width / (GLdouble)height, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

void moseMove(int button,int state,int x,int y)
{
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		cout << oldPosX << " " << oldPosX << endl;
		oldPosX = x; oldPosY = y;
	}
	//这是滚轮事件
	else if (state == GLUT_UP && button == GLUT_MIDDLE_BUTTON) // It's a wheel event
   	{
		xscale += 0.008f;
		yscale += 0.008f;
		cout << "wheel" << endl;
	}
	else if(state == GLUT_UP && button == GLUT_MIDDLE_BUTTON)
	{  // normal button event
		xscale -= 0.008f;
		yscale -= 0.008f;
   	}
}


void changeViewPoint(int x,int y)
{
	
	int temp = x - oldPosX;
	degree += temp;
	cout <<degree << endl;
	oldPosX = x;
	oldPosY = y;
	glutPostRedisplay();
}

void specialKey(GLint key,GLint x,GLint y)
{
	if(key==GLUT_KEY_UP)
	{
		yOffset+=0.1;
	}	
	if(key==GLUT_KEY_LEFT)
	{
		xOffset-=0.1;
	}
	if(key==GLUT_KEY_DOWN)
	{
		yOffset-=0.1;
	}
	if(key==GLUT_KEY_RIGHT)
	{
		xOffset+=0.1;
	}

	cout << xOffset << " " << yOffset << endl;
	glutPostRedisplay();
}


void myIdle()
{
    glutPostRedisplay();
}