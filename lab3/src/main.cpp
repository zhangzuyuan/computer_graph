
#include "operation.h"
#include "defs.h"
using namespace std;

int main(int argc, char* argv[])
{
	//初始化GLUT库
	glutInit(&argc, (char**)argv);
	init();

	glutDisplayFunc(display);
    initialize();
	
	glutMainLoop();
	return 0;
}