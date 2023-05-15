//
// Created by Tevz on 08/04/2023.
//

#include <Size.hpp>

Size::Size(float width, float height)
    :width(width), height(height)
{
    ;
}

void Size::setWidth(float width)
{
    this->width = width;
}

void Size::setHeight(float height)
{
    this->height = height;
}

[[nodiscard]] float Size::getWidth() const
{
    return width;
}

[[nodiscard]] float Size::getHeight() const
{
    return height;
}