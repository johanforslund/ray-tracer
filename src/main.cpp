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

    camera.createImage();

    std::cout << "Hello Easy C++ project!" << std::endl;
}