#ifndef DotApplication_HPP
#define DotApplication_HPP

#include "TeaApplication.hpp"
#include "glad/gl.h"

class DotApplication : public Tea::GameEngine::TeaApplication
{
    TeaAppPreProcess;

  private:
    GLuint programId;
    GLuint vertexArrayObj;
    float elapsed;

  public:
    void render(float deltaTime) override;

  protected:
    void onConstruct() override;
    void onDestruct() override;
};

#endif
