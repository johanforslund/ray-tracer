#include <iostream>
#include "Triangle.hpp"

Triangle::Triangle(glm::vec4 vertex1, glm::vec4 vertex2, glm::vec4 vertex3, Material* _material) : Geometry(_material) {
    vertexList[0] = vertex1;
    vertexList[1] = vertex2;
    vertexList[2] = vertex3;

    normalDirection = glm::normalize(glm::cross(glm::vec3(vertexList[1] - vertexList[0]), glm::vec3(vertexList[2] - vertexList[0])));
}

Triangle::~Triangle() {

}

Intersection* Triangle::rayIntersection(Ray* ray) {
    glm::vec3 normal = normalDirection;
    if (ray->isInObject) normal = -normal;
    if (glm::dot(ray->getVec3(), normal) > 0) return nullptr; // Could maybe not work
    
    glm::vec3 T = ray->start - vertexList[0];
    glm::vec3 E1 = vertexList[1] - vertexList[0];
    glm::vec3 E2 = vertexList[2] - vertexList[0];
    glm::vec3 D = glm::normalize(ray->end - ray->start);
    glm::vec3 P = glm::cross(D, E2);
    glm::vec3 Q = glm::cross(T, E1);

    float t = (glm::dot(Q, E2))/(glm::dot(P, E1));
    float u = (glm::dot(P, T))/(glm::dot(P, E1));
    float v = (glm::dot(Q, D))/(glm::dot(P, E1));

    if (u + v > 1 || v < 0 || u < 0) return nullptr;
    if (t < 0) return nullptr;

    glm::vec4 intersectionPoint = ray->start + t*glm::normalize(ray->end - ray->start);

    return new Intersection(t, this, intersectionPoint, normal);
}

std::string Triangle::getName() {
    return "Triangle";
}

void Triangle::translate(float x, float y, float z) {
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));
    vertexList[0] = translationMatrix*vertexList[0];
    vertexList[1] = translationMatrix*vertexList[1];
    vertexList[2] = translationMatrix*vertexList[2];
}
 
