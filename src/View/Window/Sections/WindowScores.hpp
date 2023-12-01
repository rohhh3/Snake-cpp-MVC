#pragma once
#include "../../Section.hpp"
#include "../../../Controller/Controller.hpp"
#include <SFML/Graphics.hpp>
namespace View
{
    class WindowScores : public Section
    {
        private:
            sf::Text high_scores_text;
            sf::Text player_name[10];
            sf::Text scores[10];
            sf::Text current_page;
            sf::Text total_pages;
            sf::Text no_scores_text;

            sf::RectangleShape vertical_rect;
            sf::RectangleShape horizontal_rect;

            sf::RectangleShape go_left_button;
            sf::RectangleShape go_right_button;
            sf::Text           sign_left;
            sf::Text           sign_right;
            sf::Text           page_info;

            int16_t  current_page_data;
            uint16_t total_pages_data;
            uint16_t number_of_scores_on_current_page_data;
            std::vector<Model::ScoreboardEntry> scores_on_page_data;

            static const uint16_t MAX_ELEMENTS_ON_PAGE = 10;
            void updateVisibleScores();
            void updateScoresOnCurrentPageData();
        public:
            ESection execute();
            WindowScores();
            ~WindowScores();
    };
}
