#ifndef VEC4_HPP
#define VEC4_HPP

#include "../type/type_vec.hpp"

namespace Tea::Math::Vector
{
    template <typename TData>
    using vec4 = Tea::Math::Type::type_vec<TData, 4>;
}


#endif // VEC4_HPP
