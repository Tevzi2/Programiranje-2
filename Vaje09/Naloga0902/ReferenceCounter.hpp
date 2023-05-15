#pragma once

#include <iostream>

class ReferenceCounter {
    public:
        ReferenceCounter();

        uint32_t getCount();

        ReferenceCounter operator--();

        ReferenceCounter operator++(int dummy);

    private:
        uint32_t count;
};
