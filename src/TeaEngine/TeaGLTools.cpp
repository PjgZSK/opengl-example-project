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

GLuint Tea::GameEngine::TeaGLTools::compileSingleShader(const GLchar* const tes, GLenum shaderType)
{
    GLuint teShader = 0;
    if (tes != nullptr)
    {
        teShader = glCreateShader(shaderType);
        glShaderSource(teShader, 1, &tes, nullptr);
        glCompileShader(teShader);

        CheckShaderCompile(teShader, tes);
    }
    return teShader;
}
void Tea::GameEngine::TeaGLTools::attachShaders(GLuint program, const GLuint* shaders, GLuint count)
{
    for (GLuint i = 0; i < count; i++)
    {
        if (shaders[i] == 0)
        {
            continue;
        }
        glAttachShader(program, shaders[i]);
    }
}
void Tea::GameEngine::TeaGLTools::deleteShaders(const GLuint* shaders, GLuint count)
{
    for (GLuint i = 0; i < count; i++)
    {
        if (shaders[i] == 0)
        {
            continue;
        }
        glDeleteShader(shaders[i]);
    }
}
GLuint Tea::GameEngine::TeaGLTools::compileProgram(
    const GLchar* const vert,
    const GLchar* const frag,
    const GLchar* const tcs,
    const GLchar* const tes,
    const GLchar* const geometry)
{
    const GLuint shaderCount = 5;
    const auto* shaders = new GLuint[shaderCount]{
        compileSingleShader(vert, GL_VERTEX_SHADER),
        compileSingleShader(frag, GL_FRAGMENT_SHADER),
        compileSingleShader(tcs, GL_TESS_CONTROL_SHADER),
        compileSingleShader(tes, GL_TESS_EVALUATION_SHADER),
        compileSingleShader(geometry, GL_GEOMETRY_SHADER),
    };

    auto program = glCreateProgram();
    attachShaders(program, shaders, shaderCount);
    glLinkProgram(program);
    CheckProgramLink(program);
    deleteShaders(shaders, shaderCount);

    return program;
}
