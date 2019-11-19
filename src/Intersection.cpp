#include "Intersection.hpp"


Intersection::Intersection(float _t, Geometry* _geometry, glm::vec4 _point, glm::vec3 _normal) {
    t = _t; 
    geometry = _geometry;
    point = _point;
    normal = _normal;
}


Intersection::~Intersection() {

}