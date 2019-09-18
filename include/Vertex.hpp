#pragma once
#include <glm/glm.hpp>

class Vertex {

public:
    Vertex();

    Vertex(glm::vec4 _vertex);

    ~Vertex();

private:

private:
    glm::vec4 vertex;
};