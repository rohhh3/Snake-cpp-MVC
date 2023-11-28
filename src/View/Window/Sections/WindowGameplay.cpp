#include "WindowGameplay.hpp"
#include "../resources.hpp"

namespace View
{
    WindowGameplay::WindowGameplay()
    {

    }

    WindowGameplay::~WindowGameplay(){ }

    ESection WindowGameplay::execute()
    {
        return MAIN_MENU;
    }
}

