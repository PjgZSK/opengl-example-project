#ifndef ShaderString_HPP
#define ShaderString_HPP

#include "glad/gl.h"

class ShaderString
{
  public:
    static const GLchar* const dot_vert_shader;
    static const GLchar* const dot_frag_shader;

    static const GLchar* const full_vert_shader;
    static const GLchar* const full_frag_shader;
    static const GLchar* const full_tcontrol_shader;
    static const GLchar* const full_tevaluation_shader;
    static const GLchar* const full_geometry_shader;
};
#endif