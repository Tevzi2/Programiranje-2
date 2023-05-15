#pragma once

#include <string>

#define ENUM_TO_STRING(e) (#e)

enum InputType
{
    number,
    decimalNumber,
    date,
    _time,
    e_mail,
    phone,
    password
};

std::string to_string(InputType);