#include "Board.hpp"
#include <time.h>

namespace Model
{
    namespace Game
    {
        namespace Board
        {
            Position fruit_position;
            void respawn_fruit(std::map<Position, EDirection> const& snake)
            {
                srand(time(NULL));
                do
                {
                    fruit_position.first  = rand() % WIDTH;
                    fruit_position.second = rand() % HEIGHT;
                }while(snake.count(fruit_position));
            }
        }
    }
}
