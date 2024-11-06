#ifndef VEC3_HPP
#define VEC3_HPP

#include "../type/type_vec.hpp"

namespace Tea::Math::Vector
{
    template <typename TData>
    using vec3 = Tea::Math::Type::type_vec<TData, 3>;
}


#endif // VEC3_HPP
