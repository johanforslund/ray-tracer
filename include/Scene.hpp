#pragma once
#include "Triangle.hpp"
#include "Ray.hpp"
#include <vector>

class Scene {

public:
    Scene();
    ~Scene();

    void getIntersection(Ray* ray);

private:
    std::vector<Triangle> triangleList;
};