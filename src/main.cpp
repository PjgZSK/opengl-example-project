#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "TeaEngine/TeaTime.hpp"
#include "example/DotApplication.hpp"
#include "TeaEngine/Template/TeaApplicationTemplate.hpp"

const GLuint WIDTH = 800, HEIGHT = 600;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

static GLFWwindow* initWindow()
{
    // init glfw
    glfwInit();

    // set glfw options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Example", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "glfw create windows failed" << std::endl;
        return NULL;
    }
    return window;
}

static int loadGLFunc()
{
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0)
    {
        std::cout << "glad load opengl function failed" << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    GLFWwindow* window = initWindow();
    if (window == NULL)
    {
        return -1;
    }
    glfwSetKeyCallback(window, key_callback);

    if (loadGLFunc() == -1)
    {
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);

    glfwPollEvents();

    using namespace Tea::Template;
    auto* app = TeaApplicationTemplate::Create<DotApplication>();
    Tea::GameEngine::TeaTime* ins = Tea::GameEngine::TeaTime::getInstance();
    while (glfwWindowShouldClose(window) == 0)
    {
        glfwPollEvents();

        float dt = ins->getDeltaTime();
        app->render(dt);
        ins->recordTime();

        glfwSwapBuffers(window);
    }

    TeaApplicationTemplate::Destory(app);
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // TODO(pjg):
    std::cout << "input key: " << key << std::endl;
}
