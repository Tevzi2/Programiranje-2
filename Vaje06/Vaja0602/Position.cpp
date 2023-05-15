//
// Created by Tevz on 08/04/2023.
//

#include <Position.hpp>

Position::Position(float x, float y)
    :x(x), y(y)
{
    ;
}

void Position::setX(float x)
{
    this->x = x;
}

void Position::setY(float y)
{
    this->y = y;
}

[[nodiscard]] float Position::getX() const
{
    return x;
}

[[nodiscard]] float Position::getY() const
{
    return y;
}
