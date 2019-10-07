#include "Scene.hpp"
#include <iostream>


Scene::Scene() {
    /******Materials*******/
    Color white = Color(1,1,1);
    Color green = Color(0,1,0);
    Color red = Color(1,0,0);
    Color turquoise = Color(0,1,1);
    Color yellow = Color(1,1,0);
    Color pink = Color(1,0.41,0.71);

    /*********************/

    /******Materials*******/
    DiffuseMaterial* floorNRoofMaterial = new DiffuseMaterial(white);
    DiffuseMaterial* frontWallMaterial = new DiffuseMaterial(green);
    DiffuseMaterial* backWallMaterial = new DiffuseMaterial(red);
    MirrorMaterial* sphereMaterial = new MirrorMaterial(turquoise, 0.8);
    MirrorMaterial* tetraMaterial = new MirrorMaterial(yellow, 0.8);
    DiffuseMaterial* diffuseTetraMaterial = new DiffuseMaterial(pink);
    TransparentMaterial* transperantSpereMaterial = new TransparentMaterial(pink, 0.8, 1.5);
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

    // Alone tri
    //geometryList.push_back(new Triangle(glm::vec4(6, 0, 2, 1), glm::vec4(5, 1, -2, 1), glm::vec4(7, -1, -2, 1), transperantSpereMaterial));


    /********TETRAHEDRON*********/
    Triangle* tri1 = new Triangle(glm::vec4(0, 0, 2, 1), glm::vec4(2, 2, -2, 1), glm::vec4(-2, 0, -2, 1), diffuseTetraMaterial);
    Triangle* tri2 = new Triangle(glm::vec4(0, 0, 2, 1), glm::vec4(-2, 0, -2, 1), glm::vec4(2, -2, -2, 1), diffuseTetraMaterial);
    Triangle* tri3 = new Triangle(glm::vec4(0, 0, 2, 1), glm::vec4(2, -2, -2, 1), glm::vec4(2, 2, -2, 1), diffuseTetraMaterial);
    Triangle* tri4 = new Triangle(glm::vec4(2, 2, -2, 1), glm::vec4(2, -2, -2, 1), glm::vec4(-2, 0, -2, 1), diffuseTetraMaterial);

    Tetrahedron* tetrahedron = new Tetrahedron(tri1, tri2, tri3, tri4, nullptr);
    tetrahedron->translate(8,1,0);
    geometryList.push_back(tetrahedron);
    /****************************/

    /********SPHERE*********/
    Sphere* sphere = new Sphere(glm::vec4(0, 0, 0, 1), 1, transperantSpereMaterial);
    sphere->translate(5,1,0);
    geometryList.push_back(sphere);
    /****************************/
}

Scene::~Scene() {
    
}

Intersection* Scene::getIntersection(Ray* ray, bool ignoreTransparent) {
    Intersection* closestIntersection = nullptr;
    for (int i=0; i<geometryList.size(); i++) {
        Intersection* intersection = geometryList[i]->rayIntersection(ray);
        if (intersection == nullptr ) continue;
        //std::cout << t << std::endl;
        //if (intersection != nullptr) std::cout << intersection->t << std::endl;

        if (intersection->geometry->material->getMaterialType() == "Transparent" && ignoreTransparent) {
            continue;
        }
        if (closestIntersection == nullptr) {
            closestIntersection = intersection;
        }
        else if (closestIntersection != nullptr && intersection->t < closestIntersection->t) {
            closestIntersection = intersection;
        } 
    }

    return closestIntersection;
}

