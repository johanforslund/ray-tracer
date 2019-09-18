#include "Ray.hpp"

Ray::Ray() {

}

Ray::Ray(glm::vec4 _start, glm::vec4 _end) {
    start = _start;
    end = _end;
}

Ray::~Ray() {

}