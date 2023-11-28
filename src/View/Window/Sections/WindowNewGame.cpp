#include "WindowNewGame.hpp"
#include "../resources.hpp"

namespace View
{
    WindowNewGame::WindowNewGame()
    {

    }

    WindowNewGame::~WindowNewGame(){ }

    ESection WindowNewGame::execute()
    {
        return MAIN_MENU;
    }

}
