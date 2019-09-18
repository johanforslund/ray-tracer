#include "Scene.hpp"

Scene::Scene() {
    triangleList.push_back(Triangle(glm::vec4(-3,0,5,1),glm::vec4(0,6,5,1),glm::vec4(0,-6,5,1),ColorDbl(1,1,1),(glm::vec3(0,0,-1)))); // Roof t1
    triangleList.push_back(Triangle(glm::vec4(0,-6,5,1), glm::vec4(0,6,5,1), glm::vec4(10,-6,5,1), ColorDbl(1,1,1), (glm::vec3(0,0,-1)))); // Roof t2
    triangleList.push_back(Triangle(glm::vec4(0,6,5,1),glm::vec4(10,6,5,1),glm::vec4(10,-6,5,1),ColorDbl(1,1,1),(glm::vec3(0,0,-1)))); // Roof t3
    triangleList.push_back(Triangle(glm::vec4(13,0,5,1),glm::vec4(10,6,5,1),glm::vec4(10,-6,5,1),ColorDbl(1,1,1),(glm::vec3(0,0,-1)))); // Roof t4
    
    triangleList.push_back(Triangle(glm::vec4(13,0,-5,1),glm::vec4(10,6,-5,1),glm::vec4(10,-6,-5,1),ColorDbl(1,1,1),(glm::vec3(0,0,1)))); // Floor t5
    triangleList.push_back(Triangle(glm::vec4(0,-6,-5,1),glm::vec4(0,6,-5,1),glm::vec4(10,-6,-5,1),ColorDbl(1,1,1),(glm::vec3(0,0,1)))); // Floor t6
    triangleList.push_back(Triangle(glm::vec4(0,6,-5,1),glm::vec4(10,6,-5,1),glm::vec4(10,-6,-5,1),ColorDbl(1,1,1),(glm::vec3(0,0,1)))); // Floor t7
    triangleList.push_back(Triangle(glm::vec4(-3,0,-5,1),glm::vec4(0,6,-5,1),glm::vec4(0,-6,-5,1),ColorDbl(1,1,1),(glm::vec3(0,0,1)))); // Floor t8

    triangleList.push_back(Triangle(glm::vec4(-3,0,-5,1),glm::vec4(-3,0,5,1),glm::vec4(0,-6,-5,1),ColorDbl(1,0,0),(glm::normalize(glm::vec3(2,1,0))))); // Front t9
    triangleList.push_back(Triangle(glm::vec4(0,-6,-5,1),glm::vec4(-3,0,5,1),glm::vec4(0,-6,5,1),ColorDbl(1,0,0),(glm::normalize(glm::vec3(2,1,0))))); // Front t10
    triangleList.push_back(Triangle(glm::vec4(0,-6,5,1),glm::vec4(0,-6,-5,1),glm::vec4(10,-6,-5,1),ColorDbl(1,0,0),(glm::vec3(0,1,0)))); // Front t11
    triangleList.push_back(Triangle(glm::vec4(10,-6,-5,1),glm::vec4(0,-6,5,1),glm::vec4(10,-6,5,1),ColorDbl(1,0,0),(glm::vec3(0,1,0)))); // Front t12
    triangleList.push_back(Triangle(glm::vec4(10,-6,5,1),glm::vec4(10,-6,-5,1),glm::vec4(13,0,5,1),ColorDbl(1,0,0),(glm::normalize(glm::vec3(-2,1,0))))); // Front t13
    triangleList.push_back(Triangle(glm::vec4(13,0,5,1),glm::vec4(10,-6,5,1),glm::vec4(13,0,-5,1),ColorDbl(1,0,0),(glm::normalize(glm::vec3(-2,1,0))))); // Front t14
    
    triangleList.push_back(Triangle(glm::vec4(-3,6,-5,1),glm::vec4(-3,6,5,1),glm::vec4(0,6,-5,1),ColorDbl(0,1,0),(glm::normalize(glm::vec3(2,-1,0))))); // Back t15
    triangleList.push_back(Triangle(glm::vec4(0,6,-5,1),glm::vec4(-3,0,5,1),glm::vec4(0,6,5,1),ColorDbl(0,1,0),(glm::normalize(glm::vec3(2,-1,0))))); // Back t16
    triangleList.push_back(Triangle(glm::vec4(0,6,5,1),glm::vec4(0,6,-5,1),glm::vec4(10,6,-5,1),ColorDbl(0,1,0),(glm::vec3(0,-1,0)))); // Back t17
    triangleList.push_back(Triangle(glm::vec4(10,6,-5,1),glm::vec4(0,6,5,1),glm::vec4(10,6,5,1),ColorDbl(0,1,0),(glm::vec3(0,-1,0)))); // Back t18
    triangleList.push_back(Triangle(glm::vec4(10,6,5,1),glm::vec4(10,6,-5,1),glm::vec4(13,0,-5,1),ColorDbl(0,1,0),(glm::normalize(glm::vec3(-2,-1,0))))); // Back t19
    triangleList.push_back(Triangle(glm::vec4(13,0,5,1),glm::vec4(10,6,5,1),glm::vec4(13,0,-5,1),ColorDbl(0,1,0),(glm::normalize(glm::vec3(-2,-1,0))))); // Back t20
}

Scene::~Scene() {
    
}

void Scene::getIntersection(Ray* ray) {
    double minT = 10000000;
    int minIndex = -1;
    for (int i=0; i<triangleList.size(); i++) {
        double t = triangleList[i].rayIntersection(ray);
        if (t < minT && t > 0) {
            minT = t;
            minIndex = i;
        }
    }

    ray->color = triangleList[minIndex].color;
}