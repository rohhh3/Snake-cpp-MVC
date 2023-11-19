#pragma once
#include "Position.hpp"
#include "EDirection.hpp"
#include <cstdint>
#include <map>

namespace Model
{
    namespace Game
    {
        namespace Board
        {
            const uint8_t WIDTH = 100;
            const uint8_t HEIGHT = 40;
            extern Position fruit_position;
            void respawn_fruit(std::map<Position, EDirection> const& snake);
        }
    }

}
