#include "WindowHelp.hpp"
#include "../resources.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    WindowHelp::WindowHelp()
    {
        boiler_text.setFont(font_default_text);
        boiler_text.setCharacterSize(32);
        boiler_text.setFillColor(sf::Color::Yellow);
        boiler_text.setString("< GO BACK");
    }

    WindowHelp::~WindowHelp(){ }

    ESection WindowHelp::execute()
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
                        if(boiler_text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            return MAIN_MENU;
                    }
                }
            }
            window.clear(sf::Color::Black);
            window.draw(boiler_text);
            window.display();
        }
        return EXIT;
    }
}
