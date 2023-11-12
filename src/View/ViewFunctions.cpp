#include "ViewFunctions.hpp"
#include <iostream>

namespace View
{
    void printSpace(uint32_t string_length)
    {
        int padding = (CONSOLE_WIDTH - string_length ) / 2;
        for(int i = 0; i < padding; i++)
            std::cout << " ";
    }
}
