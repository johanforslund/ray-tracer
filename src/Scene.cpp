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
    DiffuseMaterial* floorNRoofMaterial = new DiffuseMaterial(white, 0.05);
    DiffuseMaterial* frontWallMaterial = new DiffuseMaterial(green, 0.05);
    DiffuseMaterial* backWallMaterial = new DiffuseMaterial(red, 0.05);
    MirrorMaterial* sphereMaterial = new MirrorMaterial(turquoise, 0.8);
    MirrorMaterial* tetraMaterial = new MirrorMaterial(yellow, 0.8);
    DiffuseMaterial* diffuseTetraMaterial = new DiffuseMaterial(pink, 0.05);
    TransparentMaterial* transperantSpereMaterial = new TransparentMaterial(pink, 0.8, 1.5);
    LightMaterial* lightMaterial = new LightMaterial(pink, 100.0f);
    /*********************/

    /******Light*******/
    Triangle* lightTri1 = new Triangle(glm::vec4(0.5, 0.5, 0, 1), glm::vec4(-0.5, -0.5, 0, 1), glm::vec4(-0.5, 0.5, 0, 1), lightMaterial);
    Triangle* lightTri2 = new Triangle(glm::vec4(0.5, 0.5, 0, 1), glm::vec4(0.5, -0.5, 0, 1), glm::vec4(-0.5, -0.5, 0, 1), lightMaterial); // Light
    
    Rectangle* lightRectangle = new Rectangle(lightTri1, lightTri2, nullptr);
    lightRectangle->translate(4,0,4.99f);
    geometryList.push_back(lightRectangle);
    /*****************/

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
    //geometryList.push_back(tetrahedron);
    /****************************/

    /********Box*********/
    Triangle* boxTri1 = new Triangle(glm::vec4(-2, 2, 2, 1), glm::vec4(-2, 2, -2, 1), glm::vec4(-2, -2, -2, 1), diffuseTetraMaterial);
    Triangle* boxTri2 = new Triangle(glm::vec4(-2, 2, 2, 1), glm::vec4(-2, -2, -2, 1), glm::vec4(-2, -2, 2, 1), diffuseTetraMaterial); // Front

    Triangle* boxTri3 = new Triangle(glm::vec4(2, 2, 2, 1), glm::vec4(2, -2, 2, 1), glm::vec4(2, 2, -2, 1), diffuseTetraMaterial);
    Triangle* boxTri4 = new Triangle(glm::vec4(2, -2, 2, 1), glm::vec4(2, -2, -2, 1), glm::vec4(2, 2, -2, 1), diffuseTetraMaterial); // Back

    Triangle* boxTri5 = new Triangle(glm::vec4(2, 2, 2, 1), glm::vec4(-2, 2, 2, 1), glm::vec4(-2, -2, 2, 1), diffuseTetraMaterial);
    Triangle* boxTri6 = new Triangle(glm::vec4(2, 2, 2, 1), glm::vec4(-2, -2, 2, 1), glm::vec4(2, -2, 2, 1), diffuseTetraMaterial); // Up

    Triangle* boxTri7 = new Triangle(glm::vec4(2, 2, -2, 1), glm::vec4(-2, -2, -2, 1), glm::vec4(-2, 2, -2, 1), diffuseTetraMaterial);
    Triangle* boxTri8 = new Triangle(glm::vec4(2, 2, -2, 1), glm::vec4(2, -2, -2, 1), glm::vec4(-2, -2, -2, 1), diffuseTetraMaterial); // Down

    Triangle* boxTri9 = new Triangle(glm::vec4(-2, 2, 2, 1), glm::vec4(2, 2, 2, 1), glm::vec4(-2, 2, -2, 1), diffuseTetraMaterial);
    Triangle* boxTri10 = new Triangle(glm::vec4(2, 2, 2, 1), glm::vec4(2, 2, -2, 1), glm::vec4(-2, 2, -2, 1), diffuseTetraMaterial); // Left

    Triangle* boxTri11 = new Triangle(glm::vec4(-2, -2, 2, 1), glm::vec4(-2, -2, -2, 1), glm::vec4(2, -2, 2, 1), diffuseTetraMaterial);
    Triangle* boxTri12 = new Triangle(glm::vec4(2, -2, 2, 1), glm::vec4(-2, -2, -2, 1), glm::vec4(2, -2, -2, 1), diffuseTetraMaterial); // Right

    Box* box = new Box(boxTri1, boxTri2, boxTri3, boxTri4, boxTri5, boxTri6, boxTri7, boxTri8, boxTri9, boxTri10,
                       boxTri11, boxTri12, nullptr);
    box->translate(8,-2,-2.9);
    geometryList.push_back(box);
    /****************************/

    /********SPHERE*********/
    Sphere* sphere = new Sphere(glm::vec4(0, 0, 0, 1), 1, transperantSpereMaterial);
    sphere->translate(8,-2,1);
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
        /*if (intersection->geometry->material->getMaterialType() != "Light" && intersection->point[0] >= 3.5f &&
            intersection->point[0] <= 4.5f && intersection->point[1] >= -0.5f && intersection->point[1] <= 0.5f &&
            intersection->point[2] == 5) {
            //std::cout << "POINT" << glm::to_string(intersection->point) << std::endl;
            continue;
        }*/
        
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
    Intersection* closestIntersection = getIntersection(ray);
    if (closestIntersection == nullptr) return glm::vec3(0,0,0); // Bug pixel

    float kdSum = 0;
    //std::cout << "HEJEHJE" << std::endl;
    for (int i = 0; i < 15; i++) {
        float randX = std::rand()/(float)RAND_MAX;
        float randY = std::rand()/(float)RAND_MAX;
        
        Ray* shadowRay = new Ray(closestIntersection->point, glm::vec3(randX + 4.0f - 0.5f, randY + 0 - 0.5f, 4.99f), nullptr);

        Intersection* shadowRayIntersection = getIntersection(shadowRay, true);

        glm::vec3 Sk, Na, Nx;
        float cosAk, cosBk;

        // Visibility test
        if (shadowRayIntersection->geometry->material->getMaterialType() == "Light"){
            Sk = glm::vec3(shadowRayIntersection->point - closestIntersection->point);
            Na = shadowRayIntersection->normal;
            Nx = closestIntersection->normal;
            cosAk = glm::dot(-Sk,Na);
            cosBk = glm::dot(Sk,Nx);
            kdSum += (cosAk*cosBk)/pow(glm::length(Sk), 2);
        }
    }

    //float inclinationAngle = acos(glm::dot(shadowRay->getVec3(), closestIntersection->normal)/glm::length(shadowRay->getVec3())*glm::length(closestIntersection->normal));

    float r, g, b;

    float Ld = (kdSum/15)*100; // Change for flux

    r = closestIntersection->geometry->material->color.r;
    g = closestIntersection->geometry->material->color.g;
    b = closestIntersection->geometry->material->color.b;

    //std::cout << "Depth" <<  depth << std::endl;
    if (depth > 4) return glm::vec3(r,g,b);

    if (closestIntersection->geometry->material->getMaterialType() == "Diffuse") {
        DiffuseMaterial* intersectionMaterial = (DiffuseMaterial*)closestIntersection->geometry->material;

        glm::vec3 normal = closestIntersection->normal;

        float normalLength = glm::length(normal);
        float phi = atan(normal[1]/normal[0]);
        if (normal[0] == 0) phi = glm::pi<float>()/2;
        float theta = atan(sqrt(pow(normal[0],2)+pow(normal[1],2))/normal[2]);
        if (normal[2] == 0) theta = glm::pi<float>()/2;

        float rand1,rand2;
        rand1 = std::rand()/(float)RAND_MAX;
        rand2 = std::rand()/(float)RAND_MAX;

        float phi2 = 2*glm::pi<float>()*rand1;
        float theta2 = asin(sqrt(rand2));

        phi = phi + phi2;
        theta = theta + theta2;

        float x,y,z;
        x = normalLength*cos(phi)*sin(theta);
        y = normalLength*sin(phi)*sin(theta);
        z = normalLength*cos(theta);

        glm::vec3 reflectedVector = glm::vec3(x,y,z);

        Ray* reflectedRay = new Ray(closestIntersection->point, reflectedVector + glm::vec3(closestIntersection->point), ray, false, intersectionMaterial->absorption*ray->importance);

        return (reflectedRay->importance*traceRay(reflectedRay, depth+1))/ray->importance + Ld*glm::vec3(1,1,1);
        //return glm::vec3(r,g,b)*Ld;
    }

    if (closestIntersection->geometry->material->getMaterialType() == "Light") { 
        
        //std::cout << "I LIGHT" << std::endl;
        return glm::vec3(100,100,100);
    }

    if (closestIntersection->geometry->material->getMaterialType() == "Mirror") { 
        MirrorMaterial* intersectionMaterial = (MirrorMaterial*)closestIntersection->geometry->material;

        glm::vec3 reflectedVector = ray->getVec3() - 2*(glm::dot(ray->getVec3(),closestIntersection->normal))*closestIntersection->normal;

        Ray* reflectedRay = new Ray(closestIntersection->point, reflectedVector + glm::vec3(closestIntersection->point), ray, false, intersectionMaterial->absorption*ray->importance);

        return (reflectedRay->importance*traceRay(reflectedRay, depth+1))/ray->importance + Ld*glm::vec3(1,1,1);
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
            /*if (closestIntersection->point[2] < -0.85 && closestIntersection->point[2] > -0.95) {
                std::cout << "CRIT" << std::endl;
                std::cout << "CLOSEST" << glm::to_string(closestIntersection->point) << std::endl;
            }*/
            reflectedRay = new Ray(closestIntersection->point, reflectedVector+glm::vec3(closestIntersection->point), ray, ray->isInObject, intersectionMaterial->absorption*ray->importance);
            return reflectedRay->importance*traceRay(reflectedRay, depth+1)/ray->importance;
            //return glm::vec3(0,1,1);
        }

        /*if (closestIntersection->point[2] == -4.5) {
            std::cout << "Point: " << glm::to_string(closestIntersection->point) << std::endl;
            std::cout << "Normal: " << glm::to_string(closestIntersection->normal) << std::endl;
        }*/

        reflectedRay = new Ray(closestIntersection->point, reflectedVector+glm::vec3(closestIntersection->point), ray, ray->isInObject, intersectionMaterial->absorption*ray->importance*0.04);

        glm::vec3 transmittedVector = (n1/n2) * I + N * (float)(-(n1/n2)*glm::dot(N,I) - sqrt(1 - pow(n1/n2,2)*(1 - pow(glm::dot(N,I),2)))); 
        
        Ray* transmittedRay = new Ray(glm::vec3(closestIntersection->point) + transmittedVector*0.001f, transmittedVector + glm::vec3(closestIntersection->point), ray, !ray->isInObject, intersectionMaterial->absorption*ray->importance*0.96); 

        Intersection* transIntersection = getIntersection(transmittedRay);

        //if (transIntersection->point[1] < 0.3 && transIntersection->point[1] > -0.3 && transIntersection->point[2] < 0.3 &&
        //    transIntersection->point[2] > -0.3) std::cout << "Point" << glm::to_string(transIntersection->point) << std::endl;

        return (reflectedRay->importance*traceRay(reflectedRay, depth+1) + transmittedRay->importance*traceRay(transmittedRay, depth+1))/ray->importance;
    }
    
}