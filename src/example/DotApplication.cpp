#include "DotApplication.hpp"
#include <cmath>
#include "ShaderString.hpp"
#include "TeaGLTools.hpp"

void DotApplication::render(float deltaTime)
{
    elapsed += deltaTime;
    glClearBufferfv(GL_COLOR, 0, new GLfloat[]{1.0F, 1.0F, 1.0F, 1.0F});

    const GLfloat attrib[] = {sinf(elapsed) * 0.5F, cosf(elapsed) * 0.5F, 0, 0};
    glVertexAttrib4fv(0, attrib);

    const GLfloat color[] = {sinf(elapsed) * 0.5F + 0.5F, cosf(elapsed) * 0.5F + 0.5F, 0, 0};
    glVertexAttrib4fv(1, color);

    // glPointSize(40);
    glUseProgram(programID);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DotApplication::onConstruct()
{
    elapsed = 0.0F;
    programID = compileProgram(); 
    glGenVertexArrays(1, &vertexArrayObj);
    glBindVertexArray(vertexArrayObj);
}

void DotApplication::onDestruct()
{
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &vertexArrayObj);
}

GLuint DotApplication::compileProgram()
{
    return Tea::GameEngine::TeaGLTools::compileProgram(
        ShaderString::dot_vert_shader,
        ShaderString::dot_frag_shader);
}
