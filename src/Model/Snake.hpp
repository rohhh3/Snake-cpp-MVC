#pragma once
#include <map>
#include "Position.hpp"
#include "EDirection.hpp"
#include "typedefs.hpp"

namespace Model
{
    namespace Game
    {
        namespace Snake
        {
            extern std::map<Position, EDirection> body;
            extern uint16_t   length;
            extern Position   starting_position;
            extern EDirection starting_direction;
            void reset(Position head_position, EDirection head_direction, uint16_t init_length);
            bool move();
        }
    }

}
