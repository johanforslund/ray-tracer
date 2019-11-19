#include "DiffuseMaterial.hpp"

DiffuseMaterial::DiffuseMaterial(Color _color, float _absorption) : Material(_color){
    absorption = _absorption;
}

DiffuseMaterial::~DiffuseMaterial() {

}

std::string DiffuseMaterial::getMaterialType() {
    return "Diffuse";
}