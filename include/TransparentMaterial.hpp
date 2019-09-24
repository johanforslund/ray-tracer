#pragma once
#include "Color.hpp"
#include "Material.hpp"

class TransparentMaterial : public Material{

public:
    virtual ~TransparentMaterial() = default;

    TransparentMaterial(Color _color, float _absorption, float _refractiveIndex);

    virtual std::string getMaterialType() = 0;

    float refractiveIndex;
    float absorption;
};