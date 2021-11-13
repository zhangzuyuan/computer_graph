#ifndef OPERATION_H
#define OPERATION_H

#include "objLoader.h"
#include "defs.h"
#include<GL/glut.h>
#include<cmath>
#include<iostream>
using namespace std;

extern void setLightRes();
extern void init();
extern void display();
extern void reshape(int, int);
extern void moseMove(int, int, int, int);
extern void changeViewPoint(int, int);
extern void specialKey(GLint, GLint, GLint);
extern void myIdle();

#endif

