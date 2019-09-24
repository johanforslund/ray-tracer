#pragma once
#include "Color.hpp"
#include <glm/glm.hpp>

class Triangle;

class Ray {

public:
    Ray();
    Ray(glm::vec4 _start, glm::vec4 _end, Ray* _parent);
    ~Ray();

    glm::vec3 getVec3();
    glm::vec4 getVec4();

    Ray* parent;
    glm::vec4 start, end;
    Color color;
private:
    Triangle* endTriangle;
};