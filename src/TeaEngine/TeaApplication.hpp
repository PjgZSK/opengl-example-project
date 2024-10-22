#ifndef TeaApplication_HPP
#define TeaApplication_HPP

#include "TeaEngine/Template/TeaApplicationTemplate.hpp"

#define TeaAppPreProcess friend class Tea::Template::TeaApplicationTemplate

namespace Tea::GameEngine
{
    class TeaApplication
    {
        TeaAppPreProcess;

      public:
        TeaApplication(const TeaApplication&) = delete;
        TeaApplication(TeaApplication&&) = delete;
        TeaApplication& operator=(const TeaApplication&) = delete;
        TeaApplication& operator=(TeaApplication&&) = delete;

      protected:
        TeaApplication() = default;
        virtual ~TeaApplication() = default;

        virtual void onConstruct() {}
        virtual void onDestruct() {}

      public:
        virtual void render(float deltaTime) = 0;
    };
} // namespace Tea::GameEngine
#endif
