#include "Controller.hpp"
#include "../Model/Board.hpp"
#include "../keyCodes.hpp"
#include <conio.h>

namespace Controller
{
    void resetGameplay()
    {
        Model::Game::reset();
        Model::Game::Snake::reset({5,10}, RIGHT, 2);  //(coordinates, direction, length)
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

    uint8_t getBoardWidth()
    {
        return Model::Game::Board::WIDTH;
    }

    uint8_t getBoardHeight()
    {
        return Model::Game::Board::HEIGHT;
    }

    Position getFruitPosition()
    {
        return Model::Game::Board::fruit_position;
    }

    void addPoint()
    {
        Position current_fruit_position = Model::Game::Board::fruit_position;
        Position next_fruit_position;

        // Respawn the next fruit and get its position
        Model::Game::Board::respawn_fruit(Model::Game::Snake::body);
        next_fruit_position = Model::Game::Board::fruit_position;

        int distance = abs(next_fruit_position.first - current_fruit_position.first) +
                       abs(next_fruit_position.second - current_fruit_position.second);

        Model::Game::player_score += (100 - distance) / 10;

        current_fruit_position = next_fruit_position;
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
                    if(Model::Game::Snake::getDirection() != DOWN)
                        changeDirection(UP);
                    break;
                case KEY_LEFT:
                    if(Model::Game::Snake::getDirection() != RIGHT)
                        changeDirection(LEFT);
                    break;
                case KEY_DOWN:
                    if(Model::Game::Snake::getDirection() != UP)
                        changeDirection(DOWN);
                    break;
                case KEY_RIGHT:
                    if(Model::Game::Snake::getDirection() != LEFT)
                        changeDirection(RIGHT);
                    break;
            }
        }
    }
    void changeDirection(EDirection direction)
    {
        Model::Game::Snake::changeDirection(direction);
    }

}
