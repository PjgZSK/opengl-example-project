#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "TeaEngine/TeaTime.hpp"
#include "example/DotApplication.hpp"
#include "example/FullShaderApplication.hpp"
#include "TeaEngine/Template/TeaApplicationTemplate.hpp"
#include "TeaEngine/Math/vector/vec2.hpp"
#include "TeaEngine/Math/vector/vec3.hpp"
#include "TeaEngine/Math/vector/vec4.hpp"


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

/*
positive 2d coordinate
cos     sin
-sin    cos
negative 2d coordinate
cos     -sin
sin     cos

counterclockwise
left-handed coordinate
x
1       0       0
0       cos     -sin
0       sin    cos

y
cos     0       sin
0       1       0
-sin    0       cos

z
cos     -sin    0
sin     cos     0
0       0       1


counterclockwise
right-handed coordinate
x
1   0   0
0   cos sin
0   -sin cos

y
cos     0   -sin
0       1   0
sin     0   cos

there is a counterclockwise issue that the view point is 'out' of screen which
is -z in right-handed coordinate
z
cos     -sin    0
sin     cos     0
0       0       1
*/

using Tea::Math::Type::type_vec;
template <typename T, Tea::Math::Type::size_t t>
void printVec(type_vec<T, t>* vec)
{
    for (unsigned i = 0; i < vec->size(); i++)
    {
        std::cout << (*vec)[i] << "\t";
    }
    std::cout << "scalar is " << vec->scalar() << "\n" << std::endl;
}

int main()
{
    /***************type_vec test****************/
    using vec2f = Tea::Math::Vector::vec2<float>;
    auto* v = new vec2f{1, 3, 4, 7};
    // iterate test
    printVec(v);
    // constructor test
    auto* v1 = new vec2f(*v);
    printVec(v1);
    auto* v2 = new vec2f(std::move(*v));
    printVec(v2);
    // assignment test
    auto* v3 = new vec2f();
    *v3 = *v1;
    printVec(v3);
    auto* v4 = new vec2f{3, 4};
    *v4 = std::move(*v1);
    printVec(v4);
    // add, subtract
    printVec(new vec2f(*v3 + *v4));
    *v3 += *v4;
    printVec(v3);
    *v3 -= *v4;
    printVec(v3);
    // scalar mul
    printVec(new vec2f(*v3 * 10));
    *v3 *= 0.1;
    printVec(v3);
    // alias test
    using vec4f = Tea::Math::Vector::vec4<float>;
    vec4f v1_{2, 10, 1, 100};
    printf("x,y,z,w = %f, %f, %f, %f\n", v1_.x(), v1_.y(), v1_.z(), v1_.w());
    printf("r,g,b,a = %f, %f, %f, %f\n", v1_.r(), v1_.g(), v1_.b(), v1_.a());

    using vec3f = Tea::Math::Vector::vec3<float>;
    vec3f _v1{1, 3, 4};
    vec3f _v2{3, 1, 10};
    auto _v3 = vec3f::cross(_v1, _v2);
    // _v1.w();
    printVec(&_v3);
    /******************************************/

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
    auto* app = TeaApplicationTemplate::Create<FullShaderApplication>();
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
