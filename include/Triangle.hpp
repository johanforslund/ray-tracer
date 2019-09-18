#pragma once
#include "ColorDbl.hpp"
#include "Ray.hpp"
#include <glm/glm.hpp>

class Triangle {

public:
    Triangle();

    Triangle(glm::vec4 vertex1, glm::vec4 vertex2, glm::vec4 vertex3, ColorDbl _color, glm::vec3 _normalDirection);
    
    ~Triangle();

    double rayIntersection(Ray* ray);
    ColorDbl color;

private:
    glm::vec4 vertexList[3];
    glm::vec3 normalDirection;
};