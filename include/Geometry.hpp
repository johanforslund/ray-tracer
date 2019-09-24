#pragma once
#include "Ray.hpp"
#include <string>
#include "Material.hpp"

class Intersection;

class Geometry {

public:
    Geometry( Material* _material ) : material(_material){}
    virtual ~Geometry() = default;

    virtual Intersection* rayIntersection(Ray* ray) = 0;
    virtual std::string getName() = 0;

    Material* material;
private:
    
};