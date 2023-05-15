//
// Created by Tevz on 23/03/2023.
//

#include <Account.hpp>

Account::Account(uint32_t number, double ballance, Person* owner)
    :number(number), ballance(ballance), owner(owner)
{
    ;
}

void Account::setNumber(uint32_t number)
{
    this->number = number;
}

[[nodiscard]] uint32_t Account::getNumber() const
{
    return number;
}

[[nodiscard]] double Account::getBallance() const
{
    return ballance;
}

[[nodiscard]] Person* Account::getOwner() const
{
    return owner;
}

[[nodiscard]] bool Account::makeDeposit(double amount)
{
    if(amount < 0) return false;

    ballance += amount;

    return true;
}

[[nodiscard]] bool Account::makeWithdraval(double amount)
{
    if(amount < 0) return false;

    if(ballance - amount < 0) return false;

    ballance -= amount;

    return true;
}

[[nodiscard]] std::string Account::toString() const
{
    std::string out =
        "Owner: " +
        owner->toString() +
        " | number: " +
        std::to_string(number) +
        " | ballance: " +
        std::to_string(ballance);

    return out;
}