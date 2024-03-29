#include <iostream>
#include "Tetrahedron.hpp"


Tetrahedron::Tetrahedron(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, Material* _material) : Geometry(_material) {
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

std::string Tetrahedron::getName() {
    return "Tetrahedron";
}

void Tetrahedron::translate(float x, float y, float z) {
    triangleList[0]->translate(x,y,z);
    triangleList[1]->translate(x,y,z);
    triangleList[2]->translate(x,y,z);
    triangleList[3]->translate(x,y,z);
}
