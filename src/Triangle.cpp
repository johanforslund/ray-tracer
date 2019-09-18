#include <iostream>
#include "Triangle.hpp"

Triangle::Triangle() {

}

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl _color, Direction _normalDirection) {
    vertexList[0] = v1;
    vertexList[1] = v2;
    vertexList[2] = v3;
    color = _color;
    normalDirection = _normalDirection;
}

Triangle::~Triangle() {

}

void Triangle::rayIntersection(Ray ray) {
    std::cout << "intersect" << std::endl;
}