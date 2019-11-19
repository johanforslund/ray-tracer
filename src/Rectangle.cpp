#include "Rectangle.hpp"

Rectangle::Rectangle(Triangle* tri1, Triangle* tri2, Material* _material) : Geometry(_material) {
    triangleList[0] = tri1;
    triangleList[1] = tri2;
}

Rectangle::~Rectangle() {

}

Intersection* Rectangle::rayIntersection(Ray* ray) {
    Intersection* closestIntersection = nullptr;

    for (int i=0; i<2; i++) {
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

std::string Rectangle::getName() {
    return "Rectangle";
}

void Rectangle::translate(float x, float y, float z) {
    triangleList[0]->translate(x,y,z);
    triangleList[1]->translate(x,y,z);
}