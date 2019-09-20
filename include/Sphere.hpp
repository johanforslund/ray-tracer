#pragma once
#include "Geometry.hpp"
#include "Intersection.hpp"

class Sphere : public Geometry {

public:
    Sphere(glm::vec4 _centerPos, double _radius, ColorDbl _color);
    ~Sphere();

    Intersection* rayIntersection(Ray* ray);

private:
    glm::vec4 centerPos;
    double radius;
    ColorDbl color;
};