//
// Created by Tevz on 21/05/2023.
//

#include <FileNotFoundException.hpp>

FileNotFoundException::FileNotFoundException(std::string  message)
    : message(message)
{
    toBeLogged(message);
}

[[nodiscard]] const char* FileNotFoundException::what() const noexcept
{
    return message.c_str();
}

void FileNotFoundException::toBeLogged(std::string message) const
{
    Log(LogType::ERROR) << message << '\n';
}