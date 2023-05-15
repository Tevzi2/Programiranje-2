#pragma once

#include <Account.hpp>
#include <Person.hpp>
#include <Date.hpp>

class SavingAccount : public Account {
    public:
        SavingAccount(uint32_t number, double ballance, Person* owner, double interestRate);

        void setInterestRate(double interestRate);

        [[nodiscard]] double getInterestRate() const;

        [[nodiscard]] bool makeDeposit(double amount) override;

        [[nodiscard]] bool makeWithdraval(double amount) override;

        [[nodiscard]] std::string toString() const override;

    private:
        Date lastWithdravalDate;
        double interestRate;
};
