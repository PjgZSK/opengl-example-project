#include "ShaderString.hpp"


const GLchar* const ShaderString::dot_vert_shader =
    R"(
#version 430 core

void main(void)
{
    gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
}
)";

const GLchar* const ShaderString::dot_frag_shader =
    R"(
#version 430 core

out vec4 color;

void main(void)
{
    color = vec4(0.0, 0.8, 1.0, 1.0);
}
)";