#pragma once
#include <glm/glm.hpp>

class Direction {

public:
    Direction();
    Direction(glm::vec3 _direction);

    ~Direction();

private:
    glm::vec3 direction;
};