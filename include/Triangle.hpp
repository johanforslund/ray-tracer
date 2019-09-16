#pragma once
#include "Vertex.hpp"
#include "ColorDbl.hpp"
#include "Direction.hpp"
#include "Ray.hpp"

class Triangle {

public:
    Triangle();
    ~Triangle();

    void rayIntersection(Ray ray);

private:
    Vertex vertexList;
    ColorDbl color;
    Direction normalDirection;
};