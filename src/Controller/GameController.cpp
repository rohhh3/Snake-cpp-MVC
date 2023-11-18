#include "Controller.hpp"
#include "../Model/Board.hpp"
#include <conio.h>
namespace Controller
{
    void resetGameplay()
    {
        Model::Game::reset();
        Model::Game::Snake::reset({2,8}, Model::DOWN, 4); //(coordinates, direction, length)
        Model::Game::Board::respawn_fruit(Model::Game::Snake::body);
    }

    void moveSnake()
    {
        Model::Game::Snake::move();
    }

    void addPoint()
    {
        Model::Game::player_score++;
    }

    void handleUserInput()
    {
        if(_kbhit())
        {
            char key = _getch();
            switch (key)
            {
                case KEY_UP:
                    changeDirection(Model::UP);
                    break;
                case KEY_LEFT:
                    changeDirection(Model::LEFT);
                    break;
                case KEY_DOWN:
                    changeDirection(Model::DOWN);
                    break;
                case KEY_RIGHT:
                    changeDirection(Model::RIGHT);
                    break;
            }
        }
    }
    void changeDirection(Model::EDirection direction)
    {
        Model::Game::Snake::changeDirection(direction);
    }

}
