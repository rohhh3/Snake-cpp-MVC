#pragma once
#include <cstdint>
#include <string>
#include "../Model/typedefs.hpp"

using namespace N1;

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

