#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <Account.hpp>
#include <Transaction.hpp>

class Bank {
    public:
        Bank();

        ~Bank();

        void addAccount(Account* account);

        [[nodiscard]] bool makeDepostOnAccount(double amount, uint32_t accountNumber);

        [[nodiscard]] bool makeWithdrawalOnAccount(double amount, uint32_t accountNumber);

        [[nodiscard]] std::string toString() const;

        void printTransactionsOnAccount(uint32_t accountNumber) const;

    private:
        std::vector<Account*> accounts{};
        std::vector<Transaction*> transactions{};
};
