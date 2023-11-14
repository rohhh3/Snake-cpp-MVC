#pragma once
#include "ESection.hpp"
namespace View
{
    class Section
    {
        public:
            virtual ~Section() {};
            virtual ESection execute() = 0;
    };
}

