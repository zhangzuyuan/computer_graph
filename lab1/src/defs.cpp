#include "defs.h"


const string filePath = "./src/data/teapot.obj";
objLoader objModel = objLoader(filePath);

float c = 3.1415926 / 180.0f;
float r = 1.0f;
int degree = 90;
int oldPosX = -1;
int oldPosY = -1;
GLfloat xOffset = 0.0f;
GLfloat yOffset = 0.0f;
GLfloat xscale = 1.0f;
GLfloat yscale = 1.0f;
GLfloat zscale = 1.0f;