//
// Created by Tevz on 28/03/2023.
//

#include <Transaction.hpp>

Transaction::Transaction(uint32_t accoutNumber, Date date, double amount)
    : accountNumber(accoutNumber), date(date), amount(amount)
{
    ;
}

void Transaction::setAccountNumber(uint32_t accountNumber)
{
    this->accountNumber = accountNumber;
}

void Transaction::setDate(Date date)
{
    this->date = date;
}

void Transaction::setAmount(double amount)
{
    this->amount = amount;
}

[[nodiscard]] uint32_t Transaction::getAccountNumber() const
{
    return accountNumber;
}

[[nodiscard]] Date Transaction::getDate() const
{
    return date;
}

[[nodiscard]] double Transaction::getAmount() const
{
    return amount;
}

[[nodiscard]] std::string Transaction::toString() const
{
    std::string out =
        "Transaction on: " +
        std::to_string(accountNumber) +
        " | On date: " +
        date.toString() +
        " | Transaction amount: " +
        std::to_string(amount);

    return out;
}
