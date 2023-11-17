#include "Gameplay.hpp"
#include "../Section.hpp"
#include "../../Model/GameCore.hpp"
#include "../../Controller/Controller.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    Gameplay::Gameplay()
    {
        Controller::resetGameplay();
    }

    Gameplay::~Gameplay(){ }
    ESection Gameplay::execute()
    {
        char userInput = 0;
        while(userInput != '\b')
            userInput = _getch();

        system("cls");
        return MAIN_MENU;
    }
}
