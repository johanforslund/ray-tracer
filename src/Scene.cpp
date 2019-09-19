#include "Scene.hpp"
#include <iostream>

Scene::Scene() {
    /******ROOM*******/
    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(0, -6, 5, 1), ColorDbl(1, 0, 1))); //Roof 1
    geometryList.push_back(new Triangle(glm::vec4(0, -6, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, -6, 5, 1), ColorDbl(1, 0, 1))); //Roof 2
    geometryList.push_back(new Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, 6, 5, 1), ColorDbl(1, 0, 1))); //Roof 3
    geometryList.push_back(new Triangle(glm::vec4(10, 6, 5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, -6, 5, 1), ColorDbl(1, 0, 1))); //Roof 4

    geometryList.push_back(new Triangle(glm::vec4(-3, 0, -5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(0, 6, -5, 1), ColorDbl(1, 1, 1))); //Floor 5
    geometryList.push_back(new Triangle(glm::vec4(0, 6, -5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(10, -6, -5, 1), ColorDbl(1, 1, 1))); //Floor 6
    geometryList.push_back(new Triangle(glm::vec4(10, -6, -5, 1), glm::vec4(10, 6, -5, 1), glm::vec4(0, 6, -5, 1), ColorDbl(1, 1, 1))); //Floor 7
    geometryList.push_back(new Triangle(glm::vec4(10, 6, -5, 1), glm::vec4(10, -6, -5, 1), glm::vec4(13, 0, -5, 1), ColorDbl(1, 1, 1))); //Floor 8

    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(-3, 0, -5, 1), ColorDbl(0, 1, 0))); //Front 9
    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(0, -6, -5, 1), ColorDbl(0, 1, 0))); //Front 10
    geometryList.push_back(new Triangle(glm::vec4(0, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, -5, 1), ColorDbl(0, 1, 0))); //Front 11
    geometryList.push_back(new Triangle(glm::vec4(10, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, 5, 1), ColorDbl(0, 1, 0))); //Front 12
    geometryList.push_back(new Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(13, 0, -5, 1), glm::vec4(10, -6, -5, 1), ColorDbl(0, 1, 0))); //Front 13
    geometryList.push_back(new Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(13, 0, -5, 1), ColorDbl(0, 1, 0))); //Front 14

    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(-3, 0, -5, 1), glm::vec4(0, 6, -5, 1), ColorDbl(1, 0, 0))); //Back 15
    geometryList.push_back(new Triangle(glm::vec4(0, 6, -5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(-3, 0, 5, 1), ColorDbl(1, 0, 0))); //Back 16
    geometryList.push_back(new Triangle(glm::vec4(0, 6, 5, 1), glm::vec4(0, 6, -5, 1), glm::vec4(10, 6, -5, 1), ColorDbl(1, 0, 0))); //Back 17
    geometryList.push_back(new Triangle(glm::vec4(10, 6, -5, 1), glm::vec4(10, 6, 5, 1), glm::vec4(0, 6, 5, 1), ColorDbl(1, 0, 0))); //Back 18
    geometryList.push_back(new Triangle(glm::vec4(10, 6, 5, 1), glm::vec4(10, 6, -5, 1), glm::vec4(13, 0, -5, 1), ColorDbl(1, 0, 0))); //Back 19
    geometryList.push_back(new Triangle(glm::vec4(13, 0, -5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, 6, 5, 1), ColorDbl(1, 0, 0))); //Back 20
    /***************/

    /********TETRAHEDRON*********/
    Triangle* tri1 = new Triangle(glm::vec4(7, 0, 0, 1), glm::vec4(9, 2, -3, 1), glm::vec4(5, 0, -3, 1), ColorDbl(0.7, 0.5, 0.4));
    Triangle* tri2 = new Triangle(glm::vec4(7, 0, 0, 1), glm::vec4(5, 0, -3, 1), glm::vec4(9, -2, -3, 1), ColorDbl(0.5, 0.9, 1));
    Triangle* tri3 = new Triangle(glm::vec4(7, 0, 0, 1), glm::vec4(9, -2, -3, 1), glm::vec4(9, 2, -3, 1), ColorDbl(0.8, 0.5, 0.6));
    Triangle* tri4 = new Triangle(glm::vec4(9, 2, -3, 1), glm::vec4(9, -2, -3, 1), glm::vec4(5, 0, -3, 1), ColorDbl(0.5, 0.5, 0.5));
    geometryList.push_back(new Tetrahedron(tri1, tri2, tri3, tri4, ColorDbl(0.7, 0.3, 0.6)));
    /****************************/

}

Scene::~Scene() {
    
}

void Scene::getIntersection(Ray* ray) {
    Intersection* closestIntersection = nullptr;
    for (int i=0; i<geometryList.size(); i++) {
        Intersection* intersection = geometryList[i]->rayIntersection(ray);
        //std::cout << t << std::endl;
        //if (intersection != nullptr) std::cout << intersection->t << std::endl;

        if (closestIntersection == nullptr && intersection != nullptr && intersection->t > 0) {
            closestIntersection = intersection;
        }
        else if (intersection != nullptr && closestIntersection != nullptr && 
                intersection->t < closestIntersection->t && intersection->t > 0) {
            closestIntersection = intersection;
        } 
    }

    //std::cout << closestIntersection->t << std::endl;
   //std::cout << closestIntersection->t << std::endl;
    if (closestIntersection != nullptr && closestIntersection->geometry != nullptr) ray->color = closestIntersection->geometry->color;
}