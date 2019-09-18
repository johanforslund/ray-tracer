#include <iostream>
#include "Triangle.hpp"

Triangle::Triangle() {

}

Triangle::Triangle(glm::vec4 vertex1, glm::vec4 vertex2, glm::vec4 vertex3, ColorDbl _color, glm::vec3 _normalDirection) {
    vertexList[0] = vertex1;
    vertexList[1] = vertex2;
    vertexList[2] = vertex3;
    color = _color;
    normalDirection = _normalDirection;
}

Triangle::~Triangle() {

}

double Triangle::rayIntersection(Ray* ray) {
    // if (glm::dot(glm::vec3((ray->end - ray->start)), normalDirection) > 0) return -1; // Could maybe not work

    glm::vec3 T = ray->start - vertexList[0];
    glm::vec3 E1 = vertexList[1] - vertexList[0];
    glm::vec3 E2 = vertexList[2] - vertexList[0];
    glm::vec3 D = glm::normalize(ray->end - ray->start);
    glm::vec3 P = glm::cross(D, E2);
    glm::vec3 Q = glm::cross(T, E1);

    float t = (glm::dot(Q, E2))/(glm::dot(P, E1));
    return t;
    
    glm::vec3 intersectionPoint = ray->start + t*(ray->end - ray->start);

    std::cout << intersectionPoint[0] << " " << intersectionPoint[1] << " " << intersectionPoint[2] << std::endl;

    ray->color = color;
}