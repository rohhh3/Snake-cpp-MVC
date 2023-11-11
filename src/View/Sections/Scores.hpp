#pragma once
#include "../ESection.hpp"
#include "../../Controller/Controller.hpp"
#include "../resources.hpp"
#include "../Section.hpp"

namespace View
{
    class Scores : public Section
    {
        private:
            static const uint16_t MAX_ELEMENTS_ON_PAGE = 10;
            uint16_t current_page;
            uint16_t total_pages;
            std::vector<Model::ScoreboardEntry> scores_on_page;

        public:
            ESection execute();
    };
}
