#ifndef OBJLOADER_H
#define OBJLOADER_H

// #pragma once
#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <string>
using namespace std;
class objLoader
{
    public:
        objLoader(string filename);
        void Draw();
    private:
        vector<vector<GLfloat>> vSets;
        vector<vector<GLint>> fvSets;
        vector<vector<GLint>> fvtSets;
	    vector<vector<GLint>> fvnSets;
	    vector<vector<GLfloat>> vnSets;
	    vector<vector<GLfloat>> vtSets;
};

#endif