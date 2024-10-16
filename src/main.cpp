#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

const GLuint WIDTH = 800, HEIGHT = 600;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
    // init glfw
    glfwInit();

    // set glfw options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* windows = glfwCreateWindow(WIDTH, HEIGHT, "Example", NULL, NULL);
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

    float vertexPositons[] = {
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositons), vertexPositons, GL_STATIC_DRAW);
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
    while (glfwWindowShouldClose(windows) == 0)
    {
        glfwPollEvents();

        glClearColor(0.2F, 0.3F, 0.3F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(windows);
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // TODO(pjg): 
    std::cout << "input key: " << key << std::endl;
}
