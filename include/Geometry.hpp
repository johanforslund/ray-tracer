#pragma once
#include "Ray.hpp"

class Geometry {

public:
    virtual ~Geometry() = default;

    virtual double rayIntersection(Ray* ray) = 0;

    ColorDbl color;
private:
    
};