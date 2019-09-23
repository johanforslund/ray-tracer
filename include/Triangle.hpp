#pragma once
#include "Color.hpp"
#include "Ray.hpp"
#include <glm/glm.hpp>
#include "Geometry.hpp"
#include "Intersection.hpp"
#include <string>

class Triangle : public Geometry{

public:
    Triangle(glm::vec4 vertex1, glm::vec4 vertex2, glm::vec4 vertex3, Color _color);
    
    ~Triangle();

    Intersection* rayIntersection(Ray* ray);
    std::string getName();

private:
    glm::vec4 vertexList[3];
    glm::vec3 normalDirection;
};