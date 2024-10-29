#ifndef TeaGLTools_HPP
#define TeaGLTools_HPP

#include "glad/gl.h"

namespace Tea::GameEngine
{
    class TeaGLTools
    {
      public:
        static GLuint compileProgram(
            const GLchar*,
            const GLchar*,
            const GLchar* = nullptr,
            const GLchar* = nullptr,
            const GLchar* = nullptr);

      protected:
        static void CheckShaderCompile(GLuint, const GLchar*);
        static void CheckProgramLink(GLuint);

        static GLuint compileSingleShader(const GLchar*, GLenum);
        static void attachShaders(GLuint, const GLuint*, GLuint);
        static void deleteShaders(const GLuint*, GLuint);
    };
} // namespace Tea::GameEngine

#endif