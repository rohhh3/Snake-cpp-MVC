#pragma once
#include "ScoreboardEntry.hpp"
#include "Snake.hpp"
#include "typedefs.hpp"
#include <cstdint>
#include <vector>

namespace Model
{
    const  uint16_t MAX_SCOREBOARD_SIZE = 1000;
    extern std::vector<ScoreboardEntry> scoreboard;
    const  std::string file_path = "scoreboard.txt";
    bool doesScoreQualify(scoreInt fresh_score);
    void addScoreboardEntry(std::string player_name, scoreInt fresh_score);
    void loadScoreboard();
    void saveScoreboard();
    Model::ScoreboardEntry getScoreboardEntry(uint16_t id);
    uint16_t getScoreboardSize();
}
