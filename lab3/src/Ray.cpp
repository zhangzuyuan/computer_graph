#include "Ray.h"

//Normalizes the direction vector of the current ray to a unit vector
//将当前射线的方向向量归一化为单位向量
void Ray::normalize()
{
    dir = glm::normalize(dir);
}

//Finds the closest point of intersection of the current ray with scene objects
//找到当前光线与场景物体最近的交点
void Ray::closestPt(std::vector<SceneObject*> &sceneObjects)
{
    glm::vec3 point(0, 0, 0);
    float min = 1.e+6;
    for (int i = 0; i < (int)sceneObjects.size();++i)
    {
        float t = sceneObjects[i]->intersect(pt, dir);
        if(t>0)//Intersects the object/ /相交的对象
        {
            point = pt + dir * t;
            if(t<min)
            {
                this->xpt = point;
                this->xindex = i;
                this->xdist = t;
                min = t;
            }
        }
    }
}