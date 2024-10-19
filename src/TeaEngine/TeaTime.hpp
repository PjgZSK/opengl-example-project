#ifndef TEATIME_HPP
#define TEATIME_HPP

#include <chrono>
#include "./Template/TeaTemplate.hpp"

namespace Tea::GameEngine
{
    class TeaTime : public Template::Singleton<TeaTime>
    {
        using time_point = std::chrono::steady_clock::time_point;

        time_point _startTimePoint;
        time_point _lastTimePoint;

      private:
        void init();
        [[nodiscard]] time_point now() const;

      public:
        TeaTime() { init(); }
        ~TeaTime() = default;
        TeaTime(const TeaTime&) = delete;
        TeaTime(TeaTime&&) = delete;
        TeaTime& operator=(const TeaTime&) = delete;
        TeaTime& operator=(TeaTime&&) = delete;

        void recordTime();
        [[nodiscard]] float getDeltaTime() const
        {
            return std::chrono::duration<float>(now() - _lastTimePoint).count();
        }
        [[nodiscard]] float getTotalTime() const
        {
            return std::chrono::duration<float>(now() - _startTimePoint).count();
        }
    };
} // namespace Tea::GameEngine


#endif // TEATIME_HPP
