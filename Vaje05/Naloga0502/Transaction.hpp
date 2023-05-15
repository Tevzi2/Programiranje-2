#pragma once

#include <Date.hpp>

class Transaction {
    public:
        Transaction(uint32_t accoutNumber, Date date, double amount);

        void setAccountNumber(uint32_t accountNumber);

        void setDate(Date date);

        void setAmount(double amount);

        [[nodiscard]] uint32_t getAccountNumber() const
        ;
        [[nodiscard]] Date getDate() const;

        [[nodiscard]] double getAmount() const;

        [[nodiscard]] std::string toString() const;

    private:
        uint32_t accountNumber;
        Date date;
        double amount;
};
