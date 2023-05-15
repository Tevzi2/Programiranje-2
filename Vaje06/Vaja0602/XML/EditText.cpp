//
// Created by Tevz on 11/04/2023.
//

#include <EditText.hpp>

EditText::EditText(const Position& position, const Size& size, InputType inputType)
    : View(size, position), inputType(inputType)
{
    ;
}

[[nodiscard]] InputType EditText::getInputType() const
{
    return inputType;
}

void EditText::setInputType(InputType inputType)
{
    this->inputType = inputType;
}

[[nodiscard]] std::string EditText::toXml() const
{
    std::string out = "<EditText\n";
    out += "\t\twidth=\"" + std::to_string(size.getWidth()) + "px\"\n" +
           "\t\theight=\"" + std::to_string(size.getHeight()) + "px\"\n" +
           "\t\tinputType=\"" + to_string(inputType) + "\"\n" +
           "\t\tvisible=\"true\"/>\n";

    return out;
}