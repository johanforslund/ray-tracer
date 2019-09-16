#pragma once
#include "Vertex.hpp"
#include "Pixel.hpp"

class Camera {

public:
    Camera();
    ~Camera();

    void render();

private:
    Vertex eye1, eye2;
    bool farEye;
    Pixel pixels[800][800];
};