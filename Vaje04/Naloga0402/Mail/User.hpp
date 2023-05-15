#pragma once

#include <string>

class User {
    public:
        User(const std::string& firstName, const std::string& lastName, const std::string& address);

        void setFirstName(const std::string& firstName);

        void setLastName(const std::string& lastName);

        void setAddress(const std::string& address);

        [[nodiscard]] std::string getFirstName() const;

        [[nodiscard]] std::string getLastName() const;

        [[nodiscard]] std::string getAddress() const;

        [[nodiscard]] std::string toString() const;

    private:
        std::string firstName, lastName, address;
};
