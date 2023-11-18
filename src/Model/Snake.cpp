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
            EDirection direction;

            std::map<Position, EDirection> body;

            void reset(Position head_pos, EDirection head_dir, uint16_t init_length)
            {
                body.clear();
                length         = init_length;
                head_position  = head_pos;
                direction      = head_dir;
                body.insert({head_position, direction});

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
                    body.insert({body_tile_pos, direction});
                }
                tail_position = body_tile_pos;
            }

            bool move()
            {
                Position new_position = head_position;
                switch(direction)
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

                if(new_position.first < 0 || new_position.first >= Board::WIDTH || new_position.second < 0 || new_position.second >= Board::HEIGHT)
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

                head_position      = new_position;
                body[new_position] = direction;

                return true;
            }

            void print()
            {
                system("cls");
                std::string text = "";
                for (int y = 0; y < Board::HEIGHT; ++y)
                {
                    for (int x = 0; x < Board::WIDTH; ++x)
                    {
                        Position current_position = { x, y };

                        if (body.count(current_position))
                        {
                            text += "S";
                        }
                        else if (current_position == Board::fruit_position)
                        {
                            text += "F";
                        }
                        else
                        {
                            text += ".";
                        }
                    }
                    text += "\n";
                }
                text += "\n";
                std::cout << text;
                Sleep(200);
            }

            void changeDirection(EDirection new_direction)
            {
                if(new_direction != direction)
                {
                    if ((new_direction == UP && GetAsyncKeyState(VK_UP)) ||
                        (new_direction == RIGHT && GetAsyncKeyState(VK_RIGHT)) ||
                        (new_direction == DOWN && GetAsyncKeyState(VK_DOWN)) ||
                        (new_direction == LEFT && GetAsyncKeyState(VK_LEFT)))
                    {
                        direction = new_direction;
                    }
                }
            }

        }
    }
}
