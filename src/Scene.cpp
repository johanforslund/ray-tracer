#include "Scene.hpp"
#include <iostream>


Scene::Scene() {
    /******Materials*******/
    Color white = Color(1,1,1);
    Color green = Color(0,1,0);
    Color red = Color(1,0,0);
    Color turquoise = Color(0,1,1);
    Color yellow = Color(1,1,0);

    /*********************/

    /******Materials*******/
    DiffuseMaterial* floorNRoofMaterial = new DiffuseMaterial(white);
    DiffuseMaterial* frontWallMaterial = new DiffuseMaterial(green);
    DiffuseMaterial* backWallMaterial = new DiffuseMaterial(red);
    MirrorMaterial* sphereMaterial = new MirrorMaterial(turquoise, 0.8);
    MirrorMaterial* tetraMaterial = new MirrorMaterial(yellow, 0.8);

    /*********************/

    /******ROOM*******/
    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(0, -6, 5, 1), floorNRoofMaterial)); //Roof 1
    geometryList.push_back(new Triangle(glm::vec4(0, -6, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, -6, 5, 1), floorNRoofMaterial)); //Roof 2
    geometryList.push_back(new Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, 6, 5, 1), floorNRoofMaterial)); //Roof 3
    geometryList.push_back(new Triangle(glm::vec4(10, 6, 5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, -6, 5, 1), floorNRoofMaterial)); //Roof 4

    geometryList.push_back(new Triangle(glm::vec4(-3, 0, -5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(0, 6, -5, 1), floorNRoofMaterial)); //Floor 5
    geometryList.push_back(new Triangle(glm::vec4(0, 6, -5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(10, -6, -5, 1), floorNRoofMaterial)); //Floor 6
    geometryList.push_back(new Triangle(glm::vec4(10, -6, -5, 1), glm::vec4(10, 6, -5, 1), glm::vec4(0, 6, -5, 1), floorNRoofMaterial)); //Floor 7
    geometryList.push_back(new Triangle(glm::vec4(10, 6, -5, 1), glm::vec4(10, -6, -5, 1), glm::vec4(13, 0, -5, 1), floorNRoofMaterial)); //Floor 8

    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, -6, -5, 1), glm::vec4(-3, 0, -5, 1), frontWallMaterial)); //Front 9
    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(0, -6, -5, 1), frontWallMaterial)); //Front 10
    geometryList.push_back(new Triangle(glm::vec4(0, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, -5, 1), frontWallMaterial)); //Front 11
    geometryList.push_back(new Triangle(glm::vec4(10, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, 5, 1), frontWallMaterial)); //Front 12
    geometryList.push_back(new Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(13, 0, -5, 1), glm::vec4(10, -6, -5, 1), frontWallMaterial)); //Front 13
    geometryList.push_back(new Triangle(glm::vec4(10, -6, 5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(13, 0, -5, 1), frontWallMaterial)); //Front 14

    geometryList.push_back(new Triangle(glm::vec4(-3, 0, 5, 1), glm::vec4(-3, 0, -5, 1), glm::vec4(0, 6, -5, 1), backWallMaterial)); //Back 15
    geometryList.push_back(new Triangle(glm::vec4(0, 6, -5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(-3, 0, 5, 1), backWallMaterial)); //Back 16
    geometryList.push_back(new Triangle(glm::vec4(0, 6, 5, 1), glm::vec4(0, 6, -5, 1), glm::vec4(10, 6, -5, 1), backWallMaterial)); //Back 17
    geometryList.push_back(new Triangle(glm::vec4(10, 6, -5, 1), glm::vec4(10, 6, 5, 1), glm::vec4(0, 6, 5, 1), backWallMaterial)); //Back 18
    geometryList.push_back(new Triangle(glm::vec4(10, 6, 5, 1), glm::vec4(10, 6, -5, 1), glm::vec4(13, 0, -5, 1), backWallMaterial)); //Back 19
    geometryList.push_back(new Triangle(glm::vec4(13, 0, -5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, 6, 5, 1), backWallMaterial)); //Back 20
    /***************/

    /********TETRAHEDRON*********/
    Triangle* tri1 = new Triangle(glm::vec4(7, 2, 0, 1), glm::vec4(9, 4, -3, 1), glm::vec4(5, 1, -1, 1), tetraMaterial);
    Triangle* tri2 = new Triangle(glm::vec4(7, 2, 0, 1), glm::vec4(5, 1, -1, 1), glm::vec4(9, 0, -3, 1), tetraMaterial);
    Triangle* tri3 = new Triangle(glm::vec4(7, 2, 0, 1), glm::vec4(9, 0, -3, 1), glm::vec4(9, 4, -3, 1), tetraMaterial);
    Triangle* tri4 = new Triangle(glm::vec4(9, 4, -3, 1), glm::vec4(9, 0, -3, 1), glm::vec4(5, 1, -1, 1), tetraMaterial);
    geometryList.push_back(new Tetrahedron(tri1, tri2, tri3, tri4, nullptr));
    /****************************/

    /********SPHERE*********/
    geometryList.push_back(new Sphere(glm::vec4(7, -3, 0, 1), 1, sphereMaterial));
    /****************************/
}

Scene::~Scene() {
    
}

Intersection* Scene::getIntersection(Ray* ray) {
    Intersection* closestIntersection = nullptr;
    for (int i=0; i<geometryList.size(); i++) {
        Intersection* intersection = geometryList[i]->rayIntersection(ray);
        //std::cout << t << std::endl;
        //if (intersection != nullptr) std::cout << intersection->t << std::endl;

        if (closestIntersection == nullptr && intersection != nullptr) {
            closestIntersection = intersection;
        }
        else if (intersection != nullptr && closestIntersection != nullptr && 
                intersection->t < closestIntersection->t) {
            closestIntersection = intersection;
        } 
    }

    return closestIntersection;
}

void Scene::colorizeRay(Ray* ray) {
    glm::vec4 lightSource = glm::vec4(4,0,4.5, 1);
    Intersection* closestIntersection = getIntersection(ray);
    if (closestIntersection != nullptr) {
        Ray* shadowRay = new Ray(closestIntersection->point, lightSource, nullptr);

        //std::cout << closestIntersection->point[0] << " " << closestIntersection->point[1] << " " << closestIntersection->point[2] << std::endl;

        Intersection* shadowRayIntersection = getIntersection(shadowRay);

        if (shadowRayIntersection->geometry->getName() == "Triangle") {
            //std::cout << shadowRayIntersection->point[2] << ": " << shadowRayIntersection->t << std::endl;
        }

        float kd = 1;
        float inclinationAngle = acos(glm::dot(shadowRay->getVec3(), closestIntersection->normal)/glm::length(shadowRay->getVec3())*glm::length(closestIntersection->normal));

        float r, g, b;

        //std::cout << shadowRayIntersection->t << std::endl;
        if (glm::distance(glm::vec3(lightSource), glm::vec3(closestIntersection->point)) < glm::distance(glm::vec3(closestIntersection->point), glm::vec3(shadowRayIntersection->point))) {
            //std::cout << shadowRayIntersection->point[2] << std::endl;
            r = closestIntersection->geometry->material->color.r*kd*std::max(0.0f,cos(inclinationAngle));
            g = closestIntersection->geometry->material->color.g*kd*std::max(0.0f,cos(inclinationAngle));
            b = closestIntersection->geometry->material->color.b*kd*std::max(0.0f,cos(inclinationAngle));
        } else {
            //std::cout << shadowRayIntersection->t << std::endl;
            //std::cout << "BALL: " << shadowRayIntersection->point[0] << " " << shadowRayIntersection->point[1] << " " << shadowRayIntersection->point[2] << std::endl;
            r = 0;
            g = 0;
            b = 0;
        }

        Color color = Color(r,g,b);

        ray->color = color;
    }
}