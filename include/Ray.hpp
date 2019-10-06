#pragma once
#include "Color.hpp"
#include <glm/glm.hpp>

class Triangle;

class Ray {

public:
    Ray();
    Ray(glm::vec3 _start, glm::vec3 _end, Ray* _parent, bool _isInObject = false, float _importance = 0);
    ~Ray();

    glm::vec3 getVec3();
    glm::vec4 getVec4();

    Ray* parent;
    glm::vec4 start, end;
    Color color;
    float importance;
    bool isInObject;
private:
    Triangle* endTriangle;
};