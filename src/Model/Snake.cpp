#include "Snake.hpp"
#include "Board.hpp"
#include "../Controller/Controller.hpp"
#include <iostream>
#include <windows.h>
#include <conio.h>

namespace Model
{
    namespace Game
    {
        namespace Snake
        {
            uint16_t   length;
            Position   head_position;
            Position   tail_position;
            EDirection head_direction;
            EDirection head_next_direction;

            std::map<Position, EDirection> body;

            void reset(Position head_pos, EDirection head_dir, uint16_t init_length)
            {
                body.clear();
                length         = init_length;
                head_position  = head_pos;
                head_direction = head_next_direction = head_dir;
                body.insert({head_position, head_direction});

                Position body_tile_pos = head_pos;
                for(uint16_t i = 0; i < init_length - 1; i++)
                {
                    bool cut_tail = false;
                    switch(head_dir)
                    {
                        case UP:
                            if(body_tile_pos.second == std::numeric_limits<uint8_t>::max())
                                cut_tail = true;
                            else
                                body_tile_pos.second++;
                            break;

                        case RIGHT:
                            if(body_tile_pos.first == std::numeric_limits<uint8_t>::min())
                                cut_tail = true;
                            else
                                body_tile_pos.first--;
                            break;

                        case DOWN:
                            if(body_tile_pos.second == std::numeric_limits<uint8_t>::min())
                                cut_tail = true;
                            else
                                body_tile_pos.second--;
                            break;

                        case LEFT:
                            if(body_tile_pos.first == std::numeric_limits<uint8_t>::max())
                                cut_tail = true;
                            else
                                body_tile_pos.first++;
                            break;
                    }

                    if(cut_tail)
                    {
                        length = i + 1;
                        break;
                    }
                    body.insert({body_tile_pos, head_direction});
                }
                tail_position = body_tile_pos;
            }

            bool move()
            {
                Position new_position = head_position;
                switch(head_next_direction)
                {
                    case UP:
                        new_position.second--;
                        break;
                    case RIGHT:
                        new_position.first++;
                        break;
                    case DOWN:
                        new_position.second++;
                        break;
                    case LEFT:
                        new_position.first--;
                        break;
                }

                if(new_position.first < 0 || new_position.first >= Board::WIDTH
                   || new_position.second < 0 || new_position.second >= Board::HEIGHT)
                    return false;

                if(body.count(new_position))
                    return false;

                if(new_position == Board::fruit_position)
                    Controller::addPoint();
                else
                {
                    EDirection tail_dir = body.at(tail_position);
                    body.erase(tail_position);
                    switch(tail_dir)
                    {
                        case UP:
                            tail_position.second--;
                            break;
                        case RIGHT:
                            tail_position.first++;
                            break;
                        case DOWN:
                            tail_position.second++;
                            break;
                        case LEFT:
                            tail_position.first--;
                            break;
                    }
                }
                body.at(head_position) = head_next_direction;
                head_position          = new_position;
                body[new_position]     = head_next_direction;
                head_direction         = head_next_direction;

                return true;
            }

            void changeDirection(EDirection new_direction)
            {
                bool will_change = true;
                if(new_direction != head_direction)
                {
                    switch(new_direction)
                    {
                        case UP:
                            if(head_direction == DOWN)
                                will_change = false;
                            break;
                        case RIGHT:
                            if(head_direction == LEFT)
                                will_change = false;
                            break;
                        case DOWN:
                            if(head_direction == UP)
                                will_change = false;
                            break;
                        case LEFT:
                            if(head_direction == RIGHT)
                                will_change = false;
                            break;
                    }
                    if( will_change && ((new_direction == UP    && GetAsyncKeyState(VK_UP)) ||
                        (new_direction == RIGHT && GetAsyncKeyState(VK_RIGHT)) ||
                        (new_direction == DOWN  && GetAsyncKeyState(VK_DOWN)) ||
                        (new_direction == LEFT  && GetAsyncKeyState(VK_LEFT))))
                    {
                        head_next_direction = new_direction;
                    }
                }
            }

            EDirection getDirection()
            {
                return head_direction;
            }

        }
    }
}
