#include "ViewFunctions.hpp"
#include <iostream>
#include <windows.h>

namespace View
{
    void centerX(uint16_t string_length)
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
        setConsoleColor(2); // set green color
        std::cout << title;
        resetConsoleColor(); // back to default color
    }

    void setConsoleColor(int color)
    {
            SetConsoleTextAttribute(handle_console, color);
    }
    void resetConsoleColor()
    {
            SetConsoleTextAttribute(handle_console, 7); // 7 is the default color
    }
}
