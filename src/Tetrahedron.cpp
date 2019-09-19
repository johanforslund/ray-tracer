#include <iostream>
#include "Tetrahedron.hpp"


Tetrahedron::Tetrahedron(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, ColorDbl _color) : Geometry(_color) {
    triangleList[0] = tri1;
    triangleList[1] = tri2;
    triangleList[2] = tri3;
    triangleList[3] = tri4;
}

Tetrahedron::~Tetrahedron() {
    // Clear triangleList
}

Intersection* Tetrahedron::rayIntersection(Ray* ray) {
    Intersection* closestIntersection = nullptr;

    for (int i=0; i<4; i++) {
        Intersection* intersection = triangleList[i]->rayIntersection(ray);
        if (closestIntersection == nullptr && intersection != nullptr) {
            closestIntersection = intersection;
        }
        else if (intersection != nullptr && closestIntersection != nullptr && 
                intersection->t < closestIntersection->t && intersection->t >= 0) {
            closestIntersection = intersection;
        } 
    }
    return closestIntersection;
}
 