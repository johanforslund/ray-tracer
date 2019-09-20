#include "Sphere.hpp"

Sphere::Sphere(glm::vec4 _centerPos, double _radius, ColorDbl _color) : Geometry(_color) {
    centerPos = _centerPos;
    radius = _radius;
}

Sphere::~Sphere() {

}

Intersection* Sphere::rayIntersection(Ray* ray) {
    glm::vec4 l = glm::normalize(ray->end - ray->start);
    double b = glm::dot(2.0f*l, ray->start-centerPos);
    double c = glm::dot(ray->start - centerPos, ray->start - centerPos) - pow(radius, 2);


    double d1 = -(b/2) + sqrt(pow(b/2, 2)-c);
    double d2 = -(b/2) - sqrt(pow(b/2, 2)-c);

    double t = d1 < d2 ? d1 : d2;

    return new Intersection(t, this, glm::vec4(1, 1, 1, 1));
}