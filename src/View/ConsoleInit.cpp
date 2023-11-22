#include "ConsoleInit.hpp"
#include <windows.h>

namespace View
{
    void consoleInit()
    {
        _COORD coord;
        _SMALL_RECT rect;
        coord.X = CONSOLE_WIDTH;
        coord.Y = CONSOLE_HEIGHT;

        rect.Top  = 0;
        rect.Left = 0;
        rect.Right  = CONSOLE_WIDTH  - 1;
        rect.Bottom = CONSOLE_HEIGHT - 1;

        HWND consoleWindow = GetConsoleWindow();
        LONG style         = GetWindowLong(consoleWindow, GWL_STYLE);
        style &= ~WS_SIZEBOX;      // Disable resizing
        style &= ~WS_MAXIMIZEBOX;  // Disable maximize button

        SetConsoleScreenBufferSize(handle_console, coord);
        SetConsoleWindowInfo(handle_console, TRUE, &rect);
        SetWindowLong(consoleWindow, GWL_STYLE, style);
    }
}

