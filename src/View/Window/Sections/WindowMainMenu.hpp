#pragma once
#include "../../Section.hpp"
#include <SFML/Graphics.hpp>
namespace View
{
    class WindowMainMenu : public Section
    {
        private:
            sf::Text     option_new_game;
            sf::Text     option_scores;
            sf::Text     option_help;
            sf::Text     option_exit;
            sf::Vector2f button_size;

            sf::RectangleShape new_game_button;
            sf::RectangleShape scores_button;
            sf::RectangleShape help_button;
            sf::RectangleShape exit_button;
        public:
            ESection execute();
            WindowMainMenu();
            ~WindowMainMenu();
    };
}
