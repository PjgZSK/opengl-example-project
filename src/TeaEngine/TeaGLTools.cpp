#include "TeaGLTools.hpp"
#include <iostream>

void Tea::GameEngine::TeaGLTools::CheckShaderCompile(GLuint shader, const GLchar* const code)
{
    GLint passCode = GL_TRUE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &passCode);
    if (passCode != GL_TRUE)
    {
        auto* infoLog = new GLchar[500];
        glGetShaderInfoLog(shader, 500, nullptr, infoLog);
        std::cout << "shader compile error:\n" << infoLog << std::endl;
        std::cout << "shader code:\n" << code << std::endl;
    }
}

void Tea::GameEngine::TeaGLTools::CheckProgramLink(GLuint program)
{
    GLint passCode = GL_TRUE;
    glGetProgramiv(program, GL_LINK_STATUS, &passCode);
    if (passCode != GL_TRUE)
    {
        auto* infoLog = new GLchar[500];
        glGetProgramInfoLog(program, 500, nullptr, infoLog);
        std::cout << "program link error:\n" << infoLog << std::endl;
    }
}

GLuint Tea::GameEngine::TeaGLTools::compileProgram(
    const GLchar* const vert,
    const GLchar* const frag,
    const GLchar* const tcs,
    const GLchar* const tes)
{
    // TODO(pjg): add error check
    auto vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vert, nullptr);
    glCompileShader(vShader);
    CheckShaderCompile(vShader, vert);

    auto fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &frag, nullptr);
    glCompileShader(fShader);
    CheckShaderCompile(fShader, frag);

    GLuint tcShader = 0;
    if (tcs != nullptr)
    {
        tcShader = glCreateShader(GL_TESS_CONTROL_SHADER);
        glShaderSource(tcShader, 1, &tcs, nullptr);
        glCompileShader(tcShader);

        CheckShaderCompile(tcShader, tcs);
    }

    GLuint teShader = 0;
    if (tes != nullptr)
    {
        teShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
        glShaderSource(teShader, 1, &tes, nullptr);
        glCompileShader(teShader);

        CheckShaderCompile(teShader, tes);
    }

    auto program = glCreateProgram();
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    if (tcShader != 0)
    {
        glAttachShader(program, tcShader);
    }
    if (teShader != 0)
    {
        glAttachShader(program, teShader);
    }

    glLinkProgram(program);
    CheckProgramLink(program);

    glDeleteShader(vShader);
    glDeleteShader(fShader);
    if (tcShader != 0)
    {
        glDeleteShader(tcShader);
    }
    if (teShader != 0)
    {
        glDeleteShader(teShader);
    }
    return program;
}
