#include "Board.hpp"
#include "Snake.hpp"
#include <cstdlib>
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
                srand((unsigned) time(NULL));
                fruit_position.x = rand() % WIDTH;
                fruit_position.y = rand() % HEIGHT;

                while(snake.find(fruit_position) != snake.end())
                {
                    fruit_position.x = rand() % WIDTH;
                    fruit_position.y = rand() % HEIGHT;
                }
            }
        }
    }
}
