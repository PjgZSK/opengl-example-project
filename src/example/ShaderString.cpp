#include "ShaderString.hpp"


const GLchar* const ShaderString::dot_vert_shader =
    R"(
#version 410 core

void main(void)
{
    const vec4 vertices[3] = vec4[3](
        vec4(-0.5, -0.5, 0.5, 1.0),
        vec4(0.5, 0.5, 0.5, 1.0),
        vec4(0.5, -0.5, 0.5, 1.0)
    );
    gl_Position = vertices[gl_VertexID];
}
)";

const GLchar* const ShaderString::dot_frag_shader =
    R"(
#version 410 core

out vec4 color;

void main(void)
{
    color = vec4(0.0, 0.8, 1.0, 1.0);
}
)";