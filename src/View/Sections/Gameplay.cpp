#include "Gameplay.hpp"
#include "../Section.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    Gameplay::Gameplay()
    {

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