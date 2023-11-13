#include "ViewFunctions.hpp"
#include <iostream>
#include <windows.h>

namespace View
{
    void centerStringX(uint16_t string_length)
    {
        uint16_t padding = (CONSOLE_WIDTH - string_length) / 2;
        for(int i = 0; i < padding; i++)
            std::cout << " ";
    }

    void setCursorPosition(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void printHeader()
    {
        SetConsoleTextAttribute(handle_console, 2); // set green color
        std::cout << title;
        SetConsoleTextAttribute(handle_console, 7); // back to default color
    }
}
