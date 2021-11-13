#ifndef OPERATION_H
#define OPERATION_H


#include "defs.h"
#include "Point.h"
#include <Windows.h>
#include<GL/glut.h>
#include<cmath>
#include<iostream>
using namespace std;

extern void init();
extern void setPoint(Point);//绘制点
extern void setLine(Point, Point);//绘制直线
extern Point setBezier(Point, Point, Point, Point, double);//绘制贝塞尔曲线
extern void display();//display 函数
extern void mouseFunction(int,int,int,int);//鼠标事件


#endif

