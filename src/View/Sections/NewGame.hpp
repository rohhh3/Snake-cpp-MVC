#pragma once
#include "../ESection.hpp"
#include <iostream>
namespace View
{
    ESection executeNewGame()
    {
        std::cout << "Jestem w new game";
        return EXIT;
    }
}
