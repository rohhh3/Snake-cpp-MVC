#include "WindowInit.hpp"

namespace View
{
    void windowInit()
    {
        window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
        window.setFramerateLimit(30);
        font_title.loadFromFile("fonts/Gameplay.ttf");
        font_default_text.loadFromFile("fonts/ConsolaMono-Book.ttf");
        font_game_over.loadFromFile("fonts/game_over.ttf");
    }
}
