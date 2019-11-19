#include <iostream>
#include "Camera.hpp"
#include "Scene.hpp"

int main() {
    Camera camera = Camera();
    Scene scene = Scene();
    
    camera.render();

    for (int i =0; i<800; i++) {
        for (int j=0; j<800; j++) {
            glm::vec3 radiance = scene.traceRay(camera.pixels[i][j].ray);
            camera.pixels[i][j].color.r = radiance[0];
            camera.pixels[i][j].color.g = radiance[1];
            camera.pixels[i][j].color.b = radiance[2];

            //std::cout << radiance[0] << " " << radiance[1] << " " << radiance[2] << std::endl;
        }
    }

    camera.createImage();

    std::cout << "Reached end!" << std::endl;
}