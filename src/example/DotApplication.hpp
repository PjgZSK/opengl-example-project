#ifndef DotApplication_HPP
#define DotApplication_HPP

#include "TeaApplication.hpp"
#include "glad/gl.h"

class DotApplication : public Tea::GameEngine::TeaApplication
{
    TeaAppPreProcess;

  private:
    GLuint programID;
    GLuint vertexArrayObj;
    float elapsed;

  public:
    void render(float deltaTime) override;

    [[nodiscard]] GLuint getProgramID() const { return programID; }

    [[nodiscard]] GLuint getVertexArrayObj() const { return vertexArrayObj; }
    [[nodiscard]] float getElapsed() const { return elapsed; }

  protected:
    void setVertexArrayObj(const GLuint vertexArrayObj_) { vertexArrayObj = vertexArrayObj_; }
    void setProgramID(const GLuint programID_) { programID = programID_; }
    void setElapsed(float elapsed_) { elapsed = elapsed_; }

    void onConstruct() override;
    void onDestruct() override;

    virtual GLuint compileProgram(); 
};

#endif
