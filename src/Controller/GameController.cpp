#include "Controller.hpp"
#include "../Model/Board.hpp"
#include <conio.h>

namespace Controller
{
    void resetGameplay()
    {
        Model::Game::reset();
        Model::Game::Snake::reset({5,10}, RIGHT, 8);  //(coordinates, direction, length)
                                                      // length = 1 generates an exception
        Model::Game::Board::respawn_fruit(Model::Game::Snake::body);
    }

    bool moveSnake()
    {
        return Model::Game::Snake::move();
    }

    std::map<Position, EDirection> getSnake()
    {
        return Model::Game::Snake::body;
    }

    Position getFruitPosition()
    {
        return Model::Game::Board::fruit_position;
    }

    scoreInt getScore()
    {
        return Model::Game::player_score;
    }

    void handleUserInput()
    {
        while(kbhit())
        {
            char key = getch();
            switch(key)
            {
                case KEY_UP:
                    if(Model::Game::Snake::head_direction != DOWN)
                        changeDirection(UP);
                    break;
                case KEY_LEFT:
                    if(Model::Game::Snake::head_direction != RIGHT)
                        changeDirection(LEFT);
                    break;
                case KEY_DOWN:
                    if(Model::Game::Snake::head_direction != UP)
                        changeDirection(DOWN);
                    break;
                case KEY_RIGHT:
                    if(Model::Game::Snake::head_direction != LEFT)
                        changeDirection(RIGHT);
                    break;
            }
        }
    }

    void changeDirection(EDirection direction)
    {
        Model::Game::Snake::changeDirection(direction);
    }

    EDirection getDirection()
    {
        return Model::Game::Snake::head_direction;
    }
}
