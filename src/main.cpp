#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "TeaEngine/TeaTime.hpp"

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

    float vertexPositions[] = {
        0.0F,
        0.5F,
        0.0F,
        1.0F,
        0.5F,
        0.0F,
        0.0F,
        1.0F,
        1.0F,
        0.5F,
        0.0F,
        1.0F,
    };

    GLuint positionBufferObject = 0;
    glGenBuffers(1, &positionBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

    const char* vert_shader = R"( 
        #version 330 
        layout(location = 0) in vec4 pos;
        void main() 
        {
           gl_Position = pos; 
        } 
    )";


    const char* frag_shader = R"(
        #version 330
        out vec4 outColor;
        void main()
        {
            outColor = vec4(1.0, 1.0, 1.0, 1.0); 
        } 
    )";

    glfwPollEvents();

    Tea::GameEngine::TeaTime* ins = Tea::GameEngine::TeaTime::getInstance();
    while (glfwWindowShouldClose(window) == 0)
    {
        glfwPollEvents();

        float dt = ins->getDeltaTime();
        // do some animation work
        ins->recordTime();

        float currentTime = ins->getTotalTime();
        const GLfloat color[] = {
            sinf(currentTime) * 0.5F + 0.5F,
            cosf(currentTime) * 0.5F + 0.5F,
            0.0F,
            1.0F};
        glClearBufferfv(GL_COLOR, 0, color);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // TODO(pjg):
    std::cout << "input key: " << key << std::endl;
}
