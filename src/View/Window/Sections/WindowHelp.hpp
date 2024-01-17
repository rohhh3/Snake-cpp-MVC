#pragma once
#include "../../Section.hpp"
#include <SFML/Graphics.hpp>
namespace View
{
    class WindowHelp : public Section
    {
        private:
            sf::Text boiler_text;

        public:
            ESection execute();
            WindowHelp();
            ~WindowHelp();
    };
}
