#pragma once
#include "Geometry.hpp"
#include "Material.hpp"
#include "Intersection.hpp"
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Sphere : public Geometry {

public:
    Sphere(glm::vec4 _centerPos, float _radius, Material* _material);
    ~Sphere();

    Intersection* rayIntersection(Ray* ray);
    std::string getName();
    void translate(float x, float y, float z);


private:
    glm::vec4 centerPos;
    float radius;
};