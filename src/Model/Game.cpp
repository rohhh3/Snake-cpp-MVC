#include "GameCore.hpp"
#include "typedefs.hpp"
#include "Snake.hpp"

namespace Model
{
    namespace Game
    {
        scoreInt    player_score;
        std::string player_name;

        void reset()
        {
            player_score = 0;
            player_name  = "";
            Snake::reset({2,8}, RIGHT, 1);
        }
    }
}
