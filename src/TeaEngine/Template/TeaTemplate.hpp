#ifndef TeaTemplate_HPP
#define TeaTemplate_HPP

namespace Tea::Template
{
    template <typename T>
    class Singleton
    {
        inline static T* _ins = nullptr;

    public:
        inline static T* getInstance()
        {
            if (_ins == nullptr)
            {
                _ins = new T();
            }
            return _ins;
        }
    };
} // namespace Tea::Template

#endif