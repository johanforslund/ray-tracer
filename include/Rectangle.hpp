#pragma once
#include <glm/glm.hpp>
#include "Geometry.hpp"
#include "Triangle.hpp"

class Rectangle : public Geometry{

public:
    Rectangle(Triangle* tri1, Triangle* tri2, Material* _material);

    ~Rectangle();

    Intersection* rayIntersection(Ray* ray);
    std::string getName();
    void translate(float x, float y, float z);

    Triangle* triangleList[2];
};