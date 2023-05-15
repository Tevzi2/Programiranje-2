#include <InputType.hpp>

const char* inputTypeStr [7] = {
    ENUM_TO_STRING(number),
    ENUM_TO_STRING(decimalNumber),
    ENUM_TO_STRING(date),
    "time",
    ENUM_TO_STRING(e_mail),
    ENUM_TO_STRING(phone),
    ENUM_TO_STRING(password)
};

std::string to_string(InputType inputType)
{
    return inputTypeStr[inputType];
}