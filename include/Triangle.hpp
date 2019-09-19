#pragma once
#include "ColorDbl.hpp"
#include "Ray.hpp"
#include <glm/glm.hpp>
#include "Geometry.hpp"

class Triangle : public Geometry{

public:
    Triangle(glm::vec4 vertex1, glm::vec4 vertex2, glm::vec4 vertex3, ColorDbl _color);
    
    ~Triangle();

    double rayIntersection(Ray* ray);

private:
    glm::vec4 vertexList[3];
    glm::vec3 normalDirection;
};