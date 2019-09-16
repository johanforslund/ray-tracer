#pragma once
#include "Vertex.hpp"
#include "ColorDbl.hpp"

class Triangle;

class Ray {

public:
    Ray();
    ~Ray();

private:
    Vertex start, end;
    ColorDbl color;
    Triangle* endTriangle;
};