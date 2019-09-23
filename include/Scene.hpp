#pragma once
#include "Triangle.hpp"
#include "Tetrahedron.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include <vector>
#include <math.h>
#include "Intersection.hpp"

class Scene {

public:
    Scene();
    ~Scene();

    Intersection* getIntersection(Ray* ray);
    void colorizeRay(Ray* ray);

private:
    std::vector<Geometry*> geometryList;
};