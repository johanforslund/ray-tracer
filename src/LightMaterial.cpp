#include "LightMaterial.hpp"

LightMaterial::LightMaterial(Color _color, float _watt) : Material(_color){
    watt = _watt;
}

LightMaterial::~LightMaterial() {

}

std::string LightMaterial::getMaterialType() {
    return "Light";
}