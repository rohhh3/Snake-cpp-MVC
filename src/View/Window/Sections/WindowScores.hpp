#pragma once
#include "../../Section.hpp"

namespace View
{
    class WindowScores : public Section
    {
        public:
            ESection execute();
            WindowScores();
            ~WindowScores();
    };
}
