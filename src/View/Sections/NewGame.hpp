#pragma once
#include "../ESection.hpp"
#include "../resources.hpp"
#include "../Section.hpp"
namespace View
{
    class NewGame : public Section
    {
        public:
            ESection execute();
            NewGame();
            ~NewGame();
    };
}
