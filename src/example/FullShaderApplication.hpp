#ifndef FullShaderApplication_HPP
#define FullShaderApplication_HPP

#include "DotApplication.hpp"

class FullShaderApplication : public DotApplication 
{
    TeaAppPreProcess;

  public:
    void render(float /*deltaTime*/) override;    
    GLuint compileProgram() override;
};

#endif