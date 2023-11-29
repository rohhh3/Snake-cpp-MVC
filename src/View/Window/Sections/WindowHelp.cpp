#include "WindowHelp.hpp"
#include "../resources.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    WindowHelp::WindowHelp()
    {

    }

    WindowHelp::~WindowHelp(){ }

    ESection WindowHelp::execute()
    {
        std::cout << "I'm in help section";
        getch();
        return EXIT;
    }
}
