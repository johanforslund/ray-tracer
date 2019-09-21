#include "Sphere.hpp"

Sphere::Sphere(glm::vec4 _centerPos, float _radius, Color _color) : Geometry(_color) {
    centerPos = _centerPos;
    radius = _radius;
}

Sphere::~Sphere() {

}

Intersection* Sphere::rayIntersection(Ray* ray) {
    glm::vec4 l = glm::normalize(ray->end - ray->start);
    float b = glm::dot(2.0f*l, ray->start-centerPos);
    float c = glm::dot(ray->start - centerPos, ray->start - centerPos) - pow(radius, 2);


    float d1 = -(b/2) + sqrt(pow(b/2, 2)-c);
    float d2 = -(b/2) - sqrt(pow(b/2, 2)-c);

    float t;

    if (d1 < 0 || pow(b/2, 2) < c) return nullptr;
    else if (d2 > 0) t = d2;
    else t = d1;

    glm::vec4 intersectionPoint = ray->start + t*(glm::normalize(ray->end - ray->start));

    glm::vec3 normal = glm::normalize(intersectionPoint - centerPos);

    return new Intersection(t, this, intersectionPoint, normal);
}