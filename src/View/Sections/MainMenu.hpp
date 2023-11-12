#pragma once
#include "../ESection.hpp"
#include "../resources.hpp"
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
