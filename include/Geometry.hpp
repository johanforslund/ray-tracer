#pragma once
#include "Ray.hpp"

class Intersection;

class Geometry {

public:
    Geometry( ColorDbl _color ) : color(_color){}
    virtual ~Geometry() = default;

    virtual Intersection* rayIntersection(Ray* ray) = 0;

    ColorDbl color;
private:
    
};