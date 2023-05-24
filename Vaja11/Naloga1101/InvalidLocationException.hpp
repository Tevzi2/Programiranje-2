#pragma once

#include <exception>
#include <string>

class InvalidLocationException : public std::exception {
    public:
        explicit InvalidLocationException(std::string  message);

        const char* what() const noexcept override;

        static uint32_t get_count();

    private:
        static uint32_t called;
        std::string message;
};
