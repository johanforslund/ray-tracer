#pragma once
#include "Geometry.hpp"
#include <glm/glm.hpp>

class Intersection {

public:
    Intersection(float _t, Geometry* _geometry, glm::vec4 _point, glm::vec3 _normal);
    ~Intersection();

    glm::vec3 normal;
    float t;
    Geometry* geometry; 
    glm::vec4 point;
};