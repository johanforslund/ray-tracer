#pragma once
#include "Color.hpp"
#include "Material.hpp"

class TransparentMaterial : public Material{

public:
    ~TransparentMaterial();

    TransparentMaterial(Color _color, float _absorption, float _refractiveIndex);

    virtual std::string getMaterialType();

    float refractiveIndex;
    float absorption;
};