#include "MirrorMaterial.hpp"


MirrorMaterial::MirrorMaterial(Color _color, float _absorption) : Material(_color) {
    absorption = _absorption;
}

MirrorMaterial::~MirrorMaterial() {

}

std::string MirrorMaterial::getMaterialType() {
    return "Mirror";
}
