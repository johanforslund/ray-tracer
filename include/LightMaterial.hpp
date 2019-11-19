#pragma once
#include "Color.hpp"
#include "Material.hpp"

class LightMaterial : public Material {

public:
    LightMaterial(Color _color, float _watt);

    ~LightMaterial();

    std::string getMaterialType();

    float watt;
};