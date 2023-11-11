#pragma once
#include "../ESection.hpp"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>


namespace View
{
    ESection executeMainMenu()
    {
        std::string menu_items[]      = {"New Game", "Scores", "Help", "Exit"};
        HANDLE      handle_console    = GetStdHandle(STD_OUTPUT_HANDLE);
        std::string title             = "\r\n ________   ________    ________   ___  __     _______           ________   ________   _____ ______    _______      \r\n|\\   ____\\ |\\   ___  \\ |\\   __  \\ |\\  \\|\\  \\  |\\  ___ \\         |\\   ____\\ |\\   __  \\ |\\   _ \\  _   \\ |\\  ___ \\     \r\n\\ \\  \\___|_\\ \\  \\\\ \\  \\\\ \\  \\|\\  \\\\ \\  \\/  /|_\\ \\   __/|        \\ \\  \\___| \\ \\  \\|\\  \\\\ \\  \\\\\\__\\ \\  \\\\ \\   __/|    \r\n \\ \\_____  \\\\ \\  \\\\ \\  \\\\ \\   __  \\\\ \\   ___  \\\\ \\  \\_|/__       \\ \\  \\  ___\\ \\   __  \\\\ \\  \\\\|__| \\  \\\\ \\  \\_|/__  \r\n  \\|____|\\  \\\\ \\__\\\\ \\__\\\\ \\__\\ \\__\\\\ \\__\\\\ \\__\\\\ \\_______\\       \\ \\_______\\\\ \\__\\ \\__\\\\ \\__\\    \\ \\__\\\\ \\_______\\\r\n   |\\_________\\\\|__|\\|__|\\|__|\\|__| \\|__| \\|__| \\|_______|        \\|_______| \\|__|\\|__| \\|__|     \\|__| \\|_______|\r\n   \\|_________|                                                                                                     \r\n                                                                                                                    \r\n                                                                                                                    \r\n";

        int  option_index   = 0;
        int  console_width  = 120;
        bool isSelected     = false;

        while(!isSelected)
        {
            SetConsoleTextAttribute(handle_console, 2); // set green color

            std::cout << title;

            SetConsoleTextAttribute(handle_console, 7); // back to default color

            for(int i = 0; i < 4; ++i)
            {
                int padding = (console_width - menu_items[i].length()) / 2;
                if(i == option_index)
                {
                    SetConsoleTextAttribute(handle_console, 4); // set red color for selected item
                    std::cout << std::string(padding, ' ') << menu_items[i] << std::endl;
                    SetConsoleTextAttribute(handle_console, 7); // back to default color
                }
                else
                    std::cout << std::string(padding, ' ') << menu_items[i] << std::endl;
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
                    isSelected = true;
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
