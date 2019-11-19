#pragma once
#include "Pixel.hpp"
#include <glm/glm.hpp>

class Camera {

public:
    Camera();
    ~Camera();

    void render();
    void createImage();

    Pixel pixels[800][800];
private:
    glm::vec3 eye1, eye2;
    bool farEye;
    glm::vec3 cameraPlane[4];
};