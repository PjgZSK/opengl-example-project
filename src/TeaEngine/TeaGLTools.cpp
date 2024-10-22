#include "TeaGLTools.hpp"

GLuint Tea::GameEngine::TeaGLTools::compileShader(
    const GLchar* const vert,
    const GLchar* const frag)
{
    // TODO(pjg): add error check
    auto vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vert, nullptr);
    glCompileShader(vShader);

    auto fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &frag, nullptr);
    glCompileShader(fShader);

    auto program = glCreateProgram();
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);

    glDeleteShader(vShader);
    glDeleteShader(fShader);

    return program;
}
