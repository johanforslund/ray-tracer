#pragma once
#include "Vertex.hpp"
#include "Pixel.hpp"
#include <glm/glm.hpp>

class Camera {

public:
    Camera();
    ~Camera();

    void render();
    void createImage();

private:
    Vertex eye1, eye2;
    bool farEye;
    Pixel pixels[800][800];
};