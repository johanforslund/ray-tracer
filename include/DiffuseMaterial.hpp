#pragma once
#include "Material.hpp"

class DiffuseMaterial : public Material{

public:
    DiffuseMaterial(Color _color, float _absorption);
    ~DiffuseMaterial();

    std::string getMaterialType();

    float absorption;
};