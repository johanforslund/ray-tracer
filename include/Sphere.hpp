#pragma once
#include "Geometry.hpp"
#include "Intersection.hpp"
#include <iostream>

class Sphere : public Geometry {

public:
    Sphere(glm::vec4 _centerPos, float _radius, Color _color);
    ~Sphere();

    Intersection* rayIntersection(Ray* ray);

private:
    glm::vec4 centerPos;
    float radius;
    Color color;
};