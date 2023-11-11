#include "Scores.hpp"
#include "../Section.hpp"
#include "../../Model/ModelCore.hpp"
#include <iostream>
#include <conio.h>

namespace View
{
    ESection Scores::execute()
    {
        current_page = 0;
        total_pages  = (int16_t)(Controller::getScoreboardSize() - 1) / MAX_ELEMENTS_ON_PAGE;
        int padding = 0;
        scores_on_page.reserve(MAX_ELEMENTS_ON_PAGE);

        SetConsoleTextAttribute(handle_console, 2); // set green color
        std::cout << title;
        SetConsoleTextAttribute(handle_console, 7); // back to default color

        for(int i = 0; i < CONSOLE_WIDTH; i++)
            std::cout << "-";
        std::cout << std::endl;
        padding = (CONSOLE_WIDTH - 10) / 2; // 10 is the length of "High Scores" string
        for(int i = 0; i < padding; i++)
            std::cout << " ";
        std::cout << "High Scores" << std::endl;
        for(int i = 0; i < CONSOLE_WIDTH; i++)
            std::cout << "-";
        std::cout << std::endl;

        padding = (CONSOLE_WIDTH - 3) / 2;
        for(int i = 0; i < padding; i++)
            std::cout << " ";
        std::cout << current_page + 1 << "/" << total_pages + 1 << std::endl;

        char userInput = 0;
        while(userInput != '\b')
            userInput = _getch();

        system("cls");
        return MAIN_MENU;
    }
}
