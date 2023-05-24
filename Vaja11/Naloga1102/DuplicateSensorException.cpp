//
// Created by Tevz on 18/05/2023.
//

#include <DuplicateSensorException.hpp>

DuplicateSensorException::DuplicateSensorException(std::string  message)
    :message(std::move(message))
{
    toBeLogged(message);
}

[[nodiscard]] const char* DuplicateSensorException::what() const throw()
{
    return message.c_str();
}

void DuplicateSensorException::toBeLogged(std::string message) const
{
    Log(LogType::ERROR) << message << '\n';
}