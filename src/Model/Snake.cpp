#include "Snake.hpp"
#include "../View/resources.hpp"
namespace Model
{
    namespace Game
    {
        namespace Snake
        {
            uint16_t   length    = 0;
            Position   position  = {0, 0};
            EDirection direction = UP;

            std::map<Position, EDirection> body;

            void reset(Position head_position, EDirection head_direction, uint16_t init_length)
            {
                body.clear();
                length    = init_length;
                position  = head_position;
                direction = head_direction;
                body.insert({position, direction});
            }

            bool move()
            {
                Position new_position = position;
                switch(direction)
                {
                    case UP:
                        new_position.y--;
                        break;
                    case RIGHT:
                        new_position.x++;
                        break;
                    case DOWN:
                        new_position.y++;
                        break;
                    case LEFT:
                        new_position.x--;
                        break;
                }

               /* if(new_position.x < 0 || new_position.x >= View::CONSOLE_WIDTH || new_position.y < 0 || new_position.y >= View::CONSOLE_HEIGHT)
                    return false;*/

                auto collisionIt = body.find(new_position);
                if(collisionIt != body.end())
                    return false;

                position = new_position;
                body[new_position] = direction;


                return true;
            }
        }
    }
}
