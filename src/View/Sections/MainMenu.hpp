#pragma once
#include "../Section.hpp"

namespace View
{
    class MainMenu : public Section
    {
        public:
            ESection execute();
            MainMenu();
            ~MainMenu();
    };
}
