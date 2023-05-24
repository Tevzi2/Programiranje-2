//
// Created by Tevz on 23/05/2023.
//

#include <InvalidLocationException.hpp>

uint32_t InvalidLocationException::called = 0;

InvalidLocationException::InvalidLocationException(std::string  message)
    :message(std::move(message))
{
    called++;
}

const char* InvalidLocationException::what() const noexcept
{
    return message.c_str();
}

uint32_t InvalidLocationException::get_count()
{
    return called;
}