glm::vec3 Scene::traceRay(Ray* ray, int depth) {
    glm::vec4 lightSource = glm::vec4(4,0,4.5, 1);
    Intersection* closestIntersection = getIntersection(ray);
    if (closestIntersection == nullptr) return glm::vec3(0,0,0); // Bug pixel

    Ray* shadowRay = new Ray(closestIntersection->point, lightSource, nullptr);

    Intersection* shadowRayIntersection = getIntersection(shadowRay, true);

    float kd = 1;
    float inclinationAngle = acos(glm::dot(shadowRay->getVec3(), closestIntersection->normal)/glm::length(shadowRay->getVec3())*glm::length(closestIntersection->normal));

    float r, g, b;

    if (glm::distance(glm::vec3(lightSource), glm::vec3(closestIntersection->point)) < glm::distance(glm::vec3(closestIntersection->point), glm::vec3(shadowRayIntersection->point))) {
        r = closestIntersection->geometry->material->color.r*kd*std::max(0.0f,cos(inclinationAngle));
        g = closestIntersection->geometry->material->color.g*kd*std::max(0.0f,cos(inclinationAngle));
        b = closestIntersection->geometry->material->color.b*kd*std::max(0.0f,cos(inclinationAngle));
    } else {
        r = 0;
        g = 0;
        b = 0;
    }
    if (depth > 5) return glm::vec3(r,g,b);

    if (closestIntersection->geometry->material->getMaterialType() == "Diffuse") {
        return glm::vec3(r,g,b);
    }

    if (closestIntersection->geometry->material->getMaterialType() == "Mirror") { 
        MirrorMaterial* intersectionMaterial = (MirrorMaterial*)closestIntersection->geometry->material;

        glm::vec3 reflectedVector = ray->getVec3() - 2*(glm::dot(ray->getVec3(),closestIntersection->normal))*closestIntersection->normal;

        Ray* reflectedRay = new Ray(closestIntersection->point, reflectedVector + glm::vec3(closestIntersection->point), ray, false, intersectionMaterial->absorption*ray->importance);

        return (reflectedRay->importance*traceRay(reflectedRay, depth+1))/ray->importance + 0.5f*glm::vec3(r,g,b);
    }

    if (closestIntersection->geometry->material->getMaterialType() == "Transparent") {
        TransparentMaterial* intersectionMaterial = (TransparentMaterial*)closestIntersection->geometry->material;

        glm::vec3 I = glm::normalize(ray->getVec3()); // Normalized incoming ray
        glm::vec3 N = closestIntersection->normal;

        float n1;
        float n2;
        
        if (!ray->isInObject) {
            n1 = 1.0f;
            n2 = intersectionMaterial->refractiveIndex;
        } else {
            n1 = intersectionMaterial->refractiveIndex;
            n2 = 1.0f;
        }
        float criticalAngle = asin(n2/n1);
        float incomingAngle = acos((glm::dot(I,-N))/(glm::length(I)*glm::length(N)));
        float R0 = pow((n1 - n2)/(n1 + n2), 2);
        float R = R0 + (1 - R0)*pow(1 - cos(abs(incomingAngle)),5);
        float T = 1 - R;

        glm::vec3 reflectedVector = ray->getVec3() - 2*(glm::dot(ray->getVec3(), N))*N;
        Ray* reflectedRay; 

        if (n1 > n2 && abs(incomingAngle) > abs(criticalAngle)) {
            reflectedRay = new Ray(closestIntersection->point, reflectedVector+glm::vec3(closestIntersection->point), ray, ray->isInObject, intersectionMaterial->absorption*ray->importance);
            return reflectedRay->importance*traceRay(reflectedRay, depth+1)/ray->importance;
        }

        reflectedRay = new Ray(closestIntersection->point, reflectedVector+glm::vec3(closestIntersection->point), ray, ray->isInObject, intersectionMaterial->absorption*ray->importance*R);

        glm::vec3 transmittedVector = (n1/n2) * I + N * (float)(-(n1/n2)*glm::dot(N,I) - sqrt(1 - pow(n1/n2,2)*(1 - pow(glm::dot(N,I),2)))); 
        
        Ray* transmittedRay = new Ray(glm::vec3(closestIntersection->point) + transmittedVector*0.001f, transmittedVector + glm::vec3(closestIntersection->point), ray, !ray->isInObject, intersectionMaterial->absorption*ray->importance*T); 

        Intersection* transIntersection = getIntersection(transmittedRay);

        return (reflectedRay->importance*traceRay(reflectedRay, depth+1) + transmittedRay->importance*traceRay(transmittedRay, depth+1))/ray->importance;
    }
    
}