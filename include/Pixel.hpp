#pragma once
#include "Color.hpp"
#include "Ray.hpp"

class Pixel {

public:
    Pixel();
    Pixel(Color _color);
    ~Pixel();

    Color color;
    Ray* ray;
};