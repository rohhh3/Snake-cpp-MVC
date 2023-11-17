#include "Snake.hpp"

namespace Model
{
    namespace Game
    {
        namespace Snake
        {
            std::map<Position, EDirection> body;
            uint16_t length = 0;
            void reset(Position head_position, EDirection head_direction, uint16_t init_length)
            {
                body.clear();
                length = init_length;
                body.insert({head_position, head_direction});
            }
            bool move()
            {
                return true;
            }
        }
    }
}
