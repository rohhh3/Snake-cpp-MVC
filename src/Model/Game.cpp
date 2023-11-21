#include "GameCore.hpp"


namespace Model
{
    namespace Game
    {
        scoreInt player_score;

        void reset()
        {
            srand(time(NULL));
            player_score = 0;
        }
    }
}
