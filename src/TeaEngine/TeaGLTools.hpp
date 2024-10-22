#ifndef TeaGLTools_HPP
#define TeaGLTools_HPP

#include "glad/gl.h"

namespace Tea::GameEngine
{
    class TeaGLTools
    {
      public:
        static GLuint compileShader(const GLchar*  vert, const GLchar* frag);
    };
} // namespace Tea::GameEngine

#endif