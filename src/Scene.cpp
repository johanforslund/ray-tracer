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
    TransparentMaterial* transperantSpereMaterial = new TransparentMaterial(pink, 0.8, 1.1);

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
    Triangle* tri1 = new Triangle(glm::vec4(0, 0, 2, 1), glm::vec4(2, 2, -2, 1), glm::vec4(-2, 0, -2, 1), transperantSpereMaterial);
    Triangle* tri2 = new Triangle(glm::vec4(0, 0, 2, 1), glm::vec4(-2, 0, -2, 1), glm::vec4(2, -2, -2, 1), transperantSpereMaterial);
    Triangle* tri3 = new Triangle(glm::vec4(0, 0, 2, 1), glm::vec4(2, -2, -2, 1), glm::vec4(2, 2, -2, 1), transperantSpereMaterial);
    Triangle* tri4 = new Triangle(glm::vec4(2, 2, -2, 1), glm::vec4(2, -2, -2, 1), glm::vec4(-2, 0, -2, 1), transperantSpereMaterial);

    Tetrahedron* tetrahedron = new Tetrahedron(tri1, tri2, tri3, tri4, nullptr);
    tetrahedron->translate(4,2,-1);
    //geometryList.push_back(tetrahedron);
    /****************************/

    /********SPHERE*********/
    Sphere* sphere = new Sphere(glm::vec4(0, 0, 0, 1), 1, transperantSpereMaterial);
    sphere->translate(6,0,0);
    geometryList.push_back(sphere);
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

glm::vec3 Scene::traceRay(Ray* ray) {
    glm::vec4 lightSource = glm::vec4(4,0,4.5, 1);
    Intersection* closestIntersection = getIntersection(ray);
    if (closestIntersection == nullptr) return glm::vec3(0,0,0); // Bug pixel

    Ray* shadowRay = new Ray(closestIntersection->point, lightSource, nullptr);

    Intersection* shadowRayIntersection = getIntersection(shadowRay);

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

    if (closestIntersection->geometry->material->getMaterialType() == "Diffuse") {
        return glm::vec3(r,g,b);
    }

    if (closestIntersection->geometry->material->getMaterialType() == "Mirror") { 
        MirrorMaterial* intersectionMaterial = (MirrorMaterial*)closestIntersection->geometry->material;

        glm::vec3 reflectedVector = ray->getVec3() - 2*(glm::dot(ray->getVec3(),closestIntersection->normal))*closestIntersection->normal;

        Ray* reflectedRay = new Ray(closestIntersection->point, glm::vec4(reflectedVector, 1)+closestIntersection->point, ray, intersectionMaterial->absorption*ray->importance);

        return (reflectedRay->importance*traceRay(reflectedRay))/ray->importance + 0.5f*glm::vec3(r,g,b);
    }

    if (closestIntersection->geometry->material->getMaterialType() == "Transparent") {
        //std::cout << "En gång" << std::endl;
        TransparentMaterial* intersectionMaterial = (TransparentMaterial*)closestIntersection->geometry->material;

        glm::vec3 I = glm::normalize(ray->getVec3()); // Normalized incoming ray

        float n1 = 1;
        float n2 = 1;
        /*
        if (glm::dot(I, closestIntersection->normal) < 0) {
            n1 = 1.0f;
            n2 = intersectionMaterial->refractiveIndex;
        } else {
            n1 = intersectionMaterial->refractiveIndex;
            n2 = 1.0f;
        }
        */
        
        glm::vec3 reflectedVector = ray->getVec3() - 2*(glm::dot(ray->getVec3(),closestIntersection->normal))*closestIntersection->normal;
        glm::vec3 transmittedVector = (n1/n2) * I + closestIntersection->normal * (float)(-(n1/n2)*glm::dot(closestIntersection->normal,I) - sqrt(1 - pow(n1/n2,2)*(1 - pow(glm::dot(closestIntersection->normal,I),2)))); // Kolla parentes
        
        //std::cout << transmittedVector[0] << " " << transmittedVector[1] << " " << transmittedVector[2] << std::endl;

        Ray* reflectedRay = new Ray(closestIntersection->point, glm::vec4(reflectedVector, 1)+closestIntersection->point, ray, intersectionMaterial->absorption*ray->importance);
        Ray* transmittedRay = new Ray(closestIntersection->point + glm::vec4(transmittedVector*0.001f,1), glm::vec4(transmittedVector, 1)+closestIntersection->point, ray, intersectionMaterial->absorption*ray->importance); 

        Intersection* exitIntersection = getIntersection(transmittedRay);
        if (exitIntersection->point[0] > 6.8) {
            //std::cout << "Exit Point: " << exitIntersection->point[0] << " " << exitIntersection->point[1] << " " << exitIntersection->point[2] << std::endl;
            //std::cout << "Exit Normal: " << exitIntersection->normal[0] << " " << exitIntersection->normal[1] << " " << exitIntersection->normal[2] << std::endl;
        }

        //std::cout << glm::distance(glm::vec3(exitIntersection->point), glm::vec3(6,0,0)) << std::endl;
        //std::cout << glm::distance(glm::vec3(closestIntersection->point), glm::vec3(6,0,0)) << std::endl;

        glm::vec3 I2 = glm::normalize(transmittedRay->getVec3());
        transmittedVector = (n2/n1) * I2 + -exitIntersection->normal * (float)(-(n2/n1)*glm::dot(-exitIntersection->normal,I2) - sqrt(1 - pow(n2/n1,2)*(1 - pow(glm::dot(-exitIntersection->normal,I2),2))));
        transmittedRay = new Ray(exitIntersection->point, glm::vec4(transmittedVector, 1)+exitIntersection->point, ray, intersectionMaterial->absorption*ray->importance); 
        //std::cout << transmittedVector[0] << " " << transmittedVector[1] << " " << transmittedVector[2] << std::endl;

        float exitAngle = acos((glm::dot(I2, exitIntersection->normal))/(glm::length(I2)*glm::length(exitIntersection->normal)));


        if (exitAngle > 0.733) return glm::vec3(1,1,1);

        Intersection* wallIntersection = getIntersection(transmittedRay);
        //std::cout << wallIntersection->point[0] << " " << wallIntersection->point[1] << " " << wallIntersection->point[2] << std::endl;
        //std::cout << exitIntersection->geometry->material->getMaterialType() << std::endl;

        return (transmittedRay->importance*traceRay(transmittedRay))/ray->importance;
    }
    
}