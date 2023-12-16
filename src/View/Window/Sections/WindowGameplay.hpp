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
            const uint8_t      grid_line_thickness = 3;
            sf::RectangleShape map_border;
            sf::RectangleShape vert_lines[Controller::getBoardWidth() - 1];
            sf::RectangleShape horiz_lines[Controller::getBoardHeight() - 1];
            sf::RectangleShape fruit;
            std::vector<sf::RectangleShape> current_snake_body;
            void rebuildSnake();
        public:
            ESection execute();
            WindowGameplay();
            ~WindowGameplay();
    };
}
