#include "WindowGameplay.hpp"
#include "../resources.hpp"
#include "../../../Controller/Controller.hpp"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

namespace View
{
    WindowGameplay::WindowGameplay()
    {
        Controller::resetGameplay();

        //Map
        const sf::Vector2i max_map_size = sf::Vector2i(WINDOW_WIDTH * 0.8, WINDOW_HEIGHT * 0.3);
        if(Controller::getBoardWidth() >= Controller::getBoardHeight())
           map_scale = (max_map_size.x - (Controller::getBoardWidth() - 1) * grid_line_thickness) / Controller::getBoardWidth();
        else
           map_scale = (max_map_size.y - (Controller::getBoardHeight() - 1) * grid_line_thickness) / Controller::getBoardHeight();

        map_border.setSize(sf::Vector2f(Controller::getBoardWidth() * map_scale + (Controller::getBoardWidth() - 1) * grid_line_thickness,
                                        Controller::getBoardHeight() * map_scale + (Controller::getBoardHeight() - 1) * grid_line_thickness));
        map_border.setFillColor(sf::Color::Yellow);
        map_border.setOutlineThickness(4.f);
        map_border.setOutlineColor(sf::Color::Black);
        map_border.setPosition((WINDOW_WIDTH - map_border.getGlobalBounds().width) / 2, (WINDOW_WIDTH - map_border.getGlobalBounds().width) / 2);

        //Lines
        for(int i = 0; i < Controller::getBoardWidth() - 1; i++)
        {
            vert_lines[i].setSize(sf::Vector2f(grid_line_thickness, map_border.getSize().y));
            vert_lines[i].setFillColor(sf::Color::Black);
            vert_lines[i].setPosition(map_border.getPosition().x + (i + 1) * map_scale + i * grid_line_thickness, map_border.getPosition().y);
        }

        for(int i = 0; i < Controller::getBoardHeight() - 1; i++)
        {
            horiz_lines[i].setSize(sf::Vector2f(map_border.getSize().x, grid_line_thickness));
            horiz_lines[i].setFillColor(sf::Color::Black);
            horiz_lines[i].setPosition(map_border.getPosition().x, map_border.getPosition().y + (i + 1) * map_scale + i * grid_line_thickness );
        }

        //Fruit
        fruit.setFillColor(sf::Color::Red);
        fruit.setSize(sf::Vector2f(map_scale, map_scale));
        fruit_position = Controller::getFruitPosition();
        fruit.setPosition(map_border.getPosition().x + fruit_position.first * (map_scale + grid_line_thickness),
                                                  map_border.getPosition().y + fruit_position.second * (map_scale + grid_line_thickness));
        //Text
        points_text.setFont(font_default_text);
        points_text.setCharacterSize(32);
        points_text.setOutlineThickness(3);
        points_text.setStyle(sf::Text::Bold);
        points_text.setString(std::to_string(Controller::getScore()));
        points_text.setPosition((WINDOW_WIDTH - points_text.getGlobalBounds().width) / 2,
                                map_border.getPosition().y - 50);

        //Game over string
        game_over_text[0].setFont(font_game_over);
        game_over_text[0].setCharacterSize(64);
        game_over_text[0].setString("GAME OVER");

        for(uint8_t i = 1; i <= 4; i++)
        {
            game_over_text[i].setFont(font_default_text);
            game_over_text[i].setCharacterSize(32);
        }

        game_over_text[1].setString("Save this score?");
        game_over_text[2].setString("Yes");
        game_over_text[3].setString("No");
        game_over_text[4].setString("OK");

        game_over_text[0].setPosition((WINDOW_WIDTH - game_over_text[0].getGlobalBounds().width) / 2,
                   map_border.getGlobalBounds().height + map_border.getPosition().y);
        game_over_text[1].setPosition((WINDOW_WIDTH - game_over_text[1].getGlobalBounds().width) / 2,
           map_border.getGlobalBounds().height + map_border.getPosition().y + 100);
        game_over_text[2].setPosition((WINDOW_WIDTH - game_over_text[2].getGlobalBounds().width) / 2 - 50,
               map_border.getGlobalBounds().height + map_border.getPosition().y + 145);
        game_over_text[3].setPosition((WINDOW_WIDTH - game_over_text[3].getGlobalBounds().width) / 2 + 50,
                   map_border.getGlobalBounds().height + map_border.getPosition().y + 145);
        game_over_text[4].setPosition((WINDOW_WIDTH - game_over_text[4].getGlobalBounds().width) / 2,
                   map_border.getGlobalBounds().height + map_border.getPosition().y + 200);

        //name
        name_input.setFont(font_default_text);
        name_input.setCharacterSize(32);
        name_input.setPosition((WINDOW_WIDTH - game_over_text[0].getGlobalBounds().width) / 2,
                   map_border.getGlobalBounds().height + map_border.getPosition().y + 145);

        rebuildSnake();
    }

