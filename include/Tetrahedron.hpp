#pragma once
#include "Geometry.hpp"
#include "Ray.hpp"


class Tetrahedron : public Geometry{

public:
    Tetrahedron();
    ~Tetrahedron();

    double rayIntersection(Ray* ray);

private:
};