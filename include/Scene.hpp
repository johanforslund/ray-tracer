#pragma once
#include "Triangle.hpp"
#include "Tetrahedron.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "DiffuseMaterial.hpp"
#include "MirrorMaterial.hpp"
#include "TransparentMaterial.hpp"
#include <vector>
#include <math.h>
#include "Intersection.hpp"

class Scene {

public:
    Scene();
    ~Scene();

    Intersection* getIntersection(Ray* ray);
    glm::vec3 traceRay(Ray* ray, int depth = 0);

private:
    std::vector<Geometry*> geometryList;
};