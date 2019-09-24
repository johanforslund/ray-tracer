#pragma once
#include "Material.hpp"
#include "Color.hpp"

class MirrorMaterial : public Material{

public:
    MirrorMaterial(Color _color, float _absorption);
    ~MirrorMaterial();

    std::string getMaterialType();

    float absorption;
};