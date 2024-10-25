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
            const GLchar* = nullptr);

      protected:
        static void CheckShaderCompile(GLuint, const GLchar*);
        static void CheckProgramLink(GLuint);
    };
} // namespace Tea::GameEngine

#endif