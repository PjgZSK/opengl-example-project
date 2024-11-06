#include "TeaEngine/Math/vector/vec2.hpp"
#include "TeaEngine/Math/vector/vec3.hpp"
#include "TeaEngine/Math/vector/vec4.hpp"
#include <iostream>

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

void vectest()
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
}