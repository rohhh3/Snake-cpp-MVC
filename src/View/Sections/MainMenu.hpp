#pragma once
#include "../ESection.hpp"
#include <iostream>
namespace View
{
    ESection executeMainMenu()
    {
        std::cout << "Jestem w main menu";
        return EXIT;
    }
}
