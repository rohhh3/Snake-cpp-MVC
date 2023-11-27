#include "WindowInit.hpp"
#include "resources.hpp"

#include <SFML/Graphics.hpp>

namespace View
{
    void windowInit()
    {
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
        sf::Event event;
        window.setFramerateLimit(30);

        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color(69,69,69));
            window.display();
        }

    }
}
