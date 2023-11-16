#pragma once
#include <map>
#include "Position.hpp"
#include "EDirection.hpp"

namespace Model
{
    namespace Game
    {
        namespace Snake
        {
            extern std::map<Position, EDirection> body;
            void reset(Position head_position, EDirection head_direction, uint16_t length);
            bool move();
        }
    }

}
