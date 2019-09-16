#pragma once
#include "Triangle.hpp"
#include "Ray.hpp"

class Scene {

public:
    Scene();
    ~Scene();

    void intersectionTest(Ray ray);

private:
    static const int TRIANGLE_AMOUNT = 24;
    Triangle triangleList[TRIANGLE_AMOUNT];
};