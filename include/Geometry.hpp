#pragma once
#include "Ray.hpp"

class Intersection;

class Geometry {

public:
    Geometry( Color _color ) : color(_color){}
    virtual ~Geometry() = default;

    virtual Intersection* rayIntersection(Ray* ray) = 0;

    Color color;
private:
    
};