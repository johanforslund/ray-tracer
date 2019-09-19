#include "Scene.hpp"

Scene::Scene() {
    triangleList.push_back(Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(0, -6, 5, 1), ColorDbl(1, 1, 1))); //Roof 1
    triangleList.push_back(Triangle(glm::vec4(0, -6, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, -6, 5, 1), ColorDbl(1, 1, 1))); //Roof 2
    triangleList.push_back(Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, 6, 5, 1), ColorDbl(1, 1, 1))); //Roof 3
    triangleList.push_back(Triangle(glm::vec4(10, 6, 5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, -6, 5, 1), ColorDbl(1, 1, 1))); //Roof 4

    triangleList.push_back(Triangle(glm::vec4(-3, 0, -5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(0, 6, -5, 1), ColorDbl(1, 1, 1))); //Floor 5
    triangleList.push_back(Triangle(glm::vec4(0, 6, -5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(10, -6, -5, 1), ColorDbl(1, 1, 1))); //Floor 6
    triangleList.push_back(Triangle(glm::vec4(10, -6, -5, 1), glm::vec4(10, 6, -5, 1), glm::vec4(0, 6, -5, 1), ColorDbl(1, 1, 1))); //Floor 7
    triangleList.push_back(Triangle(glm::vec4(10, 6, -5, 1), glm::vec4(10, -6, -5, 1), glm::vec4(13, 0, -5, 1), ColorDbl(1, 1, 1))); //Floor 8

    triangleList.push_back(Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(-3, 0, -5, 1), ColorDbl(0, 1, 0))); //Front 9
    triangleList.push_back(Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(0, -6, -5, 1), ColorDbl(0, 1, 0))); //Front 10
    triangleList.push_back(Triangle(glm::vec4(0, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, -5, 1), ColorDbl(0, 1, 0))); //Front 11
    triangleList.push_back(Triangle(glm::vec4(10, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, 5, 1), ColorDbl(0, 1, 0))); //Front 12
    triangleList.push_back(Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(13, 0, -5, 1), glm::vec4(10, -6, -5, 1), ColorDbl(0, 1, 0))); //Front 13
    triangleList.push_back(Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(13, 0, -5, 1), ColorDbl(0, 1, 0))); //Front 14

    triangleList.push_back(Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(-3, 0, -5, 1), glm::vec4(0, 6, -5, 1), ColorDbl(1, 0, 0))); //Back 15
    triangleList.push_back(Triangle(glm::vec4(0, 6, -5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(-3, 0, 5, 1), ColorDbl(1, 0, 0))); //Back 16
    triangleList.push_back(Triangle(glm::vec4(0, 6, 5, 1), glm::vec4(0, 6, -5, 1), glm::vec4(10, 6, -5, 1), ColorDbl(1, 0, 0))); //Back 17
    triangleList.push_back(Triangle(glm::vec4(10, 6, -5, 1), glm::vec4(10, 6, 5, 1), glm::vec4(0, 6, 5, 1), ColorDbl(1, 0, 0))); //Back 18
    triangleList.push_back(Triangle(glm::vec4(10, 6, 5, 1), glm::vec4(10, 6, -5, 1), glm::vec4(13, 0, -5, 1), ColorDbl(1, 0, 0))); //Back 19
    triangleList.push_back(Triangle(glm::vec4(13, 0, -5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, 6, 5, 1), ColorDbl(1, 0, 0))); //Back 20
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