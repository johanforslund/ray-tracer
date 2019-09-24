#include "DiffuseMaterial.hpp"

DiffuseMaterial::DiffuseMaterial(Color _color) : Material(_color){

}

DiffuseMaterial::~DiffuseMaterial() {

}

std::string DiffuseMaterial::getMaterialType() {
    return "Diffuse";
}