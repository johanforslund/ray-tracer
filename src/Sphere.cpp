#include "Sphere.hpp"

Sphere::Sphere(glm::vec4 _centerPos, float _radius, Material* _material) : Geometry(_material) {
    centerPos = _centerPos;
    radius = _radius;
}

Sphere::~Sphere() {

}

Intersection* Sphere::rayIntersection(Ray* ray) {
    glm::vec3 sphereNormal = glm::vec3(ray->start - centerPos);
    if (glm::dot(ray->getVec3(), sphereNormal) > 0) return nullptr; // Could maybe not work
    glm::vec3 l = glm::normalize(ray->getVec3());
    float b = glm::dot(2.0f*l, sphereNormal);
    float c = glm::dot(sphereNormal, sphereNormal) - pow(radius, 2);

    if (pow(b/2, 2) < c) return nullptr;

    float d1 = -(b/2) + sqrt(pow(b/2, 2)-c);
    float d2 = -(b/2) - sqrt(pow(b/2, 2)-c);

    float t;

    if (d1 < 0) return nullptr;
    else if (d2 > 0) t = d2;
    else t = d1;

    if (t < 0) return nullptr;

    glm::vec4 intersectionPoint = ray->start + t*(glm::normalize(ray->end - ray->start));

    glm::vec3 normal = glm::normalize(intersectionPoint - centerPos);

    return new Intersection(t, this, intersectionPoint, normal);
}

std::string Sphere::getName() {
    return "Sphere";
}

void Sphere::translate(float x, float y, float z) {
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));
    centerPos = translationMatrix*centerPos;
}
