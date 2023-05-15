//
// Created by Tevz on 08/04/2023.
//

#include <View.hpp>

View::View(const Size& size, const Position& position)
    :size(size), position(position)
{
    ;
}

[[nodiscard]] const Size &View::getSize() const
{
    return size;
}

void View::setSize(const Size &size)
{
    View::size = size;
}

[[nodiscard]] const Position &View::getPosition() const
{
    return position;
}

void View::setPosition(const Position &position)
{
    View::position = position;
}
