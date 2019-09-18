#pragma once
#include "Vertex.hpp"
#include "ColorDbl.hpp"
#include "Direction.hpp"
#include "Ray.hpp"
#include <glm/glm.hpp>

class Triangle {

public:
    Triangle();

    Triangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl _color, Direction _normalDirection);
    
    ~Triangle();

    void rayIntersection(Ray ray);

private:
    Vertex vertexList[3];
    ColorDbl color;
    Direction normalDirection;
};