#include "Controller.hpp"
#include "../Model/typedefs.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace N1;

namespace Controller
{
    bool doesScoreQualify(scoreInt fresh_score)
    {
        if(
           Model::scoreboard.empty() ||
           fresh_score > Model::scoreboard.back().score ||
           Model::scoreboard.size() < Model::MAX_SCOREBOARD_SIZE
           )
            return true;
        return false;
    }

    void addScoreboardEntry(std::string player_name, scoreInt fresh_score)
    {
        if(!doesScoreQualify(fresh_score))
            return;

        // Binary insertion sort in descending order
        int16_t low            = 0;
        int16_t high           = Model::scoreboard.size() - 1;
        int16_t insert_position = -1;

        while(low <= high)
        {
            int16_t mid = (low + high) / 2;
            if(Model::scoreboard[mid].score > fresh_score)
                low = mid + 1;
            else if(Model::scoreboard[mid].score < fresh_score)
                high = mid - 1;
            else
            {
                insert_position = mid;
                break;
            }
        }

        if (insert_position == -1)
            insert_position = low; // If not found, insert after the closest lower score

        Model::scoreboard.emplace(Model::scoreboard.begin() + insert_position, player_name, fresh_score);
    }

    Model::ScoreboardEntry getScoreboardEntry(uint16_t id)
    {
        assert(id < Model::scoreboard.size());
        return Model::scoreboard[id];
    }
}
