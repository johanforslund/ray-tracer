#pragma once
#include "Color.hpp"
#include <glm/glm.hpp>
#include <string>

class Material {

public:
    Material(Color _color) : color(_color) {};
    virtual ~Material() = default;

    virtual std::string getMaterialType() = 0;

    Color color;
};