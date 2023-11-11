#pragma once
#include <windows.h>
#include "resources.hpp"

namespace View
{
    void console_init()
    {
        _COORD coord;
        _SMALL_RECT rect;
        coord.X = CONSOLE_WIDTH;
        coord.Y = CONSOLE_HEIGHT;

        rect.Top  = 0;
        rect.Left = 0;
        rect.Right  = CONSOLE_WIDTH - 1;
        rect.Bottom = CONSOLE_HEIGHT - 1;

        HWND consoleWindow = GetConsoleWindow();
        LONG style         = GetWindowLong(consoleWindow, GWL_STYLE);
        style &= ~WS_SIZEBOX;      // Disable resizing
        style &= ~WS_MAXIMIZEBOX;  // Disable maximize button

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleScreenBufferSize(handle, coord);
        SetConsoleWindowInfo(handle, TRUE, &rect);
        SetWindowLong(consoleWindow, GWL_STYLE, style);
    }
}

