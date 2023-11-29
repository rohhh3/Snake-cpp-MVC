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
        std::cout << "I'm in scores section";
        getch();
        return EXIT;
    }
}
