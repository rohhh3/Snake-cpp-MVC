#pragma once
#include "../../Section.hpp"

namespace View
{
    class WindowNewGame : public Section
    {
        public:
            ESection execute();
            WindowNewGame();
            ~WindowNewGame();
    };
}
