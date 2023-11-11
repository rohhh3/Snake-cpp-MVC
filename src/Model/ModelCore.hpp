#pragma once
#include "ScoreboardEntry.hpp"
#include "Snake.hpp"
#include <cstdint>
#include <vector>

namespace Model
{
    const  uint16_t MAX_SCOREBOARD_SIZE = 1000;
    extern std::vector<ScoreboardEntry> scoreboard;
    const  std::string file_path = "scoreboard.txt";
}
