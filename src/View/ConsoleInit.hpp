#pragma once
#include <windows.h>

namespace View
{
    void console_init()
    {
        const unsigned short WIDTH  = 120;
        const unsigned short HEIGHT = 60;
        _COORD coord;
        _SMALL_RECT rect;

        coord.X = WIDTH;
        coord.Y = HEIGHT;
        rect.Top  = 0;
        rect.Left = 0;
        rect.Right  = WIDTH - 1;
        rect.Bottom = HEIGHT - 1;

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

