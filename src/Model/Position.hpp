#pragma once
#include <cstdint>
#include <string>

namespace Model
{
    struct Position
    {
        uint8_t x, y;

        bool operator<(const Position& other) const
        {
            return (x < other.x) || ((x == other.x) && (y < other.y));
        }
    };
}
