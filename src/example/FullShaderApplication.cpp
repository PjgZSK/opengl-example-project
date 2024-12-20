#include "FullShaderApplication.hpp"
#include "TeaGLTools.hpp"
#include "ShaderString.hpp"

void FullShaderApplication::render(float deltaTime)
{
    glClearBufferfv(GL_COLOR, 0, new GLfloat[]{0.0F, 0.0F, 0.0F, 1.0F});

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // glPointSize(5.0);

    glUseProgram(getProgramID());
    // glDrawArrays(GL_PATCHES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

GLuint FullShaderApplication::compileProgram()
{
    return Tea::GameEngine::TeaGLTools::compileProgram(
        ShaderString::full_vert_shader,
        ShaderString::full_frag_shader,
        /* ShaderString::full_tcontrol_shader */nullptr,
        /* ShaderString::full_tevaluation_shader */nullptr,
        /* ShaderString::full_geometry_shader */nullptr);
}
