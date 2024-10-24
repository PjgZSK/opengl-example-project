#include "DotApplication.hpp"
#include <cmath>
#include "ShaderString.hpp"
#include "TeaGLTools.hpp"

void DotApplication::render(float deltaTime)
{
    elapsed += deltaTime;
    const GLfloat color[] = {
        std::sinf(elapsed * 0.5F) + 0.5F,
        std::cosf(elapsed * 0.5F) + 0.5F,
        0.0F,
        1.0F};
    glClearBufferfv(GL_COLOR, 0, color);

    glPointSize(40);
    glUseProgram(programID);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DotApplication::onConstruct()
{
    elapsed = 0.0F;
    programID = Tea::GameEngine::TeaGLTools::compileShader(
        ShaderString::dot_vert_shader,
        ShaderString::dot_frag_shader);
    glGenVertexArrays(1, &vertexArrayObj);
    glBindVertexArray(vertexArrayObj);
}

void DotApplication::onDestruct()
{
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &vertexArrayObj);
}
