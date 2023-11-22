#pragma once
#include "../Section.hpp"
#include "../../Model/Snake.hpp"
#include <map>
#include <string>

namespace View
{
    class Gameplay : public Section
    {
        private:
            uint8_t board_width;
            uint8_t board_height;
            std::map<Position, EDirection> snake_body;
            std::string board_string;
            Position fruit_position;
        public:
            void print_board();
            ESection execute();
            Gameplay();
            ~Gameplay();
    };
}
