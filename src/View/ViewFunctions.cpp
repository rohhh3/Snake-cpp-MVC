#include "ViewFunctions.hpp"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif


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
        #ifdef _WIN32
            SetConsoleTextAttribute(handle_console, color);
        #else
            // Unix-like system
            std::cout << "\033[38;5;" << color << "m";
        #endif
    }
    void resetConsoleColor()
    {
        #ifdef _WIN32
            SetConsoleTextAttribute(handle_console, 7); // 7 is the default color
        #else
            // Unix-like system
            std::cout << "\033[0m";
        #endif
    }
}
