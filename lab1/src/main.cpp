#include "objLoader.h"
#include "operation.h"
#include "defs.h"
using namespace std;

int main(int argc, char* argv[])
{
	//初始化GLUT库
	glutInit(&argc, (char**)argv);
	init();
	glEnable(GL_COLOR_MATERIAL);
	//设置展示的回调方法
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//设置鼠标事件回调方法
	glutMouseFunc(moseMove);
	
	glutMotionFunc(changeViewPoint);
	//键盘上下左右
	glutSpecialFunc(specialKey);
	glutIdleFunc(myIdle);
	//绘制线程开始循环
	glutMainLoop();
	return 0;
}