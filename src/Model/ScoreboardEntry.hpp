#pragma once
#include "typedefs.hpp"
#include <string>

namespace Model
{
    struct ScoreboardEntry
    {
        std::string name;
        scoreInt    score;

        ScoreboardEntry(std::string name, scoreInt score)
        {
            this->name  = name;
            this->score = score;
        }
    };
}

