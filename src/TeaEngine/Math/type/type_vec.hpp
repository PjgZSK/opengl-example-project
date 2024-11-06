#ifndef TYPE_VEC_HPP
#define TYPE_VEC_HPP

#include <initializer_list>
#include <algorithm>
#include <cmath>
#include <type_traits>

namespace Tea::Math::Type
{
    template <typename Tn>
    concept Scalarmulable = std::is_arithmetic_v<Tn>;

    using size_t = unsigned int;
    template <typename TData, size_t dim>
    class type_vec
    {
        using T = TData;
        using st = size_t;

      private:
        T _arr[dim] = {0};

      public:
        type_vec() = default;
        type_vec(std::initializer_list<T> list)
        {
            st i = 0;
            for (auto argu : list)
            {
                _arr[i] = argu;
                i++;
                if (i >= dim)
                {
                    break;
                }
            }
        }

        type_vec(const type_vec&) = default;
        type_vec(type_vec&&) = default;
        type_vec& operator=(const type_vec&) = default;
        type_vec& operator=(type_vec&&) = default;
        ~type_vec() = default;

        const T* arr() const { return _arr; }
        [[nodiscard]] st size() const { return dim; }

        T scalar()
        {
            T scalar = 0;
            std::for_each_n(_arr, dim, [&scalar](T t) { scalar += t * t; });
            scalar = std::sqrt(scalar);
            return scalar;
        }

        template <typename Func>
        static void componentWise(type_vec& res, type_vec& l, type_vec& r, Func func)
        {
            for (st i = 0; i < dim; i++)
            {
                res._arr[i] = func(l._arr[i], r._arr[i]);
            }
        }

        template <typename Func>
        static void componentWise(type_vec& l, type_vec& r, Func func)
        {
            for (st i = 0; i < dim; i++)
            {
                func(l._arr[i], r._arr[i]);
            }
        }

        static void add(type_vec& res, type_vec& l, type_vec& r)
        {
            componentWise(res, l, r, [](T tl, T tr) { return tl + tr; });
        }
        type_vec operator+(type_vec& r)
        {
            type_vec res;
            add(res, *this, r);
            return res;
        }
        type_vec& operator+=(type_vec& r)
        {
            add(*this, *this, r);
            return *this;
        }

        static void subtract(type_vec& res, type_vec& l, type_vec& r)
        {
            componentWise(res, l, r, [](T tl, T tr) { return tl - tr; });
        }
        type_vec operator-(type_vec& r)
        {
            type_vec res;
            subtract(res, *this, r);
            return res;
        }
        type_vec& operator-=(type_vec& r)
        {
            subtract(*this, *this, r);
            return *this;
        }

        template <Scalarmulable Tn>
        type_vec operator*(Tn n)
        {
            type_vec res;
            componentWise(res, *this, *this, [n](T tl, T) { return tl * n; });
            return res;
        }
        template <Scalarmulable Tn>
        type_vec& operator*=(Tn n)
        {
            componentWise(*this, *this, *this, [n](T tl, T) { return tl * n; });
            return *this;
        }

        static T dot(type_vec& l, type_vec& r)
        {
            T res = 0;
            componentWise(l, r, [](T tl, T tr) { res += tl * tr; });
            return res;
        }
        static type_vec<T, 3> cross(type_vec<T, 3>& l, type_vec<T, 3>& r)
        {
            type_vec<T, 3> res;
            res[0] = l[1] * r[2] - r[1] * l[2];
            res[1] = l[0] * r[2] - r[0] * l[2];
            res[2] = l[0] * r[1] - r[0] * l[1];
            return res;
        }

        T& operator[](st index) { return this->_arr[index]; }

        // alias
        T& x()
        {
            static_assert(dim > 0, "dim too small");
            return (*this)[0];
        }
        T& y()
        {
            static_assert(dim > 1, "dim too small");
            return (*this)[1];
        }
        T& z()
        {
            static_assert(dim > 2, "dim too small");
            return (*this)[2];
        }
        T& w()
        {
            static_assert(dim > 3, "dim too small");
            return (*this)[3];
        }

        T& r()
        {
            static_assert(dim > 0, "dim too small");
            return (*this)[0];
        }
        T& g()
        {
            static_assert(dim > 1, "dim too small");
            return (*this)[1];
        }
        T& b()
        {
            static_assert(dim > 2, "dim too small");
            return (*this)[2];
        }
        T& a()
        {
            static_assert(dim > 3, "dim too small");
            return (*this)[3];
        }
    };
} // namespace Tea::Math::Type


#endif // TYPE_VEC_HPP
