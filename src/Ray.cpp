#include "Ray.hpp"

Ray::Ray() {

}

Ray::Ray(glm::vec3 _start, glm::vec3 _end, Ray* _parent, bool _isInObject ,float _importance) {
    start = glm::vec4(_start, 1);
    end = glm::vec4(_end, 1);
    parent = _parent;
    isInObject = _isInObject;
    importance = _importance;
}

Ray::~Ray() {

}

glm::vec3 Ray::getVec3() {
    return glm::vec3(getVec4());
}

glm::vec4 Ray::getVec4() {
    return end - start;
}