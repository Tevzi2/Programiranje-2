#pragma once

#include <exception>
#include <string>

class LoggedException : public std::exception {
    public:
        virtual void toBeLogged(std::string message) const = 0;
};
