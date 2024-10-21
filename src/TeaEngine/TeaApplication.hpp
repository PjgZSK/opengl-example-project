#ifndef TeaApplication_HPP
#define TeaApplication_HPP

namespace Tea::GameEngine
{
    class TeaApplication
    {
      public:
        TeaApplication();
        virtual ~TeaApplication();

        TeaApplication(const TeaApplication&) = delete;
        TeaApplication(TeaApplication&&) = delete;
        TeaApplication& operator=(const TeaApplication&) = delete;
        TeaApplication& operator=(TeaApplication&&) = delete;

      protected:
        virtual void onConstruct() {}
        virtual void onDestruct() {}

      public:
        virtual void render(float deltaTime) {}
    };
} // namespace Tea::GameEngine

#endif
