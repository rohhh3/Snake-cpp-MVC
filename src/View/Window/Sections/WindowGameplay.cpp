#include "WindowGameplay.hpp"
#include "../resources.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    WindowGameplay::WindowGameplay()
    {

    }

    WindowGameplay::~WindowGameplay(){ }

    ESection WindowGameplay::execute()
    {
        std::cout << "I'm in gameplay section";
        getch();
        return EXIT;
    }
}

