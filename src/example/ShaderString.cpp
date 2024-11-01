#include "ShaderString.hpp"


const GLchar* const ShaderString::dot_vert_shader =
    R"(
#version 410 core

layout (location = 0) in vec4 offset;
layout (location = 1) in vec4 color;

out VS_OUT
{
    vec4 vs_color;
}vs_out;

void main(void)
{
    const vec4 vertices[3] = vec4[3](
        vec4(-0.5, -0.5, 0.5, 1.0),
        vec4(0.5, 0.5, 0.5, 1.0),
        vec4(0.5, -0.5, 0.5, 1.0)
    );
    gl_Position = vertices[gl_VertexID] + offset;
    vs_out.vs_color = color;
}
)";

const GLchar* const ShaderString::dot_frag_shader =
    R"(
#version 410 core

in VS_OUT
{
    vec4 vs_color;
}fs_in;

out vec4 color;

void main(void)
{
    color = fs_in.vs_color;
}
)";

const GLchar* const ShaderString::full_vert_shader =
    R"(
#version 410 core

out vec4 vs_color;

void main(void)
{
    const vec4 vertices[3] = vec4[3](
        vec4(-0.5, -0.5, 0.5, 1.0),
        vec4(0.5, 0.5, 0.5, 1.0),
        vec4(0.5, -0.5, 0.5, 1.0)
    );
    const vec4 color[3] = vec4[3](
        vec4(1.0, 0.0, 0.0, 1.0),
        vec4(0.0, 1.0, 0.0, 1.0),
        vec4(0.0, 0.0, 1.0, 1.0)
    );

    gl_Position = vertices[gl_VertexID];
    vs_color = color[gl_VertexID];
}
)";

// skipped
const GLchar* const ShaderString::full_tcontrol_shader =
    R"(
#version 410 core

layout (vertices = 3) out;

void main(void)
{
    if (gl_InvocationID == 0)
    {
        gl_TessLevelInner[0] = 5.0;
        gl_TessLevelOuter[0] = 5.0;
        gl_TessLevelOuter[1] = 5.0;
        gl_TessLevelOuter[2] = 5.0;
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}
)";

// skipped
const GLchar* const ShaderString::full_tevaluation_shader =
    R"(
#version 410 core

layout (triangles, equal_spacing, cw) in;

void main(void)
{
    gl_Position = ( gl_TessCoord.x * gl_in[0].gl_Position +
                    gl_TessCoord.y * gl_in[1].gl_Position + 
                    gl_TessCoord.z * gl_in[2].gl_Position);
}
)";

// skipped 
const GLchar* const ShaderString::full_geometry_shader =
    R"(
#version 410 core

layout(triangles) in;
layout(points, max_vertices = 3) out;

void main(void)
{
    for (int i = 0; i < gl_in.length(); i++)
    {
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }
}
)";

const GLchar* const ShaderString::full_frag_shader =
    R"(
#version 410 core

out vec4 color;

in vec4 vs_color;

void main(void)
{
    // color = vec4(sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5, 
    //             cos(gl_FragCoord.y * 0.25) * 0.5 + 0.5, 
    //             sin(gl_FragCoord.x * 0.15) * cos(gl_FragCoord.y * 0.15), 
    //             1.0);
    color = vs_color;
}
)";

