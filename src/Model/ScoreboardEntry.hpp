#pragma once
#include <cstdint>
#include <string>

namespace Model
{
    struct ScoreboardEntry
    {
        std::string name;
        int32_t     score;

        ScoreboardEntry(std::string name, int32_t score)
        {
            this->name  = name;
            this->score = score;
        }
    };
}

