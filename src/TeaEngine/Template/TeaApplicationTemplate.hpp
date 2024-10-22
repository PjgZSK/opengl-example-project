#ifndef TeaApplicationTemplate_HPP
#define TeaApplicationTemplate_HPP

#include <type_traits>

namespace Tea::GameEngine
{
    class TeaApplication;
}

namespace Tea::Template
{
    class TeaApplicationTemplate
    {
      public:
        template <typename T>
            requires std::is_base_of_v<Tea::GameEngine::TeaApplication, T>
        static inline T* Create()
        {
            T* t = new T();
            if (t != nullptr)
            {
                t->onConstruct();
            }
            return t;
        }

        template <typename T>
            requires std::is_base_of_v<Tea::GameEngine::TeaApplication, T>
        static inline void Destory(T* t)
        {
            if (t == nullptr)
            {
                return;
            }
            t->onDestruct();
            delete t;
        }
    };
} // namespace Tea::Template

#endif