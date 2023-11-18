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
            extern Position   head_position;
            extern Position   tail_position;
            extern EDirection starting_direction;
            void reset(Position head_pos, EDirection head_dir, uint16_t init_length);
            bool move();
            void print();
            void changeDirection(EDirection new_direction);
        }
    }

}
