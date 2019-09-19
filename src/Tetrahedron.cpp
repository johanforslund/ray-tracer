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

double Tetrahedron::rayIntersection(Ray* ray) {
    double minT = 10000000;

    for (int i=0; i<4; i++) {
        double t = triangleList[i]->rayIntersection(ray);
        if (t < minT && t >= 0) minT = t;
    }
    return minT;
}
 