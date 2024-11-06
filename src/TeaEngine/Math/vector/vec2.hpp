#ifndef vec2_HPP
#define vec2_HPP

#include "../type/type_vec.hpp"

namespace Tea::Math::Vector
{
    template <typename TData>
    using vec2 = Tea::Math::Type::type_vec<TData, 2>;
}

#endif