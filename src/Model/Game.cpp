#include "GameCore.hpp"

namespace Model
{
    namespace Game
    {
        scoreInt player_score;
        uint16_t speed;

        void reset()
        {
            player_score = 0;
            speed        = 1;
        }
    }
}