    void WindowGameplay::rebuildSnake()
    {
        std::map<Position, EDirection> buffer = Controller::getSnake();
        current_snake_body.clear();
        current_snake_body.reserve(buffer.size());

        for(auto& i : buffer)
        {
            current_snake_body.emplace_back(sf::Vector2f(map_scale, map_scale));
            current_snake_body.back().setPosition(map_border.getPosition().x + i.first.first * (map_scale + grid_line_thickness),
                                                  map_border.getPosition().y + i.first.second * (map_scale + grid_line_thickness));
            current_snake_body.back().setFillColor(sf::Color::Cyan);
        }
    }

    WindowGameplay::~WindowGameplay(){ }

    ESection WindowGameplay::execute()
    {
        bool hasEnded      = false;
        bool isScoredSaved = false;
        bool goToMainMenu  = false;
        bool doesScoreQualify = false;
        std::string player_name;
        while(window.isOpen())
        {
            if(!Controller::moveSnake())
                hasEnded = true;

            fruit_position = Controller::getFruitPosition();
            fruit.setPosition(map_border.getPosition().x + fruit_position.first * (map_scale + grid_line_thickness),
                                                  map_border.getPosition().y + fruit_position.second * (map_scale + grid_line_thickness));
            points_text.setString("Points: " + std::to_string(Controller::getScore()));
            points_text.setPosition((WINDOW_WIDTH - points_text.getGlobalBounds().width) / 2, points_text.getPosition().y);

            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                else if(event.type == sf::Event::KeyPressed)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Controller::getDirection() != RIGHT)
                        Controller::changeDirection(LEFT);

                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Controller::getDirection() != LEFT)
                        Controller::changeDirection(RIGHT);

                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Controller::getDirection() != DOWN)
                        Controller::changeDirection(UP);

                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Controller::getDirection() != UP)
                        Controller::changeDirection(DOWN);
                }
                else if(hasEnded && event.type == sf::Event::MouseButtonPressed )
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        if(Controller::doesScoreQualify(Controller::getScore()))
                        {
                            if(game_over_text[2].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                std::cout << "clicked yes" << std::endl;
                                isScoredSaved = true;
                                std::cout << "isScoreSaved: " << isScoredSaved << std::endl;

                                game_over_text[1].setString("Enter your name: ");
                                game_over_text[2].setString("");
                                game_over_text[3].setString("");

                                //don't save score, resume the game
                                if(goToMainMenu)
                                    return GAMEPLAY;
                            }

                            else if(game_over_text[3].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)
                                    || game_over_text[4].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                if(game_over_text[4].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                                {
                                    game_over_text[2].setString("Yes");
                                    game_over_text[3].setString("No");
                                    Controller::addScoreboardEntry(name_input.getString(), Controller::getScore());
                                    Controller::saveScoreboard();
                                }
                                std::cout << "clicked no" << std::endl;
                                isScoredSaved = false;
                                game_over_text[1].setString("Do you want to resume the game?");
                                game_over_text[1].setPosition((WINDOW_WIDTH - game_over_text[1].getGlobalBounds().width) / 2,
                                                                map_border.getGlobalBounds().height + map_border.getPosition().y + 100);

                                //don't save score, go back to main menu
                                if(goToMainMenu)
                                    return MAIN_MENU;

                                goToMainMenu = true;
                            }
                        }
                        else
                        {
                            doesScoreQualify = true;
                        }

                    }
                }
                else if(isScoredSaved && event.type == sf::Event::TextEntered)
                {
                    if(event.text.unicode < 128)
                    {
                        char input_char = (char)event.text.unicode;
                        if(input_char == '\b')
                        {
                           if(name_input.getString().getSize() > 0)
                                name_input.setString(name_input.getString().substring(0, name_input.getString().getSize() - 1));
                        }
                        else
                            name_input.setString(name_input.getString() + event.text.unicode);
                    }

                }
            }

            rebuildSnake(); //garbage method but works
            window.clear(sf::Color(31,194,25));
            window.draw(map_border);

            for(int i = 0; i < Controller::getBoardWidth() - 1; i++)
                window.draw(vert_lines[i]);

            for(int i = 0; i < Controller::getBoardHeight() - 1; i++)
                window.draw(horiz_lines[i]);

            for(auto& i : current_snake_body)
                window.draw(i);

            window.draw(fruit);
            window.draw(points_text);

            if(hasEnded)
            {
                window.draw(game_over_text[0]);
                window.draw(game_over_text[1]);
                window.draw(game_over_text[2]);
                window.draw(game_over_text[3]);
                if(isScoredSaved)
                {
                    window.draw(game_over_text[1]);
                    window.draw(game_over_text[4]);
                    window.draw(name_input);
                }
            }
            window.display();
        }
        return EXIT;
    }
}

