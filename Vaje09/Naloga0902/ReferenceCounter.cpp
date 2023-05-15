#include <ReferenceCounter.hpp>

ReferenceCounter::ReferenceCounter()
    :count(0)
{
    ;
}

uint32_t ReferenceCounter::getCount()
{
    return count;
}

ReferenceCounter ReferenceCounter::operator--()
{
    --count;

    return *this;
}

ReferenceCounter ReferenceCounter::operator++(int dummy)
{
    ReferenceCounter temp;

    temp.count = count;

    count++;

    return temp;
}
