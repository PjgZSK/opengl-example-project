#ifndef TeaGLTools_HPP
#define TeaGLTools_HPP

#include "glad/gl.h"

namespace Tea::GameEngine
{
    class TeaGLTools
    {
      public:
        static GLuint compileShader(const char* vert, const char* frag);
    };
} // namespace Tea::GameEngine

#endif