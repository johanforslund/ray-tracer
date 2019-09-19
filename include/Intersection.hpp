#pragma once
#include "Geometry.hpp"
#include <glm/glm.hpp>

class Intersection {

public:
    Intersection(double _t, Geometry* _geometry, glm::vec4 _point);
    ~Intersection();

    double t;
    Geometry* geometry; 
    glm::vec4 point;
};