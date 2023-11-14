#include "MainMenu.hpp"
#include "../ViewFunctions.hpp"
#include "../Section.hpp"
#include <iostream>
#include <string>
#include <conio.h>

namespace View
{
    MainMenu::MainMenu()
    {

    }

    MainMenu::~MainMenu(){ }

    ESection MainMenu::execute()
    {
        std::string menu_items[] = {"New Game", "Scores", "Help", "Exit"};
        int  option_index        = 0;
        bool is_selected         = true;

        while(is_selected)
        {
            printHeader();

            for(int i = 0; i < 4; ++i)
            {
                int padding = (CONSOLE_WIDTH - menu_items[i].length()) / 2;
                if(i == option_index)
                {
                    SetConsoleTextAttribute(handle_console, 4); // set red color for selected item
                    std::cout << std::string(padding, ' ') <<  "> " << menu_items[i] << std::endl;
                    SetConsoleTextAttribute(handle_console, 7); // back to default color
                }
                else
                    std::cout << std::string(padding, ' ') << "  " << menu_items[i] << std::endl;
            }
            char key = _getch();
            switch(key)
            {
                case 72: //up arrow key
                    option_index = (option_index == 0 ? 3 : option_index - 1);
                    break;
                case 80: // Down arrow
                    option_index = (option_index == 3 ? 0 : option_index + 1);
                    break;
                case 13: //enter button
                    is_selected = false;
                    break;
            }
            system("cls");
        }

        switch(option_index)
        {
            case 0:
                return NEW_GAME;
                break;
            case 1:
                return SCORES;
                break;
            case 2:
                return HELP;
                break;
            default:
                return EXIT;
                break;
        }
    }
}
