#include "Controller.hpp"
#include "../Model/ModelCore.hpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>

namespace Controller
{
    bool doesScoreQualify(Model::scoreInt fresh_score)
    {
        return Model::doesScoreQualify(fresh_score);
    }

    void addScoreboardEntry(std::string player_name, Model::scoreInt fresh_score)
    {
        Model::addScoreboardEntry(player_name, fresh_score);
    }

    void loadScoreboard()
    {
        Model::loadScoreboard();
    }

    void saveScoreboard()
    {
        Model::saveScoreboard();
    }

    Model::ScoreboardEntry getScoreboardEntry(uint16_t id)
    {
        return Model::getScoreboardEntry(id);
    }

    uint16_t getScoreboardSize()
    {
        return Model::getScoreboardSize();
    }

}
