#pragma once
#include "../../Controller/Controller.hpp"
#include "../Section.hpp"

namespace View
{
    class Scores : public Section
    {
        private:
            static const uint16_t MAX_ELEMENTS_ON_PAGE = 10;
            int16_t current_page;
            uint16_t total_pages;
            uint16_t number_of_scores_on_current_page;
            std::vector<Model::ScoreboardEntry> scores_on_page;
            void updateVisibleScores();
            void updatePage();
            void updateScoresOnCurrentPage();

        public:
            ESection execute();
            Scores();
            ~Scores();
    };
}
