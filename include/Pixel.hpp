#pragma once
#include "ColorDbl.hpp"
#include "Ray.hpp"

class Pixel {

public:
    Pixel();
    ~Pixel();

private:
    ColorDbl color;
    Ray ray;
};