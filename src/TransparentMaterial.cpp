#include "TransparentMaterial.hpp"

TransparentMaterial::TransparentMaterial(Color _color, float _absorption, float _refractiveIndex) : Material(_color){
    absorption = _absorption;
    refractiveIndex = _refractiveIndex;
}

std::string TransparentMaterial::getMaterialType() {
    return "Transparent";
}