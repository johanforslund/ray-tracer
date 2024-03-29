#pragma once
#include "Color.hpp"
#include "Ray.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Geometry.hpp"
#include "Intersection.hpp"
#include <string>


class Triangle : public Geometry{

public:
    Triangle(glm::vec4 vertex1, glm::vec4 vertex2, glm::vec4 vertex3, Material* _material);
    
    ~Triangle();

    Intersection* rayIntersection(Ray* ray);
    std::string getName();
    void translate(float x, float y, float z);


private:
    glm::vec4 vertexList[3];
    glm::vec3 normalDirection;
};