//
// Created by Tevz on 18/05/2023.
//

#include <DuplicateSensorException.hpp>
#include <utility>

DuplicateSensorException::DuplicateSensorException(std::string  message)
    :message(std::move(message))
{
    ;
}

const char* DuplicateSensorException::what() const throw()
{
    return message.c_str();
}
