#include "Board.hpp"
#include <random>

namespace Model
{
    namespace Game
    {
        namespace Board
        {
            Position fruit_position;
            void respawn_fruit(std::map<Position, EDirection> const& snake)
            {
                do
                {
                    fruit_position.first  = rand() % WIDTH;
                    fruit_position.second = rand() % HEIGHT;
                }while(snake.count(fruit_position));
            }
        }
    }
}
