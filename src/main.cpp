#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

const GLuint WIDTH = 800, HEIGHT = 600;
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods);

int main()
{
    // init glfw
    glfwInit();

    // set glfw options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *windows =
        glfwCreateWindow(WIDTH, HEIGHT, "Example", NULL, NULL);
    glfwMakeContextCurrent(windows);
    if (windows == NULL)
    {
        std::cout << "glfw create windows failed" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(windows, key_callback);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0)
    {
        std::cout << "glad load opengl function failed" << std::endl;
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(windows))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(windows);
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods)
{
    // TODO
    std::cout << "input key: " << key << std::endl;
}