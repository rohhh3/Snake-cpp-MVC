#pragma once
#include "resources.hpp"

namespace View
{
    void centerX(uint16_t string_length);
    std::string giveSpaceToString(uint16_t string_length);
    void setCursorPosition(int x, int y);
    void printHeader();
    void setConsoleColor(int color);
    void resetConsoleColor();
}
