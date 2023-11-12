#include "Help.hpp"
#include "../Section.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    Help::Help()
    {

    }

    Help::~Help(){ }

    ESection Help::execute()
    {
        SetConsoleTextAttribute(handle_console, 2); // set green color
        std::cout << title;
        SetConsoleTextAttribute(handle_console, 7); // back to default color
        char userInput = 0;
        while(userInput != '\b')
            userInput = _getch();

        system("cls");
        return MAIN_MENU;
    }
}
