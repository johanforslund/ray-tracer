#pragma once
#include "Material.hpp"

class DiffuseMaterial : public Material{

public:
    DiffuseMaterial(Color _color);
    ~DiffuseMaterial();

    std::string getMaterialType();
};