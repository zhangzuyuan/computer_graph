#include "SceneObject.h"

glm::vec3 SceneObject::getColor()
{
    return this->color;
}

void SceneObject::setColor(glm::vec3 col)
{
    this->color = col;
}