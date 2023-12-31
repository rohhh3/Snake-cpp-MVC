#pragma once
#include "Position.hpp"
#include "EDirection.hpp"
#include <map>

namespace Model
{
    namespace Game
    {
        namespace Board
        {
            const uint8_t WIDTH = 60;
            const uint8_t HEIGHT = 20;
            extern Position fruit_position;
            void respawn_fruit(std::map<Position, EDirection> const& snake);
        }
    }

}
