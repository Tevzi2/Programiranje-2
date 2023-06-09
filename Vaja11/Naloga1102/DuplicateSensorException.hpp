#pragma once

#include <LoggedException.hpp>
#include <string>
#include <Log.hpp>

class DuplicateSensorException : public LoggedException {
    public:
        explicit DuplicateSensorException(std::string  message);

        [[nodiscard]] const char* what() const throw() override;

        void toBeLogged(std::string message) const override;

    private:
        std::string message;
};
