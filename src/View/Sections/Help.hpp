#pragma once
#include "../ESection.hpp"
#include <iostream>
namespace View
{
    ESection executeHelp()
    {
        std::cout << "Jestem w help";
        return EXIT;
    }
}
