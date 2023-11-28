#pragma once
#include "../../Section.hpp"
#include <SFML/Graphics.hpp>
namespace View
{
    class WindowMainMenu : public Section
    {
        private:
            sf::Text     title;
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
