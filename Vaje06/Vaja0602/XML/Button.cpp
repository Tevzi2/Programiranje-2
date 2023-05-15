//
// Created by Tevz on 08/04/2023.
//

#include <Button.hpp>

Button::Button(const Position& position, const Size& size, const std::string &text)
    : View(size, position), text(text)
{
    ;
}

[[nodiscard]] const std::string &Button::getText() const
{
    return text;
}

void Button::setText(const std::string &text)
{
    Button::text = text;
}

[[nodiscard]] std::string Button::toXml() const
{
    std::string out = "<Button\n";
    out += "\t\twidth=\"" + std::to_string(size.getWidth()) + "px\"\n" +
        "\t\theight=\"" + std::to_string(size.getHeight()) + "px\"\n" +
        "\t\ttext=\"" + text + "\"\n" +
        "\t\tvisible=\"true\"/>\n";

    return out;
}