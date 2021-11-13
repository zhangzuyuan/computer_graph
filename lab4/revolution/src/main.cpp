
#include "operation.h"
#include "defs.h"
using namespace std;

int main(int argc, char* argv[])
{
	//初始化GLUT库
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//缓存模式
	//设置窗口大小
    glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);//确定显示框左上角的位置
	//创建窗口
    glutCreateWindow("revolution");

	glutDisplayFunc(display); //执行显示
	glutReshapeFunc(reshape);

	//绘制线程开始循环 进人GLUT事件处理循环
	glutMainLoop();
	return 0;
}