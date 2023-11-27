#pragma once
#include "../../Section.hpp"

namespace View
{
    class WindowGameplay : public Section
    {
        public:
            ESection execute();
            WindowGameplay();
            ~WindowGameplay();
    };
}
