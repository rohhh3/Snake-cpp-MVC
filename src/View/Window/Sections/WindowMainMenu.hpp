#pragma once
#include "../../Section.hpp"

namespace View
{
    class WindowMainMenu : public Section
    {
        public:
            ESection execute();
            WindowMainMenu();
            ~WindowMainMenu();
    };
}
