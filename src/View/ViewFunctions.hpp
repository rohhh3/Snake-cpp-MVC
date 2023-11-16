#pragma once
#include "resources.hpp"
#include <cstdint>
#include <string>
namespace View
{
    void centerX(uint16_t string_length);
    void setCursorPosition(int x, int y);
    void printHeader();
}
