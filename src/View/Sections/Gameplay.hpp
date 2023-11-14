#pragma once
#include "../ESection.hpp"
#include "../resources.hpp"
#include "../Section.hpp"
namespace View
{
    class Gameplay : public Section
    {
        public:
            ESection execute();
            Gameplay();
            ~Gameplay();
    };
}
