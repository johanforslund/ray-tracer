#include "Scene.hpp"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::intersectionTest(Ray ray) {
    for (int i=0; i<TRIANGLE_AMOUNT; i++) {
        triangleList[i].rayIntersection(ray);
    }
}