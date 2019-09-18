#pragma once
#include "ColorDbl.hpp"
#include <glm/glm.hpp>

class Triangle;

class Ray {

public:
    Ray();
    Ray(glm::vec4 _start, glm::vec4 _end);
    ~Ray();

    glm::vec4 start, end;
    ColorDbl color;
private:
    Triangle* endTriangle;
};