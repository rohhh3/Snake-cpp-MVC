#pragma once
#include "../../Section.hpp"
#include "../../../Controller/Controller.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
namespace View
{
    class WindowGameplay : public Section
    {
        private:
            uint8_t            map_scale;
            const uint8_t      grid_line_thickness = 1;
            sf::RectangleShape map_border;
            sf::RectangleShape vert_lines[Controller::getBoardWidth() - 1];
            sf::RectangleShape horiz_lines[Controller::getBoardHeight() - 1];
            sf::RectangleShape fruit;
            sf::Text           points_text;
            sf::Text           game_over_text[5];
            sf::Text           name_input;
            Position fruit_position;
            std::vector<sf::RectangleShape> current_snake_body;
            void rebuildSnake();
        public:
            ESection execute();
            WindowGameplay();
            ~WindowGameplay();
    };
}
