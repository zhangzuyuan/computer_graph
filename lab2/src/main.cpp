#include "operation.h"
#include "defs.h"
using namespace std;

int main(int argc, char* argv[])
{
	//初始化GLUT库
	glutInit(&argc, (char**)argv);
	init();
	//glEnable(GL_COLOR_MATERIAL);

	//设置展示的回调方法
	glutDisplayFunc(&DrawGLScene);/* Register the function to do all our OpenGL drawing. */
	glutIdleFunc(&DrawGLScene);/* Even if there are no events, redraw our gl scene. */
	glutReshapeFunc(&ReSizeGLScene);/* Register the function called when our window is resized. */
	glutKeyboardFunc(&keyPressed);

	InitGL(640, 480);
	//绘制线程开始循环
	glutMainLoop();
	return 0;
}