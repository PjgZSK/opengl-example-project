#include "DotApplication.hpp"

void DotApplication::render(float deltaTime) {}

void DotApplication::onConstruct()
{
    // TODO(pjg): compile shader program
    glGenVertexArrays(1, &vertexArrayObj);
    glBindVertexArray(vertexArrayObj);
}

void DotApplication::onDestruct()
{
    // TODO(pjg): delete shader pragram
    glDeleteVertexArrays(1, &vertexArrayObj);
}
