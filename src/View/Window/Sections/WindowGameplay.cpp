#include "WindowGameplay.hpp"
#include "../resources.hpp"
#include "../../../Controller/Controller.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    WindowGameplay::WindowGameplay()
    {
        Controller::resetGameplay();

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
        while(window.isOpen())
        {
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::KeyPressed)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        Controller::changeDirection(LEFT);
                        Controller::moveSnake();
                    }

                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        Controller::changeDirection(RIGHT);
                        Controller::moveSnake();
                    }

                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        Controller::changeDirection(UP);
                        Controller::moveSnake();
                    }

                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        Controller::changeDirection(DOWN);
                        Controller::moveSnake();
                    }
                }
            }
            rebuildSnake(); //potem usunac
            window.clear(sf::Color(31,194,25));
            window.draw(map_border);

            for(int i = 0; i < Controller::getBoardWidth() - 1; i++)
                window.draw(vert_lines[i]);

            for(int i = 0; i < Controller::getBoardHeight() - 1; i++)
                window.draw(horiz_lines[i]);

            for(auto& i : current_snake_body)
                window.draw(i);

            window.display();
        }
        return EXIT;
    }
}

