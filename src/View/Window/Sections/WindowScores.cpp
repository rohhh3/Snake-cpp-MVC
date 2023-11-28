#include "WindowScores.hpp"
#include "../resources.hpp"

namespace View
{
    WindowScores::WindowScores()
    {

    }

    WindowScores::~WindowScores(){ }

    ESection WindowScores::execute()
    {
        return MAIN_MENU;
    }
}
