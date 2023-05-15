#pragma once

#include <string>
#include <Person.hpp>

class Account {
    public:
        Account(uint32_t number, double ballance, Person* owner);

        void setNumber(uint32_t number);

        [[nodiscard]] uint32_t getNumber() const;

        [[nodiscard]] double getBallance() const;

        [[nodiscard]] Person* getOwner() const;

        [[nodiscard]]virtual bool makeDeposit(double amount);

        [[nodiscard]] virtual bool makeWithdraval(double amount);

        [[nodiscard]] virtual std::string toString() const;

    protected:
        uint32_t number;
        double ballance;

    private:
        Person* owner;
};
