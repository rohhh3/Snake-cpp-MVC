#include "GameCore.hpp"
#include "Position.hpp"
#include "Board.hpp"
#include "Snake.hpp"
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

        void addPoint()
        {
            Position current_fruit_position = Board::fruit_position;
            Position next_fruit_position;

            // Respawn the next fruit and get its position
            Board::respawn_fruit(Snake::body);
            next_fruit_position = Board::fruit_position;

            int distance = abs(next_fruit_position.first - current_fruit_position.first) +
                           abs(next_fruit_position.second - current_fruit_position.second);

            player_score += (100 - distance) / 10;

            current_fruit_position = next_fruit_position;
        }
    }
}
