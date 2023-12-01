#include "WindowInit.hpp"

namespace View
{
    void windowInit()
    {
        window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
        window.setFramerateLimit(30);

        //Font loading
        font_title.loadFromFile("fonts/Gameplay.ttf");
        font_default_text.loadFromFile("fonts/ConsolaMono-Book.ttf");
        font_game_over.loadFromFile("fonts/game_over.ttf");

        //Title setting
        title_window.setFont(font_title);
        title_window.setCharacterSize(64);
        title_window.setFillColor(sf::Color::Red);
        title_window.setOutlineThickness(2.f);
        title_window.setOutlineColor(sf::Color::White);
        title_window.setString("SNAKE GAME");
        title_window.setPosition((WINDOW_WIDTH - title_window.getGlobalBounds().width) / 2, 30.f);

        //Back button for help and high scores sections
        back_button.setSize(sf::Vector2f(120.f, 50.f));
        back_text.setFont(font_default_text);
        back_text.setCharacterSize(32);
        back_text.setFillColor(sf::Color::Black);
        back_text.setOutlineThickness(2.f);
        back_text.setOutlineColor(sf::Color::White);
        back_text.setString("< BACK");
    }
}
