#pragma once
#include "Ray.hpp"

class Geometry {

public:
    Geometry( ColorDbl _color ) : color(_color){}
    virtual ~Geometry() = default;

    virtual double rayIntersection(Ray* ray) = 0;

    ColorDbl color;
private:
    
};