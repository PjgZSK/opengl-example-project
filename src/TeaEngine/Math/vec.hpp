#ifndef vec_HPP
#define vec_HPP

namespace Tea::Math
{
    template <typename TData>
    class _vec2
    {
      private:
        TData* _arr = nullptr;

      public:
        _vec2()
            : _vec2(0, 0)
        {}
        _vec2(TData a1, TData a2)
            : _arr(new TData[2]{a1, a2})
        {}
        _vec2(const _vec2& c)
            : _arr(new TData[2])
        {
            _arr[0] = c._arr[0];
            _arr[1] = c._arr[1];
        }
        _vec2(_vec2&& c)
            : _arr(c._arr)
        {
            c._arr = nullptr;
        }
        _vec2& operator=(const _vec2& r)
        {
            this->_arr[0] = r._arr[0];
            this->_arr[1] = r._arr[1];
        }
        _vec2& operator=(_vec2&& r)
        {
            this->_arr = r._arr;
            r._arr = nullptr;
        }
        ~_vec2() { delete[] _arr; }
    };

    template <typename TData>
    class _vec3
    {
      private:
        TData* _arr = nullptr;

      public:
        _vec3()
            : _vec3(0, 0, 0)
        {}
        _vec3(TData a1, TData a2, TData a3)
            : _arr(new TData[3]{a1, a2, a3})
        {}
        _vec3(const _vec3& c)
            : _arr(new TData[3])
        {
            _arr[0] = c._arr[0];
            _arr[1] = c._arr[1];
            _arr[2] = c._arr[2];
        }
        _vec3(_vec3&& c)
            : _arr(c._arr)
        {
            c._arr = nullptr;
        }
        _vec3& operator=(const _vec3& r)
        {
            this->_arr[0] = r._arr[0];
            this->_arr[1] = r._arr[1];
            this->_arr[2] = r._arr[2];
        }
        _vec3& operator=(_vec3&& r)
        {
            this->_arr = r._arr;
            r._arr = nullptr;
        }
        ~_vec3() { delete[] _arr; }
    };

    template <typename TData>
    class _vec4
    {
      private:
        TData* _arr = nullptr;

      public:
        _vec4()
            : _vec4(0, 0, 0, 0)
        {}
        _vec4(TData a1, TData a2, TData a3, TData a4)
            : _arr(new TData[4]{a1, a2, a3, a4})
        {}
        _vec4(const _vec4& c)
            : _arr(new TData[4])
        {
            _arr[0] = c._arr[0];
            _arr[1] = c._arr[1];
            _arr[2] = c._arr[2];
            _arr[3] = c._arr[3];
        }
        _vec4(_vec4&& c)
            : _arr(c._arr)
        {
            c._arr = nullptr;
        }
        _vec4& operator=(const _vec4& r)
        {
            this->_arr[0] = r._arr[0];
            this->_arr[1] = r._arr[1];
            this->_arr[2] = r._arr[2];
            this->_arr[3] = r._arr[3];
        }
        _vec4& operator=(_vec4&& r)
        {
            this->_arr = r._arr;
            r._arr = nullptr;
        }
        ~_vec4() { delete[] _arr; }
    };
} // namespace Tea::Math

#endif