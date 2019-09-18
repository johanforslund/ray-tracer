#include <iostream>
#include "Camera.hpp"
#include "Scene.hpp"

int main() {
    Camera camera = Camera();
    Scene scene = Scene();
    
    camera.render();

    for (int i =0; i<800; i++) {
        for (int j=0; j<800; j++) {
            scene.getIntersection(camera.pixels[i][j].ray);
        }
    }

    std::cout << camera.pixels[0][0].ray->color.r << camera.pixels[0][0].ray->color.g << camera.pixels[0][0].ray->color.b << std::endl;
    std::cout << camera.pixels[0][1].ray->color.r << camera.pixels[0][1].ray->color.g << camera.pixels[0][1].ray->color.b << std::endl;
    camera.createImage();

    std::cout << "Hello Easy C++ project!" << std::endl;
}