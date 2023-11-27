#pragma once
#include "../../Section.hpp"

namespace View
{
    class WindowHelp : public Section
    {
        public:
            ESection execute();
            WindowHelp();
            ~WindowHelp();
    };
}
