#include "Help.hpp"
#include "../Section.hpp"
#include "../ViewFunctions.hpp"
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
        printHeader();
        char userInput = 0;
        while(userInput != '\b')
            userInput = _getch();

        system("cls");
        return MAIN_MENU;
    }
}
