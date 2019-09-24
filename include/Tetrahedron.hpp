#pragma once
#include "Geometry.hpp"
#include "Ray.hpp"
#include "Triangle.hpp"
#include "Intersection.hpp"
#include <string>


class Tetrahedron : public Geometry{

public:
    Tetrahedron(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, Material* _material);
    ~Tetrahedron();

    Intersection* rayIntersection(Ray* ray);
    std::string getName();

private:
    Triangle* triangleList[4];
};