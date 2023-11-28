#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

namespace View
{
    const uint16_t WINDOW_WIDTH  = 1000;
    const uint16_t WINDOW_HEIGHT = 800;

    extern sf::RenderWindow window;
    extern sf::Event        event;
    extern sf::Font         font_title;
    extern sf::Font         font_default_text;
    extern sf::Font         font_game_over;
}
