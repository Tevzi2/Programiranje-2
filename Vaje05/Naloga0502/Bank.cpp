//
// Created by Tevz on 23/03/2023.
//

#include <Bank.hpp>

Bank::Bank()
{
    ;
}

Bank::~Bank()
{
    for(const auto& acc : accounts)
    {
        delete acc;
    }

    for(const auto& transaction : transactions)
    {
        delete transaction;
    }
}

void Bank::addAccount(Account* account)
{
    accounts.push_back(account);
}

[[nodiscard]] bool Bank::makeDepostOnAccount(double amount, uint32_t accountNumber)
{
    Account* foundAccount = nullptr;

    for(const auto& acc : accounts)
    {
        if (acc->getNumber() == accountNumber)
            foundAccount = acc;
    }

    if(foundAccount == nullptr) return false;

    if(foundAccount->makeDeposit(amount))
    {
        transactions.push_back(new Transaction(accountNumber, Date::getCurrentDate(), amount));
        return true;
    }
    else
        return false;
}

[[nodiscard]] bool Bank::makeWithdrawalOnAccount(double amount, uint32_t accountNumber)
{
    Account* foundAccount = nullptr;

    for(const auto& acc : accounts)
    {
        if (acc->getNumber() == accountNumber)
            foundAccount = acc;
    }

    if(foundAccount == nullptr) return false;

    if(foundAccount->makeWithdraval(amount))
    {
        transactions.push_back(new Transaction(accountNumber, Date::getCurrentDate(), -amount));
        return true;
    }
    else
        return false;
}

[[nodiscard]] std::string Bank::toString() const
{
    std::string out;

    for(const auto& acc : accounts)
        out += acc->toString() + ",\n";

    return out;
}

void Bank::printTransactionsOnAccount(uint32_t accountNumber) const
{
    std::cout << "Transactions on account " << accountNumber << ": " << std::endl;
    for(const auto& transaction : transactions)
    {
        if(transaction->getAccountNumber() == accountNumber)
            std::cout << transaction->toString() << std::endl;
    }
}