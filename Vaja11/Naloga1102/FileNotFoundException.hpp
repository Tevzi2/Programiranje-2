#pragma once

#include <LoggedException.hpp>
#include <string>
#include <Log.hpp>

class FileNotFoundException : public LoggedException {
    public:
        explicit FileNotFoundException(std::string  message);

        [[nodiscard]] const char* what() const noexcept override;

        void toBeLogged(std::string message) const override;

    private:
        std::string message;
};
