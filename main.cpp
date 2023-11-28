#include "src/View/ConsoleInit.hpp"
#include "src/View/Sections/Gameplay.hpp"
#include "src/View/Sections/Help.hpp"
#include "src/View/Sections/MainMenu.hpp"
#include "src/View/Sections/NewGame.hpp"
#include "src/View/Sections/Scores.hpp"
#include "src/View/Window/WindowInit.hpp"
#include "src/View/ViewFunctions.hpp"
#include "src/View/Window/Sections/WindowGameplay.hpp"
#include "src/View/Window/Sections/WindowHelp.hpp"
#include "src/View/Window/Sections/WindowMainMenu.hpp"
#include "src/View/Window/Sections/WindowNewGame.hpp"
#include "src/View/Window/Sections/WindowScores.hpp"
#include <iostream>
#include <conio.h>
int main()
{

    Controller::initGame();
    std::string menu_items[] = {"Text mode", "Graphical mode"};
    int         option_index = 0;
    bool        is_selected  = true;
    while(is_selected)
    {
        View::centerX(12);
        std::cout << "Choose mode:\n";
        for(int i = 0; i < 2; ++i)
            {
                int padding = (View::CONSOLE_WIDTH - menu_items[i].length()) / 2;
                if(i == option_index)
                {
                    View::setConsoleColor(4); // set red color for selected item
                    std::cout << std::string(padding, ' ') <<  "> " << menu_items[i] << std::endl;
                    View::resetConsoleColor(); // back to default color
                }
                else
                    std::cout << std::string(padding, ' ') << "  " << menu_items[i] << std::endl;
            }
            char key = getch();
            switch(key)
            {
                case KEY_UP:
                    option_index = (option_index == 0 ? 1 : option_index - 1);
                    break;
                case KEY_DOWN:
                    option_index = (option_index == 1 ? 0 : option_index + 1);
                    break;
                case KEY_ENTER:
                    is_selected = false;
                    break;
            }
            system("cls");
    }

    if(option_index == 0)
    {
        View::consoleInit();
        View::Section* current_section_object;
        View::ESection current_section = View::MAIN_MENU;
        while(current_section)
        {
            switch(current_section)
            {
                case View::MAIN_MENU: { current_section_object = new View::MainMenu; break; }
                case View::GAMEPLAY:  { current_section_object = new View::Gameplay; break; }
                case View::SCORES:    { current_section_object = new View::Scores;   break; }
                case View::HELP:      { current_section_object = new View::Help;     break; }
                default: break;
            }
            current_section = current_section_object->execute();
            delete current_section_object;
        }
    }

    else
    {
        View::windowInit();
        View::Section* current_section_object;
        View::ESection current_section = View::MAIN_MENU;
        while(current_section)
        {
            switch(current_section)
            {
                case View::MAIN_MENU: { current_section_object = new View::WindowMainMenu; break; }
                case View::GAMEPLAY:  { current_section_object = new View::WindowGameplay; break; }
                case View::SCORES:    { current_section_object = new View::WindowScores;   break; }
                case View::HELP:      { current_section_object = new View::WindowHelp;     break; }
                default: break;
            }
            current_section = current_section_object->execute();
            delete current_section_object;
        }
    }

    return 0;
}
