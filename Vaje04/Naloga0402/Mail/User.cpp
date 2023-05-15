//
// Created by Tevz on 18/03/2023.
//

#include <User.hpp>

User::User(const std::string& firstName, const std::string& lastName, const std::string& address)
    : firstName(firstName), lastName(lastName), address(address)
{
    ;
}

void User::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void User::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void User::setAddress(const std::string& address)
{
    this->address = address;
}

[[nodiscard]] std::string User::getFirstName() const
{
    return firstName;
}

[[nodiscard]] std::string User::getLastName() const
{
    return lastName;
}

[[nodiscard]] std::string User::getAddress() const
{
    return address;
}

[[nodiscard]] std::string User::toString() const
{
    std::string out =
        "Name: " +
        firstName +
        " | Last name: " +
        lastName +
        " | Address: " +
        address;

    return out;
}