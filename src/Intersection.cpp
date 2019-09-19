#include "Intersection.hpp"


Intersection::Intersection(double _t, Geometry* _geometry, glm::vec4 _point) {
    t = _t; 
    geometry = _geometry;
    point = _point;
}


Intersection::~Intersection() {

}