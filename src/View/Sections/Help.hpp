#pragma once
#include "../Section.hpp"
namespace View
{
    class Help : public Section
    {
        public:
            ESection execute();
            Help();
            ~Help();

    };
}
