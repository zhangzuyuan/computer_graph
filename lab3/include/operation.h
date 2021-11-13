#ifndef OPERATION_H
#define OPERATION_H

#include "defs.h"
#include "Ray.h"
#include "Plane.h"
#include "Cylinder.h"
#include "Sphere.h"
#include<Windows.h>
#include<GL/glut.h>
#include<cmath>
#include<iostream>
using namespace std;

extern void init();
extern glm::vec3 proceduralTexture(Ray, float, float, float, glm::vec3, glm::vec3, glm::vec3);
extern glm::vec3 trace(Ray, int);
extern void display();
extern void createSpheres();
extern void createFloor();
extern void createBox();
extern void initialize();

#endif

