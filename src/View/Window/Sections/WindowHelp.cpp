#include "WindowHelp.hpp"
#include "../resources.hpp"

namespace View
{
    WindowHelp::WindowHelp()
    {

    }

    WindowHelp::~WindowHelp(){ }

    ESection WindowHelp::execute()
    {
        return MAIN_MENU;
    }
}
