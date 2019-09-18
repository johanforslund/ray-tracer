#pragma once
#include "ColorDbl.hpp"
#include "Ray.hpp"

class Pixel {

public:
    Pixel();
    Pixel(ColorDbl _color);
    ~Pixel();

    ColorDbl color;
    Ray* ray;
};