#include "Box.hpp"

Box::Box(Triangle* tri1, Triangle* tri2, Triangle* tri3, Triangle* tri4, Triangle* tri5, Triangle* tri6,
         Triangle* tri7, Triangle* tri8, Triangle* tri9, Triangle* tri10, Triangle* tri11, Triangle* tri12,
         Material* _material) : Geometry(_material) {
    triangleList[0] = tri1;
    triangleList[1] = tri2;
    triangleList[2] = tri3;
    triangleList[3] = tri4;
    triangleList[4] = tri5;
    triangleList[5] = tri6;
    triangleList[6] = tri7;
    triangleList[7] = tri8;
    triangleList[8] = tri9;
    triangleList[9] = tri10;
    triangleList[10] = tri11;
    triangleList[11] = tri12;
}

Box::~Box() {

}

Intersection* Box::rayIntersection(Ray* ray) {
    Intersection* closestIntersection = nullptr;

    for (int i=0; i<12; i++) {
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

std::string Box::getName() {
    return "Box";
}

void Box::translate(float x, float y, float z) {
    for(int i = 0; i < 12; i++) {
        triangleList[i]->translate(x,y,z);
    }
}