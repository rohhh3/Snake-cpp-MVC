#include "WindowMainMenu.hpp"
#include "../resources.hpp"

namespace View
{
    WindowMainMenu::WindowMainMenu()
    {
        title.setFont(font_title);
        title.setCharacterSize(64);
        title.setFillColor(sf::Color::Red);
        title.setOutlineThickness(2.f);
        title.setOutlineColor(sf::Color::White);
        title.setString("SNAKE GAME");
        title.setPosition((WINDOW_WIDTH - title.getGlobalBounds().width) / 2, 30.f);

        button_size = sf::Vector2f(220.f, 50.f);

        new_game_button.setSize(button_size);
        scores_button.setSize(button_size);
        help_button.setSize(button_size);
        exit_button.setSize(button_size);

        new_game_button.setFillColor(sf::Color::Blue);
        scores_button.setFillColor(sf::Color::Red);
        help_button.setFillColor(sf::Color::Yellow);
        exit_button.setFillColor(sf::Color::Magenta);

        float button_gap = 20;
        new_game_button.setPosition((WINDOW_WIDTH - new_game_button.getGlobalBounds().width) / 2, 150.f);
        scores_button.setPosition(new_game_button.getPosition().x,
                                  new_game_button.getPosition().y + new_game_button.getGlobalBounds().height + button_gap);
        help_button.setPosition(new_game_button.getPosition().x,
                                scores_button.getPosition().y + scores_button.getGlobalBounds().height + button_gap);
        exit_button.setPosition(new_game_button.getPosition().x,
                                help_button.getPosition().y + help_button.getGlobalBounds().height + button_gap);
    }

    WindowMainMenu::~WindowMainMenu(){ }

    ESection WindowMainMenu::execute()
    {
        while(window.isOpen())
        {
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::Black);

            window.draw(title);
            window.draw(new_game_button);
            window.draw(scores_button);
            window.draw(help_button);
            window.draw(exit_button);

            window.display();
        }
    }
}
