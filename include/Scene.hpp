#pragma once
#include "Triangle.hpp"
#include "Ray.hpp"
#include <vector>

class Scene {

public:
    Scene();
    ~Scene();

    void intersectionTest(Ray ray);

private:
    std::vector<Triangle> triangleList;
};