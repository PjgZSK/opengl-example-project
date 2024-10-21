#include "TeaApplication.hpp"

Tea::GameEngine::TeaApplication::TeaApplication()
{
    onConstruct();
}

Tea::GameEngine::TeaApplication::~TeaApplication()
{
    onDestruct();
}
