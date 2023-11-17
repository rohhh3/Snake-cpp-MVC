#pragma once
#include "../ESection.hpp"
#include "../resources.hpp"
#include "../Section.hpp"
namespace View
{
    class Gameplay : public Section
    {
        public:
            bool is_gameplay_running;
            ESection execute();
            Gameplay();
            ~Gameplay();
    };
}
