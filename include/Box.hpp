#pragma once
#include "Geometry.hpp"
#include "Ray.hpp"
#include "Triangle.hpp"
#include "Intersection.hpp"
#include <string>

class Box : public Geometry{

public:
     Box(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, Triangle* tri5, Triangle* tri6,
         Triangle* tri7, Triangle* tri8, Triangle* tri9, Triangle* tri10, Triangle* tri11, Triangle* tri12,
         Material* _material);
    ~Box();

    Intersection* rayIntersection(Ray* ray);
    std::string getName();
    void translate(float x, float y, float z);


private:
    Triangle* triangleList[12];
};