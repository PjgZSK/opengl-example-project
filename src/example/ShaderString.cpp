#include "ShaderString.hpp"


const GLchar* const ShaderString::dot_vert_shader =
    R"(
#version 330

void main()
{
    gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
}
)";

const GLchar* const ShaderString::dot_frag_shader =
    R"(
#version 330

out vec4 color;

void main()
{
    color = vec4(0.0, 0.8, 1.0, 1.0);
}
)";