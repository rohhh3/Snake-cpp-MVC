#include "WindowMainMenu.hpp"
#include "../resources.hpp"

namespace View
{
    WindowMainMenu::WindowMainMenu()
    {
        //New Game
        option_new_game.setFont(font_default_text);
        option_new_game.setCharacterSize(32);
        option_new_game.setFillColor(sf::Color::White);
        option_new_game.setString("New Game");
        option_new_game.setPosition((WINDOW_WIDTH - option_new_game.getGlobalBounds().width) / 2, 155.f);

        //Scores
        option_scores.setFont(font_default_text);
        option_scores.setCharacterSize(32);
        option_scores.setFillColor(sf::Color::White);
        option_scores.setString("Scores");
        option_scores.setPosition((WINDOW_WIDTH - option_scores.getGlobalBounds().width) / 2, 225.f);

        //Help
        option_help.setFont(font_default_text);
        option_help.setCharacterSize(32);
        option_help.setFillColor(sf::Color::White);
        option_help.setString("Help");
        option_help.setPosition((WINDOW_WIDTH - option_help.getGlobalBounds().width) / 2, 295.f);

        //Exit
        option_exit.setFont(font_default_text);
        option_exit.setCharacterSize(32);
        option_exit.setFillColor(sf::Color::White);
        option_exit.setString("Exit");
        option_exit.setPosition((WINDOW_WIDTH - option_exit.getGlobalBounds().width) / 2, 365.f);

        //Sizes
        button_size = sf::Vector2f(220.f, 50.f);
        new_game_button.setSize(button_size);
        scores_button.setSize(button_size);
        help_button.setSize(button_size);
        exit_button.setSize(button_size);

        //Colors
        new_game_button.setFillColor(sf::Color::Blue);
        scores_button.setFillColor(sf::Color::Red);
        help_button.setFillColor(sf::Color::Green);
        exit_button.setFillColor(sf::Color::Magenta);

        //Positions
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
                else if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        if((event.mouseButton.x >= 390 && event.mouseButton.x <= 610)
                            && (event.mouseButton.y >= 150 && event.mouseButton.y <= 200) )
                                return GAMEPLAY;
                        else if((event.mouseButton.x >= 390 && event.mouseButton.x <= 610)
                                && (event.mouseButton.y >= 220 && event.mouseButton.y <= 270) )
                                    return SCORES;
                        else if((event.mouseButton.x >= 390 && event.mouseButton.x <= 610)
                                && (event.mouseButton.y >= 290 && event.mouseButton.y <= 340) )
                                    return HELP;
                        else if((event.mouseButton.x >= 390 && event.mouseButton.x <= 610)
                                && (event.mouseButton.y >= 360 && event.mouseButton.y <= 410) )
                                    return EXIT;

                        /* TESTS
                        std::cout << "height:" << help_button.getGlobalBounds().height << std::endl;
                        std::cout << "width:" << help_button.getGlobalBounds().width << std::endl;
                        std::cout << "tip y:" << help_button.getPosition().y << std::endl;
                        std::cout << "tip x:" << help_button.getPosition().x << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        */
                    }
                    else if(event.mouseButton.button == sf::Mouse::Right)
                        system("cls");
                }
            }

            window.clear(sf::Color::Black);

            window.draw(title_window);
            window.draw(new_game_button);
            window.draw(option_new_game);

            window.draw(scores_button);
            window.draw(option_scores);

            window.draw(help_button);
            window.draw(option_help);

            window.draw(exit_button);
            window.draw(option_exit);

            window.display();
        }
        return EXIT;
    }
}
