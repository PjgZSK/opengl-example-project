#include "TeaTime.hpp"

void Tea::GameEngine::TeaTime::init()
{
    _startTimePoint = _lastTimePoint = now();
}

Tea::GameEngine::TeaTime::time_point Tea::GameEngine::TeaTime::now() const
{
    return std::chrono::steady_clock::now();
}

void Tea::GameEngine::TeaTime::recordTime()
{
    _lastTimePoint = now();
}
