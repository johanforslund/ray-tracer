#include "Ray.hpp"

Ray::Ray() {

}

Ray::Ray(glm::vec4 _start, glm::vec4 _end, Ray* _parent) {
    start = _start;
    end = _end;
    parent = _parent;
}

Ray::~Ray() {

}

glm::vec3 Ray::getVec3() {
    return glm::vec3(getVec4());
}

glm::vec4 Ray::getVec4() {
    return end - start;
}