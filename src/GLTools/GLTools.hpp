#ifndef __GLTOOLS_HPP__
#define __GLTOOLS_HPP__

#include <glad/gl.h>
#include <string>
class GLTools
{
public:
    static GLuint CreateShader(std::string shaderCode);
    static GLuint CreateProgram(GLuint vert_shader, GLuint frag_shader);
};
#endif