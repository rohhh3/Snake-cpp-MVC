#include "Gameplay.hpp"
#include "../Section.hpp"
#include "../../Model/GameCore.hpp"
#include "../../Controller/Controller.hpp"
#include <iostream>
namespace View
{
    Gameplay::Gameplay()
    {
        Controller::resetGameplay();
    }

    Gameplay::~Gameplay(){ }
    ESection Gameplay::execute()
    {
        is_gameplay_running = true;
        while(is_gameplay_running)
        {
            Controller::handleUserInput();
            Controller::moveSnake();

        }
        return EXIT;
    }
}
