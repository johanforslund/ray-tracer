#pragma once
#include "Geometry.hpp"
#include "Ray.hpp"
#include "ColorDbl.hpp"
#include "Triangle.hpp"


class Tetrahedron : public Geometry{

public:
    Tetrahedron(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, ColorDbl _color);
    ~Tetrahedron();

    double rayIntersection(Ray* ray);

private:
    Triangle* triangleList[4];
};