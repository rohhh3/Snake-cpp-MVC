#include "WindowScores.hpp"
#include "../resources.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    WindowScores::WindowScores()
    {

    }

    WindowScores::~WindowScores(){ }

    ESection WindowScores::execute()
    {
        while(window.isOpen())
        {
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);

            window.draw(title_window);

            window.display();
        }
    }
}
