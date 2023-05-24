#pragma once

#include <exception>
#include <string>

class DuplicateSensorException : public std::exception {
    public:
        explicit DuplicateSensorException(std::string  message);

        const char* what() const noexcept override;

    private:
        std::string message;
};
