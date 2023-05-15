//
// Created by Tevz on 23/03/2023.
//

#include <SavingAccount.hpp>

SavingAccount::SavingAccount(uint32_t number, double ballance, Person* owner, double interestRate)
    : Account(number, ballance, owner), interestRate(interestRate), lastWithdravalDate(Date(0, 0, 0))
{
    ;
}

void SavingAccount::setInterestRate(double interestRate)
{
    this->interestRate = interestRate;
}

[[nodiscard]] double SavingAccount::getInterestRate() const
{
    return interestRate;
}

[[nodiscard]] bool SavingAccount::makeDeposit(double amount)
{
    if(amount < 0) return false;

    ballance += amount * interestRate;

    return true;
}

[[nodiscard]] bool SavingAccount::makeWithdraval(double amount)
{
    if(amount < 0) return false;

    if(ballance - amount < 0) return false;

    Date now = Date::getCurrentDate();

    if((Date::daysSinceEpoch(now) - Date::daysSinceEpoch(lastWithdravalDate)) < 90) return false;

    ballance -= amount;
    lastWithdravalDate = now;

    return true;
}

[[nodiscard]] std::string SavingAccount::toString() const
{
    std::string out =
        Account::toString() +
        " | Interest rate: " +
        std::to_string(interestRate) +
        " | Last withdraval date: " +
        lastWithdravalDate.toString();

    return out;
}