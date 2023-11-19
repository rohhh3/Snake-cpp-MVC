#include "GameCore.hpp"
#include <time.h>
namespace Model
{
    namespace Game
    {
        scoreInt player_score;
        uint16_t speed;

        void reset()
        {
            srand(time(NULL));
            player_score = 0;
            speed        = 1;
        }
    }
}
