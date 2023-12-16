#pragma once
#include "Position.hpp"
#include "EDirection.hpp"
#include <map>


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
            extern EDirection head_direction;
            extern EDirection head_next_direction;
            void reset(Position head_pos, EDirection head_dir, uint16_t init_length);
            bool move();
            void changeDirection(EDirection new_direction);
        }
    }

}
