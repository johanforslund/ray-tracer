#pragma once
#include "Triangle.hpp"
#include "Tetrahedron.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "Rectangle.hpp"
#include "Ray.hpp"
#include "DiffuseMaterial.hpp"
#include "MirrorMaterial.hpp"
#include "TransparentMaterial.hpp"
#include "LightMaterial.hpp"
#include <vector>
#include <math.h>
#include "Intersection.hpp"
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/constants.hpp>

class Scene {

public:
    Scene();
    ~Scene();

    Intersection* getIntersection(Ray* ray, bool ignoreTransparent = false);
    glm::vec3 traceRay(Ray* ray, int depth = 0);

private:
    std::vector<Geometry*> geometryList;
};