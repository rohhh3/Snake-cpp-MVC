#include "Controller.hpp"
#include "../View/resources.hpp"
#include "../Model/Board.hpp"
#include "../Model/GameCore.hpp"
#include <map>

namespace Controller
{
    void resetGameplay()
    {
        Model::Game::reset();
       // Model::Game::Board::respawn_fruit(Model::Game::Snake::body);
    }

    void moveSnake()
    {

    }
}
