#pragma once
#include "../../Section.hpp"
#include <SFML/Graphics.hpp>
namespace View
{
    class WindowScores : public Section
    {
        public:
            ESection execute();
            WindowScores();
            ~WindowScores();
    };
}
