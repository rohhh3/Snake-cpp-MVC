#pragma once
#include "resources.hpp"
#include <cstdint>
namespace View
{
    void centerStringX(uint16_t string_length);
    void setCursorPosition(int x, int y);
    void printHeader();
}
