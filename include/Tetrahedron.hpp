#pragma once
#include "Geometry.hpp"
#include "Ray.hpp"
#include "ColorDbl.hpp"
#include "Triangle.hpp"
#include "Intersection.hpp"


class Tetrahedron : public Geometry{

public:
    Tetrahedron(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, ColorDbl _color);
    ~Tetrahedron();

    Intersection* rayIntersection(Ray* ray);

private:
    Triangle* triangleList[4];
};