#include "Controller.hpp"
#include "../Model/Board.hpp"

namespace Controller
{
    void resetGameplay()
    {
        Model::Game::reset();
        Model::Game::Snake::reset({2,8}, Model::RIGHT, 4); //(coordinates, direction, length)
        Model::Game::Board::respawn_fruit(Model::Game::Snake::body);
    }

    void moveSnake()
    {
        Model::Game::Snake::move();
        Model::Game::Snake::print();
    }

    void addPoint()
    {
        Model::Game::player_score++;
    }

    void changeDirection(Model::EDirection direction)
    {
        Model::Game::Snake::changeDirection(direction);
    }

}
