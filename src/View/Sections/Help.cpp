#include "Help.hpp"
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
        for(int i = 0; i < CONSOLE_WIDTH; i++)
                std::cout << "-";
            std::cout << std::endl;

        centerX(4);
        std::cout << "Help" << std::endl;
        for(int i = 0; i < CONSOLE_WIDTH; i++)
            std::cout << "-";
        std::cout << std::endl;
        std::string text = "\tYour goal is to collect as many fruits (";
        text += static_cast<char>(4);
        text += ") as possible without hitting yourself or a wall. Use key arrows \n\tto control snake. The amount of points you get depends on a distance between two ";
        text += "fruits. Be careful though! \n\tYour speed increases while getting more points. Good luck!";
        text += "\n\n";
        std::cout << text;
        char userInput = 0;
        while(userInput != '\b')
            userInput = _getch();

        system("cls");
        return MAIN_MENU;
    }
}
