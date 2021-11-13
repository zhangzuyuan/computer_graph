#ifndef OPERATION_H
#define OPERATION_H
#include "defs.h"
#include<Windows.h>
#include<GL/glut.h>
#include<cmath>
#include<iostream>
using namespace std;

extern void init();
extern void InitGL(int, int);
extern void ReSizeGLScene(int, int);
extern void DrawBody();
extern void DrawShoulder();
extern void DrawHip();
extern void DrawArmA();
extern void DrawArmB();
extern void DrawLegB();
extern void DrawLegA();
extern void DrawHead();
extern void DrawNeck();
extern void DrawGLScene();
extern void keyPressed(unsigned char, int, int);

#endif

